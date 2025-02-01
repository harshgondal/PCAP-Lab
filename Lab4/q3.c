#include<stdio.h>
#include"mpi.h"
int main(int argc,char*argv[]){
	int rank,size,arr[4][4],B[4][4],C[4];
	int temp[4];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	// for(i=1;i<=rank+1;i++){
	// 	fact=fact*i;
	// }
	// printf("%d",size);
	if(rank==0){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	// printf("Enter element to be searched");
	// scanf("%d",&temp);
}
MPI_Scatter(arr,4,MPI_INT,temp,4,MPI_INT,0,MPI_COMM_WORLD);
MPI_Scan(temp,C,4,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	// MPI_Bcast(&temp, 1, MPI_INT, 0, MPI_COMM_WORLD);
	// MPI_Bcast(&arr[3][3], 3, MPI_INT, 0, MPI_COMM_WORLD);
	// fact=rank+1;
	// MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_PROD,MPI_COMM_WORLD);
	// fprintf(stdout ,"%d",factsum);
	// fflush(stdout);
	// printf("\n");
MPI_Gather(C,4,MPI_INT,B,4,MPI_INT,0,MPI_COMM_WORLD);
	// count=0;
	// for(int i=0;i<3;i++){
	// 	if(arr[rank][i]==temp){
	// 		count++;
	// 	}
	// 	// printf("Rank %d and value %d",rank,count);
	// }
	// printf("\n%d",count);
	// MPI_Reduce(&count,&j,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0){
		for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d\t",B[i][j]);
		}
		printf("\n");
	}
	}
	MPI_Finalize();
	return 0;
}