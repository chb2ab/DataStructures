; mathlib.s
;
	
	global testes

	section .text

;
; mathlib
; Parameter 1  - [ebp+8] int x.
; Parameter 2  - [ebp+12] int y.
; Product Return value - x*y.
; Power Return value - x^y
;

testes:
        mov     eax, [esp+4]		; n
        cmp	eax, 1			; n <= 1
        jnle	L1			; if not, go do a recursive call
        mov	eax, 1			; otherwise return 1
        jmp	L2
L1:
	dec	eax			; n-1
	push	eax			; push argument
	call	_factorial		; do the call, result goes in eax
	add	esp, 4			; get rid of argument
	imul	eax, [esp+4]		; n * factorial(n-1)
L2:
	ret











