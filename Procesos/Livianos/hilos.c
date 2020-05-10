#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
int global_var = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 1
void *codeThread ( void *name ) {
    pthread_mutex_lock ( &mutex ); //P(mutex)
    printf ("Nombre del hilo: %s \n", ( char * ) name);
    global_var ++;
    pthread_mutex_unlock ( &mutex );
    pthread_exit ( 0 );
}
int main () {
    pthread_t hilo1, hilo2; //unsigned long int

    printf( "global_var= %d \n", global_var );
    
    pthread_create ( &hilo1, NULL, &codeThread, ( void * )"HILO1");
    pthread_create ( &hilo1, NULL, &codeThread, ( void * )"HILO2");

    pthread_join( hilo1, NULL );
    pthread_join( hilo2, NULL );
    
    pthread_mutex_destroy ( &mutex );

    printf( "global_var= %d \n", global_var );

    return EXIT_SUCCESS;
}