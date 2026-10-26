.intel_syntax noprefix

.macro isr num
.global isr\num

isr\num:			# respective isr address for idt
	pushad 
	cld			# Clears the DF flag before C code entry
	push \num	
	call isr_handler
	add esp, 4		# Pop the pushed number 
	popad
	iret
.endm

# Invoking all isrs
isr 0	
isr 1	
