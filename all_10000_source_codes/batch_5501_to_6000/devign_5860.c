/* 
 * Benchmark Sample ID : devign_5860
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5839e53bbc0fec56021d758aab7610df421ed8c8
 */

void bdrv_iterate_format(void (*it)(void *opaque, const char *name),

                         void *opaque)

{

    BlockDriver *drv;

    int count = 0;

    const char **formats = NULL;



    QLIST_FOREACH(drv, &bdrv_drivers, list) {

        if (drv->format_name) {

            bool found = false;

            int i = count;

            while (formats && i && !found) {

                found = !strcmp(formats[--i], drv->format_name);

            }



            if (!found) {

                formats = g_realloc(formats, (count + 1) * sizeof(char *));

                formats[count++] = drv->format_name;

                it(opaque, drv->format_name);

            }

        }

    }

    g_free(formats);

}
