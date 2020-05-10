#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
    char *binaryPath = "/bin/ls";
    char *args[] = {binaryPath, NULL};
    execv(binaryPath, args);
    printf("ESTA LINEA YA NO SE EJECUTA\n");
    return EXIT_SUCCESS;    
}
