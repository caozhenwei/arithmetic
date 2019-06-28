//  
//  二叉树
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int ElemType;

typedef struct BinNode {
    ElemType data;
    struct BinNode *lChild;
    struct BinNode *rChild;
}BinNode,*BiTree;

//前序创建二叉树
int createBiTree(BiTree *T) {
    ElemType data;
    scanf("%d",&data);
    if(data == -1) {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BinNode));
        if(!(*T)) {
            exit(-1);
        }
        (*T)->data = data;
        printf("输入%d的左子结点：",data);
        createBiTree(&(*T)->lChild);
        printf("输入%d的右子结点：",data);
        createBiTree(&(*T)->rChild);
    }
    return 0;
}

//二叉树深度
int treeDeep(BiTree T) {
    int deep = 0;
    if(T) {
        int leftDeep = treeDeep(T->lChild);
        int rightDeep = treeDeep(T->rChild);
        deep = (leftDeep >= rightDeep ? leftDeep + 1 : rightDeep + 1);
    }
    return deep;
}

//二叉树叶子结点个数
int leafCount(BiTree T,int *num) {
    if(T) {
        if(T->lChild == NULL && T->rChild == NULL){
            (*num)++;
        }
        leafCount(T->lChild,num);
        leafCount(T->rChild,num);
    }
    return *num;
}

//前序遍历二叉树
void preOrderTree(BiTree T) {
    if(T == NULL) {
        return;
    }
    printf("%d,",T->data);
    preOrderTree(T->lChild);
    preOrderTree(T->rChild);
}

//中序遍历二叉树
void inOrderTree(BiTree T) {
    if(T == NULL) {
        return;
    }
    inOrderTree(T->lChild);
    printf("%d,",T->data);
    inOrderTree(T->rChild);
}

//后序遍历二叉树
void postOrderTree(BiTree T) {
    if(T == NULL) {
        return;    
    }
    postOrderTree(T->lChild);
    postOrderTree(T->rChild);
    printf("%d,",T->data);
}

int main() {
    BiTree T;
    printf("请输入第一个结点的值(-1代表没有叶子结点):\n");
    createBiTree(&T);
    
    printf("前序遍历二叉树：\n");
    preOrderTree(T);
    printf("\n");

    printf("中序遍历二叉树：\n");
    inOrderTree(T);
    printf("\n");

    printf("后序遍历二叉树：\n");
    postOrderTree(T);
    printf("\n");

    int deep;
    printf("二叉树的深度为:%d\n",treeDeep(T));

    int count;
    printf("二叉树的叶子结点为：%d\n",leafCount(T,&count));
    return 0;
}
