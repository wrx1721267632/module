/*************************************************************************
	> File Name: hello.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月20日 星期五 14时45分28秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int __init lkp_init( void )
{
    printk("<1> hello,world! from the kernel space..\n");
    return 0;
}

static void __exit lkp_cleanup( void )
{
    printk("<1> goodbye, world! leaving kernel space...\n");
}

module_init(lkp_init);
module_exit(lkp_cleanup);
MODULE_LICENSE("GPL");
