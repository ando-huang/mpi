#include <mpi.h>
#include <stdio.h>

/**
*	This is a sorting algorithm in MPI
*	n keys with p comms
*	n/p keys per process
*	algo terminates when the keys are sorted
*/
//n^2 bubblesort
void Bubble_sort(
    int a[],
    int n)
    {
    int list_length, i, temp;
    for (list_length = n; list_length >= 2; list_length--){
        for(i = 0; i< list_length -1; i++){
            if(a[i] > a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1]= temp;
            }
        }
    }
}

void Odd_even_sort(
    int a[], int n
){
    int phase, i, temp;
    for(phase = 0; phase < n; phase++){
        if(phase % 2 == 0){
            for(i = 1; i< n; i+=2){
                if (a[i-1]> a[i]){
                    temp = a[i];
                    a[i] = a[i-1];
                    a[i-1] = temp;
                }
            }
        }
        else{
            for(i = 0; i<n; i+=2){
                if(a[i] > a[i+1]){
                    temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] =temp;
                }
            }
        }
    }
}



    
