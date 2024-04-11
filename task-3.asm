section .bss
inp: resb 255
out_e: resb 255

section .data
msg1 db "Введите строку: ", 0h
msg2 db "Четных: ", 0Ah, 0h

section .text
global _start

_start:
    mov    eax, msg1
    call   stprint

    mov    edx, 255
    mov    ecx, inp
    mov    ebx, 0
    mov    eax, 3
    int    80h

    call   findeven

    mov    eax, msg2
    call   stprint

    mov    ecx, out_e
    mov    edx, 254
    mov    ebx, 1
    mov    eax, 4
    int    80h

    push   0Ah
    mov    eax, esp
    call   stprint
    add    esp, 4




    mov    eax, inp
    call   stprint

    mov    ebx, 0
    mov    eax, 1
    int    80h

findeven:
    push   eax
    push   esi
    push   ebx
   
    mov    esi, -1
    mov    eax, inp

.loop:
    inc    esi
    cmp    byte [eax+esi], 0
    jz     .finish
    test   esi, 1

    jz     .loop

    jmp    .itseven
 
.itseven:
    push  ebx
    mov   ebx, 0
    mov   bl, byte [eax+esi]
    mov   byte [out_e+esi], bl
    pop   ebx
    jmp   .loop

.finish:
    pop    eax                  
    pop    esi                  
    pop    ebx                   
    ret  

stprint:
    push    edx
    push    ecx
    push    ebx
    push    eax
    call    stlen

    mov     edx, eax
    pop     eax

    mov     ecx, eax
    mov     ebx, 1
    mov     eax, 4
    int     80h

    pop     ebx
    pop     ecx
    pop     edx
    ret

stlen:
    push    ebx
    mov     ebx, eax

nextch:
    cmp     byte [eax], 0
    jz      finish
    inc     eax
    jmp     nextch

finish:
    sub     eax, ebx
    pop     ebx
    ret