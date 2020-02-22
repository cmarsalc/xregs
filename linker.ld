SECTIONS
{
    .rel.rodata_xreg_desc : {
        PROVIDE(__start_xreg_desc = .);
        *(xreg_desc)
        PROVIDE(__end_xreg_desc = .);
    }
}
INSERT AFTER .text;
