#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int col_student = 3;
int i, user_answer, user_answer_find;
int number = 1;
char tmp_find[40];
char tmp_find_save[40];
char research_famil[20];
char tmp_name[20];
char research_name[20];
char file_famil[20];
char research_facult[20];
int nomzach_research;

struct student{
	char famil[20];
	char name[20];
	char facult[20];
	int Nomzach;
}stud[3];


int main() {
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


	printf("1) Поиск по имени и фамилии\n");
	printf("2) Поиск по факультету\n");
	printf("3) Поиск по номеру зачетной книжки\n");
	printf("0) Выход\n");

	

	do {
		printf("\nВведите выбранные вариант -> ");
		scanf("%d", &user_answer_find);


		switch (user_answer_find) {
		case 1:															//ввод данных с клавиатуры
		{
			printf("Введите фамилию и имя студента для поиска -> ");			//поиск заданного студента
			getchar();
			fgets(tmp_find, 20, stdin);


			if (strpbrk(tmp_find, " ") == NULL) {
				printf("Данные некорректны");
			}
			else {
				strcpy(tmp_find_save, tmp_find);
				strcpy(research_famil, strtok(tmp_find, " "));
				strcpy(tmp_name, strpbrk(tmp_find_save, " "));						//strbrk - поиск первого вхождения
				memmove(research_name, tmp_name + 1, (strlen(tmp_name) - 2));


				for (i = 0; i < col_student; i++) {
					if ((strcmp(stud[i].famil, research_famil) == 0) && (strcmp(stud[i].name, research_name) == 0)) {
						printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки % d \n",
							stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
					}
				}
			}
			break;
		}

		case 2:
		{
			printf("Введите факультет -> ");			//поиск заданного студента
			getchar();
			fgets(research_facult, 20, stdin);
			strtok(research_facult, "\n");
			for (i = 0; i < col_student; i++) {
				if (strcmp(stud[i].facult, research_facult) == 0) {
					printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки % d \n",
						stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
				}
			}
			break;
		}


		case 3:
		{
			printf("Введите номер зачетной книжки -> ");			//поиск заданного студента
			scanf("%d", &nomzach_research);

			for (i = 0; i < col_student; i++) {
				if (stud[i].Nomzach == nomzach_research) {
					printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки % d \n",
						stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
				}
			}
			break;
		}
		}
	} while (user_answer_find != 0);
	return 0;
}