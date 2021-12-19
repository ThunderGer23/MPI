#include <mpi.h>
#include <stdio.h>
#include<stdlib.h>
#define tam 100


typedef struct resulM{
	int coorC_a;
	int coorC_b;
}resulM;

int ma[tam][tam];
int mb[tam][tam];
int mc[tam][tam];
int i,j,k;
int imain,jmain;
resulM aux,coorfal;


void matricesLlenado(int a[tam][tam],int num);
void imprimirMatriz(int b[tam][tam]);
void imprimirCoorHechas(int g, int f);
void CmatrizCoordenadas(int c, int d, int maa[tam][tam], int mbb[tam][tam], int mcc[tam][tam]);
void chequeoMatrizC(int mc1[100][100]);


int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);



    matricesLlenado(ma,1);
	printf("\nMatriz ma creada.\n");
	matricesLlenado(mb,1);
	printf("\nMatriz mb creada.\n");
	matricesLlenado(mc,0);
	printf("\nMatriz mc creada.\n");
	printf("\n");
	//imprimirMatrices(ma);
	for(imain=0;imain<tam;imain++){
		for(jmain=0;jmain<tam;jmain++){
			CmatrizCoordenadas(imain,jmain,ma,mb,mc);
		}
	}
	/*CmatrizCoordenadas(0,0,ma,mb,mc);
	CmatrizCoordenadas(73,73,ma,mb,mc);*/
	//imprimirMatriz(mc);
	printf("\n AFEASDF\n");
	imprimirMatriz(mc);
	//imprimirCoorHechas(aux.coorC_a,aux.coorC_b);




    // Finalize the MPI environment.
    MPI_Finalize();
}

void matricesLlenado(int a[tam][tam], int num){
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			a[i][j]=num;
			printf("%d",a[i][j]);
		}	
	}
}

void imprimirMatriz(int b[tam][tam]){
	/*for(i=0;i<100;i++){
		printf("\nFila terminada.\n");
		for(j=0;j<100;j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}*/
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			printf("%d ",b[i][j]);
		}	
	}
	printf("\n");
}

void CmatrizCoordenadas(int c, int d, int maa[tam][tam], int mbb[tam][tam], int mcc[tam][tam]){
	//printf("\nDebbugeo 0.\n");
	int aux1=0;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			mcc[c][d] = 0;
			for(k=0;k<tam;k++){
				mcc[c][d]=mcc[c][d]+maa[i][k]*mbb[k][j];
			} 
			//printf("\nDebbugeo 1. %d\n",j);
		}
	}
	printf("\n%d \n",mcc[c][d]);
	aux.coorC_a=c;
	aux.coorC_b=d;
	imprimirCoorHechas(aux.coorC_a,aux.coorC_b);
	//printf("\nDebbugeo 2.\n");
	/*while(1){
		for(i=0;i<100;i++){
			for(j=0;j<100;j++){
				if(mcc[i][j]==0){
					aux.coorC_a=i;
					aux.coorC_b=j;
					printf("\nCoordenada de mc creada.\n");
					break;
				}
				if(j==99){
					break;
				}
			}
		}
	}*/
}

void imprimirCoorHechas(int g,int f){
	printf("\nPrimer coordenada: %d\n",g);
	printf("\nSegunda coordenada: %d\n",f);
}

void chequeoMatrizC(int mc1[tam][tam]){
	
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(mc1[i][j]==0){
				coorfal.coorC_a=i;
				coorfal.coorC_b=j;
				printf("Encontrada matriz distinta a 0.\n");
			}
		}
	}
}