#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int col_student = 3;
int i, user_answer;
int number = 1;
char tmp_find[40];
char tmp_find_save[40];
char research_famil[20];
char tmp_name[20];
char research_name[20];
char file_famil[20];

struct student{
	char famil[20];
	char name[20];
	char facult[20];
	int Nomzach;
}stud[3];


void main() {
	SetConsoleCP(1251);
	setlocale(0, "rus");

	printf("1) Ввести данные с клавиатуры\n");
	printf("2) Загрузить данные из файла\n");

	scanf("%d", &user_answer);
	switch (user_answer) {
		case 1:															//ввод данных с клавиатуры
		{
			for (i = 0; i < col_student; i++) {
				printf("Введите фамилию %d-го студента -> ", number);
				scanf("%20s", stud[i].famil);
				number++;
			}

			number = 1;
			for (i = 0; i < col_student; i++) {
				printf("Введите имя %d-го студента -> ", number);
				scanf("%20s", stud[i].name);
				number++;
			}

			number = 1;
			for (i = 0; i < col_student; i++) {
				printf("Введите название факультета  %d-го студента -> ", number);
				scanf("%20s", stud[i].facult);
				number++;
			}

			number = 1;
			for (i = 0; i < col_student; i++) {
				printf("Введите номер зачётной книжки %d-го студента -> ", number);
				scanf("%d", &stud[i].Nomzach);
				number++;
			}
			printf("\n");
			break;
		}

		case 2:															//ввод данных из файла
		{
			FILE* file;
			file = fopen("bd.txt", "r");
			for (i = 0; i < col_student; i++) {
				fgets(stud[i].famil, 20, file);
				strtok(stud[i].famil, "\n");
				fgets(stud[i].name, 20, file);
				strtok(stud[i].name, "\n");
				fgets(stud[i].facult, 20, file);
				strtok(stud[i].facult, "\n");
				fscanf_s(file, "%d", &stud[i].Nomzach);
				fscanf_s(file, "\n");
			}
			printf("\n");
		}
	}
	
	for (i = 0; i < col_student; i++) {									//вывод всего списка студентов
		printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки % d \n",
			stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
	}
	printf("\n");

	printf("Введите фамилию и имя студента для поиска -> ");			//поиск заданного студента
	getchar();
	fgets(tmp_find, 20, stdin);
	strcpy(tmp_find_save, tmp_find);
	strcpy(research_famil, strtok(tmp_find, " "));
	strcpy(tmp_name, strpbrk(tmp_find_save, " "));						//strbrk - поиск первого вхождения
	memmove(research_name, tmp_name + 1, (strlen(tmp_name) - 2));

	for (i = 0; i < col_student; i++) {
		if ((strcmp(stud[i].famil, research_famil)==0) && (strcmp(stud[i].name, research_name)==0)){
			printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки % d \n",
					stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
		}
	}
}