/* 
 * Benchmark Sample ID : devign_8260
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5c8d6f008c0555b54cf10550fa86199a2cfabbca
 */

void css_generate_css_crws(uint8_t cssid)

{

    if (!channel_subsys.sei_pending) {

        css_queue_crw(CRW_RSC_CSS, CRW_ERC_EVENT, 0, cssid);

    }

    channel_subsys.sei_pending = true;

}
