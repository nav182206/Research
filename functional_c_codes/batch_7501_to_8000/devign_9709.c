/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9709
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=80eecda8e5d09c442c24307f340840a5b70ea3b9
 */

static int is_rndis(USBNetState *s)

{

    return s->dev.config->bConfigurationValue == DEV_RNDIS_CONFIG_VALUE;

}
