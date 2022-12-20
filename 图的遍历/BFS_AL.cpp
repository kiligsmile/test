#include <iostream>
#include <queue>//�������ͷ�ļ�
using namespace std;

const int MaxVnum=100;//���������ֵ
bool visited[MaxVnum];  //���ʱ�־���飬���ֵΪ"false"
typedef char VexType;//�������������Ϊ�ַ���

typedef struct AdjNode{ //�����ڽӵ�����
	int v; //�ڽӵ��±�
	struct AdjNode *next; //ָ����һ���ڽӵ�
}AdjNode;

typedef struct VexNode{ //���嶥������
	VexType data; // VexTypeΪ������������ͣ�������Ҫ����
	AdjNode *first; //ָ���һ���ڽӵ�
}VexNode;

typedef struct{//�����ڽӱ�����
    VexNode  Vex[MaxVnum];
    int vexnum,edgenum; //������������
}ALGragh;

int locatevex(ALGragh G,VexType x)
{
    for(int i=0;i<G.vexnum;i++)//���Ҷ�����Ϣ���±�
		if(x==G.Vex[i].data)
			return i;
    return -1;//û�ҵ�
}

void insertedge(ALGragh &G,int i,int j)//����һ����
{
    AdjNode *s;
    s=new AdjNode;
    s->v=j;
    s->next=G.Vex[i].first;
    G.Vex[i].first=s;
}

void printg(ALGragh G)//����ڽӱ�
{
   cout<<"----------�ڽӱ����£�----------"<<endl;
   for(int i=0;i<G.vexnum;i++)
   {
       AdjNode *t=G.Vex[i].first;
       cout<<G.Vex[i].data<<"��  ";
       while(t!=NULL)
       {
           cout<<"["<<t->v<<"]  ";
           t=t->next;
       }
       cout<<endl;
   }
}

void CreateALGraph(ALGragh &G)//��������ͼ�ڽӱ�
{
    int i,j;
    VexType u,v;
    cout<<"�����붥�����ͱ���:"<<endl;
    cin>>G.vexnum>>G.edgenum;
    cout << "�����붥����Ϣ:"<<endl;
    for(i=0;i<G.vexnum;i++)//���붥����Ϣ�����붥����Ϣ����
        cin>>G.Vex[i].data;
    for(i=0;i<G.vexnum;i++)
        G.Vex[i].first=NULL;
    cout<<"����������ÿ���ߵ���������u,v"<<endl;
    while(G.edgenum--)
    {
        cin>>u>>v;
        i=locatevex(G,u);//���Ҷ���u�Ĵ洢�±�
        j=locatevex(G,v);//���Ҷ���v�Ĵ洢�±�
        if(i!=-1&&j!=-1)
            insertedge(G,i,j);
        else
        {
			cout << "���붥����Ϣ�����������룡"<<endl;
			G.edgenum++;//�������벻��
        }
    }
}

void BFS_AL(ALGragh G,int v)//�����ڽӱ�Ĺ�����ȱ���
{
    int u,w;
    AdjNode *p;
    queue<int>Q; //����һ����ͨ����(�Ƚ��ȳ�)��������int����
    cout<<G.Vex[v].data<<"\t";
    visited[v]=true;
    Q.push(v); //Դ��v���
    while(!Q.empty()) //������в���
    {
        u=Q.front();//ȡ����ͷԪ�ظ�ֵ��u
        Q.pop(); //��ͷԪ�س���
        p=G.Vex[u].first;
        while(p)//���μ��u�������ڽӵ�
        {
            w=p->v;//wΪu���ڽӵ�
            if(!visited[w])//wδ������
            {
            	cout<<G.Vex[w].data<<"\t";
            	visited[w]=true;
            	Q.push(w);
            }
            p=p->next;
        }
    }
}

void BFS_AL(ALGragh G)//����ͨͼ�������ڽӱ�Ĺ�����ȱ���
{
    for(int i=0;i<G.vexnum;i++)//����ͨͼ��Ҫ��©�㣬���δ�����ʵĶ���
    	if(!visited[i])//iδ������,��iΪ����ٴι�����ȱ���
       		BFS_AL(G,i);
}

int main()
{
    ALGragh G;
    int v;
    VexType c;
    CreateALGraph(G);//��������ͼ�ڽӱ�
    printg(G);//����ڽӱ�
    cout<<"�����������ͨͼ����ʼ�㣺";
	cin>>c;
	v=locatevex(G,c);//���Ҷ���u�Ĵ洢�±�
    if(v!=-1)
    {
        cout <<"�����������������ͨͼ�����"<<endl;
        BFS_AL(G,v);
    }
    else
        cout<<"���붥����Ϣ�����������룡"<<endl;
    return 0;
}
