/* 
 * Benchmark Sample ID : devign_4458
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c804c2a71752dd1e150cde768d8c54b02fa8bad9
 */

static int event_qdev_exit(DeviceState *qdev)

{

    SCLPEvent *event = DO_UPCAST(SCLPEvent, qdev, qdev);

    SCLPEventClass *child = SCLP_EVENT_GET_CLASS(event);

    if (child->exit) {

        child->exit(event);

    }

    return 0;

}
