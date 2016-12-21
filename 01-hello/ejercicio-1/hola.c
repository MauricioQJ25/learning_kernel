#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void){
	printk(KERN_INFO "Hola Mau!\n");
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "Adios mundo cruel!\n");
}
