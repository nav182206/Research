/* 
 * Benchmark Sample ID : devign_8893
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2296f194dfde4c0a54f249d3fdb8c8ca21dc611b
 */

static struct pathelem *add_entry(struct pathelem *root, const char *name)

{

    root->num_entries++;



    root = realloc(root, sizeof(*root)

                   + sizeof(root->entries[0])*root->num_entries);



    root->entries[root->num_entries-1] = new_entry(root->pathname, root, name);

    root->entries[root->num_entries-1]

        = add_dir_maybe(root->entries[root->num_entries-1]);

    return root;

}
