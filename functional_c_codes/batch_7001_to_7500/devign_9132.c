/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9132
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9561fda8d90e176bef598ba87c42a1bd6ad03ef7
 */

void object_property_add_link(Object *obj, const char *name,

                              const char *type, Object **child,

                              Error **errp)

{

    gchar *full_type;



    full_type = g_strdup_printf("link<%s>", type);



    object_property_add(obj, name, full_type,

                        object_get_link_property,

                        object_set_link_property,

                        NULL, child, errp);



    g_free(full_type);

}
