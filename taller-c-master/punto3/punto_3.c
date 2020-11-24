#include <stdio.h>
#include <gmp.h>

// Functions declarations
void handle( mpz_t n );
int esPerfecto( int n );
void calculate( mpz_t n );

int main(){

    mpz_t num;

    // Initialize num
    mpz_init(num);
    mpz_set_ui(num, 0);

    printf("Digite cantidad: ");
    mpz_inp_str(num, stdin, 10);        // Read through stdin, in base 10 and assign value to num
    calculate(num);
    /*handle(num);*/

    return 0;
}

void calculate( mpz_t n )
{
    int counter = 0;
    int i=1;
    int general = 0;

    mpz_t num1 , op1 , op2 , num2 , op3 , op4 , result , con , mod;

    while(general <= mpz_get_ui(n))
    {  
       
        
            int contador = 0;
            int contador2 = 0;
            mpz_init(num1);
            mpz_init(op1);
            mpz_init(op2);

            mpz_init(con);
            mpz_init(result);


            mpz_init(num2);
            mpz_init(op3);
            mpz_init(op4);

            mpz_init(mod);
            mpz_set_ui(mod, 1);

            mpz_set_ui(num1, 0);
            mpz_set_ui(op1, 2);
            mpz_set_ui(op2, i-1);
            mpz_set_ui(con, 1);
            mpz_set_ui(result, 0);

            mpz_set_ui(num2, 0);
            mpz_set_ui(op3, 2);
            mpz_set_ui(op4, i);

            mpz_pow_ui(num1,op1,i-1);
            mpz_pow_ui(num2,op3,i);

            mpz_sub (num2,num2,con);

            /* Valida que p sea primo*/
            for(int j = 1 ; j <= i ; j++)
            {
                if(i%j == 0)
                {
                    contador++;
                }
            }

            /* Valida que p sea primo*/
            for(int j = 1 ; j <= mpz_get_ui(num2) ; j++)
            {
                mpz_t mod;
                mpz_init(mod);
                mpz_mod_ui (mod,num2, j);
                if(mpz_get_ui(mod)==0)
                {
                    contador2++;
                }
                /*printf("Testing : r : %d\n",r);*/
            }
            
            
            if(contador==2 && contador2==2)
            {
                general++;
                mpz_mul(result,num1,num2);

                printf("Valor : %lu\n",mpz_get_ui(num1));
                printf("Valor : %lu\n",mpz_get_ui(num2));
                printf("Valor : %lu\n",mpz_get_ui(result));
                printf("i = %d\n",i);
            }
            
            i++;
        
        
    }
}

void handle( mpz_t n ){

    int counter = 0;
    int i=0;

    while(counter < mpz_get_ui(n)){
        if( esPerfecto(i) ) {
            printf("%d\n", i);
            counter++;
            printf("Counter : %d\n",counter);
        }
        printf("i : %d\n",i);
        i++;
    }

}

int esPerfecto( int n ){

    int acum = 0;

    for (int i = 1; i <= (n/2); i++)
    {
        if( n%i == 0 ) acum += i;
    }

    if( acum == n ) return 1;

    return 0;    
}
