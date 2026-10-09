/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9252
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=454b580ae9ae3e7722f1cd5f6da7bb479f86bbd8
 */

static sPAPRDIMMState *spapr_recover_pending_dimm_state(sPAPRMachineState *ms,

                                                        PCDIMMDevice *dimm)

{

    sPAPRDRConnector *drc;

    PCDIMMDeviceClass *ddc = PC_DIMM_GET_CLASS(dimm);

    MemoryRegion *mr = ddc->get_memory_region(dimm);

    uint64_t size = memory_region_size(mr);

    uint32_t nr_lmbs = size / SPAPR_MEMORY_BLOCK_SIZE;

    uint32_t avail_lmbs = 0;

    uint64_t addr_start, addr;

    int i;

    sPAPRDIMMState *ds;



    addr_start = object_property_get_int(OBJECT(dimm), PC_DIMM_ADDR_PROP,

                                         &error_abort);



    addr = addr_start;

    for (i = 0; i < nr_lmbs; i++) {

        drc = spapr_drc_by_id(TYPE_SPAPR_DRC_LMB,

                              addr / SPAPR_MEMORY_BLOCK_SIZE);

        g_assert(drc);

        if (drc->indicator_state != SPAPR_DR_INDICATOR_STATE_INACTIVE) {

            avail_lmbs++;

        }

        addr += SPAPR_MEMORY_BLOCK_SIZE;

    }



    ds = g_malloc0(sizeof(sPAPRDIMMState));

    ds->nr_lmbs = avail_lmbs;

    ds->dimm = dimm;

    spapr_pending_dimm_unplugs_add(ms, ds);

    return ds;

}
