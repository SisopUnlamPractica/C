#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void validateOpenPipe(int status){
    if (status == -1) {
        printf("Error al crear el pipe\n");
        exit(EXIT_FAILURE);
   }
}
int main() {
   int pipefds1[2], pipefds2[2];
   int pid;
   char pipe1writemessage[20] = "Hola hijo";
   char pipe2writemessage[20] = "Hola PA";
   char readmessage[20];
   validateOpenPipe( pipe(pipefds1) );
   validateOpenPipe( pipe(pipefds2) );
   pid = fork();
   if(pid == -1)
       return -1;
   if (pid == 0){ 
      close(pipefds1[0]);
      close(pipefds2[1]);
      printf("PAPI DICE: %s\n", pipe1writemessage);
      write(pipefds1[1], pipe1writemessage, sizeof(pipe1writemessage));
      read(pipefds2[0], readmessage, sizeof(readmessage));
      printf("PAPI ESCUCHA: %s\n", readmessage);
   } else { 
      close(pipefds1[1]); 
      close(pipefds2[0]); 
      read(pipefds1[0], readmessage, sizeof(readmessage));
      printf("HIJO ESCUCHA: %s\n", readmessage);
      printf("HIJO DICE %s\n", pipe2writemessage);
      write(pipefds2[1], pipe2writemessage, sizeof(pipe2writemessage));
   }
   return 0;
}