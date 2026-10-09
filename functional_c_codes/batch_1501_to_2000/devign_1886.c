/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1886
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static int microblaze_load_dtb(target_phys_addr_t addr,

                                      uint32_t ramsize,

                                      const char *kernel_cmdline,

                                      const char *dtb_filename)

{

    int fdt_size;

#ifdef CONFIG_FDT

    void *fdt = NULL;

    int r;



    if (dtb_filename) {

        fdt = load_device_tree(dtb_filename, &fdt_size);

    }

    if (!fdt) {

        return 0;

    }



    if (kernel_cmdline) {

        r = qemu_devtree_setprop_string(fdt, "/chosen", "bootargs",

                                                        kernel_cmdline);

        if (r < 0) {

            fprintf(stderr, "couldn't set /chosen/bootargs\n");

        }

    }



    cpu_physical_memory_write(addr, (void *)fdt, fdt_size);

#else

    /* We lack libfdt so we cannot manipulate the fdt. Just pass on the blob

       to the kernel.  */

    if (dtb_filename) {

        fdt_size = load_image_targphys(dtb_filename, addr, 0x10000);

    }

    if (kernel_cmdline) {

        fprintf(stderr,

                "Warning: missing libfdt, cannot pass cmdline to kernel!\n");

    }

#endif

    return fdt_size;

}
