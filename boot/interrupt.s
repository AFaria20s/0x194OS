.section .text
.global keyboard_wrapper
// Simple wrapper for the keyboard handler
keyboard_wrapper:
    pusha
    call keyboard_handler
    popa
    iret