#include<iostream>
#include<string>
using namespace std;

typedef struct LNode {
	int data; //����������
	struct LNode *next; //����ָ����
}LNode, *LinkList; //LinkListΪָ��ṹ��LNode��ָ������

void CreateList_R(LinkList &L)//β�巨����������
{
	//����n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	int n;
	LinkList s, r;
	L=new LNode;
	L->next=NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r=L; //βָ��rָ��ͷ���
	cout <<"������Ԫ�ظ���n��" <<endl;
	cin>>n;
	cout <<"����������n��������(�ǵݼ�)��" <<endl;
	cout <<"β�巨����������..." <<endl;
	while(n--)
    {
		s=new LNode;//�����½��
		cin>>s->data; //����Ԫ��ֵ�����½���������
		s->next=NULL;
		r->next=s;//���½��s����β���r֮��
		r=s;//rָ���µ�β���s
	}
}

void mergelinklist(LinkList La, LinkList Lb, LinkList &Lc)
{
    LinkList p,q,r;
    p=La->next; //pָ��La�ĵ�һ��Ԫ��
    q=Lb->next; //qָ��Lb�ĵ�һ��Ԫ��
    Lc=La;      //Lcָ��La��ͷ���
    r=Lc;       //rָ��Lc��β��
    while(p&&q)
    {
        if(p->data<=q->data)//��pָ��Ľ�㴮����
        {
            r->next=p;
            r=p;
            p=p->next;//p����һ����� 
        }
        else             //��qָ��Ľ�㴮����
        {
            r->next=q;
            r=q;
            q=q->next;
        }
    }
    r->next=p?p:q;//�൱��if(p) r->next=p; else r->next=q;
    delete Lb;
}

void Listprint_L(LinkList L) //����������
{
    LinkList p;
    p=L->next;
    while (p)
    {
        cout<<p->data<<"\t";
		p=p->next;
    }
    cout<<endl;
}

int main()
{
	LinkList La,Lb,Lc;
	cout << "�������򣨷ǵݼ���������La:"<<endl;
	CreateList_R(La);
	cout << "�������򣨷ǵݼ���������Lb:"<<endl;
	CreateList_R(Lb);
	cout << "���������򣨷ǵݼ���������La��Lb�ϲ�ΪLc��"<<endl;
	mergelinklist(La,Lb,Lc);
	cout << "�ϲ���Ľ��Lc��"<<endl;
	Listprint_L(Lc);
	return 0;
}

