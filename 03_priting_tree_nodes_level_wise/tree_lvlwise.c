#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct trnode_ {
	int value;
	struct trnode_ *lchild;
	struct trnode_ *rchild;
	struct trnode_ *next;
}trnode;

trnode *root=0;

trnode *q_front=0;
trnode *q_rear=0;

void input_tree();
void display_inorder_tree();
void display_lvlwise();
void q_add(trnode *);
trnode * q_del();
int q_empty();

int main()
{
	trnode *p;

	p = (trnode *)malloc(sizeof(trnode)*1);
	if (!p) {
		printf("Error while allocating Memory! \n");
		exit(1);
	}

	p->lchild = p->rchild = p->next = NULL;
	printf("Enter the value at Root: ");
	scanf("%d", &p->value);
	q_add(p);	
	root = p;

	input_tree();
	q_front = q_rear = NULL;

	printf("\n\nThe inorder traversal of the input-ed tree is: \n");
	display_inorder_tree(root);

	printf("\n\nThe Level-wise printing of the input-ed tree is: \n");
	display_lvlwise();

	printf("\n");
	return(0);
}

void input_tree()
{

	int isleft=0, isright=0;
	trnode *p, *p_left, *p_right;

	do {	
		p = q_del();

		printf("Does the node with value %d have left child? (1:yes, 0:no) : ", p->value);
		scanf("%d", &isleft);
		if (isleft) {
			p_left = (trnode *)malloc(sizeof(trnode)*1);
			if (!p_left) {
				printf("Error while allocating Memory! \n");
				exit(1);
			}
			p_left->lchild = p_left->rchild = p_left->next = NULL;
			printf("Enter the value: ");
			scanf("%d", &p_left->value);
			p->lchild = p_left;

			q_add(p_left);
		}

		printf("Does the node with value %d have right child? (1:yes, 0:no) : ", p->value);
		scanf("%d", &isright);
		if (isright) {
			p_right = (trnode *)malloc(sizeof(trnode)*1);
			if (!p_right) {
				printf("Error while allocating Memory! \n");
				exit(1);
			}
			p_right->lchild = p_right->rchild = p_right->next = NULL;
			printf("Enter the value: ");
			scanf("%d", &p_right->value);
			p->rchild = p_right;
	
			q_add(p_right);
		}

	}while(!q_empty());

}

void display_inorder_tree(trnode *p)
{
	if (p) {
		display_inorder_tree(p->lchild);	
		printf("%d ", p->value);
		display_inorder_tree(p->rchild);	
	}
}

void display_lvlwise()
{

	int prev_count, count;
	int tmp;
	trnode *p = root;

	prev_count = 1;
	count = 0;

	q_add(p);

	while ( !(prev_count==0 && count==0) ) {

		p = q_del();

		if (p->lchild != NULL) {
			q_add(p->lchild);
			count++;
		}
		if (p->rchild != NULL) {
			q_add(p->rchild);
			count++;
		}

		printf("%d ", p->value);	

		prev_count--;
		if (prev_count == 0) {
			printf("\n");
			tmp = prev_count;
			prev_count = count;
			count = tmp;	
		}
	}

}

int q_empty()
{
	if (q_front == NULL && q_rear == NULL) 
		return 1;
	else
		return 0;
}

void q_add(trnode *p)
{
	if (q_empty()) {
		q_front = p;
		q_rear = p;
	}
	else {
		q_rear->next = p;
		q_rear = q_rear->next;
	}
}

trnode * q_del()
{
	trnode *p = q_front; 

	if (q_front == q_rear) 
		q_front = q_rear = 0;
	else {
		q_front = q_front->next;
	}

	return (p);
}

