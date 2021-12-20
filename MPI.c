#include <mpi.h>
#include <stdio.h>
#include<stdlib.h>

int Len = 100;
void matricesLlenado(int a[Len][Len],int num);
void matCoorC(int c, int d, int matAA[Len][Len], int matBB[Len][Len], int matCC[Len][Len]);
void imprimirMatriz(int b[Len][Len]);

typedef struct rM{
	int xCoor;
	int yCoor;
}rM;

int Mat[Len][Len];
int Mat1[Len][Len];
int Mat2[Len][Len];

rM coorfalt;

int main(int argc, char** argv) {    
    MPI_Init(NULL, NULL);
    
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    matricesLlenado(Mat,1);
	printf("\nMatriz Mat creada.\n");
	matricesLlenado(Mat1,1);
	printf("\nMatriz Mat1 creada.\n");
	matricesLlenado(mc,0);
	printf("\nMatriz mc creada.\n");
	printf("\n");	
	for(int imain=0;imain<Len;imain++){
		for(int jmain=0;jmain<Len;jmain++){
			matCoorC(imain,jmain,Mat,Mat1,Mat2);
		}
	}
	
	imprimirMatriz(Mat2);
    MPI_Finalize();
}

void matricesLlenado(int a[Len][Len], int num){
	for(int i=0;i<Len;i++){
		for(int j=0;j<Len;j++){
			a[i][j]=num;
			printf("%d",a[i][j]);
		}	
	}
}


void matCoorC(int c, int d, int matAA[Len][Len], int matBB[Len][Len], int matCC[Len][Len]){		
	for(int x=0;x<Len;x++){
		for(int y=0;y<Len;y++){
			matCC[c][d] = 0;
			for(int z=0;z<Len;z++){
				matCC[c][d]+=matAA[x][z]*matBB[z][y];
			} 			
		}
	}
	printf("\n%d \n",matCC[c][d]);
	printf("\nPrimer coordenada: %d\n",c);
	printf("\nSegunda coordenada: %d\n",d);
}

void imprimirMatriz(int b[Len][Len]){
	for(int x=0;x<Len;x++){
		for(int y=0;y<Len;y++){
			printf("%d ",b[x][y]);
		}	
	}
	printf("\n");
}