/* 
 * Benchmark Sample ID : devign_8965
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4438c8a9469d79fa2c58189418befb506da54d97
 */

static void map_exec(void *addr, long size)

{

    DWORD old_protect;

    VirtualProtect(addr, size,

                   PAGE_EXECUTE_READWRITE, &old_protect);

    

}
