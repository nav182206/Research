/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_419
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

QEMUFile *qemu_bufopen(const char *mode, QEMUSizedBuffer *input)

{

    QEMUBuffer *s;



    if (mode == NULL || (mode[0] != 'r' && mode[0] != 'w') ||

        mode[1] != '\0') {

        error_report("qemu_bufopen: Argument validity check failed");

        return NULL;

    }



    s = g_malloc0(sizeof(QEMUBuffer));

    if (mode[0] == 'r') {

        s->qsb = input;

    }



    if (s->qsb == NULL) {

        s->qsb = qsb_create(NULL, 0);

    }

    if (!s->qsb) {

        g_free(s);

        error_report("qemu_bufopen: qsb_create failed");

        return NULL;

    }





    if (mode[0] == 'r') {

        s->file = qemu_fopen_ops(s, &buf_read_ops);

    } else {

        s->file = qemu_fopen_ops(s, &buf_write_ops);

    }

    return s->file;

}
