/* 
 * Benchmark Sample ID : devign_9629
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9a2fd4347c40321f5cbb4ab4220e759fcbf87d03
 */

qcrypto_tls_creds_x509_init(Object *obj)
{
    object_property_add_bool(obj, "loaded",
                             qcrypto_tls_creds_x509_prop_get_loaded,
                             qcrypto_tls_creds_x509_prop_set_loaded,
}
