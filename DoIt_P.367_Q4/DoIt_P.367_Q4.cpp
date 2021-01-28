#include <stdio.h>

int main(void){
	char name[3][32];
	int average[3], index[3], korean[3], english[3], math[3];
	
	for(int i = 0; i < 3; i++){
		printf("\n%d 번째 학생 이름: ", i + 1);
		scanf("%s", &name[i][0]);
		printf("\n국어 점수: ");
		scanf("%d", &korean[i]);
		printf("\n영어 점수: ");
		scanf("%d", &english[i]);
		printf("\n수학 점수: ");
		scanf("%d", &math[i]);
		index[i] = i;
		average[i] = (korean[i] + english[i] + math[i]) / 3;
	}
	
	int min = 0, change;
	for(int i = 0; i < 3; i++){
		for(int i2 = min; i2 < 3; i2++){
			if(average[min] < average[i2]){
				change = average[min];
				average[min] = average[i2];
				average[i2] = change;
				
				change = index[min];
				index[min] = index[i2];
				index[i2] = change;
			}
		}
		min++;
	}
	
	printf("\n------------------------------------------\n 이름   국어  영어  수학  총점  평균  등수\n\n");
	for(int i = 0; i < 3; i++){
		printf("%s  %3d   %3d   %3d   %3d   %3d  %3d등\n", name[index[i]], korean[index[i]], english[index[i]], math[index[i]], average[index[i]] * 3, average[index[i]], i + 1);
	}
	printf("\n------------------------------------------");
}
