#include "mi_kernel.h"

static int current_process;

int ppage_of_vaddr(int ctx, unsigned vaddr){
  int ppage;
  ppage = -1;
  vpage=(vaddr>>12)& 0xFFF;
  if(ctx==0){
    ppage=vpage +1;
  }
  if(ctx==1){
    ppage = vpage +1 + N/2 ;
  }
  return ppage;
}

void mmu_handler(){
  struct tlb_entry_s tlbe;
  int vpage,ppage;
  _in(MMU_FAULT_ADDR);
  vpage=(vaddr>>12) & 0xFFF;
  ppage=ppage_of_vaddr(current_process, vaddr);
  if(ppage == -1){
    /*HALT*/
    return;
  }
  tlbe.vpage = vpage;
  tlbe.ppage = ppage;
  tlbe.access = 0x7;
  tlbe.valid = 0x1;
  _out(TLB_ADD_ENTRY,tlbe);
}

void switch_to_process0(void){
	current_process = 0;
	_out(MMU_CMD, MMU_RESET);
}


void switch_to_process1(void){
	current_process = 1;
	_out(MMU_CMD, MMU_RESET);
}

void init(){
	IRQVECTOR[16] = switch_to_process0;
	IRQVECTOR[17] = switch_to_process1;
	_mask(0x1001);
}
