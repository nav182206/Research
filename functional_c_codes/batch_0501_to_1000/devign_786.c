/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_786
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6df5718bd3ec56225c44cf96440c723c1b611b87
 */

static void megasas_reset_frames(MegasasState *s)

{

    PCIDevice *pcid = PCI_DEVICE(s);

    int i;

    MegasasCmd *cmd;



    for (i = 0; i < s->fw_cmds; i++) {

        cmd = &s->frames[i];

        if (cmd->pa) {

            pci_dma_unmap(pcid, cmd->frame, cmd->pa_size, 0, 0);

            cmd->frame = NULL;

            cmd->pa = 0;

        }

    }

}
