#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <iostream>

struct node {
	int inf;												// полезная информация
	struct node* next, * prev;									// ссылка на соседние элементы 
};
typedef node* pnode;											// тип "указатели на узел"

struct stack {
	pnode head, tail;
};

/* Последовательное добавление в список элемента*/
stack* push(stack& S, int v) {
	pnode newnode;
	newnode = new node;

	newnode->inf = v;

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


/* Удаление элемента по содержимому. */
stack* pop(stack& S) {

	if (S.tail == NULL) {
		printf("Список пуст\n");
	}

	pnode TopNode = S.head;
	S.head = TopNode->next;
	if (S.head) S.head->prev = NULL;
	else S.tail = NULL;

	delete TopNode;
	//printf("Операция выполнена успешно\n");
	return(&S);
}



int main() {
	int n, v1, v;
	int comp_sv = 0;
	stack* S = (stack*)malloc(sizeof(stack));

	setlocale(0, "rus");
	printf(" Введите размер матрицы М -> ");
	scanf("%d", &n);
	printf("\n");

	int** G = (int**)malloc(n * sizeof(int*));
	for (int i = 1; i <= n; i++) {
		G[i] = (int*)malloc(n * sizeof(int));
	}

	printf(" Матрица М:\n");
	srand(time(0));
	for (int i = 1; i <= n; i++) {					//формирование матрицы смежности М
		for (int j = 1; j <= n; j++) {
			if (j >= i) {
				if (i == j) G[i][j] = 0;
				else {
					G[i][j] = rand() % 2;
					G[j][i] = G[i][j];
				}
			}
			printf(" %d", G[i][j]);
		}
		printf("\n");
	}

	int* tops_visited = (int*)malloc(n * sizeof(int*));
	for (int i = 1; i <= n; i++) {
		tops_visited[i] = 0;
	}

	//using namespace std;
	//stack <int> s;

	S->head = NULL;
	S->tail = NULL;

	for (int v1 = 1; v1 <= n; v1++) {						//цикл для подсчета количества компонент связности
		if (tops_visited[v1] == 0) {
			comp_sv++;
			printf("\n ");

///
			S->head = NULL;
			S->tail = NULL;
			

			printf("%d ", v1);
			tops_visited[v1] = 1;
			//s.push(v);
			S = push(*S, v1);
			//while (!s.empty()) {
			while (S->head != NULL){
				v = S->head->inf;
				//s.pop();
				S = pop(*S);
				for (int i = n; i > 0; i--) {
					if ((G[v][i] == 1) && (tops_visited[i] == 0)) {
						printf("%d ", i);
						//s.push(i);
						S = push(*S, i);
						tops_visited[i] = 1;
					}
				}

			}
///


		}
	}


	if (comp_sv == 1) printf("\n\n Граф связный\n\n");
	else printf("\n\n Граф не связный. Количество компонент связности = %d\n\n", comp_sv);


	return 0;
}
