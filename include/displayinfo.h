#ifndef _AOS_DIPLAY_INFO_H_
#define _AOS_DIPLAY_INFO_H_

#include <stdint.h>

//! Display related information, can be requested by programs
typedef struct
{
    uint32_t size;                 //!< The size of this structure
    uint32_t width;                //!< The width of the main display
    uint32_t height;               //!< The height of the main display
    uint32_t bpp;                  //!< The bytes per pixel
    uint32_t pitch;
    uint32_t *framebuffer_addr;    //!< The virtual address in kernel memory of the main framebuffer
    uint32_t *backbuffer_addr;     //!< The virtual address in kernel memory of the backbuffer
} DisplayInfo;

#endif