#include <stdio.h>
#include <mpi.h>

void Get_Input(
    int my_rank,
    int comm_sz,
    double * a_p,
    double * b_p,
    int * n_p) {
        int dest;
        if (my_rank == 0){
            printf("Enter a, b, and n\n");
            scanf("%lf %lf %d", a_p, b_p, n_p);
            for(dest = 1; dest < comm_sz; dest++){
                MPI_Send(a_p, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
                MPI_Send(b_p, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
                MPI_Send(n_p, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
            }
        }
        else{
            MPI_Recv(a_p, 1, MPI_DOUBLE, 0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(b_p, 1, MPI_DOUBLE, 0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(n_p, 1, MPI_INT, 0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }

int main(void){

    MPI_Init(NULL, NULL);
    //make calls to functions
    double a, b;
    int n, comm_sz, my_rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    Get_Input(my_rank, comm_sz, &a, &b, &n);
    double h = (b-a)/n;
    printf("h: %f\n", h);

    MPI_Finalize();
    return 0;
}