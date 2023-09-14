
//Простые структуры данных

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int n, m;
int* pmas;
int i, j;
int sum_c[1][10];		//сумма столбцов
int sum_r[10][1];		//сумма строк
int max, min;
int k ;					//временная переменная

void main(){
	srand(time(NULL));

	setlocale(0, "rus");
	printf("Введите количество строк в массиве -> ");
	scanf("%d", &n);
	printf("Введите количество столбцов в массиве -> ");
	scanf("%d", &m);
	printf("\n");

	pmas = (int*)malloc(n*m * sizeof(int));

	for (i = 0; i < n; i++) {							//инициализацию массива произвольного размера случайными числами
		for (j = 0; j < m; j++) {
			pmas[i * m + j] = rand()%100-20;
			printf ("%5d ", pmas[i * m + j]);
		}
		printf("\n");	
	}
	printf("\n");


	min = pmas[m];										//вычисление разницы между максимальным и
	max = pmas[m];										//минимальным элементами массива

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (pmas[i * m + j] > max) {
				max = pmas[i * m + j];
			}

			if (pmas[i * m + j] < min) {
				min = pmas[i * m + j];
			}
		}
	}

	printf("Минимальный элемент массива = %d\n", min);
	printf("Максимальный элемент массива = %d\n", max);
	printf("max - min = %d\n\n", max - min);

																			
	for (i = 0; i < n; i++) {								//вычисление суммы значений в каждой строке
		for (j = 0; j < m; j++) {
			sum_r[k][0] += pmas[i * m + j];
		}
		k++;
	}

	printf("Сумма строк:\n");
	for (k = 0; k < n; k++) {
		printf("%5d\n", sum_r[k][0]);
	}
	printf("\n");


	k = 0;													//вычисление суммы значений в каждом столбце
	for (j = 0; j < m; j++) {
		for (i = 0; i < n; i++) {
			sum_c[0][k] += pmas[i * m + j];
		}
		k++;
	}

	printf("Сумма столбцов:\n");
	for (k = 0; k < m; k++) {
		printf("%5d ", sum_c[0][k]);
	}
	printf("\n");

	free(pmas);
}


