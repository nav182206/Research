/* 
 * Benchmark Sample ID : devign_4440
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4871b51b9241b10f4fd8e04bbb21577886795e25
 */

static void vmgenid_set_guid_test(void)

{

    QemuUUID expected, measured;

    gchar *cmd;



    g_assert(qemu_uuid_parse(VGID_GUID, &expected) == 0);



    cmd = g_strdup_printf("-machine accel=tcg -device vmgenid,id=testvgid,"

                          "guid=%s", VGID_GUID);

    qtest_start(cmd);



    /* Read the GUID from accessing guest memory */

    read_guid_from_memory(&measured);

    g_assert(memcmp(measured.data, expected.data, sizeof(measured.data)) == 0);



    qtest_quit(global_qtest);

    g_free(cmd);

}
