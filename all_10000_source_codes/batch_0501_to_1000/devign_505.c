/* 
 * Benchmark Sample ID : devign_505
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b5ab677189b93efa4eaa921f42b21dc008247184
 */

tcp_sockclosed(struct tcpcb *tp)

{



	DEBUG_CALL("tcp_sockclosed");

	DEBUG_ARG("tp = %p", tp);



	switch (tp->t_state) {



	case TCPS_CLOSED:

	case TCPS_LISTEN:

	case TCPS_SYN_SENT:

		tp->t_state = TCPS_CLOSED;

		tp = tcp_close(tp);

		break;



	case TCPS_SYN_RECEIVED:

	case TCPS_ESTABLISHED:

		tp->t_state = TCPS_FIN_WAIT_1;

		break;



	case TCPS_CLOSE_WAIT:

		tp->t_state = TCPS_LAST_ACK;

		break;

	}

	if (tp)

		tcp_output(tp);

}
