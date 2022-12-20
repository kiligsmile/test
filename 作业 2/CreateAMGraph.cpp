//�ڽӾ��󴴽�����ͼ
#include <iostream>
using namespace std;

#define MaxVnum 100  //���������ֵ
typedef char VexType;  //������������ͣ�������Ҫ����
typedef int EdgeType;  //����Ȩֵ���������ͣ�������Ȩֵ��ͼ����Ϊ0��1
typedef struct{
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum,edgenum; //������������
}AMGragh;

int locatevex(AMGragh G,VexType x)
{
    for(int i=0;i<G.vexnum;i++)//���Ҷ�����Ϣ���±�
       if(x==G.Vex[i])
        return i;
    return -1;//û�ҵ�
}


void CreateAMGraph(AMGragh &G)
{
    int i,j;
    VexType u,v;
    cout << "�����붥������"<<endl;
    cin>>G.vexnum;
    cout << "���������:"<<endl;
    cin>>G.edgenum;
    cout << "�����붥����Ϣ:"<<endl;
    for(int i=0;i<G.vexnum;i++)//���붥����Ϣ�����붥����Ϣ����
        cin>>G.Vex[i];
    for(int i=0;i<G.vexnum;i++)//��ʼ���ڽӾ�������ֵΪ0��������������ʼ���ڽӾ���Ϊ�����
      for(int j=0;j<G.vexnum;j++)
         G.Edge[i][j]=0;
    cout << "������ÿ�����������������㣺"<<endl;
    while(G.edgenum--)
    {
       cin>>u>>v;
       i=locatevex(G,u);//���Ҷ���u�Ĵ洢�±�
       j=locatevex(G,v);//���Ҷ���v�Ĵ洢�±�
       if(i!=-1&&j!=-1)
         G.Edge[i][j]=G.Edge[j][i]=1; //�ڽӾ�����1
       else
       {
           cout << "���붥����Ϣ�����������룡"<<endl;
           G.edgenum++;//�������벻��
       }
    }
}

void print(AMGragh G)//����ڽӾ���
{
    cout<<"ͼ���ڽӾ���Ϊ��"<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
         cout<<G.Edge[i][j]<<"\t";
        cout<<endl;
    }
}


int main()
{
    AMGragh G;
    CreateAMGraph(G);
    print(G);
    return 0;
}

