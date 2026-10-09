/* 
 * Benchmark Sample ID : devign_4386
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4524051c32190c1dc13ec2ccd122fd120dbed736
 */

char *qemu_find_file(int type, const char *name)

{

    int len;

    const char *subdir;

    char *buf;



    /* Try the name as a straight path first */

    if (access(name, R_OK) == 0) {

        return g_strdup(name);

    }

    switch (type) {

    case QEMU_FILE_TYPE_BIOS:

        subdir = "";

        break;

    case QEMU_FILE_TYPE_KEYMAP:

        subdir = "keymaps/";

        break;

    default:

        abort();

    }

    len = strlen(data_dir) + strlen(name) + strlen(subdir) + 2;

    buf = g_malloc0(len);

    snprintf(buf, len, "%s/%s%s", data_dir, subdir, name);

    if (access(buf, R_OK)) {

        g_free(buf);

        return NULL;

    }

    return buf;

}
