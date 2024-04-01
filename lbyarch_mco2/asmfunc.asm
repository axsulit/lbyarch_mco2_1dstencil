section .data
output_hold dq 0.0
msg1 db "(ASM) Output: Y -> %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf, %.4lf . . .", 10, 0

section .text
bits 64
default rel

global asm_dStencil
extern printf

asm_dStencil:   
    sub rsp, 8*11       
    
    mov r12, rcx ; n
    mov r13, rdx ; X
    mov r14, r8  ; Y
    
    ; displacement variables
    mov rbx, 3
    mov r11, 0

LOOP:
    ; check if all elements of Y are identified
    cmp r11, r12
    je print_output
    
    ; stencil operation
    movsd xmm5, [r13 - 24 + 8*rbx] 
    addsd xmm5, [r13 - 16 + 8*rbx]
    addsd xmm5, [r13 - 8 + 8*rbx]
    addsd xmm5, [r13 + 8*rbx]
    addsd xmm5, [r13 + 8 + 8*rbx]
    addsd xmm5, [r13 + 16 + 8*rbx]
    addsd xmm5, [r13 + 24 + 8*rbx]
    
    ; store result in Y
    movsd [r14 + 8*r11], xmm5
    
    inc rbx
    inc r11
    jmp LOOP

print_output:
    cmp r11, 10
    jg limit_10

    cmp r11, 3
    jg output_loop
    
    cmp r11, 3
    je print_three
    
    cmp r11, 2
    je print_two
    
    cmp r11, 1
    je print_one
    
    cmp r11, 0
    je end
    
    limit_10:
        mov r11, 10
        jmp output_loop
    
    output_loop:
        cmp r11, 3
        je print_three
        
        ;Get 3rd-9th index in Y
        movsd xmm6, [r14 - 8 + 8*r11]
        movsd qword [output_hold], xmm6
        mov rax, [output_hold]
        mov [rsp + 8*r11], rax
        
        dec r11
        
        jmp output_loop
    
    print_three:
        ; Get 2nd index in Y
        movsd xmm6, [r14 + 8*2]
        movsd qword [output_hold], xmm6
        mov r9, [output_hold]
        
    print_two:
        ; Get 1st index in Y
        movsd xmm6, [r14 + 8]
        movsd qword [output_hold], xmm6
        mov r8, [output_hold]
        
    print_one:
        ; Get 0th index in Y
        movsd xmm6, [r14]
        movsd qword [output_hold], xmm6
        mov rdx, [output_hold]
    
    jmp end

end:
    mov rcx, msg1
    call printf
    
    add rsp, 8*11
    mov rax, r14 ; return Y

    ret       