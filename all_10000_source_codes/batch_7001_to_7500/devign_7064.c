/* 
 * Benchmark Sample ID : devign_7064
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e0cb42ae4bc4438ba4ec0760df2d830b8759b255
 */

static int xen_init(MachineState *ms)

{

    xen_xc = xen_xc_interface_open(0, 0, 0);

    if (xen_xc == XC_HANDLER_INITIAL_VALUE) {

        xen_be_printf(NULL, 0, "can't open xen interface\n");









    qemu_add_vm_change_state_handler(xen_change_state_handler, NULL);



    global_state_set_optional();

    savevm_skip_configuration();

    savevm_skip_section_footers();



    return 0;
