#ifndef _AOS_DIPLAY_INFO_H_
#define _AOS_DIPLAY_INFO_H_

#include <stdint.h>

typedef struct
{
 uint32_t width;
 uint32_t height;
 uint32_t colorDepth;
 uint32_t *framebuffer_addr;
 uint32_t *backbuffer_addr;
} DisplayInfo;

#endif