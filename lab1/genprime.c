/**
 *  @ando-huang
 *  this is the parallel implementation of seq_prime_generator.c
**/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

void write_to_file(int* primes, char* n); //writes the primes into a file named "{n}.txt"

int main(int argc, char* argv[]){
    int my_rank, comm_sz;  //vars used to organize threads
    int n = atoi(argv[1]); //now we have N, upper limit of primes to find
    
    MPI_Init(NULL, NULL); //everything from now on is MPI
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int start = my_rank * n//comm_sz;
    int end = start + n//comm_sz;

    for(int i = start; i < end; i++){
        
    
    }


    MPI_Finalize();

    //write the array to a file
    write_to_file(primes, count, argv[1])

    return 0;
}

//for later use in sequential write to the folder
void write_to_file(int* primes, int count, char* n){
    FILE* f = fopen("", "w"); //fix this so that it appends char* n 
    for(int i = 0; i< count; i++){
        fprintf(f, "%d ", primes[i]);
    }
    f.close(); //close the file, we are done with it
    return;
}
