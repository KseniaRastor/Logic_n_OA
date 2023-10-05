#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;
int count = 0;

struct Node* CreateTree(struct Node* root, struct Node* r, int data){
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
}


void print_tree(struct Node* r, int l){
	if (r == NULL){
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++){
		printf("  ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}

int find(struct Node* r, int D_find) {

	if (r == NULL){
		return count;
	}

	if (r->data == D_find) count++;
		
	find(r->right, D_find);
	find(r->left, D_find);
}



int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;
	int D_find;

	root = NULL;
	printf("-1 - окончание построения дерева\n");
	while (start)
	{
		printf("Введите число: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);
	}

	print_tree(root, 0);

	printf("\nВведите искомый элемент -> ");
	scanf("%d", &D_find);
	count = find(root, D_find);
	if (count) printf("\nИскомый элемент найден %d раз(а)\n", count);
	else printf("\nИскомый элемент не найден\n");

	return 0;
}
