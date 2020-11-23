#include <navilnux.h>

void swiHandler(unsigned int syscallnum){
	printf("sys_call : %d \n", syscallnum);
}

void irqHandler(void){
	printf("We should not be here");
}

int main(void)
{
	while(1){
		__asm__("swi 77");
		msleep(1000);
	}
}	
