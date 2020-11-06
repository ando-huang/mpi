/**
 *  This code is SEQUENTIAL closer to the algo provided
 */ 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int n = atoi(argv[1]); //every single core must have n
    int my_rank, comm_sz;
    //int * primes = (int*)malloc(sizeof(int)*n/2);
    int * all_nums = (int*)malloc(sizeof(int)*(n+1));//extra slot for all_nums[n]
    for(int i = 0; i<= n; i++){
        all_nums[i] = 0;
    }
    all_nums[0] = 1;
    all_nums[1] = 1;
    
    //MPI_Init(NULL, NULL);
    
    //split into comms, each is determined by rank
    int start = 2;
    int end = n;
    for(int i = start; i <= end; i++){
        if(all_nums[i] == 0){
            //broadcast its recognition as a prime?
            for(int j = i; j < end; j+=i){
                all_nums[j] = 1;
            }
        }
    }

    //MPI_Finalize();
    for(int i = 0; i <= n; i++){
        if (all_nums[i] == 0){
            printf("prime: %d\n", i);
        }
        
    }
    //write contents of PRIMES to a file "n.txt"
}
