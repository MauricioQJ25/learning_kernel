/*
 * Este es el segundo ejemplo de modulos de kernel
*/

#include <linux/module.h>
#include <linux/kernel.h>

int __init hello_2_init(void){
	printk(KERN_INFO "Hola desde hello-2!\n");
	return 0;
}

void __exit hello_2_exit(void){
	printk(KERN_INFO "Adios desde hello-2!\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);