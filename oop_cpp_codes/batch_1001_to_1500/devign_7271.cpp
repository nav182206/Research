/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7271
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=967b75230b9720ea2b3ae49f38f8287026125f9f
 */

static void pnv_chip_power8e_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    PnvChipClass *k = PNV_CHIP_CLASS(klass);



    k->cpu_model = "POWER8E";

    k->chip_type = PNV_CHIP_POWER8E;

    k->chip_cfam_id = 0x221ef04980000000ull;  /* P8 Murano DD2.1 */

    k->cores_mask = POWER8E_CORE_MASK;

    k->core_pir = pnv_chip_core_pir_p8;


    dc->desc = "PowerNV Chip POWER8E";

}
