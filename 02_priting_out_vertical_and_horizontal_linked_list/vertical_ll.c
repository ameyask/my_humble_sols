#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct llnode_ {
	int val;
	struct llnode_ *next;
	struct llnode_ *down;
}llnode;

llnode *ll_head=0;

int main()
{

	int hor_n, ver_n;
	int i,j;
	llnode *p=NULL, *q=NULL, *tp, *tq;

	printf("Enter the number of Horizontal Nodes: ");
	scanf("%d", &hor_n);
	
	for( i=0 ; i<hor_n ; i++ ) {

		p = (llnode *)malloc(sizeof(llnode));
		if (!p) {
			printf("malloc failed!");
			exit(-1);
		}
		p->next=NULL;
		p->down=NULL;

		printf("Enter the Value of Horizontal Node %d: ", i);
		scanf("%d",&p->val);

		if (ll_head == NULL) {
			ll_head = p;
			tp = p;
		}
		else {
			tp->next = p;
			tp = tp->next;
		}
		tq = p;

		printf("Enter the number of vertical nodes for this node: ");
		scanf("%d", &ver_n);

		for( j=0 ; j<ver_n ; j++ ) {

			q = (llnode *)malloc(sizeof(llnode));
			if (!q) {
				printf("malloc failed!");
				exit(-1);
			}
			q->next=NULL;
			q->down=NULL;

			printf("Enter the value for %d vertical Node of Node %d: ", j, i);
			scanf("%d", &q->val);

			tq->down = q;
			tq = tq->down;
		}

	}

	printf("\n\n The vertical LL is: \n");

	tp = ll_head;
	while ( tp != NULL ) {
		printf("\nNode %d:  ", tp->val);
		tq = tp->down;
		while ( tq != NULL ) {
			printf("%d ", tq->val);
			tq = tq->down;
		}
		tp = tp->next;
	}

	printf("\n");
	return(0);
}
