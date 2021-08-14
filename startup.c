
#include"stdint.h"
extern int main();
void Reset_Handler();
void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler ()__attribute__ ((weak,alias("Default_Handler")));;
void H_Fault_Handler ()__attribute__ ((weak,alias("Default_Handler")));;

static unsigned long stack_p[256];
void ( * const g_f_vectors[])()__attribute__((section(".vectors"))) = {
(void (*)()) ((unsigned long)stack_p + sizeof(stack_p)),
	 &Reset_Handler,
	 &NMI_Handler,
	 &H_Fault_Handler,
	};

extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
int i;


void Reset_Handler()
{
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	for( i=0;i<DATA_SIZE;i++)
	{
		*((unsigned char*)P_dst++)=*((unsigned char*)P_src);
	}
	unsigned int bss_SIZE = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst=(unsigned char*)&_S_bss;
	for( i=0;i<DATA_SIZE;i++)
	{
		*((unsigned char*)P_dst++)=(unsigned char*)0;
	}
	main();
};