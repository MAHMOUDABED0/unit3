//mahmoud abed

#define sysctl (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR  (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA (*((volatile unsigned long*)0x4002553FC))
int main () {
	volatile long delay ;
	 sysctl = 0x20 ;
	 	for(delay=0;delay<2000;delay++) ;
	 GPIO_PORTF_DIR |= 1<<3 ; 
	GPIO_PORTF_DEN |= 1<<3 ;
	while(1)
	{
				GPIO_PORTF_DATA |= 1<<3 ;
	for(delay=0;delay<2000;delay++) ;
				GPIO_PORTF_DATA&= ~(1<<3) ;
	for(delay=0;delay<2000;delay++) ;
	}
	return 0;
	}