/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1662
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1e9b65bb1bad51735cab6c861c29b592dccabf0e
 */

void error_setg_file_open(Error **errp, int os_errno, const char *filename)

{

    error_setg_errno(errp, os_errno, "Could not open '%s'", filename);

}
