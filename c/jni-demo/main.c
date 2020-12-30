#include <stdio.h>
#include <time.h>
#include "test.h"

int main() {
	char str1[6] = "12345";
	char str2[5] = "6789";
	time_t t;
	t = time(NULL);

	int ii = time(&t);
	printf("ii = %d\n", ii);
	int taltal = (strlen(str1) + strlen(str2)) * sizeof(char)+1;
	char *result = (char *)malloc(taltal);
	for (int i = 0; i < 100000000; i++) {
		memset(result, 0, taltal);
		CharJoin(result, str1, str2);
	}
	str2[0] = 'a';
	str2[1] = 'b';
	str2[2] = 'c';
	str2[3] = 'd';
	printf("%s\n", result);
	free(result);
	time_t t2;
	t2 = time(NULL);
	int i2 = time(&t2);
	printf("spend t = %d\n", i2-ii);

	return 0;
}