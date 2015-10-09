#ifndef _AOS_SYSCALLS_H_
#define _AOS_SYSCALLS_H_

#include <stdint.h>

#define SYSCALL(x, y) asm volatile("int $0x80" :: "b"(x), "c"(y))

#define GETDATA_SYSCALL_NUM 7           //*< get data about the environment
#define MALLOC_SYSCALL_NUM 8            //*< userspace malloc, allocate a page to the next continuous virtual address

//* The type of the data to access
typedef enum
{
    APEROS_ENV_DATA = 0,    //*< Get environment data
    APEROS_PROC_DATA = 1    //*< Get process data
} APEROS_DATA_TYPE;

//* The kind of environment data to access
typedef enum
{
    APEROS_ENV_VAR = 1,           //*< Get a list of environment variables
    APEROS_DISPLAY_INFO = 2,      //*< Get the display information
} APEROS_ENV;

//* The kind of process data to access
typedef enum
{
    APEROS_PROC_DATA_ARGC = 1,  //*< Get the number of arguments passed to the process
    APEROS_PROC_DATA_ARGV = 2,  //*< Get the values of the args passed to the process
    APEROS_PROC_ID = 3,          //*< Get the process ID
} APEROS_PROC;

typedef struct
{
    uint32_t size;
    uint64_t arg0;
    uint64_t retval;
} generic_syscall;

typedef struct
{
    uint32_t size;
    uint64_t arg0;
    uint64_t arg1;
    uint64_t retval;
} generic_syscall_2;

typedef struct
{
    uint32_t size;
    uint64_t arg0;
    uint64_t arg1;
    uint64_t arg2;
    uint64_t retval;
} generic_syscall_3;

#endif