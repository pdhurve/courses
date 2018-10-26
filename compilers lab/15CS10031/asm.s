	.file	"test.c"
	.text	
	.globl	fib
	.type	fib, @function
fib: 
.LFB0:
	.cfi_startproc
	pushl 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subl	$56, %rsp
	movl	$1, %rax
	movl 	%rax, -4(%rbp)
	movl	8(%rbp), %rax
	cmpl	-4(%rbp), %rax
	jle .L2
	jmp .L3
	jmp .L3
.L2: 
	nop
	jmp .L3
.L3: 
	movl	$1, %rax
	movl 	%rax, -16(%rbp)
	movl 	8(%rbp), %rax
	movl 	-16(%rbp), %rdx
	subl 	%rdx, %rax
	movl 	%rax, -24(%rbp)
	movl 	-24(%rbp), %rax
	movl 	%rax, 0(%rsp)
	call	fib
	movl	%rax, -28(%rbp)
	movl	$2, %rax
	movl 	%rax, -32(%rbp)
	movl 	8(%rbp), %rax
	movl 	-32(%rbp), %rdx
	subl 	%rdx, %rax
	movl 	%rax, -40(%rbp)
	movl 	-40(%rbp), %rax
	movl 	%rax, 0(%rsp)
	call	fib
	movl	%rax, -44(%rbp)
	movl 	-28(%rbp), %rax
	movl 	-44(%rbp), %rdx
	addl 	%rdx, %rax
	movl 	%rax, -52(%rbp)
	movl	-52(%rbp), %rax
	.globl	mul
	.type	mul, @function
mul: 
.LFB0:
	.cfi_startproc
	pushl 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subl	$16, %rsp
	movl 	8(%rbp), %rax
	imull 	12(%rbp), %rax
	movl 	%rax, -8(%rbp)
	movl	-8(%rbp), %rax
	.globl	main
	.type	main, @function
main: 
.LFB0:
	.cfi_startproc
	pushl 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subl	$97, %rsp
	movl	$3, %rax
	movl 	%rax, -8(%rbp)
	movl	-8(%rbp), %rax
	movl 	%rax, -4(%rbp)
	movl	$4, %rax
	movl 	%rax, -16(%rbp)
	movl	-16(%rbp), %rax
	movl 	%rax, -12(%rbp)
	movl	$1, %rax
	movl 	%rax, -28(%rbp)
	movl 	-4(%rbp), %rax
	movl 	%rax, 0(%rsp)
	movl 	-12(%rbp), %rax
	movl 	%rax, 4(%rsp)
	call	mul
	movl	%rax, -32(%rbp)
	movl 	-32(%rbp), %rax
	movl 	%rax, 0(%rsp)
	movl 	-12(%rbp), %rax
	movl 	%rax, 4(%rsp)
	call	mul
	movl	%rax, -36(%rbp)
	movl	-36(%rbp), %rax
	movl 	%rax, -20(%rbp)
	movl	$1, %rax
	movl 	%rax, -52(%rbp)
	movl 	-20(%rbp), %rax
	movl 	-52(%rbp), %rdx
	subl 	%rdx, %rax
	movl 	%rax, -60(%rbp)
	movl 	-60(%rbp), %rax
	movl 	%rax, 0(%rsp)
	call	fib
	movl	%rax, -64(%rbp)
	movl	$1, %rax
	movl 	%rax, -68(%rbp)
	movl 	-20(%rbp), %rax
	movl 	-68(%rbp), %rdx
	subl 	%rdx, %rax
	movl 	%rax, -76(%rbp)
	movl 	-76(%rbp), %rax
	movl 	%rax, 0(%rsp)
	call	fib
	movl	%rax, -80(%rbp)
	movl 	-80(%rbp), %rax
	movl 	%rax, 0(%rsp)
	call	fib
	movl	%rax, -84(%rbp)
	movl 	-64(%rbp), %rax
	movl 	-84(%rbp), %rdx
	addl 	%rdx, %rax
	movl 	%rax, -92(%rbp)
	movl	-92(%rbp), %rax
	movl 	%rax, -40(%rbp)
	movl 	-40(%rbp), %rax
	movl 	%rax, 0(%rsp)
	call	fib
	movl	%rax, -97(%rbp)
	movl	-97(%rbp), %rax
	movl 	%rax, -96(%rbp)
	nop
	.ident		"Compiled by Pankaj Dhurve"
	.section	.note.GNU-stack,"",@progbits
