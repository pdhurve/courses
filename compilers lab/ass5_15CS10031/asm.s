	.file	"test.c"
	.text	
	.globl	main
	.type	main, @function
main: 
.LFB0:
	.cfi_startproc
	pushl 	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl 	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$91, %esp
	movl	$9, %eax
	movl 	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	$18, %eax
	movl 	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl 	%eax, -12(%ebp)
	movl	0(%ebp), %eax
	movl 	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl 	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl 	%eax, -36(%ebp)
	movl	-4(%ebp), %eax
	movl 	%eax, -44(%ebp)
	movb	$112, -46(%ebp)
	movl	-46(%ebp), %eax
	movl 	%eax, -45(%ebp)
	negl	-4(%ebp)
	movl	-47(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jg .L2
	jmp .L3
	jmp .L3
.L2: 
	movl	-12(%ebp), %eax
	movl 	%eax, -79(%ebp)
	movl 	-12(%ebp), %eax
	movl 	0(%ebp), %edx
	subl 	%edx, %eax
	movl 	%eax, -12(%ebp)
	jmp .L3
.L3: 
	movl	-12(%ebp), %eax
	movl 	%eax, -83(%ebp)
	addl 	$1, -12(%ebp)
	movl	-12(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	-12(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	$0, %eax
	movl 	%eax, -95(%ebp)
	movl	-95(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident		"Compiled by Aseem Patni"
	.section	.note.GNU-stack,"",@progbits
