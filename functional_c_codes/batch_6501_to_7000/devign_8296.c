/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8296
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2ff30257974e19ebe2a97baad32ac29c06da5fb9
 */

void qmp_migrate_set_downtime(double value, Error **errp)

{

    value *= 1e9;

    value = MAX(0, MIN(UINT64_MAX, value));

    max_downtime = (uint64_t)value;

}
