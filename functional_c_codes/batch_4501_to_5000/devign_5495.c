/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5495
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4de484698bdda6c5e093dfbe4368cdb364fdf87f
 */

void ahci_command_wait(AHCIQState *ahci, AHCICommand *cmd)

{

    /* We can't rely on STS_BSY until the command has started processing.

     * Therefore, we also use the Command Issue bit as indication of

     * a command in-flight. */

    while (BITSET(ahci_px_rreg(ahci, cmd->port, AHCI_PX_TFD),

                  AHCI_PX_TFD_STS_BSY) ||

           BITSET(ahci_px_rreg(ahci, cmd->port, AHCI_PX_CI), (1 << cmd->slot))) {

        usleep(50);

    }

}
