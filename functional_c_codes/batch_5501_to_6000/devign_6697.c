/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6697
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

QEMUFile *qemu_fopen_socket(int fd, const char *mode)

{

    QEMUFileSocket *s;



    if (qemu_file_mode_is_not_valid(mode)) {

        return NULL;

    }



    s = g_malloc0(sizeof(QEMUFileSocket));

    s->fd = fd;

    if (mode[0] == 'w') {

        qemu_set_block(s->fd);

        s->file = qemu_fopen_ops(s, &socket_write_ops);

    } else {

        s->file = qemu_fopen_ops(s, &socket_read_ops);

    }

    return s->file;

}
