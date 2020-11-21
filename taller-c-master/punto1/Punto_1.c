#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Funciton declaration
void replace(char ch, FILE* filePointer);

int main()
{
    FILE *filePointer;
    char ch;
    int counter = 0;
    pid_t padre = getpid();

    filePointer = fopen("biblia.txt", "r+");
    fork();

    if(getpid() == padre)
    {
        printf("Empezando proceso padre \n");
        while ((ch = fgetc(filePointer)) != EOF)
        {
       
            
            if( ch == 'A' ) {
                ch = 'E';
                replace(ch, filePointer);
                counter++;
            }
        }  
    }
    else
    {
        printf("Empezando proceso hijo \n");
        while ((ch = fgetc(filePointer)) != EOF)
        {
            if( ch == 'a' ) {
                ch = 'i';
                replace(ch, filePointer);
                counter++;
            }
        }
    }

    fclose(filePointer);

    printf("Cantidad de caracteres reemplazados: %d\n", counter);

    return 0;
}

void replace(char ch, FILE* filePointer){
    // set file pointer position to previous position, so we can replace actual character
    fseek(filePointer, ftell(filePointer) - 1, SEEK_SET);

    // Replace
    fputc(ch, filePointer);
}