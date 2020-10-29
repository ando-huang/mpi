/**
 * this program is a sequential program for generating all prime numbers between 2 and n
 *
 * input: int n is the upper limit of the program, primes are up to and including n
 * 
 * output: to text file, named '10.txt' that contains the list of primes separated by a single space
 *
 * goal is to write this program s.t it can be easily parallelized.
**/

#include <stdio.h>

const static int MAX = 10000000;

/**
 * approx size returns a guideline int for the number of primes 
 * param n must be <= 10000000 and greater than 2
 */ 
int approx_size(int n){
    int size;
    if(n <= MAX)    { size = 664579;}
    if(n <= MAX/10) { size = 78498; }
    if(n <= MAX/100){ size = 9592;  }
    if(n <= MAX/1000){size = 1229;  }
    if(n <= 1000)   { size = 168;   }
    if(n <= 100)    { size = 25;    }
    if(n <= 10)     { size = 4;     }
    return size;
}

int* gen_prime_list(int n){
    int size = approx_size(n);
    int primes[size]; //maybe change the initial size of the array to match whatever the size is expected to be
    primes[0] = 2;
    int count = 1;
    for(int i = 2; i < n; i++){
        int isPrime = 0; //is prime
        for(int j = 0; j < count; j++){
            if(i % primes[j] == 0){ isPrime = 1; }
        }
        if (isPrime == 0){
            primes[count] = i;
            count += 1;
        }
    }
    int* items = {&primes, &count};
    return &items;
}

int main(int argc, char** argv[]){
    int n = *(int*)argv[1]; //input n

    if(n > MAX || n < 2){
        printf("invalid input.\n");
        return -1;
    }//input handling complete
    
    //generate all the primes to a list
    int* list = gen_prime_list(n);
    int* primes = list[0];
    int size = list[1];
    for(int i = 0; i < size; i++){
        printf("%d ", primes[i]);
    }
    return 0;
}