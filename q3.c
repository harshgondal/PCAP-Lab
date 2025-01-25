#include "mpi.h"
#include <stdio.h>

int factorial(int n){
    if(n==0)return 1;
    else return n*factorial(n-1);
}
int main(int argc, char *argv[]) {

    int rank, size, N, A[10], B[10], c[10],m;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        N = size;
        fprintf(stdout, "Enter m");
        fflush(stdout);
        scanf("%d",&m);
        fprintf(stdout, "Enter %d values:\n", N);
        fflush(stdout);
        for (int i = 0; i < N*m; i++)
            scanf("%d", &A[i]);
    }
    MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(&A[rank*m], m, MPI_INT, c, m, MPI_INT, 0, MPI_COMM_WORLD);
    fprintf(stdout, "I have received %d in process %d\n",c[0],rank);
    fflush(stdout);

    int sum=0;
    for(int i=0;i<m;i++){
        sum+=c[i];
    }
    int avg=sum/m;


    MPI_Gather(&avg, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // int finalsum=0;
        fprintf(stdout, "The Result gathered in the root \n");
        fflush(stdout);
        sum=0;
        for (int i = 0; i < N; i++){
            sum+=B[i];
            fprintf(stdout,"%d \t", B[i]);
            fflush(stdout);
        }
    fprintf(stdout,"\nFinal avg is %d\n", sum/N);
    fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}