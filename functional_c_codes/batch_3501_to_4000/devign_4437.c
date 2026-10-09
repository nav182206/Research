/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4437
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f7c31d6381f2cbac03e82fc23133f6863606edd8
 */

int net_handle_fd_param(Monitor *mon, const char *param)

{

    if (!qemu_isdigit(param[0])) {

        int fd;



        fd = monitor_get_fd(mon, param);

        if (fd == -1) {

            error_report("No file descriptor named %s found", param);

            return -1;

        }



        return fd;

    } else {

        return strtol(param, NULL, 0);

    }

}
