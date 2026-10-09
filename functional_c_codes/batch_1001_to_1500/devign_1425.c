/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1425
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f81e551229070f01bf747eda3f05960182db9d2a
 */

static uint64_t xscom_read(void *opaque, hwaddr addr, unsigned width)

{

    PnvChip *chip = opaque;

    uint32_t pcba = pnv_xscom_pcba(chip, addr);

    uint64_t val = 0;

    MemTxResult result;



    /* Handle some SCOMs here before dispatch */

    val = xscom_read_default(chip, pcba);

    if (val != -1) {

        goto complete;

    }



    val = address_space_ldq(&chip->xscom_as, pcba << 3, MEMTXATTRS_UNSPECIFIED,

                            &result);

    if (result != MEMTX_OK) {

        qemu_log_mask(LOG_GUEST_ERROR, "XSCOM read failed at @0x%"

                      HWADDR_PRIx " pcba=0x%08x\n", addr, pcba);

        xscom_complete(current_cpu, HMER_XSCOM_FAIL | HMER_XSCOM_DONE);

        return 0;

    }



complete:

    xscom_complete(current_cpu, HMER_XSCOM_DONE);

    return val;

}
