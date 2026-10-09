/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6873
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bb0300dc57c10b3721451b0ff566a03f9276cc77
 */

static void add_flagname_to_bitmaps(const char *flagname, uint32_t *features,

                                    uint32_t *ext_features,

                                    uint32_t *ext2_features,

                                    uint32_t *ext3_features)

{

    int i;

    int found = 0;



    for ( i = 0 ; i < 32 ; i++ )

        if (feature_name[i] && !strcmp (flagname, feature_name[i])) {

            *features |= 1 << i;

            found = 1;

        }

    for ( i = 0 ; i < 32 ; i++ )

        if (ext_feature_name[i] && !strcmp (flagname, ext_feature_name[i])) {

            *ext_features |= 1 << i;

            found = 1;

        }

    for ( i = 0 ; i < 32 ; i++ )

        if (ext2_feature_name[i] && !strcmp (flagname, ext2_feature_name[i])) {

            *ext2_features |= 1 << i;

            found = 1;

        }

    for ( i = 0 ; i < 32 ; i++ )

        if (ext3_feature_name[i] && !strcmp (flagname, ext3_feature_name[i])) {

            *ext3_features |= 1 << i;

            found = 1;

        }

    if (!found) {

        fprintf(stderr, "CPU feature %s not found\n", flagname);

    }

}
