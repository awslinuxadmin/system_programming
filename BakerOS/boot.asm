ORG 0x7c00          ;this tells NASM where in memory
                    ; our program will run/execute
BITS 16             ; I'm going to use 16-bit code

start:                  ; marks the start of the program
    mov si, message     ; Address of 'message' - move to the SI register (Source Index)
    call print          ; call the print function
    jmp $               ; infinite loop, GOTO THIS instruction (halts program)

print:
    mov bx, 0          ; clear BX register to use as a counter
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

; Summary of Functionality:
; ORG 0x7c00 specifies that the program is loaded at address `0x7C00` in memory  
; BITS 16 asserts that the code uses 16-bit instructions  
; start is the entry point of the program  
; mov si, message loads the address of the `message` string into the `SI` register  
; call print calls the `print` function to display the message
; jmp $ creates an infinite loop, effectively halting the program after printing the message  

; print is the function to print the strin
; .loop is the label for the loop that processes each character in the string 
; lodsb loads a byte from the address pointed to by `SI` into `AL` and increments `SI`
; cmp al, 0 compares the byte in `AL` to `0` (null terminator)
; je .done jumps to `.done` if `AL` is `0`, indicating the end of the string  
; call print_char calls the `print_char` function to print the character in `AL`  
; jmp .loop repeats the loop for the next characte
; done is the label for the end of the `print` function  
; ret returns from the `print` functio

; print_char is the function to print a single character  
; mov ah, 0eh moves `0Eh` into `AH`, the BIOS service number for printing a character 
; int 0x10 calls BIOS interrupt `0x10` to print the character in `AL` 
; ret returns from the `print_char` function  

; message is the null-terminated string to be printed: "Hello kernel program" 

; times 510-($-$$) db 0 fills the remaining bytes up to 510 with zeros to pad the boot sector 
; dw 0xAA55 is the boot sector signature, required for the BIOS to recognize the bootable disk
