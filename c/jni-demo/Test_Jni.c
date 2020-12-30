#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Test_Jni.h"
//#include "test.h"


/**

* 工具方法

* 作用: 把java中的string 转化成一个c语言中的char数组

* 接受的参数 envjni环境的指针

* jstr 代表的是要被转化的java的string 字符串

* 返回值 : 一个c语言中的char数组的首地址 (char 字符串)

*/
char * Jstring2CStr(JNIEnv *env, jstring jstr){
	char* rtn = NULL;
	jclass clsstring = (*env)->FindClass(env, "java/lang/String");

	jstring strencode = (*env)->NewStringUTF(env, "UTF-8");

	jmethodID mid =

		(*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");

	// String.getByte("GB2312");

	jbyteArray barr =

		(jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode);

	jsize alen = (*env)->GetArrayLength(env, barr);

	jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);

	if (alen > 0)

	{

		rtn = (char*)malloc(alen + 1); //"\0"

		memcpy(rtn, ba, alen);

		rtn[alen] = 0;

	}

	(*env)->ReleaseByteArrayElements(env, barr, ba, 0); //

	return rtn;

}

JNIEXPORT jstring JNICALL Java_Test_1Jni_CharJoin
(JNIEnv *en, jobject job, jstring va1, jstring va2){
	//printf("%s%s\n", va1,va2);

	int str1Len = (*en)->GetStringLength(en,va1);
	int str2Len = (*en)->GetStringLength(en, va2);
	int resultSize = (str1Len + str2Len) * sizeof(char)+1;
	char *result = (char *)malloc(resultSize);
	memset(result, 0, resultSize);

	char *str1 = Jstring2CStr(en, va1);
	char *str2 = Jstring2CStr(en, va2);
	//CharJoin(result, str1, str2);
	free(str1);
	free(str2);
	jstring re = (*en)->NewStringUTF(en, result);
	free(result);
	return re;
}

JNIEXPORT jstring JNICALL Java_Test_1Jni_CharJoin2
(JNIEnv *en, jobject job, jstring va1, jstring va2){
	const char *buf1;
	const char *buf2;
	int str1Len = (*en)->GetStringLength(en, va1);
	int str2Len = (*en)->GetStringLength(en, va2);
	int resultSize = (str1Len + str2Len) * sizeof(char)+1;
	char *result = (char *)malloc(resultSize);
	memset(result, 0, resultSize);
	char *str1 = Jstring2CStr(en, va1);
	char *str2 = Jstring2CStr(en, va2);
	sprintf(result, "%s%s", str1, str2);
	
	free(str1);
	free(str2);
	jstring re = (*en)->NewStringUTF(en, result);
	free(result);
	return re;
}

