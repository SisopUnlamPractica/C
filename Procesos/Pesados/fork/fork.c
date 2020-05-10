#include<stdio.h>
#include<sys/types.h>       //pid_t
#include<unistd.h>          //fork
#include<sys/wait.h>        //wait
#include<stdlib.h>
#define ERROR_FORK -1
int main() {
    pid_t pid_hijo, pid;
    pid_hijo = fork(); //syscall para crear nuevo proceso (COPIA PCB)
    // LOS PID SON POSITIVOS
    if ( pid_hijo == ERROR_FORK ) {
        perror("error al crear el nuevo proceso");
        return EXIT_FAILURE;
    }
    pid = getpid();
    if ( pid_hijo == 0 ){
        pid_t parent_pid = getppid();
        printf("soy %d hijo de %d\n", pid, parent_pid);
    }
    else {
        printf("soy %d padre de %d\n", pid, pid_hijo);
        wait(NULL); //join
    }
    return EXIT_SUCCESS;    
}
