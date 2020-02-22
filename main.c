#include <stdio.h>
#include "xreg.h"

DECLARE_XREG(test1, XREG_FLAGS_RD, NULL, NULL);
DECLARE_XREG(test2, XREG_FLAGS_RD, NULL, NULL);

int main(void)
{
    int i, j;

    j = Xreg_Length();
    printf(" Listing %d..\n", j);
    for (i = 0; i < j; i++)
    {
        printf("%d: %s\n", i, Xreg_Name(Xreg_Desc(i)));
    }

    return 0;
}
