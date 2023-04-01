#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int resultA, resultB, resultC;

//multiplicacion dividida por hilos
void *multiplyFromTo1 () {
	resultA = (1*2*3);
} //end multiplyFromTo

void *multiplyFromTo2 () {
	resultB = (4*5*6);
} //end multiplyFromTo

void *multiplyFromTo3 () {
	resultC = (7*8*9);
} //end multiplyFromTo

int main () {

	pthread_t pthreadA, pthreadB, pthreadC;
	
	//creacion de hilos
	int state = pthread_create(&pthreadA,NULL, multiplyFromTo1, NULL);
	pthread_join(pthreadA, NULL);
	
	if (state != 0) 
        {
            perror("pthread_create() error.");
            exit(-1);
        }
	
	state = pthread_create(&pthreadB,NULL, multiplyFromTo2, NULL);
	pthread_join(pthreadB, NULL);
	
	if (state != 0) 
        {
            perror("pthread_create() error.");
            exit(-1);
        }
        
	state = pthread_create(&pthreadC,NULL, multiplyFromTo3, NULL);
	pthread_join(pthreadC, NULL);
	
	if (state != 0) 
        {
            perror("pthread_create() error.");
            exit(-1);
        }
	
	//union resultado hilos
	printf("El resultado del factorial de 9 es: %d\n", resultA*resultB*resultC);
	
	return 0;

} //end main
