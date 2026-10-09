/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9436
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f81e551229070f01bf747eda3f05960182db9d2a
 */

static void xscom_write(void *opaque, hwaddr addr, uint64_t val,

                        unsigned width)

{

    PnvChip *chip = opaque;

    uint32_t pcba = pnv_xscom_pcba(chip, addr);

    MemTxResult result;



    /* Handle some SCOMs here before dispatch */

    if (xscom_write_default(chip, pcba, val)) {

        goto complete;

    }



    address_space_stq(&chip->xscom_as, pcba << 3, val, MEMTXATTRS_UNSPECIFIED,

                      &result);

    if (result != MEMTX_OK) {

        qemu_log_mask(LOG_GUEST_ERROR, "XSCOM write failed at @0x%"

                      HWADDR_PRIx " pcba=0x%08x data=0x%" PRIx64 "\n",

                      addr, pcba, val);

        xscom_complete(current_cpu, HMER_XSCOM_FAIL | HMER_XSCOM_DONE);

        return;

    }



complete:

    xscom_complete(current_cpu, HMER_XSCOM_DONE);

}
