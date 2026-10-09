/* 
 * Benchmark Sample ID : devign_538
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2a7e8dda090af586f3d0b3d157054a9e18776a52
 */

static void do_change_vnc(const char *target)

{

    if (strcmp(target, "passwd") == 0 ||

	strcmp(target, "password") == 0) {

	char password[9];

	monitor_readline("Password: ", 1, password, sizeof(password)-1);

	password[sizeof(password)-1] = '\0';

	if (vnc_display_password(NULL, password) < 0)

	    term_printf("could not set VNC server password\n");

    } else {

	if (vnc_display_open(NULL, target) < 0)

	    term_printf("could not start VNC server on %s\n", target);

    }

}
