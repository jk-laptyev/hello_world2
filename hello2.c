#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/bug.h>

#include "inc/hello1.h"

MODULE_LICENSE("GPL");

static uint count = 1;
module_param(count, uint, S_IRUGO);

//extern int print_hello(void);
static int print_goodbye(void);

static int __init hello_init(void)
{
	int i;

	pr_info("Hello world caller loaded.\n");

	BUG_ON(count > 10);
	WARN_ON(count == 0);

	switch (count) {
	case 2:
		__module_get(THIS_MODULE);
		break;
	case 5:
		return -EINVAL;
	}

	for (i = 0; i < count; i++)
		print_hello();

	return 0;
}

static void __exit hello_exit(void)
{
	u8 *uPtr;

	print_goodbye();
	uPtr = (u8 *)__kmalloc(64, GFP_KERNEL);
	if (count == 3)
		*uPtr = 0x90;
	pr_info("Hello world caller quit.\n");
}

static int print_goodbye(void)
{
	pr_emerg("Good bye!\n");
	return 0;
}


module_init(hello_init);
module_exit(hello_exit);
