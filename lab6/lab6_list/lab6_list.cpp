#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


int main() {
	int n1, n2;
	int v1_keyboard, v2_keyboard, v_tmp, v1, v2;
	int size_G = 0;
	//int col_one;

	setlocale(0, "rus");
	printf("Введите размер матрицы М1 -> ");
	scanf("%d", &n1);
	printf("Введите размер матрицы М2 -> ");
	scanf("%d", &n2);
	printf("\n");


	int** G1 = (int**)malloc(n1 * sizeof(int*));
	for (int i = 0; i < n1; i++) {
		G1[i] = (int*)malloc(n1 * sizeof(int));
	}

	int** G2 = (int**)malloc(n2 * sizeof(int*));
	for (int i = 0; i < n2; i++) {
		G2[i] = (int*)malloc(n2 * sizeof(int));
	}

	srand(time(0));
	for (int i = 0; i < n1; i++) {				//формирование матрицы смежности М1
		for (int j = 0; j < n1; j++) {
			if (i == j) G1[i][j] = 0;
			else  G1[i][j] = rand() % 2;
			printf(" %d", G1[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	for (int i = 0; i < n2; i++) {				//формирование матрицы смежности М2
		for (int j = 0; j < n2; j++) {
			if (i == j) G2[i][j] = 0;
			else  G2[i][j] = rand() % 2;
			printf(" %d", G2[i][j]);
		}
		printf("\n");
	}




	//отождествление вершин
	printf("\n\nОтождествление вершин матрицы М1\n");
	printf("Введите вершину 1 -> ");
	scanf("%d", &v1_keyboard);
	printf("Введите размер матрицы М2 -> ");
	scanf("%d", &v2_keyboard);
	printf("\n");

	int** G1_otogd = (int**)malloc((n1 - 1) * sizeof(int*));
	for (int i = 0; i < (n1 - 1); i++) {
		G1_otogd[i] = (int*)malloc((n1 - 1) * sizeof(int));
	}

	if (v1_keyboard > v2_keyboard) {
		v_tmp = v1_keyboard;
		v1_keyboard = v2_keyboard;
		v2_keyboard = v_tmp;
	}


	v1_keyboard--;
	v2_keyboard--;

	for (int i = 0; i < n1; i++) {				//"ИЛИ" для строки
		if (i == v1_keyboard) {
			for (int j = 0; j < n1; j++) {
				G1[v1_keyboard][j] = G1[v1_keyboard][j] || G1[v2_keyboard][j];
				G1[v2_keyboard][j] = 0;
			}
		}
	}

	for (int j = 0; j < n1; j++) {				//"ИЛИ" для столбеца
		if (j == v1_keyboard) {
			for (int i = 0; i < n1; i++) {
				G1[i][v1_keyboard] = G1[i][v1_keyboard] || G1[i][v2_keyboard];
				G1[i][v2_keyboard] = 0;
			}
		}
	}

	int i_otogd = 0;							//отождествление вершин + вывод результата
	int j_otogd = 0;

	for (int i = 0; i < n1; i++) {
		if (i != v2_keyboard) {
			for (int j = 0; j < n1; j++) {
				if (j != v2_keyboard) {
					G1_otogd[i_otogd][j_otogd] = G1[i][j];
					printf(" %d", G1_otogd[i_otogd][j_otogd]);
					j_otogd++;
				}
			}
			i_otogd++;
			printf("\n");
		}

	}






	//стягивание ребра
	printf("\n\nСтягивание ребра матрицы М1\n");
	printf("Введите вершину 1 -> ");
	scanf("%d", &v1_keyboard);
	printf("Введите вершину 2 -> ");
	scanf("%d", &v2_keyboard);
	printf("\n");

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			if (i == v1_keyboard - 1) v1 = i;
			if (j == v2_keyboard - 1) v2 = j;
		}
	}

	G1[v1][v2] = 0;
	G1[v2][v1] = 0;

	for (int i = 0; i < n1; i++) {				//печать матрицы
		for (int j = 0; j < n1; j++) {
			printf(" %d", G1[i][j]);
		}
		printf("\n");
	}



	//расщепления вершины 
	printf("\n\nРасщепление вершины матрицы М1\n");
	printf("Введите вершину -> ");
	scanf("%d", &v1_keyboard);




	//меню
	int menu_answer;
	printf("1 - Формирование матрицы\n");
	printf("2 - Отождествление вершины матрицы\n");
	printf("3 - Стягивание ребра матрицы\n");
	printf("4 - Расщепление вершины матрицы\n");
	printf("0 - Выход\n");


	while (1) {
		printf("Введите выбранный вариант -> ");
		scanf("%d", menu_answer);

		switch (menu_answer) {
		case(1): {

		}

		case(2): {

		}

		case(3): {

		}

		case(0): {
			break;
		}
		}
	}

	return 0;
}

