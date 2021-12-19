#include <mpi.h>
#include <stdio.h>
#include<stdlib.h>
#define Lenght 100


typedef struct resulM{
	int xCoor;
	int yCoor;
}resulM;

int matA[Lenght][Lenght];
int matB[Lenght][Lenght];
int matC[Lenght][Lenght];

resulM aux,coorfalt;


void matricesLlenado(int a[Lenght][Lenght],int num);
void imprimirMatriz(int b[Lenght][Lenght]);
void imprimirCoorHechas(int g, int f);
void CmatrizCoordenadas(int c, int d, int maa[Lenght][Lenght], int mbb[Lenght][Lenght], int mcc[Lenght][Lenght]);
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
	for(int imain=0;imain<Lenght;imain++){
		for(int jmain=0;jmain<Lenght;jmain++){
			CmatrizCoordenadas(imain,jmain,matA,matB,matC);
		}
	}
	printf("\n AFEASDF\n");
	imprimirMatriz(matC);
    MPI_Finalize();
}

void matricesLlenado(int a[Lenght][Lenght], int num){
	for(int i=0;i<Lenght;i++){
		for(int j=0;j<Lenght;j++){
			a[i][j]=num;
			printf("%d",a[i][j]);
		}	
	}
}

void imprimirMatriz(int b[Lenght][Lenght]){
	for(int i=0;i<Lenght;i++){
		for(int j=0;j<Lenght;j++){
			printf("%d ",b[i][j]);
		}	
	}
	printf("\n");
}

void CmatrizCoordenadas(int c, int d, int maa[Lenght][Lenght], int mbb[Lenght][Lenght], int mcc[Lenght][Lenght]){	
	int aux1=0;
	for(int i=0;i<Lenght;i++){
		for(int j=0;j<Lenght;j++){
			mcc[c][d] = 0;
			for(int k=0;k<Lenght;k++){
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

void chequeoMatrizC(int mc1[Lenght][Lenght]){
	
	for(int i=0;i<Lenght;i++){
		for(int j=0;j<Lenght;j++){
			if(mc1[i][j]==0){
				coorfalt.xCoor=i;
				coorfalt.yCoor=j;
				printf("Encontrada matriz distinta a 0.\n");
			}
		}
	}
}