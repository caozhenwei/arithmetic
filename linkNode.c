//
//单链表的增删改查
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int score;
    struct student *next;
} LinkNode;

//删除链表中某个节点
void delete(LinkNode *link,int n) {
    int i = 0;
    LinkNode *t = link;
    LinkNode *findNode;
    while(i < n && t != NULL) {
        findNode = t;
        t = t->next;
        i++;
    }
    if(t != NULL) {
        findNode->next = t->next;
        free(findNode);
    } else {
        printf("节点不存在\n");
    }
}

//创建链表
LinkNode *create(int n) {
    if(n <= 0) {
        return 0;
    }
    LinkNode *head,*end,*node;
    head = (LinkNode *)malloc(sizeof(LinkNode));
    end = head;
    printf("请依次输入链表节点的值：\n");
    for(int i=0; i<n; i++) {
        node = (LinkNode *)malloc(sizeof(LinkNode));
        scanf("%d",&node->score);
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}

//打印链表
void printLink(LinkNode *link) {
    while(link->next != NULL) {
        link = link->next;
        printf("%d,",link->score);
    } 
    printf("\n");
}

int main() {
    printf("欢迎来到单链表的增删改查!\n请输入要创建链表的节点数:\n");
    int n;
    scanf("%d",&n);

    LinkNode *link = create(n);

    printLink(link);
    
    printf("请输入要删除的节点序号：\n");
    scanf("%d",&n);
    delete(link,n);
    printLink(link);
}
