//
//  main.c
//  LinkList
//
//  Created by 罗璞 on 2017/11/1.
//  Copyright © 2017年 Rbtoooooooooo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法建立单链表
// 头结点数据记录长度
LinkList createList1(LinkList l) {
    LNode *s;
    l=(LinkList)malloc(sizeof(LNode));
    l->next = NULL;
    l->data = 0;
    int x=0;
    while (1) {
        scanf("%d", &x);
        if (x==-1) {
            break;
        }
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = l->next;
        l->next = s;
        l->data++;
    }
    return l;
}

// 尾插法建立单链表
// 头结点数据记录长度
LinkList createList2(LinkList l) {
    l = (LinkList)malloc(sizeof(LNode));
    l->data = 0;
    LNode *s, *r = l;
    int x = 0;
    while (1) {
        scanf("%d", &x);
        if (x==-1) {
            break;
        }
        s = (LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next = s;
        r = s;
        l->data++;
    }
    return l;
}

// 按序号查找结点
LNode *getElemBySerial(LinkList l, int index) {
    if (l->data<index) {
        printf("序号大于链表长度%d\n", l->data);
        return l;
    }
    LNode *p = l;
    while (index!=0) {
        p = p->next;
        index--;
    }
    return p;
}

// 按值查找结点
LNode *getElemByValue(LinkList l, int e) {
    if (l->data == 0) {
        printf("该链表长度为零！返回头结点！\n");
        return l;
    }
    LNode *p = l->next;
    while (1) {
        if (p->data == e) {
            break;
        }
        if (p->next == NULL) {
            printf("该链表无此值！返回头结点！\n");
            p = l;
            break;
        }
        p = p->next;
    }
    return p;
}

// 插入结点
void insertElem(LinkList l, int index, int e) {
    if (index > l->data + 1 || index < 1) {
        printf("位序不应该超过（链表长度+1）或者小于1\n");
        return;
    }
    
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p->data = e;
// 这样写简单一点点
    LNode *s = getElemBySerial(l, index-1);
    p->next = s->next;
    s->next = p;
    
// 这样写复杂一点点
//    p->next = NULL;
//    if (index != l->data+1) {
//        p->next = getElemBySerial(l, index);
//    }
//    getElemBySerial(l, index-1)->next = p;
    
    l->data++;
}

LNode *deleteElem(LinkList l, int index) {
    if (index>l->data || index<0) {
        printf("位序不应该超过链表长度或者小于1");
        return l;
    }
    LNode *p = getElemBySerial(l, index);
    getElemBySerial(l, index-1)->next = p->next;
    l->data--;
    // 为什么free(p)了，还能把p->data输出？？？？？？？？？？？？？？？？？？
    free(p);
    printf("%d****\n", p->data);
    return p;
}

// 打印链表长度及数据
void print(LinkList l) {
    int x;
    if (l->data == 0) {
        printf("该链表长度为0！返回头结点！\n");
        return;
    }
    LNode *p = l->next;
    printf("该链表长度为：%d\n", l->data);
    while(p!=NULL) {
        x=p->data;
        printf("%d ", x);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    LinkList l1;
    
    l1 = createList2(l1);
    
    print(l1);
    print(deleteElem(l1, 1));
    print(l1);
    return 0;
}
