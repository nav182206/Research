/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6663
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b0cd14fb1dab4b044f7fe6b53ac635409849de77
 */

static enum AVHWDeviceType hw_device_match_type_by_hwaccel(enum HWAccelID hwaccel_id)

{

    int i;

    if (hwaccel_id == HWACCEL_NONE)

        return AV_HWDEVICE_TYPE_NONE;

    for (i = 0; hwaccels[i].name; i++) {

        if (hwaccels[i].id == hwaccel_id)

            return hwaccels[i].device_type;

    }

    return AV_HWDEVICE_TYPE_NONE;

}
