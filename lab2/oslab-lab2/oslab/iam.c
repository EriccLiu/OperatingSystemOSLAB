#define __LIBRARY__

#include <errno.h>
#include <unistd.h>
#include <stdio.h>

#define __NR_iam	72
#define __NR_whoami	73

_syscall1(int, iam, const char*, name);

int main(int argc,char ** argv)
{
	iam(argv[1]);
	return 0;
}
