/* 
 * Benchmark Sample ID : devign_476
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5b120785e70a9a48b43e3f1f156a10a015334a28
 */

int spapr_h_cas_compose_response(sPAPRMachineState *spapr,

                                 target_ulong addr, target_ulong size,

                                 bool cpu_update,

                                 sPAPROptionVector *ov5_updates)

{

    void *fdt, *fdt_skel;

    sPAPRDeviceTreeUpdateHeader hdr = { .version_id = 1 };



    size -= sizeof(hdr);



    /* Create sceleton */

    fdt_skel = g_malloc0(size);

    _FDT((fdt_create(fdt_skel, size)));

    _FDT((fdt_begin_node(fdt_skel, "")));

    _FDT((fdt_end_node(fdt_skel)));

    _FDT((fdt_finish(fdt_skel)));

    fdt = g_malloc0(size);

    _FDT((fdt_open_into(fdt_skel, fdt, size)));

    g_free(fdt_skel);



    /* Fixup cpu nodes */

    if (cpu_update) {

        _FDT((spapr_fixup_cpu_dt(fdt, spapr)));

    }



    if (spapr_dt_cas_updates(spapr, fdt, ov5_updates)) {

        return -1;

    }



    /* Pack resulting tree */

    _FDT((fdt_pack(fdt)));



    if (fdt_totalsize(fdt) + sizeof(hdr) > size) {

        trace_spapr_cas_failed(size);

        return -1;

    }



    cpu_physical_memory_write(addr, &hdr, sizeof(hdr));

    cpu_physical_memory_write(addr + sizeof(hdr), fdt, fdt_totalsize(fdt));

    trace_spapr_cas_continue(fdt_totalsize(fdt) + sizeof(hdr));

    g_free(fdt);



    return 0;

}
