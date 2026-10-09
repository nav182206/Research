/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1301
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=482f7bf86b43af9f6903c52726fedf82b28bf953
 */

static void select_vgahw (const char *p)
{
    const char *opts;
    vga_interface_type = VGA_NONE;
    if (strstart(p, "std", &opts)) {
        if (vga_available()) {
            vga_interface_type = VGA_STD;
            fprintf(stderr, "Error: standard VGA not available\n");
            exit(0);
    } else if (strstart(p, "cirrus", &opts)) {
        if (cirrus_vga_available()) {
            vga_interface_type = VGA_CIRRUS;
            fprintf(stderr, "Error: Cirrus VGA not available\n");
            exit(0);
    } else if (strstart(p, "vmware", &opts)) {
        if (vmware_vga_available()) {
            vga_interface_type = VGA_VMWARE;
            fprintf(stderr, "Error: VMWare SVGA not available\n");
            exit(0);
    } else if (strstart(p, "xenfb", &opts)) {
        vga_interface_type = VGA_XENFB;
    } else if (strstart(p, "qxl", &opts)) {
        vga_interface_type = VGA_QXL;
    } else if (!strstart(p, "none", &opts)) {
    invalid_vga:
        fprintf(stderr, "Unknown vga type: %s\n", p);
        exit(1);
        const char *nextopt;
        if (strstart(opts, ",retrace=", &nextopt)) {
            if (strstart(opts, "dumb", &nextopt))
                vga_retrace_method = VGA_RETRACE_DUMB;
            else if (strstart(opts, "precise", &nextopt))
                vga_retrace_method = VGA_RETRACE_PRECISE;
            else goto invalid_vga;
        } else goto invalid_vga;
