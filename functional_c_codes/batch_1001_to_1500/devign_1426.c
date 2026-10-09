/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1426
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ce137829e7e58fcdc5ba63b5e256f972e80be438
 */

static int remove_mapping(BDRVVVFATState* s, int mapping_index)

{

    mapping_t* mapping = array_get(&(s->mapping), mapping_index);

    mapping_t* first_mapping = array_get(&(s->mapping), 0);



    /* free mapping */

    if (mapping->first_mapping_index < 0)

	free(mapping->path);



    /* remove from s->mapping */

    array_remove(&(s->mapping), mapping_index);



    /* adjust all references to mappings */

    adjust_mapping_indices(s, mapping_index, -1);



    if (s->current_mapping && first_mapping != (mapping_t*)s->mapping.pointer)

	s->current_mapping = array_get(&(s->mapping),

		s->current_mapping - first_mapping);



    return 0;

}
