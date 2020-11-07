#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char* argv[]){
    int my_rank, comm_sz;  //vars used to organize threads
    int n = atoi(argv[1]); //now we have N, upper limit of primes to find
    int rootN = (int)floor(sqrt(n)); //we want everything up to and including this

    FILE * f;

    char* fileName= (char*)malloc(20);
    sprintf(fileName, "%s.txt", argv[1]);
    
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    //start timer
    double starttime, endtime;
    starttime = MPI_Wtime();

    int size = (int)(n/comm_sz);

    int my_first_i, my_last_i;
    my_first_i = my_rank * size;
    my_last_i = my_first_i + size;
    if(my_rank == 0){ my_first_i = 2; } //ignore 0 and 1
    if(my_rank == comm_sz - 1 ){ my_last_i = n; } //accomodates for when n%p != 0

    int sect_size = my_last_i - my_first_i + 1; //each section is a certain size

    int i;
    int * primes = (int*)malloc(rootN * sizeof(int)); //the prime array every core has
    for(i = 0; i < rootN; i++){
        primes[i] = i+2;
    }
    int * sect = (int*)malloc(size*sizeof(int)); //each core gets a section to process
    for(i = 0; i < sect_size; i++){
        sect[i] = i + my_first_i; 
    }

    int prime_iter, curr_prime;
    for(prime_iter = 0; prime_iter < rootN; prime_iter++){
        if(primes[prime_iter] != -1 ){
            curr_prime = primes[prime_iter];
            for(i = 0; i < sect_size; i++){
                if(sect[i] != curr_prime && sect[i] % curr_prime == 0){
                    sect[i] = -1;
                }
            }
            for(i = 2*(curr_prime - 2); i < rootN; i+= curr_prime){
                if(primes[i] % curr_prime == 0){
                    primes[i] = -1;
                }
            }
        }
    }

    if(my_rank == 0){
        f = fopen(fileName, "w");
        for(i = 0; i < sect_size; i++){
            if(sect[i] != -1){
                //printf("%d\n", sect[i]);
                fprintf(f, "%d ", sect[i]);
            }
        }
	int comm;
        for(comm = 1; comm < comm_sz; comm++){
            if(comm != comm_sz -1){ //the middle ones GOOD
                size = (int)(n/comm_sz)+1;
                MPI_Recv(sect, size, MPI_INT, comm, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                for(i = 0; i < size; i++){
                    if(sect[i] != -1){
                        //printf("%d\n", sect[i]);
                        fprintf(f, "%d ", sect[i]);
                    }
                }
            }
            else{ //comm is rank comm_sz-1
                size = n - (comm_sz-1)*(int)(n/comm_sz)+1;
                MPI_Recv(sect, size, MPI_INT, comm, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                for(i = 0; i < size; i++){
                    if(sect[i] != -1){
                        //printf("%d\n", sect[i]);
                        fprintf(f, "%d ", sect[i]);
                    }
                }
            }
            
        }
        fclose(f);
    }
    else{
        MPI_Send(sect, sect_size, MPI_INT, 0, 0, MPI_COMM_WORLD); //must match sect_size to the recv
    }
    
    endtime = MPI_Wtime();

    printf("Time expended: %f\n", endtime - starttime);

    MPI_Finalize();
    return 0;
}
