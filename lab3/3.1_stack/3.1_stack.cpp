
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct node {
	char inf[256];												// полезная информация
	struct node* next, *prev;									// ссылка на соседние элементы 
};
typedef node* pnode;											// тип "указатели на узел"

struct stack {
	pnode head, tail;
};



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


/* Последовательное добавление в список элемента*/
stack* push(stack &S, char &name) {
		pnode newnode;
		newnode = new node;

		strcpy(newnode->inf, &name);

		if (S.head == NULL) {
			newnode->next = NULL;
			newnode->prev = NULL;
			S.tail = newnode;
		}
		else {
			newnode->next = S.head;
			newnode->prev = NULL;
		}
		

		if (S.head) S.head->prev = newnode;
		S.head = newnode;

	return (&S);
}


/* Просмотр содержимого списка. */
void review(stack &S) {
	struct stack S_tmp = S;

	if (S.tail == NULL) {
		printf("Список пуст\n");
		return;
	}
	while(1){
		printf("Имя - %s, \n", S_tmp.head->inf);
		if (S_tmp.head->next == NULL) {
			return;
		}
		else {
			S_tmp.head = S_tmp.head->next;
		}
	}
}


/* Поиск элемента по содержимому. */
void find(stack &S, char &name) {
	int i = 1;
	struct stack S_tmp = S;

	if (S.tail == NULL) {
		printf("Список пуст\n");
	}
	do {
		if (strcmp(&name, S_tmp.head->inf) == 0) {
			printf("Элемент №%d в списке\n", i);
			return;
		}
		i++;
		S_tmp.head = S_tmp.head->next;
	} while (S_tmp.head != NULL);
	printf("Элемент не найден\n");
	return;
}


/* Удаление элемента по содержимому. */
stack* pop(stack &S) {

	if (S.tail == NULL) {
		printf("Список пуст\n");
	}

	pnode TopNode = S.head;
	S.head = TopNode->next;
	if (S.head) S.head->prev = NULL;
	else S.tail = NULL;

	delete TopNode;
	printf("Операция выполнена успешно\n");
	return(&S);
}


int answer;
char name[50];
int flag_first = 1;

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("1) Добавление элемента\n");
	printf("2) Просмотр всех элементов\n");
	printf("3) Поиск элемента\n");
	printf("4) Удаление элемента\n");
	printf("0) Выход\n");
stack* S = (stack*)malloc(sizeof(stack));
	do {
		
		if (flag_first == 1){
			S->head = NULL;
			S->tail = NULL;
			flag_first = 0;
		}
		


		printf("\nВведите номер выбранного варианта -> ");
		scanf("%d", &answer);

		switch (answer) {
		case (1): {
			printf("Введите название объекта: \n");						// вводим данные
			getchar();
			fgets(name, 50, stdin);
			crop(name);
			if (*name == 0) {
				printf("Запись не была произведена\n");
				break;
			}
					
			S = push(*S, *name);				
			break;
		}

		case (2): {
			review(*S);
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

			find(*S, *name);
			break;
		}
				
		case (4): {
			S = pop(*S);
			break;
		}
		}
	} while (answer != 0);

	return 0;
}