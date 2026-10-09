/* 
 * Benchmark Sample ID : devign_327
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static void omap_rtc_alarm_update(struct omap_rtc_s *s)

{

    s->alarm_ti = mktimegm(&s->alarm_tm);

    if (s->alarm_ti == -1)

        printf("%s: conversion failed\n", __FUNCTION__);

}
