#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
pid_t padre = getpid();
int i;
fork();
if(getpid() == padre)
{
printf("soy el proceso padre %i\n",padre);


for(i=1;i<=10;i++)
{
printf("2x%i=%i\n",i,2*i);
}
} 
else
{
printf("soy el proceso hijo %i\n",getpid());
for(i=1;i<=10;i++)
{	
printf("3x%i=%i\n",i,2*i);
}



}


}	

