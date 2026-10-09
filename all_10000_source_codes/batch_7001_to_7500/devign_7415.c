/* 
 * Benchmark Sample ID : devign_7415
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c1755b14fade16f02d3e10a487a03741a2f317ce
 */

uint16_t css_build_subchannel_id(SubchDev *sch)

{

    if (channel_subsys.max_cssid > 0) {

        return (sch->cssid << 8) | (1 << 3) | (sch->ssid << 1) | 1;

    }

    return (sch->ssid << 1) | 1;

}
