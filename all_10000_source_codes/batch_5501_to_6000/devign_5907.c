/* 
 * Benchmark Sample ID : devign_5907
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=661e32fb3cb71c7e019daee375be4bb487b9917c
 */

static void virtio_scsi_bad_req(void)

{

    error_report("wrong size for virtio-scsi headers");

    exit(1);

}
