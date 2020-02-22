#ifndef _XREG_H_
#define _XREG_H_

#include <stdint.h>
#include <stddef.h>
#include "error.h"

#ifdef __GNUC__
#  define __UNUSED __attribute__((__unused__))
#else
#  define __UNUSED
#endif

#define XREG_FLAGS_RD	(1U<<0)
#define XREG_FLAGS_WR	(1U<<1)

typedef eError (*tXregOnRead)(uint8_t instance, uint32_t *value);
typedef eError (*tXregOnWrite)(uint8_t instance, uint32_t value);

typedef struct {
    char name[20];
    uint8_t flags;   
    tXregOnRead onRead;
    tXregOnWrite onWrite;
    uint32_t* value;
} tXregDescriptor;

#define DECLARE_XREG(_name, _flags, _on_read, _on_write) \
    static uint32_t xreg_##_name; \
    static const tXregDescriptor xreg_desc_##_name = { \
        .name = #_name, \
        .flags = _flags, \
        .onRead = _on_read, \
        .onWrite = _on_write, \
        .value = &xreg_##_name, \
    }; \
    static const tXregDescriptor* const xreg_desc_##_name##_ptr __UNUSED __attribute__((section("xreg_desc"))) = &xreg_desc_##_name;

int Xreg_Length(void);
const tXregDescriptor* Xreg_Desc(int xreg_idx);
const char* const Xreg_Name(const tXregDescriptor* xreg_desc);

#endif
