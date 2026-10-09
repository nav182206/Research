/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_410
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42bb9c9178ae7ac4c439172b1ae99cc29188a5c6
 */

stream_push(StreamSlave *sink, uint8_t *buf, size_t len, uint32_t *app)

{

    StreamSlaveClass *k =  STREAM_SLAVE_GET_CLASS(sink);



    return k->push(sink, buf, len, app);

}
