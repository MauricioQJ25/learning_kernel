/*
 * hola-2.c Un ejemplo de lo que pueden 
 * hacer las funciones init y exit
*/

#include <linux/module.h>
#include <linux/kernel.h>

int __init hola_2_init(void){
	printk(KERN_INFO "Hola Mau desde hola-2.ko\n");
	return 0;
}

void __exit hola_2_exit(void){
	printk(KERN_INFO "Adios mundo cruel!!\n");
}

module_init(hola_2_init);
module_exit(hola_2_exit);




