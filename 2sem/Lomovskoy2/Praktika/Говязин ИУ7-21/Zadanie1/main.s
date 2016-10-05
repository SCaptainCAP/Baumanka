	.file	"main.c"
	.globl	global
	.data
	.align 4
	.type	global, @object
	.size	global, 4
global:
	.long	5
	.comm	arra,20,16
	.globl	initi
	.align 8
	.type	initi, @object
	.size	initi, 12
initi:
	.long	1
	.long	2
	.long	3
	.text
	.globl	multiplicate
	.type	multiplicate, @function
multiplicate:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	movss	-4(%rbp), %xmm0
	mulss	-8(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	multiplicate, .-multiplicate
	.section	.rodata
.LC0:
	.string	"Input number to multi: "
.LC1:
	.string	"%f"
.LC3:
	.string	"Result: %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-12(%rbp), %eax
	movss	.LC2(%rip), %xmm1
	movl	%eax, -20(%rbp)
	movss	-20(%rbp), %xmm0
	call	multiplicate
	movd	%xmm0, %eax
	movl	%eax, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	$.LC3, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC2:
	.long	1090519040
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2.1) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
