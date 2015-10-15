#include "syscalls.h"

static generic_syscall syscall_1;
static generic_syscall_2 syscall_2;
static generic_syscall_3 syscall_3;

static void 
SYSCALL(uint32_t n, 
        void *addr)
{
    asm volatile("int $0x80" :: "b"(n), "c"(addr));
}

uint64_t 
syscall_1arg(uint32_t syscall_num, 
             uint64_t arg0)
{
    syscall_1.size = sizeof(generic_syscall);
    syscall_1.arg0 = arg0;
    syscall_1.retval = 0;
    SYSCALL(syscall_num, &syscall_1);
    return syscall_1.retval;
}

uint64_t 
syscall_2arg(uint32_t syscall_num, 
             uint64_t arg0, 
             uint64_t arg1)
{
    syscall_2.size = sizeof(generic_syscall_2);
    syscall_2.arg0 = arg0;
    syscall_2.arg1 = arg1;
    syscall_2.retval = 0;
    SYSCALL(syscall_num, &syscall_2);
    return syscall_2.retval;
}

uint64_t 
syscall_3arg(uint32_t syscall_num, 
             uint64_t arg0, 
             uint64_t arg1, 
             uint64_t arg2)
{
    syscall_3.size = sizeof(generic_syscall_3);
    syscall_3.arg0 = arg0;
    syscall_3.arg1 = arg1;
    syscall_3.arg2 = arg2;
    syscall_3.retval = 0;
    SYSCALL(syscall_num, &syscall_3);
    return syscall_3.retval;
}

uint32_t 
aos_getDisplayInfo(DisplayInfo *info)
{
    if(info == NULL)return -1;
    return syscall_3arg(GETDATA_SYSCALL_NUM, APEROS_ENV_DATA, APEROS_DISPLAY_INFO, (uint32_t)info);
}

uint64_t 
aos_getPID(void)
{
    return syscall_3arg(GETDATA_SYSCALL_NUM, APEROS_PROC_DATA, APEROS_PROC_ID, 0);
}