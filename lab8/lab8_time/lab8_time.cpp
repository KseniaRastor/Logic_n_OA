#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <iostream>


void BFS(int i, int n, int** G, int* tops_visited) {
	int v;
	int v_start = i;
	printf(" ");

	using namespace std;
	queue <int> Q;

	Q.push(v_start);
	tops_visited[v_start] = 1;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		//printf("%d", v);

		for (int i = 1; i <= n; i++) {
			if ((G[v][i] == 1) && (tops_visited[i] == 0)) {
				Q.push(i);
				tops_visited[i] = 1;
			}
		}
	}
}



struct node {
	int inf;
	struct node* next, * prev;
};
typedef node* pnode;

struct my_queue {
	pnode head, tail;
};


/* Последовательное добавление в список элемента*/
my_queue* push(my_queue& S, int v) {
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
my_queue* pop(my_queue& S) {

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


void BFS_my_queue(int i, int n, int** G, int* tops_visited) {
	my_queue* Q = (my_queue*)malloc(sizeof(my_queue));
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
		//printf("%d", v);

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
	float Time_q, Time_my_q;

	setlocale(0, "rus");
	
	printf("  --------------------------------------------------------------------------------------------------\n");
	printf("  |  порядок графа     |        стандартный класс queue         |               my_queue           | \n");

	



	n = 100;

	while (n < 1000) {

		int** G = (int**)malloc(n * sizeof(int*));
		for (int i = 1; i <= n; i++) {
			G[i] = (int*)malloc(n * sizeof(int));
		}

		int* tops_visited = (int*)malloc(n * sizeof(int*));
		for (int i = 1; i <= n; i++) {
			tops_visited[i] = 0;
		}



		//printf(" Матрица М:\n");
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
				//printf(" %d", G[i][j]);
			}
			//printf("\n");
		}

		clock_t start1 = clock();
		for (int i = 1; i <= n; i++) {						//вывод результата
			if (tops_visited[i] == 0) {
				comp_sv++;
				//printf("\n");
				BFS(i, n, G, tops_visited);
			}
		}
		clock_t end1 = clock();

		Time_q = ((double)(end1 - start1) / CLOCKS_PER_SEC);
		//printf("%f\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

		//printf("__________________________________________________________________________________\n\n");

		for (int i = 1; i <= n; i++) {
			tops_visited[i] = 0;
		}

		comp_sv = 0;

		clock_t start2 = clock();
		for (int i = 1; i <= n; i++) {						//вывод результата
			if (tops_visited[i] == 0) {
				comp_sv++;
				//printf("\n");
				BFS_my_queue(i, n, G, tops_visited);
			}
		}
		clock_t end2 = clock();

		Time_my_q = ((double)(end2 - start2) / CLOCKS_PER_SEC);
		//printf("%f\n", (double)(end2 - start2) / CLOCKS_PER_SEC);


		printf("---------------------+----------------------------------------+----------------------------------|\n");
		printf("  |        %d         |                %f                |               %f           |\n", n, Time_q, Time_my_q);



		n = n + 100;
	}
	printf("  --------------------------------------------------------------------------------------------------\n");

return 0;
}

