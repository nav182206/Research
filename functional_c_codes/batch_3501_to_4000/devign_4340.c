/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4340
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0219d73283b6399a737ef5a098f849b956618eaa
 */

static ssize_t flush_buf(VirtIOSerialPort *port, const uint8_t *buf, size_t len)

{

    VirtConsole *vcon = DO_UPCAST(VirtConsole, port, port);

    ssize_t ret;



    ret = qemu_chr_write(vcon->chr, buf, len);



    trace_virtio_console_flush_buf(port->id, len, ret);

    return ret;

}
