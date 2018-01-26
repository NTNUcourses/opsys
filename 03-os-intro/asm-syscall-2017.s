# husk: 
# evn sed -i 's/main/main/g' asm-syscall-2017.s
# og gcc -o asm-syscall-2017 asm-syscall-2017.s -nostdlib

.data
str:
        .ascii "hello world\n"
.text
.global main
main:
    movq $1, %rax   # use the write syscall
    movq $1, %rdi   # write to stdout
    movq $str, %rsi # use string "Hello World"
    movq $12, %rdx  # write 12 characters
    syscall         # make syscall
    
    movq $60, %rax  # use the _exit syscall
    movq $0, %rdi   # error code 0
    syscall         # make syscall
