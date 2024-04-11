section .data
    n dq 4 ; заданнное число
    msg db "ZYXWVUTSRQPONMLKJIHGFEDCBA"
    new_line db 0dh,0ah;
    msg_len db $ - msg
    

section .text
    global _start

_start:
   mov rbx,1


loop:

    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    add rsi, 26
    sub rsi, [n]
    mov rdx, rbx
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, new_line
    mov rdx, 2
    syscall


inc rbx
cmp rbx, [n]
jbe loop

mov rax, 60
mov rdi, 0
syscall