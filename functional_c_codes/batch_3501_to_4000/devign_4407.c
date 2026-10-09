/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4407
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad4aca69bbd40663ca93a3eb1d8042c023b9b407
 */

TPMVersion tpm_tis_get_tpm_version(Object *obj)
{
    TPMState *s = TPM(obj);
    return tpm_backend_get_tpm_version(s->be_driver);
