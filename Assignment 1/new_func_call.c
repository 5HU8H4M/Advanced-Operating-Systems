#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
long int temp = syscall(548); // number of system call that we wrote
in syscalls_64.tbl
printf("Mayuresh & Shubham: System call sys_hello returned 0 %ld\n", temp);
return 0;
}
