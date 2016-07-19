; mathlib.s
; One optimization was cutting redundant code to reduce the number of commands used, redundant code included setting eax = 0 twice, once at the beginning of the program and again if x = 1. Another optimization was using a single lea command to perform the operation 3x + 1, instead of using two seperate multiply and add commands. Another optimization was storing the x variable in a register instead of using it directly from the stack. Registers are the fastest possible access, so it is faster to operate with a register than from the stack.
	
	global threexplusone

	section .text

;
; mathlib
; Parameter 1  - [ebp+8] int x.
; Return value - int.
;

threexplusone:
	; Standard callee prologue
	push	ebp			; save base pointer
	mov 	ebp, esp		; set ebp to stack pointer
	sub	esp, 4			; clear space for local variable
	push	ebx			; ebx must be saved
	; End callee prologue
	mov	ebx, [ebp+8]		; Store value for x in ebx
	cmp	ebx, 1			; if x = 1 return 0
	jle	threexplusone_done	;
	bt	ebx, 0			; if x is odd recurse with 3x + 1
	jc	threexplusone_odd	;
	shr	ebx, 1			; if x is even divide ebx by 2
	; Standard caller prologue
	push	ebx			; push parameter x onto stack
	call	threexplusone		; recursive call
	; end caller prologue
	; Standard caller epilogue
	add 	esp, 4     		; clean up stack
	; end caller epilogue
	add	eax, 1			; add 1 to eax for each recursive call
	; Standard callee epilogue
	pop 	ebx			; Restore ebx.
	mov 	esp, ebp		; set esp to stack pointer
	pop	ebp			; restore base pointer
	ret				; Return to the caller.
	; End callee epilogue	

threexplusone_odd:
	lea	ebx, [3*ebx + 1]	; x = 3 * x + 1
	push	ebx			; push parameter x onto stack
	call	threexplusone		; recursive call
	add 	esp, 4     		; clean up stack
	add	eax, 1			; add 1 to eax for each recursive call
	; Standard callee epilogue
	pop 	ebx			; Restore ebx.
	mov 	esp, ebp		; set esp to stack pointer
	pop	ebp			; restore base pointer
	ret				; Return to the caller.
	; End callee epilogue	

threexplusone_done:
	xor	eax, eax		; eax = 0
	; Standard callee epilogue
	pop 	ebx			; Restore ebx.
	mov 	esp, ebp		; set esp to stack pointer
	pop	ebp			; restore base pointer
	ret				; Return to the caller.
	; End callee epilogue	











