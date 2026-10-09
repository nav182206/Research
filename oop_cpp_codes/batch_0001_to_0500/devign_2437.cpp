/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2437
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e4f4fb1eca795e36f363b4647724221e774523c1
 */

static void spapr_phb_class_init(ObjectClass *klass, void *data)

{

    PCIHostBridgeClass *hc = PCI_HOST_BRIDGE_CLASS(klass);

    DeviceClass *dc = DEVICE_CLASS(klass);

    HotplugHandlerClass *hp = HOTPLUG_HANDLER_CLASS(klass);



    hc->root_bus_path = spapr_phb_root_bus_path;

    dc->realize = spapr_phb_realize;

    dc->props = spapr_phb_properties;

    dc->reset = spapr_phb_reset;

    dc->vmsd = &vmstate_spapr_pci;



    set_bit(DEVICE_CATEGORY_BRIDGE, dc->categories);

    hp->plug = spapr_phb_hot_plug_child;

    hp->unplug = spapr_phb_hot_unplug_child;

}
