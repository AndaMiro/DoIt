#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <conio.h>

#define MAX_NAME_LENGTH 20

typedef struct node{
  char name[MAX_NAME_LENGTH];
  int kor, eng, math, total, average;
  struct node *n_next;
} NODE;

void swapNode(NODE *n_1, NODE *n_2){
  int i_temp;
  char c_temp[MAX_NAME_LENGTH];
  for(int i = 0; i < MAX_NAME_LENGTH; i++){
    c_temp[i] = n_1->name[i];
    n_1->name[i] = n_2->name[i];
    n_2->name[i] = c_temp[i];
  }
  
  i_temp = n_1->kor;
  n_1->kor = n_2->kor;
  n_2->kor = i_temp;
  
  i_temp = n_1->eng;
  n_1->eng = n_2->eng;
  n_2->eng = i_temp;
  
  i_temp = n_1->math;
  n_1->math = n_2->math;
  n_2->math = i_temp;
  
  i_temp = n_1->total;
  n_1->total = n_2->total;
  n_2->total = i_temp;
  
  n_1->average = n_1->total / 3;
  n_2->average = n_2->total / 3;
}

void updateNode(NODE **n_head, NODE **n_new){
  NODE **n_temp;
  if(*n_head != NULL){
    n_temp = n_head;
    while(*n_temp != NULL){
      if((*n_temp)->total < (*n_new)->total){
        (*n_new)->n_next = (*n_temp)->n_next;
        (*n_temp)->n_next = *n_new;
        swapNode(*n_temp, *n_new);
        return;
      }
      n_temp = &(*n_temp)->n_next;
    }
    *n_temp = *n_new;
  }
  else{
    *n_head = *n_new;
  }
}

void addNode(NODE **n_head){
  NODE *n_new = (NODE *)malloc(sizeof(NODE));
  printf("이름 : ");
  scanf("%s", n_new->name);
  printf("국어 : ");
  scanf("%d", &n_new->kor);
  printf("영어 : ");
  scanf("%d", &n_new->eng);
  printf("수학 : ");
  scanf("%d", &n_new->math);
  
  n_new->total = n_new->kor + n_new->eng + n_new->math;
  n_new->average = n_new->total / 3;
  n_new->n_next = NULL;
  updateNode(n_head, &n_new);
}

void showList(NODE *n_head){
	if(n_head != NULL){
		int rank = 1;
		NODE *n_temp = n_head;
		printf("이름   국어   영어   수학   총점   평균   순위");
		while(n_temp != NULL){
			printf("\n%-4s   %3d점 %3d점  %3d점  %3d점  %3d점 %3d위", n_temp->name, n_temp->kor, n_temp->eng, n_temp->math, n_temp->total, n_temp->average, rank++);
			n_temp = n_temp->n_next;
		}
		Sleep(5000);
	}
	else{
		printf("정보가 존재하지 않습니다.");
		Sleep(5000);
	}
}

int getNodeCount(NODE *n_head){
	NODE *n_temp;
	int count = 0;
	n_temp = n_head;
	while(n_temp != NULL){
		count++;
		n_temp = n_temp->n_next;
	}
	
	return count;
}

void loadData(NODE **n_head){
	FILE *file = fopen("StudentData.txt", "rt");
	NODE **n_temp;
	n_temp = n_head;
	int count;
	fscanf(file, "%d", &count);
	printf("데이터 불러오는중...");
	Sleep(1000);
	printf("%d", count);
	if(file != NULL){
		for(int i = 0; i < count; i++){
			system("cls");
			printf("총 %d 개의 데이터중 %d 번째 데이터를 불러오는중...", count, i + 1);
			Sleep(500);
			NODE *n_new = (NODE *)malloc(sizeof(NODE));
			fscanf(file, "%s", n_new->name);
			fscanf(file, "%d", &n_new->kor);
			fscanf(file, "%d", &n_new->eng);
			fscanf(file, "%d", &n_new->math);
			fscanf(file, "%d", &n_new->total);
			fscanf(file, "%d", &n_new->average);
			n_new->n_next = NULL;
			
			*n_temp = n_new;
			n_temp = &(*n_temp)->n_next;
		}
	}
	system("cls");
	printf("완료!");
	Sleep(200); 
	fclose(file);
}

void saveData(NODE *n_head){
	FILE *file = fopen("StudentData.txt", "wt");
	NODE *n_temp, *n_free;
	n_temp = n_head;
	fprintf(file, "%d\n", getNodeCount(n_head));
	while(n_temp != NULL){
		fprintf(file, "%s\n", n_temp->name);
		fprintf(file, "%d\n", n_temp->kor);
		fprintf(file, "%d\n", n_temp->eng);
		fprintf(file, "%d\n", n_temp->math);
		fprintf(file, "%d\n", n_temp->total);
		fprintf(file, "%d\n", n_temp->average);
		n_free = n_temp;
		n_temp = n_temp->n_next;
		free(n_free);
	}
}

int main(void){
	int option;
	NODE *n_head = NULL;
	loadData(&n_head);
	while(1){
		system("cls");
		printf("[MENU]\n1. 성적 입력\n2. 성적 확인\n3. 종료\n------------\n선택(1 ~ 3) : ");
		option = getch();
		system("cls");
		switch(option){
			case 49 :
				addNode(&n_head);
				break;
			
			case 50 :
				showList(n_head);
				break;
				
			case 51 :
				saveData(n_head);
				return getNodeCount(n_head);
		}
	}
} 
