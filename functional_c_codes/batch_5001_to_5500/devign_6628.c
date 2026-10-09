/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6628
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ddf21908961073199f3d186204da4810f2ea150b
 */

static UserDefTwo *nested_struct_create(void)

{

    UserDefTwo *udnp = g_malloc0(sizeof(*udnp));

    udnp->string0 = strdup("test_string0");

    udnp->dict1 = g_malloc0(sizeof(*udnp->dict1));

    udnp->dict1->string1 = strdup("test_string1");

    udnp->dict1->dict2 = g_malloc0(sizeof(*udnp->dict1->dict2));

    udnp->dict1->dict2->userdef = g_new0(UserDefOne, 1);

    udnp->dict1->dict2->userdef->base = g_new0(UserDefZero, 1);

    udnp->dict1->dict2->userdef->base->integer = 42;

    udnp->dict1->dict2->userdef->string = strdup("test_string");

    udnp->dict1->dict2->string = strdup("test_string2");

    udnp->dict1->dict3 = g_malloc0(sizeof(*udnp->dict1->dict3));

    udnp->dict1->has_dict3 = true;

    udnp->dict1->dict3->userdef = g_new0(UserDefOne, 1);

    udnp->dict1->dict3->userdef->base = g_new0(UserDefZero, 1);

    udnp->dict1->dict3->userdef->base->integer = 43;

    udnp->dict1->dict3->userdef->string = strdup("test_string");

    udnp->dict1->dict3->string = strdup("test_string3");

    return udnp;

}
