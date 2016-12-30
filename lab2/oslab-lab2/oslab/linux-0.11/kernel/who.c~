/*
 *  linux/kernel/who.c
 *
 *  (C) 2016 Eric Liu
 */

#include <linux/kernel.h>
#include <unistd.h>
#include <asm/segment.h>
#include <errno.h>

char msg[24];

int sys_iam(const char* name)
{
	int size,i;
	char temp[30];
	for( size = 0 ; size < 30 ; size++ ){
		temp[size] = get_fs_byte(name+size);
		if(temp[size]=='\0'){
			break;	
		}
	}

	if(size==30){
		return -(EINVAL);
	}
	else{
		for(i = 0 ; i < size ; i++){
			msg[i] = temp[i];
		}
		size--;
		return (size);
	}
}

int sys_whoami(char* name,int size)
{
	int len = 0;
	while(msg[len]!='\0'){
		len++;
	}
	if(size<len){
		return -(EINVAL);
	}
	
	for(len = 0 ; len < size ; len++){
		put_fs_byte(msg[len],name+len);
		if(msg[len]=='\0'){
			break;
		}	
	}
	return (len);
}
