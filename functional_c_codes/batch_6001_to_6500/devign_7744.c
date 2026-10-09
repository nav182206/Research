/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7744
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bdb5ee3064d5ae786b0bcb6cf6ff4e3554a72990
 */

void do_info_roms(Monitor *mon)

{

    Rom *rom;



    QTAILQ_FOREACH(rom, &roms, next) {

        if (!rom->fw_file) {

            monitor_printf(mon, "addr=" TARGET_FMT_plx

                           " size=0x%06zx mem=%s name=\"%s\" \n",

                           rom->addr, rom->romsize,

                           rom->isrom ? "rom" : "ram",

                           rom->name);

        } else {

            monitor_printf(mon, "fw=%s%s%s"

                           " size=0x%06zx name=\"%s\" \n",

                           rom->fw_dir ? rom->fw_dir : "",

                           rom->fw_dir ? "/" : "",

                           rom->fw_file,

                           rom->romsize,

                           rom->name);

        }

    }

}
