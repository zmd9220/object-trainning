INCLUDE irvine32.inc

.data
.code
main PROC
	mov eax, 0h
	mov ebx, 0h
	mov ax, 2000h
	mov bx, 1000h
	add ax, bx
	call dumpregs
	call waitmsg
	
	mov ecx, 1000h
	add has, 3000h
	call dumpregs
	call waitmsg
	
	exit
main ENDP
END main


