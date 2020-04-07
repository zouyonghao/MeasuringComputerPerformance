%define P1 rdi
%define P2 rsi
%define P3 rdx
%define P4 rcx

bits	64
cpu	ia64

global	Reader
global	_Reader

	section .text
;------------------------------------------------------------------------------
; Name:		Reader
; Purpose:	Reads 64-bit values sequentially from an area of memory.
; Params:	P1 = ptr to memory area
; 		P2 = length in bytes
; 		P3 = loops
;------------------------------------------------------------------------------
	align 64
Reader:
_Reader:
	push	r10

	add	P2, P1	; P2 now points to end.

.L1:
	mov	r10, P1

.L2:
	mov	rax, [r10]
	mov	rax, [8+r10]
	mov	rax, [16+r10]
	mov	rax, [24+r10]
	mov	rax, [32+r10]
	mov	rax, [40+r10]
	mov	rax, [48+r10]
	mov	rax, [56+r10]
	mov	rax, [64+r10]
	mov	rax, [72+r10]
	mov	rax, [80+r10]
	mov	rax, [88+r10]
	mov	rax, [96+r10]
	mov	rax, [104+r10]
	mov	rax, [112+r10]
	mov	rax, [120+r10]
	mov	rax, [128+r10]
	mov	rax, [136+r10]
	mov	rax, [144+r10]
	mov	rax, [152+r10]
	mov	rax, [160+r10]
	mov	rax, [168+r10]
	mov	rax, [176+r10]
	mov	rax, [184+r10]
	mov	rax, [192+r10]
	mov	rax, [200+r10]
	mov	rax, [208+r10]
	mov	rax, [216+r10]
	mov	rax, [224+r10]
	mov	rax, [232+r10]
	mov	rax, [240+r10]
	mov	rax, [248+r10]

	add	r10, 256
	cmp	r10, P2
	jb	.L2

	dec	P3
	jnz	.L1

	pop	r10
	ret