/* filename: yee.c */
#include <sys/syscall.h>
#include <linux/unistd.h>
#define __NR_yee (__NR_SYSCALL_BASE+397)
#define yee(a,b) syscall(__NR_yee,(a),(b))
int main(){
yee(1,"system_yee_lab");
 return 0;
}
