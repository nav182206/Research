/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3366
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b1424e0381a7f1c9969079eca4458d5f20bf1859
 */

DisplaySurface *qemu_create_displaysurface_from(int width, int height, int bpp,

                                                int linesize, uint8_t *data)

{

    DisplaySurface *surface = g_new0(DisplaySurface, 1);



    surface->pf = qemu_default_pixelformat(bpp);



    surface->format = qemu_pixman_get_format(&surface->pf);

    assert(surface->format != 0);

    surface->image = pixman_image_create_bits(surface->format,

                                              width, height,

                                              (void *)data, linesize);

    assert(surface->image != NULL);



#ifdef HOST_WORDS_BIGENDIAN

    surface->flags = QEMU_BIG_ENDIAN_FLAG;

#endif



    return surface;

}
