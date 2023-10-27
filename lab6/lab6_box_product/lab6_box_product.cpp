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

	printf("Матрица М1:\n");
	srand(time(0));
	for (int i = 0; i < n1; i++) {				//формирование матрицы смежности G1
		for (int j = 0; j < n1; j++) {
			if (j >= i) {							//неориентированный граф
				if (i == j) G1[i][j] = 0;
				else {
					G1[i][j] = rand() % 2;
					G1[j][i] = G1[i][j];
				}
			}
			/*if (i == j) G1[i][j] = 0;				//ориентированный граф
			else  G1[i][j] = rand() % 2;*/
			printf(" %d", G1[i][j]);
		}
		printf("\n");
	}

	printf("\nМатрица М2:\n");
	for (int i = 0; i < n2; i++) {				//формирование матрицы смежности G2
		for (int j = 0; j < n2; j++) {
			if (j >= i) {							//неориентированный граф
				if (i == j) G2[i][j] = 0;
				else {
					G2[i][j] = rand() % 2;
					G2[j][i] = G2[i][j];
				}
			}
			/*if (i == j) G1[i][j] = 0;				//ориентированный граф
			else  G1[i][j] = rand() % 2;*/
			printf(" %d", G2[i][j]);
		}
		printf("\n");
	}


	int** E1 = (int**)malloc(n1 * sizeof(int*));
	for (int i = 0; i < n1; i++) {
		E1[i] = (int*)malloc(n1 * sizeof(int));
	}

	int** E2 = (int**)malloc(n2 * sizeof(int*));
	for (int i = 0; i < n2; i++) {
		E2[i] = (int*)malloc(n2 * sizeof(int));
	}

	for (int i = 0; i < n1; i++) {				//формирование единичной матрицы E1 для G1
		for (int j = 0; j < n1; j++) {
			if (i == j) E1[i][j] = 1;
			else  E1[i][j] = 0;
			//printf(" %d", E1[i][j]);
		}
	}


	for (int i = 0; i < n2; i++) {				//формирование единичной матрицы E2 для G2
		for (int j = 0; j < n2; j++) {
			if (i == j) E2[i][j] = 1;
			else  E2[i][j] = 0;
			//printf(" %d", E2[i][j]);
		}
	}



	int** Rez1 = (int**)malloc((n1*n2) * sizeof(int*));
	for (int i = 0; i < (n1 * n2); i++) {
		Rez1[i] = (int*)malloc((n1 * n2) * sizeof(int));
	}

	int** Rez2 = (int**)malloc((n1 * n2) * sizeof(int*));
	for (int i = 0; i < (n1 * n2); i++) {
		Rez2[i] = (int*)malloc((n1 * n2) * sizeof(int));
	}

	int j_r = 0;
	int i_r = 0;

	int tab = 0;
	int flag_first = 1;
	
	for (int j_G1 = 0; j_G1 < n1; j_G1++) {											//транзисторное произведение А1 и Е2
		i_r = 0;
		for (int i_G1 = 0; i_G1 < n1; i_G1++) {
			for (int i_E = 0; i_E < n2; i_E++) {
				for (int j_E = 0; j_E < n2; j_E++) {
					j_r = j_E + tab;		
					Rez1[i_r][j_r] = G1[i_G1][j_G1] * E2[i_E][j_E];
					//printf("[%d][%d] = %d\n", i_r, j_r, Rez[i_r][j_r]);
					j_r++;
				}

				j_r = 0;
				i_r++;
			}
		}
		flag_first = 0;
		tab = tab + n2;
	}
	

	j_r = 0;
	i_r = 0;
	tab = 0;
	flag_first = 1;
	for (int j_E = 0; j_E < n1; j_E++) {											//транзисторное произведение Е1 и А2 
		i_r = 0;
		for (int i_E = 0; i_E < n1; i_E++) {
			for (int i_G2 = 0; i_G2 < n2; i_G2++) {
				for (int j_G2 = 0; j_G2 < n2; j_G2++) {
					j_r = j_G2 + tab;
					Rez2[i_r][j_r] = G2[i_G2][j_G2] * E1[i_E][j_E];
					//printf("[%d][%d] = %d\n", i_r, j_r, Rez2[i_r][j_r]);
					j_r++;
				}

				j_r = 0;
				i_r++;
			}
		}
		flag_first = 0;
		tab = tab + n2;
	}

	
	int** Box_product = (int**)malloc((n1 * n2) * sizeof(int*));					//А1*E2 + E1*A2
	for (int i = 0; i < (n1 * n2); i++) {
		Box_product[i] = (int*)malloc((n1 * n2) * sizeof(int));
	}


	printf("\nДекартово произведение М1 на М2:\n");
	for (int i = 0; i < (n1 * n2); i++) {
		for (int j = 0; j < (n1 * n2); j++) {
			Box_product[i][j] = Rez1[i][j] + Rez2[i][j];
			printf(" %d", Box_product[i][j]);
		}
		printf("\n");
	}

	return 0;
}
