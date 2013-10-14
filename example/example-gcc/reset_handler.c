/* Subset of an original file from libopencm3.
 * Licensed under LGPL. See libopencm3 license for details.
 */

#include <libopencm3/cm3/vector.h>

/* Symbols exported by the linker script(s): */
extern unsigned _data_loadaddr, _data, _edata, _ebss, _stack;
typedef void (*funcp_t) (void);
extern funcp_t __preinit_array_start, __preinit_array_end;
extern funcp_t __init_array_start, __init_array_end;
extern funcp_t __fini_array_start, __fini_array_end;

void reset_handler(void)
{
    volatile unsigned *src, *dest;
    funcp_t *fp;

    for (src = &_data_loadaddr, dest = &_data;
        dest < &_edata;
        src++, dest++) {
        *dest = *src;
    }

    while (dest < &_ebss) {
        *dest++ = 0;
    }

    /* Constructors. */
    for (fp = &__preinit_array_start; fp < &__preinit_array_end; fp++) {
        (*fp)();
    }
    for (fp = &__init_array_start; fp < &__init_array_end; fp++) {
        (*fp)();
    }

    /* might be provided by platform specific vector.c */
    /* pre_main(); */ /* not needed, mikroC already initializes the FPU */
}

