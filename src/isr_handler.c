/*
 * Two functions to handle execeptions with err code
 * and no err code
 *
 */


#include <stdint.h>
#include <io.h>

void 
isr_handler_no_err(uint32_t num) 
{

	switch(num) {
		default:
			kprintf("ISR number %d\n",num);
			__asm__ volatile ("cli;hlt");
			break;
	}

}

void
isr_handler_err (uint32_t num, uint32_t err)
{
	switch(num) {
		default:
			kprintf("ISR number %d\n",num);
			kprintf("Err code %d\n",err);
			__asm__ volatile ("cli;hlt");
			break;
	}
}

