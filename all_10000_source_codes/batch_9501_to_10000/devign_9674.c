/* 
 * Benchmark Sample ID : devign_9674
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=492c30af2567a59413c064f88eb81e1691865195
 */

void *etraxfs_dmac_init(CPUState *env, 

			target_phys_addr_t base, int nr_channels)

{

	struct fs_dma_ctrl *ctrl = NULL;

	int i;



	ctrl = qemu_mallocz(sizeof *ctrl);

	if (!ctrl)

		return NULL;



	ctrl->base = base;

	ctrl->env = env;

	ctrl->nr_channels = nr_channels;

	ctrl->channels = qemu_mallocz(sizeof ctrl->channels[0] * nr_channels);

	if (!ctrl->channels)

		goto err;



	for (i = 0; i < nr_channels; i++)

	{

		ctrl->channels[i].regmap = cpu_register_io_memory(0,

								  dma_read, 

								  dma_write, 

								  ctrl);

		cpu_register_physical_memory (base + i * 0x2000,

					      sizeof ctrl->channels[i].regs, 

					      ctrl->channels[i].regmap);

	}



	/* Hax, we only support one DMA controller at a time.  */

	etraxfs_dmac = ctrl;

	return ctrl;

  err:

	qemu_free(ctrl->channels);

	qemu_free(ctrl);

	return NULL;

}
