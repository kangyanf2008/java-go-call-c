#### test.h

#pragma once
#ifndef __test
#define __test
int CharJoin(char *result, char *va1, char *va2);
#endif

######## end test.h

#### test.c

#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int CharJoin(char *result, char *va1, char *va2) {
	//printf("strlen1 %d,%d,%d\n", strlen(result), strlen(va1), strlen(va2));
	/**
	方式1
	1亿 4秒
	strcat(result, va1);
	strcat(result, va2);
	go调用有问题，C调用无问题
	*/

	/**
	方式2
	1亿4秒多
	strcpy(result, va1);
	strcat(result, va2);
	*/
	strcpy(result, va1);
	strcat(result, va2);

	//printf("strlen2  %d,%d,%d\n", strlen(result), strlen(va1), strlen(va2));
	//拼接字符串
	//方式3
	/**
		C调用无问题，go调用无问题
		1亿26秒多
		sprintf(result, "%s%s", va1, va2);
	*/
	//printf("%s\n", result);
	return 0;
}

### end test.c

(1)编译c库
gcc -c -o test.o test.c
(2)创建.a静态库
ar rcs libtest.a test.o

把test.c test.o test.h放到程序src下。进行开发调试。假如线上，直接放在可执行文件同目录即可

1百万  65毫秒
1亿    8611 毫秒