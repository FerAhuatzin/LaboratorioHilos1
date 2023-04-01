#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int array[12];
int subarrayA[4];
int subarrayB[4];
int subarrayC[4];
int foundFlag;
int numberToFind;


//procedimientos de busqueda en cada tercio del arreglo
void*findInA () {
	for(int i = 0; i<4;i++) {
		if (subarrayA[i]==numberToFind) {
			foundFlag = 1;
			pthread_exit(NULL);
		} //end if
	} //end for
	pthread_exit(NULL);
} //end findInA

void*findInB () {
	for(int i = 0; i<4;i++) {
		if (subarrayB[i]==numberToFind) {
			foundFlag = 1;
			pthread_exit(NULL);
		} //end if
	} //end for
	pthread_exit(NULL);
} //end findInB

void*findInC () {
	for(int i = 0; i<4;i++) {
		if (subarrayC[i]==numberToFind) {
			foundFlag = 1;
			pthread_exit(NULL);
		} //end if
	} //end for
	pthread_exit(NULL);
} //end findInC

int main () {

	int stateA,stateB,stateC;
	pthread_t pthreadA,pthreadB,pthreadC;
	
	//Llenando el arreglo principal y dividiendolo en 3 subarreglos
	for (int i = 0; i<12; i++) {
		array[i]=i;
	} //end for
	for (int i = 0; i<4; i++) {
		subarrayA[i]=array[i];
		subarrayB[i]=array[i+4];
		subarrayC[i]=array[i+8];
	} //end for
	
	printf("Escribe el numero que quieres buscar en el arreglo: ");
	scanf("%d", &numberToFind);
	
	//creacion de hilos de busqueda
	stateA = pthread_create(&pthreadA,NULL,findInA,NULL);
	if (stateA != 0) {
            perror("pthread_create() error.");
            exit(-1);
    }
    stateB = pthread_create(&pthreadB,NULL,findInB,NULL);
	if (stateB != 0) {
            perror("pthread_create() error.");
            exit(-1);
    }
    
    stateC = pthread_create(&pthreadC,NULL,findInC,NULL);
	if (stateC != 0) {
            perror("pthread_create() error.");
            exit(-1);
    }
    
    pthread_join(pthreadA, NULL);
    pthread_join(pthreadB, NULL);
    pthread_join(pthreadC, NULL);
    
    //comprobacion si se encontro el elemento
    if (foundFlag) {
    	printf("Uno de mis hilos encontro el numero a buscar");
    } //end if
    else {
    	printf("Ninguno de mis hilos encontro el numero a buscar");
    } //end else
    
	return 0;
} //end main
