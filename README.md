# xregs
Proof of concept for the xregs concept.

The idea behind this component is that it should be able to read/write registers of up to 32-bit sizes and also read/write buffers in and out.
These registers and buffers are then associated to a component and serve as a gateway to externally inspect or instruct components.

In order to avoid a central module to store the list of these registers (kind of a xreg repository) linker tables are used.

Caution should be taken about platform specific alignments and padding when computing xreg descriptors offset.

Some typical alignment behavior:
- uint16_t is usually 16-bit aligned to avoid rotation and masking from bus-wide aligned data
- uint32_t is usually 32-bit aligned for the same reason
- uint64_t is usually 64-bit aligned for the same reason
- structs in PC are usually 64-byte aligned to align with cache lines

https://en.wikipedia.org/wiki/Data_structure_alignment

To make the code portable a platform header should exist where alignment behavior is considered.
