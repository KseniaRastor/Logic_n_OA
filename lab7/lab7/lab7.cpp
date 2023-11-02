#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int top;
	struct node* next, * next_list;
};
struct node* head = NULL, * head_top = NULL;			


void DFS(int v, int n, int** G, int* tops_visited) {
	tops_visited[v] = 1;
	printf(" %d", v);
	for (int i = 1; i <= n; i++) {
		if ((G[v][i] == 1) && (tops_visited[i] == 0)) {
			DFS(i, n, G, tops_visited);
		}
	}
	return;
}

void DFS_list(struct node* head_save, struct node* head_top, int* tops_visited_4_list) {
	struct node* tmp_head = NULL;
	struct node* tmp_top = NULL;
	tops_visited_4_list[head_top->top] = 1;
	printf(" %d", head_top->top);
	tmp_top = head_top->next_list;
	while (tmp_top != NULL) {
		if (tops_visited_4_list[tmp_top->top] == 0) {
			head_top = head_save;
			while (head_top != NULL) {
				if (head_top->top == tmp_top->top) break;
				else head_top = head_top->next;
			}

			tmp_head = head_top;
			DFS_list(head_save, tmp_head, tops_visited_4_list);

		}
		tmp_top = tmp_top -> next;
	}
	return;
}


struct node* get_struct(int** G, int n) {
	struct node* p = NULL;
	struct node* tmp_top = NULL;
	struct node* tmp = NULL;
	struct node* head_top_first = NULL;

	int flag_first = 0;
	for (int i = 1; i <= n; i++) {
		((p = (node*)malloc(sizeof(struct node))) == NULL);			// выделение памяти под новую вершину
		p->top = i;
		p->next = NULL;
		if (flag_first == 0) {
			head_top_first = p;
			head_top = p;
			flag_first++;
			tmp_top = head_top;
		}
		else {
			tmp_top->next = p;
			tmp_top = p;
		}
	}

	tmp_top->next = NULL;

	for (int i = 1; i <= n; i++) {
		flag_first = 0;
		for (int j = 1; j <= n; j++) {
			if (G[i][j] == 1) {
				((p = (node*)malloc(sizeof(struct node))) == NULL);		// выделение память под новый элемент вершины
				p->top = j;
				p->next = NULL;

				if (flag_first == 0) {
					head = p;
					flag_first++;
					tmp = head;
				}
				else {
					tmp->next = p;
					tmp = p;
				}
			}
		}
		head_top->next_list = head;
		head_top = head_top->next;
		head = NULL;
	}
	return head_top_first;													
}


/* Просмотр содержимого списка. */
void review(struct node* head_top) {
	struct node* tmp_top = NULL;

	if (head_top == NULL) {
		printf("Список пуст\n");
		return;
	}

	while (head_top != 0) {
		printf(" %d -> ", head_top->top);
		tmp_top = head_top->next_list;
		while (tmp_top != NULL) {
			printf("%d ", tmp_top->top);
			tmp_top = tmp_top->next;
		}
		head_top = head_top->next;
		printf("\n");
	}
	return;
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
			DFS(i, n, G, tops_visited);				
		}
	}

	if (comp_sv == 1) printf("\n\n Граф связный\n\n");
	else printf("\n\n Граф не связный. Количество компонент связности = %d", comp_sv);

	printf("\n\n__________________________________________________________________________________\n\n");

	printf(" Список смежности матрицы М:\n");
	head = get_struct(G, n);
	review(head);											//формирование списка смежности матрицы М
	
	comp_sv = 0;
	head_top = head;

	while (head_top != NULL) {								//вывод результата
		if (tops_visited_4_list[head_top->top] == 0) {
			comp_sv++;
			printf("\n");
			DFS_list(head, head_top, tops_visited_4_list);
		}
		head_top = head_top->next;
	}

	if (comp_sv == 1) printf("\n\n Граф связный\n\n");
	else printf("\n\n Граф не связный. Количество компонент связности = %d\n\n", comp_sv);

	return 0;
}
