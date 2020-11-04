#include <stdio.h>
#include <stdlib.h>

int* prime_list(int n);

int main(int argc, char* argv[]){
    int n = atoi(argv[1]); //cli arg turned to integer

    int* primes = prime_list(n);
    int count = primes[0];
    for(int i = 1; i<count; i++){
        printf("%d\n", primes[i]);
    }

    return 0;
}

int* prime_list(int n){
    int* primes = (int*)(malloc(sizeof(int)*n/2));
    int count = 0;
    int isPrime;
    for(int i = 2; i <= n; i++){
        isPrime = 0;
        for(int j = 0; j < count; j++){
            if(i % primes[j] == 0){
                isPrime = 1;
                break;
            }
        }
        if(isPrime == 0){
            primes[count+1] = i;
            count+=1;
        }
    }
    primes[0] = count;
    return primes;
}