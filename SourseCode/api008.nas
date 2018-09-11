[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]
[FILE "api008.nas"]

		GLOBAL	_api_initmalloc

[SECTION .text]

_api_initmalloc:	; void api_initmalloc(void);
		PUSH	EBX
		MOV		EDX,8
		MOV		EBX,[CS:0x0020]		; malloc的大小
		MOV		EAX,EBX
		ADD		EAX,32*1024			; 32KB足?了
		MOV		ECX,[CS:0x0000]		; 数据段的大小
		SUB		ECX,EAX
		INT		0x40
		POP		EBX
		RET
