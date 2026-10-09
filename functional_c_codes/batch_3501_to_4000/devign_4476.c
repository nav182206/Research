/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4476
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a4435f9235eefac8a25f1cda471486e2c37b21b5
 */

static void print_track_chunks(FILE *out, struct Tracks *tracks, int main,

                               const char *type)

{

    int i, j;

    struct Track *track = tracks->tracks[main];

    for (i = 0; i < track->chunks; i++) {

        for (j = main + 1; j < tracks->nb_tracks; j++) {

            if (tracks->tracks[j]->is_audio == track->is_audio &&

                track->offsets[i].duration != tracks->tracks[j]->offsets[i].duration)

                fprintf(stderr, "Mismatched duration of %s chunk %d in %s and %s\n",

                        type, i, track->name, tracks->tracks[j]->name);

        }

        fprintf(out, "\t\t<c n=\"%d\" d=\"%d\" />\n",

                i, track->offsets[i].duration);

    }

}
