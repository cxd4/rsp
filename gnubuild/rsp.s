	.file	"rsp.c"
	.text
	.p2align 2,,3
	.def	_VABS;	.scl	3;	.type	32;	.endef
_VABS:
LFB28:
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
LFE28:
	.p2align 2,,3
	.def	_VADD;	.scl	3;	.type	32;	.endef
_VADD:
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
LFE29:
	.p2align 2,,3
	.def	_VADDC;	.scl	3;	.type	32;	.endef
_VADDC:
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
LFE30:
	.p2align 2,,3
	.def	_VAND;	.scl	3;	.type	32;	.endef
_VAND:
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
LFE31:
	.p2align 2,,3
	.def	_VCH;	.scl	3;	.type	32;	.endef
_VCH:
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
LFE32:
	.p2align 2,,3
	.def	_VCL;	.scl	3;	.type	32;	.endef
_VCL:
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
LFE33:
	.p2align 2,,3
	.def	_VCR;	.scl	3;	.type	32;	.endef
_VCR:
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
LFE34:
	.p2align 2,,3
	.def	_VEQ;	.scl	3;	.type	32;	.endef
_VEQ:
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
LFE35:
	.p2align 2,,3
	.def	_VGE;	.scl	3;	.type	32;	.endef
_VGE:
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
LFE36:
	.p2align 2,,3
	.def	_VLT;	.scl	3;	.type	32;	.endef
_VLT:
LFB37:
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
LFE37:
	.p2align 2,,3
	.def	_VMACF;	.scl	3;	.type	32;	.endef
_VMACF:
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
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	68(%esp), %ebx
	movl	76(%esp), %ecx
	sall	$4, %ebx
	movswl	_VR(%ebx), %eax
	sall	$5, %ecx
	movl	72(%esp), %esi
	sall	$3, %esi
	movl	_ei(%ecx), %edx
	addl	%esi, %edx
	movswl	_VR(%edx,%edx), %edx
	imull	%edx, %eax
	sall	%eax
	cltd
	addl	_VACC, %eax
	adcl	_VACC+4, %edx
	movl	%eax, _VACC
	movl	%edx, _VACC+4
	movswl	_VR+2(%ebx), %edi
	movl	_ei+4(%ecx), %ebp
	addl	%esi, %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %edi
	sall	%edi
	movl	%edi, (%esp)
	movl	%edi, %ebp
	sarl	$31, %ebp
	movl	%ebp, 4(%esp)
	movl	_VACC+8, %edi
	movl	_VACC+12, %ebp
	addl	%edi, (%esp)
	adcl	%ebp, 4(%esp)
	movl	(%esp), %edi
	movl	4(%esp), %ebp
	movl	%edi, _VACC+8
	movl	%ebp, _VACC+12
	movswl	_VR+4(%ebx), %edi
	movl	_ei+8(%ecx), %ebp
	addl	%esi, %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %edi
	sall	%edi
	movl	%edi, 8(%esp)
	movl	%edi, %ebp
	sarl	$31, %ebp
	movl	%ebp, 12(%esp)
	movl	_VACC+16, %edi
	movl	_VACC+20, %ebp
	addl	%edi, 8(%esp)
	adcl	%ebp, 12(%esp)
	movl	8(%esp), %edi
	movl	12(%esp), %ebp
	movl	%edi, _VACC+16
	movl	%ebp, _VACC+20
	movswl	_VR+6(%ebx), %edi
	movl	_ei+12(%ecx), %ebp
	addl	%esi, %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %edi
	sall	%edi
	movl	%edi, 16(%esp)
	movl	%edi, %ebp
	sarl	$31, %ebp
	movl	%ebp, 20(%esp)
	movl	_VACC+24, %edi
	movl	_VACC+28, %ebp
	addl	%edi, 16(%esp)
	adcl	%ebp, 20(%esp)
	movl	16(%esp), %edi
	movl	20(%esp), %ebp
	movl	%edi, _VACC+24
	movl	%ebp, _VACC+28
	movswl	_VR+8(%ebx), %edi
	movl	_ei+16(%ecx), %ebp
	addl	%esi, %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %edi
	sall	%edi
	movl	%edi, 24(%esp)
	movl	%edi, %ebp
	sarl	$31, %ebp
	movl	%ebp, 28(%esp)
	movl	_VACC+32, %edi
	movl	_VACC+36, %ebp
	addl	%edi, 24(%esp)
	adcl	%ebp, 28(%esp)
	movl	24(%esp), %edi
	movl	28(%esp), %ebp
	movl	%edi, _VACC+32
	movl	%ebp, _VACC+36
	movswl	_VR+10(%ebx), %edi
	movl	_ei+20(%ecx), %ebp
	addl	%esi, %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %edi
	sall	%edi
	movl	%edi, 32(%esp)
	movl	%edi, %ebp
	sarl	$31, %ebp
	movl	%ebp, 36(%esp)
	movl	_VACC+40, %edi
	movl	_VACC+44, %ebp
	addl	%edi, 32(%esp)
	adcl	%ebp, 36(%esp)
	movl	32(%esp), %edi
	movl	36(%esp), %ebp
	movl	%edi, _VACC+40
	movl	%ebp, _VACC+44
	movswl	_VR+12(%ebx), %edi
	movl	_ei+24(%ecx), %ebp
	addl	%esi, %ebp
	movswl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %edi
	sall	%edi
	movl	%edi, %ebp
	sarl	$31, %ebp
	addl	_VACC+48, %edi
	adcl	_VACC+52, %ebp
	movl	%edi, _VACC+48
	movl	%ebp, _VACC+52
	movswl	_VR+14(%ebx), %ebx
	addl	_ei+28(%ecx), %esi
	movswl	_VR(%esi,%esi), %ecx
	imull	%ecx, %ebx
	leal	(%ebx,%ebx), %ecx
	movl	%ecx, %ebx
	sarl	$31, %ebx
	addl	_VACC+56, %ecx
	adcl	_VACC+60, %ebx
	movl	%ecx, _VACC+56
	movl	%ebx, _VACC+60
	shrdl	$16, %edx, %eax
	cmpl	$-32768, %eax
	jl	L346
	cmpl	$32767, %eax
	jle	L371
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR(%eax)
	jmp	L348
	.p2align 2,,3
L346:
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
L348:
	movl	(%esp), %eax
	movl	4(%esp), %edx
	shrdl	$16, %edx, %eax
	cmpl	$-32768, %eax
	jl	L349
	cmpl	$32767, %eax
	jle	L372
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
	jmp	L351
	.p2align 2,,3
L349:
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
L351:
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	shrdl	$16, %edx, %eax
	cmpl	$-32768, %eax
	jl	L352
	cmpl	$32767, %eax
	jle	L373
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
	jmp	L354
	.p2align 2,,3
L352:
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
L354:
	movl	16(%esp), %eax
	movl	20(%esp), %edx
	shrdl	$16, %edx, %eax
	cmpl	$-32768, %eax
	jl	L355
	cmpl	$32767, %eax
	jle	L374
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
	jmp	L357
	.p2align 2,,3
L355:
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
L357:
	movl	24(%esp), %eax
	movl	28(%esp), %edx
	shrdl	$16, %edx, %eax
	cmpl	$-32768, %eax
	jl	L358
	cmpl	$32767, %eax
	jle	L375
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
	jmp	L360
	.p2align 2,,3
L358:
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
L360:
	movl	32(%esp), %eax
	movl	36(%esp), %edx
	shrdl	$16, %edx, %eax
	cmpl	$-32768, %eax
	jl	L361
	cmpl	$32767, %eax
	jle	L376
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
	movl	%edi, %esi
	shrdl	$16, %ebp, %esi
	cmpl	$-32768, %esi
	jge	L377
L364:
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
L366:
	shrdl	$16, %ebx, %ecx
	cmpl	$-32768, %ecx
	jge	L367
L379:
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+14(%eax)
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
L361:
	.cfi_restore_state
	movl	64(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
L363:
	movl	%edi, %esi
	shrdl	$16, %ebp, %esi
	cmpl	$-32768, %esi
	jl	L364
L377:
	cmpl	$32767, %esi
	movl	64(%esp), %eax
	jle	L378
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
	shrdl	$16, %ebx, %ecx
	cmpl	$-32768, %ecx
	jl	L379
L367:
	cmpl	$32767, %ecx
	movl	64(%esp), %eax
	jle	L369
	sall	$4, %eax
	movw	$32767, _VR+14(%eax)
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
L369:
	.cfi_restore_state
	sall	$4, %eax
	movw	%cx, _VR+14(%eax)
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
L378:
	.cfi_restore_state
	sall	$4, %eax
	movw	%si, _VR+12(%eax)
	jmp	L366
	.p2align 2,,3
L376:
	movl	64(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+10(%edx)
	jmp	L363
	.p2align 2,,3
L375:
	movl	64(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+8(%edx)
	jmp	L360
	.p2align 2,,3
L374:
	movl	64(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+6(%edx)
	jmp	L357
	.p2align 2,,3
L373:
	movl	64(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+4(%edx)
	jmp	L354
	.p2align 2,,3
L372:
	movl	64(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+2(%edx)
	jmp	L351
	.p2align 2,,3
L371:
	movl	64(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR(%edx)
	jmp	L348
	.cfi_endproc
LFE38:
	.p2align 2,,3
	.def	_VMACU;	.scl	3;	.type	32;	.endef
_VMACU:
LFB40:
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
	subl	$64, %esp
	.cfi_def_cfa_offset 80
	movl	80(%esp), %eax
	movl	84(%esp), %ecx
	movl	92(%esp), %edx
	sall	$4, %ecx
	movswl	_VR(%ecx), %esi
	sall	$5, %edx
	movl	88(%esp), %ebx
	sall	$3, %ebx
	movl	_ei(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	sall	%esi
	movl	%esi, (%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 4(%esp)
	movl	_VACC, %esi
	movl	_VACC+4, %edi
	addl	%esi, (%esp)
	adcl	%edi, 4(%esp)
	movl	(%esp), %esi
	movl	4(%esp), %edi
	movl	%esi, _VACC
	movl	%edi, _VACC+4
	movswl	_VR+2(%ecx), %esi
	movl	_ei+4(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	sall	%esi
	movl	%esi, 8(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 12(%esp)
	movl	_VACC+8, %esi
	movl	_VACC+12, %edi
	addl	%esi, 8(%esp)
	adcl	%edi, 12(%esp)
	movl	8(%esp), %esi
	movl	12(%esp), %edi
	movl	%esi, _VACC+8
	movl	%edi, _VACC+12
	movswl	_VR+4(%ecx), %esi
	movl	_ei+8(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	sall	%esi
	movl	%esi, 16(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 20(%esp)
	movl	_VACC+16, %esi
	movl	_VACC+20, %edi
	addl	%esi, 16(%esp)
	adcl	%edi, 20(%esp)
	movl	16(%esp), %esi
	movl	20(%esp), %edi
	movl	%esi, _VACC+16
	movl	%edi, _VACC+20
	movswl	_VR+6(%ecx), %esi
	movl	_ei+12(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	sall	%esi
	movl	%esi, 24(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 28(%esp)
	movl	_VACC+24, %esi
	movl	_VACC+28, %edi
	addl	%esi, 24(%esp)
	adcl	%edi, 28(%esp)
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	movl	%esi, _VACC+24
	movl	%edi, _VACC+28
	movswl	_VR+8(%ecx), %esi
	movl	_ei+16(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	sall	%esi
	movl	%esi, 32(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 36(%esp)
	movl	_VACC+32, %esi
	movl	_VACC+36, %edi
	addl	%esi, 32(%esp)
	adcl	%edi, 36(%esp)
	movl	32(%esp), %esi
	movl	36(%esp), %edi
	movl	%esi, _VACC+32
	movl	%edi, _VACC+36
	movswl	_VR+10(%ecx), %esi
	movl	_ei+20(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	sall	%esi
	movl	%esi, 40(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 44(%esp)
	movl	_VACC+40, %esi
	movl	_VACC+44, %edi
	addl	%esi, 40(%esp)
	adcl	%edi, 44(%esp)
	movl	40(%esp), %esi
	movl	44(%esp), %edi
	movl	%esi, _VACC+40
	movl	%edi, _VACC+44
	movswl	_VR+12(%ecx), %esi
	movl	_ei+24(%edx), %edi
	addl	%ebx, %edi
	movswl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	sall	%esi
	movl	%esi, 48(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 52(%esp)
	movl	_VACC+48, %esi
	movl	_VACC+52, %edi
	addl	%esi, 48(%esp)
	adcl	%edi, 52(%esp)
	movl	48(%esp), %esi
	movl	52(%esp), %edi
	movl	%esi, _VACC+48
	movl	%edi, _VACC+52
	movswl	_VR+14(%ecx), %ecx
	addl	_ei+28(%edx), %ebx
	movswl	_VR(%ebx,%ebx), %edx
	imull	%edx, %ecx
	sall	%ecx
	movl	%ecx, 56(%esp)
	movl	%ecx, %edi
	sarl	$31, %edi
	movl	%edi, 60(%esp)
	movl	_VACC+56, %edx
	movl	_VACC+60, %ecx
	addl	%edx, 56(%esp)
	adcl	%ecx, 60(%esp)
	movl	56(%esp), %ecx
	movl	60(%esp), %ebx
	movl	%ecx, _VACC+56
	movl	%ebx, _VACC+60
	movl	(%esp), %ecx
	movl	4(%esp), %ebx
	shrdl	$31, %ebx, %ecx
	testw	%cx, %cx
	setne	%cl
	movzbl	%cl, %ecx
	negl	%ecx
	orw	_VACC+2, %cx
	sall	$4, %eax
	movl	_VACC+4, %edx
	sarw	$15, %dx
	notl	%edx
	andl	%edx, %ecx
	movw	%cx, _VR(%eax)
	movl	8(%esp), %esi
	movl	12(%esp), %edi
	shrdl	$31, %edi, %esi
	xorl	%ecx, %ecx
	testw	%si, %si
	setne	%cl
	negl	%ecx
	orw	_VACC+10, %cx
	movl	_VACC+12, %edx
	sarw	$15, %dx
	notl	%edx
	andl	%edx, %ecx
	movw	%cx, _VR+2(%eax)
	movl	16(%esp), %esi
	movl	20(%esp), %edi
	shrdl	$31, %edi, %esi
	xorl	%ecx, %ecx
	testw	%si, %si
	setne	%cl
	negl	%ecx
	orw	_VACC+18, %cx
	movl	_VACC+20, %edx
	sarw	$15, %dx
	notl	%edx
	andl	%edx, %ecx
	movw	%cx, _VR+4(%eax)
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	shrdl	$31, %edi, %esi
	xorl	%ecx, %ecx
	testw	%si, %si
	setne	%cl
	negl	%ecx
	orw	_VACC+26, %cx
	movl	_VACC+28, %edx
	sarw	$15, %dx
	notl	%edx
	andl	%edx, %ecx
	movw	%cx, _VR+6(%eax)
	movl	32(%esp), %esi
	movl	36(%esp), %edi
	shrdl	$31, %edi, %esi
	xorl	%ecx, %ecx
	testw	%si, %si
	setne	%cl
	negl	%ecx
	orw	_VACC+34, %cx
	movl	_VACC+36, %edx
	sarw	$15, %dx
	notl	%edx
	andl	%edx, %ecx
	movw	%cx, _VR+8(%eax)
	movl	40(%esp), %esi
	movl	44(%esp), %edi
	shrdl	$31, %edi, %esi
	xorl	%ecx, %ecx
	testw	%si, %si
	setne	%cl
	negl	%ecx
	orw	_VACC+42, %cx
	movl	_VACC+44, %edx
	sarw	$15, %dx
	notl	%edx
	andl	%edx, %ecx
	movw	%cx, _VR+10(%eax)
	movl	48(%esp), %esi
	movl	52(%esp), %edi
	shrdl	$31, %edi, %esi
	xorl	%ecx, %ecx
	testw	%si, %si
	setne	%cl
	negl	%ecx
	orw	_VACC+50, %cx
	movl	_VACC+52, %edx
	sarw	$15, %dx
	notl	%edx
	andl	%edx, %ecx
	movw	%cx, _VR+12(%eax)
	movl	56(%esp), %ecx
	movl	60(%esp), %ebx
	shrdl	$31, %ebx, %ecx
	testw	%cx, %cx
	setne	%cl
	movzbl	%cl, %ecx
	negl	%ecx
	orw	_VACC+58, %cx
	movl	_VACC+60, %edx
	sarw	$15, %dx
	notl	%edx
	andl	%edx, %ecx
	movw	%cx, _VR+14(%eax)
	addl	$64, %esp
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
LFE40:
	.p2align 2,,3
	.def	_VMOV;	.scl	3;	.type	32;	.endef
_VMOV:
LFB45:
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
LFE45:
	.p2align 2,,3
	.def	_VMRG;	.scl	3;	.type	32;	.endef
_VMRG:
LFB46:
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
	jne	L385
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC
	testb	$2, %al
	jne	L387
L402:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+4(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+8
	testb	$4, %al
	jne	L389
L403:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+8(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+16
	testb	$8, %al
	jne	L391
L404:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+12(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+24
	testb	$16, %al
	jne	L393
L405:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+16(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+32
	testb	$32, %al
	jne	L395
L406:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+20(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+40
	testb	$64, %al
	jne	L397
L407:
	movl	%ecx, %esi
	sall	$5, %esi
	movl	_ei+24(%esi), %esi
	leal	(%esi,%edx,8), %esi
	movw	_VR(%esi,%esi), %si
	movw	%si, _VACC+48
	testb	$-128, %al
	je	L399
L408:
	sall	$4, %ebx
	movw	_VR+14(%ebx), %dx
L400:
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
L385:
	.cfi_restore_state
	movl	%ebx, %esi
	sall	$4, %esi
	movl	_VR(%esi), %esi
	movw	%si, _VACC
	testb	$2, %al
	je	L402
L387:
	movl	%ebx, %esi
	sall	$4, %esi
	movw	_VR+2(%esi), %si
	movw	%si, _VACC+8
	testb	$4, %al
	je	L403
L389:
	movl	%ebx, %esi
	sall	$4, %esi
	movl	_VR+4(%esi), %esi
	movw	%si, _VACC+16
	testb	$8, %al
	je	L404
L391:
	movl	%ebx, %esi
	sall	$4, %esi
	movw	_VR+6(%esi), %si
	movw	%si, _VACC+24
	testb	$16, %al
	je	L405
L393:
	movl	%ebx, %esi
	sall	$4, %esi
	movl	_VR+8(%esi), %esi
	movw	%si, _VACC+32
	testb	$32, %al
	je	L406
L395:
	movl	%ebx, %esi
	sall	$4, %esi
	movw	_VR+10(%esi), %si
	movw	%si, _VACC+40
	testb	$64, %al
	je	L407
L397:
	movl	%ebx, %esi
	sall	$4, %esi
	movl	_VR+12(%esi), %esi
	movw	%si, _VACC+48
	testb	$-128, %al
	jne	L408
L399:
	sall	$5, %ecx
	movl	_ei+28(%ecx), %eax
	leal	(%eax,%edx,8), %eax
	movw	_VR(%eax,%eax), %dx
	jmp	L400
	.cfi_endproc
LFE46:
	.p2align 2,,3
	.def	_VMUDL;	.scl	3;	.type	32;	.endef
_VMUDL:
LFB48:
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
LFE48:
	.p2align 2,,3
	.def	_VMUDM;	.scl	3;	.type	32;	.endef
_VMUDM:
LFB49:
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
LFE49:
	.p2align 2,,3
	.def	_VMUDN;	.scl	3;	.type	32;	.endef
_VMUDN:
LFB50:
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
LFE50:
	.p2align 2,,3
	.def	_VMULF;	.scl	3;	.type	32;	.endef
_VMULF:
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
LFE51:
	.p2align 2,,3
	.def	_VMULU;	.scl	3;	.type	32;	.endef
_VMULU:
LFB52:
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
	movw	_VACC+6, %cx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR(%eax)
	movw	_VACC+10, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movw	_VACC+14, %cx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+2(%eax)
	movw	_VACC+18, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movw	_VACC+22, %cx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+4(%eax)
	movw	_VACC+26, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movw	_VACC+30, %cx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+6(%eax)
	movw	_VACC+34, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movw	_VACC+38, %cx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+8(%eax)
	movw	_VACC+42, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movw	_VACC+46, %cx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+10(%eax)
	movw	_VACC+50, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movw	_VACC+54, %cx
	notl	%ecx
	andl	%ecx, %edx
	movw	%dx, _VR+12(%eax)
	movw	_VACC+58, %cx
	movl	%ecx, %edx
	sarw	$15, %dx
	orl	%ecx, %edx
	movw	_VACC+62, %cx
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
LFE52:
	.p2align 2,,3
	.def	_VNAND;	.scl	3;	.type	32;	.endef
_VNAND:
LFB53:
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
LFE53:
	.p2align 2,,3
	.def	_VNE;	.scl	3;	.type	32;	.endef
_VNE:
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
LFE54:
	.p2align 2,,3
	.def	_VNOR;	.scl	3;	.type	32;	.endef
_VNOR:
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
LFE56:
	.p2align 2,,3
	.def	_VNXOR;	.scl	3;	.type	32;	.endef
_VNXOR:
LFB57:
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
LFE57:
	.p2align 2,,3
	.def	_VOR;	.scl	3;	.type	32;	.endef
_VOR:
LFB58:
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
LFE58:
	.p2align 2,,3
	.def	_VRCP;	.scl	3;	.type	32;	.endef
_VRCP:
LFB59:
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
	movl	24(%esp), %edi
	movl	28(%esp), %eax
	andl	$7, %eax
	leal	(%eax,%edi,8), %eax
	movswl	_VR(%eax,%eax), %esi
	movl	%esi, _DivIn
	movl	%esi, %ebx
	negl	%ebx
	testl	%esi, %esi
	cmovns	%esi, %ebx
	movl	$32, %eax
	jmp	L449
	.p2align 2,,3
L447:
	testl	%eax, %eax
	je	L457
L449:
	decl	%eax
	movl	%ebx, %edx
	movb	%al, %cl
	sarl	%cl, %edx
	andl	$1, %edx
	je	L447
	movl	%eax, %ecx
	xorl	$31, %ecx
L448:
	sall	%cl, %ebx
	sarl	$22, %ebx
	andl	$511, %ebx
	movzwl	_div_ROM(%ebx,%ebx), %edx
	sall	$14, %edx
	orl	$1073741824, %edx
	movb	%al, %cl
	sarl	%cl, %edx
	cmpl	$0, %esi
	jl	L458
	je	L451
L456:
	movl	%edx, _DivOut
	movl	%edx, %ecx
L452:
	movl	28(%esp), %eax
	sall	$5, %eax
	leal	0(,%edi,8), %edx
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
	movl	20(%esp), %eax
	andl	$7, %eax
	movl	16(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movw	%cx, _VR(%eax,%eax)
	movl	$0, _DPH
	popl	%ebx
	.cfi_remember_state
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
L451:
	.cfi_restore_state
	movl	$2147483647, _DivOut
	movl	$-1, %ecx
	jmp	L452
	.p2align 2,,3
L457:
	movl	$16, %ecx
	movb	$15, %al
	jmp	L448
	.p2align 2,,3
L458:
	notl	%edx
	jmp	L456
	.cfi_endproc
LFE59:
	.p2align 2,,3
	.def	_VRCPH;	.scl	3;	.type	32;	.endef
_VRCPH:
LFB60:
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
LFE60:
	.p2align 2,,3
	.def	_VRCPL;	.scl	3;	.type	32;	.endef
_VRCPL:
LFB61:
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
	movl	28(%esp), %esi
	movl	_DPH, %edi
	movl	32(%esp), %eax
	andl	$7, %eax
	leal	(%eax,%esi,8), %eax
	testl	%edi, %edi
	je	L462
	movzwl	_VR(%eax,%eax), %ebx
	orl	_DivIn, %ebx
	movl	%ebx, _DivIn
	movl	%ebx, %edx
	testl	%ebx, %ebx
	jns	L464
	negl	%edx
	xorl	%eax, %eax
	cmpl	$-32768, %ebx
	setl	%al
	subl	%eax, %edx
L464:
	movl	$32, %eax
	jmp	L466
	.p2align 2,,3
L475:
	testl	%eax, %eax
	je	L474
L466:
	decl	%eax
	movl	%edx, %ebp
	movb	%al, %cl
	sarl	%cl, %ebp
	andl	$1, %ebp
	je	L475
L465:
	movl	%eax, %ecx
	xorl	$31, %ecx
	sall	%cl, %edx
	sarl	$22, %edx
	andl	$511, %edx
	movzwl	_div_ROM(%edx,%edx), %edx
	sall	$14, %edx
	orl	$1073741824, %edx
	movb	%al, %cl
	sarl	%cl, %edx
	cmpl	$0, %ebx
	jl	L476
	je	L468
L473:
	movl	%edx, _DivOut
L469:
	movl	32(%esp), %eax
	sall	$5, %eax
	sall	$3, %esi
	movl	_ei(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC
	movl	_ei+4(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+8
	movl	_ei+8(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+16
	movl	_ei+12(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+24
	movl	_ei+16(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+32
	movl	_ei+20(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+40
	movl	_ei+24(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+48
	addl	_ei+28(%eax), %esi
	movw	_VR(%esi,%esi), %ax
	movw	%ax, _VACC+56
	movl	24(%esp), %eax
	andl	$7, %eax
	movl	20(%esp), %ecx
	leal	(%eax,%ecx,8), %eax
	movw	%dx, _VR(%eax,%eax)
	movl	$0, _DPH
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
L462:
	.cfi_restore_state
	movzwl	_VR(%eax,%eax), %edx
	movl	%edx, _DivIn
	movl	%edx, %ebx
	jmp	L464
	.p2align 2,,3
L468:
	movl	$2147483647, _DivOut
	movl	$-1, %edx
	jmp	L469
	.p2align 2,,3
L474:
	negl	%edi
	sall	$4, %edi
	leal	31(%edi), %eax
	jmp	L465
	.p2align 2,,3
L476:
	notl	%edx
	jmp	L473
	.cfi_endproc
LFE61:
	.p2align 2,,3
	.def	_VRSQH;	.scl	3;	.type	32;	.endef
_VRSQH:
LFB63:
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
LFE63:
	.p2align 2,,3
	.def	_VRSQL;	.scl	3;	.type	32;	.endef
_VRSQL:
LFB64:
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
	movl	28(%esp), %esi
	movl	_DPH, %edi
	movl	32(%esp), %eax
	andl	$7, %eax
	leal	(%eax,%esi,8), %eax
	testl	%edi, %edi
	je	L480
	movzwl	_VR(%eax,%eax), %ebx
	orl	_DivIn, %ebx
	movl	%ebx, _DivIn
	movl	%ebx, %edx
	testl	%ebx, %ebx
	jns	L482
	negl	%edx
	xorl	%eax, %eax
	cmpl	$-32768, %ebx
	setl	%al
	subl	%eax, %edx
L482:
	movl	$32, %eax
	jmp	L484
	.p2align 2,,3
L493:
	testl	%eax, %eax
	je	L492
L484:
	decl	%eax
	movl	%edx, %ebp
	movb	%al, %cl
	sarl	%cl, %ebp
	andl	$1, %ebp
	je	L493
L483:
	movl	%eax, %ecx
	xorl	$31, %ecx
	movl	%ecx, %edi
	andl	$1, %edi
	orl	$512, %edi
	sall	%cl, %edx
	sarl	$22, %edx
	andl	$510, %edx
	orl	%edx, %edi
	movzwl	_div_ROM(%edi,%edi), %edx
	sall	$14, %edx
	orl	$1073741824, %edx
	movl	%eax, %ecx
	sarl	%ecx
	sarl	%cl, %edx
	cmpl	$0, %ebx
	jl	L494
	je	L486
L491:
	movl	%edx, _DivOut
L487:
	movl	32(%esp), %eax
	sall	$5, %eax
	sall	$3, %esi
	movl	_ei(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC
	movl	_ei+4(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+8
	movl	_ei+8(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+16
	movl	_ei+12(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+24
	movl	_ei+16(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+32
	movl	_ei+20(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+40
	movl	_ei+24(%eax), %ecx
	addl	%esi, %ecx
	movw	_VR(%ecx,%ecx), %cx
	movw	%cx, _VACC+48
	addl	_ei+28(%eax), %esi
	movw	_VR(%esi,%esi), %ax
	movw	%ax, _VACC+56
	movl	24(%esp), %eax
	andl	$7, %eax
	movl	20(%esp), %ecx
	leal	(%eax,%ecx,8), %eax
	movw	%dx, _VR(%eax,%eax)
	movl	$0, _DPH
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
L480:
	.cfi_restore_state
	movzwl	_VR(%eax,%eax), %edx
	movl	%edx, _DivIn
	movl	%edx, %ebx
	jmp	L482
	.p2align 2,,3
L486:
	movl	$2147483647, _DivOut
	movl	$-1, %edx
	jmp	L487
	.p2align 2,,3
L492:
	negl	%edi
	sall	$4, %edi
	leal	31(%edi), %eax
	jmp	L483
	.p2align 2,,3
L494:
	notl	%edx
	jmp	L491
	.cfi_endproc
LFE64:
	.p2align 2,,3
	.def	_VSUB;	.scl	3;	.type	32;	.endef
_VSUB:
LFB66:
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
	jg	L496
	cmpl	$-32768, %ebx
	jge	L521
	movw	$-32768, _VR(%eax)
	jmp	L498
	.p2align 2,,3
L496:
	movw	$32767, _VR(%eax)
L498:
	movl	20(%esp), %eax
	movw	%ax, _VACC+8
	cmpl	$32767, %eax
	jg	L499
	cmpl	$-32768, %eax
	jge	L522
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L501
	.p2align 2,,3
L499:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
L501:
	movl	24(%esp), %eax
	movw	%ax, _VACC+16
	cmpl	$32767, %eax
	jg	L502
	cmpl	$-32768, %eax
	jge	L523
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L504
	.p2align 2,,3
L502:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
L504:
	movl	28(%esp), %eax
	movw	%ax, _VACC+24
	cmpl	$32767, %eax
	jg	L505
	cmpl	$-32768, %eax
	jge	L524
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L507
	.p2align 2,,3
L505:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
L507:
	movl	32(%esp), %eax
	movw	%ax, _VACC+32
	cmpl	$32767, %eax
	jg	L508
	cmpl	$-32768, %eax
	jge	L525
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L510
	.p2align 2,,3
L508:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
L510:
	movl	36(%esp), %eax
	movw	%ax, _VACC+40
	cmpl	$32767, %eax
	jg	L511
	cmpl	$-32768, %eax
	jge	L526
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L513
	.p2align 2,,3
L511:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
L513:
	movl	40(%esp), %eax
	movw	%ax, _VACC+48
	cmpl	$32767, %eax
	jg	L514
	cmpl	$-32768, %eax
	jge	L527
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L516
	.p2align 2,,3
L514:
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
L516:
	movl	44(%esp), %eax
	movw	%ax, _VACC+56
	cmpl	$32767, %eax
	jle	L517
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$32767, _VR+14(%eax)
L518:
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
L517:
	.cfi_restore_state
	cmpl	$-32768, %eax
	jge	L519
	movl	80(%esp), %eax
	sall	$4, %eax
	movw	$-32768, _VR+14(%eax)
	jmp	L518
	.p2align 2,,3
L519:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+14(%edx)
	jmp	L518
	.p2align 2,,3
L527:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+12(%edx)
	jmp	L516
	.p2align 2,,3
L526:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+10(%edx)
	jmp	L513
	.p2align 2,,3
L525:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+8(%edx)
	jmp	L510
	.p2align 2,,3
L524:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+6(%edx)
	jmp	L507
	.p2align 2,,3
L523:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+4(%edx)
	jmp	L504
	.p2align 2,,3
L522:
	movl	80(%esp), %edx
	sall	$4, %edx
	movw	%ax, _VR+2(%edx)
	jmp	L501
	.p2align 2,,3
L521:
	movw	%bx, _VR(%eax)
	jmp	L498
	.cfi_endproc
LFE66:
	.p2align 2,,3
	.def	_VSUBC;	.scl	3;	.type	32;	.endef
_VSUBC:
LFB67:
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
	je	L529
	shrl	$31, %ebx
	orb	$1, %bh
L530:
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
L529:
	.cfi_restore_state
	xorl	%ebx, %ebx
	jmp	L530
	.cfi_endproc
LFE67:
	.p2align 2,,3
	.def	_VXOR;	.scl	3;	.type	32;	.endef
_VXOR:
LFB68:
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
LFE68:
	.p2align 2,,3
	.globl	_MTC2
	.def	_MTC2;	.scl	2;	.type	32;	.endef
_MTC2:
LFB71:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%esp), %edx
	incl	%edx
	andl	$-2, %edx
	sall	$4, %eax
	movl	4(%esp), %ecx
	movl	_SR(,%ecx,4), %ecx
	movw	%cx, _VR(%edx,%eax)
	ret
	.cfi_endproc
LFE71:
	.p2align 2,,3
	.globl	_LBV
	.def	_LBV;	.scl	2;	.type	32;	.endef
_LBV:
LFB74:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	movl	12(%esp), %ecx
	movl	20(%esp), %eax
	movl	_SR(,%eax,4), %eax
	addl	16(%esp), %eax
	andl	$4095, %eax
	xorl	$3, %eax
	movl	_RSP+12, %ebx
	movb	(%ebx,%eax), %al
	xorl	$1, %ecx
	sall	$4, %edx
	movb	%al, _VR(%ecx,%edx)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE74:
	.p2align 2,,3
	.globl	_LDV
	.def	_LDV;	.scl	2;	.type	32;	.endef
_LDV:
LFB77:
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
	leal	(%edx,%ecx,8), %ecx
	movl	%ecx, %edx
	andl	$4095, %edx
	andl	$7, %ecx
	jmp	*L560(,%ecx,4)
	.section .rdata,"dr"
	.align 4
L560:
	.long	L552
	.long	L553
	.long	L554
	.long	L555
	.long	L556
	.long	L557
	.long	L558
	.long	L559
	.text
	.p2align 2,,3
L558:
	movl	20(%esp), %ecx
	sall	$4, %ecx
	movl	_RSP+12, %ebx
	movw	-2(%ebx,%edx), %di
	leal	1(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	addl	$2, %edx
	andl	$4095, %edx
	movw	2(%ebx,%edx), %di
	leal	3(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	(%ebx,%edx), %di
	leal	5(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	6(%ebx,%edx), %dx
	addl	$7, %eax
	andl	$-2, %eax
	movw	%dx, _VR(%ecx,%eax)
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
L559:
	.cfi_restore_state
	movl	20(%esp), %ebx
	sall	$4, %ebx
	leal	1(%eax), %edi
	andl	$-2, %edi
	addl	%ebx, %edi
	movl	_RSP+12, %ecx
	movzbl	-3(%ecx,%edx), %esi
	sall	$8, %esi
	movw	%si, _VR(%edi)
	addl	$4, %edx
	andl	$4095, %edx
	movzbl	(%ecx,%edx), %ebp
	orl	%esi, %ebp
	movw	%bp, _VR(%edi)
	movw	-2(%ecx,%edx), %di
	leal	3(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ebx,%esi)
	leal	5(%eax), %esi
	andl	$-2, %esi
	leal	(%esi,%ebx), %ebp
	movzbl	-3(%ecx,%edx), %esi
	sall	$8, %esi
	movw	%si, _VR(%ebp)
	movzbl	4(%ecx,%edx), %edi
	orl	%esi, %edi
	movw	%di, _VR(%ebp)
	movw	2(%ecx,%edx), %dx
	addl	$7, %eax
	andl	$-2, %eax
	movw	%dx, _VR(%ebx,%eax)
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
L552:
	.cfi_restore_state
	movl	20(%esp), %ecx
	sall	$4, %ecx
	movl	_RSP+12, %ebx
	movw	2(%ebx,%edx), %di
	leal	1(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	(%ebx,%edx), %di
	leal	3(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	6(%ebx,%edx), %di
	leal	5(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	4(%ebx,%edx), %dx
	addl	$7, %eax
	andl	$-2, %eax
	movw	%dx, _VR(%ecx,%eax)
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
L553:
	.cfi_restore_state
	movl	20(%esp), %ebx
	sall	$4, %ebx
	movl	_RSP+12, %ecx
	movw	(%ecx,%edx), %di
	leal	1(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ebx,%esi)
	leal	3(%eax), %esi
	andl	$-2, %esi
	leal	(%esi,%ebx), %ebp
	movzbl	-1(%ecx,%edx), %esi
	sall	$8, %esi
	movw	%si, _VR(%ebp)
	movzbl	6(%ecx,%edx), %edi
	orl	%esi, %edi
	movw	%di, _VR(%ebp)
	movw	4(%ecx,%edx), %di
	leal	5(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ebx,%esi)
	addl	$7, %eax
	andl	$-2, %eax
	addl	%ebx, %eax
	movzbl	3(%ecx,%edx), %ebx
	sall	$8, %ebx
	movw	%bx, _VR(%eax)
	addl	$10, %edx
	andl	$4095, %edx
	movzbl	(%ecx,%edx), %edx
	orl	%ebx, %edx
	movw	%dx, _VR(%eax)
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
L554:
	.cfi_restore_state
	movl	20(%esp), %ecx
	sall	$4, %ecx
	movl	_RSP+12, %ebx
	movw	-2(%ebx,%edx), %di
	leal	1(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	4(%ebx,%edx), %di
	leal	3(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	2(%ebx,%edx), %di
	leal	5(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	addl	$8, %edx
	andl	$4095, %edx
	movw	(%ebx,%edx), %dx
	addl	$7, %eax
	andl	$-2, %eax
	movw	%dx, _VR(%ecx,%eax)
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
L555:
	.cfi_restore_state
	movl	20(%esp), %ebx
	sall	$4, %ebx
	leal	1(%eax), %ecx
	andl	$-2, %ecx
	leal	(%ecx,%ebx), %ebp
	movl	_RSP+12, %ecx
	movzbl	-3(%ecx,%edx), %esi
	sall	$8, %esi
	movw	%si, _VR(%ebp)
	movzbl	4(%ecx,%edx), %edi
	orl	%esi, %edi
	movw	%di, _VR(%ebp)
	movw	2(%ecx,%edx), %di
	leal	3(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ebx,%esi)
	leal	5(%eax), %edi
	andl	$-2, %edi
	addl	%ebx, %edi
	movzbl	1(%ecx,%edx), %esi
	sall	$8, %esi
	movw	%si, _VR(%edi)
	addl	$8, %edx
	andl	$4095, %edx
	movzbl	(%ecx,%edx), %ebp
	orl	%esi, %ebp
	movw	%bp, _VR(%edi)
	movw	-2(%ecx,%edx), %dx
	addl	$7, %eax
	andl	$-2, %eax
	movw	%dx, _VR(%ebx,%eax)
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
L556:
	.cfi_restore_state
	movl	20(%esp), %ecx
	sall	$4, %ecx
	movl	_RSP+12, %ebx
	movw	2(%ebx,%edx), %di
	leal	1(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	(%ebx,%edx), %di
	leal	3(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	addl	$4, %edx
	andl	$4095, %edx
	movw	2(%ebx,%edx), %di
	leal	5(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ecx,%esi)
	movw	(%ebx,%edx), %dx
	addl	$7, %eax
	andl	$-2, %eax
	movw	%dx, _VR(%ecx,%eax)
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
L557:
	.cfi_restore_state
	movl	20(%esp), %ebx
	sall	$4, %ebx
	movl	_RSP+12, %ecx
	movw	(%ecx,%edx), %di
	leal	1(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ebx,%esi)
	leal	3(%eax), %edi
	andl	$-2, %edi
	addl	%ebx, %edi
	movzbl	-1(%ecx,%edx), %esi
	sall	$8, %esi
	movw	%si, _VR(%edi)
	addl	$6, %edx
	andl	$4095, %edx
	movzbl	(%ecx,%edx), %ebp
	orl	%esi, %ebp
	movw	%bp, _VR(%edi)
	movw	-2(%ecx,%edx), %di
	leal	5(%eax), %esi
	andl	$-2, %esi
	movw	%di, _VR(%ebx,%esi)
	addl	$7, %eax
	andl	$-2, %eax
	addl	%ebx, %eax
	movzbl	-3(%ecx,%edx), %ebx
	sall	$8, %ebx
	movw	%bx, _VR(%eax)
	movzbl	4(%ecx,%edx), %edx
	orl	%ebx, %edx
	movw	%dx, _VR(%eax)
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
LFE77:
	.p2align 2,,3
	.globl	_SBV
	.def	_SBV;	.scl	2;	.type	32;	.endef
_SBV:
LFB86:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	8(%esp), %edx
	xorl	$1, %edx
	sall	$4, %eax
	movb	_VR(%edx,%eax), %cl
	movl	16(%esp), %eax
	movl	_SR(,%eax,4), %eax
	addl	12(%esp), %eax
	andl	$4095, %eax
	xorl	$3, %eax
	movl	_RSP+12, %edx
	movb	%cl, (%edx,%eax)
	ret
	.cfi_endproc
LFE86:
	.section .rdata,"dr"
LC2:
	.ascii "CP2\0"
LC3:
	.ascii "VNOP\0"
	.text
	.p2align 2,,3
	.def	_VNOP;	.scl	3;	.type	32;	.endef
_VNOP:
LFB55:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$64, 12(%esp)
	movl	$LC2, 8(%esp)
	movl	$LC3, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE55:
	.p2align 2,,3
	.def	_SIGNED_CLAMP.part.5;	.scl	3;	.type	32;	.endef
_SIGNED_CLAMP.part.5:
LFB112:
	.cfi_startproc
	movl	_VACC, %ecx
	movl	_VACC+4, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L567
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L599
	sall	$4, %edx
	movw	$32767, _VR(%edx)
	jmp	L569
	.p2align 2,,3
L567:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L599
	sall	$4, %edx
	movw	$-32768, _VR(%edx)
L569:
	movl	_VACC+8, %ecx
	movl	_VACC+12, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L571
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L600
	sall	$4, %edx
	movw	$32767, _VR+2(%edx)
L573:
	movl	_VACC+16, %ecx
	movl	_VACC+20, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L575
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L601
	sall	$4, %edx
	movw	$32767, _VR+4(%edx)
L577:
	movl	_VACC+24, %ecx
	movl	_VACC+28, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L579
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L602
	sall	$4, %edx
	movw	$32767, _VR+6(%edx)
L581:
	movl	_VACC+32, %ecx
	movl	_VACC+36, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L583
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L603
	sall	$4, %edx
	movw	$32767, _VR+8(%edx)
L585:
	movl	_VACC+40, %ecx
	movl	_VACC+44, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L587
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L604
	sall	$4, %edx
	movw	$32767, _VR+10(%edx)
L589:
	movl	_VACC+48, %ecx
	movl	_VACC+52, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L591
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L605
	sall	$4, %edx
	movw	$32767, _VR+12(%edx)
L593:
	movl	_VACC+56, %ecx
	movl	_VACC+60, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	je	L595
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	sall	$4, %eax
	orl	%ecx, %edx
	je	L598
	movw	$-32768, _VR+14(%eax)
	ret
	.p2align 2,,3
L599:
	sall	$4, %edx
	movw	_VACC+2, %cx
	movw	%cx, _VR(%edx)
	jmp	L569
	.p2align 2,,3
L595:
	andl	$65535, %edx
	sall	$4, %eax
	orl	%ecx, %edx
	je	L598
	movw	$32767, _VR+14(%eax)
	ret
	.p2align 2,,3
L591:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L605
	sall	$4, %edx
	movw	$-32768, _VR+12(%edx)
	jmp	L593
	.p2align 2,,3
L587:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L604
	sall	$4, %edx
	movw	$-32768, _VR+10(%edx)
	jmp	L589
	.p2align 2,,3
L583:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L603
	sall	$4, %edx
	movw	$-32768, _VR+8(%edx)
	jmp	L585
	.p2align 2,,3
L579:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L602
	sall	$4, %edx
	movw	$-32768, _VR+6(%edx)
	jmp	L581
	.p2align 2,,3
L575:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L601
	sall	$4, %edx
	movw	$-32768, _VR+4(%edx)
	jmp	L577
	.p2align 2,,3
L571:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L600
	sall	$4, %edx
	movw	$-32768, _VR+2(%edx)
	jmp	L573
	.p2align 2,,3
L600:
	sall	$4, %edx
	movw	_VACC+10, %cx
	movw	%cx, _VR+2(%edx)
	jmp	L573
	.p2align 2,,3
L602:
	sall	$4, %edx
	movw	_VACC+26, %cx
	movw	%cx, _VR+6(%edx)
	jmp	L581
	.p2align 2,,3
L601:
	sall	$4, %edx
	movw	_VACC+18, %cx
	movw	%cx, _VR+4(%edx)
	jmp	L577
	.p2align 2,,3
L598:
	movw	_VACC+58, %dx
	movw	%dx, _VR+14(%eax)
	ret
	.p2align 2,,3
L605:
	sall	$4, %edx
	movw	_VACC+50, %cx
	movw	%cx, _VR+12(%edx)
	jmp	L593
	.p2align 2,,3
L604:
	sall	$4, %edx
	movw	_VACC+42, %cx
	movw	%cx, _VR+10(%edx)
	jmp	L589
	.p2align 2,,3
L603:
	sall	$4, %edx
	movw	_VACC+34, %cx
	movw	%cx, _VR+8(%edx)
	jmp	L585
	.cfi_endproc
LFE112:
	.p2align 2,,3
	.def	_VMADN;	.scl	3;	.type	32;	.endef
_VMADN:
LFB44:
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
	andl	$-2147483648, %ebp
	testb	$128, %ah
	jne	L607
	andl	$65535, %eax
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L640
	sall	$4, %eax
	movw	$-1, _VR(%eax)
	jmp	L609
	.p2align 2,,3
L607:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L640
	sall	$4, %eax
	movw	$0, _VR(%eax)
L609:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L611
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L641
	sall	$4, %eax
	movw	$-1, _VR+2(%eax)
L613:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L615
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L642
	sall	$4, %eax
	movw	$-1, _VR+4(%eax)
L617:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L619
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L643
	sall	$4, %eax
	movw	$-1, _VR+6(%eax)
L621:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L623
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L644
	sall	$4, %eax
	movw	$-1, _VR+8(%eax)
L625:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L627
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L645
	sall	$4, %eax
	movw	$-1, _VR+10(%eax)
L629:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L631
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L646
	sall	$4, %eax
	movw	$-1, _VR+12(%eax)
L633:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	je	L635
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L638
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
L640:
	.cfi_restore_state
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	jmp	L609
	.p2align 2,,3
L635:
	andl	$65535, %eax
	sall	$4, %edi
	orl	%edx, %eax
	je	L638
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
L631:
	.cfi_restore_state
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L646
	sall	$4, %eax
	movw	$0, _VR+12(%eax)
	jmp	L633
	.p2align 2,,3
L627:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L645
	sall	$4, %eax
	movw	$0, _VR+10(%eax)
	jmp	L629
	.p2align 2,,3
L623:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L644
	sall	$4, %eax
	movw	$0, _VR+8(%eax)
	jmp	L625
	.p2align 2,,3
L619:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L643
	sall	$4, %eax
	movw	$0, _VR+6(%eax)
	jmp	L621
	.p2align 2,,3
L615:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L642
	sall	$4, %eax
	movw	$0, _VR+4(%eax)
	jmp	L617
	.p2align 2,,3
L611:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L641
	sall	$4, %eax
	movw	$0, _VR+2(%eax)
	jmp	L613
	.p2align 2,,3
L641:
	sall	$4, %eax
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	jmp	L613
	.p2align 2,,3
L643:
	sall	$4, %eax
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	jmp	L621
	.p2align 2,,3
L642:
	sall	$4, %eax
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	jmp	L617
	.p2align 2,,3
L638:
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
L646:
	.cfi_restore_state
	sall	$4, %eax
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	jmp	L633
	.p2align 2,,3
L645:
	sall	$4, %eax
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	jmp	L629
	.p2align 2,,3
L644:
	sall	$4, %eax
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	jmp	L625
	.cfi_endproc
LFE44:
	.p2align 2,,3
	.globl	_MFC2
	.def	_MFC2;	.scl	2;	.type	32;	.endef
_MFC2:
LFB69:
	.cfi_startproc
	movl	4(%esp), %edx
	cmpl	$15, 12(%esp)
	je	L650
	movl	12(%esp), %eax
	incl	%eax
	andl	$-2, %eax
	movl	8(%esp), %ecx
	sall	$4, %ecx
	movswl	_VR(%eax,%ecx), %eax
	movl	%eax, _SR(,%edx,4)
	ret
L648:
	.p2align 2,,3
L650:
	movl	8(%esp), %ecx
	sall	$4, %ecx
	movzbl	_VR+14(%ecx), %eax
	sall	$8, %eax
	movzbl	_VR+1(%ecx), %ecx
	orl	%ecx, %eax
	cwtl
	movl	%eax, _SR(,%edx,4)
	ret
	.cfi_endproc
LFE69:
	.section .rdata,"dr"
LC4:
	.ascii "VMACQ\0"
	.text
	.p2align 2,,3
	.def	_VMACQ;	.scl	3;	.type	32;	.endef
_VMACQ:
LFB39:
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
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC4, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_VACC, %eax
	movl	_VACC+4, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	testl	%ecx, %ecx
	jne	L652
	testb	$128, %dh
	jne	L701
	movl	$-2097152, %esi
	movl	$-1, %edi
L653:
	addl	%esi, %eax
	adcl	%edi, %edx
	movl	%eax, _VACC
	movl	%edx, _VACC+4
L652:
	movl	_VACC+8, %eax
	movl	_VACC+12, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	testl	%ecx, %ecx
	jne	L654
	testb	$128, %dh
	jne	L702
	movl	$-2097152, %esi
	movl	$-1, %edi
L655:
	addl	%esi, %eax
	adcl	%edi, %edx
	movl	%eax, _VACC+8
	movl	%edx, _VACC+12
L654:
	movl	_VACC+16, %eax
	movl	_VACC+20, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	testl	%ecx, %ecx
	jne	L656
	testb	$128, %dh
	jne	L703
	movl	$-2097152, %esi
	movl	$-1, %edi
L657:
	addl	%esi, %eax
	adcl	%edi, %edx
	movl	%eax, _VACC+16
	movl	%edx, _VACC+20
L656:
	movl	_VACC+24, %eax
	movl	_VACC+28, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	testl	%ecx, %ecx
	jne	L658
	testb	$128, %dh
	jne	L704
	movl	$-2097152, %esi
	movl	$-1, %edi
L659:
	addl	%esi, %eax
	adcl	%edi, %edx
	movl	%eax, _VACC+24
	movl	%edx, _VACC+28
L658:
	movl	_VACC+32, %eax
	movl	_VACC+36, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	testl	%ecx, %ecx
	jne	L660
	testb	$128, %dh
	jne	L705
	movl	$-2097152, %esi
	movl	$-1, %edi
L661:
	addl	%esi, %eax
	adcl	%edi, %edx
	movl	%eax, _VACC+32
	movl	%edx, _VACC+36
L660:
	movl	_VACC+40, %eax
	movl	_VACC+44, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	testl	%ecx, %ecx
	jne	L662
	testb	$128, %dh
	jne	L706
	movl	$-2097152, %esi
	movl	$-1, %edi
L663:
	addl	%esi, %eax
	adcl	%edi, %edx
	movl	%eax, _VACC+40
	movl	%edx, _VACC+44
L662:
	movl	_VACC+48, %eax
	movl	_VACC+52, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	testl	%ecx, %ecx
	jne	L664
	testb	$128, %dh
	jne	L707
	movl	$-2097152, %esi
	movl	$-1, %edi
L665:
	addl	%esi, %eax
	adcl	%edi, %edx
	movl	%eax, _VACC+48
	movl	%edx, _VACC+52
L664:
	movl	_VACC+56, %eax
	movl	_VACC+60, %edx
	movl	%eax, %ecx
	andl	$2097152, %ecx
	testl	%ecx, %ecx
	jne	L666
	testb	$128, %dh
	jne	L708
	movl	$-2097152, %esi
	movl	$-1, %edi
L667:
	addl	%esi, %eax
	adcl	%edi, %edx
	movl	%eax, _VACC+56
	movl	%edx, _VACC+60
L666:
	movl	_VACC+4, %eax
	sarw	$15, %ax
	movw	%ax, _VACC+6
	movl	_VACC+12, %eax
	sarw	$15, %ax
	movw	%ax, _VACC+14
	movl	_VACC+20, %eax
	sarw	$15, %ax
	movw	%ax, _VACC+22
	movl	_VACC+28, %eax
	sarw	$15, %ax
	movw	%ax, _VACC+30
	movl	_VACC+36, %eax
	sarw	$15, %ax
	movw	%ax, _VACC+38
	movl	_VACC+44, %eax
	sarw	$15, %ax
	movw	%ax, _VACC+46
	movl	_VACC+52, %eax
	sarw	$15, %ax
	movw	%ax, _VACC+54
	movl	_VACC+60, %eax
	sarw	$15, %ax
	movw	%ax, _VACC+62
	movl	_VACC, %eax
	movl	_VACC+4, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L668
	cmpl	$32767, %eax
	jle	L709
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$32752, _VR(%eax)
	jmp	L670
	.p2align 2,,3
L668:
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
L670:
	movl	_VACC+8, %eax
	movl	_VACC+12, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L671
	cmpl	$32767, %eax
	jle	L710
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$32752, _VR+2(%eax)
	jmp	L673
	.p2align 2,,3
L671:
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
L673:
	movl	_VACC+16, %eax
	movl	_VACC+20, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L674
	cmpl	$32767, %eax
	jle	L711
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$32752, _VR+4(%eax)
	jmp	L676
	.p2align 2,,3
L674:
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
L676:
	movl	_VACC+24, %eax
	movl	_VACC+28, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L677
	cmpl	$32767, %eax
	jle	L712
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$32752, _VR+6(%eax)
	jmp	L679
	.p2align 2,,3
L677:
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
L679:
	movl	_VACC+32, %eax
	movl	_VACC+36, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L680
	cmpl	$32767, %eax
	jle	L713
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$32752, _VR+8(%eax)
	jmp	L682
	.p2align 2,,3
L680:
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
L682:
	movl	_VACC+40, %eax
	movl	_VACC+44, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L683
	cmpl	$32767, %eax
	jle	L714
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$32752, _VR+10(%eax)
	jmp	L685
	.p2align 2,,3
L683:
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
L685:
	movl	_VACC+48, %eax
	movl	_VACC+52, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L686
	cmpl	$32767, %eax
	jle	L715
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$32752, _VR+12(%eax)
	jmp	L688
	.p2align 2,,3
L686:
	movl	%ebx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
L688:
	movl	_VACC+56, %eax
	movl	_VACC+60, %edx
	shrdl	$17, %edx, %eax
	sall	$4, %ebx
	cmpl	$-32768, %eax
	jge	L689
	movw	$-32768, _VR+14(%ebx)
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
L689:
	.cfi_restore_state
	cmpl	$32767, %eax
	jle	L691
	movw	$32752, _VR+14(%ebx)
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
L691:
	.cfi_restore_state
	andl	$-16, %eax
	movw	%ax, _VR+14(%ebx)
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
L715:
	.cfi_restore_state
	movl	%ebx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+12(%edx)
	jmp	L688
	.p2align 2,,3
L714:
	movl	%ebx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+10(%edx)
	jmp	L685
	.p2align 2,,3
L713:
	movl	%ebx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+8(%edx)
	jmp	L682
	.p2align 2,,3
L712:
	movl	%ebx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+6(%edx)
	jmp	L679
	.p2align 2,,3
L711:
	movl	%ebx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+4(%edx)
	jmp	L676
	.p2align 2,,3
L710:
	movl	%ebx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+2(%edx)
	jmp	L673
	.p2align 2,,3
L709:
	movl	%ebx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR(%edx)
	jmp	L670
	.p2align 2,,3
L708:
	movl	$2097152, %esi
	xorl	%edi, %edi
	jmp	L667
	.p2align 2,,3
L707:
	movl	$2097152, %esi
	xorl	%edi, %edi
	jmp	L665
	.p2align 2,,3
L706:
	movl	$2097152, %esi
	xorl	%edi, %edi
	jmp	L663
	.p2align 2,,3
L705:
	movl	$2097152, %esi
	xorl	%edi, %edi
	jmp	L661
	.p2align 2,,3
L704:
	movl	$2097152, %esi
	xorl	%edi, %edi
	jmp	L659
	.p2align 2,,3
L703:
	movl	$2097152, %esi
	xorl	%edi, %edi
	jmp	L657
	.p2align 2,,3
L702:
	movl	$2097152, %esi
	xorl	%edi, %edi
	jmp	L655
	.p2align 2,,3
L701:
	movl	$2097152, %esi
	xorl	%edi, %edi
	jmp	L653
	.cfi_endproc
LFE39:
	.section .rdata,"dr"
LC5:
	.ascii "VSAR\12Invalid mask.\0"
	.text
	.p2align 2,,3
	.def	_VSAW;	.scl	3;	.type	32;	.endef
_VSAW:
LFB65:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	xorl	$8, %eax
	cmpl	$1, %eax
	je	L719
	cmpl	$2, %eax
	je	L720
	testl	%eax, %eax
	je	L724
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC5, 4(%esp)
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
L724:
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
L720:
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
L719:
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
LFE65:
	.section .rdata,"dr"
LC6:
	.ascii "C2\12RESERVED\0"
	.text
	.p2align 2,,3
	.def	_res_V;	.scl	3;	.type	32;	.endef
_res_V:
LFB26:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC6, 4(%esp)
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
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE26:
	.section .rdata,"dr"
LC7:
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
LFB96:
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
	movl	$LC7, %esi
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
LFE96:
	.section .rdata,"dr"
LC8:
	.ascii "SWC2\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_072
	.def	_res_072;	.scl	2;	.type	32;	.endef
_res_072:
LFB98:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC8, 4(%esp)
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
	.p2align 2,,3
	.def	_res_M;	.scl	3;	.type	32;	.endef
_res_M:
LFB27:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC6, 4(%esp)
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
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE27:
	.section .rdata,"dr"
LC9:
	.ascii "LFV\11$v00[X], 0x000($00)\0"
	.text
	.p2align 2,,3
	.globl	_LFV
	.def	_LFV;	.scl	2;	.type	32;	.endef
_LFV:
LFB83:
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
	movl	$LC9, %esi
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
LFE83:
	.section .rdata,"dr"
LC10:
	.ascii "LWC2\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_062
	.def	_res_062;	.scl	2;	.type	32;	.endef
_res_062:
LFB85:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC10, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE85:
	.section .rdata,"dr"
LC11:
	.ascii "COP0\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_020
	.def	_res_020;	.scl	2;	.type	32;	.endef
_res_020:
LFB24:
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
LFE24:
	.section .rdata,"dr"
	.align 4
LC12:
	.ascii "VRSQ\12Unimplemented instruction.\0"
	.text
	.p2align 2,,3
	.def	_VRSQ;	.scl	3;	.type	32;	.endef
_VRSQ:
LFB62:
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
	movl	$0, _DPH
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE62:
	.section .rdata,"dr"
LC13:
	.ascii "COP2\12RESERVED\0"
	.text
	.p2align 2,,3
	.globl	_res_022
	.def	_res_022;	.scl	2;	.type	32;	.endef
_res_022:
LFB73:
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
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE73:
	.p2align 2,,3
	.def	_VMADL;	.scl	3;	.type	32;	.endef
_VMADL:
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
	andl	$-2147483648, %ebp
	testb	$128, %ah
	jne	L744
	andl	$65535, %eax
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L777
	sall	$4, %eax
	movw	$-1, _VR(%eax)
	jmp	L746
	.p2align 2,,3
L744:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L777
	sall	$4, %eax
	movw	$0, _VR(%eax)
L746:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L748
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L778
	sall	$4, %eax
	movw	$-1, _VR+2(%eax)
L750:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L752
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L779
	sall	$4, %eax
	movw	$-1, _VR+4(%eax)
L754:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L756
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L780
	sall	$4, %eax
	movw	$-1, _VR+6(%eax)
L758:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L760
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L781
	sall	$4, %eax
	movw	$-1, _VR+8(%eax)
L762:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L764
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L782
	sall	$4, %eax
	movw	$-1, _VR+10(%eax)
L766:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L768
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L783
	sall	$4, %eax
	movw	$-1, _VR+12(%eax)
L770:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	je	L772
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L775
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
L777:
	.cfi_restore_state
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	jmp	L746
	.p2align 2,,3
L772:
	andl	$65535, %eax
	sall	$4, %edi
	orl	%edx, %eax
	je	L775
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
L768:
	.cfi_restore_state
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L783
	sall	$4, %eax
	movw	$0, _VR+12(%eax)
	jmp	L770
	.p2align 2,,3
L764:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L782
	sall	$4, %eax
	movw	$0, _VR+10(%eax)
	jmp	L766
	.p2align 2,,3
L760:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L781
	sall	$4, %eax
	movw	$0, _VR+8(%eax)
	jmp	L762
	.p2align 2,,3
L756:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L780
	sall	$4, %eax
	movw	$0, _VR+6(%eax)
	jmp	L758
	.p2align 2,,3
L752:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L779
	sall	$4, %eax
	movw	$0, _VR+4(%eax)
	jmp	L754
	.p2align 2,,3
L748:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L778
	sall	$4, %eax
	movw	$0, _VR+2(%eax)
	jmp	L750
	.p2align 2,,3
L778:
	sall	$4, %eax
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	jmp	L750
	.p2align 2,,3
L780:
	sall	$4, %eax
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	jmp	L758
	.p2align 2,,3
L779:
	sall	$4, %eax
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	jmp	L754
	.p2align 2,,3
L775:
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
L783:
	.cfi_restore_state
	sall	$4, %eax
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	jmp	L770
	.p2align 2,,3
L782:
	sall	$4, %eax
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	jmp	L766
	.p2align 2,,3
L781:
	sall	$4, %eax
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	jmp	L762
	.cfi_endproc
LFE42:
	.section .rdata,"dr"
LC14:
	.ascii "LHV\12Illegal addr.\0"
	.text
	.p2align 2,,3
	.globl	_SHV
	.def	_SHV;	.scl	2;	.type	32;	.endef
_SHV:
LFB94:
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
	subl	36(%esp), %eax
	testb	$14, %al
	jne	L785
	andl	$4095, %eax
	xorl	$1, %eax
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
L785:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC14, 4(%esp)
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
LFE94:
	.p2align 2,,3
	.globl	_LHV
	.def	_LHV;	.scl	2;	.type	32;	.endef
_LHV:
LFB82:
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
	subl	36(%esp), %eax
	testb	$14, %al
	jne	L789
	andl	$4095, %eax
	xorl	$1, %eax
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	12(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+14(%edx)
	movzbl	14(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%edx)
	movzbl	8(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%edx)
	movzbl	10(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	4(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	6(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	2(%ecx,%eax), %eax
	sall	$7, %eax
	movw	%ax, _VR(%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L789:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC14, 4(%esp)
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
LFE82:
	.section .rdata,"dr"
LC15:
	.ascii "LUV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_LUV
	.def	_LUV;	.scl	2;	.type	32;	.endef
_LUV:
LFB81:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	36(%esp), %edx
	testl	%edx, %edx
	jne	L793
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %edx
	movl	%edx, %eax
	andl	$4095, %eax
	andl	$7, %edx
	movl	_RSP+12, %ecx
	jmp	*L802(,%edx,4)
	.section .rdata,"dr"
	.align 4
L802:
	.long	L794
	.long	L795
	.long	L796
	.long	L797
	.long	L798
	.long	L799
	.long	L800
	.long	L801
	.text
	.p2align 2,,3
L793:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC15, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
L792:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L800:
	.cfi_restore_state
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	-1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR(%edx)
	movzbl	-2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	addl	$2, %eax
	andl	$4095, %eax
	movzbl	3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%edx)
	movzbl	7(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%edx)
	movzbl	6(%ecx,%eax), %eax
	sall	$7, %eax
	movw	%ax, _VR+14(%edx)
	jmp	L792
	.p2align 2,,3
L801:
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	-3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR(%edx)
	incl	%eax
	andl	$4095, %eax
	movzbl	3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	7(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%edx)
	movzbl	6(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%edx)
	movzbl	5(%ecx,%eax), %eax
	sall	$7, %eax
	movw	%ax, _VR+14(%edx)
	jmp	L792
	.p2align 2,,3
L794:
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	4(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+14(%edx)
	movzbl	5(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%edx)
	movzbl	6(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%edx)
	movzbl	7(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	3(%ecx,%eax), %eax
	sall	$7, %eax
	movw	%ax, _VR(%edx)
	jmp	L792
	.p2align 2,,3
L795:
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	-1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	6(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	5(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	4(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%edx)
	movzbl	3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%edx)
	addl	$10, %eax
	andl	$4095, %eax
	movzbl	(%ecx,%eax), %eax
	sall	$7, %eax
	movw	%ax, _VR+14(%edx)
	jmp	L792
	.p2align 2,,3
L796:
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	-1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR(%edx)
	movzbl	-2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	5(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	4(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%edx)
	addl	$8, %eax
	andl	$4095, %eax
L805:
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%edx)
	movzbl	(%ecx,%eax), %eax
	sall	$7, %eax
	movw	%ax, _VR+14(%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L797:
	.cfi_restore_state
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	-3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR(%edx)
	movzbl	4(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	addl	$6, %eax
	andl	$4095, %eax
L806:
	movzbl	2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%edx)
	jmp	L805
	.p2align 2,,3
L798:
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	addl	$4, %eax
	andl	$4095, %eax
	movzbl	3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	jmp	L806
	.p2align 2,,3
L799:
	movl	32(%esp), %edx
	sall	$4, %edx
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+2(%edx)
	movzbl	-1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+4(%edx)
	addl	$3, %eax
	andl	$4095, %eax
	movzbl	3(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+6(%edx)
	movzbl	2(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+8(%edx)
	movzbl	1(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+10(%edx)
	movzbl	(%ecx,%eax), %ebx
	sall	$7, %ebx
	movw	%bx, _VR+12(%edx)
	movzbl	7(%ecx,%eax), %eax
	sall	$7, %eax
	movw	%ax, _VR+14(%edx)
	jmp	L792
	.cfi_endproc
LFE81:
	.section .rdata,"dr"
LC16:
	.ascii "LLV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LLV
	.def	_LLV;	.scl	2;	.type	32;	.endef
_LLV:
LFB76:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,4), %eax
	movl	%eax, %edx
	andl	$3, %edx
	decl	%edx
	cmpl	$2, %edx
	jbe	L811
	andl	$4095, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_RSP+12, %ebx
	movl	36(%esp), %edx
	incl	%edx
	andl	$-2, %edx
	movw	2(%ebx,%eax), %si
	movw	%si, _VR(%ecx,%edx)
	movw	(%ebx,%eax), %dx
	movl	36(%esp), %eax
	addl	$3, %eax
	andl	$-2, %eax
	movw	%dx, _VR(%ecx,%eax)
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
L811:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC16, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$20, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE76:
	.section .rdata,"dr"
LC17:
	.ascii "SFV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_SFV
	.def	_SFV;	.scl	2;	.type	32;	.endef
_SFV:
LFB95:
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
	jne	L820
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
L820:
	.cfi_restore_state
	cmpl	$8, %edx
	je	L821
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
L821:
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
LFE95:
	.section .rdata,"dr"
LC18:
	.ascii "SSV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_SSV
	.def	_SSV;	.scl	2;	.type	32;	.endef
_SSV:
LFB87:
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
	cmpl	$15, 36(%esp)
	je	L823
	andl	$3, %eax
	cmpl	$2, %eax
	je	L826
	cmpl	$3, %eax
	je	L827
	decl	%eax
	movl	36(%esp), %eax
	je	L825
	incl	%eax
	andl	$-2, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movw	_VR(%eax,%ecx), %cx
	movl	_RSP+12, %eax
	movw	%cx, 2(%eax,%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L823:
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
L827:
	.cfi_restore_state
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	36(%esp), %eax
	xorl	$1, %eax
	movb	_VR(%ecx,%eax), %bl
	movl	_RSP+12, %eax
	movb	%bl, -3(%eax,%edx)
	addl	$4, %edx
	movl	36(%esp), %eax
	incl	%eax
	xorl	$1, %eax
	movb	_VR(%ecx,%eax), %cl
	andl	$4095, %edx
	movl	_RSP+12, %eax
	movb	%cl, (%eax,%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L825:
	.cfi_restore_state
	incl	%eax
	andl	$-2, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movw	_VR(%eax,%ecx), %cx
	movl	_RSP+12, %eax
	movw	%cx, (%eax,%edx)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L826:
	.cfi_restore_state
	movl	36(%esp), %eax
	incl	%eax
	andl	$-2, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movw	_VR(%eax,%ecx), %cx
	movl	_RSP+12, %eax
	movw	%cx, -2(%eax,%edx)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE87:
	.section .rdata,"dr"
LC19:
	.ascii "LPV\12Weird addr.\0"
LC20:
	.ascii "LPV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_LPV
	.def	_LPV;	.scl	2;	.type	32;	.endef
_LPV:
LFB80:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	36(%esp), %ecx
	testl	%ecx, %ecx
	jne	L831
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %edx
	movl	%edx, %eax
	andl	$4095, %eax
	andl	$7, %edx
	je	L833
	cmpl	$4, %edx
	je	L838
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
L833:
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
L831:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC20, 4(%esp)
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
L838:
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
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE80:
	.section .rdata,"dr"
LC21:
	.ascii "LSV\12Weird addr.\0"
	.text
	.p2align 2,,3
	.globl	_LSV
	.def	_LSV;	.scl	2;	.type	32;	.endef
_LSV:
LFB75:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,2), %eax
	movl	%eax, %edx
	andl	$4095, %edx
	andl	$3, %eax
	cmpl	$2, %eax
	je	L842
	cmpl	$3, %eax
	je	L843
	decl	%eax
	movl	_RSP+12, %eax
	je	L841
	movw	2(%eax,%edx), %cx
L846:
	movl	36(%esp), %eax
	incl	%eax
	andl	$-2, %eax
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	%cx, _VR(%eax,%edx)
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L841:
	.cfi_restore_state
	movw	(%eax,%edx), %cx
	jmp	L846
	.p2align 2,,3
L843:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L842:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movw	-2(%eax,%edx), %cx
	jmp	L846
	.cfi_endproc
LFE75:
	.section .rdata,"dr"
LC22:
	.ascii "SPV\12Weird addr.\0"
LC23:
	.ascii "SPV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_SPV
	.def	_SPV;	.scl	2;	.type	32;	.endef
_SPV:
LFB92:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	36(%esp), %ebx
	testl	%ebx, %ebx
	jne	L848
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %eax
	testb	$7, %al
	jne	L852
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
L852:
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
L848:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC23, 4(%esp)
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
LFE92:
	.section .rdata,"dr"
LC24:
	.ascii "CFC2\11$zero, vcr\0"
LC25:
	.ascii "CFC2\12VCE\0"
	.align 4
LC26:
	.ascii "CFC2\12Invalid vector control register.\0"
	.text
	.p2align 2,,3
	.globl	_CFC2
	.def	_CFC2;	.scl	2;	.type	32;	.endef
_CFC2:
LFB70:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	testl	%ebx, %ebx
	je	L863
	movl	36(%esp), %eax
	andl	$3, %eax
	cmpl	$2, %eax
	je	L859
	cmpl	$3, %eax
	je	L860
	decl	%eax
	je	L858
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
L863:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC24, 4(%esp)
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
L860:
	.cfi_restore_state
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC26, 4(%esp)
L862:
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
L858:
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
L859:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC25, 4(%esp)
	jmp	L862
	.cfi_endproc
LFE70:
	.section .rdata,"dr"
LC27:
	.ascii "CTC2\12VCE\0"
	.align 4
LC28:
	.ascii "CTC2\12Invalid vector control register.\0"
	.text
	.p2align 2,,3
	.globl	_CTC2
	.def	_CTC2;	.scl	2;	.type	32;	.endef
_CTC2:
LFB72:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	36(%esp), %eax
	andl	$3, %eax
	cmpl	$2, %eax
	je	L867
	cmpl	$3, %eax
	je	L868
	movl	32(%esp), %edx
	decl	%eax
	movl	_SR(,%edx,4), %eax
	je	L866
	movw	%ax, _VCO
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L866:
	.cfi_restore_state
	movw	%ax, _VCC
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L868:
	.cfi_restore_state
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC28, 4(%esp)
L871:
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
L867:
	.cfi_restore_state
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC27, 4(%esp)
	jmp	L871
	.cfi_endproc
LFE72:
	.section .rdata,"dr"
LC29:
	.ascii "SRV\12Odd addr.\0"
LC30:
	.ascii "SRV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_SRV
	.def	_SRV;	.scl	2;	.type	32;	.endef
_SRV:
LFB91:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	36(%esp), %edx
	testl	%edx, %edx
	jne	L873
	movl	40(%esp), %edx
	sall	$4, %edx
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$4080, %eax
	andl	$15, %edx
	cmpl	$14, %edx
	jbe	L885
L874:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC29, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	.p2align 2,,3
L872:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L885:
	.cfi_restore_state
	jmp	*L883(,%edx,4)
	.section .rdata,"dr"
	.align 4
L883:
	.long	L872
	.long	L874
	.long	L876
	.long	L874
	.long	L877
	.long	L874
	.long	L878
	.long	L874
	.long	L879
	.long	L874
	.long	L880
	.long	L874
	.long	L881
	.long	L874
	.long	L882
	.text
	.p2align 2,,3
L873:
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
L882:
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
	jmp	L872
	.p2align 2,,3
L881:
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
	jmp	L872
	.p2align 2,,3
L880:
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
	jmp	L872
	.p2align 2,,3
L879:
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
	jmp	L872
	.p2align 2,,3
L878:
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movw	_VR+10(%ecx), %bx
	movw	%bx, 2(%edx,%eax)
	movl	_VR+12(%ecx), %ebx
	movw	%bx, (%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, 6(%edx,%eax)
	jmp	L872
	.p2align 2,,3
L877:
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR+12(%ecx), %ebx
	movw	%bx, 2(%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, (%edx,%eax)
	jmp	L872
	.p2align 2,,3
L876:
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	_VR+14(%edx), %cx
	movl	_RSP+12, %edx
	movw	%cx, 2(%edx,%eax)
	jmp	L872
	.cfi_endproc
LFE91:
	.section .rdata,"dr"
LC31:
	.ascii "MFC0\11$zero, rd\0"
LC32:
	.ascii "MFC0\12DMA_READ_LENGTH\0"
LC33:
	.ascii "MFC0\12DMA_WRITE_LENGTH\0"
LC34:
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
	je	L912
	cmpl	$15, 36(%esp)
	jbe	L913
L886:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L913:
	.cfi_restore_state
	movl	36(%esp), %eax
	jmp	*L905(,%eax,4)
	.section .rdata,"dr"
	.align 4
L905:
	.long	L889
	.long	L890
	.long	L891
	.long	L892
	.long	L893
	.long	L895
	.long	L895
	.long	L896
	.long	L897
	.long	L898
	.long	L899
	.long	L900
	.long	L901
	.long	L902
	.long	L903
	.long	L904
	.text
	.p2align 2,,3
L912:
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC31, 4(%esp)
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
L895:
	.cfi_restore_state
	movl	_RSP+44, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L903:
	movl	_RSP+84, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L896:
	movl	_RSP+56, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L897:
	movl	_RSP+60, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L898:
	movl	_RSP+64, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L899:
	movl	_RSP+68, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L900:
	movl	_RSP+72, %eax
	movl	(%eax), %eax
	testb	$6, %ah
	je	L911
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC34, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+72, %edx
	movl	(%edx), %eax
	andb	$249, %ah
	movl	%eax, (%edx)
	.p2align 2,,3
L911:
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L901:
	movl	_RSP+76, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L902:
	movl	_RSP+80, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L904:
	movl	_RSP+88, %eax
	movl	(%eax), %eax
	jmp	L911
	.p2align 2,,3
L889:
	movl	_RSP+24, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L890:
	movl	_RSP+28, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L891:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC32, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+32, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.p2align 2,,3
L892:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC33, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L886
	.p2align 2,,3
L893:
	movl	_RSP+40, %eax
	movl	(%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	jmp	L886
	.cfi_endproc
LFE20:
	.section .rdata,"dr"
LC35:
	.ascii "LRV\12Odd addr.\0"
LC36:
	.ascii "LRV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_LRV
	.def	_LRV;	.scl	2;	.type	32;	.endef
_LRV:
LFB79:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	36(%esp), %ecx
	testl	%ecx, %ecx
	jne	L915
	movl	40(%esp), %edx
	sall	$4, %edx
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$4080, %eax
	andl	$15, %edx
	cmpl	$14, %edx
	jbe	L927
L916:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC35, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	.p2align 2,,3
L914:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L927:
	.cfi_restore_state
	jmp	*L925(,%edx,4)
	.section .rdata,"dr"
	.align 4
L925:
	.long	L914
	.long	L916
	.long	L918
	.long	L916
	.long	L919
	.long	L916
	.long	L920
	.long	L916
	.long	L921
	.long	L916
	.long	L922
	.long	L916
	.long	L923
	.long	L916
	.long	L924
	.text
	.p2align 2,,3
L915:
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
L924:
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
	jmp	L914
	.p2align 2,,3
L923:
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
	jmp	L914
	.p2align 2,,3
L922:
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
	jmp	L914
	.p2align 2,,3
L921:
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
	jmp	L914
	.p2align 2,,3
L920:
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+10(%edx)
	movw	(%ecx,%eax), %bx
	movw	%bx, _VR+12(%edx)
	movw	6(%ecx,%eax), %ax
	movw	%ax, _VR+14(%edx)
	jmp	L914
	.p2align 2,,3
L919:
	movl	_RSP+12, %ecx
	movl	32(%esp), %edx
	sall	$4, %edx
	movw	2(%ecx,%eax), %bx
	movw	%bx, _VR+12(%edx)
	movw	(%ecx,%eax), %ax
	movw	%ax, _VR+14(%edx)
	jmp	L914
	.p2align 2,,3
L918:
	movl	_RSP+12, %edx
	movw	2(%edx,%eax), %dx
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	%dx, _VR+14(%eax)
	jmp	L914
	.cfi_endproc
LFE79:
	.section .rdata,"dr"
LC37:
	.ascii "STV\12Illegal element.\0"
LC38:
	.ascii "STV\12Uncertain case!\0"
LC39:
	.ascii "STV\12Illegal addr.\0"
	.text
	.p2align 2,,3
	.globl	_STV
	.def	_STV;	.scl	2;	.type	32;	.endef
_STV:
LFB97:
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
	jne	L929
	testb	$7, %bl
	jne	L930
L931:
	andl	$4080, %esi
	cmpl	$14, 36(%esp)
	jbe	L944
L932:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC37, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L928
	.p2align 2,,3
L944:
	movl	36(%esp), %eax
	jmp	*L941(,%eax,4)
	.section .rdata,"dr"
	.align 4
L941:
	.long	L933
	.long	L932
	.long	L934
	.long	L932
	.long	L935
	.long	L932
	.long	L936
	.long	L932
	.long	L937
	.long	L932
	.long	L938
	.long	L932
	.long	L939
	.long	L932
	.long	L940
	.text
	.p2align 2,,3
L929:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC39, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
L928:
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
L930:
	.cfi_restore_state
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC38, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	andl	$24, %ebx
	jmp	L931
	.p2align 2,,3
L940:
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
	jmp	L928
	.p2align 2,,3
L939:
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
	jmp	L928
	.p2align 2,,3
L938:
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
	jmp	L928
	.p2align 2,,3
L937:
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
	jmp	L928
	.p2align 2,,3
L936:
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
	jmp	L928
	.p2align 2,,3
L935:
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
	jmp	L928
	.p2align 2,,3
L934:
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
	jmp	L928
	.p2align 2,,3
L933:
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
	jmp	L928
	.cfi_endproc
LFE97:
	.section .rdata,"dr"
LC40:
	.ascii "LTV\12Illegal element.\0"
LC41:
	.ascii "LTV\12Uncertain case!\0"
LC42:
	.ascii "LTV\12Illegal addr.\0"
	.text
	.p2align 2,,3
	.globl	_LTV
	.def	_LTV;	.scl	2;	.type	32;	.endef
_LTV:
LFB84:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %edx
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %ecx
	addl	_SR(,%ecx,4), %eax
	testb	$15, %al
	jne	L946
	testb	$7, %dl
	jne	L947
	andl	$4080, %eax
	cmpl	$14, 36(%esp)
	jbe	L960
L948:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC40, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L945
	.p2align 2,,3
L960:
	movl	36(%esp), %ecx
	jmp	*L957(,%ecx,4)
	.section .rdata,"dr"
	.align 4
L957:
	.long	L949
	.long	L948
	.long	L950
	.long	L948
	.long	L951
	.long	L948
	.long	L952
	.long	L948
	.long	L953
	.long	L948
	.long	L954
	.long	L948
	.long	L955
	.long	L948
	.long	L956
	.text
	.p2align 2,,3
L946:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC42, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
L945:
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
L956:
	.cfi_restore_state
	movl	_RSP+12, %ecx
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	2(%ecx,%eax), %si
	movw	%si, _VR+2(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	(%ecx,%eax), %si
	movw	%si, _VR+20(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	6(%ecx,%eax), %si
	movw	%si, _VR+38(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	4(%ecx,%eax), %si
	movw	%si, _VR+56(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	10(%ecx,%eax), %si
	movw	%si, _VR+74(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	8(%ecx,%eax), %si
	movw	%si, _VR+92(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	14(%ecx,%eax), %si
	movw	%si, _VR+110(%ebx)
	movw	12(%ecx,%eax), %ax
	movw	%ax, _VR+112(%ebx)
	jmp	L945
	.p2align 2,,3
L955:
	movl	_RSP+12, %ecx
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	2(%ecx,%eax), %si
	movw	%si, _VR+4(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	(%ecx,%eax), %si
	movw	%si, _VR+22(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	6(%ecx,%eax), %si
	movw	%si, _VR+40(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	4(%ecx,%eax), %si
	movw	%si, _VR+58(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	10(%ecx,%eax), %si
	movw	%si, _VR+76(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	8(%ecx,%eax), %si
	movw	%si, _VR+94(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	14(%ecx,%eax), %si
	movw	%si, _VR+96(%ebx)
	movw	12(%ecx,%eax), %ax
	movw	%ax, _VR+114(%ebx)
	jmp	L945
	.p2align 2,,3
L954:
	movl	_RSP+12, %ecx
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	2(%ecx,%eax), %si
	movw	%si, _VR+6(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	(%ecx,%eax), %si
	movw	%si, _VR+24(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	6(%ecx,%eax), %si
	movw	%si, _VR+42(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	4(%ecx,%eax), %si
	movw	%si, _VR+60(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	10(%ecx,%eax), %si
	movw	%si, _VR+78(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	8(%ecx,%eax), %si
	movw	%si, _VR+80(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	14(%ecx,%eax), %si
	movw	%si, _VR+98(%ebx)
	movw	12(%ecx,%eax), %ax
	movw	%ax, _VR+116(%ebx)
	jmp	L945
	.p2align 2,,3
L953:
	movl	_RSP+12, %ecx
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	2(%ecx,%eax), %si
	movw	%si, _VR+8(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	(%ecx,%eax), %si
	movw	%si, _VR+26(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	6(%ecx,%eax), %si
	movw	%si, _VR+44(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	4(%ecx,%eax), %si
	movw	%si, _VR+62(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	10(%ecx,%eax), %si
	movw	%si, _VR+64(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	8(%ecx,%eax), %si
	movw	%si, _VR+82(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	14(%ecx,%eax), %si
	movw	%si, _VR+100(%ebx)
	movw	12(%ecx,%eax), %ax
	movw	%ax, _VR+118(%ebx)
	jmp	L945
	.p2align 2,,3
L952:
	movl	_RSP+12, %ecx
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	2(%ecx,%eax), %si
	movw	%si, _VR+10(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	(%ecx,%eax), %si
	movw	%si, _VR+28(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	6(%ecx,%eax), %si
	movw	%si, _VR+46(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	4(%ecx,%eax), %si
	movw	%si, _VR+48(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	10(%ecx,%eax), %si
	movw	%si, _VR+66(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	8(%ecx,%eax), %si
	movw	%si, _VR+84(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	14(%ecx,%eax), %si
	movw	%si, _VR+102(%ebx)
	movw	12(%ecx,%eax), %ax
	movw	%ax, _VR+120(%ebx)
	jmp	L945
	.p2align 2,,3
L951:
	movl	_RSP+12, %ecx
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	2(%ecx,%eax), %si
	movw	%si, _VR+12(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	(%ecx,%eax), %si
	movw	%si, _VR+30(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	6(%ecx,%eax), %si
	movw	%si, _VR+32(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	4(%ecx,%eax), %si
	movw	%si, _VR+50(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	10(%ecx,%eax), %si
	movw	%si, _VR+68(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	8(%ecx,%eax), %si
	movw	%si, _VR+86(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	14(%ecx,%eax), %si
	movw	%si, _VR+104(%ebx)
	movw	12(%ecx,%eax), %ax
	movw	%ax, _VR+122(%ebx)
	jmp	L945
	.p2align 2,,3
L950:
	movl	_RSP+12, %ecx
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	2(%ecx,%eax), %si
	movw	%si, _VR+14(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	(%ecx,%eax), %si
	movw	%si, _VR+16(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	6(%ecx,%eax), %si
	movw	%si, _VR+34(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	4(%ecx,%eax), %si
	movw	%si, _VR+52(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	10(%ecx,%eax), %si
	movw	%si, _VR+70(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	8(%ecx,%eax), %si
	movw	%si, _VR+88(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	14(%ecx,%eax), %si
	movw	%si, _VR+106(%ebx)
	movw	12(%ecx,%eax), %ax
	movw	%ax, _VR+124(%ebx)
	jmp	L945
	.p2align 2,,3
L949:
	movl	_RSP+12, %ecx
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	2(%ecx,%eax), %si
	movw	%si, _VR(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	(%ecx,%eax), %si
	movw	%si, _VR+18(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	6(%ecx,%eax), %si
	movw	%si, _VR+36(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	4(%ecx,%eax), %si
	movw	%si, _VR+54(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	10(%ecx,%eax), %si
	movw	%si, _VR+72(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	8(%ecx,%eax), %si
	movw	%si, _VR+90(%ebx)
	movl	%edx, %ebx
	sall	$4, %ebx
	movw	14(%ecx,%eax), %si
	movw	%si, _VR+108(%ebx)
	movw	12(%ecx,%eax), %ax
	movw	%ax, _VR+126(%ebx)
	jmp	L945
	.p2align 2,,3
L947:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC41, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	addl	$20, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE84:
	.section .rdata,"dr"
LC43:
	.ascii "SLV\12Weird addr.\0"
LC44:
	.ascii "SLV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_SLV
	.def	_SLV;	.scl	2;	.type	32;	.endef
_SLV:
LFB88:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	36(%esp), %eax
	movl	44(%esp), %edx
	movl	_SR(,%edx,4), %edx
	cmpl	$12, %eax
	jg	L962
	movl	40(%esp), %ecx
	leal	(%edx,%ecx,4), %edx
	movl	%edx, %ecx
	andl	$4095, %ecx
	andl	$3, %edx
	cmpl	$2, %edx
	je	L965
	cmpl	$3, %edx
	je	L964
	decl	%edx
	je	L964
	movl	_RSP+12, %ebx
	movl	32(%esp), %esi
	sall	$4, %esi
	leal	1(%eax), %edx
	andl	$-2, %edx
	movw	_VR(%esi,%edx), %dx
	movw	%dx, 2(%ebx,%ecx)
	addl	$3, %eax
	andl	$-2, %eax
	movw	_VR(%esi,%eax), %ax
	movw	%ax, (%ebx,%ecx)
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
L962:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC44, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
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
L964:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC43, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
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
L965:
	.cfi_restore_state
	movl	_RSP+12, %ebx
	movl	32(%esp), %esi
	sall	$4, %esi
	leal	1(%eax), %edx
	andl	$-2, %edx
	movw	_VR(%esi,%edx), %dx
	movw	%dx, -2(%ebx,%ecx)
	addl	$4, %ecx
	addl	$3, %eax
	andl	$-2, %eax
	movw	_VR(%esi,%eax), %ax
	andl	$4095, %ecx
	movw	%ax, (%ebx,%ecx)
	addl	$20, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE88:
	.section .rdata,"dr"
LC45:
	.ascii "SQV\12Weird addr.\0"
LC46:
	.ascii "SQV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_SQV
	.def	_SQV;	.scl	2;	.type	32;	.endef
_SQV:
LFB90:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	36(%esp), %ebx
	testl	%ebx, %ebx
	jne	L975
	movl	40(%esp), %edx
	sall	$4, %edx
	addl	%eax, %edx
	movl	%edx, %eax
	andl	$4080, %eax
	andl	$15, %edx
	cmpl	$2, %edx
	je	L978
	jle	L984
	cmpl	$4, %edx
	je	L979
	cmpl	$6, %edx
	je	L985
L976:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC45, 4(%esp)
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
L984:
	.cfi_restore_state
	testl	%edx, %edx
	jne	L976
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR(%ecx), %ebx
	movw	%bx, 2(%edx,%eax)
	movw	_VR+2(%ecx), %bx
	movw	%bx, (%edx,%eax)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 6(%edx,%eax)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 4(%edx,%eax)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 10(%edx,%eax)
	movw	_VR+10(%ecx), %bx
	movw	%bx, 8(%edx,%eax)
	movl	_VR+12(%ecx), %ebx
	movw	%bx, 14(%edx,%eax)
	movw	_VR+14(%ecx), %cx
	movw	%cx, 12(%edx,%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L975:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC46, 4(%esp)
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
L979:
	.cfi_restore_state
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR(%ecx), %ebx
	movw	%bx, 6(%edx,%eax)
	movw	_VR+2(%ecx), %bx
	movw	%bx, 4(%edx,%eax)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 10(%edx,%eax)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 8(%edx,%eax)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 14(%edx,%eax)
	movw	_VR+10(%ecx), %cx
	movw	%cx, 12(%edx,%eax)
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
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR(%ecx), %ebx
	movw	%bx, (%edx,%eax)
	movw	_VR+2(%ecx), %bx
	movw	%bx, 6(%edx,%eax)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 4(%edx,%eax)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 10(%edx,%eax)
	movl	_VR+8(%ecx), %ebx
	movw	%bx, 8(%edx,%eax)
	movw	_VR+10(%ecx), %bx
	movw	%bx, 14(%edx,%eax)
	movl	_VR+12(%ecx), %ecx
	movw	%cx, 12(%edx,%eax)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L985:
	.cfi_restore_state
	movl	_RSP+12, %edx
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	_VR(%ecx), %ebx
	movw	%bx, 4(%edx,%eax)
	movw	_VR+2(%ecx), %bx
	movw	%bx, 10(%edx,%eax)
	movl	_VR+4(%ecx), %ebx
	movw	%bx, 8(%edx,%eax)
	movw	_VR+6(%ecx), %bx
	movw	%bx, 14(%edx,%eax)
	movl	_VR+8(%ecx), %ecx
	movw	%cx, 12(%edx,%eax)
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE90:
	.section .rdata,"dr"
LC47:
	.ascii "SUV\12Weird addr.\0"
LC48:
	.ascii "SUV\12Illegal element.\0"
	.text
	.p2align 2,,3
	.globl	_SUV
	.def	_SUV;	.scl	2;	.type	32;	.endef
_SUV:
LFB93:
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
	cmpl	$15, 36(%esp)
	je	L987
	testb	$7, %al
	jne	L991
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
L991:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC47, 4(%esp)
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
L987:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC48, 4(%esp)
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
LFE93:
	.section .rdata,"dr"
LC49:
	.ascii "LQV\12Odd addr.\0"
	.text
	.p2align 2,,3
	.globl	_LQV
	.def	_LQV;	.scl	2;	.type	32;	.endef
_LQV:
LFB78:
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
	movl	36(%esp), %edx
	movl	40(%esp), %eax
	sall	$4, %eax
	movl	44(%esp), %ecx
	addl	_SR(,%ecx,4), %eax
	movl	%eax, %ecx
	andl	$4080, %ecx
	andl	$15, %eax
	cmpl	$14, %eax
	jbe	L1006
L994:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC49, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
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
L1006:
	.cfi_restore_state
	jmp	*L1003(,%eax,4)
	.section .rdata,"dr"
	.align 4
L1003:
	.long	L995
	.long	L994
	.long	L996
	.long	L994
	.long	L997
	.long	L994
	.long	L998
	.long	L994
	.long	L999
	.long	L994
	.long	L1000
	.long	L994
	.long	L1001
	.long	L994
	.long	L1002
	.text
	.p2align 2,,3
L1002:
	movl	_RSP+12, %eax
	movw	12(%eax,%ecx), %cx
	incl	%edx
	andl	$-2, %edx
	movl	32(%esp), %eax
	sall	$4, %eax
	movw	%cx, _VR(%edx,%eax)
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
L995:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movl	_RSP+12, %ebx
	leal	1(%edx), %esi
	andl	$-2, %esi
	movw	2(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	3(%edx), %esi
	andl	$-2, %esi
	movw	(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	5(%edx), %esi
	andl	$-2, %esi
	movw	6(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	7(%edx), %esi
	andl	$-2, %esi
	movw	4(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	9(%edx), %esi
	andl	$-2, %esi
	movw	10(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	11(%edx), %esi
	andl	$-2, %esi
	movw	8(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	13(%edx), %esi
	andl	$-2, %esi
	movw	14(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	movw	12(%ebx,%ecx), %cx
	addl	$15, %edx
	andl	$-2, %edx
	movw	%cx, _VR(%eax,%edx)
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
L996:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movl	_RSP+12, %ebx
	leal	1(%edx), %esi
	andl	$-2, %esi
	movw	(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	3(%edx), %esi
	andl	$-2, %esi
	movw	6(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	5(%edx), %esi
	andl	$-2, %esi
	movw	4(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	7(%edx), %esi
	andl	$-2, %esi
	movw	10(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	9(%edx), %esi
	andl	$-2, %esi
	movw	8(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	11(%edx), %esi
	andl	$-2, %esi
	movw	14(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	movw	12(%ebx,%ecx), %cx
	addl	$13, %edx
	andl	$-2, %edx
	movw	%cx, _VR(%eax,%edx)
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
L997:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movl	_RSP+12, %ebx
	leal	1(%edx), %esi
	andl	$-2, %esi
	movw	6(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	3(%edx), %esi
	andl	$-2, %esi
	movw	4(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	5(%edx), %esi
	andl	$-2, %esi
	movw	10(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	7(%edx), %esi
	andl	$-2, %esi
	movw	8(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	9(%edx), %esi
	andl	$-2, %esi
	movw	14(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	movw	12(%ebx,%ecx), %cx
	addl	$11, %edx
	andl	$-2, %edx
	movw	%cx, _VR(%eax,%edx)
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
L998:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movl	_RSP+12, %ebx
	leal	1(%edx), %esi
	andl	$-2, %esi
	movw	4(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	3(%edx), %esi
	andl	$-2, %esi
	movw	10(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	5(%edx), %esi
	andl	$-2, %esi
	movw	8(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	7(%edx), %esi
	andl	$-2, %esi
	movw	14(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	movw	12(%ebx,%ecx), %cx
	addl	$9, %edx
	andl	$-2, %edx
	movw	%cx, _VR(%eax,%edx)
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
L999:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movl	_RSP+12, %ebx
	leal	1(%edx), %esi
	andl	$-2, %esi
	movw	10(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	3(%edx), %esi
	andl	$-2, %esi
	movw	8(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	5(%edx), %esi
	andl	$-2, %esi
	movw	14(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	movw	12(%ebx,%ecx), %cx
	addl	$7, %edx
	andl	$-2, %edx
	movw	%cx, _VR(%eax,%edx)
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
L1000:
	.cfi_restore_state
	movl	32(%esp), %eax
	sall	$4, %eax
	movl	_RSP+12, %ebx
	leal	1(%edx), %esi
	andl	$-2, %esi
	movw	8(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	leal	3(%edx), %esi
	andl	$-2, %esi
	movw	14(%ebx,%ecx), %di
	movw	%di, _VR(%eax,%esi)
	movw	12(%ebx,%ecx), %cx
	addl	$5, %edx
	andl	$-2, %edx
	movw	%cx, _VR(%eax,%edx)
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
L1001:
	.cfi_restore_state
	movl	32(%esp), %ebx
	sall	$4, %ebx
	movl	_RSP+12, %esi
	leal	1(%edx), %eax
	andl	$-2, %eax
	movw	14(%esi,%ecx), %di
	movw	%di, _VR(%ebx,%eax)
	movw	12(%esi,%ecx), %ax
	addl	$3, %edx
	andl	$-2, %edx
	movw	%ax, _VR(%ebx,%edx)
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
LFE78:
	.section .rdata,"dr"
LC50:
	.ascii "SDV\12Odd addr.\0"
	.text
	.p2align 2,,3
	.globl	_SDV
	.def	_SDV;	.scl	2;	.type	32;	.endef
_SDV:
LFB89:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	44(%esp), %eax
	movl	_SR(,%eax,4), %eax
	movl	40(%esp), %edx
	leal	(%eax,%edx,8), %eax
	movl	%eax, %edx
	andl	$4095, %edx
	andl	$7, %eax
	jmp	*L1016(,%eax,4)
	.section .rdata,"dr"
	.align 4
L1016:
	.long	L1008
	.long	L1015
	.long	L1010
	.long	L1015
	.long	L1012
	.long	L1015
	.long	L1014
	.long	L1015
	.text
	.p2align 2,,3
L1015:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC50, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
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
L1012:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	36(%esp), %ebx
	incl	%ebx
	andl	$-2, %ebx
	movw	_VR(%ecx,%ebx), %bx
	movw	%bx, 2(%eax,%edx)
	movl	36(%esp), %ebx
	addl	$2, %ebx
	andl	$15, %ebx
	leal	1(%ebx), %esi
	andl	$-2, %esi
	movw	_VR(%ecx,%esi), %si
	movw	%si, (%eax,%edx)
	addl	$2, %ebx
	andl	$15, %ebx
	addl	$4, %edx
	andl	$4095, %edx
	leal	1(%ebx), %esi
	andl	$-2, %esi
	movw	_VR(%ecx,%esi), %si
	movw	%si, 2(%eax,%edx)
	addl	$2, %ebx
	andl	$15, %ebx
	incl	%ebx
	andl	$-2, %ebx
	movw	_VR(%ecx,%ebx), %cx
	movw	%cx, (%eax,%edx)
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
L1008:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	36(%esp), %ebx
	incl	%ebx
	andl	$-2, %ebx
	movw	_VR(%ecx,%ebx), %bx
	movw	%bx, 2(%eax,%edx)
	movl	36(%esp), %ebx
	addl	$2, %ebx
	andl	$15, %ebx
	leal	1(%ebx), %esi
	andl	$-2, %esi
	movw	_VR(%ecx,%esi), %si
	movw	%si, (%eax,%edx)
	addl	$2, %ebx
	andl	$15, %ebx
	leal	1(%ebx), %esi
	andl	$-2, %esi
	movw	_VR(%ecx,%esi), %si
	movw	%si, 6(%eax,%edx)
	addl	$2, %ebx
	andl	$15, %ebx
	incl	%ebx
	andl	$-2, %ebx
	movw	_VR(%ecx,%ebx), %cx
	movw	%cx, 4(%eax,%edx)
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
L1014:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	36(%esp), %ebx
	incl	%ebx
	andl	$-2, %ebx
	movw	_VR(%ecx,%ebx), %bx
	movw	%bx, -2(%eax,%edx)
	movl	36(%esp), %ebx
	addl	$2, %ebx
	andl	$15, %ebx
	addl	$2, %edx
	andl	$4095, %edx
	leal	1(%ebx), %esi
	andl	$-2, %esi
	movw	_VR(%ecx,%esi), %si
	movw	%si, 2(%eax,%edx)
	addl	$2, %ebx
	andl	$15, %ebx
	leal	1(%ebx), %esi
	andl	$-2, %esi
	movw	_VR(%ecx,%esi), %si
	movw	%si, (%eax,%edx)
	addl	$2, %ebx
	andl	$15, %ebx
	incl	%ebx
	andl	$-2, %ebx
	movw	_VR(%ecx,%ebx), %cx
	movw	%cx, 6(%eax,%edx)
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
L1010:
	.cfi_restore_state
	movl	_RSP+12, %eax
	movl	32(%esp), %ecx
	sall	$4, %ecx
	movl	36(%esp), %ebx
	incl	%ebx
	andl	$-2, %ebx
	movw	_VR(%ecx,%ebx), %bx
	movw	%bx, -2(%eax,%edx)
	movl	36(%esp), %ebx
	addl	$2, %ebx
	andl	$15, %ebx
	leal	1(%ebx), %esi
	andl	$-2, %esi
	movw	_VR(%ecx,%esi), %si
	movw	%si, 4(%eax,%edx)
	addl	$2, %ebx
	andl	$15, %ebx
	leal	1(%ebx), %esi
	andl	$-2, %esi
	movw	_VR(%ecx,%esi), %si
	movw	%si, 2(%eax,%edx)
	addl	$2, %ebx
	addl	$8, %edx
	andl	$15, %ebx
	incl	%ebx
	andl	$-2, %ebx
	movw	_VR(%ecx,%ebx), %cx
	andl	$4095, %edx
	movw	%cx, (%eax,%edx)
	addl	$20, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE89:
	.p2align 2,,3
	.def	_VMADM;	.scl	3;	.type	32;	.endef
_VMADM:
LFB43:
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
	movl	96(%esp), %eax
	movl	100(%esp), %ecx
	movl	108(%esp), %edx
	sall	$4, %ecx
	movswl	_VR(%ecx), %esi
	sall	$5, %edx
	movl	104(%esp), %ebx
	sall	$3, %ebx
	movl	_ei(%edx), %edi
	addl	%ebx, %edi
	movzwl	_VR(%edi,%edi), %edi
	imull	%edi, %esi
	movl	%esi, 8(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 12(%esp)
	movl	_VACC, %esi
	movl	_VACC+4, %edi
	addl	%esi, 8(%esp)
	adcl	%edi, 12(%esp)
	movl	8(%esp), %edi
	movl	%edi, 4(%esp)
	movl	8(%esp), %esi
	movl	12(%esp), %edi
	movl	%esi, _VACC
	movl	%edi, _VACC+4
	movswl	_VR+2(%ecx), %esi
	movl	_ei+4(%edx), %ebp
	addl	%ebx, %ebp
	movzwl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %esi
	movl	%esi, 16(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 20(%esp)
	movl	_VACC+8, %esi
	movl	_VACC+12, %edi
	addl	%esi, 16(%esp)
	adcl	%edi, 20(%esp)
	movl	16(%esp), %esi
	movl	20(%esp), %edi
	movl	%esi, _VACC+8
	movl	%edi, _VACC+12
	movswl	_VR+4(%ecx), %esi
	movl	_ei+8(%edx), %ebp
	addl	%ebx, %ebp
	movzwl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %esi
	movl	%esi, 24(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 28(%esp)
	movl	_VACC+16, %esi
	movl	_VACC+20, %edi
	addl	%esi, 24(%esp)
	adcl	%edi, 28(%esp)
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	movl	%esi, _VACC+16
	movl	%edi, _VACC+20
	movswl	_VR+6(%ecx), %esi
	movl	_ei+12(%edx), %ebp
	addl	%ebx, %ebp
	movzwl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %esi
	movl	%esi, 32(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 36(%esp)
	movl	_VACC+24, %esi
	movl	_VACC+28, %edi
	addl	%esi, 32(%esp)
	adcl	%edi, 36(%esp)
	movl	32(%esp), %esi
	movl	36(%esp), %edi
	movl	%esi, _VACC+24
	movl	%edi, _VACC+28
	movswl	_VR+8(%ecx), %esi
	movl	_ei+16(%edx), %ebp
	addl	%ebx, %ebp
	movzwl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %esi
	movl	%esi, 40(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 44(%esp)
	movl	_VACC+32, %esi
	movl	_VACC+36, %edi
	addl	%esi, 40(%esp)
	adcl	%edi, 44(%esp)
	movl	40(%esp), %esi
	movl	44(%esp), %edi
	movl	%esi, _VACC+32
	movl	%edi, _VACC+36
	movswl	_VR+10(%ecx), %esi
	movl	_ei+20(%edx), %ebp
	addl	%ebx, %ebp
	movzwl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %esi
	movl	%esi, 48(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 52(%esp)
	movl	_VACC+40, %esi
	movl	_VACC+44, %edi
	addl	%esi, 48(%esp)
	adcl	%edi, 52(%esp)
	movl	48(%esp), %esi
	movl	52(%esp), %edi
	movl	%esi, _VACC+40
	movl	%edi, _VACC+44
	movswl	_VR+12(%ecx), %esi
	movl	_ei+24(%edx), %ebp
	addl	%ebx, %ebp
	movzwl	_VR(%ebp,%ebp), %ebp
	imull	%ebp, %esi
	movl	%esi, 56(%esp)
	movl	%esi, %edi
	sarl	$31, %edi
	movl	%edi, 60(%esp)
	movl	_VACC+48, %esi
	movl	_VACC+52, %edi
	addl	%esi, 56(%esp)
	adcl	%edi, 60(%esp)
	movl	56(%esp), %esi
	movl	60(%esp), %edi
	movl	%esi, _VACC+48
	movl	%edi, _VACC+52
	movswl	_VR+14(%ecx), %ecx
	addl	_ei+28(%edx), %ebx
	movzwl	_VR(%ebx,%ebx), %edx
	imull	%edx, %ecx
	movl	%ecx, 64(%esp)
	movl	%ecx, %edi
	sarl	$31, %edi
	movl	%edi, 68(%esp)
	movl	_VACC+56, %edx
	movl	_VACC+60, %ecx
	addl	%edx, 64(%esp)
	adcl	%ecx, 68(%esp)
	movl	64(%esp), %ecx
	movl	68(%esp), %ebx
	movl	%ecx, _VACC+56
	movl	%ebx, _VACC+60
	movl	4(%esp), %edi
	movl	_VACC+4, %edx
	andl	$-2147483648, %edi
	testb	$128, %dh
	jne	L1020
	andl	$65535, %edx
	orl	%edi, %edx
	movl	%eax, %edx
	je	L1077
	sall	$4, %edx
	movw	$32767, _VR(%edx)
	jmp	L1022
	.p2align 2,,3
L1020:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %edi
	orl	%edi, %edx
	movl	%eax, %edx
	je	L1077
	sall	$4, %edx
	movw	$-32768, _VR(%edx)
L1022:
	movl	_VACC+8, %ecx
	movl	_VACC+12, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L1024
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1078
	sall	$4, %edx
	movw	$32767, _VR+2(%edx)
L1026:
	movl	_VACC+16, %ecx
	movl	_VACC+20, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L1028
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1079
	sall	$4, %edx
	movw	$32767, _VR+4(%edx)
L1030:
	movl	_VACC+24, %ecx
	movl	_VACC+28, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L1032
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1080
	sall	$4, %edx
	movw	$32767, _VR+6(%edx)
L1034:
	movl	_VACC+32, %ecx
	movl	_VACC+36, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L1036
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1081
	sall	$4, %edx
	movw	$32767, _VR+8(%edx)
L1038:
	movl	_VACC+40, %ecx
	movl	_VACC+44, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L1040
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1082
	sall	$4, %edx
	movw	$32767, _VR+10(%edx)
L1042:
	movl	_VACC+48, %ecx
	movl	_VACC+52, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	jne	L1044
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1083
	sall	$4, %edx
	movw	$32767, _VR+12(%edx)
L1046:
	movl	_VACC+56, %ecx
	movl	_VACC+60, %edx
	andl	$-2147483648, %ecx
	testb	$128, %dh
	je	L1048
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1051
	sall	$4, %edx
	movw	$-32768, _VR+14(%edx)
L1050:
	movl	8(%esp), %ecx
	movl	12(%esp), %ebx
	shrdl	$16, %ebx, %ecx
	cmpl	$-32768, %ecx
	jl	L1052
	cmpl	$32767, %ecx
	movl	%eax, %edx
	jg	L1053
	sall	$4, %edx
	movw	%cx, _VR(%edx)
L1054:
	movl	16(%esp), %esi
	movl	20(%esp), %edi
	shrdl	$16, %edi, %esi
	cmpl	$-32768, %esi
	jl	L1055
	cmpl	$32767, %esi
	movl	%eax, %edx
	jg	L1056
	sall	$4, %edx
	movw	%si, _VR+2(%edx)
L1057:
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	shrdl	$16, %edi, %esi
	cmpl	$-32768, %esi
	jl	L1058
	cmpl	$32767, %esi
	movl	%eax, %edx
	jg	L1059
	sall	$4, %edx
	movw	%si, _VR+4(%edx)
L1060:
	movl	32(%esp), %esi
	movl	36(%esp), %edi
	shrdl	$16, %edi, %esi
	cmpl	$-32768, %esi
	jl	L1061
	cmpl	$32767, %esi
	movl	%eax, %edx
	jg	L1062
	sall	$4, %edx
	movw	%si, _VR+6(%edx)
L1063:
	movl	40(%esp), %esi
	movl	44(%esp), %edi
	shrdl	$16, %edi, %esi
	cmpl	$-32768, %esi
	jl	L1064
	cmpl	$32767, %esi
	movl	%eax, %edx
	jg	L1065
	sall	$4, %edx
	movw	%si, _VR+8(%edx)
L1066:
	movl	48(%esp), %esi
	movl	52(%esp), %edi
	shrdl	$16, %edi, %esi
	cmpl	$-32768, %esi
	jl	L1067
	cmpl	$32767, %esi
	movl	%eax, %edx
	jg	L1068
	sall	$4, %edx
	movw	%si, _VR+10(%edx)
L1069:
	movl	56(%esp), %esi
	movl	60(%esp), %edi
	shrdl	$16, %edi, %esi
	cmpl	$-32768, %esi
	jl	L1070
	cmpl	$32767, %esi
	movl	%eax, %edx
	jg	L1071
	sall	$4, %edx
	movw	%si, _VR+12(%edx)
L1072:
	movl	64(%esp), %ecx
	movl	68(%esp), %ebx
	shrdl	$16, %ebx, %ecx
	sall	$4, %eax
	cmpl	$-32768, %ecx
	jge	L1073
	movw	$-32768, _VR+14(%eax)
	addl	$76, %esp
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
L1077:
	.cfi_restore_state
	sall	$4, %edx
	movw	_VACC+2, %cx
	movw	%cx, _VR(%edx)
	jmp	L1022
	.p2align 2,,3
L1073:
	cmpl	$32767, %ecx
	jle	L1075
	movw	$32767, _VR+14(%eax)
	addl	$76, %esp
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
L1070:
	.cfi_restore_state
	movl	%eax, %edx
	sall	$4, %edx
	movw	$-32768, _VR+12(%edx)
	jmp	L1072
	.p2align 2,,3
L1067:
	movl	%eax, %edx
	sall	$4, %edx
	movw	$-32768, _VR+10(%edx)
	jmp	L1069
	.p2align 2,,3
L1064:
	movl	%eax, %edx
	sall	$4, %edx
	movw	$-32768, _VR+8(%edx)
	jmp	L1066
	.p2align 2,,3
L1061:
	movl	%eax, %edx
	sall	$4, %edx
	movw	$-32768, _VR+6(%edx)
	jmp	L1063
	.p2align 2,,3
L1058:
	movl	%eax, %edx
	sall	$4, %edx
	movw	$-32768, _VR+4(%edx)
	jmp	L1060
	.p2align 2,,3
L1055:
	movl	%eax, %edx
	sall	$4, %edx
	movw	$-32768, _VR+2(%edx)
	jmp	L1057
	.p2align 2,,3
L1052:
	movl	%eax, %edx
	sall	$4, %edx
	movw	$-32768, _VR(%edx)
	jmp	L1054
	.p2align 2,,3
L1048:
	andl	$65535, %edx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1051
	sall	$4, %edx
	movw	$32767, _VR+14(%edx)
	jmp	L1050
	.p2align 2,,3
L1044:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1083
	sall	$4, %edx
	movw	$-32768, _VR+12(%edx)
	jmp	L1046
	.p2align 2,,3
L1040:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1082
	sall	$4, %edx
	movw	$-32768, _VR+10(%edx)
	jmp	L1042
	.p2align 2,,3
L1036:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1081
	sall	$4, %edx
	movw	$-32768, _VR+8(%edx)
	jmp	L1038
	.p2align 2,,3
L1032:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1080
	sall	$4, %edx
	movw	$-32768, _VR+6(%edx)
	jmp	L1034
	.p2align 2,,3
L1028:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1079
	sall	$4, %edx
	movw	$-32768, _VR+4(%edx)
	jmp	L1030
	.p2align 2,,3
L1024:
	andl	$65535, %edx
	xorl	$65535, %edx
	addl	$-2147483648, %ecx
	orl	%ecx, %edx
	movl	%eax, %edx
	je	L1078
	sall	$4, %edx
	movw	$-32768, _VR+2(%edx)
	jmp	L1026
	.p2align 2,,3
L1078:
	sall	$4, %edx
	movw	_VACC+10, %cx
	movw	%cx, _VR+2(%edx)
	jmp	L1026
	.p2align 2,,3
L1080:
	sall	$4, %edx
	movw	_VACC+26, %cx
	movw	%cx, _VR+6(%edx)
	jmp	L1034
	.p2align 2,,3
L1079:
	sall	$4, %edx
	movw	_VACC+18, %cx
	movw	%cx, _VR+4(%edx)
	jmp	L1030
	.p2align 2,,3
L1051:
	sall	$4, %edx
	movw	_VACC+58, %cx
	movw	%cx, _VR+14(%edx)
	jmp	L1050
	.p2align 2,,3
L1083:
	sall	$4, %edx
	movw	_VACC+50, %cx
	movw	%cx, _VR+12(%edx)
	jmp	L1046
	.p2align 2,,3
L1082:
	sall	$4, %edx
	movw	_VACC+42, %cx
	movw	%cx, _VR+10(%edx)
	jmp	L1042
	.p2align 2,,3
L1081:
	sall	$4, %edx
	movw	_VACC+34, %cx
	movw	%cx, _VR+8(%edx)
	jmp	L1038
	.p2align 2,,3
L1071:
	sall	$4, %edx
	movw	$32767, _VR+12(%edx)
	jmp	L1072
	.p2align 2,,3
L1075:
	movw	%cx, _VR+14(%eax)
	addl	$76, %esp
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
L1068:
	.cfi_restore_state
	sall	$4, %edx
	movw	$32767, _VR+10(%edx)
	jmp	L1069
	.p2align 2,,3
L1065:
	sall	$4, %edx
	movw	$32767, _VR+8(%edx)
	jmp	L1066
	.p2align 2,,3
L1062:
	sall	$4, %edx
	movw	$32767, _VR+6(%edx)
	jmp	L1063
	.p2align 2,,3
L1059:
	sall	$4, %edx
	movw	$32767, _VR+4(%edx)
	jmp	L1060
	.p2align 2,,3
L1056:
	sall	$4, %edx
	movw	$32767, _VR+2(%edx)
	jmp	L1057
	.p2align 2,,3
L1053:
	sall	$4, %edx
	movw	$32767, _VR(%edx)
	jmp	L1054
	.cfi_endproc
LFE43:
	.p2align 2,,3
	.def	_VMUDH;	.scl	3;	.type	32;	.endef
_VMUDH:
LFB47:
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
	andl	$-2147483648, %ebp
	testb	$128, %ah
	jne	L1085
	andl	$65535, %eax
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L1118
	sall	$4, %eax
	movw	$32767, _VR(%eax)
	jmp	L1087
	.p2align 2,,3
L1085:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L1118
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
L1087:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1089
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1119
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
L1091:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1093
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1120
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
L1095:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1097
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1121
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
L1099:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1101
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1122
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
L1103:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1105
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1123
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
L1107:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1109
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1124
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
L1111:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	je	L1113
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L1116
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
L1118:
	.cfi_restore_state
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
	jmp	L1087
	.p2align 2,,3
L1113:
	andl	$65535, %eax
	sall	$4, %edi
	orl	%edx, %eax
	je	L1116
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
L1109:
	.cfi_restore_state
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1124
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L1111
	.p2align 2,,3
L1105:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1123
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L1107
	.p2align 2,,3
L1101:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1122
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L1103
	.p2align 2,,3
L1097:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1121
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L1099
	.p2align 2,,3
L1093:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1120
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L1095
	.p2align 2,,3
L1089:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1119
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L1091
	.p2align 2,,3
L1119:
	sall	$4, %eax
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
	jmp	L1091
	.p2align 2,,3
L1121:
	sall	$4, %eax
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
	jmp	L1099
	.p2align 2,,3
L1120:
	sall	$4, %eax
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
	jmp	L1095
	.p2align 2,,3
L1116:
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
L1124:
	.cfi_restore_state
	sall	$4, %eax
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
	jmp	L1111
	.p2align 2,,3
L1123:
	sall	$4, %eax
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
	jmp	L1107
	.p2align 2,,3
L1122:
	sall	$4, %eax
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
	jmp	L1103
	.cfi_endproc
LFE47:
	.p2align 2,,3
	.def	_VMADH;	.scl	3;	.type	32;	.endef
_VMADH:
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
	andl	$-2147483648, %ebp
	testb	$128, %ah
	jne	L1126
	andl	$65535, %eax
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L1159
	sall	$4, %eax
	movw	$32767, _VR(%eax)
	jmp	L1128
	.p2align 2,,3
L1126:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %ebp
	orl	%ebp, %eax
	movl	%edi, %eax
	je	L1159
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
L1128:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1130
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1160
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
L1132:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1134
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1161
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
L1136:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1138
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1162
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
L1140:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1142
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1163
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
L1144:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1146
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1164
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
L1148:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1150
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1165
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
L1152:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	je	L1154
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	sall	$4, %edi
	orl	%edx, %eax
	je	L1157
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
L1159:
	.cfi_restore_state
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
	jmp	L1128
	.p2align 2,,3
L1154:
	andl	$65535, %eax
	sall	$4, %edi
	orl	%edx, %eax
	je	L1157
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
L1150:
	.cfi_restore_state
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1165
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L1152
	.p2align 2,,3
L1146:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1164
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L1148
	.p2align 2,,3
L1142:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1163
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L1144
	.p2align 2,,3
L1138:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1162
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L1140
	.p2align 2,,3
L1134:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1161
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L1136
	.p2align 2,,3
L1130:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%edi, %eax
	je	L1160
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L1132
	.p2align 2,,3
L1160:
	sall	$4, %eax
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
	jmp	L1132
	.p2align 2,,3
L1162:
	sall	$4, %eax
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
	jmp	L1140
	.p2align 2,,3
L1161:
	sall	$4, %eax
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
	jmp	L1136
	.p2align 2,,3
L1157:
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
L1165:
	.cfi_restore_state
	sall	$4, %eax
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
	jmp	L1152
	.p2align 2,,3
L1164:
	sall	$4, %eax
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
	jmp	L1148
	.p2align 2,,3
L1163:
	sall	$4, %eax
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
	jmp	L1144
	.cfi_endproc
LFE41:
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
	je	L1166
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
L1166:
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
LC51:
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
	movl	$LC51, 4(%esp)
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
	.p2align 2,,3
	.globl	_SP_DMA_WRITE
	.def	_SP_DMA_WRITE;	.scl	2;	.type	32;	.endef
_SP_DMA_WRITE:
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
	pushl	%esi
	.cfi_def_cfa_offset 24
	movl	_RSP+36, %eax
	movl	(%eax), %eax
	movl	%eax, %edi
	andl	$4095, %edi
	movl	%eax, %ebx
	shrl	$12, %ebx
	andl	$255, %ebx
	leal	1(%ebx), %ebp
	shrl	$20, %eax
	incl	%edi
	addl	%edi, %eax
	movl	%eax, (%esp)
	movl	%ebx, %esi
	imull	%edi, %esi
	imull	%eax, %ebx
	.p2align 2,,3
L1176:
	decl	%ebp
	xorl	%ecx, %ecx
	.p2align 2,,3
L1175:
	movl	_RSP+28, %eax
	movl	(%eax), %eax
	addl	%ebx, %eax
	addl	%ecx, %eax
	andl	$16777215, %eax
	addl	_RSP+8, %eax
	movl	_RSP+24, %edx
	movl	(%edx), %edx
	addl	%esi, %edx
	addl	%ecx, %edx
	andl	$8191, %edx
	addl	_RSP+12, %edx
	movb	(%edx), %dl
	movb	%dl, (%eax)
	incl	%ecx
	cmpl	%ecx, %edi
	ja	L1175
	subl	%edi, %esi
	subl	(%esp), %ebx
	testl	%ebp, %ebp
	jne	L1176
	movl	_RSP+48, %eax
	movl	$0, (%eax)
	movl	_RSP+40, %eax
	andl	$-5, (%eax)
	popl	%ebx
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
LFE21:
	.p2align 2,,3
	.globl	_SP_DMA_READ
	.def	_SP_DMA_READ;	.scl	2;	.type	32;	.endef
_SP_DMA_READ:
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
	pushl	%ebp
	.cfi_def_cfa_offset 24
	movl	_RSP+32, %eax
	movl	(%eax), %eax
	movl	%eax, %edi
	andl	$4095, %edi
	movl	%eax, %ebx
	shrl	$12, %ebx
	andl	$255, %ebx
	leal	1(%ebx), %ebp
	shrl	$20, %eax
	incl	%edi
	addl	%edi, %eax
	movl	%eax, (%esp)
	movl	%ebx, %esi
	imull	%edi, %esi
	imull	%eax, %ebx
	.p2align 2,,3
L1182:
	decl	%ebp
	xorl	%ecx, %ecx
	.p2align 2,,3
L1181:
	movl	_RSP+24, %eax
	movl	(%eax), %eax
	addl	%esi, %eax
	addl	%ecx, %eax
	andl	$8191, %eax
	addl	_RSP+12, %eax
	movl	_RSP+28, %edx
	movl	(%edx), %edx
	addl	%ebx, %edx
	addl	%ecx, %edx
	andl	$16777215, %edx
	addl	_RSP+8, %edx
	movb	(%edx), %dl
	movb	%dl, (%eax)
	incl	%ecx
	cmpl	%ecx, %edi
	ja	L1181
	subl	%edi, %esi
	subl	(%esp), %ebx
	testl	%ebp, %ebp
	jne	L1182
	movl	_RSP+48, %eax
	movl	$0, (%eax)
	movl	_RSP+40, %eax
	andl	$-5, (%eax)
	popl	%edi
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
LFE22:
	.section .rdata,"dr"
LC52:
	.ascii "MTC0\12DMA_FULL\0"
LC53:
	.ascii "MTC0\12DMA_BUSY\0"
LC54:
	.ascii "MTC0\12CMD_START\0"
LC55:
	.ascii "MTC0\12CMD_END\0"
LC56:
	.ascii "MTC0\12CMD_CURRENT\0"
LC57:
	.ascii "MTC0\12CMD_STATUS\0"
LC58:
	.ascii "MTC0\12CMD_CLOCK\0"
LC59:
	.ascii "MTC0\12CMD_BUSY\0"
LC60:
	.ascii "MTC0\12CMD_PIPE_BUSY\0"
LC61:
	.ascii "MTC0\12CMD_TMEM_BUSY\0"
	.text
	.p2align 2,,3
	.globl	_MTC0
	.def	_MTC0;	.scl	2;	.type	32;	.endef
_MTC0:
LFB23:
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
	ja	L1186
	jmp	*L1204(,%eax,4)
	.section .rdata,"dr"
	.align 4
L1204:
	.long	L1188
	.long	L1189
	.long	L1190
	.long	L1191
	.long	L1192
	.long	L1193
	.long	L1194
	.long	L1195
	.long	L1196
	.long	L1197
	.long	L1198
	.long	L1199
	.long	L1200
	.long	L1201
	.long	L1202
	.long	L1203
	.text
	.p2align 2,,3
L1203:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC61, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	.p2align 2,,3
L1186:
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
L1202:
	.cfi_restore_state
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC60, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1186
	.p2align 2,,3
L1188:
	movl	_SR(,%ebx,4), %eax
	andl	$-8, %eax
	movl	_RSP+24, %edx
	movl	%eax, (%edx)
	jmp	L1186
	.p2align 2,,3
L1189:
	movl	_SR(,%ebx,4), %eax
	andl	$-8, %eax
	movl	_RSP+28, %edx
	movl	%eax, (%edx)
	jmp	L1186
	.p2align 2,,3
L1190:
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
L1191:
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
L1192:
	.cfi_restore_state
	movl	_RSP+40, %ecx
	movl	_SR(,%ebx,4), %eax
	movl	%eax, %edx
	andl	$1, %edx
	notl	%edx
	andl	(%ecx), %edx
	movl	%eax, %ebx
	shrl	%ebx
	andl	$1, %ebx
	orl	%ebx, %edx
	movl	%eax, %ebx
	andl	$4, %ebx
	cmpl	$1, %ebx
	sbbl	%ebx, %ebx
	orl	$-3, %ebx
	andl	%edx, %ebx
	movl	%ebx, (%ecx)
	movl	_RSP+20, %esi
	movl	%eax, %ebx
	andl	$16, %ebx
	sarl	$4, %ebx
	movl	%eax, %edx
	andl	$8, %edx
	sarl	$3, %edx
	notl	%edx
	andl	(%esi), %edx
	orl	%ebx, %edx
	movl	%edx, (%esi)
	movl	(%ecx), %edx
	orl	%ebx, %edx
	movl	%eax, %ebx
	andl	$32, %ebx
	notl	%ebx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	%ebx
	andl	$32, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$128, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-65, %edx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	$2, %ebx
	andl	$64, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$512, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-129, %edx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	$3, %ebx
	andl	$128, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$2048, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-257, %edx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	$4, %ebx
	andl	$256, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$8192, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-513, %edx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	$5, %ebx
	andl	$512, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$32768, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-1025, %edx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	$6, %ebx
	andl	$1024, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$131072, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-2049, %edx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	$7, %ebx
	andl	$2048, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$524288, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-4097, %edx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	$8, %ebx
	andl	$4096, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$2097152, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-8193, %edx
	andl	%ebx, %edx
	movl	%eax, %ebx
	shrl	$9, %ebx
	andl	$8192, %ebx
	orl	%edx, %ebx
	movl	%eax, %edx
	andl	$8388608, %edx
	cmpl	$1, %edx
	sbbl	%edx, %edx
	orl	$-16385, %edx
	andl	%ebx, %edx
	shrl	$10, %eax
	andl	$16384, %eax
	orl	%edx, %eax
	movl	%eax, (%ecx)
	jmp	L1186
	.p2align 2,,3
L1193:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC52, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1186
	.p2align 2,,3
L1194:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC53, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1186
	.p2align 2,,3
L1195:
	movl	_RSP+56, %eax
	movl	$0, (%eax)
	jmp	L1186
	.p2align 2,,3
L1196:
	movl	_RSP+80, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1265
L1225:
	movl	_SR(,%ebx,4), %eax
	movl	_RSP+60, %edx
	movl	%eax, (%edx)
	movl	_RSP+68, %edx
	movl	%eax, (%edx)
	movl	_RSP+64, %edx
	movl	%eax, (%edx)
	testb	$7, %al
	je	L1186
	movl	$32, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC54, 4(%esp)
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
	jmp	L1186
	.p2align 2,,3
L1197:
	movl	_RSP+80, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L1266
	movl	_SR(,%ebx,4), %eax
	andl	$-8, %eax
	movl	_RSP+64, %edx
	movl	%eax, (%edx)
	movl	_RSP+104, %eax
	testl	%eax, %eax
	je	L1186
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
L1198:
	.cfi_restore_state
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC56, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1186
	.p2align 2,,3
L1199:
	movl	_SR(,%ebx,4), %eax
	testl	$-640, %eax
	jne	L1267
L1229:
	movl	_RSP+72, %ebx
	movl	%eax, %edx
	andl	$1, %edx
	notl	%edx
	andl	(%ebx), %edx
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
	movl	%eax, %edx
	shrl	$2, %edx
	andl	$2, %edx
	orl	%ecx, %edx
	movl	%eax, %ecx
	andl	$16, %ecx
	cmpl	$1, %ecx
	sbbl	%ecx, %ecx
	orl	$-5, %ecx
	andl	%edx, %ecx
	movl	%eax, %edx
	shrl	$3, %edx
	andl	$4, %edx
	orl	%ecx, %edx
	movl	%edx, (%ebx)
	movl	_RSP+88, %ecx
	xorl	%edx, %edx
	testb	$64, %al
	sete	%dl
	negl	%edx
	andl	%edx, (%ecx)
	movl	_RSP+76, %edx
	testb	$2, %ah
	sete	%al
	movzbl	%al, %eax
	negl	%eax
	andl	%eax, (%edx)
	jmp	L1186
	.p2align 2,,3
L1200:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC58, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_SR(,%ebx,4), %edx
	movl	_RSP+76, %eax
	movl	%edx, (%eax)
	jmp	L1186
	.p2align 2,,3
L1201:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC59, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1186
	.p2align 2,,3
L1265:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC54, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1225
	.p2align 2,,3
L1267:
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC57, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_SR(,%ebx,4), %eax
	jmp	L1229
	.p2align 2,,3
L1266:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC55, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	jmp	L1186
	.cfi_endproc
LFE23:
	.p2align 2,,3
	.globl	_SIGNED_CLAMP
	.def	_SIGNED_CLAMP;	.scl	2;	.type	32;	.endef
_SIGNED_CLAMP:
LFB25:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ecx
	movl	12(%esp), %eax
	cmpl	$1, %eax
	je	L1271
	cmpl	$2, %eax
	je	L1272
	testl	%eax, %eax
	jne	L1268
	movl	_VACC, %edx
	movl	_VACC+4, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1273
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1363
	sall	$4, %eax
	movw	$32767, _VR(%eax)
L1275:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1277
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1364
	sall	$4, %eax
	movw	$32767, _VR+2(%eax)
L1279:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1281
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1365
	sall	$4, %eax
	movw	$32767, _VR+4(%eax)
L1283:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1285
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1366
	sall	$4, %eax
	movw	$32767, _VR+6(%eax)
L1287:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1289
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1367
	sall	$4, %eax
	movw	$32767, _VR+8(%eax)
L1291:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1293
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1368
	sall	$4, %eax
	movw	$32767, _VR+10(%eax)
L1295:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1297
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1369
	sall	$4, %eax
	movw	$32767, _VR+12(%eax)
L1299:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	je	L1301
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	sall	$4, %ecx
	orl	%edx, %eax
	je	L1304
L1377:
	movw	$-32768, _VR+14(%ecx)
L1268:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1272:
	.cfi_restore_state
	movl	_VACC, %eax
	movl	_VACC+4, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L1338
	cmpl	$32767, %eax
	jg	L1339
	movl	%ecx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR(%edx)
L1340:
	movl	_VACC+8, %eax
	movl	_VACC+12, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L1341
	cmpl	$32767, %eax
	jg	L1342
	movl	%ecx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+2(%edx)
L1343:
	movl	_VACC+16, %eax
	movl	_VACC+20, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L1344
	cmpl	$32767, %eax
	jg	L1345
	movl	%ecx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+4(%edx)
L1346:
	movl	_VACC+24, %eax
	movl	_VACC+28, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L1347
	cmpl	$32767, %eax
	jg	L1348
	movl	%ecx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+6(%edx)
L1349:
	movl	_VACC+32, %eax
	movl	_VACC+36, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L1350
	cmpl	$32767, %eax
	jg	L1351
	movl	%ecx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+8(%edx)
L1352:
	movl	_VACC+40, %eax
	movl	_VACC+44, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L1353
	cmpl	$32767, %eax
	jg	L1354
	movl	%ecx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+10(%edx)
L1355:
	movl	_VACC+48, %eax
	movl	_VACC+52, %edx
	shrdl	$17, %edx, %eax
	cmpl	$-32768, %eax
	jl	L1356
	cmpl	$32767, %eax
	jg	L1357
	movl	%ecx, %edx
	sall	$4, %edx
	andl	$-16, %eax
	movw	%ax, _VR+12(%edx)
L1358:
	movl	_VACC+56, %eax
	movl	_VACC+60, %edx
	shrdl	$17, %edx, %eax
	sall	$4, %ecx
	cmpl	$-32768, %eax
	jl	L1377
	cmpl	$32767, %eax
	jle	L1361
	movw	$32752, _VR+14(%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1271:
	.cfi_restore_state
	movl	_VACC, %edx
	movl	_VACC+4, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1305
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1370
	sall	$4, %eax
	movw	$-1, _VR(%eax)
L1307:
	movl	_VACC+8, %edx
	movl	_VACC+12, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1309
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1371
	sall	$4, %eax
	movw	$-1, _VR+2(%eax)
L1311:
	movl	_VACC+16, %edx
	movl	_VACC+20, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1313
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1372
	sall	$4, %eax
	movw	$-1, _VR+4(%eax)
L1315:
	movl	_VACC+24, %edx
	movl	_VACC+28, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1317
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1373
	sall	$4, %eax
	movw	$-1, _VR+6(%eax)
L1319:
	movl	_VACC+32, %edx
	movl	_VACC+36, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1321
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1374
	sall	$4, %eax
	movw	$-1, _VR+8(%eax)
L1323:
	movl	_VACC+40, %edx
	movl	_VACC+44, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1325
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1375
	sall	$4, %eax
	movw	$-1, _VR+10(%eax)
L1327:
	movl	_VACC+48, %edx
	movl	_VACC+52, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	jne	L1329
	andl	$65535, %eax
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1376
	sall	$4, %eax
	movw	$-1, _VR+12(%eax)
L1331:
	movl	_VACC+56, %edx
	movl	_VACC+60, %eax
	andl	$-2147483648, %edx
	testb	$128, %ah
	je	L1333
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	sall	$4, %ecx
	orl	%edx, %eax
	je	L1336
	movw	$0, _VR+14(%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1305:
	.cfi_restore_state
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1370
	sall	$4, %eax
	movw	$0, _VR(%eax)
	jmp	L1307
	.p2align 2,,3
L1338:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
	jmp	L1340
	.p2align 2,,3
L1273:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1363
	sall	$4, %eax
	movw	$-32768, _VR(%eax)
	jmp	L1275
	.p2align 2,,3
L1313:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1372
	sall	$4, %eax
	movw	$0, _VR+4(%eax)
	jmp	L1315
	.p2align 2,,3
L1309:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1371
	sall	$4, %eax
	movw	$0, _VR+2(%eax)
	jmp	L1311
	.p2align 2,,3
L1329:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1376
	sall	$4, %eax
	movw	$0, _VR+12(%eax)
	jmp	L1331
	.p2align 2,,3
L1325:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1375
	sall	$4, %eax
	movw	$0, _VR+10(%eax)
	jmp	L1327
	.p2align 2,,3
L1321:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1374
	sall	$4, %eax
	movw	$0, _VR+8(%eax)
	jmp	L1323
	.p2align 2,,3
L1317:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1373
	sall	$4, %eax
	movw	$0, _VR+6(%eax)
	jmp	L1319
	.p2align 2,,3
L1333:
	andl	$65535, %eax
	sall	$4, %ecx
	orl	%edx, %eax
	je	L1336
	movw	$-1, _VR+14(%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1356:
	.cfi_restore_state
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L1358
	.p2align 2,,3
L1353:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L1355
	.p2align 2,,3
L1350:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L1352
	.p2align 2,,3
L1347:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L1349
	.p2align 2,,3
L1344:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L1346
	.p2align 2,,3
L1341:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L1343
	.p2align 2,,3
L1301:
	andl	$65535, %eax
	sall	$4, %ecx
	orl	%edx, %eax
	je	L1304
	movw	$32767, _VR+14(%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1297:
	.cfi_restore_state
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1369
	sall	$4, %eax
	movw	$-32768, _VR+12(%eax)
	jmp	L1299
	.p2align 2,,3
L1293:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1368
	sall	$4, %eax
	movw	$-32768, _VR+10(%eax)
	jmp	L1295
	.p2align 2,,3
L1289:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1367
	sall	$4, %eax
	movw	$-32768, _VR+8(%eax)
	jmp	L1291
	.p2align 2,,3
L1285:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1366
	sall	$4, %eax
	movw	$-32768, _VR+6(%eax)
	jmp	L1287
	.p2align 2,,3
L1281:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1365
	sall	$4, %eax
	movw	$-32768, _VR+4(%eax)
	jmp	L1283
	.p2align 2,,3
L1277:
	andl	$65535, %eax
	xorl	$65535, %eax
	addl	$-2147483648, %edx
	orl	%edx, %eax
	movl	%ecx, %eax
	je	L1364
	sall	$4, %eax
	movw	$-32768, _VR+2(%eax)
	jmp	L1279
	.p2align 2,,3
L1375:
	sall	$4, %eax
	movl	_VACC+40, %edx
	movw	%dx, _VR+10(%eax)
	jmp	L1327
	.p2align 2,,3
L1374:
	sall	$4, %eax
	movl	_VACC+32, %edx
	movw	%dx, _VR+8(%eax)
	jmp	L1323
	.p2align 2,,3
L1371:
	sall	$4, %eax
	movl	_VACC+8, %edx
	movw	%dx, _VR+2(%eax)
	jmp	L1311
	.p2align 2,,3
L1370:
	sall	$4, %eax
	movl	_VACC, %edx
	movw	%dx, _VR(%eax)
	jmp	L1307
	.p2align 2,,3
L1373:
	sall	$4, %eax
	movl	_VACC+24, %edx
	movw	%dx, _VR+6(%eax)
	jmp	L1319
	.p2align 2,,3
L1372:
	sall	$4, %eax
	movl	_VACC+16, %edx
	movw	%dx, _VR+4(%eax)
	jmp	L1315
	.p2align 2,,3
L1336:
	movl	_VACC+56, %eax
	movw	%ax, _VR+14(%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1364:
	.cfi_restore_state
	sall	$4, %eax
	movw	_VACC+10, %dx
	movw	%dx, _VR+2(%eax)
	jmp	L1279
	.p2align 2,,3
L1363:
	sall	$4, %eax
	movw	_VACC+2, %dx
	movw	%dx, _VR(%eax)
	jmp	L1275
	.p2align 2,,3
L1366:
	sall	$4, %eax
	movw	_VACC+26, %dx
	movw	%dx, _VR+6(%eax)
	jmp	L1287
	.p2align 2,,3
L1365:
	sall	$4, %eax
	movw	_VACC+18, %dx
	movw	%dx, _VR+4(%eax)
	jmp	L1283
	.p2align 2,,3
L1376:
	sall	$4, %eax
	movl	_VACC+48, %edx
	movw	%dx, _VR+12(%eax)
	jmp	L1331
	.p2align 2,,3
L1368:
	sall	$4, %eax
	movw	_VACC+42, %dx
	movw	%dx, _VR+10(%eax)
	jmp	L1295
	.p2align 2,,3
L1367:
	sall	$4, %eax
	movw	_VACC+34, %dx
	movw	%dx, _VR+8(%eax)
	jmp	L1291
	.p2align 2,,3
L1369:
	sall	$4, %eax
	movw	_VACC+50, %dx
	movw	%dx, _VR+12(%eax)
	jmp	L1299
	.p2align 2,,3
L1304:
	movw	_VACC+58, %ax
	movw	%ax, _VR+14(%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1339:
	.cfi_restore_state
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$32752, _VR(%eax)
	jmp	L1340
	.p2align 2,,3
L1357:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$32752, _VR+12(%eax)
	jmp	L1358
	.p2align 2,,3
L1345:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$32752, _VR+4(%eax)
	jmp	L1346
	.p2align 2,,3
L1342:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$32752, _VR+2(%eax)
	jmp	L1343
	.p2align 2,,3
L1361:
	andl	$-16, %eax
	movw	%ax, _VR+14(%ecx)
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1354:
	.cfi_restore_state
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$32752, _VR+10(%eax)
	jmp	L1355
	.p2align 2,,3
L1351:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$32752, _VR+8(%eax)
	jmp	L1352
	.p2align 2,,3
L1348:
	movl	%ecx, %eax
	sall	$4, %eax
	movw	$32752, _VR+6(%eax)
	jmp	L1349
	.cfi_endproc
LFE25:
	.section .rdata,"dr"
LC62:
	.ascii "SPECIAL\12RESERVED\0"
LC63:
	.ascii "REGIMM\12RESERVED\0"
	.align 4
LC64:
	.ascii "Halted RSP CPU loop by means of MTC0.\0"
	.text
	.p2align 2,,3
	.globl	_run_microcode
	.def	_run_microcode;	.scl	2;	.type	32;	.endef
_run_microcode:
LFB99:
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
	movl	_RSP+40, %eax
	movl	%eax, 36(%esp)
	movl	__imp__MessageBoxA@16, %edx
	movl	%edx, 44(%esp)
	movl	%eax, %edx
	.p2align 2,,3
L1482:
	movl	(%edx), %eax
	testb	$1, %al
	jne	L1498
L1472:
	movl	_RSP+52, %ecx
	movl	(%ecx), %edx
	movl	_RSP+16, %edi
	movl	(%edi,%edx), %eax
	addl	$4, %edx
	andl	$4092, %edx
	movl	%edx, (%ecx)
	movl	%eax, %ebx
	shrl	$25, %ebx
	cmpl	$37, %ebx
	je	L1475
	movl	_temp_PC, %ebp
	movl	%ecx, 24(%esp)
L1474:
	movl	$0, _SR
	movzwl	%ax, %esi
	movl	%esi, %ebx
	shrl	$11, %ebx
	movl	%ebx, 40(%esp)
	movl	%eax, %ecx
	shrl	$21, %ecx
	movl	%ecx, 32(%esp)
	movl	%eax, %ebx
	shrl	$16, %ebx
	andl	$31, %ebx
	movl	%eax, %ecx
	shrl	$26, %ecx
	movl	%ecx, 28(%esp)
	cmpl	$58, %ecx
	jbe	L1499
L1382:
	movl	%ebp, _temp_PC
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC51, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 64
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movl	_RSP+40, %ebx
	movl	%ebx, 36(%esp)
	movl	%ebx, %edx
	movl	(%edx), %eax
	testb	$1, %al
	je	L1472
	.p2align 2,,3
L1498:
	movl	_RSP+56, %edx
	cmpl	$1, (%edx)
	je	L1500
	movl	$48, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC64, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 64
	subl	$16, %esp
	.cfi_def_cfa_offset 80
L1493:
	movl	_RSP+20, %eax
	orl	$1, (%eax)
	movl	_RSP+92, %eax
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
	jmp	*%eax
	.p2align 2,,3
L1499:
	.cfi_restore_state
	jmp	*L1411(,%ecx,4)
	.section .rdata,"dr"
	.align 4
L1411:
	.long	L1383
	.long	L1384
	.long	L1492
	.long	L1386
	.long	L1387
	.long	L1388
	.long	L1389
	.long	L1390
	.long	L1392
	.long	L1392
	.long	L1393
	.long	L1394
	.long	L1395
	.long	L1396
	.long	L1397
	.long	L1398
	.long	L1399
	.long	L1382
	.long	L1400
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1401
	.long	L1402
	.long	L1382
	.long	L1403
	.long	L1404
	.long	L1405
	.long	L1382
	.long	L1382
	.long	L1406
	.long	L1407
	.long	L1382
	.long	L1408
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1409
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1382
	.long	L1410
	.text
	.p2align 2,,3
L1392:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	movswl	%si, %esi
	addl	_SR(,%ebp,4), %esi
	movl	%esi, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1386:
	leal	4(%edx), %eax
	andl	$4092, %eax
	movl	%eax, _SR+124
L1492:
	leal	0(,%esi,4), %ebp
L1433:
	movl	(%edi,%edx), %eax
	movl	%ebp, %edx
	andl	$4092, %edx
	movl	24(%esp), %ecx
	movl	%edx, (%ecx)
	movl	%eax, %ebx
	shrl	$25, %ebx
	cmpl	$37, %ebx
	jne	L1474
	movl	%ebp, _temp_PC
	.p2align 2,,3
L1475:
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
	movl	_RSP+40, %ebx
	movl	%ebx, 36(%esp)
	movl	%ebx, %edx
	jmp	L1482
	.p2align 2,,3
L1390:
	movl	32(%esp), %eax
	andl	$31, %eax
	movl	_SR(,%eax,4), %eax
	testl	%eax, %eax
	jle	L1490
L1449:
	leal	(%edx,%esi,4), %ebp
	jmp	L1433
	.p2align 2,,3
L1389:
	movl	32(%esp), %eax
	andl	$31, %eax
	movl	_SR(,%eax,4), %eax
	testl	%eax, %eax
	jle	L1449
L1490:
	movl	%ebp, _temp_PC
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1410:
	movl	%ebp, _temp_PC
	movl	%eax, %edx
	sall	$25, %edx
	sarl	$31, %edx
	andl	$65408, %edx
	movl	32(%esp), %ebp
	andl	$31, %ebp
	movl	%ebp, 12(%esp)
	movl	%eax, %ecx
	andl	$127, %ecx
	orl	%ecx, %edx
	movl	%edx, 8(%esp)
	shrl	$7, %eax
	andl	$15, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	movl	40(%esp), %eax
	call	*_SP_SWC2(,%eax,4)
	movl	_RSP+40, %edx
	movl	%edx, 36(%esp)
	jmp	L1482
	.p2align 2,,3
L1388:
	movl	32(%esp), %eax
	andl	$31, %eax
	movl	_SR(,%ebx,4), %ecx
	cmpl	%ecx, _SR(,%eax,4)
	jne	L1449
	jmp	L1490
	.p2align 2,,3
L1387:
	movl	32(%esp), %eax
	andl	$31, %eax
	movl	_SR(,%ebx,4), %ecx
	cmpl	%ecx, _SR(,%eax,4)
	jne	L1490
	jmp	L1449
	.p2align 2,,3
L1384:
	movl	32(%esp), %eax
	andl	$31, %eax
	cmpl	$1, %ebx
	je	L1497
	jle	L1501
	cmpl	$16, %ebx
	je	L1438
	cmpl	$17, %ebx
	je	L1439
L1435:
	movl	%ebp, _temp_PC
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC63, 4(%esp)
	movl	$0, (%esp)
	call	*44(%esp)
	.cfi_def_cfa_offset 64
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movl	_RSP+40, %edx
	movl	%edx, 36(%esp)
	jmp	L1482
	.p2align 2,,3
L1383:
	movl	%eax, %esi
	andl	$63, %esi
	cmpl	$43, %esi
	jbe	L1502
L1412:
	movl	%ebp, _temp_PC
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC62, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 64
	subl	$16, %esp
	.cfi_def_cfa_offset 80
	movl	_RSP+40, %eax
	movl	%eax, 36(%esp)
	movl	%eax, %edx
	jmp	L1482
	.p2align 2,,3
L1409:
	movl	%ebp, _temp_PC
	movl	%eax, %edx
	sall	$25, %edx
	sarl	$31, %edx
	andl	$65408, %edx
	movl	32(%esp), %ebp
	andl	$31, %ebp
	movl	%ebp, 12(%esp)
	movl	%eax, %ecx
	andl	$127, %ecx
	orl	%ecx, %edx
	movl	%edx, 8(%esp)
	shrl	$7, %eax
	andl	$15, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	movl	40(%esp), %edx
	call	*_SP_LWC2(,%edx,4)
	movl	_RSP+40, %ebx
	movl	%ebx, 36(%esp)
	movl	%ebx, %edx
	jmp	L1482
	.p2align 2,,3
L1408:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	addl	_SR(,%ebp,4), %esi
	movl	%esi, %eax
	andl	$4095, %eax
	andl	$3, %esi
	cmpl	$2, %esi
	je	L1468
	cmpl	$3, %esi
	je	L1469
	decl	%esi
	je	L1467
	movl	_SR(,%ebx,4), %ecx
	movl	_RSP+12, %edx
	movl	%ecx, (%edx,%eax)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1407:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	addl	_SR(,%ebp,4), %esi
	movl	%esi, %eax
	andl	$4095, %eax
	andl	$3, %esi
	cmpl	$2, %esi
	je	L1464
	cmpl	$3, %esi
	je	L1465
	movl	_SR(,%ebx,4), %ecx
	movl	_RSP+12, %edx
	decl	%esi
	je	L1463
	movw	%cx, 2(%edx,%eax)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1406:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	addl	_SR(,%ebp,4), %esi
	andl	$4095, %esi
	xorl	$3, %esi
	movl	_SR(,%ebx,4), %edx
	movl	_RSP+12, %eax
	movb	%dl, (%eax,%esi)
	movl	_RSP+40, %ebx
	movl	%ebx, 36(%esp)
	movl	%ebx, %edx
	jmp	L1482
	.p2align 2,,3
L1405:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	addl	_SR(,%ebp,4), %esi
	movl	%esi, %eax
	andl	$4095, %eax
	andl	$3, %esi
	cmpl	$2, %esi
	je	L1460
	cmpl	$3, %esi
	je	L1461
	movl	_RSP+12, %edx
	decl	%esi
	je	L1459
	movzwl	2(%edx,%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1404:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	addl	_SR(,%ebp,4), %esi
	andl	$4095, %esi
	xorl	$3, %esi
	movl	_RSP+12, %eax
	movzbl	(%eax,%esi), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1403:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	addl	_SR(,%ebp,4), %esi
	movl	%esi, %eax
	andl	$4095, %eax
	andl	$3, %esi
	cmpl	$2, %esi
	je	L1456
	cmpl	$3, %esi
	je	L1457
	decl	%esi
	je	L1455
	movl	_RSP+12, %edx
	movl	(%edx,%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1402:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	addl	_SR(,%ebp,4), %esi
	movl	%esi, %eax
	andl	$4095, %eax
	andl	$3, %esi
	cmpl	$2, %esi
	je	L1452
	cmpl	$3, %esi
	je	L1453
	movl	_RSP+12, %edx
	decl	%esi
	je	L1451
	movswl	2(%edx,%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1401:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	addl	_SR(,%ebp,4), %esi
	andl	$4095, %esi
	xorl	$3, %esi
	movl	_RSP+12, %eax
	movsbl	(%eax,%esi), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1400:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	sarl	$7, %esi
	andl	$15, %esi
	movl	%esi, 8(%esp)
	movl	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	*_SP_COP2(,%ebp,4)
	movl	_RSP+40, %edx
	movl	%edx, 36(%esp)
	jmp	L1482
	.p2align 2,,3
L1399:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	movl	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	*_SP_COP0(,%ebp,4)
	movl	_RSP+40, %edx
	movl	%edx, 36(%esp)
	jmp	L1482
	.p2align 2,,3
L1398:
	movl	%ebp, _temp_PC
	sall	$16, %esi
	movl	%esi, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1397:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	xorl	_SR(,%ebp,4), %esi
	movl	%esi, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1396:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	orl	_SR(,%ebp,4), %esi
	movl	%esi, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1395:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	andl	_SR(,%ebp,4), %esi
	movl	%esi, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1394:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	movswl	%si, %esi
	xorl	%eax, %eax
	cmpl	%esi, _SR(,%ebp,4)
	setb	%al
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1393:
	movl	%ebp, _temp_PC
	movl	32(%esp), %ebp
	andl	$31, %ebp
	movswl	%si, %esi
	xorl	%eax, %eax
	cmpl	%esi, _SR(,%ebp,4)
	setl	%al
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.p2align 2,,3
L1502:
	jmp	*L1432(,%esi,4)
	.section .rdata,"dr"
	.align 4
L1432:
	.long	L1413
	.long	L1412
	.long	L1414
	.long	L1415
	.long	L1416
	.long	L1412
	.long	L1417
	.long	L1418
	.long	L1491
	.long	L1420
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1421
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1412
	.long	L1423
	.long	L1423
	.long	L1425
	.long	L1425
	.long	L1426
	.long	L1427
	.long	L1428
	.long	L1429
	.long	L1412
	.long	L1412
	.long	L1430
	.long	L1431
	.text
	.p2align 2,,3
L1500:
	andl	$-2, %eax
	movl	36(%esp), %ebx
	movl	%eax, (%ebx)
L1378:
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
L1439:
	.cfi_restore_state
	leal	4(%edx), %ebx
	andl	$4092, %ebx
	movl	%ebx, _SR+124
L1497:
	movl	_SR(,%eax,4), %eax
	testl	%eax, %eax
	jns	L1449
	jmp	L1490
L1457:
	movl	_RSP+12, %esi
	leal	4(%eax), %ecx
	andl	$4095, %ecx
	movzbl	(%esi,%ecx), %edx
	movzbl	-3(%esi,%eax), %eax
	sall	$8, %eax
	orl	%eax, %edx
	sall	$8, %edx
	movzbl	-1(%esi,%ecx), %eax
	orl	%eax, %edx
	sall	$8, %edx
	movzbl	-2(%esi,%ecx), %eax
	orl	%eax, %edx
	movl	%edx, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1469:
	movl	_SR(,%ebx,4), %edx
	movl	%edx, %ebx
	shrl	$24, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, -3(%ecx,%eax)
	addl	$4, %eax
	andl	$4095, %eax
	movl	%edx, %ebx
	sarl	$16, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, (%ecx,%eax)
	movl	%edx, %ebx
	sarl	$8, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, -1(%ecx,%eax)
	movl	_RSP+12, %ecx
	movb	%dl, -2(%ecx,%eax)
	movl	_RSP+40, %eax
	movl	%eax, 36(%esp)
	movl	%eax, %edx
	jmp	L1482
L1465:
	movl	_SR(,%ebx,4), %edx
	movl	%edx, %ebx
	sarl	$8, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, -3(%ecx,%eax)
	addl	$4, %eax
	andl	$4095, %eax
	movl	_RSP+12, %ecx
	movb	%dl, (%ecx,%eax)
	movl	_RSP+40, %eax
	movl	%eax, 36(%esp)
	movl	%eax, %edx
	jmp	L1482
L1461:
	movl	_RSP+12, %ecx
	leal	4(%eax), %edx
	andl	$4095, %edx
	movzbl	(%ecx,%edx), %edx
	movzbl	-3(%ecx,%eax), %eax
	sall	$8, %eax
	orl	%eax, %edx
	movl	%edx, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1453:
	movl	_RSP+12, %ecx
	leal	4(%eax), %edx
	andl	$4095, %edx
	movzbl	(%ecx,%edx), %edx
	movzbl	-3(%ecx,%eax), %eax
	sall	$8, %eax
	orl	%eax, %edx
	movswl	%dx, %edx
	movl	%edx, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1501:
	testl	%ebx, %ebx
	jne	L1435
L1495:
	movl	_SR(,%eax,4), %eax
	testl	%eax, %eax
	jns	L1490
	jmp	L1449
L1425:
	movl	%ebp, _temp_PC
	movl	32(%esp), %edx
	movl	_SR(,%edx,4), %eax
	subl	_SR(,%ebx,4), %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1423:
	movl	%ebp, _temp_PC
	movl	32(%esp), %edx
	movl	_SR(,%edx,4), %eax
	addl	_SR(,%ebx,4), %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1420:
	leal	4(%edx), %eax
	andl	$4092, %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
L1491:
	movl	32(%esp), %eax
	movl	_SR(,%eax,4), %ebp
	jmp	L1433
L1468:
	movl	_SR(,%ebx,4), %edx
	movl	%edx, %ebx
	shrl	$24, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, -1(%ecx,%eax)
	movl	%edx, %ebx
	sarl	$16, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, -2(%ecx,%eax)
	addl	$5, %eax
	andl	$4095, %eax
	movl	%edx, %ebx
	sarl	$8, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, (%ecx,%eax)
	movl	_RSP+12, %ecx
	movb	%dl, -1(%ecx,%eax)
	movl	_RSP+40, %ebx
	movl	%ebx, 36(%esp)
	movl	%ebx, %edx
	jmp	L1482
L1456:
	movl	_RSP+12, %ecx
	movzbl	-1(%ecx,%eax), %edx
	sall	$8, %edx
	movzbl	-2(%ecx,%eax), %esi
	orl	%esi, %edx
	addl	$5, %eax
	andl	$4095, %eax
	sall	$8, %edx
	movzbl	(%ecx,%eax), %esi
	orl	%esi, %edx
	sall	$8, %edx
	movzbl	-1(%ecx,%eax), %eax
	orl	%eax, %edx
	movl	%edx, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1467:
	movl	_SR(,%ebx,4), %edx
	movl	%edx, %ebx
	shrl	$24, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, 1(%ecx,%eax)
	movl	%edx, %ebx
	sarl	$16, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, (%ecx,%eax)
	movl	%edx, %ebx
	sarl	$8, %ebx
	movl	_RSP+12, %ecx
	movb	%bl, -1(%ecx,%eax)
	addl	$6, %eax
	andl	$4095, %eax
	movl	_RSP+12, %ecx
	movb	%dl, (%ecx,%eax)
	movl	_RSP+40, %edx
	movl	%edx, 36(%esp)
	jmp	L1482
L1455:
	movl	_RSP+12, %ecx
	movzbl	1(%ecx,%eax), %edx
	sall	$8, %edx
	movzbl	(%ecx,%eax), %esi
	orl	%esi, %edx
	sall	$8, %edx
	movzbl	-1(%ecx,%eax), %esi
	orl	%esi, %edx
	addl	$6, %eax
	sall	$8, %edx
	andl	$4095, %eax
	movzbl	(%ecx,%eax), %eax
	orl	%eax, %edx
	movl	%edx, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1463:
	movw	%cx, (%edx,%eax)
	movl	36(%esp), %edx
	jmp	L1482
L1459:
	movzwl	(%edx,%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1451:
	movswl	(%edx,%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1438:
	leal	4(%edx), %ebx
	andl	$4092, %ebx
	movl	%ebx, _SR+124
	jmp	L1495
L1452:
	movl	_RSP+12, %edx
	movswl	-2(%edx,%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1464:
	movl	_SR(,%ebx,4), %ecx
	movl	_RSP+12, %edx
	movw	%cx, -2(%edx,%eax)
	movl	36(%esp), %edx
	jmp	L1482
L1460:
	movl	_RSP+12, %edx
	movzwl	-2(%edx,%eax), %eax
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1413:
	movl	%ebp, _temp_PC
	movl	%eax, %ecx
	andl	$1984, %ecx
	sarl	$6, %ecx
	movl	_SR(,%ebx,4), %edx
	sall	%cl, %edx
	movl	40(%esp), %ebx
	movl	%edx, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1414:
	movl	%ebp, _temp_PC
	movl	%eax, %ecx
	andl	$1984, %ecx
	sarl	$6, %ecx
	movl	_SR(,%ebx,4), %edx
	shrl	%cl, %edx
	movl	40(%esp), %eax
	movl	%edx, _SR(,%eax,4)
	movl	36(%esp), %edx
	jmp	L1482
L1415:
	movl	%ebp, _temp_PC
	movl	%eax, %ecx
	andl	$1984, %ecx
	sarl	$6, %ecx
	movl	_SR(,%ebx,4), %edx
	sarl	%cl, %edx
	movl	40(%esp), %ebx
	movl	%edx, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1416:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %eax
	movl	32(%esp), %edx
	movl	_SR(,%edx,4), %ecx
	sall	%cl, %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1417:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %eax
	movl	32(%esp), %edx
	movl	_SR(,%edx,4), %ecx
	shrl	%cl, %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1418:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %eax
	movl	32(%esp), %edx
	movl	_SR(,%edx,4), %ecx
	sarl	%cl, %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1427:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %eax
	movl	32(%esp), %edx
	orl	_SR(,%edx,4), %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1428:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %eax
	movl	32(%esp), %edx
	xorl	_SR(,%edx,4), %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1421:
	movl	%ebp, _temp_PC
	movl	36(%esp), %edx
	movl	(%edx), %eax
	movl	%eax, %edx
	orl	$3, %edx
	movl	36(%esp), %ebx
	movl	%edx, (%ebx)
	testb	$64, %al
	je	L1378
	jmp	L1493
L1431:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %edx
	movl	32(%esp), %eax
	cmpl	%edx, _SR(,%eax,4)
	setb	%al
	movzbl	%al, %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1430:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %edx
	movl	32(%esp), %eax
	cmpl	%edx, _SR(,%eax,4)
	setl	%al
	movzbl	%al, %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1426:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %eax
	movl	32(%esp), %edx
	andl	_SR(,%edx,4), %eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
L1429:
	movl	%ebp, _temp_PC
	movl	_SR(,%ebx,4), %eax
	movl	32(%esp), %edx
	orl	_SR(,%edx,4), %eax
	notl	%eax
	movl	40(%esp), %ebx
	movl	%eax, _SR(,%ebx,4)
	movl	36(%esp), %edx
	jmp	L1482
	.cfi_endproc
LFE99:
	.p2align 2,,3
	.globl	_CloseDLL
	.def	_CloseDLL;	.scl	2;	.type	32;	.endef
_CloseDLL:
LFB100:
	.cfi_startproc
	ret
	.cfi_endproc
LFE100:
	.section .rdata,"dr"
LC65:
	.ascii "RSP Interpreter\0"
	.align 4
LC66:
	.ascii "Thanks for test RDP:  Jabo, ziggy, Gonetz\12SP thread examples:  bpoint, zilmar, Ville Linde\0"
	.text
	.p2align 2,,3
	.globl	_DllAbout
	.def	_DllAbout;	.scl	2;	.type	32;	.endef
_DllAbout:
LFB101:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$64, 12(%esp)
	movl	$LC65, 8(%esp)
	movl	$LC66, 4(%esp)
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
LFE101:
	.section .rdata,"dr"
LC67:
	.ascii "SP_STATUS_HALT\0"
	.text
	.p2align 2,,3
	.globl	_DoRspCycles
	.def	_DoRspCycles;	.scl	2;	.type	32;	.endef
_DoRspCycles:
LFB102:
	.cfi_startproc
	subl	$44, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %eax
	movl	_RSP+40, %edx
	testb	$3, (%edx)
	jne	L1510
	movl	%eax, 28(%esp)
	call	_run_microcode
	movl	28(%esp), %eax
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret
	.p2align 2,,3
L1510:
	.cfi_restore_state
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC67, 4(%esp)
	movl	$0, (%esp)
	call	*__imp__MessageBoxA@16
	.cfi_def_cfa_offset 32
	subl	$16, %esp
	.cfi_def_cfa_offset 48
	xorl	%eax, %eax
	addl	$44, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE102:
	.section .rdata,"dr"
	.align 4
LC68:
	.ascii "Iconoclast's LLE SP Interpreter\0"
	.text
	.p2align 2,,3
	.globl	_GetDllInfo
	.def	_GetDllInfo;	.scl	2;	.type	32;	.endef
_GetDllInfo:
LFB103:
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
	movl	$LC68, %esi
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
LFE103:
	.section .rdata,"dr"
	.align 4
LC69:
	.ascii "Virtual host map noncontiguity.\0"
	.text
	.p2align 2,,3
	.globl	_InitiateRSP
	.def	_InitiateRSP;	.scl	2;	.type	32;	.endef
_InitiateRSP:
LFB104:
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
	movl	_RSP+12, %eax
	addl	$4096, %eax
	movl	__imp__MessageBoxA@16, %ebx
	cmpl	%eax, _RSP+16
	je	L1513
	.p2align 2,,3
L1517:
	movl	$16, 12(%esp)
	movl	$0, 8(%esp)
	movl	$LC69, 4(%esp)
	movl	$0, (%esp)
	call	*%ebx
	.cfi_def_cfa_offset 16
	subl	$16, %esp
	.cfi_def_cfa_offset 32
	movl	_RSP+12, %eax
	addl	$4096, %eax
	cmpl	%eax, _RSP+16
	jne	L1517
L1513:
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
LFE104:
	.p2align 2,,3
	.globl	_InitiateRSPDebugger
	.def	_InitiateRSPDebugger;	.scl	2;	.type	32;	.endef
_InitiateRSPDebugger:
LFB105:
	.cfi_startproc
	movl	8(%esp), %eax
	jmp	*%eax
	.cfi_endproc
LFE105:
	.p2align 2,,3
	.globl	_RomClosed
	.def	_RomClosed;	.scl	2;	.type	32;	.endef
_RomClosed:
LFB106:
	.cfi_startproc
	movl	_RSP+52, %eax
	movl	$0, (%eax)
	ret
	.cfi_endproc
LFE106:
	.comm	_VCE, 1, 4
	.comm	_VCC, 2, 4
	.comm	_VCO, 2, 4
	.comm	_RSP, 112, 5
.lcomm _SR,128,32
.lcomm _VACC,64,32
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
.lcomm _temp_PC,4,16
	.align 32
_SP_COP0:
	.long	_MFC0
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_MTC0
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
	.long	_res_020
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
.lcomm _DivOut,4,16
.lcomm _DPH,4,16
	.align 32
_div_ROM:
	.word	-1
	.word	-256
	.word	-511
	.word	-764
	.word	-1017
	.word	-1268
	.word	-1519
	.word	-1768
	.word	-2017
	.word	-2265
	.word	-2511
	.word	-2757
	.word	-3002
	.word	-3246
	.word	-3489
	.word	-3731
	.word	-3972
	.word	-4213
	.word	-4452
	.word	-4690
	.word	-4928
	.word	-5165
	.word	-5400
	.word	-5635
	.word	-5869
	.word	-6103
	.word	-6335
	.word	-6566
	.word	-6797
	.word	-7027
	.word	-7255
	.word	-7483
	.word	-7711
	.word	-7937
	.word	-8162
	.word	-8387
	.word	-8611
	.word	-8834
	.word	-9056
	.word	-9278
	.word	-9498
	.word	-9718
	.word	-9937
	.word	-10156
	.word	-10373
	.word	-10590
	.word	-10806
	.word	-11021
	.word	-11235
	.word	-11449
	.word	-11662
	.word	-11874
	.word	-12085
	.word	-12296
	.word	-12506
	.word	-12715
	.word	-12923
	.word	-13131
	.word	-13338
	.word	-13544
	.word	-13749
	.word	-13954
	.word	-14158
	.word	-14361
	.word	-14564
	.word	-14766
	.word	-14967
	.word	-15168
	.word	-15368
	.word	-15567
	.word	-15765
	.word	-15963
	.word	-16160
	.word	-16356
	.word	-16552
	.word	-16747
	.word	-16942
	.word	-17136
	.word	-17329
	.word	-17521
	.word	-17713
	.word	-17904
	.word	-18095
	.word	-18284
	.word	-18474
	.word	-18662
	.word	-18850
	.word	-19038
	.word	-19224
	.word	-19410
	.word	-19596
	.word	-19781
	.word	-19965
	.word	-20149
	.word	-20332
	.word	-20514
	.word	-20696
	.word	-20877
	.word	-21058
	.word	-21238
	.word	-21417
	.word	-21596
	.word	-21775
	.word	-21952
	.word	-22130
	.word	-22306
	.word	-22482
	.word	-22658
	.word	-22832
	.word	-23007
	.word	-23180
	.word	-23354
	.word	-23526
	.word	-23698
	.word	-23870
	.word	-24041
	.word	-24211
	.word	-24381
	.word	-24550
	.word	-24719
	.word	-24888
	.word	-25055
	.word	-25223
	.word	-25389
	.word	-25555
	.word	-25721
	.word	-25886
	.word	-26051
	.word	-26215
	.word	-26378
	.word	-26542
	.word	-26704
	.word	-26866
	.word	-27028
	.word	-27189
	.word	-27349
	.word	-27509
	.word	-27669
	.word	-27828
	.word	-27987
	.word	-28145
	.word	-28302
	.word	-28460
	.word	-28616
	.word	-28772
	.word	-28928
	.word	-29083
	.word	-29238
	.word	-29392
	.word	-29546
	.word	-29700
	.word	-29852
	.word	-30005
	.word	-30157
	.word	-30308
	.word	-30460
	.word	-30610
	.word	-30760
	.word	-30910
	.word	-31059
	.word	-31208
	.word	-31357
	.word	-31504
	.word	-31652
	.word	-31799
	.word	-31946
	.word	-32092
	.word	-32238
	.word	-32383
	.word	-32528
	.word	-32672
	.word	32720
	.word	32576
	.word	32433
	.word	32290
	.word	32147
	.word	32005
	.word	31864
	.word	31723
	.word	31582
	.word	31442
	.word	31302
	.word	31162
	.word	31023
	.word	30884
	.word	30746
	.word	30608
	.word	30470
	.word	30333
	.word	30197
	.word	30060
	.word	29924
	.word	29789
	.word	29653
	.word	29519
	.word	29384
	.word	29250
	.word	29116
	.word	28983
	.word	28850
	.word	28718
	.word	28585
	.word	28454
	.word	28322
	.word	28191
	.word	28060
	.word	27930
	.word	27800
	.word	27670
	.word	27541
	.word	27412
	.word	27284
	.word	27155
	.word	27027
	.word	26900
	.word	26773
	.word	26646
	.word	26520
	.word	26393
	.word	26268
	.word	26142
	.word	26017
	.word	25892
	.word	25768
	.word	25644
	.word	25520
	.word	25397
	.word	25274
	.word	25151
	.word	25029
	.word	24907
	.word	24785
	.word	24664
	.word	24543
	.word	24422
	.word	24301
	.word	24181
	.word	24061
	.word	23942
	.word	23823
	.word	23704
	.word	23586
	.word	23467
	.word	23349
	.word	23232
	.word	23115
	.word	22998
	.word	22881
	.word	22765
	.word	22649
	.word	22533
	.word	22417
	.word	22302
	.word	22188
	.word	22073
	.word	21959
	.word	21845
	.word	21731
	.word	21618
	.word	21505
	.word	21392
	.word	21280
	.word	21167
	.word	21056
	.word	20944
	.word	20833
	.word	20722
	.word	20611
	.word	20501
	.word	20390
	.word	20280
	.word	20171
	.word	20062
	.word	19953
	.word	19844
	.word	19735
	.word	19627
	.word	19519
	.word	19411
	.word	19304
	.word	19197
	.word	19090
	.word	18983
	.word	18877
	.word	18771
	.word	18665
	.word	18560
	.word	18455
	.word	18350
	.word	18245
	.word	18140
	.word	18036
	.word	17932
	.word	17829
	.word	17725
	.word	17622
	.word	17519
	.word	17416
	.word	17314
	.word	17212
	.word	17110
	.word	17008
	.word	16907
	.word	16806
	.word	16705
	.word	16604
	.word	16504
	.word	16404
	.word	16304
	.word	16204
	.word	16104
	.word	16005
	.word	15906
	.word	15808
	.word	15709
	.word	15611
	.word	15513
	.word	15415
	.word	15318
	.word	15220
	.word	15123
	.word	15026
	.word	14930
	.word	14833
	.word	14737
	.word	14641
	.word	14546
	.word	14450
	.word	14355
	.word	14260
	.word	14165
	.word	14071
	.word	13976
	.word	13882
	.word	13788
	.word	13695
	.word	13601
	.word	13508
	.word	13415
	.word	13322
	.word	13230
	.word	13137
	.word	13045
	.word	12953
	.word	12862
	.word	12770
	.word	12679
	.word	12588
	.word	12497
	.word	12406
	.word	12316
	.word	12226
	.word	12136
	.word	12046
	.word	11956
	.word	11867
	.word	11778
	.word	11689
	.word	11600
	.word	11512
	.word	11423
	.word	11335
	.word	11247
	.word	11159
	.word	11072
	.word	10984
	.word	10897
	.word	10810
	.word	10724
	.word	10637
	.word	10551
	.word	10464
	.word	10379
	.word	10293
	.word	10207
	.word	10122
	.word	10037
	.word	9952
	.word	9867
	.word	9782
	.word	9698
	.word	9613
	.word	9529
	.word	9445
	.word	9362
	.word	9278
	.word	9195
	.word	9112
	.word	9029
	.word	8946
	.word	8864
	.word	8781
	.word	8699
	.word	8617
	.word	8535
	.word	8453
	.word	8372
	.word	8291
	.word	8210
	.word	8129
	.word	8048
	.word	7967
	.word	7887
	.word	7807
	.word	7726
	.word	7647
	.word	7567
	.word	7487
	.word	7408
	.word	7329
	.word	7250
	.word	7171
	.word	7092
	.word	7014
	.word	6935
	.word	6857
	.word	6779
	.word	6701
	.word	6624
	.word	6546
	.word	6469
	.word	6392
	.word	6315
	.word	6238
	.word	6161
	.word	6084
	.word	6008
	.word	5932
	.word	5856
	.word	5780
	.word	5704
	.word	5629
	.word	5553
	.word	5478
	.word	5403
	.word	5328
	.word	5253
	.word	5179
	.word	5104
	.word	5030
	.word	4956
	.word	4882
	.word	4808
	.word	4735
	.word	4661
	.word	4588
	.word	4515
	.word	4441
	.word	4369
	.word	4296
	.word	4223
	.word	4151
	.word	4079
	.word	4006
	.word	3934
	.word	3863
	.word	3791
	.word	3719
	.word	3648
	.word	3577
	.word	3506
	.word	3435
	.word	3364
	.word	3293
	.word	3223
	.word	3152
	.word	3082
	.word	3012
	.word	2942
	.word	2872
	.word	2802
	.word	2733
	.word	2664
	.word	2594
	.word	2525
	.word	2456
	.word	2387
	.word	2319
	.word	2250
	.word	2182
	.word	2114
	.word	2045
	.word	1977
	.word	1910
	.word	1842
	.word	1774
	.word	1707
	.word	1640
	.word	1572
	.word	1505
	.word	1438
	.word	1372
	.word	1305
	.word	1238
	.word	1172
	.word	1106
	.word	1040
	.word	974
	.word	908
	.word	842
	.word	777
	.word	711
	.word	646
	.word	581
	.word	516
	.word	451
	.word	386
	.word	321
	.word	257
	.word	192
	.word	128
	.word	64
	.word	27145
	.word	-1
	.word	26965
	.word	-256
	.word	26785
	.word	-510
	.word	26607
	.word	-762
	.word	26430
	.word	-1013
	.word	26253
	.word	-1262
	.word	26078
	.word	-1510
	.word	25904
	.word	-1757
	.word	25730
	.word	-2002
	.word	25558
	.word	-2245
	.word	25387
	.word	-2488
	.word	25216
	.word	-2729
	.word	25047
	.word	-2969
	.word	24878
	.word	-3207
	.word	24711
	.word	-3444
	.word	24544
	.word	-3680
	.word	24378
	.word	-3914
	.word	24213
	.word	-4147
	.word	24049
	.word	-4379
	.word	23886
	.word	-4609
	.word	23724
	.word	-4839
	.word	23563
	.word	-5067
	.word	23403
	.word	-5294
	.word	23243
	.word	-5519
	.word	23084
	.word	-5744
	.word	22927
	.word	-5967
	.word	22770
	.word	-6189
	.word	22613
	.word	-6410
	.word	22458
	.word	-6629
	.word	22304
	.word	-6848
	.word	22150
	.word	-7065
	.word	21997
	.word	-7282
	.word	21845
	.word	-7497
	.word	21694
	.word	-7711
	.word	21543
	.word	-7923
	.word	21393
	.word	-8135
	.word	21244
	.word	-8346
	.word	21096
	.word	-8556
	.word	20949
	.word	-8764
	.word	20802
	.word	-8972
	.word	20656
	.word	-9178
	.word	20511
	.word	-9383
	.word	20366
	.word	-9588
	.word	20222
	.word	-9791
	.word	20079
	.word	-9993
	.word	19937
	.word	-10195
	.word	19795
	.word	-10395
	.word	19654
	.word	-10594
	.word	19514
	.word	-10793
	.word	19375
	.word	-10990
	.word	19236
	.word	-11186
	.word	19098
	.word	-11382
	.word	18960
	.word	-11576
	.word	18823
	.word	-11770
	.word	18687
	.word	-11962
	.word	18552
	.word	-12154
	.word	18417
	.word	-12345
	.word	18283
	.word	-12534
	.word	18149
	.word	-12723
	.word	18016
	.word	-12911
	.word	17884
	.word	-13098
	.word	17752
	.word	-13285
	.word	17621
	.word	-13470
	.word	17491
	.word	-13655
	.word	17361
	.word	-13838
	.word	17231
	.word	-14021
	.word	17103
	.word	-14203
	.word	16975
	.word	-14384
	.word	16847
	.word	-14564
	.word	16721
	.word	-14743
	.word	16594
	.word	-14922
	.word	16469
	.word	-15100
	.word	16344
	.word	-15277
	.word	16219
	.word	-15453
	.word	16095
	.word	-15628
	.word	15972
	.word	-15803
	.word	15849
	.word	-15976
	.word	15726
	.word	-16149
	.word	15605
	.word	-16321
	.word	15484
	.word	-16493
	.word	15363
	.word	-16663
	.word	15243
	.word	-16833
	.word	15123
	.word	-17002
	.word	15004
	.word	-17171
	.word	14886
	.word	-17338
	.word	14768
	.word	-17505
	.word	14650
	.word	-17672
	.word	14533
	.word	-17837
	.word	14417
	.word	-18002
	.word	14301
	.word	-18166
	.word	14185
	.word	-18329
	.word	14070
	.word	-18491
	.word	13956
	.word	-18653
	.word	13842
	.word	-18815
	.word	13728
	.word	-18975
	.word	13615
	.word	-19135
	.word	13503
	.word	-19294
	.word	13391
	.word	-19452
	.word	13279
	.word	-19610
	.word	13168
	.word	-19767
	.word	13058
	.word	-19924
	.word	12947
	.word	-20079
	.word	12838
	.word	-20235
	.word	12729
	.word	-20389
	.word	12620
	.word	-20543
	.word	12511
	.word	-20696
	.word	12404
	.word	-20849
	.word	12296
	.word	-21001
	.word	12189
	.word	-21152
	.word	12083
	.word	-21303
	.word	11976
	.word	-21453
	.word	11871
	.word	-21602
	.word	11766
	.word	-21751
	.word	11661
	.word	-21899
	.word	11556
	.word	-22047
	.word	11452
	.word	-22194
	.word	11349
	.word	-22340
	.word	11246
	.word	-22486
	.word	11143
	.word	-22631
	.word	11041
	.word	-22776
	.word	10939
	.word	-22920
	.word	10837
	.word	-23064
	.word	10736
	.word	-23207
	.word	10635
	.word	-23349
	.word	10535
	.word	-23491
	.word	10435
	.word	-23632
	.word	10336
	.word	-23773
	.word	10237
	.word	-23913
	.word	10138
	.word	-24053
	.word	10040
	.word	-24192
	.word	9942
	.word	-24330
	.word	9844
	.word	-24468
	.word	9747
	.word	-24606
	.word	9650
	.word	-24743
	.word	9554
	.word	-24879
	.word	9458
	.word	-25015
	.word	9362
	.word	-25150
	.word	9266
	.word	-25285
	.word	9171
	.word	-25420
	.word	9077
	.word	-25553
	.word	8983
	.word	-25687
	.word	8889
	.word	-25819
	.word	8795
	.word	-25952
	.word	8702
	.word	-26084
	.word	8609
	.word	-26215
	.word	8517
	.word	-26346
	.word	8424
	.word	-26476
	.word	8333
	.word	-26606
	.word	8241
	.word	-26735
	.word	8150
	.word	-26864
	.word	8059
	.word	-26993
	.word	7969
	.word	-27121
	.word	7879
	.word	-27248
	.word	7789
	.word	-27375
	.word	7699
	.word	-27502
	.word	7610
	.word	-27628
	.word	7521
	.word	-27753
	.word	7433
	.word	-27878
	.word	7345
	.word	-28003
	.word	7257
	.word	-28127
	.word	7169
	.word	-28251
	.word	7082
	.word	-28375
	.word	6995
	.word	-28497
	.word	6908
	.word	-28620
	.word	6822
	.word	-28742
	.word	6736
	.word	-28864
	.word	6650
	.word	-28985
	.word	6565
	.word	-29105
	.word	6480
	.word	-29226
	.word	6395
	.word	-29346
	.word	6311
	.word	-29465
	.word	6227
	.word	-29584
	.word	6143
	.word	-29703
	.word	6059
	.word	-29821
	.word	5976
	.word	-29939
	.word	5893
	.word	-30056
	.word	5810
	.word	-30173
	.word	5728
	.word	-30290
	.word	5645
	.word	-30406
	.word	5564
	.word	-30522
	.word	5482
	.word	-30637
	.word	5401
	.word	-30752
	.word	5320
	.word	-30867
	.word	5239
	.word	-30981
	.word	5158
	.word	-31095
	.word	5078
	.word	-31208
	.word	4998
	.word	-31321
	.word	4919
	.word	-31434
	.word	4839
	.word	-31546
	.word	4760
	.word	-31658
	.word	4681
	.word	-31769
	.word	4603
	.word	-31881
	.word	4524
	.word	-31991
	.word	4446
	.word	-32102
	.word	4369
	.word	-32212
	.word	4291
	.word	-32321
	.word	4214
	.word	-32431
	.word	4137
	.word	-32540
	.word	4060
	.word	-32648
	.word	3983
	.word	-32756
	.word	3907
	.word	32672
	.word	3831
	.word	32564
	.word	3755
	.word	32457
	.word	3680
	.word	32350
	.word	3605
	.word	32244
	.word	3530
	.word	32138
	.word	3455
	.word	32032
	.word	3380
	.word	31926
	.word	3306
	.word	31821
	.word	3232
	.word	31717
	.word	3158
	.word	31612
	.word	3084
	.word	31508
	.word	3011
	.word	31404
	.word	2938
	.word	31301
	.word	2865
	.word	31198
	.word	2792
	.word	31095
	.word	2720
	.word	30993
	.word	2648
	.word	30891
	.word	2576
	.word	30789
	.word	2504
	.word	30687
	.word	2433
	.word	30586
	.word	2361
	.word	30485
	.word	2290
	.word	30385
	.word	2219
	.word	30285
	.word	2149
	.word	30185
	.word	2078
	.word	30085
	.word	2008
	.word	29986
	.word	1938
	.word	29887
	.word	1869
	.word	29789
	.word	1799
	.word	29690
	.word	1730
	.word	29592
	.word	1661
	.word	29495
	.word	1592
	.word	29397
	.word	1523
	.word	29300
	.word	1455
	.word	29203
	.word	1386
	.word	29107
	.word	1318
	.word	29010
	.word	1250
	.word	28914
	.word	1183
	.word	28819
	.word	1115
	.word	28723
	.word	1048
	.word	28628
	.word	981
	.word	28534
	.word	914
	.word	28439
	.word	848
	.word	28345
	.word	781
	.word	28251
	.word	715
	.word	28157
	.word	649
	.word	28064
	.word	583
	.word	27971
	.word	518
	.word	27878
	.word	452
	.word	27786
	.word	387
	.word	27693
	.word	322
	.word	27601
	.word	257
	.word	27510
	.word	192
	.word	27418
	.word	128
	.word	27327
	.word	64
	.word	27236
	.section .drectve
	.ascii " -export:\"RomClosed\""
	.ascii " -export:\"InitiateRSPDebugger\""
	.ascii " -export:\"InitiateRSP\""
	.ascii " -export:\"GetDllInfo\""
	.ascii " -export:\"DoRspCycles\""
	.ascii " -export:\"DllAbout\""
	.ascii " -export:\"CloseDLL\""
