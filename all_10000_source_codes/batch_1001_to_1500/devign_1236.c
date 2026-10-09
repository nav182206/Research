/* 
 * Benchmark Sample ID : devign_1236
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e16e49ac90f6da9e019fdf23084cbb256d14bd9c
 */

static void term_init(void)

{

#ifndef __MINGW32__

    struct termios tty;



    tcgetattr (0, &tty);

    oldtty = tty;



    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP

                          |INLCR|IGNCR|ICRNL|IXON);

    tty.c_oflag |= OPOST;

    tty.c_lflag &= ~(ECHO|ECHONL|ICANON|IEXTEN);

    tty.c_cflag &= ~(CSIZE|PARENB);

    tty.c_cflag |= CS8;

    tty.c_cc[VMIN] = 1;

    tty.c_cc[VTIME] = 0;



    tcsetattr (0, TCSANOW, &tty);

    signal(SIGQUIT, sigterm_handler); /* Quit (POSIX).  */

#endif



    signal(SIGINT , sigterm_handler); /* Interrupt (ANSI).  */

    signal(SIGTERM, sigterm_handler); /* Termination (ANSI).  */

    /*

    register a function to be called at normal program termination

    */

    atexit(term_exit);

#ifdef CONFIG_BEOS_NETSERVER

    fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);

#endif

}
