#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>

// Funcitons declarations
long long convertirABinario(int n);
int esPalindromo(long long n);

int main()
{

    long long binary;
    pid_t padre=getpid();
    int i;
    fork();

    if(getpid()==padre)
    {
            for (i = 0; i < 500000; i++)
            {
                binary = convertirABinario(i);

                // si es palindromo en decimal (i) Y es palindromo en binario
                if( esPalindromo(i) && esPalindromo(binary) ) printf("PADRE decimal=%d \t binario=%lld \n", i, binary);
            }
    }
    else
    {
        for (i = 500001; i < 1000000; i++)
        {
            binary = convertirABinario(i);

            // si es palindromo en decimal (i) Y es palindromo en binario
            if( esPalindromo(i) && esPalindromo(binary) ) printf("HIJO decimal=%d \t binario=%lld \n", i, binary);
        }
    }

    return 0;
}

long long convertirABinario(int n)
{
    long long binary = 0;
    int rem = 0;
    long long i = 1;

    while (n > 0)
    {
        rem = floor(n % 2);
        n = floor(n / 2);
        binary += rem * i;
        i *= 10;
    }

    return binary;
}

int esPalindromo(long long n)
{
    long long cifra = 0, reves = 0;
    long long copia = n;

    while (n != 0)
    {
        cifra = n % 10;
        reves = reves * 10 + cifra;
        n = n / 10;

    }

    return copia == reves;
}