#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

struct node {
	int inf;												
	struct node* next, * prev;									 
};
typedef node* pnode;											

struct queue {
	pnode head, tail;
};


/* Последовательное добавление в список элемента*/
queue* push(queue& S, int v) {
	pnode newnode;
	newnode = new node;

	newnode->inf = v;

	if (S.head == NULL) {
		newnode->next = NULL;
		newnode->prev = NULL;
		S.tail = newnode;
		S.head = newnode;
	}
	else {
		S.tail->next = newnode;
		newnode->prev = S.tail;
		S.tail = newnode;
		S.tail->next = NULL;
	}

	return (&S);
}


/* Удаление элемента по содержимому. */
queue* pop(queue& S) {

	if (S.head == NULL) {
		printf("Список пуст\n");
	}

	pnode HeadNode = S.head;
	S.head = HeadNode->next;
	
	
	if (S.head) {
		S.head->prev = NULL;
	}
		
	else S.head = NULL;
	HeadNode->next = NULL;

	delete HeadNode;
	//printf("Операция выполнена успешно\n");
	return(&S);
}


void BFS(int i, int n, int** G, int* tops_visited) {
	queue* Q = (queue*)malloc(sizeof(queue));
	int v_start = i;
	Q->head = NULL;
	Q->tail = NULL;
	int v;
	
	printf(" ");

	Q = push(*Q, v_start);
	tops_visited[v_start] = 1;
	while (Q->head != NULL) {
		v = Q->head->inf;
		Q = pop(*Q);
		printf("%d", v);

		for (int i = 1; i <= n; i++) {
			if ((G[v][i] == 1) && (tops_visited[i] == 0)) {
				Q = push(*Q, i);
				tops_visited[i] = 1;
			}
		}
	}
}



int main() {
	int n;
	int comp_sv = 0;

	setlocale(0, "rus");
	printf(" Введите размер матрицы М -> ");
	scanf("%d", &n);
	printf("\n");

	int** G = (int**)malloc(n * sizeof(int*));
	for (int i = 1; i <= n; i++) {
		G[i] = (int*)malloc(n * sizeof(int));
	}

	int* tops_visited = (int*)malloc(n * sizeof(int*));
	for (int i = 1; i <= n; i++) {
		tops_visited[i] = 0;
	}

	int* tops_visited_4_list = (int*)malloc(n * sizeof(int*));
	for (int i = 1; i <= n; i++) {
		tops_visited_4_list[i] = 0;
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


	for (int i = 1; i <= n; i++) {						//вывод результата
		if (tops_visited[i] == 0) {
			comp_sv++;
			printf("\n");
			BFS(i, n, G, tops_visited);
		}
	}

	if (comp_sv == 1) printf("\n\n Граф связный\n\n");
	else printf("\n\n Граф не связный. Количество компонент связности = %d", comp_sv);

	return 0;
}