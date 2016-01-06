#ifndef _SWAP_H_
#define _SWAP_H_

#include <stdio.h>
#include "hw_config.h"

struct vmapping_s{
    unsigned vm_ppage:8;
    unsigned vm_allocate:1;
};

struct pmapping_s{
    unsigned pm_vpage:12;
    unsigned pm_allocate:1;
};

static FILE *swap_file;
struct vmapping_s vmapping[VM_PAGES];
struct pmapping_s pmapping[PM_PAGES];
unsigned vm_page;

extern char init_swap(const char *path);
extern char store_to_swap(int vpage, int ppage);
extern char fetch_from_swap(int vpage, int ppage);

#endif
