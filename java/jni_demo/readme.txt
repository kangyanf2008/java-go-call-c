（1）在src目录下
javac Test_Jni.java

（2）生成.h jni头文件
javah -jni Test_Jni

可编译
 gcc -c test.c -fPIC -Wl,--add-stdcall-alias -shared -I. -L.  -o test.dll
 gcc -c Test_jni.c -fPIC -Wl,--add-stdcall-alias -shared -I. -L. -ID:\kyf\tool\jdk1.8.0\include -ID:\kyf\tool\jdk1.8.0\include\win32 -o Test_jni.dll


好使
 gcc -c test.c  -fPIC -Wl,--add-stdcall-alias -shared -I. -L.  -o test.dll
 gcc -Wl,--add-stdcall-alias -shared -I. -L. -ID:\kyf\tool\jdk1.8.0\include -ID:\kyf\tool\jdk1.8.0\include\win32 -o Test_jni.dll Test_jni.c


1亿 383861 毫秒
1百万 3164 毫秒