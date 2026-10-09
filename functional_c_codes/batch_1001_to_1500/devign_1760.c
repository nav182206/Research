/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1760
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dc5999787181f6d090217f45570067e55333835b
 */

monitor_qapi_event_queue(QAPIEvent event, QDict *qdict, Error **errp)

{

    MonitorQAPIEventConf *evconf;

    MonitorQAPIEventState *evstate;



    assert(event < QAPI_EVENT__MAX);

    evconf = &monitor_qapi_event_conf[event];

    trace_monitor_protocol_event_queue(event, qdict, evconf->rate);



    qemu_mutex_lock(&monitor_lock);



    if (!evconf->rate) {

        /* Unthrottled event */

        monitor_qapi_event_emit(event, qdict);

    } else {

        QDict *data = qobject_to_qdict(qdict_get(qdict, "data"));

        MonitorQAPIEventState key = { .event = event, .data = data };



        evstate = g_hash_table_lookup(monitor_qapi_event_state, &key);

        assert(!evstate || timer_pending(evstate->timer));



        if (evstate) {

            /*

             * Timer is pending for (at least) evconf->rate ns after

             * last send.  Store event for sending when timer fires,

             * replacing a prior stored event if any.

             */

            QDECREF(evstate->qdict);

            evstate->qdict = qdict;

            QINCREF(evstate->qdict);

        } else {

            /*

             * Last send was (at least) evconf->rate ns ago.

             * Send immediately, and arm the timer to call

             * monitor_qapi_event_handler() in evconf->rate ns.  Any

             * events arriving before then will be delayed until then.

             */

            int64_t now = qemu_clock_get_ns(QEMU_CLOCK_REALTIME);



            monitor_qapi_event_emit(event, qdict);



            evstate = g_new(MonitorQAPIEventState, 1);

            evstate->event = event;

            evstate->data = data;

            QINCREF(evstate->data);

            evstate->qdict = NULL;

            evstate->timer = timer_new_ns(QEMU_CLOCK_REALTIME,

                                          monitor_qapi_event_handler,

                                          evstate);

            g_hash_table_add(monitor_qapi_event_state, evstate);

            timer_mod_ns(evstate->timer, now + evconf->rate);

        }

    }



    qemu_mutex_unlock(&monitor_lock);

}
