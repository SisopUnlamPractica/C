#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>
int main(){
    sem_t *x = sem_open("/x",0);
    sem_t *y = sem_open("/y",0);
    for (int i=0; i<10; i++){
        sem_wait(y);
        sleep(1);
        printf("B\n");
        sem_post(x);
    }
    sem_close(x);
    sem_close(y);
    return 0;
}