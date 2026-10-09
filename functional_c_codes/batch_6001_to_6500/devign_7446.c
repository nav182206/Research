/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7446
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2c6942fa7b332a95286071b92d233853e1000948
 */

void bdrv_info(Monitor *mon, QObject **ret_data)

{

    QList *bs_list;

    BlockDriverState *bs;



    bs_list = qlist_new();



    QTAILQ_FOREACH(bs, &bdrv_states, list) {

        QObject *bs_obj;



        bs_obj = qobject_from_jsonf("{ 'device': %s, 'type': 'unknown', "

                                    "'removable': %i, 'locked': %i }",

                                    bs->device_name, bs->removable,

                                    bdrv_dev_is_medium_locked(bs));



        if (bs->drv) {

            QObject *obj;

            QDict *bs_dict = qobject_to_qdict(bs_obj);



            obj = qobject_from_jsonf("{ 'file': %s, 'ro': %i, 'drv': %s, "

                                     "'encrypted': %i }",

                                     bs->filename, bs->read_only,

                                     bs->drv->format_name,

                                     bdrv_is_encrypted(bs));

            if (bs->backing_file[0] != '\0') {

                QDict *qdict = qobject_to_qdict(obj);

                qdict_put(qdict, "backing_file",

                          qstring_from_str(bs->backing_file));

            }



            qdict_put_obj(bs_dict, "inserted", obj);

        }

        qlist_append_obj(bs_list, bs_obj);

    }



    *ret_data = QOBJECT(bs_list);

}
