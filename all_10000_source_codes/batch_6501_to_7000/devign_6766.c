/* 
 * Benchmark Sample ID : devign_6766
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2917dce477f91e933052f5555b4c6be961ff624e
 */

int main (int argc, char *argv[])

{

  char *fnam = argv[0];

  FILE *f;

  if (argv[0][0] != '/')

    {

      fnam = malloc (strlen (argv[0]) + 2);

      if (fnam == NULL)

	abort ();

      strcpy (fnam, "/");

      strcat (fnam, argv[0]);

    }



  f = fopen (fnam, "rb");

  if (f == NULL)

    abort ();

  close (f);



  /* Cover another execution path.  */

  if (fopen ("/nonexistent", "rb") != NULL

      || errno != ENOENT)

    abort ();

  printf ("pass\n");

  return 0;

}
