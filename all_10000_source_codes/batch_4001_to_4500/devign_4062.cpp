/* 
 * Benchmark Sample ID : devign_4062
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9d6a3d58e4d1431ab3809ff621cfd1f9ec75eef5
 */

ObjectClass *object_class_dynamic_cast_assert(ObjectClass *class,

                                              const char *typename,

                                              const char *file, int line,

                                              const char *func)

{

    ObjectClass *ret;



    trace_object_class_dynamic_cast_assert(class ? class->type->name : "(null)",

                                           typename, file, line, func);



#ifdef CONFIG_QOM_CAST_DEBUG

    int i;



    for (i = 0; i < OBJECT_CLASS_CAST_CACHE; i++) {

        if (class->cast_cache[i] == typename) {

            ret = class;

            goto out;

        }

    }

#else

    if (!class->interfaces) {

        return class;

    }

#endif



    ret = object_class_dynamic_cast(class, typename);

    if (!ret && class) {

        fprintf(stderr, "%s:%d:%s: Object %p is not an instance of type %s\n",

                file, line, func, class, typename);

        abort();

    }



#ifdef CONFIG_QOM_CAST_DEBUG

    if (ret == class) {

        for (i = 1; i < OBJECT_CLASS_CAST_CACHE; i++) {

            class->cast_cache[i - 1] = class->cast_cache[i];

        }

        class->cast_cache[i - 1] = typename;

    }

out:

#endif

    return ret;

}
