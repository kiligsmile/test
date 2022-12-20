#include<iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next=NULL;
} LNode, *LinkList;

void CreateList_R(LinkList &L) { //β�巨����������
	//����n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	int n;
	LinkList s, r;
	L=new LNode;
	L->next=NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r=L; //βָ��rָ��ͷ���
	cout <<"������Ԫ�ظ���n��" <<endl;
	cin>>n;
	cout <<"β�巨�����򣩴���������..." <<endl;
	while(n--) {
		s=new LNode;//�����½��
		cin>>s->data; //����Ԫ��ֵ�����½���������
		s->next=NULL;
		r->next=s;//���½��s����β���r֮��
		r=s;//rָ���µ�β���s
	}
}

void Listprint_L(LinkList L) { //����������
	LinkList p;
	p=L->next;
	while (p) {
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
}

void SumofBigData(LinkList La, LinkList Lb, LinkList &Lc) { // La�ǰ���ͷ���Ŀ�����
	Lc = new LNode;
	Lc->next = NULL;
	LinkList p=La->next, q=Lb->next, end, t;  // p q�ֱ�ָ�򱻼�����ǰ�����λ
	int carry;  // ���ÿһλ���ʱ�Ľ�λ

	// �����λ��
	end = new LNode;
	end->next = NULL;
	end->data = p->data + q->data;
	carry = end->data / 10;
	end->data %= 10;
	Lc->next = end;
	p = p->next;
	q = q->next;

	while(p!=NULL && q!=NULL) { // ��ʮλ����ʼ����Ӧ���
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
		p = q;  // pָ����δ�����������δ��������λ
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

	if(carry != 0){  // ���λ�н�λ
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
	cout<<"����������La:"<<endl;
	CreateList_R(La);
	cout<<"����������Ϊ:"<<endl;
	Listprint_L(La);
	cout<<"����������Lb:"<<endl;
	CreateList_R(Lb);
	cout<<"����������Ϊ:"<<endl;
	Listprint_L(Lb);
	SumofBigData(La,Lb,Lc);
	cout << "-----------------" << endl; 
	cout << "��ͺ������ΪLc��"<<endl;
	Listprint_L(Lc);

	return 0;
}
