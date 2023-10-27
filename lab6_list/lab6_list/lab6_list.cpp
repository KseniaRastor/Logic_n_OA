
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

struct node {
	int top;
	struct node* next, *next_list;
};
struct node* head = NULL, * last = NULL, * f = NULL, * head_top = NULL;			// указатели на первый и последний элементы списка


struct node* get_struct(int** G, int n) {
	struct node* p = NULL;
	struct node* tmp_top = NULL;
	struct node* tmp = NULL;
	struct node* head_top_first = NULL;

	int flag_first = 0;
	for (int i = 0; i < n; i++) {
		((p = (node*)malloc(sizeof(struct node))) == NULL);		// выделяем память под новый элемент списка
		p->top = i+1;
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

	for (int i = 0; i < n; i++) {
		flag_first = 0;
		for (int j = 0; j < n; j++) {
			if (G[i][j] == 1) {
				((p = (node*)malloc(sizeof(struct node))) == NULL);		// выделяем память под новый элемент списка
				p->top = j + 1;
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
	return head_top_first;													// возвращаем указатель на созданный элемент
}




/* Просмотр содержимого списка. */
void review(struct node* head_top) {
	struct node* tmp_top = NULL;

	if (head_top == NULL) {
		printf("Список пуст\n");
		return;
	}

	while (head_top != 0) {
		printf("%d -> ", head_top->top);
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


struct node* Otogd(struct node* head_top, int v1_keyboard, int v2_keyboard) {
	int flag_add, v_tmp;
	int number_one = 0;
	int mas_tops[100];

	struct node* v1_top = NULL;
	struct node* v1_top_save = NULL;
	struct node* v1_top_copy = NULL;
	struct node* v2_top = NULL;
	struct node* p = NULL;
	struct node* save = NULL;
	struct node* prev_head_top = NULL;
	struct node* head_top_first = head_top;
	struct node* prev_v1_top = NULL;
	

	if (v1_keyboard > v2_keyboard) {
		v_tmp = v1_keyboard;
		v1_keyboard = v2_keyboard;
		v2_keyboard = v_tmp;
	}


	while (head_top != 0) {
		if (v1_keyboard == head_top->top) {
			v1_top = head_top->next_list;
			v1_top_save = v1_top;
			save = head_top;
		}
		if (v2_keyboard == head_top->top) {
			v2_top = head_top->next_list;
			
		}
		head_top = head_top->next;
	}


	int flag_find = 0;
		v1_top = v1_top_save;
		while (v1_top != NULL) {
			if (v1_top->top == v2_keyboard) {
				flag_find = 1;
			}
			v1_top = v1_top->next;
		}
		
		if (flag_find == 0) {
			printf("Операция невозможна\nИсходный список:\n");
			return head_top_first;
		}

	while (v2_top != NULL) {
		flag_add = 0;

		v1_top_copy = v1_top;
			while (v1_top != NULL) {
				if (v2_top->top != v1_top->top) {
					flag_add = 1;
				}
				if (v2_top->top == v1_top->top) {
					flag_add = 0;
					break;
				}
				v1_top = v1_top->next;
			}
			/*if (flag_add == 1)*/ v1_top = v1_top_copy;

			if (flag_add == 0) {
				v2_top = v2_top->next;
				continue;
			}

			while (v1_top != NULL) {
				if ((v1_top->top != v2_top->top) and (v1_top->top > v2_top->top) and (save->next_list->top == v1_top->top)) {		//в начало
					((p = (node*)malloc(sizeof(struct node))) == NULL);
					save->next_list = p;
					p->next = v1_top;
					p->top = v2_top->top;
					v1_top_save = p;
					break;
				}

				if ((v1_top->top != v2_top->top) and (v1_top->next == NULL)) {															//в конец
					((p = (node*)malloc(sizeof(struct node))) == NULL);
					v1_top->next = p;
					p->next = NULL;
					p->top = v2_top->top;
					break;
				}


				if ((v1_top->top != v2_top->top) and (v1_top->top < v2_top->top) and (v1_top->next->top > v2_top->top )) {				//середиина
					save = v1_top->next;
					((p = (node*)malloc(sizeof(struct node))) == NULL);
					v1_top->next = p;
					p->next = save;
					p->top = v2_top->top;
					break;
				}

				v1_top = v1_top->next;
			}
			v1_top = v1_top_save;
	
		v2_top = v2_top->next;
	}

	head_top = head_top_first;
	while (head_top != NULL) {
		if (v1_keyboard == head_top->top) {
			head_top->next_list = v1_top_save;
			
		}
		if (v2_keyboard == head_top->top) {
			prev_head_top->next = head_top->next;
			free(head_top);
			break;
		}
		
		prev_head_top = head_top;
		head_top = head_top->next;
	}

	//printf("\n");
	//review(head_top_first);
	//printf("\n");

	int flag_delete = 0;
	head_top = head_top_first;						//удаление второй вершины во всем списке
	while (head_top != NULL) {
		v1_top = head_top->next_list;
		v1_top_save = v1_top;
		flag_delete = 0;

		while (v1_top != NULL) {
			if (v1_top->top == v1_keyboard) {
				flag_delete = 1;
				break;
			}
			v1_top = v1_top->next;
		}
		//v1_top = v1_top_save;


		if (flag_delete == 1) {
				v1_top = head_top->next_list;
				while (v1_top != NULL) {
					if (v1_top->top == v2_keyboard) {

						if (v1_top->top == head_top->next_list->top) {					//начало
							head_top->next_list = v1_top->next;
							v1_top_save = v1_top->next;
							free(v1_top);
							v1_top = v1_top_save;
							continue;
						}

						else {
							prev_v1_top->next = v1_top->next;
							v1_top_save = v1_top->next;
							free(v1_top);
							v1_top = v1_top_save;
							continue;

						}

					}
					prev_v1_top = v1_top;
					v1_top = v1_top->next;
				}
		}
		
		head_top = head_top->next;
	}

//	printf("\n");
//review(head_top_first);
//printf("\n");

	head_top = head_top_first;						//вершины указывающие на 2-ую -> указывают на 1-ую
	while (head_top != NULL) {
		v1_top = head_top->next_list;
		while (v1_top != NULL) {
			if (v1_top->top == v2_keyboard) {
				v1_top->top = v1_keyboard;
			}
			v1_top = v1_top->next;
		}
	head_top = head_top->next;
	}




	return head_top_first;
}


struct node* Connection_ribs(struct node* head_top, int v1_keyboard, int v2_keyboard) {
	
	head_top = Otogd(head_top, v1_keyboard, v2_keyboard);

	struct node* head_top_save = head_top;
	struct node* v_tops = NULL;
	struct node* prev = NULL;

	while (head_top != NULL) {
		if (v1_keyboard == head_top->top) {
			v_tops = head_top->next_list;
			break;
		}
		head_top = head_top->next;
	}

	while (v_tops != NULL) {
		if (v_tops->top == v1_keyboard) {
			if (prev == NULL) {
				head_top->next_list = v_tops->next;
			}
			else {
				prev->next = v_tops->next;
				free(v_tops);
			}
		}
		prev = v_tops;
		v_tops = v_tops->next;
	}
	
	return head_top_save;
}


struct node* Destroy_tops(struct node* head_top, int v1_keyboard) {
	struct node* head_top_save = head_top;
	struct node* p = NULL;
	struct node* new_top = NULL;
	struct node* old_top = NULL;
	struct node* v_tops = NULL;
	struct node* v_tops_save = NULL;
	struct node* prev = NULL;

	while (head_top != NULL) {							//создание вершины
		if (v1_keyboard == head_top->top) {
			old_top = head_top;
			((p = (node*)malloc(sizeof(struct node))) == NULL);
			p->next = head_top->next;
			head_top->next = p;
			p->top = v1_keyboard;
			new_top = p;
			v_tops = head_top->next_list;
			break;
		}
		head_top = head_top->next;
	}

	v_tops_save = v_tops;

	while (v_tops != NULL) {								//копирование связей
		((p = (node*)malloc(sizeof(struct node))) == NULL);
		p->top = v_tops->top;
		p->next = NULL;
		if (prev == NULL) {
			new_top->next_list = p;
			prev = p;
		}
		else {
			prev->next = p;
			prev = p;
		}
		v_tops = v_tops->next;
	}

	head_top = head_top_save;
	int number_of_top = 0;
	while (head_top != NULL) {
		if (number_of_top < head_top->top) number_of_top = head_top->top;
		head_top = head_top->next;
	}
	head_top = head_top_save;

	number_of_top++;
	new_top->top = number_of_top;

	int add;
	int flag_add = 0;
	add = v1_keyboard;
	v_tops = new_top->next_list;			//добавление связи м/д новой вершиной и старой (в новую вершину)
	while (v_tops != NULL) {
		
		if ((add != v_tops->top) and (add < v_tops->top) and (new_top->next_list->top == v_tops->top)) {
			((p = (node*)malloc(sizeof(struct node))) == NULL);
			new_top->next_list = p;
			p->next = v_tops;
			p->top = add;
			v_tops = p;
			flag_add = 1;
			break;

		}

		if ((add != v_tops->top) and (v_tops->next == NULL)) {															//в конец
			((p = (node*)malloc(sizeof(struct node))) == NULL);
			v_tops->next = p;
			p->next = NULL;
			p->top = add;
			break;
		}



		if ((add != v_tops->top) and (add > v_tops->top) and (add < v_tops->next->top)) {
			((p = (node*)malloc(sizeof(struct node))) == NULL);
			p->next = v_tops->next;
			v_tops->next = p;
			p->top = add;
			flag_add = 1;
			break;
		}
		v_tops = v_tops->next;
	}

	v_tops = new_top->next_list;
	if (flag_add = 0) {
			while (v_tops != NULL) {

				if (v_tops->next == NULL) {
					((p = (node*)malloc(sizeof(struct node))) == NULL);
					p->next = NULL;
					v_tops->next = p;
					p->top = add;
					break;
				}
				v_tops = v_tops->next;
			}
		
	}




	add = number_of_top;
	v_tops = old_top->next_list;			//добавление связи м/д новой вершиной и старой (в старую вершину)

	flag_add = 0;

	v_tops_save = v_tops;
	while (v_tops != NULL) {
		if (v_tops->top == add) flag_add= 1;
		v_tops = v_tops->next;
	}

	v_tops = v_tops_save;

	if (flag_add == 0) {
		while (v_tops != NULL) {

			if (v_tops->next == NULL) {
				((p = (node*)malloc(sizeof(struct node))) == NULL);
				p->next = NULL;
				v_tops->next = p;
				p->top = add;
				break;
			}

			v_tops = v_tops->next;
		}
	}



	return head_top_save;
}


int main() {
	int n1, n2;
	int v1_keyboard, v2_keyboard, v_tmp, v1, v2;
	int size_G = 0;
	

	setlocale(0, "rus");
	printf("Введите размер матрицы М1 -> ");
	scanf("%d", &n1);
	/*printf("Введите размер матрицы М2 -> ");
	scanf("%d", &n2);
	printf("\n");*/


	int** G1 = (int**)malloc(n1 * sizeof(int*));
	for (int i = 0; i < n1; i++) {
		G1[i] = (int*)malloc(n1 * sizeof(int));
	}

	/*int** G2 = (int**)malloc(n2 * sizeof(int*));
	for (int i = 0; i < n2; i++) {
		G2[i] = (int*)malloc(n2 * sizeof(int));
	}*/

	srand(time(0));
	for (int i = 0; i < n1; i++) {				//формирование матрицы смежности М1
		for (int j = 0; j < n1; j++) {
				if (j >= i) {		
					if (i == j) G1[i][j] = 0;
					else {
						G1[i][j] = rand() % 2;
						G1[j][i] = G1[i][j];
					}
				}
			printf(" %d", G1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	//for (int i = 0; i < n2; i++) {				//формирование матрицы смежности М2
	//	for (int j = 0; j < n2; j++) {
	//		if (j >= i) {				
	//			if (i == j) G2[i][j] = 0;
	//			else {
	//				G2[i][j] = rand() % 2;
	//				G2[j][i] = G2[i][j];
	//			}	
	//		}
	//		printf(" %d", G2[i][j]);
	//	}
	//	printf("\n");
	//}


	printf("\n");
	





	head = get_struct(G1, n1);
	review(head);



	//меню
	int menu_answer;
	int n;
	int start = 1;




	printf("\n1 - Отождествление вершины матрицы\n");
	printf("2 - Стягивание ребра матрицы\n");
	printf("3 - Расщепление вершины матрицы\n");
	printf("0 - Выход\n");


	while (start) {
		printf("Введите выбранный вариант -> ");
		scanf("%d", &menu_answer);

		if (menu_answer == 0) {
			start = 0;
		}

		else {
			switch (menu_answer) {
			case(1): {
				printf("\nОтождествление вершин\n");
				printf("Введите вершину №1 -> ");
				scanf("%d", &v1_keyboard);
				if ((v1_keyboard > n1) or (v1_keyboard < 1)) {
					printf("Данные некорректны\nПри выборе вершин введите число от 1 до %d\n\n", n1);
					break;
				}

				printf("Введите вершину №2 -> ");
				scanf("%d", &v2_keyboard);
				if ((v2_keyboard > n1) or (v2_keyboard < 1)) {
					printf("Данные некорректны\nПри выборе вершин введите число от 1 до %d\n\n", n1);
					break;
				}
				printf("\n");

				


				head = Otogd(head, v1_keyboard, v2_keyboard);
				review(head);
				break;
			}

			case(2): {
				printf("\nСтягивание вершин\n");
				printf("Введите вершину №1 -> ");
				scanf("%d", &v1_keyboard);
				if ((v1_keyboard > n1) or (v1_keyboard < 1)) {
					printf("Данные некорректны\nПри выборе вершин введите число от 1 до %d\n\n", n1);
					break;
				}
				printf("Введите вершину №2 -> ");
				scanf("%d", &v2_keyboard);
				if ((v2_keyboard > n1) or (v2_keyboard < 1)) {
					printf("Данные некорректны\nПри выборе вершин введите число от 1 до %d\n\n", n1);
					break;
				}
				printf("\n");
				head = Connection_ribs(head, v1_keyboard, v2_keyboard);
				review(head);
				break;
			}

			case(3): {
				printf("\nРасщепление вершины матрицы\n");
				printf("Введите вершину -> ");
				scanf("%d", &v1_keyboard);
				if ((v1_keyboard > n1) or (v1_keyboard < 1)) {
					printf("Данные некорректны\nПри выборе вершин введите число от 1 до %d\n\n", n1);
					break;
				}
				head = Destroy_tops(head, v1_keyboard);
				n1++;
				review(head);
				break;
			}

			case(0): {
				break;
			}
			}
		}
	}

        return 0;    
}

