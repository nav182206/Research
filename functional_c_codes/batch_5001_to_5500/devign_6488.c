/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6488
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3dc6f8693694a649a9c83f1e2746565b47683923
 */

ISADevice *pc_find_fdc0(void)

{

    int i;

    Object *container;

    CheckFdcState state = { 0 };



    for (i = 0; i < ARRAY_SIZE(fdc_container_path); i++) {

        container = container_get(qdev_get_machine(), fdc_container_path[i]);

        object_child_foreach(container, check_fdc, &state);

    }



    if (state.multiple) {

        error_report("warning: multiple floppy disk controllers with "

                     "iobase=0x3f0 have been found");

        error_printf("the one being picked for CMOS setup might not reflect "

                     "your intent\n");

    }



    return state.floppy;

}
