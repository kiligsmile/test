#include<iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next=NULL;
} LNode, *LinkList;

void CreateList_R(LinkList &L) { //尾插法创建单链表
	//输入n个元素的值，建立带表头结点的单链表L
	int n;
	LinkList s, r;
	L=new LNode;
	L->next=NULL; //先建立一个带头结点的空链表
	r=L; //尾指针r指向头结点
	cout <<"请输入元素个数n：" <<endl;
	cin>>n;
	cout <<"尾插法（正序）创建单链表..." <<endl;
	while(n--) {
		s=new LNode;//生成新结点
		cin>>s->data; //输入元素值赋给新结点的数据域
		s->next=NULL;
		r->next=s;//将新结点s插入尾结点r之后
		r=s;//r指向新的尾结点s
	}
}

void Listprint_L(LinkList L) { //单链表的输出
	LinkList p;
	p=L->next;
	while (p) {
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
}

void SumofBigData(LinkList La, LinkList Lb, LinkList &Lc) { // La是包含头结点的空链表
	Lc = new LNode;
	Lc->next = NULL;
	LinkList p=La->next, q=Lb->next, end, t;  // p q分别指向被加数当前处理的位
	int carry;  // 存放每一位相加时的进位

	// 处理个位数
	end = new LNode;
	end->next = NULL;
	end->data = p->data + q->data;
	carry = end->data / 10;
	end->data %= 10;
	Lc->next = end;
	p = p->next;
	q = q->next;

	while(p!=NULL && q!=NULL) { // 从十位数开始将对应相加
		t = new LNode;
		t->next = NULL;
		t->data = p->data + q->data + carry;
		carry = t->data / 10;
		t->data %= 10;
		end->next = t;
		end = end->next;
		p = p->next;
		q = q->next;
	}

	if(p == NULL)
		p = q;  // p指向尚未处理完的数的未处理的最低位
	while(p != NULL) {
		t = new LNode;
		t->next = NULL;
		t->data = p->data + carry;
		carry = t->data / 10;
		t->data %= 10;
		end->next = t;
		end = end->next;
		p = p->next;
	}

	if(carry != 0){  // 最高位有进位
		t = new LNode;
		t->next = NULL;
		t->data = carry;
		end->next = t;
		end = end->next;
	}
	return;
}

int main() {
	LinkList La, Lb, Lc;
	cout<<"创建单链表La:"<<endl;
	CreateList_R(La);
	cout<<"单链表数据为:"<<endl;
	Listprint_L(La);
	cout<<"创建单链表Lb:"<<endl;
	CreateList_R(Lb);
	cout<<"单链表数据为:"<<endl;
	Listprint_L(Lb);
	SumofBigData(La,Lb,Lc);
	cout << "-----------------" << endl; 
	cout << "求和后的链表为Lc："<<endl;
	Listprint_L(Lc);

	return 0;
}
