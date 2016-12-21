/*
 *Ejercicio-1.c repaso 
*/
#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void){
	printk(KERN_INFO "Hola mundo!\n");
	return 0;
}

void clean_module(void){
	printk(KERN_INFO "Adios mundo cruel\n");
}