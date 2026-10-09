/* 
 * Benchmark Sample ID : devign_7135
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee9a569ab88edd0755402aaf31ec0c69decf7756
 */

static void spapr_tce_reset(DeviceState *dev)

{

    sPAPRTCETable *tcet = SPAPR_TCE_TABLE(dev);

    size_t table_size = tcet->nb_table * sizeof(uint64_t);



    tcet->bypass = false;

    memset(tcet->table, 0, table_size);

}
