/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2663
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e4e12bb26d9f2e2de02ff888063f41cc1e1b3935
 */

static void open_help(void)

{

    printf(

"\n"

" opens a new file in the requested mode\n"

"\n"

" Example:\n"

" 'open -Cn /tmp/data' - creates/opens data file read-write and uncached\n"

"\n"

" Opens a file for subsequent use by all of the other qemu-io commands.\n"

" -r, -- open file read-only\n"

" -s, -- use snapshot file\n"

" -n, -- disable host cache\n"

" -o, -- options to be given to the block driver"

"\n");

}
