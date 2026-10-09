/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1376
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bec1631100323fac0900aea71043d5c4e22fc2fa
 */

static void tcg_out_jxx(TCGContext *s, int opc, int label_index, int small)

{

    int32_t val, val1;

    TCGLabel *l = &s->labels[label_index];



    if (l->has_value) {

        val = tcg_pcrel_diff(s, l->u.value_ptr);

        val1 = val - 2;

        if ((int8_t)val1 == val1) {

            if (opc == -1) {

                tcg_out8(s, OPC_JMP_short);

            } else {

                tcg_out8(s, OPC_JCC_short + opc);

            }

            tcg_out8(s, val1);

        } else {

            if (small) {

                tcg_abort();

            }

            if (opc == -1) {

                tcg_out8(s, OPC_JMP_long);

                tcg_out32(s, val - 5);

            } else {

                tcg_out_opc(s, OPC_JCC_long + opc, 0, 0, 0);

                tcg_out32(s, val - 6);

            }

        }

    } else if (small) {

        if (opc == -1) {

            tcg_out8(s, OPC_JMP_short);

        } else {

            tcg_out8(s, OPC_JCC_short + opc);

        }

        tcg_out_reloc(s, s->code_ptr, R_386_PC8, label_index, -1);

        s->code_ptr += 1;

    } else {

        if (opc == -1) {

            tcg_out8(s, OPC_JMP_long);

        } else {

            tcg_out_opc(s, OPC_JCC_long + opc, 0, 0, 0);

        }

        tcg_out_reloc(s, s->code_ptr, R_386_PC32, label_index, -4);

        s->code_ptr += 4;

    }

}
