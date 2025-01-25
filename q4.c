#include "mpi.h"
#include <stdio.h>
#include<string.h>
int factorial(int n){
    if(n==0)return 1;
    else return n*factorial(n-1);
}
int isvowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return 1;
    return 0;
}
int main(int argc, char *argv[]) {

    int rank, size, N, A[10], B[10],m;
    char str[100],c[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        N = size;
        fprintf(stdout, "Enter m");
        fflush(stdout);
        scanf("%d",&m);
        fprintf(stdout, "Enter String");
        fflush(stdout);
        scanf("%s",str);
    }
    if(strlen(str)!=0){
    m=m/strlen(str);
}   
    MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(&str[rank*m], m, MPI_CHAR, c, m, MPI_CHAR, 0, MPI_COMM_WORLD);
    c[m]='\0';
    fprintf(stdout, "I have received %c in process %d\n",c[0],rank);
    fflush(stdout);

    int count=0;
    for(int i=0;i<m;i++){
        if(isvowel(c[i])==1)count++;
    }
    // int avg=sum/m;


    MPI_Gather(&count, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // int finalsum=0;
        fprintf(stdout, "The Result gathered in the root \n");
        fflush(stdout);
        count=0;
        for (int i = 0; i < N; i++){
            count+=B[i];
            fprintf(stdout,"%d \t", B[i]);
            fflush(stdout);
        }
    fprintf(stdout,"\nFinal avg is %d\n", strlen(str)-count);
    fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}