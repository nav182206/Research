/* 
 * Benchmark Sample ID : devign_3308
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=40ff6d7e8dceca227e7f8a3e8e0d58b2c66d19b4
 */

static int hpet_start_timer(struct qemu_alarm_timer *t)

{

    struct hpet_info info;

    int r, fd;



    fd = open("/dev/hpet", O_RDONLY);

    if (fd < 0)

        return -1;



    /* Set frequency */

    r = ioctl(fd, HPET_IRQFREQ, RTC_FREQ);

    if (r < 0) {

        fprintf(stderr, "Could not configure '/dev/hpet' to have a 1024Hz timer. This is not a fatal\n"

                "error, but for better emulation accuracy type:\n"

                "'echo 1024 > /proc/sys/dev/hpet/max-user-freq' as root.\n");

        goto fail;

    }



    /* Check capabilities */

    r = ioctl(fd, HPET_INFO, &info);

    if (r < 0)

        goto fail;



    /* Enable periodic mode */

    r = ioctl(fd, HPET_EPI, 0);

    if (info.hi_flags && (r < 0))

        goto fail;



    /* Enable interrupt */

    r = ioctl(fd, HPET_IE_ON, 0);

    if (r < 0)

        goto fail;



    enable_sigio_timer(fd);

    t->priv = (void *)(long)fd;



    return 0;

fail:

    close(fd);

    return -1;

}
