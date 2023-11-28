	.file	"main.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._Z3MaxIcET_S0_S0_,"axG",@progbits,_Z3MaxIcET_S0_S0_,comdat
	.weak	_Z3MaxIcET_S0_S0_
	.type	_Z3MaxIcET_S0_S0_, @function
_Z3MaxIcET_S0_S0_:
.LFB1767:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %edx
	movl	%esi, %eax
	movb	%dl, -4(%rbp)
	movb	%al, -8(%rbp)
	movzbl	-4(%rbp), %eax
	cmpb	-8(%rbp), %al
	jle	.L2
	movzbl	-4(%rbp), %eax
	jmp	.L4
.L2:
	movzbl	-8(%rbp), %eax
.L4:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1767:
	.size	_Z3MaxIcET_S0_S0_, .-_Z3MaxIcET_S0_S0_
	.section	.rodata
.LC0:
	.string	"Max<const char*>()"
	.text
	.globl	_Z3MaxIPKcET_S2_S2_
	.type	_Z3MaxIPKcET_S2_S2_, @function
_Z3MaxIPKcET_S2_S2_:
.LFB1523:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1523:
	.size	_Z3MaxIPKcET_S2_S2_, .-_Z3MaxIPKcET_S2_S2_
	.section	.text._ZN8EmployeeD2Ev,"axG",@progbits,_ZN8EmployeeD5Ev,comdat
	.align 2
	.weak	_ZN8EmployeeD2Ev
	.type	_ZN8EmployeeD2Ev, @function
_ZN8EmployeeD2Ev:
.LFB1529:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rdi
	call	_ZN7IntegerD1Ev@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1529:
	.size	_ZN8EmployeeD2Ev, .-_ZN8EmployeeD2Ev
	.weak	_ZN8EmployeeD1Ev
	.set	_ZN8EmployeeD1Ev,_ZN8EmployeeD2Ev
	.section	.rodata
.LC1:
	.string	"Daniel"
.LC2:
	.string	"Dan"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1527:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1527
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$136, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-136(%rbp), %rdx
	leaq	-128(%rbp), %rax
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE0:
	leaq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-136(%rbp), %rax
	movl	$100, %esi
	movq	%rax, %rdi
.LEHB1:
	call	_ZN7IntegerC1Ei@PLT
.LEHE1:
	leaq	-137(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	leaq	-137(%rbp), %rdx
	leaq	-96(%rbp), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
.LEHB2:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE2:
	leaq	-136(%rbp), %rdx
	leaq	-96(%rbp), %rcx
	leaq	-64(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB3:
	call	_ZN8EmployeeC1INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_
.LEHE3:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-137(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movl	$0, %ebx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN8EmployeeD1Ev
	leaq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7IntegerD1Ev@PLT
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movl	%ebx, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L14
	jmp	.L19
.L15:
	endbr64
	movq	%rax, %rbx
	leaq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB4:
	call	_Unwind_Resume@PLT
.L18:
	endbr64
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L12
.L17:
	endbr64
	movq	%rax, %rbx
.L12:
	leaq	-137(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7IntegerD1Ev@PLT
	jmp	.L13
.L16:
	endbr64
	movq	%rax, %rbx
.L13:
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE4:
.L19:
	call	__stack_chk_fail@PLT
.L14:
	addq	$136, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1527:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1527:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1527-.LLSDACSB1527
.LLSDACSB1527:
	.uleb128 .LEHB0-.LFB1527
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L15-.LFB1527
	.uleb128 0
	.uleb128 .LEHB1-.LFB1527
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L16-.LFB1527
	.uleb128 0
	.uleb128 .LEHB2-.LFB1527
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L17-.LFB1527
	.uleb128 0
	.uleb128 .LEHB3-.LFB1527
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L18-.LFB1527
	.uleb128 0
	.uleb128 .LEHB4-.LFB1527
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE1527:
	.text
	.size	main, .-main
	.section	.rodata
.LC3:
	.string	"Employee(&&, &&)"
	.section	.text._ZN8EmployeeC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_,"axG",@progbits,_ZN8EmployeeC5INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_,comdat
	.align 2
	.weak	_ZN8EmployeeC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_
	.type	_ZN8EmployeeC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_, @function
_ZN8EmployeeC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_:
.LFB1775:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1775
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEOT_RNSt16remove_referenceIS6_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@PLT
	movq	-24(%rbp), %rax
	leaq	32(%rax), %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIR7IntegerEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB5:
	call	_ZN7IntegerC1ERKS_@PLT
.LEHE5:
	leaq	.LC3(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB6:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE6:
	jmp	.L25
.L24:
	endbr64
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rdi
	call	_ZN7IntegerD1Ev@PLT
	jmp	.L22
.L23:
	endbr64
	movq	%rax, %rbx
.L22:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB7:
	call	_Unwind_Resume@PLT
.LEHE7:
.L25:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1775:
	.section	.gcc_except_table
.LLSDA1775:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1775-.LLSDACSB1775
.LLSDACSB1775:
	.uleb128 .LEHB5-.LFB1775
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L23-.LFB1775
	.uleb128 0
	.uleb128 .LEHB6-.LFB1775
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L24-.LFB1775
	.uleb128 0
	.uleb128 .LEHB7-.LFB1775
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
.LLSDACSE1775:
	.section	.text._ZN8EmployeeC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_,"axG",@progbits,_ZN8EmployeeC5INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_,comdat
	.size	_ZN8EmployeeC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_, .-_ZN8EmployeeC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_
	.weak	_ZN8EmployeeC1INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_
	.set	_ZN8EmployeeC1INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_,_ZN8EmployeeC2INSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEER7IntegerEEOT_OT0_
	.section	.text._ZSt7forwardINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEOT_RNSt16remove_referenceIS6_E4typeE,"axG",@progbits,_ZSt7forwardINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEOT_RNSt16remove_referenceIS6_E4typeE,comdat
	.weak	_ZSt7forwardINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEOT_RNSt16remove_referenceIS6_E4typeE
	.type	_ZSt7forwardINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEOT_RNSt16remove_referenceIS6_E4typeE, @function
_ZSt7forwardINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEOT_RNSt16remove_referenceIS6_E4typeE:
.LFB1888:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1888:
	.size	_ZSt7forwardINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEOT_RNSt16remove_referenceIS6_E4typeE, .-_ZSt7forwardINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEOT_RNSt16remove_referenceIS6_E4typeE
	.section	.text._ZSt7forwardIR7IntegerEOT_RNSt16remove_referenceIS2_E4typeE,"axG",@progbits,_ZSt7forwardIR7IntegerEOT_RNSt16remove_referenceIS2_E4typeE,comdat
	.weak	_ZSt7forwardIR7IntegerEOT_RNSt16remove_referenceIS2_E4typeE
	.type	_ZSt7forwardIR7IntegerEOT_RNSt16remove_referenceIS2_E4typeE, @function
_ZSt7forwardIR7IntegerEOT_RNSt16remove_referenceIS2_E4typeE:
.LFB1889:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1889:
	.size	_ZSt7forwardIR7IntegerEOT_RNSt16remove_referenceIS2_E4typeE, .-_ZSt7forwardIR7IntegerEOT_RNSt16remove_referenceIS2_E4typeE
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2028:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L32
	cmpl	$65535, -8(%rbp)
	jne	.L32
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L32:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2028:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z3MaxIPKcET_S2_S2_, @function
_GLOBAL__sub_I__Z3MaxIPKcET_S2_S2_:
.LFB2029:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2029:
	.size	_GLOBAL__sub_I__Z3MaxIPKcET_S2_S2_, .-_GLOBAL__sub_I__Z3MaxIPKcET_S2_S2_
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3MaxIPKcET_S2_S2_
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
