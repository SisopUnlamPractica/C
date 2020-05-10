#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "./config.h"
int main() {
   char readbuf[TAMBUF];
   int read_bytes;
   //crear fifo en caso de que no exista
   mkfifo(FIFO_FILE, S_IFIFO|0640);
   //abrir el fifo
   int fd = open(FIFO_FILE, O_RDWR);
   while(1) {
      //leer fifo
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      //poner fin de cadena para no imprimir basura
      readbuf[read_bytes] = '\0';
      printf("FIFOSERVER: RECV: %s\n", readbuf);
      //si el cliente envia end se termina la com
      if (strcmp(readbuf, "end") == 0)
         break;
      printf("FIFOSERVER: SEND %s\n", readbuf);
      //escribir lo que recivi
      write(fd, readbuf, strlen(readbuf));
      //hasta ver sem, es para no recuperar lo que escribi
      sleep(2);
   }
   close(fd);
   return 0;
}
