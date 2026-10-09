/* 
 * Benchmark Sample ID : devign_4155
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8be487d8f184f2f721cabeac559fb7a6cba18c95
 */

static void sdhci_end_transfer(SDHCIState *s)

{

    /* Automatically send CMD12 to stop transfer if AutoCMD12 enabled */

    if ((s->trnmod & SDHC_TRNS_ACMD12) != 0) {

        SDRequest request;

        uint8_t response[16];



        request.cmd = 0x0C;

        request.arg = 0;

        DPRINT_L1("Automatically issue CMD%d %08x\n", request.cmd, request.arg);

        sdbus_do_command(&s->sdbus, &request, response);

        /* Auto CMD12 response goes to the upper Response register */

        s->rspreg[3] = (response[0] << 24) | (response[1] << 16) |

                (response[2] << 8) | response[3];

    }



    s->prnsts &= ~(SDHC_DOING_READ | SDHC_DOING_WRITE |

            SDHC_DAT_LINE_ACTIVE | SDHC_DATA_INHIBIT |

            SDHC_SPACE_AVAILABLE | SDHC_DATA_AVAILABLE);



    if (s->norintstsen & SDHC_NISEN_TRSCMP) {

        s->norintsts |= SDHC_NIS_TRSCMP;

    }



    sdhci_update_irq(s);

}
