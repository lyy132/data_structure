#include<iostream>
using namespace std;
typedef struct node {
	int x;
	struct node* next;
}Node;
void insert(Node* head, int n, int loc) {
	int cnt = 1;
	Node* p = head;
	Node* newnode = new Node();
	newnode->x = n;
	while (cnt < loc) {
		p = p->next;
		cnt++;

	}
	newnode->next = p->next;
	p->next = newnode;

}
void delete1(Node* head, int l) {
	int l1 = 1;
	Node* start = head;
	while (l1 < l) {
		l1++;
		start = start->next;
	}
	Node* gtd = start->next;
	start->next = gtd->next;
	free(gtd);
}
int main() {
/*int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int mid;
	int j = 0, k = 0;
	int cnt = 0;
	while (cnt<n) {
		if (a[j] <= b[k]) {
			cnt++;
			mid = a[j];
			j++;
		}
		else {
			cnt++;
			mid = b[k];
			k++;
		}

	}
	cout << mid << endl;
*/	
/*
		带头结点的链表，头插法
Node* first = new Node();
	first->next = nullptr;
	Node* head = first;
	int length=0;
	cin >> length;
	for (int k = 0; k < length; k++) {
		Node* temp = new Node();
		cin >> temp->x;
		temp->next = head->next;
		head->next = temp;
	}
	Node* p=head;
	while (p->next != nullptr) {
		p = p->next;
		printf("%d ", p->x);
	}
*/	
/*
	不带头结点的链表，头插法
	Node* head=nullptr;
	int length1 = 0;
	cin >> length1;
	for (int l = 0; l < length1; l++) {
		Node* temp1 = new Node();
		cin >> temp1->x;
		if (head == nullptr) {
			head = temp1;
			temp1->next = nullptr;
		}
		else {
			temp1->next = head;
			head = temp1;
		}
	}
	Node* p = head;
	while (p != nullptr) {
		printf("%d ", p->x);
		p = p->next;
	}
*/
//尾插法

	Node* head = new Node();
	Node* tail = head;
	int length2 = 0;
	cin >> length2;
	for (int m = 0; m < length2; m++) {
		Node* temp3 = new Node();
		cin >> temp3->x;
		temp3->next = nullptr;
		tail->next = temp3;
		tail = temp3;
	}
	Node* p = head;
	while (p->next != nullptr) {
		p = p->next;
		printf("%d ", p->x);

	}
	//插入值
	printf("请输入位置：");
	int loc = 0;
	cin >> loc;

	int n;
	cout << "请输入值" << endl;
	cin >> n;
	insert(head, n, loc);
	p = head;
	while (p->next != nullptr) {
		p = p->next;
		printf("%d ", p->x);

	}
	//删除值
	cout << "请输入要删除的位置" << endl;
	int del_loc;
	cin >> del_loc;
	delete1(head, del_loc);
	p = head;
	while (p->next != nullptr) {
		p = p->next;
		printf("%d ", p->x);

	}
	//按值查找
	printf("请输入要查找的值：");
	int n1;
	cin >> n1;
	int cnt = 1;
	Node* p1 = head->next;
	bool flag = false;
	while (p1!=nullptr) {
		if (p1->x == n1) {
			flag = true;
			break;
		}
		p1 = p1->next;

		cnt++;
	}
	if (flag == true) {
	printf("%d", cnt);
	}
	else {
		printf("-1");
	}

}