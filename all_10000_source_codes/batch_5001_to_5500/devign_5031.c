/* 
 * Benchmark Sample ID : devign_5031
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a9ceb76d55abfed9426a819024aa3a4b87266c9f
 */

dbdma_control_write(DBDMA_channel *ch)

{

    uint16_t mask, value;

    uint32_t status;



    mask = (ch->regs[DBDMA_CONTROL] >> 16) & 0xffff;

    value = ch->regs[DBDMA_CONTROL] & 0xffff;



    value &= (RUN | PAUSE | FLUSH | WAKE | DEVSTAT);



    status = ch->regs[DBDMA_STATUS];



    status = (value & mask) | (status & ~mask);



    if (status & WAKE)

        status |= ACTIVE;

    if (status & RUN) {

        status |= ACTIVE;

        status &= ~DEAD;

    }

    if (status & PAUSE)

        status &= ~ACTIVE;

    if ((ch->regs[DBDMA_STATUS] & RUN) && !(status & RUN)) {

        /* RUN is cleared */

        status &= ~(ACTIVE|DEAD);

    }



    DBDMA_DPRINTF("    status 0x%08x\n", status);



    ch->regs[DBDMA_STATUS] = status;



    if (status & ACTIVE)

        qemu_bh_schedule(dbdma_bh);

    if (status & FLUSH)

        ch->flush(&ch->io);

}
