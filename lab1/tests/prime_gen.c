#include <stdio.h>
#include <stdlib.h>

int* prime_list(int n);

int main(int argc, char* argv[]){
    int n = atoi(argv[1]); //cli arg turned to integer
    
    int* primes = prime_list(n);
    int count = primes[0];

    for(int i = 1; i<=count; i++){ //this part will be a fprintf in the mpi
        printf("%d\n", primes[i]);
    }

    return 0;
}

//This function generates the primes in the list
int* prime_list(int n){
    int* primes = (int*)(malloc(sizeof(int)*(n))); //creates a container of size n/2
    primes[1] = 2;
    int count = 1;//current size of the list
    int isPrime;
    for(int i = 2; i <= n; i++){
        isPrime = 0;
        for(int j = 1; j <= count; j++){
            if( i % primes[j] == 0){ //if composite
                isPrime = 1; //indicate not prime
                break;
            }
        }
        if (isPrime == 0){
            count++;
            primes[count] = i;
        }
    }
    primes[0] = count;
    return primes;
}