/* 
 * Benchmark Sample ID : devign_768
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f25391c2a6ef1674384204265429520ea50e82bc
 */

static void dump_qobject(fprintf_function func_fprintf, void *f,

                         int comp_indent, QObject *obj)

{

    switch (qobject_type(obj)) {

        case QTYPE_QINT: {

            QInt *value = qobject_to_qint(obj);

            func_fprintf(f, "%" PRId64, qint_get_int(value));

            break;

        }

        case QTYPE_QSTRING: {

            QString *value = qobject_to_qstring(obj);

            func_fprintf(f, "%s", qstring_get_str(value));

            break;

        }

        case QTYPE_QDICT: {

            QDict *value = qobject_to_qdict(obj);

            dump_qdict(func_fprintf, f, comp_indent, value);

            break;

        }

        case QTYPE_QLIST: {

            QList *value = qobject_to_qlist(obj);

            dump_qlist(func_fprintf, f, comp_indent, value);

            break;

        }

        case QTYPE_QFLOAT: {

            QFloat *value = qobject_to_qfloat(obj);

            func_fprintf(f, "%g", qfloat_get_double(value));

            break;

        }

        case QTYPE_QBOOL: {

            QBool *value = qobject_to_qbool(obj);

            func_fprintf(f, "%s", qbool_get_int(value) ? "true" : "false");

            break;

        }

        case QTYPE_QERROR: {

            QString *value = qerror_human((QError *)obj);

            func_fprintf(f, "%s", qstring_get_str(value));


            break;

        }

        case QTYPE_NONE:

            break;

        case QTYPE_MAX:

        default:

            abort();

    }

}
