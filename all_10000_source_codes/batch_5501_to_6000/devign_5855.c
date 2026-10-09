/* 
 * Benchmark Sample ID : devign_5855
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabbae730cf732afeb7c2a085e0e5c1e7b1b8614
 */

offset_t url_filesize(URLContext *h)

{

    offset_t pos, size;



    size= url_seek(h, 0, AVSEEK_SIZE);

    if(size<0){

        pos = url_seek(h, 0, SEEK_CUR);

        size = url_seek(h, -1, SEEK_END)+1;

        url_seek(h, pos, SEEK_SET);

    }

    return size;

}
