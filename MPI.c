#include <mpi.h>
#include <stdio.h>
#include<stdlib.h>


typedef struct rM{
	int xCoor;
	int yCoor;
}rM;

int Len = 100;
int matA[Len][Len];
int matB[Len][Len];
int matC[Len][Len];

rM aux,coorfalt;


void matricesLlenado(int a[Len][Len],int num);
void imprimirMatriz(int b[Len][Len]);
void imprimirCoorHechas(int g, int f);
void CmatrizCoordenadas(int c, int d, int maa[Len][Len], int mbb[Len][Len], int mcc[Len][Len]);
void chequeoMatrizC(int mc1[100][100]);


int main(int argc, char** argv) {    
    MPI_Init(NULL, NULL);
    
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);

    matricesLlenado(matA,1);
	printf("\nMatriz matA creada.\n");
	matricesLlenado(matB,1);
	printf("\nMatriz matB creada.\n");
	matricesLlenado(mc,0);
	printf("\nMatriz mc creada.\n");
	printf("\n");	
	for(int imain=0;imain<Len;imain++){
		for(int jmain=0;jmain<Len;jmain++){
			CmatrizCoordenadas(imain,jmain,matA,matB,matC);
		}
	}
	printf("\n AFEASDF\n");
	imprimirMatriz(matC);
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

void imprimirMatriz(int b[Len][Len]){
	for(int i=0;i<Len;i++){
		for(int j=0;j<Len;j++){
			printf("%d ",b[i][j]);
		}	
	}
	printf("\n");
}

void CmatrizCoordenadas(int c, int d, int maa[Len][Len], int mbb[Len][Len], int mcc[Len][Len]){	
	int aux1=0;
	for(int i=0;i<Len;i++){
		for(int j=0;j<Len;j++){
			mcc[c][d] = 0;
			for(int k=0;k<Len;k++){
				mcc[c][d]=mcc[c][d]+maa[i][k]*mbb[k][j];
			} 			
		}
	}
	printf("\n%d \n",mcc[c][d]);
	aux.xCoor=c;
	aux.yCoor=d;
	imprimirCoorHechas(aux.xCoor,aux.yCoor);
}

void imprimirCoorHechas(int g,int f){
	printf("\nPrimer coordenada: %d\n",g);
	printf("\nSegunda coordenada: %d\n",f);
}

void chequeoMatrizC(int mc1[Len][Len]){
	
	for(int i=0;i<Len;i++){
		for(int j=0;j<Len;j++){
			if(mc1[i][j]==0){
				coorfalt.xCoor=i;
				coorfalt.yCoor=j;
				printf("Encontrada matriz distinta a 0.\n");
			}
		}
	}
}