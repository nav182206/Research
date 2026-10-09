/* 
 * Benchmark Sample ID : devign_755
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=98cb5dccb192b0082626080890dac413473573c6
 */

static void ahci_reg_init(AHCIState *s)

{

    int i;



    s->control_regs.cap = (s->ports - 1) |

                          (AHCI_NUM_COMMAND_SLOTS << 8) |

                          (AHCI_SUPPORTED_SPEED_GEN1 << AHCI_SUPPORTED_SPEED) |

                          HOST_CAP_NCQ | HOST_CAP_AHCI;



    s->control_regs.impl = (1 << s->ports) - 1;



    s->control_regs.version = AHCI_VERSION_1_0;



    for (i = 0; i < s->ports; i++) {

        s->dev[i].port_state = STATE_RUN;

    }

}
