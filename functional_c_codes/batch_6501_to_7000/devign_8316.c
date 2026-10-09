/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8316
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=90901860c21468d6e9ae437c2bacb099c7bd3acf
 */

long check_dcbzl_effect(void)

{

  register char *fakedata = (char*)av_malloc(1024);

  register char *fakedata_middle;

  register long zero = 0;

  register long i = 0;

  long count = 0;



  if (!fakedata)

  {

    return 0L;

  }



  fakedata_middle = (fakedata + 512);



  memset(fakedata, 0xFF, 1024);



  /* below the constraint "b" seems to mean "Address base register"

     in gcc-3.3 / RS/6000 speaks. seems to avoid using r0, so.... */

  asm volatile("dcbzl %0, %1" : : "b" (fakedata_middle), "r" (zero));



  for (i = 0; i < 1024 ; i ++)

  {

    if (fakedata[i] == (char)0)

      count++;

  }



  av_free(fakedata);



  return count;

}
