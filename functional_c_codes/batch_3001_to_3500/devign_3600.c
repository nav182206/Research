/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3600
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=97f3ad35517e0d02c0149637d1bb10713c52b057
 */

QEMUFile *qemu_fopen(const char *filename, const char *mode)

{

    QEMUFileStdio *s;



    if (qemu_file_mode_is_not_valid(mode)) {

        return NULL;

    }



    s = g_malloc0(sizeof(QEMUFileStdio));



    s->stdio_file = fopen(filename, mode);

    if (!s->stdio_file) {

        goto fail;

    }



    if (mode[0] == 'w') {

        s->file = qemu_fopen_ops(s, &stdio_file_write_ops);

    } else {

        s->file = qemu_fopen_ops(s, &stdio_file_read_ops);

    }

    return s->file;

fail:

    g_free(s);

    return NULL;

}
