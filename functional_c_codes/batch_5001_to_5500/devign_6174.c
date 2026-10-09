/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6174
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c8057f951d64de93bfd01569c0a725baa9f94372
 */

void select_soundhw(const char *optarg)

{

    struct soundhw *c;



    if (*optarg == '?') {

    show_valid_cards:



        printf("Valid sound card names (comma separated):\n");

        for (c = soundhw; c->name; ++c) {

            printf ("%-11s %s\n", c->name, c->descr);

        }

        printf("\n-soundhw all will enable all of the above\n");

        exit(*optarg != '?');

    }

    else {

        size_t l;

        const char *p;

        char *e;

        int bad_card = 0;



        if (!strcmp(optarg, "all")) {

            for (c = soundhw; c->name; ++c) {

                c->enabled = 1;

            }

            return;

        }



        p = optarg;

        while (*p) {

            e = strchr(p, ',');

            l = !e ? strlen(p) : (size_t) (e - p);



            for (c = soundhw; c->name; ++c) {

                if (!strncmp(c->name, p, l) && !c->name[l]) {

                    c->enabled = 1;

                    break;

                }

            }



            if (!c->name) {

                if (l > 80) {

                    fprintf(stderr,

                            "Unknown sound card name (too big to show)\n");

                }

                else {

                    fprintf(stderr, "Unknown sound card name `%.*s'\n",

                            (int) l, p);

                }

                bad_card = 1;

            }

            p += l + (e != NULL);

        }



        if (bad_card) {

            goto show_valid_cards;

        }

    }

}
