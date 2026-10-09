/* 
 * Benchmark Sample ID : devign_6245
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0abfc4b885566eb41c3a4e1de5e2e105bdc062d9
 */

static void simple_number(void)

{

    int i;

    struct {

        const char *encoded;

        int64_t decoded;

        int skip;

    } test_cases[] = {

        { "0", 0 },

        { "1234", 1234 },

        { "1", 1 },

        { "-32", -32 },

        { "-0", 0, .skip = 1 },

        { },

    };



    for (i = 0; test_cases[i].encoded; i++) {

        QObject *obj;

        QInt *qint;



        obj = qobject_from_json(test_cases[i].encoded);

        g_assert(obj != NULL);

        g_assert(qobject_type(obj) == QTYPE_QINT);



        qint = qobject_to_qint(obj);

        g_assert(qint_get_int(qint) == test_cases[i].decoded);

        if (test_cases[i].skip == 0) {

            QString *str;



            str = qobject_to_json(obj);

            g_assert(strcmp(qstring_get_str(str), test_cases[i].encoded) == 0);

            QDECREF(str);

        }



        QDECREF(qint);

    }

}
