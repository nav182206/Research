/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4421
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1ff7df1a848044f58d0f3540f1447db4bb1d2d20
 */

void do_info_vnc(Monitor *mon)

{

    if (vnc_display == NULL || vnc_display->display == NULL)

        monitor_printf(mon, "VNC server disabled\n");

    else {

        monitor_printf(mon, "VNC server active on: ");

        monitor_print_filename(mon, vnc_display->display);

        monitor_printf(mon, "\n");



	if (vnc_display->clients == NULL)

            monitor_printf(mon, "No client connected\n");

	else

	    monitor_printf(mon, "Client connected\n");

    }

}
