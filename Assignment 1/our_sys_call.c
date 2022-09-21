// System call defination

#include <linux/kernel.h>
asmlinkage long sys_hello(void) //tells compiler to check for params in
//CPU stack rather than registers

{
printk("Hello world\n"); // prints to kernel’s log file
return 0;
}
