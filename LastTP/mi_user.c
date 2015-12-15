#include "mi_syscall.h"

static int current_process;

int sum (void *ptr){
	int i;
	int sum = 0;
	for(i = 0; i<PAGE_SIZE * N/2;i++){
		sum +=((char*)ptr)[i];
	}
}

int main(int arc, char **argv){
	void *ptr;
	int res;

	init();

	ptr = virtual_memory;
    _init(16);
	 memset(ptr,1,PAGE_SIZE * N/2);
	 _int(17);
	 memset(ptr, 3, PAGE_SIZE * N/2);

	 _int(16);
	 res = sum(ptr);
	 printf("Resultat du processus 0 : d\n",res);
	 _int(17);
	 res = sum(ptr);
	 printf("Resultat du processus 0 : d\n",res);
}
