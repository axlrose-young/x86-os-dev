#ifndef IDT_ITEMS_H
#define IDT_ITEMS_H

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
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr_err8(void);
extern void isr9(void);
extern void isr_err10(void);
extern void isr_err11(void);
extern void isr_err12(void);
extern void isr_err13(void);
extern void isr_err14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr_err17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr_err21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);

#endif
