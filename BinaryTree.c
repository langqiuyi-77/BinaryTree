#define MIN_VALUE -20

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *lChild;
    struct BiTNode *rChild;
}BiTNode,*BiTree; 

typedef struct{
	int *elem;
	int front;
	int rear;
	int maxsize;
}SqQueue;


//���򴴽�������
void CreateBiTree(BiTree *T) //�ص� �����Ĵ���ֻ��ֵ����
{
    int ch;
    scanf("%d",&ch);
    if (ch == -1)
    {
        *T = NULL;
        return;
    }
    else
    {
        (*T) = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        printf("����%d�����ӽڵ㣺",ch);
        CreateBiTree(&((*T)->lChild));
        printf("����%d�����ӽڵ㣺",ch);
        CreateBiTree(&((*T)->rChild));
    }

    return;
}

//�������������
void PreOrderBiTree(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("%d ",(T->data));
        PreOrderBiTree(T->lChild);
        PreOrderBiTree(T->rChild);
    }
}

//�������������
void MiddleOrderBiTree(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        MiddleOrderBiTree(T->lChild);
        printf("%d ",T->data);
        MiddleOrderBiTree(T->rChild);
    }
}

//��������������
void PostOrderBiTree(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PostOrderBiTree(T->lChild);
        PostOrderBiTree(T->rChild);
        printf("%d ",T->data);
    }
}


//Ҷ�ӽڵ����
int LeafCount(BiTree T)
{
    static int count;
    if (T != NULL)
    {
        if (T->lChild == NULL && T->rChild == NULL)
        {
            count++;
        }

        LeafCount(T->lChild);
        LeafCount(T->rChild);
    }

    return count;
}

//����������Ĵ�С
int find_size(BiTree T){
    if(T == NULL) return 0;
	return 1 + find_size(T->lChild) + find_size(T->rChild);
}

//�����������
int TreeDeep(BiTree T)
{
    int deep = 0;
    if (T != NULL)
    {
        int leftdeep = TreeDeep(T->lChild);
        int rightdeep = TreeDeep(T->rChild);
        deep = leftdeep >= rightdeep?leftdeep+1:rightdeep+1;
    }

    return deep;
}

//���ٶ�����
void DestoryBiTree(BiTree *T){ //���ٶ������ú�������
	if(*T != NULL) {
	DestoryBiTree(&((*T)->lChild));
	DestoryBiTree(&((*T)->rChild));
	*T = NULL;
	}
}

//�пն�����
void BiTreeEmpty(BiTree T){
	if(T == NULL) printf("������Ϊ��\n");
	else printf("�������ǿ�\n");
}



//��ת������ �������������
BiTree invertTree (BiTree T){
    BiTree temp;	
	if(T==NULL) return T;

	temp=T->lChild;
	T->lChild = T->rChild;
	T->rChild = temp;
	invertTree(T->lChild);
	invertTree(T->rChild);
	return T;
}

//������
int main()
{   BiTree T; int size;int depth,leafCount = 0;
    printf("�༶����1 ������������ ѧ�ţ�3219009454\n");
	
    printf("�������һ���ڵ��ֵ��-1��ʾû��Ҷ�ڵ㣺\n");
    CreateBiTree(&T);

    printf("���������������");
    PreOrderBiTree(T);
    printf("\n");

    printf("���������������");
    MiddleOrderBiTree(T);
    printf("\n");

    printf("����������������");
    PostOrderBiTree(T);
    printf("\n");

    depth = TreeDeep(T);
    printf("�������Ϊ��%d\n",depth);

	size = find_size(T);
	printf("�������Ĵ�С=%d\n",size);
    
    leafCount = LeafCount(T);
    printf("Ҷ�ӽڵ����:%d\n",leafCount);

	printf("��ת������\n");
	T=invertTree (T);
    printf("���������������");
    PreOrderBiTree(T);
    printf("\n");
	
	printf("���ٶ�����\n");
	DestoryBiTree(&T);
	BiTreeEmpty(T);
    

    return 0;
}
