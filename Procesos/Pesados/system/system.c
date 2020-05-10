#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
    char *binaryPath = "/bin/ls";
    system(binaryPath);
    printf("ESTA LINEA YA SE EJECUTA\n");
    return EXIT_SUCCESS;    
}
