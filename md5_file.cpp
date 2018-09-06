/*************************************************************************
    > File Name: 3.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 06 Sep 2018 05:14:52 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include <cstdlib>
#include "md5.h"

int main(int argc,const char** argv)
{
	if(argc != 2)
	{
		perror("参数错误！");	
		exit(1);
	}
	std::fstream f(argv[1],f.in);
	long filesize;
	f.seekg(0,f.end);
	filesize = f.tellg();
	f.seekg(0);
	char* a = new char[filesize];
	f.read(a,filesize);
	std::cout<<md5_encrypt(a,filesize)<<std::endl;
	delete []a;
	f.close();
return 0;
}
