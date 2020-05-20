TITLE add

INCLUDE irvine32.inc
.data

val1 DWORD 10000h
val2 DWORD 40000h
val3 DWORD 20000h
finalVal DWORD ?
.code

MAIN PROC
	
	mov eax,val1
	mov ebx,val2

	add eax,ebx

	mov ebx,val3

	sub eax,ebx
	mov finalVal,eax
	call dumpregs
	call waitmsg
	exit

MAIN ENDP
END MAIN