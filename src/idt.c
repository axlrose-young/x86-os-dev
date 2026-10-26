#include <stdint.h>
#include <stddef.h>

/*
 *  Sets the idt pointer and the table
 *
 */

struct idt_ptr {
	uint16_t size;
	uint32_t offset;
}__attribute__((packed));

struct idt_table {
	uint16_t offset_low;
	uint16_t selector;
	uint8_t reserved;
	uint8_t type;
	uint16_t offset_high;
}__attribute__((packed));

struct idt_table idt[256] = {0};
struct idt_ptr idtr = {0};

/* address of isr entry point */
extern void isr0(void);
extern void isr1(void);

/* helper function: sets idt entry */ 
static void 
idt_set_entry(size_t index, uint32_t isr_addr, uint16_t selector, uint8_t type)
{
	idt[index].offset_low = isr_addr & 0xffff;
	idt[index].offset_high = (isr_addr >> 16) & 0xffff;
	idt[index].type = type;
	idt[index].selector = selector; 
}

void
idt_init(void)
{
	/* index, address of isr, CS, type of gate */
	idt_set_entry(0, (uint32_t)isr0, 0x08, 0x8f); 	
	idt_set_entry(1, (uint32_t)isr1, 0x08, 0x8f);	

	idtr.size = (uint16_t)sizeof(idt) - 1;
	idtr.offset = (uint32_t) idt; 
	__asm__ volatile (
		"lidt [%0]"
		: 
		: "r"(&idtr)
		: "memory" 
	);
}
