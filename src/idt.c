#include <stdint.h>
#include <stddef.h>
#include "../private/idt_items.h"

/*
 *  Sets the idt pointer and the table
 *
 */

void (*isr[])(void) = {
	isr0, isr1, isr2, isr3, 
	isr4, isr5, isr6, isr7, 
	isr8, isr9, isr10, isr11, 
	isr12, isr13, isr14, isr15, 
	isr16, isr17, isr18, isr19, 
	isr20, isr21, isr22, isr23, 
	isr24, isr25, isr26, isr27, 
	isr28, isr29, isr30, isr31
};

/* helper function: sets idt entry */ 
static void 
idt_set_entry(size_t index, uint32_t isr_addr, uint16_t selector, uint8_t type)
{
	idt[index].offset_low = isr_addr & 0xffff;
	idt[index].offset_high = (isr_addr >> 16) & 0xffff;
	idt[index].type = type;
	idt[index].selector = selector; 
}

static void
idt_entry(void)
{
	for (size_t i = 0; i < 32; i++) {
		/* index, address of isr, CS, type of gate */
		idt_set_entry(i, (uint32_t)isr[i], 0x08, 0x8f); 
	}
}

void
idt_init(void)
{
	idt_entry(); /* Setting idt table entries */	

	idtr.size = (uint16_t)sizeof(idt) - 1;
	idtr.offset = (uint32_t) idt; 
	__asm__ volatile (
		"lidt [%0]"
		: 
		: "r"(&idtr)
		: "memory" 
	);
}
