#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int CharJoin(char *result, char *va1, char *va2) {
	//printf("strlen1 %d,%d,%d\n", strlen(result), strlen(va1), strlen(va2));
	/**
	��ʽ1
	1�� 4��
	strcat(result, va1);
	strcat(result, va2);
	go���������⣬C����������
	*/

	/**
	��ʽ2
	1��4���
	strcpy(result, va1);
	strcat(result, va2);
	*/
	strcpy(result, va1);
	strcat(result, va2);
	
	//printf("strlen2  %d,%d,%d\n", strlen(result), strlen(va1), strlen(va2));
	//ƴ���ַ���
	//��ʽ3
	/**
		C���������⣬go����������
		1��26���
		sprintf(result, "%s%s", va1, va2);
	*/
	//printf("%s\n", result);
	return 0;
}