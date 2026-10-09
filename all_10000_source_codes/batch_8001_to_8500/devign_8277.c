/* 
 * Benchmark Sample ID : devign_8277
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bf937a7965c1d1a6dce4f615d0ead2e2ab505004
 */

static void bt_hid_interrupt_sdu(void *opaque, const uint8_t *data, int len)

{

    struct bt_hid_device_s *hid = opaque;



    if (len > BT_HID_MTU || len < 1)

        goto bad;

    if ((data[0] & 3) != BT_DATA_OUTPUT)

        goto bad;

    if ((data[0] >> 4) == BT_DATA) {

        if (hid->intr_state)

            goto bad;



        hid->data_type = BT_DATA_OUTPUT;

        hid->intrdataout.len = 0;

    } else if ((data[0] >> 4) == BT_DATC) {

        if (!hid->intr_state)

            goto bad;

    } else

        goto bad;



    memcpy(hid->intrdataout.buffer + hid->intrdataout.len, data + 1, len - 1);

    hid->intrdataout.len += len - 1;

    hid->intr_state = (len == BT_HID_MTU);

    if (!hid->intr_state) {

        memcpy(hid->dataout.buffer, hid->intrdataout.buffer,

                        hid->dataout.len = hid->intrdataout.len);

        bt_hid_out(hid);

    }



    return;

bad:

    fprintf(stderr, "%s: bad transaction on Interrupt channel.\n",

                    __func__);

}
