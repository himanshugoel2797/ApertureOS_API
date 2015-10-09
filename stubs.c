#include "syscalls.h"

uint64_t syscall_1arg(uint32_t syscall_num, uint64_t arg0)
{
    generic_syscall syscall;
    syscall.size = sizeof(generic_syscall);
    syscall.arg0 = arg0;
    syscall.retval = 0;
    SYSCALL(syscall_num, &syscall);
    return syscall.retval;
}

uint64_t syscall_2arg(uint32_t syscall_num, uint64_t arg0, uint64_t arg1)
{
    generic_syscall_2 syscall;
    syscall.size = sizeof(generic_syscall_2);
    syscall.arg0 = arg0;
    syscall.arg1 = arg1;
    syscall.retval = 0;
    SYSCALL(syscall_num, &syscall);
    return syscall.retval;
}

uint64_t syscall_3arg(uint32_t syscall_num, uint64_t arg0, uint64_t arg1, uint64_t arg2)
{
    generic_syscall_3 syscall;
    syscall.size = sizeof(generic_syscall_3);
    syscall.arg0 = arg0;
    syscall.arg1 = arg1;
    syscall.arg2 = arg2;
    syscall.retval = 0;
    SYSCALL(syscall_num, &syscall);
    return syscall.retval;
}

