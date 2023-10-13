#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


int main(void){
	int n;
	int size_G = 0;
	int col_one;

	setlocale(0, "rus");
	printf("Введите размер матрицы -> ");
	scanf("%d", &n);
	printf("\n");


/*Матрица смежности*/
	int** G = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++){
		G[i] = (int*)malloc(n * sizeof(int));
	}

	srand(time(0));
	for (int i = 0; i < n; i++) {						//формирование матирицы смежности
		for (int j = 0; j < n; j++) {
			if (j >= i) {								//половина матрицы G
				if (i == j) G[i][j] = 0;
				else {
					G[i][j] = rand() % 2;
					G[j][i] = G[i][j];
				}
			}
		}
	}
		
	
	for (int i = 0; i < n; i++) {						//вывод матрицы и её размера
		for (int j = 0; j < n; j++) {
			printf(" %d", G[i][j]);
			if (G[i][j] == 1) size_G++;
		}
		printf("\n");
	}
	size_G = size_G / 2;
	printf("\nРазмер графа = %d\n", size_G);


	for (int i = 0; i < n; i++) {						//поиск изолированных, концевых и доминирующих вершин
		col_one = 0;
		for (int j = 0; j < n; j++) {
			if (G[i][j] == 1) col_one++;	
		}

		if (col_one == 0) printf("Вершина %d изолировнная\n", i+1);
		if (col_one == 1) printf("Вершина %d концевая\n", i+1);
		if (col_one == n-1) printf("Вершина %d доминирующая\n", i+1);
	}
	printf("\n\n");



/*Матрица инцидентности*/
	int j_int = 0;
	int** Gi = (int**)malloc(size_G * sizeof(int*));

	for (int i = 0; i < n; i++) {
		Gi[i] = (int*)malloc(n * sizeof(int));
	}

	
	for (int i = 0; i < n; i++) {				//формирование матрицы инцидентности
		for (int j = 0; j < n; j++) {
			if (j > i) {						//половина матрицы G
				if (G[i][j] == 1) {
					Gi[i][j_int] = 1;
					Gi[j][j_int] = 1;
					j_int++;
				}
			}	
		}	
	}
	
	for (int i = 0; i < n; i++) {				//вывод матрицы инцидентности и её размера
		for (int j = 0; j < size_G; j++) {
			if (Gi[i][j] != 1) Gi[i][j] = 0;
			printf(" %d", Gi[i][j]);
		}
		printf("\n");
	}
	printf("\nРазмер графа = %d\n", j_int);

	for (int i = 0; i < n; i++) {				//поиск изолированных, концевых и доминирующих вершин
		col_one = 0;
		for (int j = 0; j < size_G; j++) {
			if (Gi[i][j] == 1) col_one++;
		}

		if (col_one == 0) printf("Вершина %d изолировнная\n", i + 1);
		if (col_one == 1) printf("Вершина %d концевая\n", i + 1);
		if (col_one == n - 1) printf("Вершина %d доминирующая\n", i + 1);
	}

	
	return(0);
}
