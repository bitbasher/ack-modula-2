.sect .text; .sect .rom; .sect .data; .sect .bss
.define _brk
.sect .text
_brk:
	mov	ax,17
	callf	0x7:0x0
	jb	1f
	mov	ax,4(sp)
	mov	(.limhp),ax
	xor	ax,ax
	ret
1:
	jmp	cerror
