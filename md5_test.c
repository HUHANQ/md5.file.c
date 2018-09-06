#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "md5.h"


int main(int argc, char** argv)
{
	FILE* fp = NULL;
	if(argc != 2)
	{
		fprintf(stderr,"Usage error!\n");//标准错误输出
		return 1;
	}	
	fp = fopen(argv[1], "rb");
	if(NULL == fp)
	{
		fprintf(stderr,"read %s fail :%s\n",argv[1],strerror(errno));
		return 1;
	}

	fseek(fp,0,SEEK_END);
	int filesize = ftell(fp);
	rewind(fp);
	unsigned char* a = NULL;
	a = malloc(filesize);
	if(fread(a,1,filesize,fp) != filesize )
	{
		fprintf(stderr,"read %s fail!\n",argv[1]);
		fclose(fp);
		return 1;
	}

	fclose(fp);
	printf("%s\n", md5_encrypt(a, filesize));
	free(a);

	return 0;
}
