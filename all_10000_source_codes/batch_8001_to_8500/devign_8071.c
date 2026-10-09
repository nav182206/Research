/* 
 * Benchmark Sample ID : devign_8071
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bc0129d97804615fbcf3281fe30361ab8aa8f4ab
 */

void monitor_readline(const char *prompt, int is_password,

                      char *buf, int buf_size)

{

    int i;



    if (is_password) {

        for (i = 0; i < MAX_MON; i++)

            if (monitor_hd[i] && monitor_hd[i]->focus == 0)

                qemu_chr_send_event(monitor_hd[i], CHR_EVENT_FOCUS);

    }

    readline_start(prompt, is_password, monitor_readline_cb, NULL);

    monitor_readline_buf = buf;

    monitor_readline_buf_size = buf_size;

    monitor_readline_started = 1;

    while (monitor_readline_started) {

        main_loop_wait(10);

    }

}
