/* 
 * Benchmark Sample ID : devign_6489
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a980f7f2c2f4d7e9a1eba4f804cd66dbd458b6d4
 */

static void qvirtio_scsi_start(const char *extra_opts)

{

    char *cmdline;



    cmdline = g_strdup_printf(

                "-drive id=drv0,if=none,file=/dev/null,format=raw "

                "-device virtio-scsi-pci,id=vs0 "

                "-device scsi-hd,bus=vs0.0,drive=drv0 %s",

                extra_opts ? : "");

    qtest_start(cmdline);

    g_free(cmdline);

}
