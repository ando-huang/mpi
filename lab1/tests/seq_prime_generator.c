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
#include <stdlib.h>

const static int MAX = 10000000;

int* generate_primes(int n); // solving function

//driver code, handles input and conditionals
int main(int argc, char** argv[]){
    int n = atoi(argv[1]); //cli arg turned to integer

    char * filename = argv[1];
    strcat(filename, ".txt");

    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    if(n < 2){
        printf("invalid input.\n");
        return -1;
    }//input handling complete
    
    //generate all the primes to a list
    int* args = generate_primes(n);
    int* primes = args[0];
    int size = args[1];

    for(int i = 0; i < size; i++){ //write to file instead
        printf("%d ", primes[i]);
    }
    //FILE * file = fopen("n.txt", "w");

    return 0;
}

/**
 * this function creates the list of primes that we are returning
 */

int * generate_primes(int n){
    int cap = (int)floor((double)((n+1)/2));
    int primes[n/2];
    int count = 0;
    int isPrime;
    for(int i = 2; i < n; i++){
        isPrime = 0; //reset prior to every call
        for(int j = 0; j < count; j++){
            if (i/primes[j] == 0) { isPrime = 1; }

        }
        if (isPrime == 0){
            primes[count] = i;
            count+=1;
        }
    }
    //we want to return primes and count.

}