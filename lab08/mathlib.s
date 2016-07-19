; mathlib.s
;
	
	global product
	global power
	global umm

	section .text

;
; mathlib
; Parameter 1  - [ebp+8] int x.
; Parameter 2  - [ebp+12] int y.
; Product Return value - x*y.
; Power Return value - x^y
;

product:
	; Standard prologue
	push	ebp		; save base pointer
	mov 	ebp, esp	; set ebp to stack pointer
	sub	esp, 4		; clear space for local variable
	push	ebx		; ebx must be saved
	mov	ebx, [ebp+12]	; Store value for y in ebx
	xor	eax, eax	; eax = 0
	cmp	ebx, 0		; if y = 0 return 0
	jle	product_done	;

product_loop:
	add	eax, [ebp+8]	; add x to eax
	dec	ebx		; decrease y by 1
	cmp	ebx, 0		; repeat untill y = 0
	jg	product_loop	;

product_done:
	; Standard epilogue
	pop 	ebx		; Restore ebx.
	mov 	esp, ebp	; set esp to stack pointer
	pop	ebp		; restore base pointer
	ret			; Return to the caller.


power:
	; 	Standard prologue
	push	ebp		; save base pointer
	mov 	ebp, esp	; set ebp to stack pointer
	sub	esp, 4		; clear space for local variable
	mov	edx, [ebp+12]	; set edx = y
	mov	ecx, [ebp+8]	; set ecx = x
	cmp 	edx, 0	  	; if y > 0, recurse
	ja  	power_loop  	;
	mov 	eax, 1  	; Otherwise return 1.
	mov 	esp, ebp	; set esp = stack pointer
	pop	ebp		; restore base pointer
	ret 			; return 1

power_loop:
	dec 	edx 		; decrease y by 1
	push 	edx		; push y onto stack
	push	ecx		; push x onto stack
	call	power   	; repeat until y = 0, eax = 1
	mov 	edx, eax	; set y = eax
	push 	edx		; push y onto stack
	push	ecx		; push x onto stack
	call	product 	; call product with x and y. eax = x*y
	mov 	esp, ebp	; set esp = stack pointer
	pop	ebp		; restore base pointer
	ret			; return eax

umm:
	push	ebp		; save base pointer
	mov 	ebp, esp	; set ebp to stack pointer
	and	esp, -16	;
	sub	esp, 80		;
	mov	eax, [esp]	;
	mov	esp, ebp	;
	pop	ebp		;
	ret			;
	











