/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2976
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void watchdog_add_model(WatchdogTimerModel *model)

{

    LIST_INSERT_HEAD(&watchdog_list, model, entry);

}
