
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct node{
	int priority;
	char inf[256];												// полезная информация
	struct node* next;											// ссылка на следующий элемент 
};
struct node* head = NULL, * last = NULL, * f = NULL;			// указатели на первый и последний элементы списка
int dlinna = 0;


// Функции добавления элемента, просмотра списка
void spstore(void), review(void), del(char* name);

char find_el[256];
struct node* find(char* name);									// функция нахождения элемента
struct node* get_struct(void);									// функция создания элемента

void crop(char* str) {
	int str_num = 0;
	while (str[str_num] != '\0')
	{
		if (str[str_num] == char(10))
		{
			str[str_num] = char(0);
		};
		str_num++;
	};
}

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)		// выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");						// вводим данные
	getchar();
	fgets(s, 50, stdin);
	crop(s);
	
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);
	printf("Введите приоритет объекта: \n");						// вводим данные
	scanf("%d", &(p->priority));
	

	p->next = NULL;

	return p;													// возвращаем указатель на созданный элемент
}

/* Добавление в список элемента*/
void spstore(void){
	struct node* p = NULL;
	struct node* struc = head;
	struct node* prev = NULL;

	p = get_struct();
	if (head == NULL && p != NULL) {							// если списка нет, то устанавливаем голову списка
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) {						// список уже есть
		do {
			if (struc->priority > p->priority) {				//приоритет выше существующего
				if (prev==NULL) {								//приоритет добавляется на первое место
					p->next = head;
					head = p;
				}
				else {											//приоритет добавляется после головы
					prev->next = p;
					p->next = struc;
				}
				return;
			}
			
			prev = struc;										
			struc = struc->next;
			
		} while (struc != NULL);

		last = prev;											//приоритет добавляется в конец списка
		last->next = p;
		last = p;
	}
	return;
}


/* Просмотр содержимого списка. */
void review(void){
	struct node* struc = head;
	if (head == NULL){
		printf("Список пуст\n");
	}
	while (struc){
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}


/* Поиск элемента по содержимому. */
struct node* find(char* name){
	int i = 1;
	struct node* struc = head;
	if (head == NULL){
		printf("Список пуст\n");
	}
	while (struc){
		if (strcmp(name, struc->inf) == 0){
			printf("Элемент с приоритетом №%d \n", struc->priority);
			return struc;
		}
		i++;
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}


/* Удаление элемента по содержимому. */
void del(char* name){
	struct node* struc = head;								// указатель, проходящий по списку установлен на начало списка
	struct node* prev = struc;								// указатель на предшествующий удаляемому элемент
	int flag = 0;											// индикатор отсутствия удаляемого элемента в списке

	if (head == NULL) {										// если голова списка равна NULL, то список пуст		
		printf("Список пуст\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) {					// если удаляемый элемент - первый
		flag = 1;
		head = struc->next;									// установливаем голову на следующий элемент
		free(struc);										// удаляем первый элемент
		struc = head;										// устанавливаем указатель для продолжения поиска
		printf("Удаление выполнено успешно\n");
	}
	else
	{
		struc = struc->next;
	}

	while (struc)												// проход по списку и поиск удаляемого элемента
	{
		if (strcmp(name, struc->inf) == 0)						// если нашли, то
		{
			flag = 1;											// выставляем индикатор
			if (struc->next)									// если найденный элемент не последний в списке
			{
				prev->next = struc->next;						// меняем указатели
				free(struc);									// удаляем  элемент
				struc = prev->next;								// устанавливаем указатель для продолжения поиска
				printf("Удаление выполнено успешно\n");
			}
			else												// если найденный элемент последний в списке
			{
				prev->next = NULL;								// обнуляем указатель предшествующего элемента
				free(struc);									// удаляем  элемент
				printf("Удаление выполнено успешно\n");
				return;
			}
			
		}
		else													// если не нашли, то
		{
			prev = struc;										// устанавливаем указатели для продолжения поиска
			struc = struc->next;
		}
	}

	if (flag == 0)												// если флаг = 0, значит нужный элемент не найден
	{
		printf("Элемент не найден\n");
		return;
	}
}


void swap() {
	int i = 1;
	int element_1, element_2;
	printf("Введите 1-ый элемент -> ");
	scanf("%d", &element_1);
	printf("Введите 2-ой элемент -> ");
	scanf("%d", &element_2);

	struct node* struc = head;
	struct node* struc_save = head;
	struct node* node_1 = NULL;
	struct node* node_2 = NULL;
	char char_swap[50];
	//char* node_swap;

		//,* node_2, *node_swap;

	if (head == NULL) {
		printf("Список пуст\n");
	}
	while (struc) {
		if (i == element_1) {
			node_1 = struc;
		}
		if (i == element_2) {
			node_2 = struc;
		}
		i++;
		struc = struc->next;
	}
	
	strcpy(char_swap, node_1->inf);
	strcpy(node_1->inf, node_2->inf);
	strcpy(node_2->inf, char_swap);

	while (struc_save) {
		printf("Имя - %s, \n", struc_save->inf);
		struc_save = struc_save->next;
	}

	return;
}


int answer; 
char name[50];	


int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("1) Добавление элемента\n");
	printf("2) Просмотр всех элементов\n");
	printf("3) Поиск элемента\n");
	printf("4) Удаление элемента\n");
	printf("0) Выход\n\n");

	do {
		printf("\nВведите номер выбранного варианта -> ");
		scanf("%d", &answer);
		switch (answer) {
		case (1):{
			spstore();
			break;
			}

		case (2): {
			review();
			break;
		}

		case (3): {
			printf("Введите искомый элемент -> ");
			getchar();
			fgets(name, 50, stdin);
			crop(name);
			if (*name == 0) {
				printf("Запись не была произведена\n");
				break;
			}

			find(name);
			break;
		}
		case (4): {
			printf("Введите удаляемый элемент -> ");
			getchar();
			fgets(name, 50, stdin);
			crop(name);
			if (*name == 0) {
				printf("Запись не была произведена\n");
				break;
			}

			del(name);
			break;
		}

		case (5): {
			swap();
			break;
		}
		}
	} while (answer != 0);

	return 0;
}