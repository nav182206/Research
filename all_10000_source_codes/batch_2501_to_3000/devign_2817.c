/* 
 * Benchmark Sample ID : devign_2817
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2569da0cb64506ea05323544c26f3aaffbf3f9fe
 */

static void do_change(const char *device, const char *target, const char *fmt)

{

    if (strcmp(device, "vnc") == 0) {

	do_change_vnc(target);

    } else {

	do_change_block(device, target, fmt);

    }

}
