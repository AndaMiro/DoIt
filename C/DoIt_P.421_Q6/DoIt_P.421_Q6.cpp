#include <stdio.h>
#include <malloc.h>

int main(void){
	char ***p;
	int i, n, m;
	p = (char ***)malloc(sizeof(char **) * 2);
	
	for(i = 0; i < 2; i++){
		*(p + i) = (char **)malloc(sizeof(char *) * 3);
		for(int n = 0; n < 3; n++){
			*(*(p + i) + n) = (char *)malloc(sizeof(char) * 4);
		}
	}
	
	
	for(i = 0; i < 2; i++){
		for(n = 0; n < 3; n++){
			for(m = 0; m < 4; m++){
				*(*(*(p + i) + n) + m) = i * 3 * 4 + n * 4 + m;
			}
		}
	}
	
	
	for(i = 0; i < 2; i++){
		printf("*(p + %d)에 해당하는 메모리 주소 = %p\n", i, p + i);
		printf("========================================\n\n");
		for(n = 0; n < 3; n++){
			printf("*(*(p + %d) + %d)에 해당하는 메모리 주소 = %p\n", i, n, *(p + i) + n);
			printf("----------------------------------------\n\n");
			for(m = 0; m < 4; m++){
				printf("*(*(*(p + %d) + %d) + %d)의 주소(%p)와 저장된 값(%d)\n", i, n, m, *(*(p + i) + n) + m, *(*(*(p + i) + n) + m));
			}
			printf("\n\n");
		}
		printf("\n\n");
	}
	
	
	for(i = 0; i < 2; i++){
		for(n = 0; n < 3; n++){
		free(*(*(p + i) + n));
		}
		free(*(p + i));
	}
	free(p);
	
	return 0;
}
