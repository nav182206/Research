/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_969
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=18b101ff595c7f18e9571d26f8840f556b24ec03
 */

intptr_t (*checkasm_check_func(intptr_t (*func)(), const char *name, ...))()

{

    char name_buf[256];

    intptr_t (*ref)() = func;

    CheckasmFuncVersion *v;

    int name_length;

    va_list arg;



    va_start(arg, name);

    name_length = vsnprintf(name_buf, sizeof(name_buf), name, arg);

    va_end(arg);



    if (!func || name_length <= 0 || name_length >= sizeof(name_buf))

        return NULL;



    state.current_func = get_func(name_buf, name_length);

    v = &state.current_func->versions;



    if (v->func) {

        CheckasmFuncVersion *prev;

        do {

            /* Only test functions that haven't already been tested */

            if (v->func == func)

                return NULL;



            if (v->ok)

                ref = v->func;



            prev = v;

        } while ((v = v->next));



        v = prev->next = checkasm_malloc(sizeof(CheckasmFuncVersion));

    }



    v->func = func;

    v->ok = 1;

    v->cpu = state.cpu_flag;

    state.current_func_ver = v;



    if (state.cpu_flag)

        state.num_checked++;



    return ref;

}
