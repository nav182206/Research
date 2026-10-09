/* 
 * Benchmark Sample ID : devign_6145
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=19f3322379c25a235eb1ec6335676549109fa625
 */

static int do_token_setup(USBDevice *s, USBPacket *p)

{

    int request, value, index;

    int ret = 0;



    if (p->len != 8)


 

    memcpy(s->setup_buf, p->data, 8);

    s->setup_len   = (s->setup_buf[7] << 8) | s->setup_buf[6];

    s->setup_index = 0;



    request = (s->setup_buf[0] << 8) | s->setup_buf[1];

    value   = (s->setup_buf[3] << 8) | s->setup_buf[2];

    index   = (s->setup_buf[5] << 8) | s->setup_buf[4];

 

    if (s->setup_buf[0] & USB_DIR_IN) {

        ret = s->info->handle_control(s, request, value, index, 

                                      s->setup_len, s->data_buf);

        if (ret < 0)

            return ret;



        if (ret < s->setup_len)

            s->setup_len = ret;

        s->setup_state = SETUP_STATE_DATA;

    } else {







        if (s->setup_len == 0)

            s->setup_state = SETUP_STATE_ACK;

        else

            s->setup_state = SETUP_STATE_DATA;




    return ret;
