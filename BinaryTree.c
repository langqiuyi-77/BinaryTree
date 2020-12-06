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


//先序创建二叉树
void CreateBiTree(BiTree *T) //重点 参数的传递只有值传递
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
        printf("输入%d的左子节点：",ch);
        CreateBiTree(&((*T)->lChild));
        printf("输入%d的右子节点：",ch);
        CreateBiTree(&((*T)->rChild));
    }

    return;
}

//先序遍历二叉树
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

//中序遍历二叉树
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

//后续遍历二叉树
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


//叶子节点个数
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

//计算二叉树的大小
int find_size(BiTree T){
    if(T == NULL) return 0;
	return 1 + find_size(T->lChild) + find_size(T->rChild);
}

//二叉树的深度
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

//销毁二叉树
void DestoryBiTree(BiTree *T){ //销毁二叉树用后续遍历
	if(*T != NULL) {
	DestoryBiTree(&((*T)->lChild));
	DestoryBiTree(&((*T)->rChild));
	*T = NULL;
	}
}

//判空二叉树
void BiTreeEmpty(BiTree T){
	if(T == NULL) printf("二叉树为空\n");
	else printf("二叉树非空\n");
}



//翻转二叉树 不能用中序遍历
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

//主函数
int main()
{   BiTree T; int size;int depth,leafCount = 0;
    printf("班级：计1 姓名：郎秋意 学号：3219009454\n");
	
    printf("请输入第一个节点的值，-1表示没有叶节点：\n");
    CreateBiTree(&T);

    printf("先序遍历二叉树：");
    PreOrderBiTree(T);
    printf("\n");

    printf("中序遍历二叉树：");
    MiddleOrderBiTree(T);
    printf("\n");

    printf("后续遍历二叉树：");
    PostOrderBiTree(T);
    printf("\n");

    depth = TreeDeep(T);
    printf("树的深度为：%d\n",depth);

	size = find_size(T);
	printf("二叉树的大小=%d\n",size);
    
    leafCount = LeafCount(T);
    printf("叶子节点个数:%d\n",leafCount);

	printf("反转二叉树\n");
	T=invertTree (T);
    printf("先序遍历二叉树：");
    PreOrderBiTree(T);
    printf("\n");
	
	printf("销毁二叉树\n");
	DestoryBiTree(&T);
	BiTreeEmpty(T);
    

    return 0;
}
