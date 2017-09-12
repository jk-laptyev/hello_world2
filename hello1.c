#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
//#include <linux/printk.h>

#include "inc/hello1.h"

MODULE_LICENSE("GPL");

static int __init hello_init(void)
{
	pr_info("Hello world printer loaded.\n");
	return 0;
}

static void __exit hello_exit(void)
{
	pr_info("Hello world printer quit.\n");
}

int print_hello(void)
{
	pr_emerg("Hello world!\n");
	return 0;
}
EXPORT_SYMBOL(print_hello);

module_init(hello_init);
module_exit(hello_exit);
