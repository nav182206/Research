/* 
 * Benchmark Sample ID : devign_9623
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=98caa5bc0083ed4fe4833addd3078b56ce2f6cfa
 */

kern_return_t GetBSDPath( io_iterator_t mediaIterator, char *bsdPath, CFIndex maxPathSize )

{

    io_object_t     nextMedia;

    kern_return_t   kernResult = KERN_FAILURE;

    *bsdPath = '\0';

    nextMedia = IOIteratorNext( mediaIterator );

    if ( nextMedia )

    {

        CFTypeRef   bsdPathAsCFString;

    bsdPathAsCFString = IORegistryEntryCreateCFProperty( nextMedia, CFSTR( kIOBSDNameKey ), kCFAllocatorDefault, 0 );

        if ( bsdPathAsCFString ) {

            size_t devPathLength;

            strcpy( bsdPath, _PATH_DEV );

            strcat( bsdPath, "r" );

            devPathLength = strlen( bsdPath );

            if ( CFStringGetCString( bsdPathAsCFString, bsdPath + devPathLength, maxPathSize - devPathLength, kCFStringEncodingASCII ) ) {

                kernResult = KERN_SUCCESS;

            }

            CFRelease( bsdPathAsCFString );

        }

        IOObjectRelease( nextMedia );

    }



    return kernResult;

}
