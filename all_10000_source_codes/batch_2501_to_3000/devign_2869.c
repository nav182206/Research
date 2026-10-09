/* 
 * Benchmark Sample ID : devign_2869
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5fb6c7a8b26eab1a22207d24b4784bd2b39ab54b
 */

static int vnc_set_x509_credential(VncDisplay *vs,

				   const char *certdir,

				   const char *filename,

				   char **cred,

				   int ignoreMissing)

{

    struct stat sb;



    if (*cred) {

	qemu_free(*cred);

	*cred = NULL;

    }



    *cred = qemu_malloc(strlen(certdir) + strlen(filename) + 2);



    strcpy(*cred, certdir);

    strcat(*cred, "/");

    strcat(*cred, filename);



    VNC_DEBUG("Check %s\n", *cred);

    if (stat(*cred, &sb) < 0) {

	qemu_free(*cred);

	*cred = NULL;

	if (ignoreMissing && errno == ENOENT)

	    return 0;

	return -1;

    }



    return 0;

}
