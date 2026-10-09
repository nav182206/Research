/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1839
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b027a538c6790bcfc93ef7f4819fe3e581445959
 */

static int oss_ctl_in (HWVoiceIn *hw, int cmd, ...)

{

    OSSVoiceIn *oss = (OSSVoiceIn *) hw;



    switch (cmd) {

    case VOICE_ENABLE:

        {

            va_list ap;

            int poll_mode;



            va_start (ap, cmd);

            poll_mode = va_arg (ap, int);

            va_end (ap);



            if (poll_mode && oss_poll_in (hw)) {

                poll_mode = 0;

            }

            hw->poll_mode = poll_mode;

        }

        break;



    case VOICE_DISABLE:

        if (hw->poll_mode) {

            hw->poll_mode = 0;

            qemu_set_fd_handler (oss->fd, NULL, NULL, NULL);

        }

        break;

    }

    return 0;

}
