#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "./config.h"
int main() {
   int stringlen;
   int read_bytes;
   char readbuf[TAMBUF];
   int fd = open(FIFO_FILE, O_CREAT|O_RDWR);
   while (1) {
      printf("EscribaMensaje: ");
      fgets(readbuf, sizeof(readbuf), stdin);
      stringlen = strlen(readbuf);
      readbuf[stringlen - 1] = '\0';
      if ( strcmp(readbuf, "end") == 0) 
         break;
      write(fd, readbuf, strlen(readbuf));
      printf("FIFOCLIENT: Send %s\n", readbuf);
      //hasta ver sem, es para no recuperar lo que escribi
      sleep(1);
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0';
      printf("FIFOCLIENT: RECV: %s (%d chars)\n", readbuf, (int)strlen(readbuf));
   }
   write(fd, readbuf, strlen(readbuf));
   printf("FIFOCLIENT: SEND: %s\n", readbuf);
   close(fd);
   return 0;
}