#define __LIBRARY__

#include <errno.h>
#include <unistd.h>
#include <stdio.h>

#define __NR_iam	72
#define __NR_whoami	73

_syscall2(int, whoami,char*, name, int, size);

int main()
{
	char temp[30];
	whoami(temp,30);
	printf("%s\n",temp);
	return 0;
}
