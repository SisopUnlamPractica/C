#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>
int main(){
    sem_t *x = sem_open("/x",O_CREAT|O_EXCL,0666,1);
    sem_t *y = sem_open("/y",O_CREAT|O_EXCL,0666,0);
    for (int i=0; i<10; i++){
        sem_wait(x);
        sleep(1);
        printf("A\n");
        sem_post(y);
    }
    sem_close(x);
    sem_close(y);
    sem_unlink("/x");
    sem_unlink("/y");
    return 0;
}