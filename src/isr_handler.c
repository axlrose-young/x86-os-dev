#include <io.h>

void 
isr_handler(int num) 
{

	switch(num){
		case 0:
			kprintf("ISR number %d\n",num);
			__asm__ volatile ("hlt");
			break;
		default:
			kprintf("ISR number %d\n",num);
			__asm__ volatile ("hlt");
			break;
	}

}

