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

int main(int argc, char* argv[]){
    int n = (int)argv[1];

    if(n > MAX || n < 2){
        printf("invalid input.");
        return -1;
    }//input handling complete
    
    //generate all the primes to a list
    int* primes = malloc(sizeof(int) * n);




    return 0;
}