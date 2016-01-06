#ifndef _KERNEL_
#define _KERNEL_


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "swap.h"

#define SYSCALL_SWTCH_0 16
#define SYSCALL_SWTCH_1 17
#define N 42
#define PAGE_SIZE 42

struct tlb_entry_s {
  unsigned rfu :8;
  unsigned vpage :12;
  unsigned ppage :8;
  unsigned access :3;
  unsigned valid :1;
};


extern void mmu_handler();
extern void mmu_handler2();
extern int ppage_of_vaddr(int ctx, unsigned vaddr);
extern void switch_to_process0(void);
extern void switch_to_process1(void);
extern void init();

extern int sum (void *ptr);

#endif
