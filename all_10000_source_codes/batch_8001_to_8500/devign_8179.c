/* 
 * Benchmark Sample ID : devign_8179
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d65b9114f35c1afe2a7061f0a1ec957d33ba02b5
 */

static int file_close_dir(URLContext *h)

{

#if HAVE_DIRENT_H

    FileContext *c = h->priv_data;

    closedir(c->dir);

    return 0;

#else

    return AVERROR(ENOSYS);

#endif /* HAVE_DIRENT_H */

}
