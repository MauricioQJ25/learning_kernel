/*
 *	stop.c	-	Illustration of multi filed modules
 */

#include <linux/kernel.h>	/*	We're doing kernel work 	*/
#include <linux/module.h>	/*	Specifically, a modules 	*/

void cleanup_module(){
	printk(KERN_INFO "short is the life of a kernel module\n");
}