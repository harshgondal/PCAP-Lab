#include<stdio.h>
#include"mpi.h"
int main(int argc,char*argv[]){
	int rank,size,fact,factsum,i,j;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	// for(i=1;i<=rank+1;i++){
	// 	fact=fact*i;
	// }
	// printf("%d",size);
	fact=rank+1;
	printf("Rank %d",rank);
	MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_PROD,MPI_COMM_WORLD);
	fprintf(stdout ,"%d",factsum);
	fflush(stdout);
	printf("\n");
	MPI_Reduce(&factsum,&j,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0){
		fprintf(stdout,"%d",j);
		fflush(stdout);
		MPI_Finalize();
	}
	return 0;
}