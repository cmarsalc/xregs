#include "xreg.h"
#include <stdio.h>

extern tXregDescriptor* __start_xreg_desc[];
extern tXregDescriptor* __end_xreg_desc[];

int Xreg_Length(void)
{
    size_t start = (size_t)&__start_xreg_desc;
    size_t end = (size_t)&__end_xreg_desc;
    int elem = (end - start) / sizeof(tXregDescriptor*);
    return elem;
}

const tXregDescriptor* Xreg_Desc(int xreg_idx)
{
    const tXregDescriptor* result;

    if (xreg_idx < Xreg_Length())
    {
        result = __start_xreg_desc[xreg_idx];
    }
    else
    {
        result = NULL;
    }

    return result;
}

const char* const Xreg_Name(const tXregDescriptor* xreg_desc)
{
    const char* result;

    if (xreg_desc != NULL) 
    {
        result = xreg_desc->name; 
    }
    else
    {
        result = "xreg_OOR";
    }

    return result;
}
