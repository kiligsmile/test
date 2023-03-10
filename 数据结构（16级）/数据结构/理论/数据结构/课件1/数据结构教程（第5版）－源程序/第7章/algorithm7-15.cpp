//【例7.15】的算法：判断两棵二叉树是否相似
#include "btree.cpp"
bool Like(BTNode *b1,BTNode *b2)
//b1和b2两棵二叉树相似时返回true，否则返回false
{
    bool like1,like2;
    if (b1==NULL && b2==NULL) 
		return true;
    else if (b1==NULL || b2==NULL) 
		return false;
    else
    {
		like1=Like(b1->lchild,b2->lchild);
		like2=Like(b1->rchild,b2->rchild);
		return (like1 && like2);		//返回like1和like2的与
    }
}
int main()
{
	bool l;
	BTNode *b1,*b2;
	CreateBTree(b1,"A(B(D(,G)),C(E,F))");
	printf("b1:");DispBTree(b1);printf("\n");
	CreateBTree(b2,"a(b(d(,g)),c(e,f))");
	printf("b2:");DispBTree(b2);printf("\n");
	l=Like(b1,b2);
	if (l==true)
		printf("b1和b2相似\n");
	else
		printf("b1和b2不相似\n");
	DestroyBTree(b1);
	DestroyBTree(b2);
	return 1;
}
