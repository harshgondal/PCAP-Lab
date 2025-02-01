#include<stdio.h>
#include"mpi.h"
int main(int argc,char*argv[]){
	int rank,size,fact,factsum,i,j,arr[10][10],temp,count;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	// for(i=1;i<=rank+1;i++){
	// 	fact=fact*i;
	// }
	// printf("%d",size);
	if(rank==0){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("Enter element to be searched");
	scanf("%d",&temp);
}
	MPI_Bcast(&temp, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&arr[3][3], 3, MPI_INT, 0, MPI_COMM_WORLD);
	// fact=rank+1;
	// MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_PROD,MPI_COMM_WORLD);
	// fprintf(stdout ,"%d",factsum);
	// fflush(stdout);
	// printf("\n");
	count=0;
	for(int i=0;i<3;i++){
		if(arr[rank][i]==temp){
			count++;
		}
		// printf("Rank %d and value %d",rank,count);
	}
	printf("\n%d",count);
	MPI_Reduce(&count,&j,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0){
		printf("%d",j);
		// fflush(stdout);
		
	}
	MPI_Finalize();
	return 0;
}