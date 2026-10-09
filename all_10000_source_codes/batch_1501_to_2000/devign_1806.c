/* 
 * Benchmark Sample ID : devign_1806
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=36b62ae6a58f9a588fd33be9386e18a2b90103f5
 */

static void fw_cfg_data_mem_write(void *opaque, hwaddr addr,

                                  uint64_t value, unsigned size)

{

    FWCfgState *s = opaque;

    uint8_t buf[8];

    unsigned i;



    switch (size) {

    case 1:

        buf[0] = value;

        break;

    case 2:

        stw_he_p(buf, value);

        break;

    case 4:

        stl_he_p(buf, value);

        break;

    case 8:

        stq_he_p(buf, value);

        break;

    default:

        abort();

    }

    for (i = 0; i < size; ++i) {

        fw_cfg_write(s, buf[i]);

    }

}
