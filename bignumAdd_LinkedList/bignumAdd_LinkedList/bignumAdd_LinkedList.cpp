#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;

typedef struct bigNum {
	int data;
	struct bigNum *next;
}node;

node *creat()
{
	node *head, *p, *s;
	int x, cycle =1;
	head = (node*)malloc(sizeof(node));
	p = head;

	//cout<< "Please input the data:" ;
	while( (x = getchar()) != 10) {
		
		s = (node *)malloc(sizeof(node));
		x = x - '0';
		s->data = x;
		p->next = s;
		p = s;

	}
	//head = head->next;
	p->next = NULL;

	return (head);

}

int length (node *head)
{
	int n=0;
	node *p;
	p = head;
	while (p!=NULL) {
		p = p->next;
		n++;
	}

	return n;

}


void print (node *head) {
	node *p;
	int n;
	//n = length(head);
	p = head->next;
	//cout<< "Input num is:"<<endl;
	while ( p != NULL)
	{
		printf( "%d", p->data);
		p = p->next;
	}
	cout<< endl;
}

node *reverse(node *head) {
	node *p1, *p2, *p3;

	if ( head == NULL || head->next == NULL)
		return head;

	p1 = head->next;
	p2 = p1->next;
	p1->next = NULL;

	while(p2) {
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	head->next = p1;

	cout<< "After reversed:" <<endl;
	return head;
}

node * listnumAdd(node *num1, node *num2) {
	if ( num1==NULL || num1->next==NULL )
		return num2;
	else if ( num2 ==NULL || num2->next == NULL )
		return num1;

	int jinwei = 0;
	node *p = num1->next;
	node *q = num2->next;

	int sum = p->data + q->data;
	p->data = sum%10;
	jinwei = sum/10;

	while( p->next != NULL && q->next != NULL)
	{
		p = p->next;
		q = q->next;
		sum = p->data + q->data + jinwei;
		p->data = sum%10;
		jinwei = sum/10;
	}
	
	if ( p->next == NULL)
	{
		p->next = q->next;
	}

	while ( p->next) {
		p = p->next;
		sum = p->data + jinwei;
		p->data = sum%10;
		jinwei = sum/10;
	}

	if ( jinwei )
	{
		node *tail = (node*)malloc(sizeof(node));
		tail->data = jinwei;

		p->next = tail;
		tail->next = NULL;
	}
	return num1;
}

int main() {
	//input
	cout<< "******************Input***************"<<endl;
	cout << "输入加数  ：";
	node *L1 = creat();
	print(L1);
	
	cout << "输入被加数：";
	node *L2 = creat();
	print(L2);

	//reverse
	cout<< "*******************Reverse************" <<endl;
	L1 = reverse(L1);
	cout<< "L1 ";
	print(L1);
	L2 = reverse(L2);
	print(L2);

	//add
	cout<< "*******************Add***************" <<endl;
	listnumAdd(L1, L2);
	cout<< "After add:"<<endl;
	print(L1);

	reverse(L1);
	cout<< "Final result:"<<endl;
	print(L1);

	return 0;

}