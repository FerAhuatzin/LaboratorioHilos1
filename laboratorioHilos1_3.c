#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int array[5]={0};

//lectura arreglo
void*consumer() {
	int notFound = 1;
	int i = 0;
	while (notFound) {
		if (array[i]!=0) {
			if (i==4) {
				printf("El valor colocado en la posicion %d (ultima) es %d\n", i, array[i]);
				array[i] = 0;
				notFound = 0;
			} //end if
			else {
				printf("El valor colocado en la posicion %d es %d\n", i, array[i]);
				array[i] = 0;
			} //end else
		} //end if
		
		if (i==4) {
			i=0;
		} //end if
		else {
			i++;
		} //end else
		
	} //end while
	pthread_exit(NULL);
} //end consumer

///escritura arreglo
void producer () {
	int numberBuffer;
 	for (int i=0; i<5;i++) {
 		sleep(1);
 		printf("Escribe el numero a colocar en el arreglo: \n");
    	scanf("%d",&numberBuffer);
    	array[i] = numberBuffer;
    } //end for
} //end producer


int main () {
	//creacion hilo
	pthread_t pthreadA;
	int stateA = pthread_create(&pthreadA,NULL,consumer,NULL);
	if (stateA != 0) {
            perror("pthread_create() error.");
            exit(-1);
    } //end if
    producer();
    pthread_join(pthreadA, NULL);
    printf("Hemos terminado");
    return 0;
} //end main
