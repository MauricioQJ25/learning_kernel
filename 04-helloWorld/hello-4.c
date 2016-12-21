/*
 *	hello-4.c  - Demonsttrates module documentation.
 */

#include <linux/module.h>	/*	Needed by all modules	*/
#include <linux/kernel.h>	/*	Needed for KERN_INFO	*/
#include <linux/init.h>		/*	Needed for the macros	*/
#define DRIVER_AUTHOR	"Mauricio Quijada <Mau@mau.org>"
#define DRIVER_DESC		"A sample driver"

static int __init init_hello_4(void){
	printk(KERN_INFO "Hello, world 4\n");
	return 0;
}		

static void __exit cleanup_hello_4(void){
	printk(KERN_INFO "Good bye, world \n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);

/*
 *	Get rid of taint message by declaring code as GPL
 */

MODULE_LICENSE("GPL");

/*
 * Or with defines, like this:
 */

MODULE_AUTHOR(DRIVER_AUTHOR); 		/*	Who wrote this module    */
MODULE_DESCRIPTION(DRIVER_DESC);	/*	What does this module do */

/*	This module uses /dev/testdevice. The MODULE_SUPPORTED_DEVICE macro might
 *	be used in the future to help automatic configuration of modules, but is
 *	currently unused other than for documentation purposes.
 *
 */

MODULE_SUPPORTED_DEVICE("testdevice");