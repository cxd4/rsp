	.file	"rsp.c"
	.text
	.p2align 2,,3
	.def	_VABS;	.scl	3;	.type	32;	.endef
_VABS:
LFB26:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %eax
	movl	16(%esp), %edx
	movl	20(%esp), %ecx
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR(%ebx)
	jl	L2
	je	L3
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC
L4:
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+2(%ebx)
	jl	L5
L29:
	je	L6
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+4(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+8
L7:
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+4(%ebx)
	jl	L8
L30:
	je	L9
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+8(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+16
L10:
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+6(%ebx)
	jl	L11
L31:
	je	L12
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+12(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+24
L13:
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+8(%ebx)
	jl	L14
L32:
	je	L15
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+16(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+32
L16:
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+10(%ebx)
	jl	L17
L33:
	je	L18
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+20(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+40
L19:
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+12(%ebx)
	jl	L20
L34:
	je	L21
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+24(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+48
L22:
	sall	$4, %eax
	cmpw	$0, _VR+14(%eax)
	jl	L28
L23:
	jne	L25
	movw	$0, _VACC+56
L24:
	movl	8(%esp), %eax
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	movl	_VACC+56, %edx
	movw	%dx, _VR+14(%eax)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L3:
	.cfi_restore_state
	movw	$0, _VACC
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+2(%ebx)
	jge	L29
L5:
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+4(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	negl	%ebx
	movw	%bx, _VACC+8
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+4(%ebx)
	jge	L30
L8:
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+8(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	negl	%ebx
	movw	%bx, _VACC+16
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+6(%ebx)
	jge	L31
L11:
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+12(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	negl	%ebx
	movw	%bx, _VACC+24
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+8(%ebx)
	jge	L32
L14:
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+16(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	negl	%ebx
	movw	%bx, _VACC+32
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+10(%ebx)
	jge	L33
L17:
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+20(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	negl	%ebx
	movw	%bx, _VACC+40
	movl	%eax, %ebx
	sall	$4, %ebx
	cmpw	$0, _VR+12(%ebx)
	jge	L34
L20:
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei+24(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	negl	%ebx
	movw	%bx, _VACC+48
	sall	$4, %eax
	cmpw	$0, _VR+14(%eax)
	jge	L23
L28:
	sall	$5, %ecx
	movl	_ei+28(%ecx), %eax
	leal	(%eax,%edx,8), %eax
	movw	_VR(%eax,%eax), %ax
	negl	%eax
	movw	%ax, _VACC+56
	jmp	L24
	.p2align 2,,3
L25:
	sall	$5, %ecx
	movl	_ei+28(%ecx), %eax
	leal	(%eax,%edx,8), %eax
	movw	_VR(%eax,%eax), %ax
	movw	%ax, _VACC+56
	jmp	L24
	.p2align 2,,3
L21:
	movw	$0, _VACC+48
	jmp	L22
	.p2align 2,,3
L18:
	movw	$0, _VACC+40
	jmp	L19
	.p2align 2,,3
L15:
	movw	$0, _VACC+32
	jmp	L16
	.p2align 2,,3
L12:
	movw	$0, _VACC+24
	jmp	L13
	.p2align 2,,3
L9:
	movw	$0, _VACC+16
	jmp	L10
	.p2align 2,,3
L6:
	movw	$0, _VACC+8
	jmp	L7
	.p2align 2,,3
L2:
	movl	%ecx, %ebx
	sall	$5, %ebx
	movl	_ei(%ebx), %ebx
	leal	(%ebx,%edx,8), %ebx
	movw	_VR(%ebx,%ebx), %bx
	negl	%ebx
	movw	%bx, _VACC
	jmp	L4
	.cfi_endproc
LFE26:
	.p2align 2,,3
	.def	_VADD;	.scl	3;	.type	32;	.endef
_VADD:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	84(%esp), %edx
	movl	92(%esp), %eax
	movl	_VCO, %ebx
	sall	$4, %edx
	movswl	_VR(%edx), %edi
	sall	$5, %eax
	movl	88(%esp), %ecx
	sall	$3, %ecx
	movl	_ei(%eax), %esi
	addl	%ecx, %esi
	movswl	_VR(%esi,%esi), %esi
	addl	%esi, %edi
	movl	%ebx, %esi
	andl	$1, %esi
	addl	%edi, %esi
	movl	%esi, 12(%esp)
	movl	%ebx, %esi
	shrw	%si
	movswl	_VR+2(%edx), %ebp
	movl	_ei+4(%eax), %edi
	addl	%ecx, %edi
	movswl	_VR(%edi,%edi), %edi
	addl	%ebp, %edi
	andl	$1, %esi
	addl	%esi, %edi
	movl	%edi, 20(%esp)
	movl	%ebx, %esi
	shrw	$2, %si
	movswl	_VR+4(%edx), %ebp
	movl	_ei+8(%eax), %edi
	addl	%ecx, %edi
	movswl	_VR(%edi,%edi), %edi
	addl	%ebp, %edi
	andl	$1, %esi
	addl	%esi, %edi
	movl	%edi, 24(%esp)
	movl	%ebx, %esi
	shrw	$3, %si
	movswl	_VR+6(%edx), %ebp
	movl	_ei+12(%eax), %edi
	addl	%ecx, %edi
	movswl	_VR(%edi,%edi), %edi
	addl	%ebp, %edi
	andl	$1, %esi
	addl	%esi, %edi
	movl	%edi, 28(%esp)
	movl	%ebx, %esi
	shrw	$4, %si
	movswl	_VR+8(%edx), %ebp
	movl	_ei+16(%eax), %edi
	addl	%ecx, %edi
	movswl	_VR(%edi,%edi), %edi
	addl	%ebp, %edi
	andl	$1, %esi
	addl	%esi, %edi
	movl	%edi, 32(%esp)
	movl	%ebx, %esi
	shrw	$5, %si
	movswl	_VR+10(%edx), %ebp
	movl	_ei+20(%eax), %edi
	addl	%ecx, %edi
	movswl	_VR(%edi,%edi), %edi
	addl	%ebp, %edi
	andl	$1, %esi
	addl	%esi, %edi
	movl	%edi, 36(%esp)
	movl	%ebx, %esi
	shrw	$6, %si
	movswl	_VR+12(%edx), %ebp
	movl	_ei+24(%eax), %edi
	addl	%ecx, %edi
	movswl	_VR(%edi,%edi), %edi
	addl	%ebp, %edi
	andl	$1, %esi
	addl	%esi, %edi
	movl	%edi, 40(%esp)
	shrw	$7, %bx
	movswl	_VR+14(%edx), %edx
	addl	_ei+28(%eax), %ecx
	movswl	_VR(%ecx,%ecx), %eax
	addl	%edx, %eax
	andl	$1, %ebx
	addl	%eax, %ebx
	movl	%ebx, 44(%esp)
	movl	12(%esp), %eax
	movw	%ax, _VACC
	movl	80(%esp), %eax
	sall	$4, %eax
	cmpl	$32767, 12(%esp)
	jg	L36
	cmpl	$-32768, 12(%esp)
	jge	L61
	movw	$-32768, _VR(%eax)
	jmp	L38
	.p2align 2,,3
L36:
	movw	$32767, _VR(%eax)
L38:
	movl	20(%esp), %eax
	movw	%ax, _VACC+8
	cmpl	$32767, %eax
	jg	L39
	cmpl	$-32768, %eax
	jge	L62
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L41
	.p2align 2,,3
L39:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
L41:
	movl	24(%esp), %eax
	movw	%ax, _VACC+16
	cmpl	$32767, %eax
	jg	L42
	cmpl	$-32768, %eax
	jge	L63
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L44
	.p2align 2,,3
L42:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
L44:
	movl	28(%esp), %eax
	movw	%ax, _VACC+24
	cmpl	$32767, %eax
	jg	L45
	cmpl	$-32768, %eax
	jge	L64
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L47
	.p2align 2,,3
L45:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
L47:
	movl	32(%esp), %eax
	movw	%ax, _VACC+32
	cmpl	$32767, %eax
	jg	L48
	cmpl	$-32768, %eax
	jge	L65
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L50
	.p2align 2,,3
L48:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
L50:
	movl	36(%esp), %eax
	movw	%ax, _VACC+40
	cmpl	$32767, %eax
	jg	L51
	cmpl	$-32768, %eax
	jge	L66
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L53
	.p2align 2,,3
L51:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
L53:
	movl	40(%esp), %eax
	movw	%ax, _VACC+48
	cmpl	$32767, %eax
	jg	L54
	cmpl	$-32768, %eax
	jge	L67
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L56
	.p2align 2,,3
L54:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
L56:
	movl	44(%esp), %eax
	movw	%ax, _VACC+56
	cmpl	$32767, %eax
	jle	L57
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+14(%eax)
L58:
	movw	$0, _VCO
	addl	$60, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L57:
	.cfi_restore_state
	cmpl	$-32768, %eax
	jge	L59
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+14(%eax)
	jmp	L58
	.p2align 2,,3
L59:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+14(%edx)
	jmp	L58
	.p2align 2,,3
L67:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+12(%edx)
	jmp	L56
	.p2align 2,,3
L66:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+10(%edx)
	jmp	L53
	.p2align 2,,3
L65:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+8(%edx)
	jmp	L50
	.p2align 2,,3
L64:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+6(%edx)
	jmp	L47
	.p2align 2,,3
L63:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+4(%edx)
	jmp	L44
	.p2align 2,,3
L62:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+2(%edx)
	jmp	L41
	.p2align 2,,3
L61:
	movl	12(%esp), %edx
	movw	%dx, _VR(%eax)
	jmp	L38
	.cfi_endproc
LFE27:
	.p2align 2,,3
	.def	_VADDC;	.scl	3;	.type	32;	.endef
_VADDC:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %ebp
	movl	52(%esp), %ecx
	movl	60(%esp), %edx
	sall	$4, %ecx
	movzwl	_VR(%ecx), %ebx
	sall	$5, %edx
	movl	56(%esp), %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	addl	_ei(%edx), %eax
	movzwl	_VR(%eax,%eax), %eax
	addl	%ebx, %eax
	movl	%eax, 12(%esp)
	movw	%ax, _VACC
	movzwl	_VR+2(%ecx), %ebx
	movl	4(%esp), %eax
	addl	_ei+4(%edx), %eax
	movzwl	_VR(%eax,%eax), %eax
	addl	%ebx, %eax
	movl	%eax, 16(%esp)
	movw	%ax, _VACC+8
	movl	12(%esp), %ebx
	shrl	$16, %ebx
	shrl	$16, %eax
	sall	%eax
	orl	%ebx, %eax
	movzwl	_VR+4(%ecx), %esi
	movl	4(%esp), %ebx
	addl	_ei+8(%edx), %ebx
	movzwl	_VR(%ebx,%ebx), %ebx
	addl	%esi, %ebx
	movl	%ebx, 20(%esp)
	movw	%bx, _VACC+16
	shrl	$16, %ebx
	sall	$2, %ebx
	orl	%ebx, %eax
	movzwl	_VR+6(%ecx), %esi
	movl	4(%esp), %ebx
	addl	_ei+12(%edx), %ebx
	movzwl	_VR(%ebx,%ebx), %ebx
	addl	%esi, %ebx
	movl	%ebx, 24(%esp)
	movw	%bx, _VACC+24
	shrl	$16, %ebx
	sall	$3, %ebx
	orl	%ebx, %eax
	movzwl	_VR+8(%ecx), %edi
	movl	4(%esp), %ebx
	addl	_ei+16(%edx), %ebx
	movzwl	_VR(%ebx,%ebx), %ebx
	addl	%edi, %ebx
	movl	%ebx, (%esp)
	movw	%bx, _VACC+32
	shrl	$16, %ebx
	sall	$4, %ebx
	orl	%ebx, %eax
	movzwl	_VR+10(%ecx), %esi
	movl	4(%esp), %ebx
	addl	_ei+20(%edx), %ebx
	movzwl	_VR(%ebx,%ebx), %ebx
	addl	%ebx, %esi
	movw	%si, _VACC+40
	movl	%esi, %ebx
	shrl	$16, %ebx
	sall	$5, %ebx
	orl	%ebx, %eax
	movzwl	_VR+12(%ecx), %edi
	movl	4(%esp), %ebx
	addl	_ei+24(%edx), %ebx
	movzwl	_VR(%ebx,%ebx), %ebx
	addl	%edi, %ebx
	movw	%bx, _VACC+48
	movl	%ebx, %edi
	shrl	$16, %edi
	sall	$6, %edi
	orl	%edi, %eax
	movzwl	_VR+14(%ecx), %ecx
	movl	_ei+28(%edx), %edx
	addl	4(%esp), %edx
	movzwl	_VR(%edx,%edx), %edx
	addl	%ecx, %edx
	movw	%dx, _VACC+56
	movl	%edx, %ecx
	shrl	$16, %ecx
	sall	$7, %ecx
	orl	%ecx, %eax
	movw	%ax, _VCO
	sall	$4, %ebp
	movl	12(%esp), %eax
	movw	%ax, _VR(%ebp)
	movl	16(%esp), %edi
	movw	%di, _VR+2(%ebp)
	movl	20(%esp), %eax
	movw	%ax, _VR+4(%ebp)
	movl	24(%esp), %edi
	movw	%di, _VR+6(%ebp)
	movl	(%esp), %eax
	movw	%ax, _VR+8(%ebp)
	movw	%si, _VR+10(%ebp)
	movw	%bx, _VR+12(%ebp)
	movw	%dx, _VR+14(%ebp)
	addl	$28, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE28:
	.p2align 2,,3
	.def	_VAND;	.scl	3;	.type	32;	.endef
_VAND:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	sall	$5, 40(%esp)
	movl	36(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	movl	%eax, %ecx
	movl	40(%esp), %edx
	addl	_ei(%edx), %ecx
	sall	$4, 32(%esp)
	movw	_VR(%ecx,%ecx), %bp
	movl	32(%esp), %ecx
	andl	_VR(%ecx), %ebp
	movw	%bp, _VACC
	movl	_ei+4(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %di
	movl	32(%esp), %ebx
	andw	_VR+2(%ebx), %di
	movw	%di, _VACC+8
	movl	_ei+8(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %si
	andl	_VR+4(%ebx), %esi
	movw	%si, _VACC+16
	movl	_ei+12(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	32(%esp), %eax
	andw	_VR+6(%eax), %bx
	movw	%bx, _VACC+24
	movl	(%esp), %ecx
	addl	_ei+16(%edx), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	_VR+8(%eax), %edx
	andl	%edx, %ecx
	movw	%cx, 6(%esp)
	movw	%cx, _VACC+32
	movl	(%esp), %ecx
	movl	40(%esp), %eax
	addl	_ei+20(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %edx
	movw	_VR+10(%edx), %dx
	andl	%edx, %ecx
	movw	%cx, 4(%esp)
	movw	%cx, _VACC+40
	movl	(%esp), %ecx
	addl	_ei+24(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %eax
	andl	_VR+12(%eax), %ecx
	movw	%cx, _VACC+48
	movl	(%esp), %edx
	movl	40(%esp), %eax
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %dx
	movl	32(%esp), %eax
	andw	_VR+14(%eax), %dx
	movw	%dx, _VACC+56
	sall	$4, 28(%esp)
	movl	28(%esp), %eax
	movw	%bp, _VR(%eax)
	movw	%di, _VR+2(%eax)
	movw	%si, _VR+4(%eax)
	movw	%bx, _VR+6(%eax)
	movw	6(%esp), %bx
	movw	%bx, _VR+8(%eax)
	movl	4(%esp), %ebx
	movw	%bx, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE29:
	.p2align 2,,3
	.def	_VCH;	.scl	3;	.type	32;	.endef
_VCH:
LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$16, %esp
	.cfi_def_cfa_offset 36
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	_VR(%eax), %eax
	movl	48(%esp), %edx
	sall	$5, %edx
	movl	_ei(%edx), %edx
	movl	44(%esp), %ecx
	leal	(%edx,%ecx,8), %edx
	movw	_VR(%edx,%edx), %cx
	movl	%ecx, %ebx
	xorw	%ax, %bx
	js	L73
	movswl	%ax, %ebx
	movswl	%cx, %edx
	subl	%edx, %ebx
	notl	%ebx
	xorl	%edx, %edx
	cmpw	%cx, %ax
	setne	%dl
	shrl	$31, %ebx
	cmovne	%ecx, %eax
	movw	%ax, _VACC
	shrw	$15, %cx
	sall	$8, %ebx
	orl	%ebx, %ecx
	movl	%edx, %esi
	sall	$8, %esi
	movb	$0, 7(%esp)
L75:
	movl	40(%esp), %eax
	sall	$4, %eax
	movw	_VR+2(%eax), %dx
	movl	48(%esp), %eax
	sall	$5, %eax
	movl	_ei+4(%eax), %eax
	movl	44(%esp), %edi
	leal	(%eax,%edi,8), %eax
	movw	_VR(%eax,%eax), %ax
	movl	%eax, %ebx
	xorw	%dx, %bx
	js	L78
	movswl	%ax, %edi
	movl	%edi, %ebp
	shrl	$31, %ebp
	movswl	%dx, %ebx
	subl	%edi, %ebx
	notl	%ebx
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	cmpw	%ax, %dx
	setne	%bl
	movl	%ebx, %edi
	movl	(%esp), %ebx
	shrl	$31, %ebx
	cmove	%edx, %eax
	movw	%ax, _VACC+8
	sall	$9, %ebx
	sall	%ebp
	orl	%ebp, %ebx
	orl	%ecx, %ebx
	sall	$9, %edi
	orl	%edi, %esi
L80:
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	_VR+4(%eax), %edx
	movl	48(%esp), %eax
	sall	$5, %eax
	movl	_ei+8(%eax), %eax
	movl	44(%esp), %edi
	leal	(%eax,%edi,8), %eax
	movw	_VR(%eax,%eax), %ax
	movl	%eax, %ecx
	xorw	%dx, %cx
	js	L83
	movswl	%ax, %edi
	movl	%edi, %ebp
	shrl	$31, %ebp
	movswl	%dx, %ecx
	subl	%edi, %ecx
	notl	%ecx
	movl	%ecx, (%esp)
	xorl	%ecx, %ecx
	cmpw	%ax, %dx
	setne	%cl
	movl	%ecx, %edi
	movl	(%esp), %ecx
	shrl	$31, %ecx
	cmove	%edx, %eax
	movw	%ax, _VACC+16
	sall	$10, %ecx
	sall	$2, %ebp
	orl	%ebp, %ecx
	orl	%ebx, %ecx
	sall	$10, %edi
	orl	%edi, %esi
L85:
	movl	40(%esp), %eax
	sall	$4, %eax
	movw	_VR+6(%eax), %dx
	movl	48(%esp), %eax
	sall	$5, %eax
	movl	_ei+12(%eax), %eax
	movl	44(%esp), %ebx
	leal	(%eax,%ebx,8), %eax
	movw	_VR(%eax,%eax), %ax
	movl	%eax, %edi
	movswl	%ax, %ebx
	xorw	%dx, %di
	js	L88
	movl	%ebx, %ebp
	shrl	$31, %ebp
	movswl	%dx, %edi
	subl	%ebx, %edi
	notl	%edi
	xorl	%ebx, %ebx
	cmpw	%ax, %dx
	setne	%bl
	shrl	$31, %edi
	cmove	%edx, %eax
	movw	%ax, _VACC+24
	sall	$11, %edi
	sall	$3, %ebp
	orl	%ebp, %edi
	orl	%ecx, %edi
	sall	$11, %ebx
	orl	%ebx, %esi
L90:
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	_VR+8(%eax), %edx
	movl	48(%esp), %eax
	sall	$5, %eax
	movl	_ei+16(%eax), %eax
	movl	44(%esp), %ecx
	leal	(%eax,%ecx,8), %eax
	movw	_VR(%eax,%eax), %ax
	movl	%eax, %ebx
	xorw	%dx, %bx
	js	L93
	movswl	%ax, %ebx
	movl	%ebx, %ecx
	shrl	$31, %ecx
	movswl	%dx, %ebp
	subl	%ebx, %ebp
	notl	%ebp
	xorl	%ebx, %ebx
	cmpw	%ax, %dx
	setne	%bl
	shrl	$31, %ebp
	cmove	%edx, %eax
	movw	%ax, _VACC+32
	sall	$12, %ebp
	sall	$4, %ecx
	orl	%ebp, %ecx
	orl	%edi, %ecx
	sall	$12, %ebx
	orl	%ebx, %esi
L95:
	movl	40(%esp), %eax
	sall	$4, %eax
	movw	_VR+10(%eax), %dx
	movl	48(%esp), %eax
	sall	$5, %eax
	movl	_ei+20(%eax), %eax
	movl	44(%esp), %ebx
	leal	(%eax,%ebx,8), %eax
	movw	_VR(%eax,%eax), %ax
	movl	%eax, %edi
	movswl	%ax, %ebx
	xorw	%dx, %di
	js	L98
	movl	%ebx, %ebp
	shrl	$31, %ebp
	movswl	%dx, %edi
	subl	%ebx, %edi
	notl	%edi
	xorl	%ebx, %ebx
	cmpw	%ax, %dx
	setne	%bl
	shrl	$31, %edi
	cmove	%edx, %eax
	movw	%ax, _VACC+40
	sall	$13, %edi
	sall	$5, %ebp
	orl	%edi, %ebp
	orl	%ecx, %ebp
	sall	$13, %ebx
	orl	%ebx, %esi
L100:
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	_VR+12(%eax), %edx
	movl	48(%esp), %eax
	sall	$5, %eax
	movl	_ei+24(%eax), %eax
	movl	44(%esp), %edi
	leal	(%eax,%edi,8), %eax
	movw	_VR(%eax,%eax), %ax
	movl	%eax, %ecx
	xorw	%dx, %cx
	js	L103
	movswl	%ax, %ebx
	movl	%ebx, %ecx
	shrl	$31, %ecx
	movswl	%dx, %edi
	subl	%ebx, %edi
	notl	%edi
	xorl	%ebx, %ebx
	cmpw	%ax, %dx
	setne	%bl
	shrl	$31, %edi
	cmove	%edx, %eax
	movw	%ax, _VACC+48
	sall	$14, %edi
	sall	$6, %ecx
	orl	%edi, %ecx
	orl	%ebp, %ecx
	sall	$14, %ebx
	orl	%ebx, %esi
	movw	%si, 8(%esp)
L105:
	movl	40(%esp), %eax
	sall	$4, %eax
	movw	_VR+14(%eax), %dx
	movl	48(%esp), %eax
	sall	$5, %eax
	movl	_ei+28(%eax), %eax
	movl	44(%esp), %ebx
	leal	(%eax,%ebx,8), %eax
	movw	_VR(%eax,%eax), %ax
	movl	%eax, %esi
	xorw	%dx, %si
	movswl	%ax, %esi
	js	L122
	movl	%esi, %ebp
	shrl	$31, %ebp
	movswl	%dx, %edi
	subl	%esi, %edi
	notl	%edi
	xorl	%ebx, %ebx
	cmpw	%ax, %dx
	setne	%bl
	movl	%ebx, %esi
	shrl	$31, %edi
	cmove	%edx, %eax
	movw	%ax, _VACC+56
	sall	$15, %edi
	sall	$7, %ebp
	orl	%edi, %ebp
	orl	%ecx, %ebp
	sall	$15, %esi
	movl	8(%esp), %ebx
	orl	%esi, %ebx
L110:
	movb	7(%esp), %al
	movb	%al, _VCE
	movw	%bp, _VCC
	movw	%bx, _VCO
	movl	36(%esp), %eax
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	movl	_VACC+56, %edx
	movw	%dx, _VR+14(%eax)
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L73:
	.cfi_restore_state
	movswl	%cx, %edx
	movl	%edx, %ebx
	shrl	$31, %ebx
	movswl	%ax, %esi
	addl	%edx, %esi
	testl	%esi, %esi
	setle	%dl
	movl	%edx, %edi
	cmpl	$-1, %esi
	sete	7(%esp)
	testl	%esi, %esi
	setne	%dl
	movl	%edx, %esi
	movb	7(%esp), %dl
	xorl	%edx, %esi
	andl	$255, %esi
	testl	$1, %edi
	jne	L76
	movl	%eax, %ecx
L77:
	movw	%cx, _VACC
	movl	%ebx, %ecx
	sall	$8, %ecx
	movl	%edi, %ebx
	movzbl	%bl, %edx
	orl	%edx, %ecx
	sall	$8, %esi
	orl	$1, %esi
	jmp	L75
	.p2align 2,,3
L122:
	movl	%esi, %edi
	shrl	$31, %edi
	movl	%edi, (%esp)
	movswl	%dx, %edi
	addl	%edi, %esi
	xorl	%ebx, %ebx
	testl	%esi, %esi
	setle	%bl
	movl	%ebx, %ebp
	cmpl	$-1, %esi
	sete	6(%esp)
	movzbl	6(%esp), %edi
	sall	$7, %edi
	movl	%edi, %ebx
	orb	%bl, 7(%esp)
	testl	%esi, %esi
	setne	%bl
	movl	%ebx, %esi
	movb	6(%esp), %bl
	xorl	%ebx, %esi
	andl	$255, %esi
	testl	%ebp, %ebp
	jne	L123
	movl	%edx, %eax
L109:
	movw	%ax, _VACC+56
	sall	$7, %ebp
	movl	(%esp), %eax
	sall	$15, %eax
	orl	%eax, %ebp
	orl	%ecx, %ebp
	sall	$15, %esi
	orl	$128, %esi
	movl	8(%esp), %ebx
	orl	%esi, %ebx
	jmp	L110
	.p2align 2,,3
L103:
	movswl	%ax, %ecx
	movl	%ecx, %ebx
	shrl	$31, %ebx
	movl	%ebx, 12(%esp)
	movswl	%dx, %ebx
	addl	%ecx, %ebx
	xorl	%ecx, %ecx
	testl	%ebx, %ebx
	setle	%cl
	movl	%ecx, (%esp)
	cmpl	$-1, %ebx
	sete	8(%esp)
	movzbl	8(%esp), %edi
	sall	$6, %edi
	movl	%edi, %ecx
	orb	%cl, 7(%esp)
	testl	%ebx, %ebx
	setne	%bl
	xorl	8(%esp), %ebx
	movzbl	%bl, %ebx
	movl	(%esp), %ecx
	testl	%ecx, %ecx
	jne	L106
	movl	%edx, %eax
L107:
	movw	%ax, _VACC+48
	movl	(%esp), %ecx
	sall	$6, %ecx
	movl	12(%esp), %eax
	sall	$14, %eax
	orl	%eax, %ecx
	orl	%ebp, %ecx
	sall	$14, %ebx
	orl	$64, %ebx
	orl	%ebx, %esi
	movw	%si, 8(%esp)
	jmp	L105
	.p2align 2,,3
L98:
	movl	%ebx, %edi
	shrl	$31, %edi
	movl	%edi, 12(%esp)
	movswl	%dx, %edi
	addl	%ebx, %edi
	movl	%edi, (%esp)
	xorl	%ebx, %ebx
	testl	%edi, %edi
	setle	%bl
	movl	%ebx, %ebp
	incl	%edi
	sete	8(%esp)
	movzbl	8(%esp), %edi
	sall	$5, %edi
	movl	%edi, %ebx
	orb	%bl, 7(%esp)
	movl	(%esp), %ebx
	testl	%ebx, %ebx
	setne	%bl
	xorl	8(%esp), %ebx
	movzbl	%bl, %ebx
	testl	%ebp, %ebp
	jne	L101
	movl	%edx, %eax
L102:
	movw	%ax, _VACC+40
	sall	$5, %ebp
	movl	12(%esp), %eax
	sall	$13, %eax
	orl	%eax, %ebp
	orl	%ecx, %ebp
	sall	$13, %ebx
	orl	$32, %ebx
	orl	%ebx, %esi
	jmp	L100
	.p2align 2,,3
L93:
	movswl	%ax, %ecx
	movl	%ecx, %ebx
	shrl	$31, %ebx
	movl	%ebx, 12(%esp)
	movswl	%dx, %ebx
	addl	%ecx, %ebx
	xorl	%ecx, %ecx
	testl	%ebx, %ebx
	setle	%cl
	movl	%ecx, (%esp)
	cmpl	$-1, %ebx
	sete	8(%esp)
	movzbl	8(%esp), %ebp
	sall	$4, %ebp
	movl	%ebp, %ecx
	orb	%cl, 7(%esp)
	testl	%ebx, %ebx
	setne	%bl
	xorl	8(%esp), %ebx
	movzbl	%bl, %ebx
	movl	(%esp), %ebp
	testl	%ebp, %ebp
	jne	L96
	movl	%edx, %eax
L97:
	movw	%ax, _VACC+32
	movl	(%esp), %ecx
	sall	$4, %ecx
	movl	12(%esp), %eax
	sall	$12, %eax
	orl	%eax, %ecx
	orl	%edi, %ecx
	sall	$12, %ebx
	orl	$16, %ebx
	orl	%ebx, %esi
	jmp	L95
	.p2align 2,,3
L88:
	movl	%ebx, %edi
	shrl	$31, %edi
	movl	%edi, 12(%esp)
	movswl	%dx, %edi
	addl	%ebx, %edi
	xorl	%ebx, %ebx
	testl	%edi, %edi
	setle	%bl
	movl	%ebx, 8(%esp)
	cmpl	$-1, %edi
	sete	6(%esp)
	movzbl	6(%esp), %ebp
	sall	$3, %ebp
	movl	%ebp, %ebx
	orb	%bl, 7(%esp)
	testl	%edi, %edi
	setne	%bl
	movl	%ebx, %edi
	movb	6(%esp), %bl
	xorl	%ebx, %edi
	movl	%edi, %ebx
	movzbl	%bl, %ebp
	movl	8(%esp), %ebx
	testl	%ebx, %ebx
	jne	L91
	movl	%edx, %eax
L92:
	movw	%ax, _VACC+24
	movl	8(%esp), %edi
	sall	$3, %edi
	movl	12(%esp), %eax
	sall	$11, %eax
	orl	%eax, %edi
	orl	%ecx, %edi
	movl	%ebp, %ebx
	sall	$11, %ebx
	orl	$8, %ebx
	orl	%ebx, %esi
	jmp	L90
	.p2align 2,,3
L83:
	movswl	%ax, %ecx
	movl	%ecx, %edi
	shrl	$31, %edi
	movl	%edi, 12(%esp)
	movswl	%dx, %edi
	addl	%ecx, %edi
	xorl	%ecx, %ecx
	testl	%edi, %edi
	setle	%cl
	movl	%ecx, (%esp)
	cmpl	$-1, %edi
	sete	8(%esp)
	movzbl	8(%esp), %ebp
	sall	$2, %ebp
	movl	%ebp, %ecx
	orb	%cl, 7(%esp)
	testl	%edi, %edi
	setne	%cl
	movl	%ecx, %edi
	movb	8(%esp), %cl
	xorl	%ecx, %edi
	andl	$255, %edi
	movl	(%esp), %ebp
	testl	%ebp, %ebp
	jne	L86
	movl	%edx, %eax
L87:
	movw	%ax, _VACC+16
	movl	(%esp), %ecx
	sall	$2, %ecx
	movl	12(%esp), %eax
	sall	$10, %eax
	orl	%eax, %ecx
	orl	%ebx, %ecx
	sall	$10, %edi
	orl	$4, %edi
	orl	%edi, %esi
	jmp	L85
	.p2align 2,,3
L78:
	movswl	%ax, %ebx
	movl	%ebx, %edi
	shrl	$31, %edi
	movl	%edi, 12(%esp)
	movswl	%dx, %edi
	addl	%ebx, %edi
	xorl	%ebx, %ebx
	testl	%edi, %edi
	setle	%bl
	movl	%ebx, (%esp)
	cmpl	$-1, %edi
	sete	8(%esp)
	movzbl	8(%esp), %ebp
	sall	%ebp
	movl	%ebp, %ebx
	orb	%bl, 7(%esp)
	testl	%edi, %edi
	setne	%bl
	movl	%ebx, %edi
	movb	8(%esp), %bl
	xorl	%ebx, %edi
	andl	$255, %edi
	movl	(%esp), %ebx
	testl	%ebx, %ebx
	jne	L81
	movl	%edx, %eax
L82:
	movw	%ax, _VACC+8
	movl	(%esp), %ebx
	sall	%ebx
	movl	12(%esp), %eax
	sall	$9, %eax
	orl	%eax, %ebx
	orl	%ecx, %ebx
	sall	$9, %edi
	orl	$2, %edi
	orl	%edi, %esi
	jmp	L80
	.p2align 2,,3
L81:
	negl	%eax
	jmp	L82
	.p2align 2,,3
L86:
	negl	%eax
	jmp	L87
	.p2align 2,,3
L91:
	negl	%eax
	jmp	L92
	.p2align 2,,3
L96:
	negl	%eax
	jmp	L97
	.p2align 2,,3
L101:
	negl	%eax
	jmp	L102
	.p2align 2,,3
L106:
	negl	%eax
	jmp	L107
	.p2align 2,,3
L123:
	negl	%eax
	jmp	L109
	.p2align 2,,3
L76:
	negl	%ecx
	jmp	L77
	.cfi_endproc
LFE30:
	.p2align 2,,3
	.def	_VCL;	.scl	3;	.type	32;	.endef
_VCL:
LFB31:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$48, %esp
	.cfi_def_cfa_offset 68
	movl	_VCO, %eax
	movzwl	%ax, %ebp
	movl	_VCC, %ecx
	movb	_VCE, %bl
	movzbl	%bl, %edx
	movl	%edx, 40(%esp)
	movl	72(%esp), %edx
	sall	$4, %edx
	movl	_VR(%edx), %edx
	movl	80(%esp), %esi
	sall	$5, %esi
	movl	_ei(%esi), %esi
	movl	76(%esp), %edi
	leal	(%esi,%edi,8), %esi
	movw	_VR(%esi,%esi), %si
	movl	%ebp, %edi
	sarl	$8, %edi
	andl	$1, %edi
	xorl	$1, %edi
	testb	$1, %al
	jne	L125
	movzwl	%cx, %eax
	movl	%ecx, %ebx
	andl	$1, %ebx
	movl	%ebx, (%esp)
	testl	%edi, %edi
	jne	L126
	sarl	$8, %eax
	andl	$1, %eax
L130:
	testl	%eax, %eax
	cmovne	%esi, %edx
	movw	%dx, _VACC
	jmp	L129
	.p2align 2,,3
L125:
	movzbl	%ch, %eax
	andl	$1, %eax
	testl	%edi, %edi
	jne	L131
	movl	%ecx, %edi
	andl	$1, %edi
	movl	%edi, (%esp)
L135:
	negl	%esi
	movl	(%esp), %edi
	testl	%edi, %edi
	cmovne	%esi, %edx
	movw	%dx, _VACC
L129:
	andl	$-258, %ecx
	sall	$8, %eax
	movl	(%esp), %ebx
	orl	%eax, %ebx
	orl	%ecx, %ebx
	movl	72(%esp), %eax
	sall	$4, %eax
	movw	_VR+2(%eax), %ax
	movl	80(%esp), %edx
	sall	$5, %edx
	movl	_ei+4(%edx), %edx
	movl	76(%esp), %edi
	leal	(%edx,%edi,8), %edx
	movw	_VR(%edx,%edx), %cx
	movl	%ebp, %esi
	sarl	$9, %esi
	andl	$1, %esi
	xorl	$1, %esi
	testl	$2, %ebp
	jne	L136
	movzwl	%bx, %edi
	movl	%edi, %edx
	sarl	%edx
	andl	$1, %edx
	movl	%edx, (%esp)
	testl	%esi, %esi
	je	L243
	movzwl	%ax, %edi
	movzwl	%cx, %esi
	subl	%esi, %edi
	notl	%edi
	shrl	$31, %edi
L141:
	testl	%edi, %edi
	cmovne	%ecx, %eax
	movw	%ax, _VACC+8
L140:
	andl	$-515, %ebx
	movl	%edi, %eax
	sall	$9, %eax
	movl	(%esp), %edx
	sall	%edx
	orl	%eax, %edx
	orl	%ebx, %edx
	movl	72(%esp), %eax
	sall	$4, %eax
	movl	_VR+4(%eax), %eax
	movl	80(%esp), %ecx
	sall	$5, %ecx
	movl	_ei+8(%ecx), %ecx
	movl	76(%esp), %ebx
	leal	(%ecx,%ebx,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	%ebp, %esi
	sarl	$10, %esi
	andl	$1, %esi
	xorl	$1, %esi
	testl	$4, %ebp
	jne	L147
	movzwl	%dx, %edi
	movl	%edi, %ecx
	sarl	$2, %ecx
	andl	$1, %ecx
	movl	%ecx, (%esp)
	testl	%esi, %esi
	je	L244
	movzwl	%ax, %edi
	movzwl	%bx, %esi
	subl	%esi, %edi
	notl	%edi
	shrl	$31, %edi
L152:
	testl	%edi, %edi
	cmovne	%ebx, %eax
	movw	%ax, _VACC+16
L151:
	andl	$-1029, %edx
	movl	%edi, %eax
	sall	$10, %eax
	movl	(%esp), %ecx
	sall	$2, %ecx
	orl	%eax, %ecx
	orl	%edx, %ecx
	movl	72(%esp), %eax
	sall	$4, %eax
	movw	_VR+6(%eax), %ax
	movl	80(%esp), %edx
	sall	$5, %edx
	movl	_ei+12(%edx), %edx
	movl	76(%esp), %ebx
	leal	(%edx,%ebx,8), %edx
	movw	_VR(%edx,%edx), %bx
	movl	%ebp, %esi
	sarl	$11, %esi
	andl	$1, %esi
	xorl	$1, %esi
	testl	$8, %ebp
	jne	L158
	movzwl	%cx, %edi
	movl	%edi, %edx
	sarl	$3, %edx
	andl	$1, %edx
	movl	%edx, (%esp)
	testl	%esi, %esi
	je	L245
	movzwl	%ax, %edi
	movzwl	%bx, %esi
	subl	%esi, %edi
	notl	%edi
	shrl	$31, %edi
L163:
	testl	%edi, %edi
	cmovne	%ebx, %eax
	movw	%ax, _VACC+24
L162:
	andl	$-2057, %ecx
	movl	%edi, %eax
	sall	$11, %eax
	movl	(%esp), %edx
	sall	$3, %edx
	orl	%eax, %edx
	orl	%ecx, %edx
	movl	72(%esp), %eax
	sall	$4, %eax
	movl	_VR+8(%eax), %eax
	movl	80(%esp), %ecx
	sall	$5, %ecx
	movl	_ei+16(%ecx), %ecx
	movl	76(%esp), %ebx
	leal	(%ecx,%ebx,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	%ebp, %esi
	sarl	$12, %esi
	andl	$1, %esi
	xorl	$1, %esi
	testl	$16, %ebp
	jne	L169
	movzwl	%dx, %edi
	movl	%edi, %ecx
	sarl	$4, %ecx
	andl	$1, %ecx
	movl	%ecx, (%esp)
	testl	%esi, %esi
	je	L246
	movzwl	%ax, %edi
	movzwl	%bx, %esi
	subl	%esi, %edi
	notl	%edi
	shrl	$31, %edi
L174:
	testl	%edi, %edi
	cmovne	%ebx, %eax
	movw	%ax, _VACC+32
L173:
	andl	$-4113, %edx
	movl	%edi, %eax
	sall	$12, %eax
	movl	(%esp), %ecx
	sall	$4, %ecx
	orl	%eax, %ecx
	orl	%edx, %ecx
	movl	72(%esp), %eax
	sall	$4, %eax
	movw	_VR+10(%eax), %ax
	movl	80(%esp), %edx
	sall	$5, %edx
	movl	_ei+20(%edx), %edx
	movl	76(%esp), %ebx
	leal	(%edx,%ebx,8), %edx
	movw	_VR(%edx,%edx), %bx
	movl	%ebp, %esi
	sarl	$13, %esi
	andl	$1, %esi
	xorl	$1, %esi
	testl	$32, %ebp
	jne	L180
	movzwl	%cx, %edi
	movl	%edi, %edx
	sarl	$5, %edx
	andl	$1, %edx
	movl	%edx, (%esp)
	testl	%esi, %esi
	je	L247
	movzwl	%ax, %edi
	movzwl	%bx, %esi
	subl	%esi, %edi
	notl	%edi
	shrl	$31, %edi
L185:
	testl	%edi, %edi
	cmovne	%ebx, %eax
	movw	%ax, _VACC+40
L184:
	andl	$-8225, %ecx
	movl	%edi, %eax
	sall	$13, %eax
	movl	(%esp), %edx
	sall	$5, %edx
	orl	%eax, %edx
	orl	%ecx, %edx
	movl	72(%esp), %eax
	sall	$4, %eax
	movl	_VR+12(%eax), %ecx
	movl	80(%esp), %eax
	sall	$5, %eax
	movl	_ei+24(%eax), %eax
	movl	76(%esp), %ebx
	leal	(%eax,%ebx,8), %eax
	movw	_VR(%eax,%eax), %si
	movl	%ebp, %edi
	sarl	$14, %edi
	andl	$1, %edi
	xorl	$1, %edi
	testl	$64, %ebp
	jne	L191
	movzwl	%dx, %eax
	movl	%eax, %ebx
	sarl	$6, %ebx
	andl	$1, %ebx
	movl	%ebx, (%esp)
	testl	%edi, %edi
	je	L248
	movzwl	%cx, %eax
	movzwl	%si, %edi
	subl	%edi, %eax
	notl	%eax
	shrl	$31, %eax
L196:
	testl	%eax, %eax
	cmovne	%esi, %ecx
	movw	%cx, _VACC+48
L195:
	andl	$-16449, %edx
	sall	$14, %eax
	movl	(%esp), %ebx
	sall	$6, %ebx
	orl	%ebx, %eax
	orl	%edx, %eax
	movl	72(%esp), %edx
	sall	$4, %edx
	movw	_VR+14(%edx), %dx
	movl	80(%esp), %ecx
	sall	$5, %ecx
	movl	_ei+28(%ecx), %ecx
	movl	76(%esp), %edi
	leal	(%ecx,%edi,8), %ecx
	movw	_VR(%ecx,%ecx), %si
	movl	%ebp, %edi
	sarl	$15, %edi
	xorl	$1, %edi
	andl	$128, %ebp
	je	L202
	movzwl	%ax, %ecx
	movl	%ecx, %ebx
	sarl	$15, %ebx
	movl	%ebx, 20(%esp)
	testl	%edi, %edi
	je	L203
	movzwl	%dx, %edi
	movzwl	%si, %ecx
	leal	(%edi,%ecx), %ebx
	movl	40(%esp), %edi
	sarl	$7, %edi
	testw	%bx, %bx
	sete	%cl
	movl	%ecx, %ebp
	andl	$65536, %ebx
	sete	4(%esp)
	movb	4(%esp), %cl
	orl	%ebp, %ecx
	andl	%edi, %ecx
	xorl	$1, %edi
	andl	%ebp, %edi
	movb	4(%esp), %bl
	andl	%ebx, %edi
	orl	%edi, %ecx
L204:
	negl	%esi
	testl	%ecx, %ecx
	cmovne	%esi, %edx
	movw	%dx, _VACC+56
L206:
	movl	20(%esp), %ebx
	sall	$15, %ebx
	sall	$7, %ecx
	orl	%ebx, %ecx
	andl	$32639, %eax
	orl	%eax, %ecx
	movw	%cx, _VCC
	movl	68(%esp), %eax
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	movl	_VACC+56, %edx
	movw	%dx, _VR+14(%eax)
	movw	$0, _VCO
	movb	$0, _VCE
	addl	$48, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L131:
	.cfi_restore_state
	movzwl	%dx, %edi
	movl	%edi, 20(%esp)
	movzwl	%si, %edi
	addl	20(%esp), %edi
	andl	$1, %ebx
	movb	%bl, 20(%esp)
	testw	%di, %di
	sete	24(%esp)
	andl	$65536, %edi
	sete	47(%esp)
	movb	47(%esp), %bl
	orl	24(%esp), %ebx
	movl	%ebx, %edi
	movzbl	20(%esp), %ebx
	andl	%edi, %ebx
	movl	%ebx, (%esp)
	movb	20(%esp), %bl
	xorl	$1, %ebx
	movl	%ebx, %edi
	movb	24(%esp), %bl
	andl	%ebx, %edi
	movb	47(%esp), %bl
	andl	%ebx, %edi
	andl	$255, %edi
	orl	%edi, (%esp)
	jmp	L135
	.p2align 2,,3
L126:
	movzwl	%dx, %eax
	movzwl	%si, %edi
	subl	%edi, %eax
	notl	%eax
	shrl	$31, %eax
	jmp	L130
	.p2align 2,,3
L136:
	movzwl	%bx, %edx
	movl	%edx, %edi
	sarl	$9, %edi
	andl	$1, %edi
	testl	%esi, %esi
	je	L249
	movzwl	%ax, %esi
	movzwl	%cx, %edx
	addl	%esi, %edx
	movl	40(%esp), %esi
	sarl	%esi
	andl	$1, %esi
	testw	%dx, %dx
	sete	20(%esp)
	andl	$65536, %edx
	sete	24(%esp)
	movb	24(%esp), %dl
	orl	20(%esp), %edx
	andl	%esi, %edx
	movl	%edx, (%esp)
	xorl	$1, %esi
	movb	20(%esp), %dl
	andl	%edx, %esi
	movb	24(%esp), %dl
	andl	%edx, %esi
	orl	%esi, (%esp)
L146:
	negl	%ecx
	movl	(%esp), %esi
	testl	%esi, %esi
	cmovne	%ecx, %eax
	movw	%ax, _VACC+8
	jmp	L140
	.p2align 2,,3
L158:
	movzwl	%cx, %edx
	movl	%edx, %edi
	sarl	$11, %edi
	andl	$1, %edi
	testl	%esi, %esi
	je	L250
	movzwl	%ax, %esi
	movzwl	%bx, %edx
	addl	%esi, %edx
	movl	40(%esp), %esi
	sarl	$3, %esi
	andl	$1, %esi
	testw	%dx, %dx
	sete	20(%esp)
	andl	$65536, %edx
	sete	24(%esp)
	movb	24(%esp), %dl
	orl	20(%esp), %edx
	andl	%esi, %edx
	movl	%edx, (%esp)
	xorl	$1, %esi
	movb	20(%esp), %dl
	andl	%edx, %esi
	movb	24(%esp), %dl
	andl	%edx, %esi
	orl	%esi, (%esp)
L168:
	negl	%ebx
	movl	(%esp), %esi
	testl	%esi, %esi
	cmovne	%ebx, %eax
	movw	%ax, _VACC+24
	jmp	L162
	.p2align 2,,3
L147:
	movzwl	%dx, %ecx
	movl	%ecx, %edi
	sarl	$10, %edi
	andl	$1, %edi
	testl	%esi, %esi
	je	L251
	movzwl	%ax, %esi
	movzwl	%bx, %ecx
	addl	%esi, %ecx
	movl	40(%esp), %esi
	sarl	$2, %esi
	andl	$1, %esi
	testw	%cx, %cx
	sete	20(%esp)
	andl	$65536, %ecx
	sete	24(%esp)
	movb	24(%esp), %cl
	orl	20(%esp), %ecx
	andl	%esi, %ecx
	movl	%ecx, (%esp)
	xorl	$1, %esi
	movb	20(%esp), %cl
	andl	%ecx, %esi
	movb	24(%esp), %cl
	andl	%ecx, %esi
	orl	%esi, (%esp)
L157:
	negl	%ebx
	movl	(%esp), %ecx
	testl	%ecx, %ecx
	cmovne	%ebx, %eax
	movw	%ax, _VACC+16
	jmp	L151
	.p2align 2,,3
L202:
	movzwl	%ax, %ebx
	movl	%ebx, %ecx
	sarl	$7, %ecx
	andl	$1, %ecx
	testl	%edi, %edi
	je	L207
	movzwl	%dx, %edi
	movl	%edi, 20(%esp)
	movzwl	%si, %edi
	subl	%edi, 20(%esp)
	notl	20(%esp)
	shrl	$31, 20(%esp)
L208:
	movl	20(%esp), %edi
	testl	%edi, %edi
	cmovne	%esi, %edx
	movw	%dx, _VACC+56
	jmp	L206
	.p2align 2,,3
L180:
	movzwl	%cx, %edx
	movl	%edx, %edi
	sarl	$13, %edi
	andl	$1, %edi
	testl	%esi, %esi
	je	L252
	movzwl	%ax, %esi
	movzwl	%bx, %edx
	addl	%esi, %edx
	movl	40(%esp), %esi
	sarl	$5, %esi
	andl	$1, %esi
	testw	%dx, %dx
	sete	20(%esp)
	andl	$65536, %edx
	sete	24(%esp)
	movb	24(%esp), %dl
	orl	20(%esp), %edx
	andl	%esi, %edx
	movl	%edx, (%esp)
	xorl	$1, %esi
	movb	20(%esp), %dl
	andl	%edx, %esi
	movb	24(%esp), %dl
	andl	%edx, %esi
	orl	%esi, (%esp)
L190:
	negl	%ebx
	movl	(%esp), %esi
	testl	%esi, %esi
	cmovne	%ebx, %eax
	movw	%ax, _VACC+40
	jmp	L184
	.p2align 2,,3
L191:
	movzwl	%dx, %ebx
	movl	%ebx, %eax
	sarl	$14, %eax
	andl	$1, %eax
	testl	%edi, %edi
	je	L253
	movzwl	%cx, %ebx
	movzwl	%si, %edi
	addl	%edi, %ebx
	movl	40(%esp), %edi
	sarl	$6, %edi
	andl	$1, %edi
	testw	%bx, %bx
	sete	20(%esp)
	andl	$65536, %ebx
	sete	24(%esp)
	movb	24(%esp), %bl
	orl	20(%esp), %ebx
	andl	%edi, %ebx
	movl	%ebx, (%esp)
	xorl	$1, %edi
	movb	20(%esp), %bl
	andl	%ebx, %edi
	movb	24(%esp), %bl
	andl	%ebx, %edi
	orl	%edi, (%esp)
L201:
	negl	%esi
	movl	(%esp), %ebx
	testl	%ebx, %ebx
	cmovne	%esi, %ecx
	movw	%cx, _VACC+48
	jmp	L195
	.p2align 2,,3
L169:
	movzwl	%dx, %ecx
	movl	%ecx, %edi
	sarl	$12, %edi
	andl	$1, %edi
	testl	%esi, %esi
	je	L254
	movzwl	%ax, %esi
	movzwl	%bx, %ecx
	addl	%esi, %ecx
	movl	40(%esp), %esi
	sarl	$4, %esi
	andl	$1, %esi
	testw	%cx, %cx
	sete	20(%esp)
	andl	$65536, %ecx
	sete	24(%esp)
	movb	24(%esp), %cl
	orl	20(%esp), %ecx
	andl	%esi, %ecx
	movl	%ecx, (%esp)
	xorl	$1, %esi
	movb	20(%esp), %cl
	andl	%ecx, %esi
	movb	24(%esp), %cl
	andl	%ecx, %esi
	orl	%esi, (%esp)
L179:
	negl	%ebx
	movl	(%esp), %ecx
	testl	%ecx, %ecx
	cmovne	%ebx, %eax
	movw	%ax, _VACC+32
	jmp	L173
	.p2align 2,,3
L243:
	sarl	$9, %edi
	andl	$1, %edi
	jmp	L141
	.p2align 2,,3
L254:
	sarl	$4, %ecx
	andl	$1, %ecx
	movl	%ecx, (%esp)
	jmp	L179
	.p2align 2,,3
L245:
	sarl	$11, %edi
	andl	$1, %edi
	jmp	L163
	.p2align 2,,3
L249:
	sarl	%edx
	andl	$1, %edx
	movl	%edx, (%esp)
	jmp	L146
	.p2align 2,,3
L244:
	sarl	$10, %edi
	andl	$1, %edi
	jmp	L152
	.p2align 2,,3
L250:
	sarl	$3, %edx
	andl	$1, %edx
	movl	%edx, (%esp)
	jmp	L168
	.p2align 2,,3
L203:
	sarl	$7, %ecx
	andl	$1, %ecx
	jmp	L204
	.p2align 2,,3
L251:
	sarl	$2, %ecx
	andl	$1, %ecx
	movl	%ecx, (%esp)
	jmp	L157
	.p2align 2,,3
L248:
	sarl	$14, %eax
	andl	$1, %eax
	jmp	L196
	.p2align 2,,3
L252:
	sarl	$5, %edx
	andl	$1, %edx
	movl	%edx, (%esp)
	jmp	L190
	.p2align 2,,3
L247:
	sarl	$13, %edi
	andl	$1, %edi
	jmp	L185
	.p2align 2,,3
L207:
	sarl	$15, %ebx
	movl	%ebx, 20(%esp)
	jmp	L208
	.p2align 2,,3
L246:
	sarl	$12, %edi
	andl	$1, %edi
	jmp	L174
	.p2align 2,,3
L253:
	sarl	$6, %ebx
	andl	$1, %ebx
	movl	%ebx, (%esp)
	jmp	L201
	.cfi_endproc
LFE31:
	.p2align 2,,3
	.def	_VCR;	.scl	3;	.type	32;	.endef
_VCR:
LFB32:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	pushl	%eax
	.cfi_def_cfa_offset 24
	movl	32(%esp), %eax
	movl	36(%esp), %ebp
	movl	28(%esp), %edx
	sall	$4, %edx
	movl	_VR(%edx), %esi
	movl	%ebp, %edx
	sall	$5, %edx
	movl	_ei(%edx), %edx
	leal	(%edx,%eax,8), %edx
	movw	_VR(%edx,%edx), %bx
	movl	%ebx, %edx
	xorw	%si, %dx
	js	L256
	movl	%ebx, %ecx
	shrw	$15, %cx
	movswl	%si, %edx
	movswl	%bx, %edi
	subl	%edi, %edx
	notl	%edx
	shrl	$31, %edx
	testb	$1, %cl
	cmove	%esi, %ebx
	movw	%bx, _VACC
	sall	$8, %edx
	movzbl	%cl, %ecx
	orl	%edx, %ecx
L258:
	movl	28(%esp), %edx
	sall	$4, %edx
	movw	_VR+2(%edx), %si
	movl	%ebp, %edx
	sall	$5, %edx
	movl	_ei+4(%edx), %edx
	leal	(%edx,%eax,8), %edx
	movw	_VR(%edx,%edx), %bx
	movl	%ebx, %edi
	movswl	%bx, %edx
	xorw	%si, %di
	js	L261
	movswl	%si, %edi
	subl	%edx, %edi
	notl	%edi
	shrl	$31, %edi
	shrl	$31, %edx
	cmove	%esi, %ebx
	movw	%bx, _VACC+8
	sall	$9, %edi
	sall	%edx
	orl	%edi, %edx
	orl	%ecx, %edx
L263:
	movl	28(%esp), %ecx
	sall	$4, %ecx
	movl	_VR+4(%ecx), %esi
	movl	%ebp, %ecx
	sall	$5, %ecx
	movl	_ei+8(%ecx), %ecx
	leal	(%ecx,%eax,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	%ebx, %ecx
	xorw	%si, %cx
	movswl	%bx, %ecx
	js	L266
	movswl	%si, %edi
	subl	%ecx, %edi
	notl	%edi
	shrl	$31, %edi
	shrl	$31, %ecx
	cmove	%esi, %ebx
	movw	%bx, _VACC+16
	sall	$10, %edi
	sall	$2, %ecx
	orl	%edi, %ecx
	orl	%edx, %ecx
L268:
	movl	28(%esp), %edx
	sall	$4, %edx
	movw	_VR+6(%edx), %si
	movl	%ebp, %edx
	sall	$5, %edx
	movl	_ei+12(%edx), %edx
	leal	(%edx,%eax,8), %edx
	movw	_VR(%edx,%edx), %bx
	movl	%ebx, %edx
	xorw	%si, %dx
	movswl	%bx, %edx
	js	L271
	movswl	%si, %edi
	subl	%edx, %edi
	notl	%edi
	shrl	$31, %edi
	shrl	$31, %edx
	cmove	%esi, %ebx
	movw	%bx, _VACC+24
	sall	$11, %edi
	sall	$3, %edx
	orl	%edi, %edx
	orl	%ecx, %edx
L273:
	movl	28(%esp), %ecx
	sall	$4, %ecx
	movl	_VR+8(%ecx), %esi
	movl	%ebp, %ecx
	sall	$5, %ecx
	movl	_ei+16(%ecx), %ecx
	leal	(%ecx,%eax,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	%ebx, %ecx
	xorw	%si, %cx
	movswl	%bx, %ecx
	js	L276
	movswl	%si, %edi
	subl	%ecx, %edi
	notl	%edi
	shrl	$31, %edi
	shrl	$31, %ecx
	cmove	%esi, %ebx
	movw	%bx, _VACC+32
	sall	$12, %edi
	sall	$4, %ecx
	orl	%edi, %ecx
	orl	%edx, %ecx
L278:
	movl	28(%esp), %edx
	sall	$4, %edx
	movw	_VR+10(%edx), %si
	movl	%ebp, %edx
	sall	$5, %edx
	movl	_ei+20(%edx), %edx
	leal	(%edx,%eax,8), %edx
	movw	_VR(%edx,%edx), %bx
	movl	%ebx, %edx
	xorw	%si, %dx
	movswl	%bx, %edx
	js	L281
	movswl	%si, %edi
	subl	%edx, %edi
	notl	%edi
	shrl	$31, %edi
	shrl	$31, %edx
	cmove	%esi, %ebx
	movw	%bx, _VACC+40
	sall	$13, %edi
	sall	$5, %edx
	orl	%edi, %edx
	orl	%ecx, %edx
L283:
	movl	28(%esp), %ecx
	sall	$4, %ecx
	movl	_VR+12(%ecx), %ebx
	movl	%ebp, %ecx
	sall	$5, %ecx
	movl	_ei+24(%ecx), %ecx
	leal	(%ecx,%eax,8), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	%ecx, %esi
	xorw	%bx, %si
	js	L286
	movswl	%cx, %edi
	movswl	%bx, %esi
	subl	%edi, %esi
	notl	%esi
	shrl	$31, %esi
	shrl	$31, %edi
	cmove	%ebx, %ecx
	movw	%cx, _VACC+48
	sall	$14, %esi
	sall	$6, %edi
	orl	%edi, %esi
	orl	%edx, %esi
L288:
	movl	28(%esp), %edx
	sall	$4, %edx
	movw	_VR+14(%edx), %cx
	movl	%ebp, %edx
	sall	$5, %edx
	movl	_ei+28(%edx), %edx
	leal	(%edx,%eax,8), %eax
	movw	_VR(%eax,%eax), %dx
	movl	%edx, %eax
	movswl	%dx, %ebx
	xorw	%cx, %ax
	js	L305
	movswl	%cx, %eax
	subl	%ebx, %eax
	notl	%eax
	shrl	$31, %eax
	shrl	$31, %ebx
	cmove	%ecx, %edx
	movw	%dx, _VACC+56
	sall	$15, %eax
	sall	$7, %ebx
	orl	%ebx, %eax
	orl	%esi, %eax
L293:
	movw	%ax, _VCC
	movl	24(%esp), %eax
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	movl	_VACC+56, %edx
	movw	%dx, _VR+14(%eax)
	movw	$0, _VCO
	movb	$0, _VCE
	popl	%ebp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L256:
	.cfi_restore_state
	movswl	%bx, %edx
	movl	%edx, %edi
	shrl	$31, %edi
	movswl	%si, %ecx
	addl	%edx, %ecx
	shrl	$31, %ecx
	testb	$1, %cl
	jne	L259
	movl	%esi, %ebx
L260:
	movw	%bx, _VACC
	sall	$8, %edi
	movzbl	%cl, %ecx
	orl	%edi, %ecx
	jmp	L258
	.p2align 2,,3
L305:
	movl	%ebx, %edi
	shrl	$31, %edi
	movswl	%cx, %eax
	addl	%ebx, %eax
	shrl	$31, %eax
	jne	L306
	movl	%ecx, %edx
L292:
	movw	%dx, _VACC+56
	sall	$7, %eax
	movl	%edi, %edx
	sall	$15, %edx
	orl	%edx, %eax
	orl	%esi, %eax
	jmp	L293
	.p2align 2,,3
L286:
	movswl	%cx, %esi
	movl	%esi, %edi
	shrl	$31, %edi
	movl	%edi, (%esp)
	movswl	%bx, %edi
	addl	%edi, %esi
	shrl	$31, %esi
	jne	L289
	movl	%ebx, %ecx
L290:
	movw	%cx, _VACC+48
	sall	$6, %esi
	movl	(%esp), %edi
	sall	$14, %edi
	orl	%edi, %esi
	orl	%edx, %esi
	jmp	L288
	.p2align 2,,3
L281:
	movl	%edx, %edi
	shrl	$31, %edi
	movl	%edi, (%esp)
	movswl	%si, %edi
	addl	%edi, %edx
	shrl	$31, %edx
	jne	L284
	movl	%esi, %ebx
L285:
	movw	%bx, _VACC+40
	sall	$5, %edx
	movl	(%esp), %edi
	sall	$13, %edi
	orl	%edi, %edx
	orl	%ecx, %edx
	jmp	L283
	.p2align 2,,3
L276:
	movl	%ecx, %edi
	shrl	$31, %edi
	movl	%edi, (%esp)
	movswl	%si, %edi
	addl	%edi, %ecx
	shrl	$31, %ecx
	jne	L279
	movl	%esi, %ebx
L280:
	movw	%bx, _VACC+32
	sall	$4, %ecx
	movl	(%esp), %edi
	sall	$12, %edi
	orl	%edi, %ecx
	orl	%edx, %ecx
	jmp	L278
	.p2align 2,,3
L271:
	movl	%edx, %edi
	shrl	$31, %edi
	movl	%edi, (%esp)
	movswl	%si, %edi
	addl	%edi, %edx
	shrl	$31, %edx
	jne	L274
	movl	%esi, %ebx
L275:
	movw	%bx, _VACC+24
	sall	$3, %edx
	movl	(%esp), %edi
	sall	$11, %edi
	orl	%edi, %edx
	orl	%ecx, %edx
	jmp	L273
	.p2align 2,,3
L266:
	movl	%ecx, %edi
	shrl	$31, %edi
	movl	%edi, (%esp)
	movswl	%si, %edi
	addl	%edi, %ecx
	shrl	$31, %ecx
	jne	L269
	movl	%esi, %ebx
L270:
	movw	%bx, _VACC+16
	sall	$2, %ecx
	movl	(%esp), %edi
	sall	$10, %edi
	orl	%edi, %ecx
	orl	%edx, %ecx
	jmp	L268
	.p2align 2,,3
L261:
	movl	%edx, %edi
	shrl	$31, %edi
	movl	%edi, (%esp)
	movswl	%si, %edi
	addl	%edi, %edx
	shrl	$31, %edx
	jne	L264
	movl	%esi, %ebx
L265:
	movw	%bx, _VACC+8
	sall	%edx
	movl	(%esp), %edi
	sall	$9, %edi
	orl	%edi, %edx
	orl	%ecx, %edx
	jmp	L263
	.p2align 2,,3
L264:
	notl	%ebx
	jmp	L265
	.p2align 2,,3
L269:
	notl	%ebx
	jmp	L270
	.p2align 2,,3
L274:
	notl	%ebx
	jmp	L275
	.p2align 2,,3
L279:
	notl	%ebx
	jmp	L280
	.p2align 2,,3
L284:
	notl	%ebx
	jmp	L285
	.p2align 2,,3
L289:
	notl	%ecx
	jmp	L290
	.p2align 2,,3
L306:
	notl	%edx
	jmp	L292
	.p2align 2,,3
L259:
	notl	%ebx
	jmp	L260
	.cfi_endproc
LFE32:
	.p2align 2,,3
	.def	_VEQ;	.scl	3;	.type	32;	.endef
_VEQ:
LFB33:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$12, %esp
	.cfi_def_cfa_offset 32
	movl	_VCO, %eax
	movl	%eax, %ebx
	shrw	$8, %bx
	sall	$5, 44(%esp)
	movl	40(%esp), %edx
	sall	$3, %edx
	movl	%edx, (%esp)
	movl	44(%esp), %ecx
	addl	_ei(%ecx), %edx
	movw	_VR(%edx,%edx), %dx
	movw	%dx, 4(%esp)
	andl	$1, %ebx
	xorl	$1, %ebx
	sall	$4, 36(%esp)
	movl	36(%esp), %esi
	cmpw	%dx, _VR(%esi)
	sete	%dl
	andl	%edx, %ebx
	movl	4(%esp), %ebp
	movw	%bp, _VACC
	movl	%eax, %edx
	shrw	$9, %dx
	movl	(%esp), %ecx
	movl	44(%esp), %esi
	addl	_ei+4(%esi), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, 6(%esp)
	andl	$1, %edx
	xorl	$1, %edx
	movl	36(%esp), %ebp
	cmpw	%cx, _VR+2(%ebp)
	sete	%cl
	movzbl	%cl, %ecx
	andl	%edx, %ecx
	sall	%ecx
	orl	%ecx, %ebx
	movw	6(%esp), %dx
	movw	%dx, _VACC+8
	movl	%eax, %edx
	shrw	$10, %dx
	movl	(%esp), %ecx
	addl	_ei+8(%esi), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, 8(%esp)
	andl	$1, %edx
	xorl	$1, %edx
	cmpw	%cx, _VR+4(%ebp)
	sete	%cl
	movzbl	%cl, %ecx
	andl	%edx, %ecx
	sall	$2, %ecx
	orl	%ecx, %ebx
	movl	8(%esp), %ecx
	movw	%cx, _VACC+16
	movl	%eax, %edx
	shrw	$11, %dx
	movl	(%esp), %ecx
	addl	_ei+12(%esi), %ecx
	movw	_VR(%ecx,%ecx), %di
	andl	$1, %edx
	xorl	$1, %edx
	xorl	%ecx, %ecx
	cmpw	%di, _VR+6(%ebp)
	sete	%cl
	andl	%edx, %ecx
	sall	$3, %ecx
	orl	%ecx, %ebx
	movw	%di, _VACC+24
	movl	%eax, %ecx
	shrw	$12, %cx
	movl	(%esp), %edx
	addl	_ei+16(%esi), %edx
	movw	_VR(%edx,%edx), %si
	andl	$1, %ecx
	xorl	$1, %ecx
	xorl	%edx, %edx
	cmpw	%si, _VR+8(%ebp)
	sete	%dl
	andl	%ecx, %edx
	sall	$4, %edx
	orl	%edx, %ebx
	movw	%si, _VACC+32
	movl	%eax, %ecx
	shrw	$13, %cx
	movl	(%esp), %edx
	movl	44(%esp), %ebp
	addl	_ei+20(%ebp), %edx
	movw	_VR(%edx,%edx), %dx
	movw	%dx, 10(%esp)
	andl	$1, %ecx
	xorl	$1, %ecx
	movl	36(%esp), %ebp
	cmpw	%dx, _VR+10(%ebp)
	sete	%dl
	movzbl	%dl, %edx
	andl	%ecx, %edx
	sall	$5, %edx
	orl	%edx, %ebx
	movw	10(%esp), %dx
	movw	%dx, _VACC+40
	movl	%eax, %ebp
	shrw	$14, %bp
	movl	(%esp), %edx
	movl	44(%esp), %ecx
	addl	_ei+24(%ecx), %edx
	movw	_VR(%edx,%edx), %cx
	andl	$1, %ebp
	xorl	$1, %ebp
	movl	36(%esp), %edx
	cmpw	%cx, _VR+12(%edx)
	sete	%dl
	movzbl	%dl, %edx
	andl	%ebp, %edx
	sall	$6, %edx
	orl	%edx, %ebx
	movw	%cx, _VACC+48
	movl	(%esp), %edx
	movl	44(%esp), %ebp
	addl	_ei+28(%ebp), %edx
	movw	_VR(%edx,%edx), %bp
	shrw	$15, %ax
	xorl	$1, %eax
	movl	36(%esp), %edx
	cmpw	%bp, _VR+14(%edx)
	sete	%dl
	movzbl	%dl, %edx
	andl	%eax, %edx
	sall	$7, %edx
	orl	%edx, %ebx
	movw	%bp, _VACC+56
	movw	%bx, _VCC
	movw	$0, _VCO
	sall	$4, 32(%esp)
	movl	4(%esp), %edx
	movl	32(%esp), %eax
	movw	%dx, _VR(%eax)
	movw	6(%esp), %dx
	movw	%dx, _VR+2(%eax)
	movl	8(%esp), %edx
	movw	%dx, _VR+4(%eax)
	movw	%di, _VR+6(%eax)
	movw	%si, _VR+8(%eax)
	movw	10(%esp), %si
	movw	%si, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%bp, _VR+14(%eax)
	addl	$12, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE33:
	.p2align 2,,3
	.def	_VGE;	.scl	3;	.type	32;	.endef
_VGE:
LFB34:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	44(%esp), %eax
	sall	$4, %eax
	movl	_VR(%eax), %ecx
	sall	$5, 52(%esp)
	movl	48(%esp), %edx
	sall	$3, %edx
	movl	%edx, 4(%esp)
	movl	52(%esp), %ebx
	addl	_ei(%ebx), %edx
	movw	_VR(%edx,%edx), %bx
	movl	_VCO, %edx
	andl	$257, %edx
	cmpw	$257, %dx
	setne	%dl
	movl	%edx, %edi
	cmpw	%bx, %cx
	sete	%dl
	andl	%edx, %edi
	cmpw	%bx, %cx
	setg	2(%esp)
	movl	%edi, %edx
	orb	2(%esp), %dl
	movl	%edx, %edi
	cmove	%ebx, %ecx
	movw	%cx, 12(%esp)
	movw	%cx, _VACC
	movl	_VCO, %edx
	shrw	%dx
	movl	4(%esp), %ebx
	movl	52(%esp), %ecx
	addl	_ei+4(%ecx), %ebx
	movw	_VR(%ebx,%ebx), %bx
	andl	$257, %edx
	cmpw	$257, %dx
	setne	%dl
	cmpw	%bx, _VR+2(%eax)
	sete	%cl
	movl	%ecx, %esi
	andl	%esi, %edx
	cmpw	%bx, _VR+2(%eax)
	setg	%cl
	movl	%ecx, %esi
	orl	%esi, %edx
	movzbl	%dl, %edx
	movl	%edi, %ecx
	movzbl	%cl, %ebp
	leal	(%edx,%edx), %esi
	orl	%esi, %ebp
	testl	%edx, %edx
	cmovne	_VR+2(%eax), %bx
	movw	%bx, 14(%esp)
	movw	%bx, _VACC+8
	movl	_VCO, %edx
	shrw	$2, %dx
	movl	_VR+4(%eax), %edi
	movl	4(%esp), %ebx
	movl	52(%esp), %esi
	addl	_ei+8(%esi), %ebx
	movw	_VR(%ebx,%ebx), %bx
	andl	$257, %edx
	cmpw	$257, %dx
	setne	%dl
	cmpw	%bx, %di
	sete	%cl
	movl	%ecx, %esi
	andl	%esi, %edx
	cmpw	%bx, %di
	setg	%cl
	movl	%ecx, %esi
	orl	%esi, %edx
	movzbl	%dl, %edx
	leal	0(,%edx,4), %esi
	orl	%esi, %ebp
	testl	%edx, %edx
	cmove	%ebx, %edi
	movw	%di, 16(%esp)
	movw	%di, _VACC+16
	movl	_VCO, %edx
	shrw	$3, %dx
	movw	_VR+6(%eax), %di
	movl	4(%esp), %ebx
	movl	52(%esp), %esi
	addl	_ei+12(%esi), %ebx
	movw	_VR(%ebx,%ebx), %bx
	andl	$257, %edx
	cmpw	$257, %dx
	setne	%dl
	cmpw	%bx, %di
	sete	%cl
	movl	%ecx, %esi
	andl	%esi, %edx
	cmpw	%bx, %di
	setg	%cl
	movl	%ecx, %esi
	orl	%esi, %edx
	movzbl	%dl, %edx
	leal	0(,%edx,8), %esi
	orl	%esi, %ebp
	testl	%edx, %edx
	cmove	%ebx, %edi
	movw	%di, 18(%esp)
	movw	%di, _VACC+24
	movl	_VCO, %edx
	shrw	$4, %dx
	movl	_VR+8(%eax), %ecx
	movl	4(%esp), %ebx
	movl	52(%esp), %esi
	addl	_ei+16(%esi), %ebx
	movw	_VR(%ebx,%ebx), %di
	andl	$257, %edx
	cmpw	$257, %dx
	setne	%dl
	cmpw	%di, %cx
	sete	%bl
	andl	%ebx, %edx
	cmpw	%di, %cx
	setg	%bl
	orl	%ebx, %edx
	movzbl	%dl, %edx
	movl	%edx, %ebx
	sall	$4, %ebx
	orl	%ebx, %ebp
	testl	%edx, %edx
	cmovne	%ecx, %edi
	movw	%di, _VACC+32
	movl	_VCO, %edx
	shrw	$5, %dx
	movw	_VR+10(%eax), %cx
	movl	4(%esp), %ebx
	addl	_ei+20(%esi), %ebx
	movw	_VR(%ebx,%ebx), %si
	andl	$257, %edx
	cmpw	$257, %dx
	setne	%dl
	cmpw	%si, %cx
	sete	%bl
	andl	%ebx, %edx
	cmpw	%si, %cx
	setg	%bl
	orl	%ebx, %edx
	movzbl	%dl, %edx
	movl	%edx, %ebx
	sall	$5, %ebx
	orl	%ebx, %ebp
	testl	%edx, %edx
	cmovne	%ecx, %esi
	movw	%si, _VACC+40
	movl	_VCO, %edx
	shrw	$6, %dx
	movl	4(%esp), %ecx
	movl	52(%esp), %ebx
	addl	_ei+24(%ebx), %ecx
	movw	_VR(%ecx,%ecx), %bx
	andl	$257, %edx
	cmpw	$257, %dx
	setne	%dl
	cmpw	%bx, _VR+12(%eax)
	sete	%cl
	andl	%ecx, %edx
	cmpw	%bx, _VR+12(%eax)
	setg	%cl
	orl	%ecx, %edx
	movzbl	%dl, %edx
	movl	%edx, %ecx
	sall	$6, %ecx
	orl	%ecx, %ebp
	testl	%edx, %edx
	movl	_VR+12(%eax), %ecx
	cmove	%ebx, %ecx
	movw	%cx, _VACC+48
	movl	_VCO, %ebx
	shrw	$7, %bx
	movw	%bx, 2(%esp)
	movw	_VR+14(%eax), %dx
	movl	4(%esp), %eax
	movl	52(%esp), %ebx
	addl	_ei+28(%ebx), %eax
	movw	_VR(%eax,%eax), %bx
	andw	$257, 2(%esp)
	cmpw	$257, 2(%esp)
	setne	%al
	cmpw	%bx, %dx
	sete	2(%esp)
	andb	2(%esp), %al
	cmpw	%bx, %dx
	setg	2(%esp)
	orb	2(%esp), %al
	movzbl	%al, %eax
	testl	%eax, %eax
	cmove	%ebx, %edx
	movw	%dx, _VACC+56
	sall	$7, %eax
	orl	%eax, %ebp
	movw	%bp, _VCC
	sall	$4, 40(%esp)
	movl	12(%esp), %ebx
	movl	40(%esp), %eax
	movw	%bx, _VR(%eax)
	movw	14(%esp), %bx
	movw	%bx, _VR+2(%eax)
	movl	16(%esp), %ebx
	movw	%bx, _VR+4(%eax)
	movw	18(%esp), %bx
	movw	%bx, _VR+6(%eax)
	movw	%di, _VR+8(%eax)
	movw	%si, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	movw	$0, _VCO
	addl	$20, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE34:
	.p2align 2,,3
	.def	_VLT;	.scl	3;	.type	32;	.endef
_VLT:
LFB35:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	44(%esp), %eax
	sall	$4, %eax
	movl	_VR(%eax), %ecx
	sall	$5, 52(%esp)
	movl	48(%esp), %edx
	sall	$3, %edx
	movl	%edx, 4(%esp)
	movl	52(%esp), %ebx
	addl	_ei(%ebx), %edx
	movw	_VR(%edx,%edx), %bx
	movl	_VCO, %edx
	andl	$257, %edx
	cmpw	$257, %dx
	sete	%dl
	movl	%edx, %edi
	cmpw	%bx, %cx
	sete	%dl
	andl	%edx, %edi
	cmpw	%bx, %cx
	setl	2(%esp)
	movl	%edi, %edx
	orb	2(%esp), %dl
	movl	%edx, %edi
	cmove	%ebx, %ecx
	movw	%cx, 12(%esp)
	movw	%cx, _VACC
	movl	_VCO, %edx
	shrw	%dx
	movl	4(%esp), %ebx
	movl	52(%esp), %ecx
	addl	_ei+4(%ecx), %ebx
	movw	_VR(%ebx,%ebx), %bx
	andl	$257, %edx
	cmpw	$257, %dx
	sete	%dl
	cmpw	%bx, _VR+2(%eax)
	sete	%cl
	movl	%ecx, %esi
	andl	%esi, %edx
	cmpw	%bx, _VR+2(%eax)
	setl	%cl
	movl	%ecx, %esi
	orl	%esi, %edx
	movzbl	%dl, %edx
	movl	%edi, %ecx
	movzbl	%cl, %ebp
	leal	(%edx,%edx), %esi
	orl	%esi, %ebp
	testl	%edx, %edx
	cmovne	_VR+2(%eax), %bx
	movw	%bx, 14(%esp)
	movw	%bx, _VACC+8
	movl	_VCO, %edx
	shrw	$2, %dx
	movl	_VR+4(%eax), %edi
	movl	4(%esp), %ebx
	movl	52(%esp), %esi
	addl	_ei+8(%esi), %ebx
	movw	_VR(%ebx,%ebx), %bx
	andl	$257, %edx
	cmpw	$257, %dx
	sete	%dl
	cmpw	%bx, %di
	sete	%cl
	movl	%ecx, %esi
	andl	%esi, %edx
	cmpw	%bx, %di
	setl	%cl
	movl	%ecx, %esi
	orl	%esi, %edx
	movzbl	%dl, %edx
	leal	0(,%edx,4), %esi
	orl	%esi, %ebp
	testl	%edx, %edx
	cmove	%ebx, %edi
	movw	%di, 16(%esp)
	movw	%di, _VACC+16
	movl	_VCO, %edx
	shrw	$3, %dx
	movw	_VR+6(%eax), %di
	movl	4(%esp), %ebx
	movl	52(%esp), %esi
	addl	_ei+12(%esi), %ebx
	movw	_VR(%ebx,%ebx), %bx
	andl	$257, %edx
	cmpw	$257, %dx
	sete	%dl
	cmpw	%bx, %di
	sete	%cl
	movl	%ecx, %esi
	andl	%esi, %edx
	cmpw	%bx, %di
	setl	%cl
	movl	%ecx, %esi
	orl	%esi, %edx
	movzbl	%dl, %edx
	leal	0(,%edx,8), %esi
	orl	%esi, %ebp
	testl	%edx, %edx
	cmove	%ebx, %edi
	movw	%di, 18(%esp)
	movw	%di, _VACC+24
	movl	_VCO, %edx
	shrw	$4, %dx
	movl	_VR+8(%eax), %ecx
	movl	4(%esp), %ebx
	movl	52(%esp), %esi
	addl	_ei+16(%esi), %ebx
	movw	_VR(%ebx,%ebx), %di
	andl	$257, %edx
	cmpw	$257, %dx
	sete	%dl
	cmpw	%di, %cx
	sete	%bl
	andl	%ebx, %edx
	cmpw	%di, %cx
	setl	%bl
	orl	%ebx, %edx
	movzbl	%dl, %edx
	movl	%edx, %ebx
	sall	$4, %ebx
	orl	%ebx, %ebp
	testl	%edx, %edx
	cmovne	%ecx, %edi
	movw	%di, _VACC+32
	movl	_VCO, %edx
	shrw	$5, %dx
	movw	_VR+10(%eax), %cx
	movl	4(%esp), %ebx
	addl	_ei+20(%esi), %ebx
	movw	_VR(%ebx,%ebx), %si
	andl	$257, %edx
	cmpw	$257, %dx
	sete	%dl
	cmpw	%si, %cx
	sete	%bl
	andl	%ebx, %edx
	cmpw	%si, %cx
	setl	%bl
	orl	%ebx, %edx
	movzbl	%dl, %edx
	movl	%edx, %ebx
	sall	$5, %ebx
	orl	%ebx, %ebp
	testl	%edx, %edx
	cmovne	%ecx, %esi
	movw	%si, _VACC+40
	movl	_VCO, %edx
	shrw	$6, %dx
	movl	4(%esp), %ecx
	movl	52(%esp), %ebx
	addl	_ei+24(%ebx), %ecx
	movw	_VR(%ecx,%ecx), %bx
	andl	$257, %edx
	cmpw	$257, %dx
	sete	%dl
	cmpw	%bx, _VR+12(%eax)
	sete	%cl
	andl	%ecx, %edx
	cmpw	%bx, _VR+12(%eax)
	setl	%cl
	orl	%ecx, %edx
	movzbl	%dl, %edx
	movl	%edx, %ecx
	sall	$6, %ecx
	orl	%ecx, %ebp
	testl	%edx, %edx
	movl	_VR+12(%eax), %ecx
	cmove	%ebx, %ecx
	movw	%cx, _VACC+48
	movl	_VCO, %ebx
	shrw	$7, %bx
	movw	%bx, 2(%esp)
	movw	_VR+14(%eax), %dx
	movl	4(%esp), %eax
	movl	52(%esp), %ebx
	addl	_ei+28(%ebx), %eax
	movw	_VR(%eax,%eax), %bx
	andw	$257, 2(%esp)
	cmpw	$257, 2(%esp)
	sete	%al
	cmpw	%bx, %dx
	sete	2(%esp)
	andb	2(%esp), %al
	cmpw	%bx, %dx
	setl	2(%esp)
	orb	2(%esp), %al
	movzbl	%al, %eax
	testl	%eax, %eax
	cmove	%ebx, %edx
	movw	%dx, _VACC+56
	sall	$7, %eax
	orl	%eax, %ebp
	movw	%bp, _VCC
	sall	$4, 40(%esp)
	movl	12(%esp), %ebx
	movl	40(%esp), %eax
	movw	%bx, _VR(%eax)
	movw	14(%esp), %bx
	movw	%bx, _VR+2(%eax)
	movl	16(%esp), %ebx
	movw	%bx, _VR+4(%eax)
	movw	18(%esp), %bx
	movw	%bx, _VR+6(%eax)
	movw	%di, _VR+8(%eax)
	movw	%si, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	movw	$0, _VCO
	addl	$20, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE35:
	.p2align 2,,3
	.def	_VMACF;	.scl	3;	.type	32;	.endef
_VMACF:
LFB36:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %edi
	movl	24(%esp), %ebx
	movl	32(%esp), %ecx
	sall	$4, %ebx
	movswl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	28(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	_VACC, %eax
	adcl	_VACC+4, %edx
	movl	%eax, %ebp
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movswl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+8
	adcl	%edx, _VACC+12
	movswl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+16
	adcl	%edx, _VACC+20
	movswl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+24
	adcl	%edx, _VACC+28
	movswl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+32
	adcl	%edx, _VACC+36
	movswl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+40
	adcl	%edx, _VACC+44
	movswl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+48
	adcl	%edx, _VACC+52
	movswl	_VR+14(%ebx), %eax
	addl	_ei+28(%ecx), %esi
	movswl	_VR(%esi,%esi), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+56
	adcl	%edx, _VACC+60
	movl	_VACC+4, %eax
	testb	$128, %ah
	jne	L346
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	jne	L347
L379:
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
L348:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testb	$128, %ah
	jne	L350
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L351
L380:
	sall	$4, %eax
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
L352:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testb	$128, %ah
	jne	L354
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L355
L381:
	sall	$4, %eax
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
L356:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testb	$128, %ah
	jne	L358
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L359
L382:
	sall	$4, %eax
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
L360:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testb	$128, %ah
	jne	L362
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L363
L383:
	sall	$4, %eax
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
L364:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testb	$128, %ah
	jne	L366
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L367
L384:
	sall	$4, %eax
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
L368:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testb	$128, %ah
	jne	L370
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L371
L385:
	sall	$4, %eax
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
L372:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testb	$128, %ah
	je	L374
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	jne	L386
L377:
	movw	_VACC+58, %ax
	movw	%ax, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L374:
	.cfi_restore_state
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L377
	movw	$32767, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L370:
	.cfi_restore_state
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L385
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L372
	.p2align 2,,3
L366:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L384
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L368
	.p2align 2,,3
L362:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L383
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L364
	.p2align 2,,3
L358:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L382
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L360
	.p2align 2,,3
L354:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L381
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L356
	.p2align 2,,3
L350:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L380
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L352
	.p2align 2,,3
L346:
	notl	%ebp
	notl	%eax
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L379
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
	jmp	L348
	.p2align 2,,3
L386:
	movw	$-32768, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L371:
	.cfi_restore_state
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
	jmp	L372
	.p2align 2,,3
L367:
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
	jmp	L368
	.p2align 2,,3
L363:
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
	jmp	L364
	.p2align 2,,3
L359:
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
	jmp	L360
	.p2align 2,,3
L355:
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
	jmp	L356
	.p2align 2,,3
L351:
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
	jmp	L352
	.p2align 2,,3
L347:
	sall	$4, %eax
	movw	$32767, _VR(%eax)
	jmp	L348
	.cfi_endproc
LFE36:
	.p2align 2,,3
	.def	_VMACU;	.scl	3;	.type	32;	.endef
_VMACU:
LFB38:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %edi
	movl	24(%esp), %ebx
	movl	32(%esp), %ecx
	sall	$4, %ebx
	movswl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	28(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	_VACC, %eax
	adcl	_VACC+4, %edx
	movl	%eax, %ebp
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movswl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+8
	adcl	%edx, _VACC+12
	movswl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+16
	adcl	%edx, _VACC+20
	movswl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+24
	adcl	%edx, _VACC+28
	movswl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+32
	adcl	%edx, _VACC+36
	movswl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+40
	adcl	%edx, _VACC+44
	movswl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+48
	adcl	%edx, _VACC+52
	movswl	_VR+14(%ebx), %eax
	addl	_ei+28(%ecx), %esi
	movswl	_VR(%esi,%esi), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	%eax, _VACC+56
	adcl	%edx, _VACC+60
	movl	_VACC+4, %eax
	testb	$128, %ah
	jne	L388
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L413
	sall	$4, %eax
	movw	$-1, _VR(%eax)
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testb	$128, %ah
	je	L414
L391:
	movl	%edi, %eax
	sall	$4, %eax
	movw	$0, _VR+2(%eax)
L393:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testb	$128, %ah
	jne	L394
L422:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L415
	sall	$4, %eax
	movw	$-1, _VR+4(%eax)
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testb	$128, %ah
	je	L416
L397:
	movl	%edi, %eax
	sall	$4, %eax
	movw	$0, _VR+6(%eax)
L399:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testb	$128, %ah
	jne	L400
L424:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L417
	sall	$4, %eax
	movw	$-1, _VR+8(%eax)
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testb	$128, %ah
	je	L418
L403:
	movl	%edi, %eax
	sall	$4, %eax
	movw	$0, _VR+10(%eax)
L405:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testb	$128, %ah
	jne	L406
L426:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L419
	sall	$4, %eax
	movw	$-1, _VR+12(%eax)
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testb	$128, %ah
	jne	L420
L409:
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L411
	movw	$-1, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L388:
	.cfi_restore_state
	movl	%edi, %eax
	sall	$4, %eax
	movw	$0, _VR(%eax)
L390:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testb	$128, %ah
	jne	L391
L414:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L421
	sall	$4, %eax
	movw	$-1, _VR+2(%eax)
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testb	$128, %ah
	je	L422
L394:
	movl	%edi, %eax
	sall	$4, %eax
	movw	$0, _VR+4(%eax)
L396:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testb	$128, %ah
	jne	L397
L416:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L423
	sall	$4, %eax
	movw	$-1, _VR+6(%eax)
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testb	$128, %ah
	je	L424
L400:
	movl	%edi, %eax
	sall	$4, %eax
	movw	$0, _VR+8(%eax)
L402:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testb	$128, %ah
	jne	L403
L418:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L425
	sall	$4, %eax
	movw	$-1, _VR+10(%eax)
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testb	$128, %ah
	je	L426
L406:
	movl	%edi, %eax
	sall	$4, %eax
	movw	$0, _VR+12(%eax)
L408:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testb	$128, %ah
	je	L409
L420:
	sall	$4, %edi
	movw	$0, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L411:
	.cfi_restore_state
	movw	_VACC+58, %ax
	movw	%ax, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L419:
	.cfi_restore_state
	sall	$4, %eax
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
	jmp	L408
	.p2align 2,,3
L425:
	sall	$4, %eax
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
	jmp	L405
	.p2align 2,,3
L417:
	sall	$4, %eax
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
	jmp	L402
	.p2align 2,,3
L423:
	sall	$4, %eax
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
	jmp	L399
	.p2align 2,,3
L415:
	sall	$4, %eax
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
	jmp	L396
	.p2align 2,,3
L421:
	sall	$4, %eax
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
	jmp	L393
	.p2align 2,,3
L413:
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
	jmp	L390
	.cfi_endproc
LFE38:
	.p2align 2,,3
	.def	_VMADH;	.scl	3;	.type	32;	.endef
_VMADH:
LFB39:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %edi
	movl	24(%esp), %ebx
	movl	32(%esp), %ecx
	sall	$4, %ebx
	movswl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	28(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	addl	_VACC, %eax
	adcl	_VACC+4, %edx
	movl	%eax, %ebp
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movswl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	addl	%eax, _VACC+8
	adcl	%edx, _VACC+12
	movswl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	addl	%eax, _VACC+16
	adcl	%edx, _VACC+20
	movswl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	addl	%eax, _VACC+24
	adcl	%edx, _VACC+28
	movswl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	addl	%eax, _VACC+32
	adcl	%edx, _VACC+36
	movswl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	addl	%eax, _VACC+40
	adcl	%edx, _VACC+44
	movswl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	addl	%eax, _VACC+48
	adcl	%edx, _VACC+52
	movswl	_VR+14(%ebx), %eax
	addl	_ei+28(%ecx), %esi
	movswl	_VR(%esi,%esi), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	addl	%eax, _VACC+56
	adcl	%edx, _VACC+60
	movl	_VACC+4, %eax
	testb	$128, %ah
	jne	L428
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	jne	L429
L461:
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
L430:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testb	$128, %ah
	jne	L432
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L433
L462:
	sall	$4, %eax
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
L434:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testb	$128, %ah
	jne	L436
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L437
L463:
	sall	$4, %eax
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
L438:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testb	$128, %ah
	jne	L440
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L441
L464:
	sall	$4, %eax
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
L442:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testb	$128, %ah
	jne	L444
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L445
L465:
	sall	$4, %eax
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
L446:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testb	$128, %ah
	jne	L448
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L449
L466:
	sall	$4, %eax
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
L450:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testb	$128, %ah
	jne	L452
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L453
L467:
	sall	$4, %eax
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
L454:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testb	$128, %ah
	je	L456
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	jne	L468
L459:
	movw	_VACC+58, %ax
	movw	%ax, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L456:
	.cfi_restore_state
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L459
	movw	$32767, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L452:
	.cfi_restore_state
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L467
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L454
	.p2align 2,,3
L448:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L466
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L450
	.p2align 2,,3
L444:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L465
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L446
	.p2align 2,,3
L440:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L464
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L442
	.p2align 2,,3
L436:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L463
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L438
	.p2align 2,,3
L432:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L462
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L434
	.p2align 2,,3
L428:
	notl	%ebp
	notl	%eax
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L461
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
	jmp	L430
	.p2align 2,,3
L468:
	movw	$-32768, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L453:
	.cfi_restore_state
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
	jmp	L454
	.p2align 2,,3
L449:
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
	jmp	L450
	.p2align 2,,3
L445:
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
	jmp	L446
	.p2align 2,,3
L441:
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
	jmp	L442
	.p2align 2,,3
L437:
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
	jmp	L438
	.p2align 2,,3
L433:
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
	jmp	L434
	.p2align 2,,3
L429:
	sall	$4, %eax
	movw	$32767, _VR(%eax)
	jmp	L430
	.cfi_endproc
LFE39:
	.p2align 2,,3
	.def	_VMADL;	.scl	3;	.type	32;	.endef
_VMADL:
LFB40:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %edi
	movl	24(%esp), %ebx
	movl	32(%esp), %ecx
	sall	$4, %ebx
	movzwl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	28(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	shrl	$16, %eax
	xorl	%edx, %edx
	addl	_VACC, %eax
	adcl	_VACC+4, %edx
	movl	%eax, %ebp
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movzwl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	shrl	$16, %eax
	xorl	%edx, %edx
	addl	%eax, _VACC+8
	adcl	%edx, _VACC+12
	movzwl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	shrl	$16, %eax
	xorl	%edx, %edx
	addl	%eax, _VACC+16
	adcl	%edx, _VACC+20
	movzwl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	shrl	$16, %eax
	xorl	%edx, %edx
	addl	%eax, _VACC+24
	adcl	%edx, _VACC+28
	movzwl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	shrl	$16, %eax
	xorl	%edx, %edx
	addl	%eax, _VACC+32
	adcl	%edx, _VACC+36
	movzwl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	shrl	$16, %eax
	xorl	%edx, %edx
	addl	%eax, _VACC+40
	adcl	%edx, _VACC+44
	movzwl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	shrl	$16, %eax
	xorl	%edx, %edx
	addl	%eax, _VACC+48
	adcl	%edx, _VACC+52
	movzwl	_VR+14(%ebx), %eax
	addl	_ei+28(%ecx), %esi
	movzwl	_VR(%esi,%esi), %edx
	imull	%edx, %eax
	shrl	$16, %eax
	xorl	%edx, %edx
	addl	%eax, _VACC+56
	adcl	%edx, _VACC+60
	movl	_VACC+4, %eax
	testb	$128, %ah
	jne	L470
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	jne	L471
L503:
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
L472:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testb	$128, %ah
	jne	L474
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L475
L504:
	sall	$4, %eax
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
L476:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testb	$128, %ah
	jne	L478
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L479
L505:
	sall	$4, %eax
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
L480:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testb	$128, %ah
	jne	L482
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L483
L506:
	sall	$4, %eax
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
L484:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testb	$128, %ah
	jne	L486
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L487
L507:
	sall	$4, %eax
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
L488:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testb	$128, %ah
	jne	L490
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L491
L508:
	sall	$4, %eax
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
L492:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testb	$128, %ah
	jne	L494
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L495
L509:
	sall	$4, %eax
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
L496:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testb	$128, %ah
	je	L498
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	jne	L510
L501:
	movl	_VACC+56, %eax
	movw	%ax, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L498:
	.cfi_restore_state
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L501
	movw	$-1, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L494:
	.cfi_restore_state
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L509
	sall	$4, %eax
	movw	$0, _VR+12(%eax)
	jmp	L496
	.p2align 2,,3
L490:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L508
	sall	$4, %eax
	movw	$0, _VR+10(%eax)
	jmp	L492
	.p2align 2,,3
L486:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L507
	sall	$4, %eax
	movw	$0, _VR+8(%eax)
	jmp	L488
	.p2align 2,,3
L482:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L506
	sall	$4, %eax
	movw	$0, _VR+6(%eax)
	jmp	L484
	.p2align 2,,3
L478:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L505
	sall	$4, %eax
	movw	$0, _VR+4(%eax)
	jmp	L480
	.p2align 2,,3
L474:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L504
	sall	$4, %eax
	movw	$0, _VR+2(%eax)
	jmp	L476
	.p2align 2,,3
L470:
	notl	%ebp
	notl	%eax
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L503
	sall	$4, %eax
	movw	$0, _VR(%eax)
	jmp	L472
	.p2align 2,,3
L510:
	movw	$0, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L495:
	.cfi_restore_state
	sall	$4, %eax
	movw	$-1, _VR+12(%eax)
	jmp	L496
	.p2align 2,,3
L491:
	sall	$4, %eax
	movw	$-1, _VR+10(%eax)
	jmp	L492
	.p2align 2,,3
L487:
	sall	$4, %eax
	movw	$-1, _VR+8(%eax)
	jmp	L488
	.p2align 2,,3
L483:
	sall	$4, %eax
	movw	$-1, _VR+6(%eax)
	jmp	L484
	.p2align 2,,3
L479:
	sall	$4, %eax
	movw	$-1, _VR+4(%eax)
	jmp	L480
	.p2align 2,,3
L475:
	sall	$4, %eax
	movw	$-1, _VR+2(%eax)
	jmp	L476
	.p2align 2,,3
L471:
	sall	$4, %eax
	movw	$-1, _VR(%eax)
	jmp	L472
	.cfi_endproc
LFE40:
	.p2align 2,,3
	.def	_VMADM;	.scl	3;	.type	32;	.endef
_VMADM:
LFB41:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %edi
	movl	24(%esp), %ebx
	movl	32(%esp), %ecx
	sall	$4, %ebx
	movswl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	28(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	_VACC, %eax
	adcl	_VACC+4, %edx
	movl	%eax, %ebp
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movswl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+8
	adcl	%edx, _VACC+12
	movswl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+16
	adcl	%edx, _VACC+20
	movswl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+24
	adcl	%edx, _VACC+28
	movswl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+32
	adcl	%edx, _VACC+36
	movswl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+40
	adcl	%edx, _VACC+44
	movswl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movzwl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+48
	adcl	%edx, _VACC+52
	movswl	_VR+14(%ebx), %eax
	addl	_ei+28(%ecx), %esi
	movzwl	_VR(%esi,%esi), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+56
	adcl	%edx, _VACC+60
	movl	_VACC+4, %eax
	testb	$128, %ah
	jne	L512
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	jne	L513
L545:
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
L514:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testb	$128, %ah
	jne	L516
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L517
L546:
	sall	$4, %eax
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
L518:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testb	$128, %ah
	jne	L520
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L521
L547:
	sall	$4, %eax
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
L522:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testb	$128, %ah
	jne	L524
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L525
L548:
	sall	$4, %eax
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
L526:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testb	$128, %ah
	jne	L528
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L529
L549:
	sall	$4, %eax
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
L530:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testb	$128, %ah
	jne	L532
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L533
L550:
	sall	$4, %eax
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
L534:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testb	$128, %ah
	jne	L536
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L537
L551:
	sall	$4, %eax
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
L538:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testb	$128, %ah
	je	L540
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	jne	L552
L543:
	movw	_VACC+58, %ax
	movw	%ax, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L540:
	.cfi_restore_state
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L543
	movw	$32767, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L536:
	.cfi_restore_state
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L551
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L538
	.p2align 2,,3
L532:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L550
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L534
	.p2align 2,,3
L528:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L549
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L530
	.p2align 2,,3
L524:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L548
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L526
	.p2align 2,,3
L520:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L547
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L522
	.p2align 2,,3
L516:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L546
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L518
	.p2align 2,,3
L512:
	notl	%ebp
	notl	%eax
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L545
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
	jmp	L514
	.p2align 2,,3
L552:
	movw	$-32768, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L537:
	.cfi_restore_state
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
	jmp	L538
	.p2align 2,,3
L533:
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
	jmp	L534
	.p2align 2,,3
L529:
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
	jmp	L530
	.p2align 2,,3
L525:
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
	jmp	L526
	.p2align 2,,3
L521:
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
	jmp	L522
	.p2align 2,,3
L517:
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
	jmp	L518
	.p2align 2,,3
L513:
	sall	$4, %eax
	movw	$32767, _VR(%eax)
	jmp	L514
	.cfi_endproc
LFE41:
	.p2align 2,,3
	.def	_VMADN;	.scl	3;	.type	32;	.endef
_VMADN:
LFB42:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %edi
	movl	24(%esp), %ebx
	movl	32(%esp), %ecx
	sall	$4, %ebx
	movzwl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	28(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	_VACC, %eax
	adcl	_VACC+4, %edx
	movl	%eax, %ebp
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movzwl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+8
	adcl	%edx, _VACC+12
	movzwl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+16
	adcl	%edx, _VACC+20
	movzwl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+24
	adcl	%edx, _VACC+28
	movzwl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+32
	adcl	%edx, _VACC+36
	movzwl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+40
	adcl	%edx, _VACC+44
	movzwl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+48
	adcl	%edx, _VACC+52
	movzwl	_VR+14(%ebx), %eax
	addl	_ei+28(%ecx), %esi
	movswl	_VR(%esi,%esi), %edx
	imull	%edx, %eax
	cltd
	addl	%eax, _VACC+56
	adcl	%edx, _VACC+60
	movl	_VACC+4, %eax
	testb	$128, %ah
	jne	L554
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	jne	L555
L587:
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
L556:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testb	$128, %ah
	jne	L558
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L559
L588:
	sall	$4, %eax
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
L560:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testb	$128, %ah
	jne	L562
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L563
L589:
	sall	$4, %eax
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
L564:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testb	$128, %ah
	jne	L566
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L567
L590:
	sall	$4, %eax
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
L568:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testb	$128, %ah
	jne	L570
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L571
L591:
	sall	$4, %eax
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
L572:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testb	$128, %ah
	jne	L574
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L575
L592:
	sall	$4, %eax
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
L576:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testb	$128, %ah
	jne	L578
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L579
L593:
	sall	$4, %eax
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
L580:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testb	$128, %ah
	je	L582
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	jne	L594
L585:
	movl	_VACC+56, %eax
	movw	%ax, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L582:
	.cfi_restore_state
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L585
	movw	$-1, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L578:
	.cfi_restore_state
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L593
	sall	$4, %eax
	movw	$0, _VR+12(%eax)
	jmp	L580
	.p2align 2,,3
L574:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L592
	sall	$4, %eax
	movw	$0, _VR+10(%eax)
	jmp	L576
	.p2align 2,,3
L570:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L591
	sall	$4, %eax
	movw	$0, _VR+8(%eax)
	jmp	L572
	.p2align 2,,3
L566:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L590
	sall	$4, %eax
	movw	$0, _VR+6(%eax)
	jmp	L568
	.p2align 2,,3
L562:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L589
	sall	$4, %eax
	movw	$0, _VR+4(%eax)
	jmp	L564
	.p2align 2,,3
L558:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L588
	sall	$4, %eax
	movw	$0, _VR+2(%eax)
	jmp	L560
	.p2align 2,,3
L554:
	notl	%ebp
	notl	%eax
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L587
	sall	$4, %eax
	movw	$0, _VR(%eax)
	jmp	L556
	.p2align 2,,3
L594:
	movw	$0, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L579:
	.cfi_restore_state
	sall	$4, %eax
	movw	$-1, _VR+12(%eax)
	jmp	L580
	.p2align 2,,3
L575:
	sall	$4, %eax
	movw	$-1, _VR+10(%eax)
	jmp	L576
	.p2align 2,,3
L571:
	sall	$4, %eax
	movw	$-1, _VR+8(%eax)
	jmp	L572
	.p2align 2,,3
L567:
	sall	$4, %eax
	movw	$-1, _VR+6(%eax)
	jmp	L568
	.p2align 2,,3
L563:
	sall	$4, %eax
	movw	$-1, _VR+4(%eax)
	jmp	L564
	.p2align 2,,3
L559:
	sall	$4, %eax
	movw	$-1, _VR+2(%eax)
	jmp	L560
	.p2align 2,,3
L555:
	sall	$4, %eax
	movw	$-1, _VR(%eax)
	jmp	L556
	.cfi_endproc
LFE42:
	.p2align 2,,3
	.def	_VMOV;	.scl	3;	.type	32;	.endef
_VMOV:
LFB43:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %ecx
	movl	20(%esp), %eax
	sall	$5, %eax
	movl	16(%esp), %edx
	sall	$3, %edx
	movl	_ei(%eax), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC
	movl	_ei+4(%eax), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+8
	movl	_ei+8(%eax), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+16
	movl	_ei+12(%eax), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+24
	movl	_ei+16(%eax), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+32
	movl	_ei+20(%eax), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+40
	movl	_ei+24(%eax), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+48
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %ax
	movw	%ax, _VACC+56
	andl	$7, %ecx
	movl	8(%esp), %eax
	leal	(%ecx,%eax,8), %eax
	movl	_VACC(,%ecx,8), %edx
	movw	%dx, _VR(%eax,%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE43:
	.p2align 2,,3
	.def	_VMRG;	.scl	3;	.type	32;	.endef
_VMRG:
LFB44:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	16(%esp), %ebx
	movl	20(%esp), %edx
	movl	24(%esp), %ecx
	movl	_VCC, %esi
	movzwl	%si, %eax
	andl	$1, %esi
	jne	L598
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC
	testb	$2, %al
	jne	L600
L615:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+4(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+8
	testb	$4, %al
	jne	L602
L616:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+8(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+16
	testb	$8, %al
	jne	L604
L617:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+12(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+24
	testb	$16, %al
	jne	L606
L618:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+16(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+32
	testb	$32, %al
	jne	L608
L619:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+20(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+40
	testb	$64, %al
	jne	L610
L620:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+24(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+48
	testb	$-128, %al
	je	L612
L621:
	sall	$4, %ebx
	movw	_VR+14(%ebx), %dx
L613:
	movw	%dx, _VACC+56
	movl	12(%esp), %eax
	sall	$4, %eax
	movl	_VACC, %ecx
	movw	%cx, _VR(%eax)
	movl	_VACC+8, %ecx
	movw	%cx, _VR+2(%eax)
	movl	_VACC+16, %ecx
	movw	%cx, _VR+4(%eax)
	movl	_VACC+24, %ecx
	movw	%cx, _VR+6(%eax)
	movl	_VACC+32, %ecx
	movw	%cx, _VR+8(%eax)
	movl	_VACC+40, %ecx
	movw	%cx, _VR+10(%eax)
	movl	_VACC+48, %ecx
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L598:
	.cfi_restore_state
	movl	%ebx, %esi
	sall	$4, %esi
	movl	_VR(%esi), %esi
	movw	%si, _VACC
	testb	$2, %al
	je	L615
L600:
	movl	%ebx, %esi
	sall	$4, %esi
	movw	_VR+2(%esi), %si
	movw	%si, _VACC+8
	testb	$4, %al
	je	L616
L602:
	movl	%ebx, %esi
	sall	$4, %esi
	movl	_VR+4(%esi), %esi
	movw	%si, _VACC+16
	testb	$8, %al
	je	L617
L604:
	movl	%ebx, %esi
	sall	$4, %esi
	movw	_VR+6(%esi), %si
	movw	%si, _VACC+24
	testb	$16, %al
	je	L618
L606:
	movl	%ebx, %esi
	sall	$4, %esi
	movl	_VR+8(%esi), %esi
	movw	%si, _VACC+32
	testb	$32, %al
	je	L619
L608:
	movl	%ebx, %esi
	sall	$4, %esi
	movw	_VR+10(%esi), %si
	movw	%si, _VACC+40
	testb	$64, %al
	je	L620
L610:
	movl	%ebx, %esi
	sall	$4, %esi
	movl	_VR+12(%esi), %esi
	movw	%si, _VACC+48
	testb	$-128, %al
	jne	L621
L612:
	sall	$5, %ecx
	movl	_ei+28(%ecx), %eax
	leal	(%eax,%edx,8), %eax
	movw	_VR(%eax,%eax), %dx
	jmp	L613
	.cfi_endproc
LFE44:
	.p2align 2,,3
	.def	_VMUDH;	.scl	3;	.type	32;	.endef
_VMUDH:
LFB45:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %edi
	movl	24(%esp), %ebx
	movl	32(%esp), %ecx
	sall	$4, %ebx
	movswl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	28(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	movl	%eax, %ebp
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movswl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	movl	%eax, _VACC+8
	movl	%edx, _VACC+12
	movswl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	movl	%eax, _VACC+16
	movl	%edx, _VACC+20
	movswl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	movl	%eax, _VACC+24
	movl	%edx, _VACC+28
	movswl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	movl	%eax, _VACC+32
	movl	%edx, _VACC+36
	movswl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	movl	%eax, _VACC+40
	movl	%edx, _VACC+44
	movswl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	movl	%eax, _VACC+48
	movl	%edx, _VACC+52
	movswl	_VR+14(%ebx), %eax
	addl	_ei+28(%ecx), %esi
	movswl	_VR(%esi,%esi), %edx
	imull	%edx, %eax
	cltd
	shldl	$16, %eax, %edx
	sall	$16, %eax
	movl	%eax, _VACC+56
	movl	%edx, _VACC+60
	movl	_VACC+4, %eax
	testl	%eax, %eax
	js	L623
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	jne	L624
L656:
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
L625:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testl	%eax, %eax
	js	L627
L670:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L628
L657:
	sall	$4, %eax
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
L629:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testl	%eax, %eax
	js	L631
L669:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L632
L658:
	sall	$4, %eax
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
L633:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testl	%eax, %eax
	js	L635
L668:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L636
L659:
	sall	$4, %eax
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
L637:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testl	%eax, %eax
	js	L639
L667:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L640
L660:
	sall	$4, %eax
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
L641:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testl	%eax, %eax
	js	L643
L666:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L644
L661:
	sall	$4, %eax
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
L645:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testl	%eax, %eax
	js	L647
L665:
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	jne	L648
L662:
	sall	$4, %eax
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
L649:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testl	%eax, %eax
	js	L663
L651:
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	jne	L664
L654:
	movw	_VACC+58, %ax
	movw	%ax, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L664:
	.cfi_restore_state
	movw	$32767, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L648:
	.cfi_restore_state
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	testl	%eax, %eax
	jns	L651
L663:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L654
	movw	$-32768, _VR+14(%edi)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L644:
	.cfi_restore_state
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	testl	%eax, %eax
	jns	L665
L647:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L662
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L649
	.p2align 2,,3
L640:
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	testl	%eax, %eax
	jns	L666
L643:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L661
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L645
	.p2align 2,,3
L636:
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	testl	%eax, %eax
	jns	L667
L639:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L660
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L641
	.p2align 2,,3
L632:
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	testl	%eax, %eax
	jns	L668
L635:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L659
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L637
	.p2align 2,,3
L628:
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	testl	%eax, %eax
	jns	L669
L631:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L658
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L633
	.p2align 2,,3
L624:
	sall	$4, %eax
	movw	$32767, _VR(%eax)
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	testl	%eax, %eax
	jns	L670
L627:
	notl	%edx
	notl	%eax
	andl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L657
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L629
	.p2align 2,,3
L623:
	notl	%ebp
	notl	%eax
	andl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L656
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
	jmp	L625
	.cfi_endproc
LFE45:
	.p2align 2,,3
	.def	_VMUDL;	.scl	3;	.type	32;	.endef
_VMUDL:
LFB46:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %eax
	movl	20(%esp), %ecx
	movl	28(%esp), %edx
	sall	$4, %ecx
	movzwl	_VR(%ecx), %esi
	sall	$5, %edx
	movl	24(%esp), %ebx
	sall	$3, %ebx
	movl	_ei(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	shrl	$16, %esi
	movl	%esi, _VACC
	movl	$0, _VACC+4
	movzwl	_VR+2(%ecx), %esi
	movl	_ei+4(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	shrl	$16, %esi
	movl	%esi, _VACC+8
	movl	$0, _VACC+12
	movzwl	_VR+4(%ecx), %esi
	movl	_ei+8(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	shrl	$16, %esi
	movl	%esi, _VACC+16
	movl	$0, _VACC+20
	movzwl	_VR+6(%ecx), %esi
	movl	_ei+12(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	shrl	$16, %esi
	movl	%esi, _VACC+24
	movl	$0, _VACC+28
	movzwl	_VR+8(%ecx), %esi
	movl	_ei+16(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	shrl	$16, %esi
	movl	%esi, _VACC+32
	movl	$0, _VACC+36
	movzwl	_VR+10(%ecx), %esi
	movl	_ei+20(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	shrl	$16, %esi
	movl	%esi, _VACC+40
	movl	$0, _VACC+44
	movzwl	_VR+12(%ecx), %esi
	movl	_ei+24(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	shrl	$16, %esi
	movl	%esi, _VACC+48
	movl	$0, _VACC+52
	movzwl	_VR+14(%ecx), %ecx
	addl	_ei+28(%edx), %ebx
	movzwl	_VR(%ebx,%ebx), %edx
	imull	%edx, %ecx
	shrl	$16, %ecx
	movl	%ecx, _VACC+56
	movl	$0, _VACC+60
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	movl	_VACC+56, %edx
	movw	%dx, _VR+14(%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE46:
	.p2align 2,,3
	.def	_VMUDM;	.scl	3;	.type	32;	.endef
_VMUDM:
LFB47:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %eax
	movl	20(%esp), %ecx
	movl	28(%esp), %edx
	sall	$4, %ecx
	movswl	_VR(%ecx), %esi
	sall	$5, %edx
	movl	24(%esp), %ebx
	sall	$3, %ebx
	movl	_ei(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	movl	%esi, _VACC
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+4
	movswl	_VR+2(%ecx), %esi
	movl	_ei+4(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	movl	%esi, _VACC+8
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+12
	movswl	_VR+4(%ecx), %esi
	movl	_ei+8(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	movl	%esi, _VACC+16
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+20
	movswl	_VR+6(%ecx), %esi
	movl	_ei+12(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	movl	%esi, _VACC+24
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+28
	movswl	_VR+8(%ecx), %esi
	movl	_ei+16(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	movl	%esi, _VACC+32
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+36
	movswl	_VR+10(%ecx), %esi
	movl	_ei+20(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	movl	%esi, _VACC+40
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+44
	movswl	_VR+12(%ecx), %esi
	movl	_ei+24(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	movl	%esi, _VACC+48
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+52
	movswl	_VR+14(%ecx), %ecx
	addl	_ei+28(%edx), %ebx
	movzwl	_VR(%ebx,%ebx), %edx
	imull	%edx, %ecx
	movl	%ecx, _VACC+56
	movl	%ecx, %edx
	sarl	$31, %edx
	movl	%edx, _VACC+60
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
	movw	_VACC+58, %dx
	movw	%dx, _VR+14(%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE47:
	.p2align 2,,3
	.def	_VMUDN;	.scl	3;	.type	32;	.endef
_VMUDN:
LFB48:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	40(%esp), %ebp
	movl	44(%esp), %ebx
	movl	52(%esp), %ecx
	sall	$4, %ebx
	movzwl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	48(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	movw	%ax, 4(%esp)
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movzwl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	movw	%ax, 6(%esp)
	movl	%eax, _VACC+8
	movl	%edx, _VACC+12
	movzwl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	movw	%ax, 8(%esp)
	movl	%eax, _VACC+16
	movl	%edx, _VACC+20
	movzwl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	movw	%ax, 10(%esp)
	movl	%eax, _VACC+24
	movl	%edx, _VACC+28
	movzwl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	movw	%ax, 12(%esp)
	movl	%eax, _VACC+32
	movl	%edx, _VACC+36
	movzwl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	movw	%ax, 14(%esp)
	movl	%eax, _VACC+40
	movl	%edx, _VACC+44
	movzwl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	movl	%eax, %edi
	movl	%eax, _VACC+48
	movl	%edx, _VACC+52
	movzwl	_VR+14(%ebx), %eax
	movl	_ei+28(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	cltd
	movl	%eax, %ecx
	movl	%eax, _VACC+56
	movl	%edx, _VACC+60
	sall	$4, %ebp
	movl	4(%esp), %eax
	movw	%ax, _VR(%ebp)
	movw	6(%esp), %dx
	movw	%dx, _VR+2(%ebp)
	movl	8(%esp), %eax
	movw	%ax, _VR+4(%ebp)
	movw	10(%esp), %dx
	movw	%dx, _VR+6(%ebp)
	movl	12(%esp), %eax
	movw	%ax, _VR+8(%ebp)
	movw	14(%esp), %dx
	movw	%dx, _VR+10(%ebp)
	movw	%di, _VR+12(%ebp)
	movw	%cx, _VR+14(%ebp)
	addl	$20, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE48:
	.p2align 2,,3
	.def	_VMULF;	.scl	3;	.type	32;	.endef
_VMULF:
LFB49:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %edi
	movl	52(%esp), %ebx
	movl	60(%esp), %ecx
	sall	$4, %ebx
	movswl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	56(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	leal	32768(%eax,%eax), %eax
	cltd
	movl	%eax, (%esp)
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movswl	_VR+2(%ebx), %eax
	movl	_ei+4(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	leal	32768(%eax,%eax), %eax
	cltd
	movl	%eax, 4(%esp)
	movl	%eax, _VACC+8
	movl	%edx, _VACC+12
	movswl	_VR+4(%ebx), %eax
	movl	_ei+8(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	leal	32768(%eax,%eax), %eax
	cltd
	movl	%eax, 8(%esp)
	movl	%eax, _VACC+16
	movl	%edx, _VACC+20
	movswl	_VR+6(%ebx), %eax
	movl	_ei+12(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	leal	32768(%eax,%eax), %eax
	cltd
	movl	%eax, 12(%esp)
	movl	%eax, _VACC+24
	movl	%edx, _VACC+28
	movswl	_VR+8(%ebx), %eax
	movl	_ei+16(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	leal	32768(%eax,%eax), %eax
	cltd
	movl	%eax, 16(%esp)
	movl	%eax, _VACC+32
	movl	%edx, _VACC+36
	movswl	_VR+10(%ebx), %eax
	movl	_ei+20(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	leal	32768(%eax,%eax), %eax
	cltd
	movl	%eax, 20(%esp)
	movl	%eax, _VACC+40
	movl	%edx, _VACC+44
	movswl	_VR+12(%ebx), %eax
	movl	_ei+24(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	leal	32768(%eax,%eax), %eax
	cltd
	movl	%eax, %ebp
	movl	%eax, _VACC+48
	movl	%edx, _VACC+52
	movswl	_VR+14(%ebx), %eax
	addl	_ei+28(%ecx), %esi
	movswl	_VR(%esi,%esi), %edx
	imull	%edx, %eax
	leal	32768(%eax,%eax), %eax
	cltd
	movl	%eax, %ecx
	movl	%eax, _VACC+56
	movl	%edx, _VACC+60
	sall	$4, %edi
	xorl	%edx, %edx
	cmpl	$-2147450880, (%esp)
	sete	%dl
	movw	_VACC+2, %ax
	subl	%edx, %eax
	movw	%ax, _VR(%edi)
	xorl	%edx, %edx
	cmpl	$-2147450880, 4(%esp)
	sete	%dl
	movw	_VACC+10, %ax
	subl	%edx, %eax
	movw	%ax, _VR+2(%edi)
	xorl	%edx, %edx
	cmpl	$-2147450880, 8(%esp)
	sete	%dl
	movw	_VACC+18, %ax
	subl	%edx, %eax
	movw	%ax, _VR+4(%edi)
	xorl	%edx, %edx
	cmpl	$-2147450880, 12(%esp)
	sete	%dl
	movw	_VACC+26, %ax
	subl	%edx, %eax
	movw	%ax, _VR+6(%edi)
	xorl	%edx, %edx
	cmpl	$-2147450880, 16(%esp)
	sete	%dl
	movw	_VACC+34, %ax
	subl	%edx, %eax
	movw	%ax, _VR+8(%edi)
	xorl	%edx, %edx
	cmpl	$-2147450880, 20(%esp)
	sete	%dl
	movw	_VACC+42, %ax
	subl	%edx, %eax
	movw	%ax, _VR+10(%edi)
	xorl	%edx, %edx
	cmpl	$-2147450880, %ebp
	sete	%dl
	movw	_VACC+50, %ax
	subl	%edx, %eax
	movw	%ax, _VR+12(%edi)
	xorl	%edx, %edx
	cmpl	$-2147450880, %ecx
	sete	%dl
	movw	_VACC+58, %ax
	subl	%edx, %eax
	movw	%ax, _VR+14(%edi)
	addl	$28, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE49:
	.p2align 2,,3
	.def	_VMULU;	.scl	3;	.type	32;	.endef
_VMULU:
LFB50:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %eax
	movl	20(%esp), %ecx
	movl	28(%esp), %edx
	sall	$4, %ecx
	movswl	_VR(%ecx), %esi
	sall	$5, %edx
	movl	24(%esp), %ebx
	sall	$3, %ebx
	movl	_ei(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	leal	32768(%esi,%esi), %esi
	movl	%esi, _VACC
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+4
	movswl	_VR+2(%ecx), %esi
	movl	_ei+4(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	leal	32768(%esi,%esi), %esi
	movl	%esi, _VACC+8
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+12
	movswl	_VR+4(%ecx), %esi
	movl	_ei+8(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	leal	32768(%esi,%esi), %esi
	movl	%esi, _VACC+16
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+20
	movswl	_VR+6(%ecx), %esi
	movl	_ei+12(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	leal	32768(%esi,%esi), %esi
	movl	%esi, _VACC+24
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+28
	movswl	_VR+8(%ecx), %esi
	movl	_ei+16(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	leal	32768(%esi,%esi), %esi
	movl	%esi, _VACC+32
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+36
	movswl	_VR+10(%ecx), %esi
	movl	_ei+20(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	leal	32768(%esi,%esi), %esi
	movl	%esi, _VACC+40
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+44
	movswl	_VR+12(%ecx), %esi
	movl	_ei+24(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	leal	32768(%esi,%esi), %esi
	movl	%esi, _VACC+48
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, _VACC+52
	movswl	_VR+14(%ecx), %ecx
	addl	_ei+28(%edx), %ebx
	movswl	_VR(%ebx,%ebx), %edx
	imull	%edx, %ecx
	leal	32768(%ecx,%ecx), %edx
	movl	%edx, _VACC+56
	movl	%edx, %ecx
	sarl	$31, %ecx
	movl	%ecx, _VACC+60
	movw	_VACC+2, %cx
	sall	$4, %eax
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movl	_VACC+4, %ecx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR(%eax)
	movw	_VACC+10, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movl	_VACC+12, %ecx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+2(%eax)
	movw	_VACC+18, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movl	_VACC+20, %ecx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+4(%eax)
	movw	_VACC+26, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movl	_VACC+28, %ecx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+6(%eax)
	movw	_VACC+34, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movl	_VACC+36, %ecx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+8(%eax)
	movw	_VACC+42, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movl	_VACC+44, %ecx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+10(%eax)
	movw	_VACC+50, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movl	_VACC+52, %ecx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+12(%eax)
	movw	_VACC+58, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movl	_VACC+60, %ecx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+14(%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE50:
	.p2align 2,,3
	.def	_VNAND;	.scl	3;	.type	32;	.endef
_VNAND:
LFB51:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	sall	$5, 40(%esp)
	movl	36(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	movl	%eax, %ecx
	movl	40(%esp), %edx
	addl	_ei(%edx), %ecx
	sall	$4, 32(%esp)
	movw	_VR(%ecx,%ecx), %bp
	movl	32(%esp), %ecx
	andl	_VR(%ecx), %ebp
	notl	%ebp
	movw	%bp, _VACC
	movl	_ei+4(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %di
	movl	32(%esp), %ebx
	andw	_VR+2(%ebx), %di
	notl	%edi
	movw	%di, _VACC+8
	movl	_ei+8(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %si
	andl	_VR+4(%ebx), %esi
	notl	%esi
	movw	%si, _VACC+16
	movl	_ei+12(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	32(%esp), %eax
	andw	_VR+6(%eax), %bx
	notl	%ebx
	movw	%bx, _VACC+24
	movl	(%esp), %ecx
	addl	_ei+16(%edx), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	_VR+8(%eax), %edx
	andl	%edx, %ecx
	notl	%ecx
	movw	%cx, 6(%esp)
	movw	%cx, _VACC+32
	movl	(%esp), %ecx
	movl	40(%esp), %eax
	addl	_ei+20(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %edx
	movw	_VR+10(%edx), %dx
	andl	%edx, %ecx
	notl	%ecx
	movw	%cx, 4(%esp)
	movw	%cx, _VACC+40
	movl	(%esp), %ecx
	addl	_ei+24(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %eax
	andl	_VR+12(%eax), %ecx
	notl	%ecx
	movw	%cx, _VACC+48
	movl	(%esp), %edx
	movl	40(%esp), %eax
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %dx
	movl	32(%esp), %eax
	andw	_VR+14(%eax), %dx
	notl	%edx
	movw	%dx, _VACC+56
	sall	$4, 28(%esp)
	movl	28(%esp), %eax
	movw	%bp, _VR(%eax)
	movw	%di, _VR+2(%eax)
	movw	%si, _VR+4(%eax)
	movw	%bx, _VR+6(%eax)
	movw	6(%esp), %bx
	movw	%bx, _VR+8(%eax)
	movl	4(%esp), %ebx
	movw	%bx, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE51:
	.p2align 2,,3
	.def	_VNE;	.scl	3;	.type	32;	.endef
_VNE:
LFB52:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$36, %esp
	.cfi_def_cfa_offset 56
	movl	60(%esp), %eax
	movl	_VCO, %edx
	movl	%edx, %esi
	shrw	$8, %si
	sall	$4, %eax
	movl	_VR(%eax), %ebp
	sall	$5, 68(%esp)
	movl	64(%esp), %ecx
	sall	$3, %ecx
	movl	%ecx, 8(%esp)
	movl	68(%esp), %ebx
	addl	_ei(%ebx), %ecx
	movw	_VR(%ecx,%ecx), %di
	andl	$1, %esi
	cmpw	%di, %bp
	setne	%cl
	movl	%esi, %ebx
	orb	%cl, %bl
	movl	%ebx, %esi
	cmove	%edi, %ebp
	movw	%bp, 28(%esp)
	movw	%bp, _VACC
	movl	%edx, %edi
	shrw	$9, %di
	movl	8(%esp), %ecx
	movl	68(%esp), %ebx
	addl	_ei+4(%ebx), %ecx
	movw	_VR(%ecx,%ecx), %bx
	cmpw	%bx, _VR+2(%eax)
	setne	%cl
	orl	%ecx, %edi
	andl	$1, %edi
	movl	%esi, %ecx
	movzbl	%cl, %ebp
	leal	(%edi,%edi), %esi
	orl	%esi, %ebp
	testl	%edi, %edi
	cmovne	_VR+2(%eax), %bx
	movw	%bx, 30(%esp)
	movw	%bx, _VACC+8
	movl	%edx, %edi
	shrw	$10, %di
	movl	_VR+4(%eax), %ebx
	movl	8(%esp), %ecx
	movl	68(%esp), %esi
	addl	_ei+8(%esi), %ecx
	movw	_VR(%ecx,%ecx), %si
	cmpw	%si, %bx
	setne	%cl
	orl	%edi, %ecx
	andl	$1, %ecx
	leal	0(,%ecx,4), %edi
	orl	%edi, %ebp
	testl	%ecx, %ecx
	cmove	%esi, %ebx
	movw	%bx, 32(%esp)
	movw	%bx, _VACC+16
	movl	%edx, %edi
	shrw	$11, %di
	movw	_VR+6(%eax), %bx
	movl	8(%esp), %ecx
	movl	68(%esp), %esi
	addl	_ei+12(%esi), %ecx
	movw	_VR(%ecx,%ecx), %si
	cmpw	%si, %bx
	setne	%cl
	orl	%edi, %ecx
	andl	$1, %ecx
	leal	0(,%ecx,8), %edi
	orl	%edi, %ebp
	testl	%ecx, %ecx
	cmove	%esi, %ebx
	movw	%bx, 34(%esp)
	movw	%bx, _VACC+24
	movl	%edx, %ebx
	shrw	$12, %bx
	movl	_VR+8(%eax), %edi
	movl	8(%esp), %ecx
	movl	68(%esp), %esi
	addl	_ei+16(%esi), %ecx
	movw	_VR(%ecx,%ecx), %si
	cmpw	%si, %di
	setne	%cl
	orl	%ebx, %ecx
	andl	$1, %ecx
	movl	%ecx, %ebx
	sall	$4, %ebx
	orl	%ebx, %ebp
	testl	%ecx, %ecx
	cmovne	%edi, %esi
	movw	%si, _VACC+32
	movl	%edx, %edi
	shrw	$13, %di
	movl	8(%esp), %ecx
	movl	68(%esp), %ebx
	addl	_ei+20(%ebx), %ecx
	movw	_VR(%ecx,%ecx), %bx
	cmpw	%bx, _VR+10(%eax)
	setne	%cl
	orl	%edi, %ecx
	andl	$1, %ecx
	movl	%ecx, %edi
	sall	$5, %edi
	orl	%edi, %ebp
	testl	%ecx, %ecx
	cmovne	_VR+10(%eax), %bx
	movw	%bx, _VACC+40
	movl	%edx, %edi
	shrw	$14, %di
	movw	%di, 12(%esp)
	movl	8(%esp), %ecx
	movl	68(%esp), %edi
	addl	_ei+24(%edi), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, 6(%esp)
	cmpw	%cx, _VR+12(%eax)
	setne	%cl
	movl	12(%esp), %edi
	orl	%edi, %ecx
	andl	$1, %ecx
	movl	%ecx, %edi
	sall	$6, %edi
	orl	%edi, %ebp
	testl	%ecx, %ecx
	movl	_VR+12(%eax), %ecx
	cmove	6(%esp), %cx
	movw	%cx, _VACC+48
	movw	_VR+14(%eax), %ax
	movw	%ax, 12(%esp)
	movl	8(%esp), %edi
	movl	68(%esp), %eax
	addl	_ei+28(%eax), %edi
	movw	_VR(%edi,%edi), %di
	shrw	$15, %dx
	cmpw	%di, 12(%esp)
	setne	%al
	orl	%edx, %eax
	movzbl	%al, %eax
	testl	%eax, %eax
	cmovne	12(%esp), %di
	movw	%di, _VACC+56
	sall	$7, %eax
	orl	%eax, %ebp
	movw	%bp, _VCC
	movw	$0, _VCO
	sall	$4, 56(%esp)
	movl	28(%esp), %eax
	movl	56(%esp), %edx
	movw	%ax, _VR(%edx)
	movw	30(%esp), %ax
	movw	%ax, _VR+2(%edx)
	movl	32(%esp), %eax
	movw	%ax, _VR+4(%edx)
	movw	34(%esp), %ax
	movw	%ax, _VR+6(%edx)
	movw	%si, _VR+8(%edx)
	movw	%bx, _VR+10(%edx)
	movw	%cx, _VR+12(%edx)
	movw	%di, _VR+14(%edx)
	addl	$36, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE52:
	.p2align 2,,3
	.def	_VNOR;	.scl	3;	.type	32;	.endef
_VNOR:
LFB54:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	sall	$5, 40(%esp)
	movl	36(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	movl	%eax, %ecx
	movl	40(%esp), %edx
	addl	_ei(%edx), %ecx
	sall	$4, 32(%esp)
	movw	_VR(%ecx,%ecx), %bp
	movl	32(%esp), %ecx
	orl	_VR(%ecx), %ebp
	notl	%ebp
	movw	%bp, _VACC
	movl	_ei+4(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %di
	movl	32(%esp), %ebx
	orw	_VR+2(%ebx), %di
	notl	%edi
	movw	%di, _VACC+8
	movl	_ei+8(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %si
	orl	_VR+4(%ebx), %esi
	notl	%esi
	movw	%si, _VACC+16
	movl	_ei+12(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	32(%esp), %eax
	orw	_VR+6(%eax), %bx
	notl	%ebx
	movw	%bx, _VACC+24
	movl	(%esp), %ecx
	addl	_ei+16(%edx), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	_VR+8(%eax), %edx
	orl	%edx, %ecx
	notl	%ecx
	movw	%cx, 6(%esp)
	movw	%cx, _VACC+32
	movl	(%esp), %ecx
	movl	40(%esp), %eax
	addl	_ei+20(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %edx
	movw	_VR+10(%edx), %dx
	orl	%edx, %ecx
	notl	%ecx
	movw	%cx, 4(%esp)
	movw	%cx, _VACC+40
	movl	(%esp), %ecx
	addl	_ei+24(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %eax
	orl	_VR+12(%eax), %ecx
	notl	%ecx
	movw	%cx, _VACC+48
	movl	(%esp), %edx
	movl	40(%esp), %eax
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %dx
	movl	32(%esp), %eax
	orw	_VR+14(%eax), %dx
	notl	%edx
	movw	%dx, _VACC+56
	sall	$4, 28(%esp)
	movl	28(%esp), %eax
	movw	%bp, _VR(%eax)
	movw	%di, _VR+2(%eax)
	movw	%si, _VR+4(%eax)
	movw	%bx, _VR+6(%eax)
	movw	6(%esp), %bx
	movw	%bx, _VR+8(%eax)
	movl	4(%esp), %ebx
	movw	%bx, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE54:
	.p2align 2,,3
	.def	_VNXOR;	.scl	3;	.type	32;	.endef
_VNXOR:
LFB55:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	sall	$5, 40(%esp)
	movl	36(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	movl	%eax, %ecx
	movl	40(%esp), %edx
	addl	_ei(%edx), %ecx
	sall	$4, 32(%esp)
	movw	_VR(%ecx,%ecx), %bp
	movl	32(%esp), %ecx
	xorl	_VR(%ecx), %ebp
	notl	%ebp
	movw	%bp, _VACC
	movl	_ei+4(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %di
	movl	32(%esp), %ebx
	xorw	_VR+2(%ebx), %di
	notl	%edi
	movw	%di, _VACC+8
	movl	_ei+8(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %si
	xorl	_VR+4(%ebx), %esi
	notl	%esi
	movw	%si, _VACC+16
	movl	_ei+12(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	32(%esp), %eax
	xorw	_VR+6(%eax), %bx
	notl	%ebx
	movw	%bx, _VACC+24
	movl	(%esp), %ecx
	addl	_ei+16(%edx), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	_VR+8(%eax), %edx
	xorl	%edx, %ecx
	notl	%ecx
	movw	%cx, 6(%esp)
	movw	%cx, _VACC+32
	movl	(%esp), %ecx
	movl	40(%esp), %eax
	addl	_ei+20(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %edx
	movw	_VR+10(%edx), %dx
	xorl	%edx, %ecx
	notl	%ecx
	movw	%cx, 4(%esp)
	movw	%cx, _VACC+40
	movl	(%esp), %ecx
	addl	_ei+24(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %eax
	xorl	_VR+12(%eax), %ecx
	notl	%ecx
	movw	%cx, _VACC+48
	movl	(%esp), %edx
	movl	40(%esp), %eax
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %dx
	movl	32(%esp), %eax
	xorw	_VR+14(%eax), %dx
	notl	%edx
	movw	%dx, _VACC+56
	sall	$4, 28(%esp)
	movl	28(%esp), %eax
	movw	%bp, _VR(%eax)
	movw	%di, _VR+2(%eax)
	movw	%si, _VR+4(%eax)
	movw	%bx, _VR+6(%eax)
	movw	6(%esp), %bx
	movw	%bx, _VR+8(%eax)
	movl	4(%esp), %ebx
	movw	%bx, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE55:
	.p2align 2,,3
	.def	_VOR;	.scl	3;	.type	32;	.endef
_VOR:
LFB56:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	sall	$5, 40(%esp)
	movl	36(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	movl	%eax, %ecx
	movl	40(%esp), %edx
	addl	_ei(%edx), %ecx
	sall	$4, 32(%esp)
	movw	_VR(%ecx,%ecx), %bp
	movl	32(%esp), %ecx
	orl	_VR(%ecx), %ebp
	movw	%bp, _VACC
	movl	_ei+4(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %di
	movl	32(%esp), %ebx
	orw	_VR+2(%ebx), %di
	movw	%di, _VACC+8
	movl	_ei+8(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %si
	orl	_VR+4(%ebx), %esi
	movw	%si, _VACC+16
	movl	_ei+12(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	32(%esp), %eax
	orw	_VR+6(%eax), %bx
	movw	%bx, _VACC+24
	movl	(%esp), %ecx
	addl	_ei+16(%edx), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	_VR+8(%eax), %edx
	orl	%edx, %ecx
	movw	%cx, 6(%esp)
	movw	%cx, _VACC+32
	movl	(%esp), %ecx
	movl	40(%esp), %eax
	addl	_ei+20(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %edx
	movw	_VR+10(%edx), %dx
	orl	%edx, %ecx
	movw	%cx, 4(%esp)
	movw	%cx, _VACC+40
	movl	(%esp), %ecx
	addl	_ei+24(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %eax
	orl	_VR+12(%eax), %ecx
	movw	%cx, _VACC+48
	movl	(%esp), %edx
	movl	40(%esp), %eax
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %dx
	movl	32(%esp), %eax
	orw	_VR+14(%eax), %dx
	movw	%dx, _VACC+56
	sall	$4, 28(%esp)
	movl	28(%esp), %eax
	movw	%bp, _VR(%eax)
	movw	%di, _VR+2(%eax)
	movw	%si, _VR+4(%eax)
	movw	%bx, _VR+6(%eax)
	movw	6(%esp), %bx
	movw	%bx, _VR+8(%eax)
	movl	4(%esp), %ebx
	movw	%bx, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE56:
	.p2align 2,,3
	.def	_VRCP;	.scl	3;	.type	32;	.endef
_VRCP:
LFB57:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$12, %esp
	.cfi_def_cfa_offset 24
	movl	32(%esp), %edx
	movl	36(%esp), %eax
	movl	%eax, %ecx
	andl	$7, %ecx
	leal	(%ecx,%edx,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movswl	%bx, %ecx
	movl	%ecx, _DivIn
	cmpl	$0, %ecx
	je	L710
	jl	L713
	fldl	LC2
	pushl	%ebx
	fidivs	(%esp)
	popl	%ebx
	fstpl	(%esp)
	cvttsd2si	(%esp), %ecx
	movl	%ecx, %ebx
	jmp	L708
	.p2align 2,,3
L710:
	movl	$-1, %ebx
	movl	$2147483647, %ecx
L708:
	sall	$5, %eax
	sall	$3, %edx
	movl	_ei(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC
	movl	_ei+4(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+8
	movl	_ei+8(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+16
	movl	_ei+12(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+24
	movl	_ei+16(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+32
	movl	_ei+20(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+40
	movl	_ei+24(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+48
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %ax
	movw	%ax, _VACC+56
	movl	%ecx, _DivOut
	movl	28(%esp), %eax
	andl	$7, %eax
	movl	24(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movw	%bx, _VR(%eax,%eax)
	movl	$0, _DPH
	addl	$12, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L713:
	.cfi_restore_state
	negl	%ecx
	fldl	LC2
	pushl	%ecx
	fidivl	(%esp)
	popl	%esi
	fstpl	(%esp)
	cvttsd2si	(%esp), %ecx
	notl	%ecx
	movl	%ecx, %ebx
	jmp	L708
	.cfi_endproc
LFE57:
	.p2align 2,,3
	.def	_VRCPH;	.scl	3;	.type	32;	.endef
_VRCPH:
LFB58:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %ecx
	movl	20(%esp), %edx
	movl	%edx, %ebx
	andl	$7, %ebx
	movl	16(%esp), %eax
	sall	$3, %eax
	addl	%eax, %ebx
	movswl	_VR(%ebx,%ebx), %ebx
	sall	$16, %ebx
	movl	%ebx, _DivIn
	sall	$5, %edx
	movl	_ei(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC
	movl	_ei+4(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+8
	movl	_ei+8(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+16
	movl	_ei+12(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+24
	movl	_ei+16(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+32
	movl	_ei+20(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+40
	movl	_ei+24(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+48
	addl	_ei+28(%edx), %eax
	movw	_VR(%eax,%eax), %ax
	movw	%ax, _VACC+56
	andl	$7, %ecx
	movl	8(%esp), %eax
	leal	(%ecx,%eax,8), %edx
	movl	_DivOut, %eax
	sarl	$16, %eax
	movw	%ax, _VR(%edx,%edx)
	movl	$1, _DPH
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE58:
	.p2align 2,,3
	.def	_VRCPL;	.scl	3;	.type	32;	.endef
_VRCPL:
LFB59:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	20(%esp), %ebx
	movl	24(%esp), %eax
	andl	$7, %eax
	leal	(%eax,%ebx,8), %eax
	movl	_DPH, %edx
	testl	%edx, %edx
	je	L717
	movzwl	_VR(%eax,%eax), %ecx
	orl	_DivIn, %ecx
	movl	%ecx, _DivIn
	cmpl	$0, %ecx
	je	L722
L726:
	jl	L725
	movl	$2147483647, %eax
	cltd
	idivl	%ecx
	movl	%eax, %esi
	jmp	L719
	.p2align 2,,3
L717:
	movswl	_VR(%eax,%eax), %ecx
	movl	%ecx, _DivIn
	cmpl	$0, %ecx
	jne	L726
L722:
	movl	$-1, %esi
	movl	$2147483647, %eax
L719:
	movl	24(%esp), %ecx
	sall	$5, %ecx
	leal	0(,%ebx,8), %edx
	movl	_ei(%ecx), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC
	movl	_ei+4(%ecx), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+8
	movl	_ei+8(%ecx), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+16
	movl	_ei+12(%ecx), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+24
	movl	_ei+16(%ecx), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+32
	movl	_ei+20(%ecx), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+40
	movl	_ei+24(%ecx), %ebx
	addl	%edx, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+48
	addl	_ei+28(%ecx), %edx
	movw	_VR(%edx,%edx), %dx
	movw	%dx, _VACC+56
	movl	%eax, _DivOut
	movl	16(%esp), %eax
	andl	$7, %eax
	movl	12(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movw	%si, _VR(%eax,%eax)
	movl	$0, _DPH
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L725:
	.cfi_restore_state
	notl	%ecx
	movl	%ecx, %eax
	andl	$-32768, %eax
	cmpl	$1, %eax
	adcl	$0, %ecx
	movl	$2147483647, %eax
	cltd
	idivl	%ecx
	notl	%eax
	movl	%eax, %esi
	jmp	L719
	.cfi_endproc
LFE59:
	.p2align 2,,3
	.def	_VRSQH;	.scl	3;	.type	32;	.endef
_VRSQH:
LFB61:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %ecx
	movl	20(%esp), %edx
	movl	%edx, %ebx
	andl	$7, %ebx
	movl	16(%esp), %eax
	sall	$3, %eax
	addl	%eax, %ebx
	movswl	_VR(%ebx,%ebx), %ebx
	sall	$16, %ebx
	movl	%ebx, _DivIn
	sall	$5, %edx
	movl	_ei(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC
	movl	_ei+4(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+8
	movl	_ei+8(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+16
	movl	_ei+12(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+24
	movl	_ei+16(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+32
	movl	_ei+20(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+40
	movl	_ei+24(%edx), %ebx
	addl	%eax, %ebx
	movw	_VR(%ebx,%ebx), %bx
	movw	%bx, _VACC+48
	addl	_ei+28(%edx), %eax
	movw	_VR(%eax,%eax), %ax
	movw	%ax, _VACC+56
	andl	$7, %ecx
	movl	8(%esp), %eax
	leal	(%ecx,%eax,8), %edx
	movl	_DivOut, %eax
	sarl	$16, %eax
	movw	%ax, _VR(%edx,%edx)
	movl	$1, _DPH
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE61:
	.p2align 2,,3
	.def	_VSUB;	.scl	3;	.type	32;	.endef
_VSUB:
LFB91:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$60, %esp
	.cfi_def_cfa_offset 80
	movl	84(%esp), %edx
	movl	92(%esp), %eax
	movl	_VCO, %ecx
	sall	$4, %edx
	movswl	_VR(%edx), %ebx
	sall	$5, %eax
	movl	88(%esp), %esi
	sall	$3, %esi
	movl	%esi, 12(%esp)
	addl	_ei(%eax), %esi
	movswl	_VR(%esi,%esi), %esi
	subl	%esi, %ebx
	movl	%ecx, %esi
	andl	$1, %esi
	subl	%esi, %ebx
	movl	%ecx, %edi
	shrw	%di
	movswl	_VR+2(%edx), %esi
	movl	12(%esp), %ebp
	addl	_ei+4(%eax), %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	subl	%ebp, %esi
	andl	$1, %edi
	subl	%edi, %esi
	movl	%esi, 20(%esp)
	movl	%ecx, %edi
	shrw	$2, %di
	movswl	_VR+4(%edx), %esi
	movl	12(%esp), %ebp
	addl	_ei+8(%eax), %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	subl	%ebp, %esi
	andl	$1, %edi
	subl	%edi, %esi
	movl	%esi, 24(%esp)
	movl	%ecx, %edi
	shrw	$3, %di
	movswl	_VR+6(%edx), %esi
	movl	12(%esp), %ebp
	addl	_ei+12(%eax), %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	subl	%ebp, %esi
	andl	$1, %edi
	subl	%edi, %esi
	movl	%esi, 28(%esp)
	movl	%ecx, %edi
	shrw	$4, %di
	movswl	_VR+8(%edx), %esi
	movl	12(%esp), %ebp
	addl	_ei+16(%eax), %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	subl	%ebp, %esi
	andl	$1, %edi
	subl	%edi, %esi
	movl	%esi, 32(%esp)
	movl	%ecx, %edi
	shrw	$5, %di
	movswl	_VR+10(%edx), %esi
	movl	12(%esp), %ebp
	addl	_ei+20(%eax), %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	subl	%ebp, %esi
	andl	$1, %edi
	subl	%edi, %esi
	movl	%esi, 36(%esp)
	movl	%ecx, %edi
	shrw	$6, %di
	movswl	_VR+12(%edx), %esi
	movl	12(%esp), %ebp
	addl	_ei+24(%eax), %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	subl	%ebp, %esi
	andl	$1, %edi
	subl	%edi, %esi
	movl	%esi, 40(%esp)
	shrw	$7, %cx
	movswl	_VR+14(%edx), %edx
	movl	_ei+28(%eax), %eax
	addl	12(%esp), %eax
	movswl	_VR(%eax,%eax), %eax
	subl	%eax, %edx
	andl	$1, %ecx
	subl	%ecx, %edx
	movl	%edx, 44(%esp)
	movw	%bx, _VACC
	movl	80(%esp), %eax
	sall	$4, %eax
	cmpl	$32767, %ebx
	jg	L730
	cmpl	$-32768, %ebx
	jge	L755
	movw	$-32768, _VR(%eax)
	jmp	L732
	.p2align 2,,3
L730:
	movw	$32767, _VR(%eax)
L732:
	movl	20(%esp), %eax
	movw	%ax, _VACC+8
	cmpl	$32767, %eax
	jg	L733
	cmpl	$-32768, %eax
	jge	L756
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L735
	.p2align 2,,3
L733:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
L735:
	movl	24(%esp), %eax
	movw	%ax, _VACC+16
	cmpl	$32767, %eax
	jg	L736
	cmpl	$-32768, %eax
	jge	L757
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L738
	.p2align 2,,3
L736:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
L738:
	movl	28(%esp), %eax
	movw	%ax, _VACC+24
	cmpl	$32767, %eax
	jg	L739
	cmpl	$-32768, %eax
	jge	L758
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L741
	.p2align 2,,3
L739:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
L741:
	movl	32(%esp), %eax
	movw	%ax, _VACC+32
	cmpl	$32767, %eax
	jg	L742
	cmpl	$-32768, %eax
	jge	L759
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L744
	.p2align 2,,3
L742:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
L744:
	movl	36(%esp), %eax
	movw	%ax, _VACC+40
	cmpl	$32767, %eax
	jg	L745
	cmpl	$-32768, %eax
	jge	L760
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L747
	.p2align 2,,3
L745:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
L747:
	movl	40(%esp), %eax
	movw	%ax, _VACC+48
	cmpl	$32767, %eax
	jg	L748
	cmpl	$-32768, %eax
	jge	L761
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L750
	.p2align 2,,3
L748:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
L750:
	movl	44(%esp), %eax
	movw	%ax, _VACC+56
	cmpl	$32767, %eax
	jle	L751
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+14(%eax)
L752:
	movw	$0, _VCO
	addl	$60, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L751:
	.cfi_restore_state
	cmpl	$-32768, %eax
	jge	L753
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+14(%eax)
	jmp	L752
	.p2align 2,,3
L753:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+14(%edx)
	jmp	L752
	.p2align 2,,3
L761:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+12(%edx)
	jmp	L750
	.p2align 2,,3
L760:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+10(%edx)
	jmp	L747
	.p2align 2,,3
L759:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+8(%edx)
	jmp	L744
	.p2align 2,,3
L758:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+6(%edx)
	jmp	L741
	.p2align 2,,3
L757:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+4(%edx)
	jmp	L738
	.p2align 2,,3
L756:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+2(%edx)
	jmp	L735
	.p2align 2,,3
L755:
	movw	%bx, _VR(%eax)
	jmp	L732
	.cfi_endproc
LFE91:
	.p2align 2,,3
	.def	_VSUBC;	.scl	3;	.type	32;	.endef
_VSUBC:
LFB92:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$16, %esp
	.cfi_def_cfa_offset 36
	movl	40(%esp), %edx
	movl	44(%esp), %edi
	movl	48(%esp), %eax
	movl	%edx, %ecx
	sall	$4, %ecx
	movzwl	_VR(%ecx), %ebx
	movl	%eax, %ecx
	sall	$5, %ecx
	movl	_ei(%ecx), %ecx
	leal	(%ecx,%edi,8), %ecx
	movzwl	_VR(%ecx,%ecx), %ecx
	subl	%ecx, %ebx
	movw	%bx, _VACC
	testl	%ebx, %ebx
	je	L763
	shrl	$31, %ebx
	orb	$1, %bh
L764:
	sall	$4, %edx
	movzwl	_VR+2(%edx), %esi
	sall	$5, %eax
	sall	$3, %edi
	movl	%edi, (%esp)
	movl	_ei+4(%eax), %ecx
	addl	%edi, %ecx
	movzwl	_VR(%ecx,%ecx), %ecx
	subl	%ecx, %esi
	movw	%si, _VACC+8
	movl	%esi, %ecx
	shrl	$31, %ecx
	sall	%ecx
	orb	$2, %ch
	orl	%ebx, %ecx
	testl	%esi, %esi
	cmove	%ebx, %ecx
	movzwl	_VR+4(%edx), %ebx
	movl	%ebx, 4(%esp)
	movl	_ei+8(%eax), %ebx
	addl	%edi, %ebx
	movzwl	_VR(%ebx,%ebx), %ebx
	subl	%ebx, 4(%esp)
	movl	4(%esp), %edi
	movw	%di, _VACC+16
	movl	4(%esp), %ebx
	shrl	$31, %ebx
	sall	$2, %ebx
	orb	$4, %bh
	orl	%ecx, %ebx
	movl	4(%esp), %edi
	testl	%edi, %edi
	cmove	%ecx, %ebx
	movzwl	_VR+6(%edx), %ecx
	movl	%ecx, 8(%esp)
	movl	(%esp), %ecx
	addl	_ei+12(%eax), %ecx
	movzwl	_VR(%ecx,%ecx), %ecx
	subl	%ecx, 8(%esp)
	movl	8(%esp), %edi
	movw	%di, _VACC+24
	movl	8(%esp), %ecx
	shrl	$31, %ecx
	sall	$3, %ecx
	orb	$8, %ch
	orl	%ebx, %ecx
	movl	8(%esp), %ebp
	testl	%ebp, %ebp
	cmove	%ebx, %ecx
	movzwl	_VR+8(%edx), %ebx
	movl	(%esp), %edi
	addl	_ei+16(%eax), %edi
	movzwl	_VR(%edi,%edi), %edi
	subl	%edi, %ebx
	movw	%bx, _VACC+32
	movl	%ebx, %ebp
	shrl	$31, %ebp
	sall	$4, %ebp
	orl	$4096, %ebp
	orl	%ecx, %ebp
	testl	%ebx, %ebx
	cmovne	%ebp, %ecx
	movzwl	_VR+10(%edx), %edi
	movl	%edi, 12(%esp)
	movl	(%esp), %edi
	addl	_ei+20(%eax), %edi
	movzwl	_VR(%edi,%edi), %edi
	subl	%edi, 12(%esp)
	movl	12(%esp), %edi
	movw	%di, _VACC+40
	movl	12(%esp), %ebp
	shrl	$31, %ebp
	sall	$5, %ebp
	orl	$8192, %ebp
	orl	%ecx, %ebp
	movl	12(%esp), %edi
	testl	%edi, %edi
	cmove	%ecx, %ebp
	movzwl	_VR+12(%edx), %ecx
	movl	(%esp), %edi
	addl	_ei+24(%eax), %edi
	movzwl	_VR(%edi,%edi), %edi
	subl	%edi, %ecx
	movw	%cx, _VACC+48
	movl	%ecx, %edi
	shrl	$31, %edi
	sall	$6, %edi
	orl	$16384, %edi
	orl	%ebp, %edi
	testl	%ecx, %ecx
	cmove	%ebp, %edi
	movzwl	_VR+14(%edx), %edx
	movl	_ei+28(%eax), %eax
	addl	(%esp), %eax
	movzwl	_VR(%eax,%eax), %eax
	subl	%eax, %edx
	movw	%dx, _VACC+56
	movl	%edx, %eax
	shrl	$31, %eax
	sall	$7, %eax
	orl	$-32768, %eax
	orl	%edi, %eax
	testl	%edx, %edx
	cmove	%edi, %eax
	movw	%ax, _VCO
	movl	36(%esp), %eax
	sall	$4, %eax
	movl	_VACC, %edi
	movw	%di, _VR(%eax)
	movw	%si, _VR+2(%eax)
	movl	4(%esp), %esi
	movw	%si, _VR+4(%eax)
	movl	8(%esp), %edi
	movw	%di, _VR+6(%eax)
	movw	%bx, _VR+8(%eax)
	movl	12(%esp), %ebx
	movw	%bx, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L763:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L764
	.cfi_endproc
LFE92:
	.p2align 2,,3
	.def	_VXOR;	.scl	3;	.type	32;	.endef
_VXOR:
LFB93:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	sall	$5, 40(%esp)
	movl	36(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	movl	%eax, %ecx
	movl	40(%esp), %edx
	addl	_ei(%edx), %ecx
	sall	$4, 32(%esp)
	movw	_VR(%ecx,%ecx), %bp
	movl	32(%esp), %ecx
	xorl	_VR(%ecx), %ebp
	movw	%bp, _VACC
	movl	_ei+4(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %di
	movl	32(%esp), %ebx
	xorw	_VR+2(%ebx), %di
	movw	%di, _VACC+8
	movl	_ei+8(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %si
	xorl	_VR+4(%ebx), %esi
	movw	%si, _VACC+16
	movl	_ei+12(%edx), %ecx
	addl	%eax, %ecx
	movw	_VR(%ecx,%ecx), %bx
	movl	32(%esp), %eax
	xorw	_VR+6(%eax), %bx
	movw	%bx, _VACC+24
	movl	(%esp), %ecx
	addl	_ei+16(%edx), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	_VR+8(%eax), %edx
	xorl	%edx, %ecx
	movw	%cx, 6(%esp)
	movw	%cx, _VACC+32
	movl	(%esp), %ecx
	movl	40(%esp), %eax
	addl	_ei+20(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %edx
	movw	_VR+10(%edx), %dx
	xorl	%edx, %ecx
	movw	%cx, 4(%esp)
	movw	%cx, _VACC+40
	movl	(%esp), %ecx
	addl	_ei+24(%eax), %ecx
	movw	_VR(%ecx,%ecx), %cx
	movl	32(%esp), %eax
	xorl	_VR+12(%eax), %ecx
	movw	%cx, _VACC+48
	movl	(%esp), %edx
	movl	40(%esp), %eax
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %dx
	movl	32(%esp), %eax
	xorw	_VR+14(%eax), %dx
	movw	%dx, _VACC+56
	sall	$4, 28(%esp)
	movl	28(%esp), %eax
	movw	%bp, _VR(%eax)
	movw	%di, _VR+2(%eax)
	movw	%si, _VR+4(%eax)
	movw	%bx, _VR+6(%eax)
	movw	6(%esp), %bx
	movw	%bx, _VR+8(%eax)
	movl	4(%esp), %ebx
	movw	%bx, _VR+10(%eax)
	movw	%cx, _VR+12(%eax)
	movw	%dx, _VR+14(%eax)
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE93:
	.p2align 2,,3
	.globl	_LBV
	.def	_LBV;	.scl	2;	.type	32;	.endef
_LBV:
LFB101:
	.cfi_startproc
	movl	4(%esp), %ecx
	movl	8(%esp), %edx
	movl	16(%esp), %eax
	movl	_SR(,%eax,4), %eax
	addl	12(%esp), %eax
	andl	$4095, %eax
	testb	$1, %dl
	jne	L785
	shrl	%edx
	leal	(%edx,%ecx,8), %ecx
	xorl	$3, %eax
	movl	_RSP+12, %edx
	movzbl	(%edx,%eax), %edx
	sall	$8, %edx
	movzbl	_VR(%ecx,%ecx), %eax
	orl	%edx, %eax
	movw	%ax, _VR(%ecx,%ecx)
	ret
	.p2align 2,,3
L785:
	shrl	%edx
	leal	(%edx,%ecx,8), %ecx
	xorl	$3, %eax
	movl	_RSP+12, %edx
	movzbl	(%edx,%eax), %eax
	movw	_VR(%ecx,%ecx), %dx
	xorb	%dl, %dl
	orl	%edx, %eax
	movw	%ax, _VR(%ecx,%ecx)
	ret
	.cfi_endproc
LFE101:
	.p2align 2,,3
	.globl	_SBV
	.def	_SBV;	.scl	2;	.type	32;	.endef
_SBV:
LFB113:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %ecx
	movl	20(%esp), %eax
	movl	_SR(,%eax,4), %eax
	addl	16(%esp), %eax
	andl	$4095, %eax
	xorl	$3, %eax
	addl	_RSP+12, %eax
	movl	%ecx, %edx
	sarl	%edx
	movl	8(%esp), %ebx
	leal	(%edx,%ebx,8), %edx
	movswl	_VR(%edx,%edx), %edx
	andl	$1, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	andl	$8, %ecx
	sarl	%cl, %edx
	movb	%dl, (%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE113:
	.p2align 2,,3
	.globl	_SSV
	.def	_SSV;	.scl	2;	.type	32;	.endef
_SSV:
LFB114:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	24(%esp), %eax
	movl	32(%esp), %edx
	movl	_SR(,%edx,4), %edx
	movl	28(%esp), %ecx
	leal	(%edx,%ecx,2), %edx
	movl	%edx, %ecx
	andl	$4095, %ecx
	testb	$1, %al
	jne	L798
	shrl	%eax
	andl	$3, %edx
	cmpl	$2, %edx
	je	L795
	cmpl	$3, %edx
	je	L796
	decl	%edx
	je	L794
	movl	20(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movw	_VR(%eax,%eax), %dx
	movl	_RSP+12, %eax
	movw	%dx, 2(%eax,%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L798:
	.cfi_restore_state
	shrl	%eax
	movl	%ecx, %ebp
	xorl	$3, %ebp
	movl	20(%esp), %edx
	sall	$3, %edx
	leal	(%edx,%eax), %esi
	movw	_VR(%esi,%esi), %si
	movl	%esi, %ebx
	movl	_RSP+12, %edi
	movb	%bl, (%edi,%ebp)
	incl	%ecx
	incl	%eax
	andl	$4095, %ecx
	xorl	$3, %ecx
	andl	$7, %eax
	addl	%edx, %eax
	movw	_VR(%eax,%eax), %ax
	sarw	$8, %ax
	movl	_RSP+12, %edx
	movb	%al, (%edx,%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L795:
	.cfi_restore_state
	movl	20(%esp), %edi
	leal	(%eax,%edi,8), %eax
	movw	_VR(%eax,%eax), %dx
	movl	_RSP+12, %eax
	movw	%dx, -2(%eax,%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L794:
	.cfi_restore_state
	movl	20(%esp), %ebx
	leal	(%eax,%ebx,8), %eax
	movw	_VR(%eax,%eax), %dx
	movl	_RSP+12, %eax
	movw	%dx, (%eax,%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L796:
	.cfi_restore_state
	movl	20(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movw	_VR(%eax,%eax), %ax
	movl	%eax, %ebx
	shrw	$8, %bx
	movl	_RSP+12, %edx
	movb	%bl, -3(%edx,%ecx)
	addl	$4, %ecx
	andl	$4095, %ecx
	movl	_RSP+12, %edx
	movb	%al, (%edx,%ecx)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE114:
	.section .rdata,"dr"
LC4:
	.ascii "CP2\0"
LC5:
	.ascii "VNOP\0"
	.text
	.p2align 2,,3
	.def	_VNOP;	.scl	3;	.type	32;	.endef
_VNOP:
LFB53:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$64, 12(%esp)
	movl	$LC4, 8(%esp)
	movl	$LC5, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE53:
	.p2align 2,,3
	.def	_VRSQL;	.scl	3;	.type	32;	.endef
_VRSQL:
LFB89:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	56(%esp), %esi
	movl	60(%esp), %eax
	andl	$7, %eax
	leal	(%eax,%esi,8), %eax
	movl	_DPH, %edx
	testl	%edx, %edx
	je	L802
	movzwl	_VR(%eax,%eax), %eax
	orl	_DivIn, %eax
	movl	%eax, _DivIn
	testl	%eax, %eax
	je	L811
L817:
	cmpl	$-32768, %eax
	je	L812
	testl	%eax, %eax
	js	L815
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	fld	%st(0)
	fsqrt
	fucomi	%st(0), %st
	jp	L816
	fstp	%st(1)
L809:
	fdivrs	LC6
	fstps	24(%esp)
	cvttss2si	24(%esp), %ecx
	movl	%ecx, %ebx
	jmp	L804
	.p2align 2,,3
L802:
	movswl	_VR(%eax,%eax), %eax
	movl	%eax, _DivIn
	testl	%eax, %eax
	jne	L817
L811:
	movl	$-1, %ebx
	movl	$2147483647, %ecx
L804:
	movl	60(%esp), %eax
	sall	$5, %eax
	leal	0(,%esi,8), %edx
	movl	_ei(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC
	movl	_ei+4(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+8
	movl	_ei+8(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+16
	movl	_ei+12(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+24
	movl	_ei+16(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+32
	movl	_ei+20(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+40
	movl	_ei+24(%eax), %esi
	addl	%edx, %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+48
	addl	_ei+28(%eax), %edx
	movw	_VR(%edx,%edx), %ax
	movw	%ax, _VACC+56
	movl	%ecx, _DivOut
	movl	52(%esp), %eax
	andl	$7, %eax
	movl	48(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movw	%bx, _VR(%eax,%eax)
	movl	$0, _DPH
	addl	$36, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L812:
	.cfi_restore_state
	xorl	%ebx, %ebx
	movl	$-65536, %ecx
	jmp	L804
	.p2align 2,,3
L815:
	notl	%eax
	movl	%eax, %ecx
	andl	$-32768, %ecx
	cmpl	$1, %ecx
	adcl	$0, %eax
	movl	%eax, 28(%esp)
	fildl	28(%esp)
	fld	%st(0)
	fsqrt
	fucomi	%st(0), %st
	jp	L818
	fstp	%st(1)
L807:
	fdivrs	LC6
	fstps	24(%esp)
	cvttss2si	24(%esp), %ecx
	notl	%ecx
	movl	%ecx, %ebx
	jmp	L804
L818:
	fstp	%st(0)
	fstps	(%esp)
	call	_sqrtf
	jmp	L807
L816:
	fstp	%st(0)
	fstps	(%esp)
	call	_sqrtf
	jmp	L809
	.cfi_endproc
LFE89:
	.section .rdata,"dr"
LC7:
	.ascii "VSAR\12Invalid mask.\0"
	.text
	.p2align 2,,3
	.def	_VSAW;	.scl	3;	.type	32;	.endef
_VSAW:
LFB90:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	xorl	$8, %eax
	cmpl	$1, %eax
	je	L822
	cmpl	$2, %eax
	je	L823
	testl	%eax, %eax
	je	L827
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC7, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	sall	$4, %eax
	pxor	%xmm0, %xmm0
	movdqa	%xmm0, _VR(%eax)
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L827:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movl	_VACC+4, %edx
	movw	%dx, _VR(%eax)
	movl	_VACC+12, %edx
	movw	%dx, _VR+2(%eax)
	movl	_VACC+20, %edx
	movw	%dx, _VR+4(%eax)
	movl	_VACC+28, %edx
	movw	%dx, _VR+6(%eax)
	movl	_VACC+36, %edx
	movw	%dx, _VR+8(%eax)
	movl	_VACC+44, %edx
	movw	%dx, _VR+10(%eax)
	movl	_VACC+52, %edx
	movw	%dx, _VR+12(%eax)
	movl	_VACC+60, %edx
	movw	%dx, _VR+14(%eax)
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L823:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	movl	_VACC+56, %edx
	movw	%dx, _VR+14(%eax)
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L822:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
	movw	_VACC+58, %dx
	movw	%dx, _VR+14(%eax)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE90:
	.section .rdata,"dr"
LC8:
	.ascii "SWV\11$v00[X], 0x000($00)\0"
	.data
LC0:
	.byte	48
	.byte	49
	.byte	50
	.byte	51
	.byte	52
	.byte	53
	.byte	54
	.byte	55
	.byte	56
	.byte	57
	.byte	65
	.byte	66
	.byte	67
	.byte	68
	.byte	69
	.byte	70
	.text
	.p2align 2,,3
	.globl	_SWV
	.def	_SWV;	.scl	2;	.type	32;	.endef
_SWV:
LFB123:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$76, %esp
	.cfi_def_cfa_offset 96
	movl	96(%esp), %ebp
	movl	100(%esp), %ebx
	leal	40(%esp), %edi
	movl	$LC8, %esi
	movl	$6, %ecx
	rep movsl
	leal	24(%esp), %edi
	movl	$LC0, %esi
	movb	$4, %cl
	rep movsl
	movl	$1717986919, %ecx
	movl	%ebp, %eax
	imull	%ecx
	sarl	$2, %edx
	movl	%ebp, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	orl	$48, %eax
	movb	%al, 46(%esp)
	leal	(%edx,%edx,4), %eax
	sall	%eax
	subl	%eax, %ebp
	movl	%ebp, %eax
	orl	$48, %eax
	movb	%al, 47(%esp)
	andl	$15, %ebx
	movb	24(%esp,%ebx), %bl
	movb	%bl, 49(%esp)
	movl	104(%esp), %eax
	sarl	$8, %eax
	andl	$15, %eax
	movb	24(%esp,%eax), %al
	movb	%al, 55(%esp)
	movl	104(%esp), %eax
	sarl	$4, %eax
	andl	$15, %eax
	movb	24(%esp,%eax), %al
	movb	%al, 56(%esp)
	movl	104(%esp), %eax
	andl	$15, %eax
	movb	24(%esp,%eax), %al
	movb	%al, 57(%esp)
	movl	108(%esp), %eax
	imull	%ecx
	sarl	$2, %edx
	movl	108(%esp), %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	orl	$48, %eax
	movb	%al, 60(%esp)
	leal	(%edx,%edx,4), %eax
	sall	%eax
	movl	108(%esp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	orl	$48, %eax
	movb	%al, 61(%esp)
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 80
	subl	$16, %esp
	.cfi_def_cfa_offset 96
	addl	$76, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE123:
	.section .rdata,"dr"
LC9:
	.ascii "SWC2\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_072
	.def	_res_072;	.scl	2;	.type	32;	.endef
_res_072:
LFB125:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE125:
	.section .rdata,"dr"
LC10:
	.ascii "LFV\11$v00[X], 0x000($00)\0"
	.text
	.p2align 2,,3
	.globl	_LFV
	.def	_LFV;	.scl	2;	.type	32;	.endef
_LFV:
LFB110:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$76, %esp
	.cfi_def_cfa_offset 96
	movl	96(%esp), %ebp
	movl	100(%esp), %ebx
	leal	40(%esp), %edi
	movl	$LC10, %esi
	movl	$6, %ecx
	rep movsl
	leal	24(%esp), %edi
	movl	$LC0, %esi
	movb	$4, %cl
	rep movsl
	movl	$1717986919, %ecx
	movl	%ebp, %eax
	imull	%ecx
	sarl	$2, %edx
	movl	%ebp, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	orl	$48, %eax
	movb	%al, 46(%esp)
	leal	(%edx,%edx,4), %eax
	sall	%eax
	subl	%eax, %ebp
	movl	%ebp, %eax
	orl	$48, %eax
	movb	%al, 47(%esp)
	andl	$15, %ebx
	movb	24(%esp,%ebx), %bl
	movb	%bl, 49(%esp)
	movl	104(%esp), %eax
	sarl	$8, %eax
	andl	$15, %eax
	movb	24(%esp,%eax), %al
	movb	%al, 55(%esp)
	movl	104(%esp), %eax
	sarl	$4, %eax
	andl	$15, %eax
	movb	24(%esp,%eax), %al
	movb	%al, 56(%esp)
	movl	104(%esp), %eax
	andl	$15, %eax
	movb	24(%esp,%eax), %al
	movb	%al, 57(%esp)
	movl	108(%esp), %eax
	imull	%ecx
	sarl	$2, %edx
	movl	108(%esp), %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	orl	$48, %eax
	movb	%al, 60(%esp)
	leal	(%edx,%edx,4), %eax
	sall	%eax
	movl	108(%esp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	orl	$48, %eax
	movb	%al, 61(%esp)
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 80
	subl	$16, %esp
	.cfi_def_cfa_offset 96
	addl	$76, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE110:
	.section .rdata,"dr"
LC11:
	.ascii "LWC2\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_062
	.def	_res_062;	.scl	2;	.type	32;	.endef
_res_062:
LFB112:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC11, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE112:
	.section .rdata,"dr"
	.align 4
LC12:
	.ascii "VMACQ\12Unimplemented instruction.\0"
	.text
	.p2align 2,,3
	.def	_VMACQ;	.scl	3;	.type	32;	.endef
_VMACQ:
LFB37:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC12, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE37:
	.section .rdata,"dr"
	.align 4
LC13:
	.ascii "VRSQ\12Unimplemented instruction.\0"
	.text
	.p2align 2,,3
	.def	_VRSQ;	.scl	3;	.type	32;	.endef
_VRSQ:
LFB60:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC13, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	$0, _DPH
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE60:
	.section .rdata,"dr"
	.align 4
LC14:
	.ascii "VRNDP/VRNDN/VMULQ\12MPEG DCT canceled.\0"
	.text
	.p2align 2,,3
	.def	_res_M;	.scl	3;	.type	32;	.endef
_res_M:
LFB94:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC14, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE94:
	.section .rdata,"dr"
LC15:
	.ascii "VU reserved instruction\0"
	.text
	.p2align 2,,3
	.def	_res_V;	.scl	3;	.type	32;	.endef
_res_V:
LFB95:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE95:
	.section .rdata,"dr"
LC16:
	.ascii "COP2\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_022
	.def	_res_022;	.scl	2;	.type	32;	.endef
_res_022:
LFB100:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE100:
	.section .rdata,"dr"
LC17:
	.ascii "SHV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_SHV
	.def	_SHV;	.scl	2;	.type	32;	.endef
_SHV:
LFB121:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %edx
	addl	_SR(,%edx,4), %eax
	movl	36(%esp), %ecx
	testl	%ecx, %ecx
	jne	L847
	testb	$14, %al
	jne	L847
	movl	%eax, %edx
	andl	$4095, %edx
	testb	$1, %al
	je	L852
	leal	-1(%edx), %eax
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	_VR+14(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 12(%ebx,%eax)
	movl	_VR+12(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 14(%ebx,%eax)
	movw	_VR+10(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 8(%ebx,%eax)
	movl	_VR+8(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 10(%ebx,%eax)
	movw	_VR+6(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 4(%ebx,%eax)
	movl	_VR+4(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 6(%ebx,%eax)
	movw	_VR+2(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, (%ebx,%eax)
	movl	_VR(%edx), %edx
	sarw	$7, %dx
	movl	_RSP+12, %ecx
	movb	%dl, 2(%ecx,%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L847:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC17, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L852:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	_VR+14(%eax), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 13(%ebx,%edx)
	movl	_VR+12(%eax), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 15(%ebx,%edx)
	movw	_VR+10(%eax), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 9(%ebx,%edx)
	movl	_VR+8(%eax), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 11(%ebx,%edx)
	movw	_VR+6(%eax), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 5(%ebx,%edx)
	movl	_VR+4(%eax), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 7(%ebx,%edx)
	movw	_VR+2(%eax), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 1(%ebx,%edx)
	movl	_VR(%eax), %eax
	sarw	$7, %ax
	movl	_RSP+12, %ecx
	movb	%al, 3(%ecx,%edx)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE121:
	.section .rdata,"dr"
LC18:
	.ascii "LHV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LHV
	.def	_LHV;	.scl	2;	.type	32;	.endef
_LHV:
LFB109:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %edx
	addl	_SR(,%edx,4), %eax
	movl	36(%esp), %ebx
	testl	%ebx, %ebx
	jne	L854
	testb	$14, %al
	jne	L854
	movl	%eax, %edx
	andl	$4095, %edx
	movl	_RSP+12, %ecx
	testb	$1, %al
	movl	32(%esp), %eax
	je	L859
	sall	$4, %eax
	movzbl	11(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+14(%eax)
	movzbl	13(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%eax)
	movzbl	7(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%eax)
	movzbl	9(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%eax)
	movzbl	3(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%eax)
	movzbl	5(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%eax)
	movzbl	-1(%ecx,%edx), %ebx
	decl	%edx
	sall	$7, %ebx
	movw	%bx, _VR+2(%eax)
	movzbl	2(%ecx,%edx), %edx
	sall	$7, %edx
	movw	%dx, _VR(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L854:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC18, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L859:
	.cfi_restore_state
	sall	$4, %eax
	movzbl	13(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+14(%eax)
	movzbl	15(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%eax)
	movzbl	9(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%eax)
	movzbl	11(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%eax)
	movzbl	5(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%eax)
	movzbl	7(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%eax)
	movzbl	1(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%eax)
	movzbl	3(%ecx,%edx), %edx
	sall	$7, %edx
	movw	%dx, _VR(%eax)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE109:
	.section .rdata,"dr"
LC19:
	.ascii "SFV\12Weird element.\0"
	.text
	.p2align 2,,3
	.globl	_SFV
	.def	_SFV;	.scl	2;	.type	32;	.endef
_SFV:
LFB122:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %ecx
	addl	_SR(,%ecx,4), %eax
	andl	$4083, %eax
	xorl	$3, %eax
	testl	%edx, %edx
	jne	L867
	movl	32(%esp), %edx
	sall	$4, %edx
	movl	_VR(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, (%ebx,%eax)
	movw	_VR+2(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 4(%ebx,%eax)
	movl	_VR+4(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 8(%ebx,%eax)
	movw	_VR+6(%edx), %dx
	sarw	$7, %dx
	movl	_RSP+12, %ecx
	movb	%dl, 12(%ecx,%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L867:
	.cfi_restore_state
	cmpl	$8, %edx
	je	L868
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC19, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L868:
	.cfi_restore_state
	movl	32(%esp), %edx
	sall	$4, %edx
	movl	_VR+8(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, (%ebx,%eax)
	movw	_VR+10(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 4(%ebx,%eax)
	movl	_VR+12(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 8(%ebx,%eax)
	movw	_VR+14(%edx), %dx
	sarw	$7, %dx
	movl	_RSP+12, %ecx
	movb	%dl, 12(%ecx,%eax)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE122:
	.section .rdata,"dr"
LC20:
	.ascii "SLV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_SLV
	.def	_SLV;	.scl	2;	.type	32;	.endef
_SLV:
LFB115:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	72(%esp), %edx
	leal	(%eax,%edx,4), %eax
	movl	%eax, %edx
	andl	$4095, %edx
	testb	$3, 68(%esp)
	jne	L880
	andl	$3, %eax
	decl	%eax
	cmpl	$2, %eax
	ja	L881
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC20, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 48
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L881:
	.cfi_restore_state
	movl	68(%esp), %ecx
	shrl	%ecx
	movl	_RSP+12, %eax
	movl	64(%esp), %ebx
	leal	(%ecx,%ebx,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+2(%ecx,%ecx), %cx
	movw	%cx, (%eax,%edx)
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L880:
	.cfi_restore_state
	movl	68(%esp), %eax
	andl	$1, %eax
	movl	%eax, 28(%esp)
	movl	%eax, %ebx
	xorl	$1, %ebx
	movl	68(%esp), %esi
	shrl	%esi
	leal	0(,%ebx,8), %ecx
	movl	%ecx, 20(%esp)
	movl	%edx, %edi
	xorl	$3, %edi
	movl	64(%esp), %ebp
	sall	$3, %ebp
	leal	0(%ebp,%esi), %eax
	movswl	_VR(%eax,%eax), %eax
	sarl	%cl, %eax
	movl	_RSP+12, %ecx
	movb	%al, (%ecx,%edi)
	incl	%edx
	andl	$4095, %edx
	addl	28(%esp), %esi
	movl	%esi, 24(%esp)
	movl	%edx, %esi
	xorl	$3, %esi
	addl	_RSP+12, %esi
	movl	24(%esp), %eax
	andl	$7, %eax
	addl	%ebp, %eax
	movswl	_VR(%eax,%eax), %edi
	cmpl	$1, %ebx
	sbbl	%eax, %eax
	andl	$8, %eax
	movb	%al, %cl
	sarl	%cl, %edi
	movl	%edi, %ecx
	movb	%cl, (%esi)
	incl	%edx
	andl	$4095, %edx
	movl	24(%esp), %esi
	addl	%ebx, %esi
	movl	%edx, %edi
	xorl	$3, %edi
	movl	%esi, %ecx
	andl	$7, %ecx
	addl	%ebp, %ecx
	movswl	_VR(%ecx,%ecx), %ebx
	movb	20(%esp), %cl
	sarl	%cl, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, (%ecx,%edi)
	incl	%edx
	andl	$4095, %edx
	xorl	$3, %edx
	addl	_RSP+12, %edx
	addl	28(%esp), %esi
	andl	$7, %esi
	addl	%ebp, %esi
	movswl	_VR(%esi,%esi), %ebx
	movb	%al, %cl
	sarl	%cl, %ebx
	movb	%bl, (%edx)
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE115:
	.section .rdata,"dr"
LC21:
	.ascii "SUV\12Weird element.\0"
LC22:
	.ascii "SPV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_SUV
	.def	_SUV;	.scl	2;	.type	32;	.endef
_SUV:
LFB120:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movl	36(%esp), %edx
	testl	%edx, %edx
	jne	L889
	testb	$7, %al
	jne	L887
	andl	$4095, %eax
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	_VR+14(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 4(%ebx,%eax)
	movl	_VR+12(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 5(%ebx,%eax)
	movw	_VR+10(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 6(%ebx,%eax)
	movl	_VR+8(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 7(%ebx,%eax)
	movw	_VR+6(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, (%ebx,%eax)
	movl	_VR+4(%edx), %ecx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 1(%ebx,%eax)
	movw	_VR+2(%edx), %cx
	sarw	$7, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 2(%ebx,%eax)
	movl	_VR(%edx), %edx
	sarw	$7, %dx
	movl	_RSP+12, %ecx
	movb	%dl, 3(%ecx,%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L887:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC22, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L889:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE120:
	.section .rdata,"dr"
LC23:
	.ascii "MFC2\11$zero, vd\0"
	.text
	.p2align 2,,3
	.globl	_MFC2
	.def	_MFC2;	.scl	2;	.type	32;	.endef
_MFC2:
LFB96:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	testl	%eax, %eax
	je	L895
	testb	$1, 40(%esp)
	jne	L896
	movl	40(%esp), %edx
	shrl	%edx
	movl	36(%esp), %ecx
	leal	(%edx,%ecx,8), %edx
	movswl	_VR(%edx,%edx), %edx
	movl	%edx, _SR(,%eax,4)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L895:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC23, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	$0, _SR
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L896:
	.cfi_restore_state
	movl	40(%esp), %ecx
	shrl	%ecx
	leal	1(%ecx), %edx
	andl	$15, %edx
	movl	36(%esp), %ebx
	sall	$3, %ebx
	addl	%ebx, %edx
	movw	_VR(%edx,%edx), %dx
	movzbl	%dh, %edx
	addl	%ebx, %ecx
	movsbl	_VR(%ecx,%ecx), %ecx
	sall	$8, %ecx
	orl	%ecx, %edx
	movl	%edx, _SR(,%eax,4)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE96:
	.section .rdata,"dr"
LC24:
	.ascii "LLV\12Weird element.\0"
LC25:
	.ascii "LLV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LLV
	.def	_LLV;	.scl	2;	.type	32;	.endef
_LLV:
LFB103:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,4), %eax
	testb	$3, 36(%esp)
	jne	L904
	movl	%eax, %edx
	andl	$3, %edx
	decl	%edx
	cmpl	$2, %edx
	ja	L905
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L905:
	.cfi_restore_state
	andl	$4095, %eax
	movl	36(%esp), %edx
	sarl	%edx
	movl	_RSP+12, %ecx
	movl	32(%esp), %ebx
	leal	(%edx,%ebx,8), %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR(%edx,%edx)
	movw	(%ecx,%eax), %ax
	movw	%ax, _VR+2(%edx,%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L904:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC24, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE103:
	.section .rdata,"dr"
LC26:
	.ascii "CTC2\12VCE\0"
	.align 4
LC27:
	.ascii "CTC2\12Invalid vector control register.\0"
	.text
	.p2align 2,,3
	.globl	_CTC2
	.def	_CTC2;	.scl	2;	.type	32;	.endef
_CTC2:
LFB99:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	36(%esp), %eax
	andl	$3, %eax
	cmpl	$2, %eax
	je	L909
	cmpl	$3, %eax
	je	L910
	movl	32(%esp), %edx
	decl	%eax
	movl	_SR(,%edx,4), %eax
	je	L908
	movw	%ax, _VCO
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L908:
	.cfi_restore_state
	movw	%ax, _VCC
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L910:
	.cfi_restore_state
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC27, 4(%esp)
L913:
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %edx
	movl	_SR(,%edx,4), %eax
	movb	%al, _VCE
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L909:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC26, 4(%esp)
	jmp	L913
	.cfi_endproc
LFE99:
	.section .rdata,"dr"
LC28:
	.ascii "MTC2\12Unaligned element.\0"
	.text
	.p2align 2,,3
	.globl	_MTC2
	.def	_MTC2;	.scl	2;	.type	32;	.endef
_MTC2:
LFB98:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	testb	$1, 40(%esp)
	jne	L918
	movl	40(%esp), %eax
	shrl	%eax
	movl	36(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movl	32(%esp), %edx
	movl	_SR(,%edx,4), %edx
	movw	%dx, _VR(%eax,%eax)
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L918:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC28, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE98:
	.section .rdata,"dr"
LC29:
	.ascii "LUV\12Weird element.\0"
LC30:
	.ascii "LUV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LUV
	.def	_LUV;	.scl	2;	.type	32;	.endef
_LUV:
LFB108:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %edx
	movl	36(%esp), %ecx
	testl	%ecx, %ecx
	jne	L926
	testb	$7, %dl
	jne	L924
	andl	$4095, %edx
	movl	_RSP+12, %ecx
	movl	32(%esp), %eax
	sall	$4, %eax
	movzbl	4(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+14(%eax)
	movzbl	5(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%eax)
	movzbl	6(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%eax)
	movzbl	7(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%eax)
	movzbl	(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%eax)
	movzbl	1(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%eax)
	movzbl	2(%ecx,%edx), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%eax)
	movzbl	3(%ecx,%edx), %edx
	sall	$7, %edx
	movw	%dx, _VR(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L924:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC30, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L926:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC29, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE108:
	.section .rdata,"dr"
LC31:
	.ascii "LPV\12Illegal element.\0"
LC32:
	.ascii "LPV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LPV
	.def	_LPV;	.scl	2;	.type	32;	.endef
_LPV:
LFB107:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %edx
	movl	%edx, %eax
	andl	$4095, %eax
	movl	36(%esp), %ebx
	testl	%ebx, %ebx
	jne	L935
	andl	$7, %edx
	je	L931
	cmpl	$4, %edx
	je	L936
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC32, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L931:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	3(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	7(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	6(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+10(%edx)
	movzbl	5(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+12(%edx)
	movzbl	4(%ecx,%eax), %eax
	sall	$8, %eax
	movw	%ax, _VR+14(%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L936:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	3(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+6(%edx)
	addl	$4, %eax
	andl	$4095, %eax
	movzbl	3(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+10(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$8, %ebx
	movw	%bx, _VR+12(%edx)
	movzbl	(%ecx,%eax), %eax
	sall	$8, %eax
	movw	%ax, _VR+14(%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L935:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC31, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE107:
	.section .rdata,"dr"
LC33:
	.ascii "LDV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_LDV
	.def	_LDV;	.scl	2;	.type	32;	.endef
_LDV:
LFB104:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	76(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	72(%esp), %edx
	leal	(%eax,%edx,8), %ecx
	movl	%ecx, %eax
	andl	$4095, %eax
	testb	$7, 68(%esp)
	jne	L950
	movl	68(%esp), %edx
	shrl	%edx
	andl	$7, %ecx
	jmp	*L948(,%ecx,4)
	.section .rdata,"dr"
	.align 4
L948:
	.long	L940
	.long	L941
	.long	L942
	.long	L943
	.long	L944
	.long	L945
	.long	L946
	.long	L947
	.text
	.p2align 2,,3
L950:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC33, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 48
	subl	$16, %esp
	.cfi_def_cfa_offset 64
L937:
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L946:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movw	-2(%ecx,%eax), %bx
	movl	64(%esp), %esi
	leal	(%edx,%esi,8), %edx
	movw	%bx, _VR(%edx,%edx)
	addl	$2, %eax
	andl	$4095, %eax
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+2(%edx,%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+4(%edx,%edx)
	movw	6(%ecx,%eax), %ax
	movw	%ax, _VR+6(%edx,%edx)
	jmp	L937
	.p2align 2,,3
L947:
	movl	_RSP+12, %ecx
	movzbl	-3(%ecx,%eax), %esi
	sall	$8, %esi
	movl	64(%esp), %edi
	sall	$3, %edi
	leal	(%edi,%edx), %ebx
	movw	%si, _VR(%ebx,%ebx)
	addl	$4, %eax
	andl	$4095, %eax
	movzbl	(%ecx,%eax), %ebp
	orl	%esi, %ebp
	movw	%bp, _VR(%ebx,%ebx)
	movw	-2(%ecx,%eax), %si
	movw	%si, _VR+2(%ebx,%ebx)
	movzbl	-3(%ecx,%eax), %esi
	sall	$8, %esi
	leal	2(%edx,%edi), %edi
	movw	%si, _VR(%edi,%edi)
	movzbl	4(%ecx,%eax), %edx
	orl	%esi, %edx
	movw	%dx, _VR(%edi,%edi)
	movw	2(%ecx,%eax), %ax
	movw	%ax, _VR+6(%ebx,%ebx)
	jmp	L937
	.p2align 2,,3
L940:
	movl	_RSP+12, %ecx
	movw	2(%ecx,%eax), %bx
	movl	64(%esp), %esi
	leal	(%edx,%esi,8), %edx
	movw	%bx, _VR(%edx,%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+2(%edx,%edx)
	movw	6(%ecx,%eax), %bx
	movw	%bx, _VR+4(%edx,%edx)
	movw	4(%ecx,%eax), %ax
	movw	%ax, _VR+6(%edx,%edx)
	jmp	L937
	.p2align 2,,3
L941:
	movl	_RSP+12, %ecx
	movw	(%ecx,%eax), %bx
	movl	64(%esp), %esi
	sall	$3, %esi
	leal	(%esi,%edx), %edi
	movl	%edi, 28(%esp)
	movw	%bx, _VR(%edi,%edi)
	movzbl	-1(%ecx,%eax), %ebx
	sall	$8, %ebx
	leal	1(%edx,%esi), %ebp
	movw	%bx, _VR(%ebp,%ebp)
	movzbl	6(%ecx,%eax), %edi
	orl	%ebx, %edi
	movw	%di, _VR(%ebp,%ebp)
	movw	4(%ecx,%eax), %bx
	movl	28(%esp), %edi
	movw	%bx, _VR+4(%edi,%edi)
	movzbl	3(%ecx,%eax), %ebx
	sall	$8, %ebx
	leal	3(%edx,%esi), %edx
	movw	%bx, _VR(%edx,%edx)
	addl	$10, %eax
	andl	$4095, %eax
	movzbl	(%ecx,%eax), %eax
	orl	%ebx, %eax
	movw	%ax, _VR(%edx,%edx)
	jmp	L937
	.p2align 2,,3
L942:
	movl	_RSP+12, %ecx
	movw	-2(%ecx,%eax), %bx
	movl	64(%esp), %esi
	leal	(%edx,%esi,8), %edx
	movw	%bx, _VR(%edx,%edx)
	movw	4(%ecx,%eax), %bx
	movw	%bx, _VR+2(%edx,%edx)
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+4(%edx,%edx)
	addl	$8, %eax
	andl	$4095, %eax
	movw	(%ecx,%eax), %ax
	movw	%ax, _VR+6(%edx,%edx)
	jmp	L937
	.p2align 2,,3
L943:
	movl	_RSP+12, %ecx
	movzbl	-3(%ecx,%eax), %esi
	sall	$8, %esi
	movl	64(%esp), %edi
	sall	$3, %edi
	leal	(%edi,%edx), %ebx
	movw	%si, _VR(%ebx,%ebx)
	movzbl	4(%ecx,%eax), %ebp
	orl	%esi, %ebp
	movw	%bp, _VR(%ebx,%ebx)
	movw	2(%ecx,%eax), %si
	movw	%si, _VR+2(%ebx,%ebx)
	movzbl	1(%ecx,%eax), %esi
	sall	$8, %esi
	leal	2(%edx,%edi), %edi
	movw	%si, _VR(%edi,%edi)
	addl	$8, %eax
	andl	$4095, %eax
	movzbl	(%ecx,%eax), %edx
	orl	%esi, %edx
	movw	%dx, _VR(%edi,%edi)
	movw	-2(%ecx,%eax), %ax
	movw	%ax, _VR+6(%ebx,%ebx)
	jmp	L937
	.p2align 2,,3
L944:
	movl	_RSP+12, %ecx
	movw	2(%ecx,%eax), %bx
	movl	64(%esp), %edi
	leal	(%edx,%edi,8), %edx
	movw	%bx, _VR(%edx,%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+2(%edx,%edx)
	addl	$4, %eax
	andl	$4095, %eax
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+4(%edx,%edx)
	movw	(%ecx,%eax), %ax
	movw	%ax, _VR+6(%edx,%edx)
	jmp	L937
	.p2align 2,,3
L945:
	movl	_RSP+12, %ecx
	movw	(%ecx,%eax), %bx
	movl	64(%esp), %esi
	sall	$3, %esi
	leal	(%esi,%edx), %edi
	movl	%edi, 28(%esp)
	movw	%bx, _VR(%edi,%edi)
	movzbl	-1(%ecx,%eax), %ebx
	sall	$8, %ebx
	leal	1(%edx,%esi), %edi
	movw	%bx, _VR(%edi,%edi)
	addl	$6, %eax
	andl	$4095, %eax
	movzbl	(%ecx,%eax), %ebp
	orl	%ebx, %ebp
	movw	%bp, _VR(%edi,%edi)
	movw	-2(%ecx,%eax), %bx
	movl	28(%esp), %edi
	movw	%bx, _VR+4(%edi,%edi)
	movzbl	-3(%ecx,%eax), %ebx
	sall	$8, %ebx
	leal	3(%edx,%esi), %edx
	movw	%bx, _VR(%edx,%edx)
	movzbl	4(%ecx,%eax), %eax
	orl	%ebx, %eax
	movw	%ax, _VR(%edx,%edx)
	jmp	L937
	.cfi_endproc
LFE104:
	.section .rdata,"dr"
LC34:
	.ascii "LQV\12Illegal element.\0"
LC35:
	.ascii "LQV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LQV
	.def	_LQV;	.scl	2;	.type	32;	.endef
_LQV:
LFB105:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %edx
	addl	_SR(,%edx,4), %eax
	movl	%eax, %edx
	andl	$4095, %edx
	movl	36(%esp), %ecx
	testl	%ecx, %ecx
	jne	L962
	andl	$15, %eax
	cmpl	$8, %eax
	jbe	L963
L954:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC35, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L963:
	.cfi_restore_state
	jmp	*L960(,%eax,4)
	.section .rdata,"dr"
	.align 4
L960:
	.long	L955
	.long	L954
	.long	L956
	.long	L954
	.long	L957
	.long	L954
	.long	L958
	.long	L954
	.long	L959
	.text
	.p2align 2,,3
L962:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC34, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L959:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	2(%ecx,%edx), %bx
	movw	%bx, _VR(%eax)
	movw	(%ecx,%edx), %bx
	movw	%bx, _VR+2(%eax)
	movw	6(%ecx,%edx), %bx
	movw	%bx, _VR+4(%eax)
	movw	4(%ecx,%edx), %dx
	movw	%dx, _VR+6(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L958:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	-2(%ecx,%edx), %bx
	movw	%bx, _VR(%eax)
	movw	4(%ecx,%edx), %bx
	movw	%bx, _VR+2(%eax)
	movw	2(%ecx,%edx), %bx
	movw	%bx, _VR+4(%eax)
	movw	8(%ecx,%edx), %bx
	movw	%bx, _VR+6(%eax)
	movw	6(%ecx,%edx), %dx
	movw	%dx, _VR+8(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L957:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	2(%ecx,%edx), %bx
	movw	%bx, _VR(%eax)
	movw	(%ecx,%edx), %bx
	movw	%bx, _VR+2(%eax)
	movw	6(%ecx,%edx), %bx
	movw	%bx, _VR+4(%eax)
	movw	4(%ecx,%edx), %bx
	movw	%bx, _VR+6(%eax)
	movw	10(%ecx,%edx), %bx
	movw	%bx, _VR+8(%eax)
	movw	8(%ecx,%edx), %dx
	movw	%dx, _VR+10(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L956:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	-2(%ecx,%edx), %bx
	movw	%bx, _VR(%eax)
	movw	4(%ecx,%edx), %bx
	movw	%bx, _VR+2(%eax)
	movw	2(%ecx,%edx), %bx
	movw	%bx, _VR+4(%eax)
	movw	8(%ecx,%edx), %bx
	movw	%bx, _VR+6(%eax)
	movw	6(%ecx,%edx), %bx
	movw	%bx, _VR+8(%eax)
	movw	12(%ecx,%edx), %bx
	movw	%bx, _VR+10(%eax)
	movw	10(%ecx,%edx), %dx
	movw	%dx, _VR+12(%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L955:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	2(%ecx,%edx), %bx
	movw	%bx, _VR(%eax)
	movw	(%ecx,%edx), %bx
	movw	%bx, _VR+2(%eax)
	movw	6(%ecx,%edx), %bx
	movw	%bx, _VR+4(%eax)
	movw	4(%ecx,%edx), %bx
	movw	%bx, _VR+6(%eax)
	movw	10(%ecx,%edx), %bx
	movw	%bx, _VR+8(%eax)
	movw	8(%ecx,%edx), %bx
	movw	%bx, _VR+10(%eax)
	movw	14(%ecx,%edx), %bx
	movw	%bx, _VR+12(%eax)
	movw	12(%ecx,%edx), %dx
	movw	%dx, _VR+14(%eax)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE105:
	.section .rdata,"dr"
LC36:
	.ascii "LSV\12Odd element.\0"
LC37:
	.ascii "LSV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LSV
	.def	_LSV;	.scl	2;	.type	32;	.endef
_LSV:
LFB102:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,2), %eax
	movl	%eax, %edx
	andl	$4095, %edx
	testb	$1, 36(%esp)
	jne	L972
	movl	36(%esp), %ecx
	sarl	%ecx
	andl	$3, %eax
	cmpl	$2, %eax
	je	L969
	cmpl	$3, %eax
	je	L970
	decl	%eax
	movl	_RSP+12, %eax
	je	L968
	movw	2(%eax,%edx), %dx
	movl	32(%esp), %ebx
	leal	(%ecx,%ebx,8), %eax
	movw	%dx, _VR(%eax,%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L972:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC36, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L970:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC37, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L968:
	.cfi_restore_state
	movw	(%eax,%edx), %dx
	movl	32(%esp), %ebx
	leal	(%ecx,%ebx,8), %eax
	movw	%dx, _VR(%eax,%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L969:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movw	-2(%eax,%edx), %dx
	movl	32(%esp), %ebx
	leal	(%ecx,%ebx,8), %eax
	movw	%dx, _VR(%eax,%eax)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE102:
	.section .rdata,"dr"
LC38:
	.ascii "SPV\12Weird element.\0"
	.text
	.p2align 2,,3
	.globl	_SPV
	.def	_SPV;	.scl	2;	.type	32;	.endef
_SPV:
LFB119:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movl	36(%esp), %ebx
	testl	%ebx, %ebx
	jne	L980
	testb	$7, %al
	jne	L978
	andl	$4095, %eax
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	_VR+14(%edx), %cx
	sarw	$8, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 4(%ebx,%eax)
	movl	_VR+12(%edx), %ecx
	sarw	$8, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 5(%ebx,%eax)
	movw	_VR+10(%edx), %cx
	sarw	$8, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 6(%ebx,%eax)
	movl	_VR+8(%edx), %ecx
	sarw	$8, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 7(%ebx,%eax)
	movw	_VR+6(%edx), %cx
	sarw	$8, %cx
	movl	_RSP+12, %ebx
	movb	%cl, (%ebx,%eax)
	movl	_VR+4(%edx), %ecx
	sarw	$8, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 1(%ebx,%eax)
	movw	_VR+2(%edx), %cx
	sarw	$8, %cx
	movl	_RSP+12, %ebx
	movb	%cl, 2(%ebx,%eax)
	movl	_VR(%edx), %edx
	sarw	$8, %dx
	movl	_RSP+12, %ecx
	movb	%dl, 3(%ecx,%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L978:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC22, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L980:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC38, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE119:
	.section .rdata,"dr"
LC39:
	.ascii "LRV\12Weird element.\0"
LC40:
	.ascii "LRV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LRV
	.def	_LRV;	.scl	2;	.type	32;	.endef
_LRV:
LFB106:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %edx
	addl	_SR(,%edx,4), %eax
	movl	%eax, %edx
	andl	$15, %edx
	andl	$4080, %eax
	movl	36(%esp), %ecx
	testl	%ecx, %ecx
	jne	L994
	cmpl	$14, %edx
	jbe	L995
L984:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC40, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	.p2align 2,,3
L981:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L995:
	.cfi_restore_state
	jmp	*L992(,%edx,4)
	.section .rdata,"dr"
	.align 4
L992:
	.long	L981
	.long	L984
	.long	L985
	.long	L984
	.long	L986
	.long	L984
	.long	L987
	.long	L984
	.long	L988
	.long	L984
	.long	L989
	.long	L984
	.long	L990
	.long	L984
	.long	L991
	.text
	.p2align 2,,3
L994:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC39, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L991:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+2(%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+4(%edx)
	movw	6(%ecx,%eax), %bx
	movw	%bx, _VR+6(%edx)
	movw	4(%ecx,%eax), %bx
	movw	%bx, _VR+8(%edx)
	movw	10(%ecx,%eax), %bx
	movw	%bx, _VR+10(%edx)
	movw	8(%ecx,%eax), %bx
	movw	%bx, _VR+12(%edx)
	movw	14(%ecx,%eax), %ax
	movw	%ax, _VR+14(%edx)
	jmp	L981
	.p2align 2,,3
L990:
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+4(%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+6(%edx)
	movw	6(%ecx,%eax), %bx
	movw	%bx, _VR+8(%edx)
	movw	4(%ecx,%eax), %bx
	movw	%bx, _VR+10(%edx)
	movw	10(%ecx,%eax), %bx
	movw	%bx, _VR+12(%edx)
	movw	8(%ecx,%eax), %ax
	movw	%ax, _VR+14(%edx)
	jmp	L981
	.p2align 2,,3
L989:
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+6(%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+8(%edx)
	movw	6(%ecx,%eax), %bx
	movw	%bx, _VR+10(%edx)
	movw	4(%ecx,%eax), %bx
	movw	%bx, _VR+12(%edx)
	movw	10(%ecx,%eax), %ax
	movw	%ax, _VR+14(%edx)
	jmp	L981
	.p2align 2,,3
L988:
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+8(%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+10(%edx)
	movw	6(%ecx,%eax), %bx
	movw	%bx, _VR+12(%edx)
	movw	4(%ecx,%eax), %ax
	movw	%ax, _VR+14(%edx)
	jmp	L981
	.p2align 2,,3
L987:
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+10(%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+12(%edx)
	movw	6(%ecx,%eax), %ax
	movw	%ax, _VR+14(%edx)
	jmp	L981
	.p2align 2,,3
L986:
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+12(%edx)
	movw	(%ecx,%eax), %ax
	movw	%ax, _VR+14(%edx)
	jmp	L981
	.p2align 2,,3
L985:
	movl	_RSP+12, %edx
	movw	2(%edx,%eax), %dx
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	%dx, _VR+14(%eax)
	jmp	L981
	.cfi_endproc
LFE106:
	.section .rdata,"dr"
LC41:
	.ascii "SRV\12Nonzero element.\0"
LC42:
	.ascii "SRV\12Unaligned addr.\0"
	.text
	.p2align 2,,3
	.globl	_SRV
	.def	_SRV;	.scl	2;	.type	32;	.endef
_SRV:
LFB118:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %edx
	addl	_SR(,%edx,4), %eax
	movl	%eax, %edx
	andl	$15, %edx
	andl	$4080, %eax
	movl	36(%esp), %ebx
	testl	%ebx, %ebx
	jne	L1009
	cmpl	$14, %edx
	jbe	L1010
L999:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	.p2align 2,,3
L996:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1010:
	.cfi_restore_state
	jmp	*L1007(,%edx,4)
	.section .rdata,"dr"
	.align 4
L1007:
	.long	L996
	.long	L999
	.long	L1000
	.long	L999
	.long	L1001
	.long	L999
	.long	L1002
	.long	L999
	.long	L1003
	.long	L999
	.long	L1004
	.long	L999
	.long	L1005
	.long	L999
	.long	L1006
	.text
	.p2align 2,,3
L1009:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC41, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1006:
	.cfi_restore_state
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movw	_VR+2(%ecx), %bx
	movw	%bx, 2(%edx,%eax)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, (%edx,%eax)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 6(%edx,%eax)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 4(%edx,%eax)
	movw	_VR+10(%ecx), %bx
	movw	%bx, 10(%edx,%eax)
	movl	_VR+12(%ecx), %ebx
	movw	%bx, 8(%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, 14(%edx,%eax)
	jmp	L996
	.p2align 2,,3
L1005:
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 2(%edx,%eax)
	movw	_VR+6(%ecx), %bx
	movw	%bx, (%edx,%eax)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 6(%edx,%eax)
	movw	_VR+10(%ecx), %bx
	movw	%bx, 4(%edx,%eax)
	movl	_VR+12(%ecx), %ebx
	movw	%bx, 10(%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, 8(%edx,%eax)
	jmp	L996
	.p2align 2,,3
L1004:
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movw	_VR+6(%ecx), %bx
	movw	%bx, 2(%edx,%eax)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, (%edx,%eax)
	movw	_VR+10(%ecx), %bx
	movw	%bx, 6(%edx,%eax)
	movl	_VR+12(%ecx), %ebx
	movw	%bx, 4(%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, 10(%edx,%eax)
	jmp	L996
	.p2align 2,,3
L1003:
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 2(%edx,%eax)
	movw	_VR+10(%ecx), %bx
	movw	%bx, (%edx,%eax)
	movl	_VR+12(%ecx), %ebx
	movw	%bx, 6(%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, 4(%edx,%eax)
	jmp	L996
	.p2align 2,,3
L1002:
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movw	_VR+10(%ecx), %bx
	movw	%bx, 2(%edx,%eax)
	movl	_VR+12(%ecx), %ebx
	movw	%bx, (%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, 6(%edx,%eax)
	jmp	L996
	.p2align 2,,3
L1001:
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR+12(%ecx), %ebx
	movw	%bx, 2(%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, (%edx,%eax)
	jmp	L996
	.p2align 2,,3
L1000:
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	_VR+14(%edx), %cx
	movl	_RSP+12, %edx
	movw	%cx, 2(%edx,%eax)
	jmp	L996
	.cfi_endproc
LFE118:
	.section .rdata,"dr"
LC43:
	.ascii "SDV\12Illegal element.\0"
LC44:
	.ascii "SDV\12addr2..0 = 1\0"
LC45:
	.ascii "SDV\12addr2..0 = 3\0"
LC46:
	.ascii "SDV\12addr2..0 = 5\0"
LC47:
	.ascii "SDV\12addr2..0 = 7\0"
	.text
	.p2align 2,,3
	.globl	_SDV
	.def	_SDV;	.scl	2;	.type	32;	.endef
_SDV:
LFB116:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movl	%eax, %edx
	andl	$4095, %edx
	testb	$7, 36(%esp)
	jne	L1024
	movl	36(%esp), %ecx
	shrl	%ecx
	andl	$7, %eax
	jmp	*L1022(,%eax,4)
	.section .rdata,"dr"
	.align 4
L1022:
	.long	L1014
	.long	L1015
	.long	L1016
	.long	L1017
	.long	L1018
	.long	L1019
	.long	L1020
	.long	L1021
	.text
	.p2align 2,,3
L1024:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC43, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
L1011:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1020:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	32(%esp), %ebx
	leal	(%ecx,%ebx,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movw	%bx, -2(%eax,%edx)
	addl	$2, %edx
	andl	$4095, %edx
	movw	_VR+2(%ecx,%ecx), %bx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+4(%ecx,%ecx), %bx
	movw	%bx, (%eax,%edx)
	movw	_VR+6(%ecx,%ecx), %cx
	movw	%cx, 6(%eax,%edx)
	jmp	L1011
	.p2align 2,,3
L1021:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC47, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1011
	.p2align 2,,3
L1014:
	movl	_RSP+12, %eax
	movl	32(%esp), %ebx
	leal	(%ecx,%ebx,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+2(%ecx,%ecx), %bx
	movw	%bx, (%eax,%edx)
	movw	_VR+4(%ecx,%ecx), %bx
	movw	%bx, 6(%eax,%edx)
	movw	_VR+6(%ecx,%ecx), %cx
	movw	%cx, 4(%eax,%edx)
	jmp	L1011
	.p2align 2,,3
L1015:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1011
	.p2align 2,,3
L1016:
	movl	_RSP+12, %eax
	movl	32(%esp), %ebx
	leal	(%ecx,%ebx,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movw	%bx, -2(%eax,%edx)
	movw	_VR+2(%ecx,%ecx), %bx
	movw	%bx, 4(%eax,%edx)
	movw	_VR+4(%ecx,%ecx), %bx
	movw	%bx, 2(%eax,%edx)
	addl	$8, %edx
	movw	_VR+6(%ecx,%ecx), %cx
	andl	$4095, %edx
	movw	%cx, (%eax,%edx)
	jmp	L1011
	.p2align 2,,3
L1017:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC45, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1011
	.p2align 2,,3
L1018:
	movl	_RSP+12, %eax
	movl	32(%esp), %ebx
	leal	(%ecx,%ebx,8), %ecx
	movw	_VR(%ecx,%ecx), %bx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+2(%ecx,%ecx), %bx
	movw	%bx, (%eax,%edx)
	addl	$4, %edx
	andl	$4095, %edx
	movw	_VR+4(%ecx,%ecx), %bx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+6(%ecx,%ecx), %cx
	movw	%cx, (%eax,%edx)
	jmp	L1011
	.p2align 2,,3
L1019:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC46, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1011
	.cfi_endproc
LFE116:
	.section .rdata,"dr"
	.align 4
LC48:
	.ascii "STV\12Crossed quadword index barrier.\0"
	.align 4
LC49:
	.ascii "STV\12Crossed memory dest DW allocation barrier.\0"
LC50:
	.ascii "STV\12Odd element.\0"
	.text
	.p2align 2,,3
	.globl	_STV
	.def	_STV;	.scl	2;	.type	32;	.endef
_STV:
LFB124:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	40(%esp), %esi
	sall	$4, %esi
	movl	44(%esp), %eax
	addl	_SR(,%eax,4), %esi
	testl	$15, %esi
	jne	L1043
	andl	$4080, %esi
	testb	$7, %bl
	jne	L1044
L1028:
	cmpl	$14, 36(%esp)
	jbe	L1045
L1029:
	movl	36(%esp), %edi
	shrl	$31, %edi
	addl	36(%esp), %edi
	sarl	%edi
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC50, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+12, %eax
	movl	%edi, %edx
	andl	$7, %edx
	orl	%ebx, %edx
	sall	$4, %edx
	movl	_VR(%edx), %ecx
	movl	%esi, %edx
	xorl	$2, %edx
	movw	%cx, (%eax,%edx)
	leal	1(%edi), %edx
	andl	$7, %edx
	orl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+2(%edx), %cx
	leal	2(%esi), %edx
	xorl	$2, %edx
	movw	%cx, (%eax,%edx)
	leal	2(%edi), %edx
	andl	$7, %edx
	orl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+4(%edx), %ecx
	leal	4(%esi), %edx
	xorl	$2, %edx
	movw	%cx, (%eax,%edx)
	leal	3(%edi), %edx
	andl	$7, %edx
	orl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+6(%edx), %cx
	leal	6(%esi), %edx
	xorl	$2, %edx
	movw	%cx, (%eax,%edx)
	leal	4(%edi), %edx
	andl	$7, %edx
	orl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+8(%edx), %ecx
	leal	8(%esi), %edx
	xorl	$2, %edx
	movw	%cx, (%eax,%edx)
	leal	5(%edi), %edx
	andl	$7, %edx
	orl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+10(%edx), %cx
	leal	10(%esi), %edx
	xorl	$2, %edx
	movw	%cx, (%eax,%edx)
	leal	6(%edi), %edx
	andl	$7, %edx
	orl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+12(%edx), %ecx
	leal	12(%esi), %edx
	xorl	$2, %edx
	movw	%cx, (%eax,%edx)
	addl	$7, %edi
	andl	$7, %edi
	orl	%ebx, %edi
	sall	$4, %edi
	movw	_VR+14(%edi), %dx
	addl	$14, %esi
	xorl	$2, %esi
	movw	%dx, (%eax,%esi)
	jmp	L1025
	.p2align 2,,3
L1045:
	movl	36(%esp), %eax
	jmp	*L1038(,%eax,4)
	.section .rdata,"dr"
	.align 4
L1038:
	.long	L1030
	.long	L1029
	.long	L1031
	.long	L1029
	.long	L1032
	.long	L1029
	.long	L1033
	.long	L1029
	.long	L1034
	.long	L1029
	.long	L1035
	.long	L1029
	.long	L1036
	.long	L1029
	.long	L1037
	.text
	.p2align 2,,3
L1044:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	andl	$-8, %ebx
	jmp	L1028
	.p2align 2,,3
L1043:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC48, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
L1025:
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1037:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+112(%edx), %edx
	movw	%dx, 2(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+2(%edx), %dx
	movw	%dx, (%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+20(%edx), %edx
	movw	%dx, 6(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+38(%edx), %dx
	movw	%dx, 4(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+56(%edx), %edx
	movw	%dx, 10(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+74(%edx), %dx
	movw	%dx, 8(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+92(%edx), %edx
	movw	%dx, 14(%eax,%esi)
	sall	$4, %ebx
	movw	_VR+110(%ebx), %dx
	movw	%dx, 12(%eax,%esi)
	jmp	L1025
	.p2align 2,,3
L1036:
	movl	_RSP+12, %eax
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+96(%edx), %edx
	movw	%dx, 2(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+114(%edx), %dx
	movw	%dx, (%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+4(%edx), %edx
	movw	%dx, 6(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+22(%edx), %dx
	movw	%dx, 4(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+40(%edx), %edx
	movw	%dx, 10(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+58(%edx), %dx
	movw	%dx, 8(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+76(%edx), %edx
	movw	%dx, 14(%eax,%esi)
	sall	$4, %ebx
	movw	_VR+94(%ebx), %dx
	movw	%dx, 12(%eax,%esi)
	jmp	L1025
	.p2align 2,,3
L1035:
	movl	_RSP+12, %eax
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+80(%edx), %edx
	movw	%dx, 2(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+98(%edx), %dx
	movw	%dx, (%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+116(%edx), %edx
	movw	%dx, 6(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+6(%edx), %dx
	movw	%dx, 4(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+24(%edx), %edx
	movw	%dx, 10(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+42(%edx), %dx
	movw	%dx, 8(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+60(%edx), %edx
	movw	%dx, 14(%eax,%esi)
	sall	$4, %ebx
	movw	_VR+78(%ebx), %dx
	movw	%dx, 12(%eax,%esi)
	jmp	L1025
	.p2align 2,,3
L1034:
	movl	_RSP+12, %eax
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+64(%edx), %edx
	movw	%dx, 2(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+82(%edx), %dx
	movw	%dx, (%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+100(%edx), %edx
	movw	%dx, 6(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+118(%edx), %dx
	movw	%dx, 4(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+8(%edx), %edx
	movw	%dx, 10(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+26(%edx), %dx
	movw	%dx, 8(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+44(%edx), %edx
	movw	%dx, 14(%eax,%esi)
	sall	$4, %ebx
	movw	_VR+62(%ebx), %dx
	movw	%dx, 12(%eax,%esi)
	jmp	L1025
	.p2align 2,,3
L1033:
	movl	_RSP+12, %eax
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+48(%edx), %edx
	movw	%dx, 2(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+66(%edx), %dx
	movw	%dx, (%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+84(%edx), %edx
	movw	%dx, 6(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+102(%edx), %dx
	movw	%dx, 4(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+120(%edx), %edx
	movw	%dx, 10(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+10(%edx), %dx
	movw	%dx, 8(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+28(%edx), %edx
	movw	%dx, 14(%eax,%esi)
	sall	$4, %ebx
	movw	_VR+46(%ebx), %dx
	movw	%dx, 12(%eax,%esi)
	jmp	L1025
	.p2align 2,,3
L1032:
	movl	_RSP+12, %eax
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+32(%edx), %edx
	movw	%dx, 2(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+50(%edx), %dx
	movw	%dx, (%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+68(%edx), %edx
	movw	%dx, 6(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+86(%edx), %dx
	movw	%dx, 4(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+104(%edx), %edx
	movw	%dx, 10(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+122(%edx), %dx
	movw	%dx, 8(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+12(%edx), %edx
	movw	%dx, 14(%eax,%esi)
	sall	$4, %ebx
	movw	_VR+30(%ebx), %dx
	movw	%dx, 12(%eax,%esi)
	jmp	L1025
	.p2align 2,,3
L1031:
	movl	_RSP+12, %eax
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+16(%edx), %edx
	movw	%dx, 2(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+34(%edx), %dx
	movw	%dx, (%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+52(%edx), %edx
	movw	%dx, 6(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+70(%edx), %dx
	movw	%dx, 4(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+88(%edx), %edx
	movw	%dx, 10(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+106(%edx), %dx
	movw	%dx, 8(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+124(%edx), %edx
	movw	%dx, 14(%eax,%esi)
	sall	$4, %ebx
	movw	_VR+14(%ebx), %dx
	movw	%dx, 12(%eax,%esi)
	jmp	L1025
	.p2align 2,,3
L1030:
	movl	_RSP+12, %eax
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR(%edx), %edx
	movw	%dx, 2(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+18(%edx), %dx
	movw	%dx, (%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+36(%edx), %edx
	movw	%dx, 6(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+54(%edx), %dx
	movw	%dx, 4(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+72(%edx), %edx
	movw	%dx, 10(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movw	_VR+90(%edx), %dx
	movw	%dx, 8(%eax,%esi)
	movl	%ebx, %edx
	sall	$4, %edx
	movl	_VR+108(%edx), %edx
	movw	%dx, 14(%eax,%esi)
	sall	$4, %ebx
	movw	_VR+126(%ebx), %dx
	movw	%dx, 12(%eax,%esi)
	jmp	L1025
	.cfi_endproc
LFE124:
	.section .rdata,"dr"
	.align 4
LC51:
	.ascii "LTV\12Crossed quadword allocation barrier.\0"
	.align 4
LC52:
	.ascii "LTV\12Weird vector target register.\0"
LC53:
	.ascii "LTV\12Odd element.\0"
	.text
	.p2align 2,,3
	.globl	_LTV
	.def	_LTV;	.scl	2;	.type	32;	.endef
_LTV:
LFB111:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	40(%esp), %esi
	sall	$4, %esi
	movl	44(%esp), %eax
	addl	_SR(,%eax,4), %esi
	testl	$15, %esi
	jne	L1062
	andl	$4080, %esi
	testb	$7, %bl
	jne	L1063
L1049:
	cmpl	$14, 36(%esp)
	jbe	L1064
L1051:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC53, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1046
	.p2align 2,,3
L1064:
	movl	36(%esp), %eax
	jmp	*L1060(,%eax,4)
	.section .rdata,"dr"
	.align 4
L1060:
	.long	L1052
	.long	L1051
	.long	L1053
	.long	L1051
	.long	L1054
	.long	L1051
	.long	L1055
	.long	L1051
	.long	L1056
	.long	L1051
	.long	L1057
	.long	L1051
	.long	L1058
	.long	L1051
	.long	L1059
	.text
	.p2align 2,,3
L1062:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	andl	$4088, %esi
	addl	$8, %esi
	andl	$4080, %esi
	testb	$7, %bl
	je	L1049
L1063:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC52, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
L1046:
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1059:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movw	2(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+2(%edx)
	movw	(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+20(%edx)
	movw	6(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+38(%edx)
	movw	4(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+56(%edx)
	movw	10(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+74(%edx)
	movw	8(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+92(%edx)
	movw	14(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+110(%edx)
	movw	12(%eax,%esi), %ax
	movw	%ax, _VR+112(%edx)
	jmp	L1046
	.p2align 2,,3
L1058:
	movl	_RSP+12, %eax
	movw	2(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+4(%edx)
	movw	(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+22(%edx)
	movw	6(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+40(%edx)
	movw	4(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+58(%edx)
	movw	10(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+76(%edx)
	movw	8(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+94(%edx)
	movw	14(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+96(%edx)
	movw	12(%eax,%esi), %ax
	movw	%ax, _VR+114(%edx)
	jmp	L1046
	.p2align 2,,3
L1057:
	movl	_RSP+12, %eax
	movw	2(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+6(%edx)
	movw	(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+24(%edx)
	movw	6(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+42(%edx)
	movw	4(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+60(%edx)
	movw	10(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+78(%edx)
	movw	8(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+80(%edx)
	movw	14(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+98(%edx)
	movw	12(%eax,%esi), %ax
	movw	%ax, _VR+116(%edx)
	jmp	L1046
	.p2align 2,,3
L1056:
	movl	_RSP+12, %eax
	movw	2(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+8(%edx)
	movw	(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+26(%edx)
	movw	6(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+44(%edx)
	movw	4(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+62(%edx)
	movw	10(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+64(%edx)
	movw	8(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+82(%edx)
	movw	14(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+100(%edx)
	movw	12(%eax,%esi), %ax
	movw	%ax, _VR+118(%edx)
	jmp	L1046
	.p2align 2,,3
L1055:
	movl	_RSP+12, %eax
	movw	2(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+10(%edx)
	movw	(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+28(%edx)
	movw	6(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+46(%edx)
	movw	4(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+48(%edx)
	movw	10(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+66(%edx)
	movw	8(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+84(%edx)
	movw	14(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+102(%edx)
	movw	12(%eax,%esi), %ax
	movw	%ax, _VR+120(%edx)
	jmp	L1046
	.p2align 2,,3
L1054:
	movl	_RSP+12, %eax
	movw	2(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+12(%edx)
	movw	(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+30(%edx)
	movw	6(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+32(%edx)
	movw	4(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+50(%edx)
	movw	10(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+68(%edx)
	movw	8(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+86(%edx)
	movw	14(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+104(%edx)
	movw	12(%eax,%esi), %ax
	movw	%ax, _VR+122(%edx)
	jmp	L1046
	.p2align 2,,3
L1053:
	movl	_RSP+12, %eax
	movw	2(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+14(%edx)
	movw	(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+16(%edx)
	movw	6(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+34(%edx)
	movw	4(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+52(%edx)
	movw	10(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+70(%edx)
	movw	8(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+88(%edx)
	movw	14(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+106(%edx)
	movw	12(%eax,%esi), %ax
	movw	%ax, _VR+124(%edx)
	jmp	L1046
	.p2align 2,,3
L1052:
	movl	_RSP+12, %eax
	movw	2(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR(%edx)
	movw	(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+18(%edx)
	movw	6(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+36(%edx)
	movw	4(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+54(%edx)
	movw	10(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+72(%edx)
	movw	8(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+90(%edx)
	movw	14(%eax,%esi), %cx
	movl	%ebx, %edx
	sall	$4, %edx
	movw	%cx, _VR+108(%edx)
	movw	12(%eax,%esi), %ax
	movw	%ax, _VR+126(%edx)
	jmp	L1046
	.cfi_endproc
LFE111:
	.section .rdata,"dr"
LC54:
	.ascii "CFC2\11$zero, vcr\0"
LC55:
	.ascii "CFC2\12VCE\0"
	.align 4
LC56:
	.ascii "CFC2\12Invalid vector control register.\0"
	.text
	.p2align 2,,3
	.globl	_CFC2
	.def	_CFC2;	.scl	2;	.type	32;	.endef
_CFC2:
LFB97:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	testl	%ebx, %ebx
	je	L1074
	movl	36(%esp), %eax
	andl	$3, %eax
	cmpl	$2, %eax
	je	L1070
	cmpl	$3, %eax
	je	L1071
	decl	%eax
	je	L1069
	movswl	_VCO, %eax
	movl	%eax, _SR(,%ebx,4)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1074:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC54, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1071:
	.cfi_restore_state
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC56, 4(%esp)
L1073:
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movzbl	_VCE, %eax
	movl	%eax, _SR(,%ebx,4)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1069:
	.cfi_restore_state
	movswl	_VCC, %eax
	movl	%eax, _SR(,%ebx,4)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1070:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC55, 4(%esp)
	jmp	L1073
	.cfi_endproc
LFE97:
	.section .rdata,"dr"
LC57:
	.ascii "SQV\12Illegal element.\0"
LC58:
	.ascii "SQV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_SQV
	.def	_SQV;	.scl	2;	.type	32;	.endef
_SQV:
LFB117:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %edx
	addl	_SR(,%edx,4), %eax
	movl	%eax, %edx
	andl	$4095, %edx
	andl	$15, %eax
	movl	36(%esp), %ecx
	testl	%ecx, %ecx
	jne	L1085
	cmpl	$2, %eax
	je	L1080
	jle	L1086
	cmpl	$4, %eax
	je	L1081
	cmpl	$6, %eax
	je	L1087
L1078:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1086:
	.cfi_restore_state
	testl	%eax, %eax
	jne	L1078
	movl	_RSP+12, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR(%ecx), %ebx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+2(%ecx), %bx
	movw	%bx, (%eax,%edx)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 6(%eax,%edx)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 4(%eax,%edx)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 10(%eax,%edx)
	movw	_VR+10(%ecx), %bx
	movw	%bx, 8(%eax,%edx)
	movl	_VR+12(%ecx), %ebx
	movw	%bx, 14(%eax,%edx)
	movw	_VR+14(%ecx), %cx
	movw	%cx, 12(%eax,%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1085:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC57, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1081:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR(%ecx), %ebx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+2(%ecx), %bx
	movw	%bx, (%eax,%edx)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 6(%eax,%edx)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 4(%eax,%edx)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 10(%eax,%edx)
	movw	_VR+10(%ecx), %cx
	movw	%cx, 8(%eax,%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1080:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR(%ecx), %ebx
	movw	%bx, -2(%eax,%edx)
	movw	_VR+2(%ecx), %bx
	movw	%bx, 4(%eax,%edx)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 8(%eax,%edx)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 6(%eax,%edx)
	movw	_VR+10(%ecx), %bx
	movw	%bx, 12(%eax,%edx)
	movl	_VR+12(%ecx), %ecx
	movw	%cx, 10(%eax,%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1087:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR(%ecx), %ebx
	movw	%bx, -2(%eax,%edx)
	movw	_VR+2(%ecx), %bx
	movw	%bx, 4(%eax,%edx)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 2(%eax,%edx)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 8(%eax,%edx)
	movl	_VR+8(%ecx), %ecx
	movw	%cx, 6(%eax,%edx)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE117:
	.data
	.align 4
LC1:
	.long	0
	.long	32
	.long	48
	.long	16
	.text
	.p2align 2,,3
	.globl	_message
	.def	_message;	.scl	2;	.type	32;	.endef
_message:
LFB18:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	leal	16(%esp), %edi
	movl	$LC1, %esi
	movl	$4, %ecx
	rep movsl
	movl	52(%esp), %eax
	andl	$3, %eax
	je	L1088
	movl	16(%esp,%eax,4), %eax
	movl	%eax, 12(%esp)
	movl	$0, 8(%esp)
	movl	48(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 32
	subl	$16, %esp
	.cfi_def_cfa_offset 48
L1088:
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE18:
	.section .rdata,"dr"
LC59:
	.ascii "RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_S
	.def	_res_S;	.scl	2;	.type	32;	.endef
_res_S:
LFB19:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC59, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE19:
	.section .rdata,"dr"
LC60:
	.ascii "MFC0\11$zero, rd\0"
LC61:
	.ascii "MFC0\12DMA_READ_LENGTH\0"
LC62:
	.ascii "MFC0\12DMA_WRITE_LENGTH\0"
LC63:
	.ascii "MFC0\12DMA_FULL\0"
LC64:
	.ascii "MFC0\12DMA_BUSY\0"
LC65:
	.ascii "MFC0\12CMD_STATUS\0"
	.text
	.p2align 2,,3
	.globl	_MFC0
	.def	_MFC0;	.scl	2;	.type	32;	.endef
_MFC0:
LFB20:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	testl	%ebx, %ebx
	je	L1124
	cmpl	$15, 36(%esp)
	jbe	L1125
L1096:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1125:
	.cfi_restore_state
	movl	36(%esp), %eax
	jmp	*L1115(,%eax,4)
	.section .rdata,"dr"
	.align 4
L1115:
	.long	L1099
	.long	L1100
	.long	L1101
	.long	L1102
	.long	L1103
	.long	L1104
	.long	L1105
	.long	L1106
	.long	L1107
	.long	L1108
	.long	L1109
	.long	L1110
	.long	L1111
	.long	L1112
	.long	L1113
	.long	L1114
	.text
	.p2align 2,,3
L1124:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC60, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	$0, _SR
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1113:
	.cfi_restore_state
	movl	_RSP+84, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1114:
	movl	_RSP+88, %eax
	movl	(%eax), %eax
L1123:
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1099:
	movl	_RSP+24, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1100:
	movl	_RSP+28, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1101:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC61, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+32, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1102:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC62, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1096
	.p2align 2,,3
L1103:
	movl	_RSP+40, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1104:
	movl	_RSP+44, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L1117
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC63, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	.p2align 2,,3
L1117:
	movl	$0, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1105:
	movl	_RSP+48, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L1117
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC64, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1117
	.p2align 2,,3
L1106:
	movl	_RSP+56, %eax
	movl	(%eax), %edx
	movl	%edx, _SR(,%ebx,4)
	movl	$0, (%eax)
	jmp	L1096
	.p2align 2,,3
L1107:
	movl	_RSP+60, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1108:
	movl	_RSP+64, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1109:
	movl	_RSP+68, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1110:
	movl	_RSP+72, %eax
	movl	(%eax), %eax
	testb	$6, %ah
	je	L1123
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC65, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+72, %edx
	movl	(%edx), %eax
	andb	$249, %ah
	movl	%eax, (%edx)
	jmp	L1123
	.p2align 2,,3
L1111:
	movl	_RSP+76, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.p2align 2,,3
L1112:
	movl	_RSP+80, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L1096
	.cfi_endproc
LFE20:
	.section .rdata,"dr"
LC66:
	.ascii "PC:  0x%03X\12inst:  0x%08X\0"
LC67:
	.ascii "SPECIAL\12Transposed rt?\0"
LC68:
	.ascii "?...Uhh\0"
LC69:
	.ascii "Search\12AND\0"
LC70:
	.ascii "RESERVED\12SPECIAL\0"
LC71:
	.ascii "RESERVED\12REGIMM\0"
LC72:
	.ascii "Did I fuck these up?\0"
LC73:
	.ascii "ADDI\12Transposed rt?\0"
LC74:
	.ascii "Possible indirection?\0"
LC75:
	.ascii "No signals?\0"
LC76:
	.ascii "SIG0\0"
LC77:
	.ascii "SIG1\0"
LC78:
	.ascii "SIG2\0"
LC79:
	.ascii "SIG3\0"
LC80:
	.ascii "SIG4\0"
LC81:
	.ascii "SIG5\0"
LC82:
	.ascii "SIG6\0"
LC83:
	.ascii "SIG7\0"
LC84:
	.ascii "Signal hybrid!\0"
LC85:
	.ascii "ORI\12Transposed rt?\0"
LC86:
	.ascii "ORI\12Scan unsupported.\0"
LC87:
	.ascii "XORI\12Transposed rt?\0"
LC88:
	.ascii "No scan for MTC0.\0"
LC89:
	.ascii "wut\0"
LC90:
	.ascii "Voided a co-mfc0.\0"
LC91:
	.ascii "No scan for COP2.\0"
LC92:
	.ascii "LH\0"
LC93:
	.ascii "meh...no big deal\0"
LC94:
	.ascii "Stores?\12Nah.\0"
LC95:
	.ascii "Kiss my ass!\0"
	.text
	.p2align 2,,3
	.globl	_scan_ICACHE_for_cycle_fault
	.def	_scan_ICACHE_for_cycle_fault;	.scl	2;	.type	32;	.endef
_scan_ICACHE_for_cycle_fault:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$268, %esp
	.cfi_def_cfa_offset 288
	movdqa	_SR, %xmm0
	movdqa	%xmm0, 128(%esp)
	movdqa	_SR+16, %xmm0
	movdqa	%xmm0, 144(%esp)
	movdqa	_SR+32, %xmm0
	movdqa	%xmm0, 160(%esp)
	movdqa	_SR+48, %xmm0
	movdqa	%xmm0, 176(%esp)
	movdqa	_SR+64, %xmm0
	movdqa	%xmm0, 192(%esp)
	movdqa	_SR+80, %xmm0
	movdqa	%xmm0, 208(%esp)
	movdqa	_SR+96, %xmm0
	movdqa	%xmm0, 224(%esp)
	movdqa	_SR+112, %xmm0
	movdqa	%xmm0, 240(%esp)
	movl	_temp_PC, %esi
	andl	$4092, %esi
	movl	$-1, 32(%esp)
	movl	%esi, %ebp
	.p2align 2,,3
L1214:
	movl	_RSP+16, %eax
	movl	(%eax,%ebp), %ecx
	movl	%ecx, %edx
	shrl	$26, %edx
	movl	%edx, 36(%esp)
	movswl	%cx, %esi
	movl	%ecx, %edi
	andl	$65011712, %edi
	shrl	$21, %edi
	movl	%ecx, %ebx
	andl	$2031616, %ebx
	shrl	$16, %ebx
	movzwl	%cx, %edx
	movl	%edx, 40(%esp)
	shrl	$11, %edx
	movl	%edx, 44(%esp)
	movl	%ecx, 12(%esp)
	movl	%ebp, %eax
	andl	$4092, %eax
	movl	%eax, 8(%esp)
	movl	$LC66, 4(%esp)
	leal	48(%esp), %eax
	movl	%eax, (%esp)
	movl	%ecx, 28(%esp)
	call	_sprintf
	cmpl	$-1, 32(%esp)
	movl	28(%esp), %ecx
	je	L1219
	movl	32(%esp), %ebp
	andl	$4092, %ebp
L1129:
	movl	$0, 128(%esp)
	cmpl	$58, 36(%esp)
	jbe	L1220
L1130:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC59, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1220:
	movl	36(%esp), %edx
	jmp	*L1152(,%edx,4)
	.section .rdata,"dr"
	.align 4
L1152:
	.long	L1131
	.long	L1213
	.long	L1133
	.long	L1134
	.long	L1135
	.long	L1135
	.long	L1136
	.long	L1136
	.long	L1137
	.long	L1137
	.long	L1138
	.long	L1139
	.long	L1140
	.long	L1141
	.long	L1142
	.long	L1143
	.long	L1144
	.long	L1130
	.long	L1145
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1146
	.long	L1154
	.long	L1130
	.long	L1153
	.long	L1149
	.long	L1149
	.long	L1130
	.long	L1130
	.long	L1150
	.long	L1150
	.long	L1130
	.long	L1150
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1151
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1130
	.long	L1151
	.text
	.p2align 2,,3
L1146:
	movl	128(%esp,%edi,4), %eax
	addl	%esi, %eax
	andl	$4095, %eax
	movl	_RSP+12, %ecx
	movsbl	(%ecx,%eax), %eax
	movl	%eax, 128(%esp,%ebx,4)
L1154:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC92, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
L1153:
	addl	128(%esp,%edi,4), %esi
	andl	$4095, %esi
	movl	_RSP+12, %eax
	movl	(%eax,%esi), %eax
	movl	%eax, 128(%esp,%ebx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1134:
	leal	8(%ebp), %eax
	andl	$4092, %eax
	movl	%eax, 252(%esp)
L1133:
	andl	$1023, %ecx
	sall	$2, %ecx
	movl	%ecx, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1149:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC93, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
L1150:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC94, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1131:
	cmpl	%ebx, 288(%esp)
	je	L1155
	cmpl	%edi, 288(%esp)
	je	L1155
L1156:
	movl	%ecx, %eax
	andl	$1984, %eax
	shrl	$7, %eax
	andl	$63, %ecx
	cmpl	$43, %ecx
	jbe	L1221
L1157:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC70, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1151:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC95, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1145:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC91, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1144:
	testl	%edi, %edi
	jne	L1222
	cmpl	$4, 44(%esp)
	je	L1204
L1233:
	cmpl	288(%esp), %ebx
	je	L1223
L1209:
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1143:
	sall	$16, %esi
	movl	%esi, 128(%esp,%ebx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1142:
	cmpl	%edi, 288(%esp)
	je	L1224
L1202:
	andl	128(%esp,%edi,4), %esi
	movl	%esi, 128(%esp,%ebx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1141:
	cmpl	%edi, 288(%esp)
	je	L1225
L1201:
	orl	128(%esp,%edi,4), %esi
	movl	%esi, 128(%esp,%ebx,4)
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC86, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1140:
	movl	%esi, %ebp
	cmpl	%edi, 288(%esp)
	je	L1188
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC74, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
L1188:
	movl	%ebp, %eax
	sarw	$7, %ax
	cmpb	$8, %al
	je	L1194
	jbe	L1226
	cmpb	$32, %al
	je	L1196
	jbe	L1227
	cmpb	$64, %al
	je	L1197
	cmpb	$-128, %al
	jne	L1189
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC83, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$16384, (%eax)
	jmp	L1126
	.p2align 2,,3
L1139:
	xorl	%eax, %eax
	cmpl	%esi, 128(%esp,%edi,4)
	setb	%al
	movl	%eax, 128(%esp,%ebx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1138:
	xorl	%eax, %eax
	cmpl	%esi, 128(%esp,%edi,4)
	setl	%al
	movl	%eax, 128(%esp,%ebx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1137:
	cmpl	%edi, 288(%esp)
	je	L1228
L1187:
	addl	128(%esp,%edi,4), %esi
	movl	%esi, 128(%esp,%ebx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1136:
	testb	$1, 36(%esp)
	je	L1185
	xorl	%eax, %eax
	movl	128(%esp,%edi,4), %ecx
	testl	%ecx, %ecx
	setg	%al
	jmp	L1186
	.p2align 2,,3
L1135:
	testb	$1, 36(%esp)
	jne	L1229
	movl	128(%esp,%ebx,4), %edx
	xorl	%eax, %eax
	cmpl	%edx, 128(%esp,%edi,4)
	sete	%al
L1186:
	testl	%eax, %eax
	je	L1209
	leal	0(%ebp,%esi,4), %esi
	movl	%esi, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1213:
	cmpl	$1, %ebx
	jg	L1230
	movl	128(%esp,%edi,4), %eax
	andl	$1, %ebx
	je	L1181
L1232:
	notl	%eax
	shrl	$31, %eax
L1182:
	testl	%eax, %eax
	je	L1209
	movl	40(%esp), %ecx
	leal	4(%ebp,%ecx,4), %ecx
	andl	$4092, %ecx
	movl	%ecx, 32(%esp)
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC72, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	jmp	L1214
	.p2align 2,,3
L1219:
	addl	$4, %ebp
	andl	$4092, %ebp
	jmp	L1129
	.p2align 2,,3
L1221:
	jmp	*L1175(,%ecx,4)
	.section .rdata,"dr"
	.align 4
L1175:
	.long	L1158
	.long	L1157
	.long	L1159
	.long	L1160
	.long	L1161
	.long	L1157
	.long	L1162
	.long	L1163
	.long	L1164
	.long	L1165
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1166
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1157
	.long	L1167
	.long	L1167
	.long	L1168
	.long	L1168
	.long	L1169
	.long	L1170
	.long	L1171
	.long	L1172
	.long	L1157
	.long	L1157
	.long	L1173
	.long	L1174
	.text
	.p2align 2,,3
L1229:
	movl	128(%esp,%ebx,4), %eax
	cmpl	%eax, 128(%esp,%edi,4)
	setne	%al
	movzbl	%al, %eax
	jmp	L1186
	.p2align 2,,3
L1185:
	xorl	%eax, %eax
	movl	128(%esp,%edi,4), %edx
	testl	%edx, %edx
	setle	%al
	jmp	L1186
	.p2align 2,,3
L1230:
	leal	-16(%ebx), %eax
	cmpl	$1, %eax
	jbe	L1215
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC71, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	$-1, 32(%esp)
	jmp	L1214
	.p2align 2,,3
L1226:
	cmpb	$1, %al
	je	L1191
	jb	L1190
	cmpb	$2, %al
	je	L1192
	cmpb	$4, %al
	je	L1231
L1189:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC84, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$32640, (%eax)
	.p2align 2,,3
L1126:
	addl	$268, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1181:
	.cfi_restore_state
	shrl	$31, %eax
	jmp	L1182
L1215:
	leal	8(%ebp), %eax
	andl	$4092, %eax
	movl	%eax, 252(%esp)
	movl	128(%esp,%edi,4), %eax
	andl	$1, %ebx
	je	L1181
	jmp	L1232
	.p2align 2,,3
L1155:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC67, 4(%esp)
	movl	$0, (%esp)
	movl	%ecx, 28(%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	44(%esp), %edx
	movl	%edx, 288(%esp)
	movl	28(%esp), %ecx
	jmp	L1156
	.p2align 2,,3
L1222:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC88, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	cmpl	$4, 44(%esp)
	jne	L1233
L1204:
	cmpl	288(%esp), %ebx
	je	L1205
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC90, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	$-1, 32(%esp)
	jmp	L1214
L1227:
	cmpb	$16, %al
	jne	L1189
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC80, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$2048, (%eax)
	jmp	L1126
L1190:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC75, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	jmp	L1126
L1223:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC89, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
L1205:
	movl	_RSP+52, %eax
	movl	(%eax), %ebp
	andl	$4095, %ebp
	movl	$-1, 32(%esp)
	jmp	L1214
L1173:
	movl	128(%esp,%ebx,4), %ecx
	xorl	%eax, %eax
	cmpl	%ecx, 128(%esp,%edi,4)
	setl	%al
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1172:
	movl	128(%esp,%ebx,4), %eax
	orl	128(%esp,%edi,4), %eax
	notl	%eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1167:
	movl	128(%esp,%edi,4), %eax
	addl	128(%esp,%ebx,4), %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1166:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC68, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	jmp	L1126
L1165:
	movl	128(%esp,%edi,4), %edi
	movl	%edi, 32(%esp)
	andl	$4092, 32(%esp)
	leal	8(%ebp), %eax
	andl	$4092, %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	jmp	L1214
L1164:
	movl	128(%esp,%edi,4), %edi
	movl	%edi, 32(%esp)
	andl	$4092, 32(%esp)
	jmp	L1214
L1163:
	movl	128(%esp,%ebx,4), %eax
	movl	128(%esp,%edi,4), %ecx
	sarl	%cl, %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1162:
	movl	128(%esp,%ebx,4), %eax
	movl	128(%esp,%edi,4), %ecx
	shrl	%cl, %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1161:
	movl	128(%esp,%ebx,4), %eax
	movl	128(%esp,%edi,4), %ecx
	sall	%cl, %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1160:
	movl	128(%esp,%ebx,4), %ebx
	movb	%al, %cl
	sarl	%cl, %ebx
	movl	44(%esp), %edx
	movl	%ebx, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1171:
	movl	128(%esp,%ebx,4), %eax
	xorl	128(%esp,%edi,4), %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1170:
	movl	128(%esp,%ebx,4), %eax
	orl	128(%esp,%edi,4), %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1169:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC69, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	128(%esp,%ebx,4), %eax
	andl	128(%esp,%edi,4), %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1168:
	movl	128(%esp,%edi,4), %eax
	subl	128(%esp,%ebx,4), %eax
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1174:
	movl	128(%esp,%ebx,4), %ecx
	xorl	%eax, %eax
	cmpl	%ecx, 128(%esp,%edi,4)
	setb	%al
	movl	44(%esp), %edx
	movl	%eax, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1159:
	movl	128(%esp,%ebx,4), %ebx
	movb	%al, %cl
	shrl	%cl, %ebx
	movl	44(%esp), %edx
	movl	%ebx, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1158:
	movl	128(%esp,%ebx,4), %ebx
	movb	%al, %cl
	sall	%cl, %ebx
	movl	44(%esp), %edx
	movl	%ebx, 128(%esp,%edx,4)
	movl	$-1, 32(%esp)
	jmp	L1214
L1224:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC87, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	%ebx, 288(%esp)
	jmp	L1202
L1228:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC73, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	%ebx, 288(%esp)
	jmp	L1187
L1225:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC85, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	%ebx, 288(%esp)
	jmp	L1201
L1196:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC81, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$4096, (%eax)
	jmp	L1126
L1197:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC82, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$8192, (%eax)
	jmp	L1126
L1191:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC76, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$128, (%eax)
	jmp	L1126
	.p2align 2,,3
L1194:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC79, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$1024, (%eax)
	jmp	L1126
L1231:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC78, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$512, (%eax)
	jmp	L1126
L1192:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC77, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 272
	subl	$16, %esp
	.cfi_def_cfa_offset 288
	movl	_RSP+40, %eax
	xorl	$256, (%eax)
	jmp	L1126
	.cfi_endproc
LFE21:
	.p2align 2,,3
	.globl	_SP_DMA_WRITE
	.def	_SP_DMA_WRITE;	.scl	2;	.type	32;	.endef
_SP_DMA_WRITE:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$20, %esp
	.cfi_def_cfa_offset 40
	movl	_RSP+24, %eax
	movl	(%eax), %esi
	testl	$4096, %esi
	jne	L1235
	movl	_RSP+12, %eax
	movl	%eax, 16(%esp)
L1236:
	movl	_RSP+36, %eax
	movl	(%eax), %ecx
	movl	%ecx, %ebx
	andl	$4095, %ebx
	movl	%ecx, %edx
	shrl	$12, %edx
	andl	$255, %edx
	leal	1(%edx), %eax
	shrl	$20, %ecx
	leal	1(%ebx), %ebp
	addl	%ebp, %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, %ecx
	imull	%ebp, %ecx
	imull	8(%esp), %edx
	jmp	L1240
	.p2align 2,,3
L1243:
	movl	_RSP+24, %ebx
	movl	(%ebx), %esi
L1240:
	decl	%eax
	xorl	%ebx, %ebx
	movl	%ebx, (%esp)
L1238:
	movl	_RSP+28, %edi
	movl	(%edi), %edi
	addl	%edx, %edi
	addl	(%esp), %edi
	andl	$16777215, %edi
	movl	_RSP+8, %ebx
	addl	%ebx, %edi
	movl	%edi, 12(%esp)
	movl	(%esp), %edi
	addl	%ecx, %edi
	addl	%esi, %edi
	andl	$4095, %edi
	movl	16(%esp), %ebx
	movb	(%ebx,%edi), %bl
	movl	12(%esp), %esi
	movb	%bl, (%esi)
	incl	(%esp)
	cmpl	(%esp), %ebp
	ja	L1242
	subl	%ebp, %ecx
	subl	8(%esp), %edx
	testl	%eax, %eax
	jne	L1243
	movl	_RSP+48, %eax
	movl	$0, (%eax)
	movl	_RSP+40, %eax
	andl	$-5, (%eax)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1235:
	.cfi_restore_state
	movl	_RSP+16, %ebx
	movl	%ebx, 16(%esp)
	jmp	L1236
L1242:
	movl	_RSP+24, %esi
	movl	(%esi), %esi
	jmp	L1238
	.cfi_endproc
LFE22:
	.p2align 2,,3
	.globl	_SP_DMA_READ
	.def	_SP_DMA_READ;	.scl	2;	.type	32;	.endef
_SP_DMA_READ:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$16, %esp
	.cfi_def_cfa_offset 36
	movl	_RSP+24, %eax
	movl	(%eax), %edi
	testl	$4096, %edi
	jne	L1245
	movl	_RSP+12, %eax
	movl	%eax, 12(%esp)
L1246:
	movl	_RSP+32, %eax
	movl	(%eax), %ecx
	movl	%ecx, %esi
	andl	$4095, %esi
	movl	%ecx, %edx
	shrl	$12, %edx
	andl	$255, %edx
	leal	1(%edx), %eax
	shrl	$20, %ecx
	incl	%esi
	addl	%esi, %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, %ecx
	imull	%esi, %ecx
	imull	8(%esp), %edx
	jmp	L1250
	.p2align 2,,3
L1253:
	movl	_RSP+24, %ebx
	movl	(%ebx), %edi
L1250:
	decl	%eax
	xorl	%ebx, %ebx
	movl	%ebx, (%esp)
	movl	%ebx, %ebp
L1248:
	addl	%ecx, %ebp
	addl	%ebp, %edi
	andl	$4095, %edi
	movl	_RSP+28, %ebp
	movl	0(%ebp), %ebp
	addl	%edx, %ebp
	addl	(%esp), %ebp
	andl	$16777215, %ebp
	addl	_RSP+8, %ebp
	movb	0(%ebp), %bl
	movl	12(%esp), %ebp
	movb	%bl, 0(%ebp,%edi)
	incl	(%esp)
	cmpl	(%esp), %esi
	ja	L1252
	subl	%esi, %ecx
	subl	8(%esp), %edx
	testl	%eax, %eax
	jne	L1253
	movl	_RSP+48, %eax
	movl	$0, (%eax)
	movl	_RSP+40, %eax
	andl	$-5, (%eax)
	addl	$16, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1245:
	.cfi_restore_state
	movl	_RSP+16, %ebx
	movl	%ebx, 12(%esp)
	jmp	L1246
L1252:
	movl	_RSP+24, %edi
	movl	(%edi), %edi
	movl	(%esp), %ebp
	jmp	L1248
	.cfi_endproc
LFE23:
	.section .rdata,"dr"
LC96:
	.ascii "MTC0\12SP INTR:CLR\0"
LC97:
	.ascii "MTC0\12SP INTR BREAK:CLR\0"
LC98:
	.ascii "MTC0\12SP INTR BREAK:SET\0"
LC99:
	.ascii "MTC0\12SP_STATUS\0"
LC100:
	.ascii "MTC0\12DMA_FULL\0"
LC101:
	.ascii "MTC0\12DMA_BUSY\0"
LC102:
	.ascii "MTC0\12SP_RESERVED\0"
LC103:
	.ascii "MTC0\12CMD_START\0"
LC104:
	.ascii "MTC0\12CMD_END\0"
LC105:
	.ascii "MTC0\12CMD_CURRENT\0"
LC106:
	.ascii "CMD_STATUS\12TMEM_CTR\0"
LC107:
	.ascii "CMD_STATUS\12PIPE_CTR\0"
LC108:
	.ascii "CMD_STATUS\12COMMAND_CTR\0"
LC109:
	.ascii "CMD_STATUS\12CLOCK_CTR\0"
LC110:
	.ascii "MTC0\12CMD_STATUS\0"
LC111:
	.ascii "MTC0\12CMD_CLOCK\0"
LC112:
	.ascii "MTC0\12CMD_BUSY\0"
LC113:
	.ascii "MTC0\12CMD_PIPE_BUSY\0"
LC114:
	.ascii "MTC0\12CMD_TMEM_BUSY\0"
	.text
	.p2align 2,,3
	.globl	_MTC0
	.def	_MTC0;	.scl	2;	.type	32;	.endef
_MTC0:
LFB24:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	36(%esp), %eax
	cmpl	$15, %eax
	ja	L1254
	jmp	*L1272(,%eax,4)
	.section .rdata,"dr"
	.align 4
L1272:
	.long	L1256
	.long	L1257
	.long	L1258
	.long	L1259
	.long	L1260
	.long	L1261
	.long	L1262
	.long	L1263
	.long	L1264
	.long	L1265
	.long	L1266
	.long	L1267
	.long	L1268
	.long	L1269
	.long	L1270
	.long	L1271
	.text
	.p2align 2,,3
L1264:
	movl	_RSP+80, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1383
	movl	_SR(,%ebx,4), %eax
	movl	_RSP+60, %edx
	movl	%eax, (%edx)
	movl	_RSP+68, %edx
	movl	%eax, (%edx)
	movl	_RSP+64, %edx
	movl	%eax, (%edx)
	testb	$7, %al
	je	L1254
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC103, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+60, %eax
	andl	$-8, (%eax)
	movl	_RSP+68, %eax
	andl	$-8, (%eax)
	movl	_RSP+64, %eax
	andl	$-8, (%eax)
	.p2align 2,,3
L1254:
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1270:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC113, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1271:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC114, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1256:
	movl	_RSP+24, %edx
	movl	_SR(,%ebx,4), %eax
	movl	%eax, (%edx)
	testb	$7, %al
	je	L1254
L1382:
	andl	$-8, %eax
	movl	%eax, (%edx)
	jmp	L1254
	.p2align 2,,3
L1257:
	movl	_RSP+28, %edx
	movl	_SR(,%ebx,4), %eax
	movl	%eax, (%edx)
	testb	$7, %al
	je	L1254
	jmp	L1382
	.p2align 2,,3
L1258:
	movl	_SR(,%ebx,4), %eax
	orl	$7, %eax
	movl	_RSP+32, %edx
	movl	%eax, (%edx)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_SP_DMA_READ
	.p2align 2,,3
L1259:
	.cfi_restore_state
	movl	_SR(,%ebx,4), %eax
	orl	$7, %eax
	movl	_RSP+36, %edx
	movl	%eax, (%edx)
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	_SP_DMA_WRITE
	.p2align 2,,3
L1260:
	.cfi_restore_state
	movl	_RSP+40, %esi
	movl	_SR(,%ebx,4), %eax
	movl	%eax, %edx
	andl	$1, %edx
	notl	%edx
	andl	(%esi), %edx
	movl	%eax, %ecx
	shrl	%ecx
	andl	$1, %ecx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$4, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-3, %ecx
	andl	%edx, %ecx
	movl	%ecx, (%esi)
	testb	$8, %al
	jne	L1384
L1276:
	testb	$16, %al
	jne	L1385
L1277:
	movl	_RSP+40, %esi
	movl	%eax, %ecx
	andl	$32, %ecx
	notl	%ecx
	andl	(%esi), %ecx
	movl	%eax, %edx
	shrl	%edx
	andl	$32, %edx
	orl	%ecx, %edx
	movl	%edx, (%esi)
	testb	$-128, %al
	jne	L1386
L1279:
	testb	$1, %ah
	jne	L1387
L1280:
	movl	_RSP+40, %ebx
	movl	%eax, %edx
	andl	$512, %edx
	cmpl	$1, %edx
	sbbl	%ecx, %ecx
	orl	$-129, %ecx
	andl	(%ebx), %ecx
	movl	%eax, %edx
	shrl	$3, %edx
	andl	$128, %edx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$2048, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-257, %ecx
	andl	%edx, %ecx
	movl	%eax, %edx
	shrl	$4, %edx
	andl	$256, %edx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$8192, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-513, %ecx
	andl	%edx, %ecx
	movl	%eax, %edx
	shrl	$5, %edx
	andl	$512, %edx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$32768, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-1025, %ecx
	andl	%edx, %ecx
	movl	%eax, %edx
	shrl	$6, %edx
	andl	$1024, %edx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$131072, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-2049, %ecx
	andl	%edx, %ecx
	movl	%eax, %edx
	shrl	$7, %edx
	andl	$2048, %edx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$524288, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-4097, %ecx
	andl	%edx, %ecx
	movl	%eax, %edx
	shrl	$8, %edx
	andl	$4096, %edx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-8193, %ecx
	andl	%edx, %ecx
	movl	%eax, %edx
	shrl	$9, %edx
	andl	$8192, %edx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$8388608, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-16385, %ecx
	andl	%edx, %ecx
	movl	%eax, %edx
	shrl	$10, %edx
	andl	$16384, %edx
	orl	%ecx, %edx
	movl	%edx, (%ebx)
	testl	$-33554432, %eax
	je	L1254
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC99, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1261:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC100, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1262:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC101, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1263:
	movl	_SR(,%ebx,4), %eax
	testl	%eax, %eax
	jne	L1388
L1297:
	movl	_RSP+56, %eax
	movl	$0, (%eax)
	jmp	L1254
	.p2align 2,,3
L1265:
	movl	_RSP+80, %eax
	movl	(%eax), %esi
	testl	%esi, %esi
	jne	L1389
	movl	_SR(,%ebx,4), %eax
	movl	_RSP+64, %edx
	movl	%eax, (%edx)
	testb	$7, %al
	jne	L1390
L1300:
	movl	_RSP+104, %eax
	testl	%eax, %eax
	je	L1254
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.p2align 2,,3
L1266:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC105, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1267:
	movl	_SR(,%ebx,4), %eax
	testl	$-64, %eax
	je	L1301
	testb	$64, %al
	je	L1302
	movl	_RSP+88, %edx
	movl	(%edx), %ecx
	testl	%ecx, %ecx
	jne	L1391
L1303:
	movl	$0, (%edx)
L1302:
	testb	$-128, %al
	je	L1304
	movl	_RSP+84, %edx
	movl	(%edx), %esi
	testl	%esi, %esi
	jne	L1392
L1305:
	movl	$0, (%edx)
L1304:
	testb	$1, %ah
	je	L1306
	movl	_RSP+80, %edx
	movl	(%edx), %ecx
	testl	%ecx, %ecx
	jne	L1393
L1307:
	movl	$0, (%edx)
L1306:
	testb	$2, %ah
	je	L1308
	movl	_RSP+76, %edx
	movl	(%edx), %esi
	testl	%esi, %esi
	jne	L1394
L1309:
	movl	$0, (%edx)
L1308:
	testl	$-1024, %eax
	je	L1301
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC110, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_SR(,%ebx,4), %eax
	.p2align 2,,3
L1301:
	movl	_RSP+72, %esi
	movl	%eax, %edx
	andl	$1, %edx
	notl	%edx
	andl	(%esi), %edx
	movl	%eax, %ecx
	shrl	%ecx
	andl	$1, %ecx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$4, %ecx
	cmpl	$1, %ecx
	sbbl	%ebx, %ebx
	orl	$-3, %ebx
	andl	%edx, %ebx
	movl	%eax, %ecx
	shrl	$2, %ecx
	andl	$2, %ecx
	orl	%ebx, %ecx
	movl	%eax, %edx
	andl	$16, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-5, %edx
	andl	%ecx, %edx
	shrl	$3, %eax
	andl	$4, %eax
	orl	%edx, %eax
	movl	%eax, (%esi)
	jmp	L1254
	.p2align 2,,3
L1268:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC111, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_SR(,%ebx,4), %edx
	movl	_RSP+76, %eax
	movl	%edx, (%eax)
	jmp	L1254
	.p2align 2,,3
L1269:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC112, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1388:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC102, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1297
	.p2align 2,,3
L1385:
	movl	_RSP+20, %eax
	orl	$1, (%eax)
	call	*_RSP+92
	movl	_SR(,%ebx,4), %eax
	jmp	L1277
	.p2align 2,,3
L1384:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC96, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_SR(,%ebx,4), %eax
	jmp	L1276
	.p2align 2,,3
L1387:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC98, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_SR(,%ebx,4), %eax
	jmp	L1280
	.p2align 2,,3
L1386:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC97, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_SR(,%ebx,4), %eax
	jmp	L1279
	.p2align 2,,3
L1389:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC104, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1383:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC103, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1254
	.p2align 2,,3
L1390:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC104, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+64, %eax
	andl	$-8, (%eax)
	jmp	L1300
L1393:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC108, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+80, %edx
	movl	_SR(,%ebx,4), %eax
	jmp	L1307
L1394:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC109, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+76, %edx
	movl	_SR(,%ebx,4), %eax
	jmp	L1309
L1391:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC106, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+88, %edx
	movl	_SR(,%ebx,4), %eax
	jmp	L1303
L1392:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC107, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+84, %edx
	movl	_SR(,%ebx,4), %eax
	jmp	L1305
	.cfi_endproc
LFE24:
	.section .rdata,"dr"
LC115:
	.ascii "COP0\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_020
	.def	_res_020;	.scl	2;	.type	32;	.endef
_res_020:
LFB25:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC115, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE25:
	.section .rdata,"dr"
LC116:
	.ascii "SPECIAL\12RESERVED\0"
LC117:
	.ascii "REGIMM\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_run_microcode
	.def	_run_microcode;	.scl	2;	.type	32;	.endef
_run_microcode:
LFB126:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	_RSP+16, %eax
	movl	%eax, 20(%esp)
	movl	_RSP+52, %ebx
	movl	(%ebx), %edi
	movl	__imp__MessageBoxA@16, %edx
	movl	%edx, 28(%esp)
	movl	%eax, %ebp
	.p2align 2,,3
L1498:
	movl	0(%ebp,%edi), %eax
	addl	$4, %edi
	andl	$4092, %edi
	movl	%edi, (%ebx)
	movl	%eax, %edx
	shrl	$25, %edx
	cmpl	$37, %edx
	je	L1494
	movl	_temp_PC, %esi
L1493:
	movl	$0, _SR
	movzwl	%ax, %ecx
	movl	%ecx, %edx
	shrl	$11, %edx
	movl	%edx, 24(%esp)
	movl	%eax, %ebp
	shrl	$21, %ebp
	movl	%ebp, 16(%esp)
	movl	%eax, %edx
	shrl	$16, %edx
	andl	$31, %edx
	movl	%eax, %ebp
	shrl	$26, %ebp
	cmpl	$58, %ebp
	jbe	L1511
L1401:
	movl	%esi, _temp_PC
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC59, 4(%esp)
L1504:
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 48
	subl	$16, %esp
	.cfi_def_cfa_offset 64
L1501:
	movl	_RSP+16, %edx
	movl	%edx, 20(%esp)
	movl	_RSP+52, %ebx
	movl	(%ebx), %edi
	movl	%edx, %ebp
	jmp	L1498
	.p2align 2,,3
L1511:
	jmp	*L1430(,%ebp,4)
	.section .rdata,"dr"
	.align 4
L1430:
	.long	L1402
	.long	L1403
	.long	L1506
	.long	L1405
	.long	L1406
	.long	L1407
	.long	L1408
	.long	L1409
	.long	L1411
	.long	L1411
	.long	L1412
	.long	L1413
	.long	L1414
	.long	L1415
	.long	L1416
	.long	L1417
	.long	L1418
	.long	L1401
	.long	L1419
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1420
	.long	L1421
	.long	L1401
	.long	L1422
	.long	L1423
	.long	L1424
	.long	L1401
	.long	L1401
	.long	L1425
	.long	L1426
	.long	L1401
	.long	L1427
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1428
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1401
	.long	L1429
	.text
	.p2align 2,,3
L1411:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	movswl	%cx, %ecx
	addl	_SR(,%eax,4), %ecx
	movl	%ecx, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1405:
	leal	4(%edi), %eax
	andl	$4092, %eax
	movl	%eax, _SR+124
L1506:
	leal	0(,%ecx,4), %esi
L1452:
	movl	20(%esp), %ebp
	movl	0(%ebp,%edi), %eax
	movl	%esi, %edi
	andl	$4092, %edi
	movl	%edi, (%ebx)
	movl	%eax, %edx
	shrl	$25, %edx
	cmpl	$37, %edx
	jne	L1493
	movl	%esi, _temp_PC
	.p2align 2,,3
L1494:
	movl	%eax, %ecx
	andl	$63, %ecx
	movl	%eax, %edx
	andl	$31457280, %edx
	shrl	$21, %edx
	movl	%edx, 12(%esp)
	movl	%eax, %edx
	andl	$2031616, %edx
	shrl	$16, %edx
	movl	%edx, 8(%esp)
	movzwl	%ax, %edx
	shrl	$11, %edx
	movl	%edx, 4(%esp)
	andl	$1984, %eax
	shrl	$6, %eax
	movl	%eax, (%esp)
	call	*_SP_COP2_C2(,%ecx,4)
L1502:
	movl	_RSP+16, %eax
	movl	%eax, 20(%esp)
	movl	_RSP+52, %ebx
	movl	(%ebx), %edi
	movl	%eax, %ebp
	jmp	L1498
	.p2align 2,,3
L1409:
	movl	16(%esp), %eax
	andl	$31, %eax
	movl	_SR(,%eax,4), %eax
	testl	%eax, %eax
	jle	L1460
L1467:
	leal	(%edi,%ecx,4), %esi
	jmp	L1452
	.p2align 2,,3
L1408:
	movl	16(%esp), %eax
	andl	$31, %eax
	movl	_SR(,%eax,4), %eax
	testl	%eax, %eax
	jle	L1467
L1460:
	movl	%esi, _temp_PC
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1429:
	movl	%esi, _temp_PC
	movl	%eax, %ecx
	sall	$25, %ecx
	sarl	$31, %ecx
	andl	$65408, %ecx
	movl	16(%esp), %ebx
	andl	$31, %ebx
	movl	%ebx, 12(%esp)
	movl	%eax, %ebx
	andl	$127, %ebx
	orl	%ebx, %ecx
	movl	%ecx, 8(%esp)
	shrl	$7, %eax
	andl	$15, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	24(%esp), %ebp
	call	*_SP_SWC2(,%ebp,4)
	jmp	L1502
	.p2align 2,,3
L1407:
	movl	16(%esp), %eax
	andl	$31, %eax
	movl	_SR(,%edx,4), %ebp
	cmpl	%ebp, _SR(,%eax,4)
	jne	L1467
	jmp	L1460
	.p2align 2,,3
L1406:
	movl	16(%esp), %eax
	andl	$31, %eax
	movl	_SR(,%edx,4), %ebp
	cmpl	%ebp, _SR(,%eax,4)
	jne	L1460
	jmp	L1467
	.p2align 2,,3
L1403:
	movl	16(%esp), %eax
	andl	$31, %eax
	cmpl	$1, %edx
	je	L1510
	jle	L1512
	cmpl	$16, %edx
	je	L1457
	cmpl	$17, %edx
	je	L1458
L1454:
	movl	%esi, _temp_PC
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC117, 4(%esp)
	jmp	L1504
	.p2align 2,,3
L1428:
	movl	%esi, _temp_PC
	movl	%eax, %ecx
	sall	$25, %ecx
	sarl	$31, %ecx
	andl	$65408, %ecx
	movl	16(%esp), %ebx
	andl	$31, %ebx
	movl	%ebx, 12(%esp)
	movl	%eax, %ebx
	andl	$127, %ebx
	orl	%ebx, %ecx
	movl	%ecx, 8(%esp)
	shrl	$7, %eax
	andl	$15, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	24(%esp), %eax
	call	*_SP_LWC2(,%eax,4)
	jmp	L1501
	.p2align 2,,3
L1402:
	movl	%eax, %ecx
	andl	$63, %ecx
	cmpl	$43, %ecx
	jbe	L1513
L1431:
	movl	%esi, _temp_PC
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC116, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 48
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	jmp	L1502
	.p2align 2,,3
L1427:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	addl	_SR(,%eax,4), %ecx
	movl	%ecx, %eax
	andl	$4095, %eax
	andl	$3, %ecx
	cmpl	$2, %ecx
	je	L1489
	cmpl	$3, %ecx
	je	L1490
	decl	%ecx
	je	L1488
	movl	_SR(,%edx,4), %ecx
	movl	_RSP+12, %edx
	movl	%ecx, (%edx,%eax)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1419:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	sarl	$7, %ecx
	andl	$15, %ecx
	movl	%ecx, 8(%esp)
	movl	24(%esp), %ebp
	movl	%ebp, 4(%esp)
	movl	%edx, (%esp)
	call	*_SP_COP2(,%eax,4)
	jmp	L1502
	.p2align 2,,3
L1417:
	movl	%esi, _temp_PC
	sall	$16, %ecx
	movl	%ecx, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1416:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	xorl	_SR(,%eax,4), %ecx
	movl	%ecx, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1423:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	addl	_SR(,%eax,4), %ecx
	andl	$4095, %ecx
	xorl	$3, %ecx
	movl	_RSP+12, %eax
	movzbl	(%eax,%ecx), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1422:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	addl	_SR(,%eax,4), %ecx
	movl	%ecx, %eax
	andl	$4095, %eax
	andl	$3, %ecx
	cmpl	$2, %ecx
	je	L1477
	cmpl	$3, %ecx
	je	L1478
	decl	%ecx
	je	L1476
	movl	_RSP+12, %ecx
	movl	(%ecx,%eax), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1421:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	addl	_SR(,%eax,4), %ecx
	movl	%ecx, %eax
	andl	$4095, %eax
	andl	$3, %ecx
	cmpl	$2, %ecx
	je	L1473
	cmpl	$3, %ecx
	je	L1474
	decl	%ecx
	movl	_RSP+12, %ecx
	je	L1472
	movswl	2(%ecx,%eax), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1420:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	addl	_SR(,%eax,4), %ecx
	andl	$4095, %ecx
	xorl	$3, %ecx
	movl	_RSP+12, %eax
	movsbl	(%eax,%ecx), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1425:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	addl	_SR(,%eax,4), %ecx
	andl	$4095, %ecx
	xorl	$3, %ecx
	movl	_SR(,%edx,4), %edx
	movl	_RSP+12, %eax
	movb	%dl, (%eax,%ecx)
	jmp	L1501
	.p2align 2,,3
L1424:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	addl	_SR(,%eax,4), %ecx
	movl	%ecx, %eax
	andl	$4095, %eax
	andl	$3, %ecx
	cmpl	$2, %ecx
	je	L1481
	cmpl	$3, %ecx
	je	L1482
	decl	%ecx
	movl	_RSP+12, %ecx
	je	L1480
	movzwl	2(%ecx,%eax), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1426:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	addl	_SR(,%eax,4), %ecx
	movl	%ecx, %eax
	andl	$4095, %eax
	andl	$3, %ecx
	cmpl	$2, %ecx
	je	L1485
	cmpl	$3, %ecx
	je	L1486
	decl	%ecx
	movl	_SR(,%edx,4), %ecx
	movl	_RSP+12, %edx
	je	L1484
	movw	%cx, 2(%edx,%eax)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1415:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	orl	_SR(,%eax,4), %ecx
	movl	%ecx, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1413:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	movswl	%cx, %ecx
	cmpl	%ecx, _SR(,%eax,4)
	setb	%al
	movzbl	%al, %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1412:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	movswl	%cx, %ecx
	cmpl	%ecx, _SR(,%eax,4)
	setl	%al
	movzbl	%al, %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1418:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	jne	L1514
	movl	24(%esp), %ebp
	movl	_CR(,%ebp,4), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1414:
	movl	%esi, _temp_PC
	movl	16(%esp), %eax
	andl	$31, %eax
	andl	_SR(,%eax,4), %ecx
	movl	%ecx, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1513:
	jmp	*L1451(,%ecx,4)
	.section .rdata,"dr"
	.align 4
L1451:
	.long	L1432
	.long	L1431
	.long	L1433
	.long	L1434
	.long	L1435
	.long	L1431
	.long	L1436
	.long	L1437
	.long	L1438
	.long	L1439
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1440
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1431
	.long	L1441
	.long	L1442
	.long	L1444
	.long	L1444
	.long	L1445
	.long	L1446
	.long	L1447
	.long	L1448
	.long	L1431
	.long	L1431
	.long	L1449
	.long	L1450
	.text
L1444:
	movl	%esi, _temp_PC
	movl	16(%esp), %ecx
	movl	_SR(,%ecx,4), %eax
	subl	_SR(,%edx,4), %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1450:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %ecx
	movl	16(%esp), %eax
	cmpl	%ecx, _SR(,%eax,4)
	setb	%al
	movzbl	%al, %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1442:
	movl	%esi, _temp_PC
	movl	16(%esp), %ecx
	movl	_SR(,%ecx,4), %eax
	addl	_SR(,%edx,4), %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1441:
	movl	%esi, _temp_PC
	movl	16(%esp), %ebp
	movl	_SR(,%ebp,4), %eax
	addl	_SR(,%edx,4), %eax
	movl	24(%esp), %edx
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1440:
	movl	%esi, _temp_PC
	movl	_RSP+40, %edx
	movl	(%edx), %eax
	movl	%eax, %ecx
	orl	$3, %ecx
	movl	%ecx, (%edx)
	testb	$64, %al
	jne	L1515
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
L1439:
	.cfi_restore_state
	leal	4(%edi), %eax
	andl	$4092, %eax
	movl	24(%esp), %edx
	movl	%eax, _SR(,%edx,4)
	movl	16(%esp), %ecx
	movl	_SR(,%ecx,4), %esi
	jmp	L1452
L1438:
	movl	16(%esp), %eax
	movl	_SR(,%eax,4), %esi
	jmp	L1452
L1437:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %eax
	movl	16(%esp), %edx
	movl	_SR(,%edx,4), %ecx
	sarl	%cl, %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1436:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %eax
	movl	16(%esp), %edx
	movl	_SR(,%edx,4), %ecx
	shrl	%cl, %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1435:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %eax
	movl	16(%esp), %edx
	movl	_SR(,%edx,4), %ecx
	sall	%cl, %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1434:
	movl	%esi, _temp_PC
	movl	%eax, %ecx
	andl	$1984, %ecx
	sarl	$6, %ecx
	movl	_SR(,%edx,4), %edx
	sarl	%cl, %edx
	movl	24(%esp), %eax
	movl	%edx, _SR(,%eax,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1433:
	movl	%esi, _temp_PC
	movl	%eax, %ecx
	andl	$1984, %ecx
	sarl	$6, %ecx
	movl	_SR(,%edx,4), %edx
	shrl	%cl, %edx
	movl	24(%esp), %ebp
	movl	%edx, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1432:
	movl	%esi, _temp_PC
	movl	%eax, %ecx
	andl	$1984, %ecx
	sarl	$6, %ecx
	movl	_SR(,%edx,4), %edx
	sall	%cl, %edx
	movl	24(%esp), %eax
	movl	%edx, _SR(,%eax,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1449:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %ecx
	movl	16(%esp), %eax
	cmpl	%ecx, _SR(,%eax,4)
	setl	%al
	movzbl	%al, %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1448:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %eax
	movl	16(%esp), %edx
	orl	_SR(,%edx,4), %eax
	notl	%eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1447:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %eax
	movl	16(%esp), %edx
	xorl	_SR(,%edx,4), %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1446:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %eax
	movl	16(%esp), %edx
	orl	_SR(,%edx,4), %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1445:
	movl	%esi, _temp_PC
	movl	_SR(,%edx,4), %eax
	movl	16(%esp), %edx
	andl	_SR(,%edx,4), %eax
	movl	24(%esp), %ebp
	movl	%eax, _SR(,%ebp,4)
	movl	20(%esp), %ebp
	jmp	L1498
	.p2align 2,,3
L1514:
	cmpl	$4, %eax
	je	L1516
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC115, 4(%esp)
	movl	$0, (%esp)
	call	*28(%esp)
	.cfi_def_cfa_offset 48
	subl	$16, %esp
	.cfi_def_cfa_offset 64
	movl	_RSP+16, %ebp
	movl	%ebp, 20(%esp)
	movl	_RSP+52, %ebx
	movl	(%ebx), %edi
	jmp	L1498
L1458:
	leal	4(%edi), %edx
	andl	$4092, %edx
	movl	%edx, _SR+124
L1510:
	movl	_SR(,%eax,4), %eax
	testl	%eax, %eax
	jns	L1467
	jmp	L1460
L1516:
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_MTC0
	jmp	L1501
L1488:
	movzbl	_SR+3(,%edx,4), %ebx
	movl	_RSP+12, %ecx
	movb	%bl, 1(%ecx,%eax)
	movl	_SR(,%edx,4), %ecx
	sarl	$16, %ecx
	movl	_RSP+12, %ebx
	movb	%cl, (%ebx,%eax)
	movl	_SR(,%edx,4), %ecx
	sarl	$8, %ecx
	movl	_RSP+12, %ebx
	movb	%cl, -1(%ebx,%eax)
	addl	$6, %eax
	andl	$4095, %eax
	movl	_SR(,%edx,4), %ecx
	movl	_RSP+12, %edx
	movb	%cl, (%edx,%eax)
	jmp	L1502
L1476:
	movl	_RSP+12, %ebp
	movzbl	1(%ebp,%eax), %ecx
	sall	$8, %ecx
	movl	%ecx, _SR(,%edx,4)
	movzbl	0(%ebp,%eax), %esi
	orl	%ecx, %esi
	sall	$8, %esi
	movl	%esi, _SR(,%edx,4)
	movzbl	-1(%ebp,%eax), %ecx
	orl	%esi, %ecx
	sall	$8, %ecx
	movl	%ecx, _SR(,%edx,4)
	addl	$6, %eax
L1505:
	andl	$4095, %eax
	movzbl	0(%ebp,%eax), %eax
	orl	%ecx, %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1478:
	movl	_RSP+12, %esi
	movzbl	-3(%esi,%eax), %ebp
	sall	$8, %ebp
	movl	%ebp, _SR(,%edx,4)
	addl	$4, %eax
	andl	$4095, %eax
	movzbl	(%esi,%eax), %ecx
	orl	%ebp, %ecx
	sall	$8, %ecx
	movl	%ecx, _SR(,%edx,4)
	leal	-1(%eax), %ebp
	andl	$4095, %ebp
	movzbl	(%esi,%ebp), %eax
	orl	%ecx, %eax
	sall	$8, %eax
	movl	%eax, _SR(,%edx,4)
	decl	%ebp
	andl	$4095, %ebp
	movzbl	(%esi,%ebp), %ecx
	orl	%eax, %ecx
	movl	%ecx, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1477:
	movl	_RSP+12, %ebp
	movzbl	-1(%ebp,%eax), %ecx
	sall	$8, %ecx
	movl	%ecx, _SR(,%edx,4)
	movzbl	-2(%ebp,%eax), %esi
	orl	%ecx, %esi
	sall	$8, %esi
	movl	%esi, _SR(,%edx,4)
	addl	$5, %eax
	andl	$4095, %eax
	movzbl	0(%ebp,%eax), %ecx
	orl	%esi, %ecx
	sall	$8, %ecx
	movl	%ecx, _SR(,%edx,4)
	decl	%eax
	jmp	L1505
L1490:
	movzbl	_SR+3(,%edx,4), %ebx
	movl	_RSP+12, %ecx
	movb	%bl, -3(%ecx,%eax)
	leal	4(%eax), %ecx
	andl	$4095, %ecx
	movl	_SR(,%edx,4), %ebx
	sarl	$16, %ebx
	movl	_RSP+12, %esi
	movb	%bl, (%esi,%ecx)
	leal	3(%eax), %ecx
	andl	$4095, %ecx
	movl	_SR(,%edx,4), %ebx
	sarl	$8, %ebx
	movl	_RSP+12, %esi
	movb	%bl, (%esi,%ecx)
	addl	$2, %eax
L1503:
	andl	$4095, %eax
	movl	_SR(,%edx,4), %ecx
	movl	_RSP+12, %edx
	movb	%cl, (%edx,%eax)
	movl	_RSP+16, %ebp
	movl	%ebp, 20(%esp)
	movl	_RSP+52, %ebx
	movl	(%ebx), %edi
	jmp	L1498
L1489:
	movzbl	_SR+3(,%edx,4), %ebx
	movl	_RSP+12, %ecx
	movb	%bl, -1(%ecx,%eax)
	movl	_SR(,%edx,4), %ecx
	sarl	$16, %ecx
	movl	_RSP+12, %ebx
	movb	%cl, -2(%ebx,%eax)
	leal	5(%eax), %ecx
	andl	$4095, %ecx
	movl	_SR(,%edx,4), %ebx
	sarl	$8, %ebx
	movl	_RSP+12, %esi
	movb	%bl, (%esi,%ecx)
	addl	$4, %eax
	andl	$4095, %eax
	movl	_SR(,%edx,4), %ecx
	movl	_RSP+12, %edx
	movb	%cl, (%edx,%eax)
	jmp	L1501
L1480:
	movzwl	(%ecx,%eax), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1472:
	movswl	(%ecx,%eax), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1474:
	movl	_RSP+12, %esi
	movzbl	-3(%esi,%eax), %ecx
	sall	$8, %ecx
	movl	%ecx, _SR(,%edx,4)
	addl	$4, %eax
	andl	$4095, %eax
	movzbl	(%esi,%eax), %eax
	orl	%ecx, %eax
	cwtl
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1473:
	movl	_RSP+12, %ecx
	movswl	-2(%ecx,%eax), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1486:
	movl	_SR(,%edx,4), %ecx
	sarl	$8, %ecx
	movl	_RSP+12, %ebx
	movb	%cl, -3(%ebx,%eax)
	addl	$4, %eax
	jmp	L1503
L1485:
	movl	_SR(,%edx,4), %ecx
	movl	_RSP+12, %edx
	movw	%cx, -2(%edx,%eax)
	movl	20(%esp), %ebp
	jmp	L1498
L1482:
	movl	_RSP+12, %esi
	movzbl	-3(%esi,%eax), %ecx
	sall	$8, %ecx
	movl	%ecx, _SR(,%edx,4)
	addl	$4, %eax
	andl	$4095, %eax
	movzbl	(%esi,%eax), %eax
	orl	%ecx, %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1481:
	movl	_RSP+12, %ecx
	movzwl	-2(%ecx,%eax), %eax
	movl	%eax, _SR(,%edx,4)
	movl	20(%esp), %ebp
	jmp	L1498
L1484:
	movw	%cx, (%edx,%eax)
	movl	20(%esp), %ebp
	jmp	L1498
L1457:
	leal	4(%edi), %edx
	andl	$4092, %edx
	movl	%edx, _SR+124
L1508:
	movl	_SR(,%eax,4), %eax
	testl	%eax, %eax
	jns	L1460
	jmp	L1467
L1512:
	testl	%edx, %edx
	je	L1508
	jmp	L1454
L1515:
	movl	_RSP+20, %eax
	orl	$1, (%eax)
	movl	_RSP+92, %eax
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	jmp	*%eax
	.cfi_endproc
LFE126:
	.p2align 2,,3
	.globl	_CloseDLL
	.def	_CloseDLL;	.scl	2;	.type	32;	.endef
_CloseDLL:
LFB127:
	.cfi_startproc
	ret
	.cfi_endproc
LFE127:
	.section .rdata,"dr"
LC118:
	.ascii "Iconoclast's MLE Test\0"
	.align 4
LC119:
	.ascii "Thanks for test RDP:  Jabo, ziggy, Gonetz\12SP thread examples:  bpoint, zilmar, Ville Linde\0"
	.text
	.p2align 2,,3
	.globl	_DllAbout
	.def	_DllAbout;	.scl	2;	.type	32;	.endef
_DllAbout:
LFB128:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$64, 12(%esp)
	movl	$LC118, 8(%esp)
	movl	$LC119, 4(%esp)
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE128:
	.section .rdata,"dr"
LC120:
	.ascii "SP_STATUS_HALT\0"
	.align 4
LC121:
	.ascii "Halted RSP CPU loop by means of MTC0.\0"
	.text
	.p2align 2,,3
	.globl	_DoRspCycles
	.def	_DoRspCycles;	.scl	2;	.type	32;	.endef
_DoRspCycles:
LFB129:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	movl	_RSP+40, %ecx
	movl	(%ecx), %edx
	testb	$3, %dl
	jne	L1532
	movl	_RSP+12, %eax
	cmpl	$2, 4032(%eax)
	je	L1533
	call	_run_microcode
	movl	_RSP+40, %eax
	testb	$2, (%eax)
	je	L1534
L1522:
	movl	%ebx, %eax
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1533:
	.cfi_restore_state
	movl	_RSP+100, %eax
	testl	%eax, %eax
	je	L1525
	call	*%eax
	movl	_RSP+40, %ecx
	movl	(%ecx), %edx
L1525:
	movl	%edx, %eax
	orl	$515, %eax
	movl	%eax, (%ecx)
	andl	$64, %edx
	jne	L1535
	xorl	%ebx, %ebx
	movl	%ebx, %eax
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1532:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC120, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	xorl	%ebx, %ebx
	movl	%ebx, %eax
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1535:
	.cfi_restore_state
	movl	_RSP+20, %eax
	orl	$1, (%eax)
	call	*_RSP+92
	xorl	%ebx, %ebx
	movl	%ebx, %eax
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1534:
	.cfi_restore_state
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC121, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1522
	.cfi_endproc
LFE129:
	.section .rdata,"dr"
	.align 4
LC122:
	.ascii "Iconoclast's LLE SP Interpreter\0"
	.text
	.p2align 2,,3
	.globl	_GetDllInfo
	.def	_GetDllInfo;	.scl	2;	.type	32;	.endef
_GetDllInfo:
LFB130:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	movl	12(%esp), %eax
	movw	$257, (%eax)
	movw	$1, 2(%eax)
	leal	4(%eax), %edx
	movl	$LC122, %esi
	movl	$8, %ecx
	movl	%edx, %edi
	rep movsl
	movl	$0, 104(%eax)
	movl	$1, 108(%eax)
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE130:
	.section .rdata,"dr"
	.align 4
LC123:
	.ascii "This EXE sucks.\12Pick another one.\0"
	.text
	.p2align 2,,3
	.globl	_InitiateRSP
	.def	_InitiateRSP;	.scl	2;	.type	32;	.endef
_InitiateRSP:
LFB131:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	144(%esp), %eax
	movl	$0, (%eax)
	movl	$_RSP, %edi
	movl	$28, %ecx
	leal	32(%esp), %esi
	rep movsl
	movl	_RSP+52, %eax
	movl	$0, (%eax)
	movl	_RSP+12, %edx
	leal	4096(%edx), %eax
	cmpl	%eax, _RSP+16
	je	L1539
	movl	__imp__MessageBoxA@16, %ebx
	.p2align 2,,3
L1540:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC123, 4(%esp)
	movl	$0, (%esp)
	call	*%ebx
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+12, %edx
	leal	4096(%edx), %eax
	cmpl	%eax, _RSP+16
	jne	L1540
L1539:
	movl	$8192, %ecx
	xorl	%eax, %eax
	movl	%edx, %edi
	rep stosb
	addl	$16, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE131:
	.p2align 2,,3
	.globl	_InitiateRSPDebugger
	.def	_InitiateRSPDebugger;	.scl	2;	.type	32;	.endef
_InitiateRSPDebugger:
LFB132:
	.cfi_startproc
	movl	8(%esp), %eax
	jmp	*%eax
	.cfi_endproc
LFE132:
	.p2align 2,,3
	.globl	_RomClosed
	.def	_RomClosed;	.scl	2;	.type	32;	.endef
_RomClosed:
LFB133:
	.cfi_startproc
	movl	_RSP+52, %eax
	movl	$0, (%eax)
	ret
	.cfi_endproc
LFE133:
	.comm	_res_RSQ_high, 4, 2
	.comm	_res_RCP_high, 4, 2
	.comm	_res_RSQ, 4, 2
	.comm	_res_RCP, 4, 2
	.comm	_DPH, 4, 4
	.comm	_VCE, 1, 4
	.comm	_VCC, 2, 4
	.comm	_VCO, 2, 4
	.comm	_RSP, 112, 5
.lcomm _SR,128,32
.lcomm _temp_PC,4,16
.lcomm _VR,512,32
	.section .rdata,"dr"
	.align 32
_SP_COP2_C2:
	.long	_VMULF
	.long	_VMULU
	.long	_res_M
	.long	_res_M
	.long	_VMUDL
	.long	_VMUDM
	.long	_VMUDN
	.long	_VMUDH
	.long	_VMACF
	.long	_VMACU
	.long	_res_M
	.long	_VMACQ
	.long	_VMADL
	.long	_VMADM
	.long	_VMADN
	.long	_VMADH
	.long	_VADD
	.long	_VSUB
	.long	_res_V
	.long	_VABS
	.long	_VADDC
	.long	_VSUBC
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_VSAW
	.long	_res_V
	.long	_res_V
	.long	_VLT
	.long	_VEQ
	.long	_VNE
	.long	_VGE
	.long	_VCL
	.long	_VCH
	.long	_VCR
	.long	_VMRG
	.long	_VAND
	.long	_VNAND
	.long	_VOR
	.long	_VNOR
	.long	_VXOR
	.long	_VNXOR
	.long	_res_V
	.long	_res_V
	.long	_VRCP
	.long	_VRCPL
	.long	_VRCPH
	.long	_VMOV
	.long	_VRSQ
	.long	_VRSQL
	.long	_VRSQH
	.long	_VNOP
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.long	_res_V
	.align 32
_CR:
	.long	_RSP+24
	.long	_RSP+28
	.long	_RSP+32
	.long	_RSP+36
	.long	_RSP+40
	.long	_RSP+44
	.long	_RSP+48
	.long	_RSP+56
	.long	_RSP+60
	.long	_RSP+64
	.long	_RSP+68
	.long	_RSP+72
	.long	_RSP+76
	.long	_RSP+80
	.long	_RSP+84
	.long	_RSP+88
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.align 32
_SP_COP2:
	.long	_MFC2
	.long	_res_022
	.long	_CFC2
	.long	_res_022
	.long	_MTC2
	.long	_res_022
	.long	_CTC2
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.long	_res_022
	.align 32
_SP_LWC2:
	.long	_LBV
	.long	_LSV
	.long	_LLV
	.long	_LDV
	.long	_LQV
	.long	_LRV
	.long	_LPV
	.long	_LUV
	.long	_LHV
	.long	_LFV
	.long	_res_062
	.long	_LTV
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.long	_res_062
	.align 32
_SP_SWC2:
	.long	_SBV
	.long	_SSV
	.long	_SLV
	.long	_SDV
	.long	_SQV
	.long	_SRV
	.long	_SPV
	.long	_SUV
	.long	_SHV
	.long	_SFV
	.long	_SWV
	.long	_STV
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
	.long	_res_072
.lcomm _DivIn,4,16
	.align 32
_ei:
	.long	0
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.long	0
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.long	0
	.long	0
	.long	2
	.long	2
	.long	4
	.long	4
	.long	6
	.long	6
	.long	1
	.long	1
	.long	3
	.long	3
	.long	5
	.long	5
	.long	7
	.long	7
	.long	0
	.long	0
	.long	0
	.long	0
	.long	4
	.long	4
	.long	4
	.long	4
	.long	1
	.long	1
	.long	1
	.long	1
	.long	5
	.long	5
	.long	5
	.long	5
	.long	2
	.long	2
	.long	2
	.long	2
	.long	6
	.long	6
	.long	6
	.long	6
	.long	3
	.long	3
	.long	3
	.long	3
	.long	7
	.long	7
	.long	7
	.long	7
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	1
	.long	2
	.long	2
	.long	2
	.long	2
	.long	2
	.long	2
	.long	2
	.long	2
	.long	3
	.long	3
	.long	3
	.long	3
	.long	3
	.long	3
	.long	3
	.long	3
	.long	4
	.long	4
	.long	4
	.long	4
	.long	4
	.long	4
	.long	4
	.long	4
	.long	5
	.long	5
	.long	5
	.long	5
	.long	5
	.long	5
	.long	5
	.long	5
	.long	6
	.long	6
	.long	6
	.long	6
	.long	6
	.long	6
	.long	6
	.long	6
	.long	7
	.long	7
	.long	7
	.long	7
	.long	7
	.long	7
	.long	7
	.long	7
.lcomm _VACC,64,32
.lcomm _DivOut,4,16
	.align 8
LC2:
	.long	-4194304
	.long	1105199103
	.align 4
LC6:
	.long	1325400064
	.def	_sqrtf;	.scl	2;	.type	32;	.endef
	.def	_sprintf;	.scl	2;	.type	32;	.endef
	.section .drectve
	.ascii " -export:\"RomClosed\""
	.ascii " -export:\"InitiateRSPDebugger\""
	.ascii " -export:\"InitiateRSP\""
	.ascii " -export:\"GetDllInfo\""
	.ascii " -export:\"DoRspCycles\""
	.ascii " -export:\"DllAbout\""
	.ascii " -export:\"CloseDLL\""
