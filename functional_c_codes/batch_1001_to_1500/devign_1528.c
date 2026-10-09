/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1528
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=354711279fcc532cee310ed8098f51403dfef5d9
 */

static void qemu_add_data_dir(const char *path)

{

    int i;



    if (path == NULL) {

        return;

    }

    if (data_dir_idx == ARRAY_SIZE(data_dir)) {

        return;

    }

    for (i = 0; i < data_dir_idx; i++) {

        if (strcmp(data_dir[i], path) == 0) {

            return; /* duplicate */

        }

    }

    data_dir[data_dir_idx++] = path;

}
