/* 
 * Benchmark Sample ID : devign_1281
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b027a538c6790bcfc93ef7f4819fe3e581445959
 */

static int oss_poll_out (HWVoiceOut *hw)

{

    OSSVoiceOut *oss = (OSSVoiceOut *) hw;



    return qemu_set_fd_handler (oss->fd, NULL, oss_helper_poll_out, NULL);

}
