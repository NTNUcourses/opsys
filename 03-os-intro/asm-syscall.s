.data
str:
        .ascii "hello world\n"
.text
.globl main
main:
        movl    $4, %eax   # system call number (sys_write)
        movl    $1, %ebx   # first argument: file handle (stdout)
        movl    $str, %ecx # second argument: message to write
        movl    $13, %edx  # third argument: message length
        int     $0x80      # call kernel

        movl    $1, %eax   # system call number (sys_exit)
        movl    $0, %ebx   # first argument: exit code
        int     $0x80      # call kernel
