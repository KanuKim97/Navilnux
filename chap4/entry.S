.globl _ram_entry
 _ram_entry:
    bl  main
	b   _ram_entry
    b   navilnux_swiHandler
    b   navilnux_irqHandler


.global navilnux_swiHandler
navilnux_swiHandler:
	mov r0, #77
	bl	swiHandler

.global navilnux_irqHandler
navilnux_irqHandler:   
	bl	irqHandler
