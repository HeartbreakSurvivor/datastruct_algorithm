#include "stdafx.h"
#include "linklist.h"
#include <iostream>

using namespace std;

/*
******************************单链表篇*****************************
*/
/*
建立一个不带头结点的链表
*/
Linklist create_Linklist(ElemType *buf, size_t length)
{
    if (buf == nullptr || length <= 0) return nullptr;
    LNode *head = (LNode*)malloc(sizeof(LNode));
    head->data = buf[0];
    head->next = nullptr;
    LNode *r = head, *s;//the head and tail pointer
    for (size_t i = 1; i < length; i++)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = buf[i];
        r->next = s;
        r = s;
    }
    r->next = nullptr;
    return head;
}

/*
尾插法创建一个单链表
buf: 指向一个数组
size: 数组的大小
*/
Linklist create_Linklist_from_tail(ElemType *buf, size_t length)
{
    //if (buf == nullptr || length <= 0) return nullptr;
    LNode *head, *s, *r;//the head and tail pointer
    head = (LNode *)malloc(sizeof(LNode));//create a head node
    head->next = nullptr;
    r = head;
    for (size_t i = 0; i < length; i++)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = buf[i];
        r->next = s;
        r = s;
    }
    r->next = nullptr;
    return head;
}

/*
头插法创建一个单链表
buf: 指向一个数组
size: 数组的大小
*/
Linklist create_linklist_from_head(ElemType *buf, size_t length)
{
    if (buf == nullptr || length <= 0) return nullptr;
    LNode *head,*s;//work pointer
    head = (LNode *)malloc(sizeof(LNode));//create a head node
    head->next = nullptr;
    for (size_t i = 0; i < length; i++)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = buf[i];
        s->next = head->next;
        head->next = s;
    }
    return head;
}

/*
创建一个带环的单链表
offset: 代表最后一个节点应该指向前面的第几个节点
*/
Linklist create_cycle_linklist(ElemType *buf, size_t length, int offset)
{
    if (buf == nullptr || length <= 0 || offset > length) return nullptr;
    LNode *head, *s, *r, *tail;//the head and tail pointer
    head = (LNode *)malloc(sizeof(LNode));//create a head node
    head->next = nullptr;
    tail = r = head;
    for (size_t i = 0; i < length; i++)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = buf[i];
        if (i == offset) {
            tail = s;//make the tail pointer to the corresponding node 
        }
        r->next = s;
        r = s;
    }
    r->next = tail;//form a loop
    return head;
}

/*
创建一个带头结点的循环单链表
*/
Linklist create_loop_list(ElemType *buf, size_t length)
{
    LNode *head, *s, *r;//the head and tail pointer
    head = (LNode *)malloc(sizeof(LNode));//create a head node
    head->next = nullptr;
    r = head;
    for (size_t i = 0; i < length; i++)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = buf[i];
        r->next = s;
        r = s;
    }
    r->next = head;
    return head;
}

//销毁一个单链表
void destroy_linklist(Linklist L)
{
    if (!L) return;
    LNode *p = L->next, *q;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    free(L);
}

//在单链表中查找某个元素
LNode* locate_x_in_linklist(Linklist L, ElemType x)
{
    if (!L) return nullptr;
    LNode *p = L->next;
    while (p)
    {
        if (p->data == x) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

//遍历链表，输出每个节点的值
void traverse_linklist(Linklist L)
{
    cout << "linklist's nodes:" << endl;
    LNode *p = L->next;
    while (p)
    {
        if (!p->next) 
            cout << p->data;
        else
            cout << p->data << " -> ";
        p = p->next;
    }
    cout << endl;
}

//遍历循环单链表，输出每个节点的值
void traverse_cycle_list(Linklist L)
{
    cout << "cycle linklist's nodes:" << endl;
    LNode *p = L->next;
    while (p!=L)
    {
        if (p->next!=L)
            cout << p->data << " -> ";
        else
            cout << p->data;
        p = p->next;
    }
    cout << endl;
}

//在链表末尾插入一个节点
bool insert_node_linklist(Linklist L, ElemType x)
{
    if (!L) return false;
    LNode*p = L->next;
    while (p)
    {
        if (p->next == nullptr) {
            LNode *s = (LNode*)malloc(sizeof(LNode));
            s->data = x;
            s->next = nullptr;
            p->next = s;
            return true;
        }
        p = p->next;
    }
}

//删除单链表中某个指定的值
//删除操作一般需要两个指针，其中用于记录要删除的节点的前一个节点
bool delete_node_linklist(Linklist L, ElemType x)
{
    if (!L) return false;
    LNode *p = L->next, *temp;
    if (p->data == x) {
        L = p->next;
        free(p);
        return true;
    }
    while (p)
    {
        temp = p;//暂存工作指针p
        p = p->next;
        if (p->data == x) {
            temp->next = p->next;
            free(p);
            return true;
        }
    }
    return false;
}

int get_length_linklist(Linklist L)
{   
    int length = 0;
    LNode *p = L->next;
    while (p!=nullptr)
    {
        length++;
        p = p->next;
    }
    return length;
}


/*
******************************双链表篇*****************************
*/

/*
创建一个带头结点的循环双链表
*/
DLinklist create_loop_dlist(ElemType *buf, size_t length)
{
    DNode *head, *s, *r;//the head and tail pointer
    head = (DNode *)malloc(sizeof(DNode));//创建一个头结点
    head->next = head;
    head->prev = head;
    r = head;
    for (size_t i = 0; i < length; i++)
    {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = buf[i];
        s->prev = r;
        s->next = head;
        r->next = s;
        head->prev = s;
        r = s;
    }
    return head;
}

/*
打印双链表
*/
void traverse_dlinklist(DLinklist head)
{
    DNode *p = head->next;
    printf("dlinklist's values: \n");
    while (p != head)
    {
        if(p->next != head)
            cout << p->data << " -> ";
        else
            cout << p->data << " ";
        p = p->next;
    }
    cout << std::endl;
}

/*
判断双链表是否为空
*/
int is_empty_dlinklist(DLinklist head)
{
    DNode *p = head->next;
    return p == head;
}

/*
计算双链表的长度
*/
int get_length_dlinklist(DLinklist head)
{
    int length = 0;
    DNode *p = head->next;
    while (p != head)
    {
        length++;
        p = p->next;
    }
    return length;
}
