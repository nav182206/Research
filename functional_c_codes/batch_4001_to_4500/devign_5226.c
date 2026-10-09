/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5226
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=13412c9d2fce7c402e93a08177abdbc593208140
 */

void do_info_vnc(void)

{

    if (vnc_state == NULL)

	term_printf("VNC server disabled\n");

    else {

	term_printf("VNC server active on: ");

	term_print_filename(vnc_state->display);

	term_printf("\n");



	if (vnc_state->csock == -1)

	    term_printf("No client connected\n");

	else

	    term_printf("Client connected\n");

    }

}
