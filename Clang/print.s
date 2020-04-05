	.file	"print.c"
	.text
Ltext0:
	.comm	_test, 20, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "%4.1f\12\0"
LC2:
	.ascii "%c\12 %c\12\0"
LC3:
	.ascii "%d %d %x\12\0"
LC4:
	.ascii "%d\12\0"
LC5:
	.ascii "hello, world\0"
LC6:
	.ascii ":%s:\12\0"
LC7:
	.ascii ":%10s:\12\0"
LC8:
	.ascii ":%.10s:\12\0"
LC9:
	.ascii ":%-10s:\12\0"
LC10:
	.ascii ":%.15s:\12\0"
LC11:
	.ascii ":%-15s:\12\0"
LC12:
	.ascii ":%15.10s:\12\0"
LC13:
	.ascii ":%-15.10s:\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.file 1 "print.c"
	.loc 1 6 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	.loc 1 6 1
	call	___main
LVL0:
	.loc 1 7 5
	fldl	LC0
	fstpl	4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	.loc 1 10 10
	movb	$-103, 31(%esp)
	.loc 1 12 10
	movb	$50, 30(%esp)
	.loc 1 14 5
	movsbl	30(%esp), %edx
	movsbl	31(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	.loc 1 23 5
	movl	$18, 12(%esp)
	movl	$17, 8(%esp)
	movl	$0, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	.loc 1 25 5
	movl	$20, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	.loc 1 27 11
	movl	$LC5, 24(%esp)
	.loc 1 29 5
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	.loc 1 31 5
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	.loc 1 33 5
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	.loc 1 34 5
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	.loc 1 35 5
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	.loc 1 36 5
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_printf
	.loc 1 37 5
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	.loc 1 38 5
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
	.loc 1 39 5
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_printf
	movl	$0, %eax
	.loc 1 40 1
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.section .rdata,"dr"
	.align 8
LC0:
	.long	1717986918
	.long	1074816614
	.text
Letext0:
	.file 2 "d:/program files/mingw/include/stdio.h"
	.section	.debug_info,"dr"
Ldebug_info0:
	.long	0x1fa
	.word	0x4
	.secrel32	Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.ascii "GNU C17 8.2.0 -mtune=generic -march=i586 -g\0"
	.byte	0xc
	.ascii "print.c\0"
	.ascii "D:\\GitHub\\my_learning\\Clang\0"
	.long	Ltext0
	.long	Letext0-Ltext0
	.secrel32	Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x3
	.ascii "_iobuf\0"
	.byte	0x20
	.byte	0x2
	.byte	0xd2
	.byte	0x10
	.long	0x14b
	.uleb128 0x4
	.ascii "_ptr\0"
	.byte	0x2
	.byte	0xd4
	.byte	0x9
	.long	0x14b
	.byte	0
	.uleb128 0x4
	.ascii "_cnt\0"
	.byte	0x2
	.byte	0xd5
	.byte	0x7
	.long	0xac
	.byte	0x4
	.uleb128 0x4
	.ascii "_base\0"
	.byte	0x2
	.byte	0xd6
	.byte	0x9
	.long	0x14b
	.byte	0x8
	.uleb128 0x4
	.ascii "_flag\0"
	.byte	0x2
	.byte	0xd7
	.byte	0x7
	.long	0xac
	.byte	0xc
	.uleb128 0x4
	.ascii "_file\0"
	.byte	0x2
	.byte	0xd8
	.byte	0x7
	.long	0xac
	.byte	0x10
	.uleb128 0x4
	.ascii "_charbuf\0"
	.byte	0x2
	.byte	0xd9
	.byte	0x7
	.long	0xac
	.byte	0x14
	.uleb128 0x4
	.ascii "_bufsiz\0"
	.byte	0x2
	.byte	0xda
	.byte	0x7
	.long	0xac
	.byte	0x18
	.uleb128 0x4
	.ascii "_tmpfname\0"
	.byte	0x2
	.byte	0xdb
	.byte	0x9
	.long	0x14b
	.byte	0x1c
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.long	0xb3
	.uleb128 0x6
	.ascii "FILE\0"
	.byte	0x2
	.byte	0xdc
	.byte	0x3
	.long	0xbb
	.uleb128 0x7
	.long	0x151
	.long	0x169
	.uleb128 0x8
	.byte	0
	.uleb128 0x9
	.ascii "_iob\0"
	.byte	0x2
	.byte	0xef
	.byte	0x2c
	.long	0x15e
	.uleb128 0x7
	.long	0xac
	.long	0x186
	.uleb128 0xa
	.long	0x69
	.byte	0x4
	.byte	0
	.uleb128 0xb
	.ascii "test\0"
	.byte	0x1
	.byte	0x3
	.byte	0x5
	.long	0x176
	.uleb128 0x5
	.byte	0x3
	.long	_test
	.uleb128 0xc
	.ascii "main\0"
	.byte	0x1
	.byte	0x5
	.byte	0x5
	.long	0xac
	.long	LFB13
	.long	LFE13-LFB13
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.ascii "c\0"
	.byte	0x1
	.byte	0xa
	.byte	0xa
	.long	0xb3
	.uleb128 0x2
	.byte	0x74
	.sleb128 31
	.uleb128 0xd
	.ascii "d\0"
	.byte	0x1
	.byte	0xc
	.byte	0xa
	.long	0xb3
	.uleb128 0x2
	.byte	0x74
	.sleb128 30
	.uleb128 0xe
	.ascii "a\0"
	.byte	0x7
	.byte	0x4
	.long	0x69
	.byte	0x1
	.byte	0x10
	.byte	0xa
	.long	0x1ea
	.uleb128 0xf
	.ascii "a1\0"
	.byte	0
	.uleb128 0xf
	.ascii "a2\0"
	.byte	0x11
	.uleb128 0xf
	.ascii "a3\0"
	.byte	0x12
	.byte	0
	.uleb128 0xd
	.ascii "string\0"
	.byte	0x1
	.byte	0x1b
	.byte	0xb
	.long	0x14b
	.uleb128 0x2
	.byte	0x74
	.sleb128 24
	.byte	0
	.byte	0
	.section	.debug_abbrev,"dr"
Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"dr"
	.long	0x1c
	.word	0x2
	.secrel32	Ldebug_info0
	.byte	0x4
	.byte	0
	.word	0
	.word	0
	.long	Ltext0
	.long	Letext0-Ltext0
	.long	0
	.long	0
	.section	.debug_line,"dr"
Ldebug_line0:
	.section	.debug_str,"dr"
	.ident	"GCC: (MinGW.org GCC-8.2.0-5) 8.2.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
