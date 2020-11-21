#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

pid_t padre = getpid();
int i;
fork();

if(padre == getpid()){
	for(i=1;i<=500;i++)
	{
		if((i%2)==0)
		if((i%3)==0) 
		
		printf("padre : %i es divisible por dos y por tres\n",i);
	}

}else{

	for(i=501;i<=1000;i++)
	{
		if((i%2)==0)
		if((i%3)==0)

		printf("hijo : %i es divisible por dos y por tres\n",i);
	}

}


}
