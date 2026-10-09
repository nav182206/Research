/* 
 * Benchmark Sample ID : devign_3259
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=39ee3ddff87a12e108fc4e0d36f756d0ca080472
 */

static void mov_metadata_creation_time(AVDictionary **metadata, int64_t time)
{
    if (time) {
        if(time >= 2082844800)
            time -= 2082844800;  /* seconds between 1904-01-01 and Epoch */
        avpriv_dict_set_timestamp(metadata, "creation_time", time * 1000000);
