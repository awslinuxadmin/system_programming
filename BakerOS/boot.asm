ORG 0x7c00          ;this tells NASM where in memory
                    ; our program will run/execute
BITS 16             ; I'm going to use 16-bit code

start:                  ; marks the start of the program
    mov si, message     ; Address of 'message' - move to the SI register (Source Index)
    call print          ; call the print function
    jmp $               ; infinite loop, GOTO THIS instruction (halts program)

print:
    mov bx, 0          ; clear BX register to use as a counter (Base Register)
.loop:
    lodsb               ; load the byte at address SI into AL and increment SI
    cmp al, 0          ; comapre value in AL to o (end of string)
    je .done            ; If AL is 0, then wwe are at end of string - we're done
    call print_char     ; Otherwise, print the character in AL
    jmp .loop           ; loop to next character
.done:
    ret                 ; return from print function

print_char:
    mov ah, 0eh         ; mlve oeh into AH, BIOS servive number for printing a character
    int 0x10            ; call BIOS interrupt 0x10, handles screen operations
    ret                 ; return from print_char function
message: db 'Hello kernel program', 0 ; null-terminated string to be printed

times 510-($-$$) db 0   ; fill the rest of the sector with zeros up to 510 bytes

dw 0xAA55               ; boot sector signature