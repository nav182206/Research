/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8199
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=30901475b91ef1f46304404ab4bfe89097f61b96
 */

static void gen_load_exclusive(DisasContext *s, int rt, int rt2,

                               TCGv_i32 addr, int size)

{

    TCGv_i32 tmp = tcg_temp_new_i32();



    s->is_ldex = true;



    switch (size) {

    case 0:

        gen_aa32_ld8u(tmp, addr, get_mem_index(s));

        break;

    case 1:

        gen_aa32_ld16u(tmp, addr, get_mem_index(s));

        break;

    case 2:

    case 3:

        gen_aa32_ld32u(tmp, addr, get_mem_index(s));

        break;

    default:

        abort();

    }



    if (size == 3) {

        TCGv_i32 tmp2 = tcg_temp_new_i32();

        TCGv_i32 tmp3 = tcg_temp_new_i32();



        tcg_gen_addi_i32(tmp2, addr, 4);

        gen_aa32_ld32u(tmp3, tmp2, get_mem_index(s));

        tcg_temp_free_i32(tmp2);

        tcg_gen_concat_i32_i64(cpu_exclusive_val, tmp, tmp3);

        store_reg(s, rt2, tmp3);

    } else {

        tcg_gen_extu_i32_i64(cpu_exclusive_val, tmp);

    }



    store_reg(s, rt, tmp);

    tcg_gen_extu_i32_i64(cpu_exclusive_addr, addr);

}
