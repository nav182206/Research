/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1406
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=91be2ad756d658acc24fec5bc46c1775158d28b0
 */

static void hdcd_reset(hdcd_state *state, unsigned rate, unsigned cdt_ms)

{

    int i;



    state->window = 0;

    state->readahead = 32;

    state->arg = 0;

    state->control = 0;



    state->running_gain = 0;



    state->sustain = 0;

    state->sustain_reset = cdt_ms*rate/1000;



    state->code_counterA = 0;

    state->code_counterA_almost = 0;

    state->code_counterB = 0;

    state->code_counterB_checkfails = 0;

    state->code_counterC = 0;

    state->code_counterC_unmatched = 0;

    state->count_peak_extend = 0;

    state->count_transient_filter = 0;

    for(i = 0; i < 16; i++) state->gain_counts[i] = 0;

    state->max_gain = 0;

    state->count_sustain_expired = -1;



    state->_ana_snb = 0;

}
