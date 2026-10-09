/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2428
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dadc43eee4d9036aa532665a04720238cc15e922
 */

PCA *ff_pca_init(int n){
    PCA *pca;
    if(n<=0)
    pca= av_mallocz(sizeof(*pca));
    pca->n= n;
    pca->z = av_malloc_array(n, sizeof(*pca->z));
    pca->count=0;
    pca->covariance= av_calloc(n*n, sizeof(double));
    pca->mean= av_calloc(n, sizeof(double));
    return pca;
