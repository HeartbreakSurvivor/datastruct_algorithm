#include "stdafx.h"
#include "linklist.h"
#include <iostream>

using namespace std;

/*
******************************������ƪ*****************************
*/
/*
����һ������ͷ��������
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
β�巨����һ��������
buf: ָ��һ������
size: ����Ĵ�С
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
ͷ�巨����һ��������
buf: ָ��һ������
size: ����Ĵ�С
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
����һ�������ĵ�����
offset: �������һ���ڵ�Ӧ��ָ��ǰ��ĵڼ����ڵ�
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
����һ����ͷ����ѭ��������
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

//����һ��������
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

//�ڵ������в���ĳ��Ԫ��
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

//�����������ÿ���ڵ��ֵ
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

//����ѭ�����������ÿ���ڵ��ֵ
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

//������ĩβ����һ���ڵ�
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

//ɾ����������ĳ��ָ����ֵ
//ɾ������һ����Ҫ����ָ�룬�������ڼ�¼Ҫɾ���Ľڵ��ǰһ���ڵ�
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
        temp = p;//�ݴ湤��ָ��p
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
******************************˫����ƪ*****************************
*/

/*
����һ����ͷ����ѭ��˫����
*/
DLinklist create_loop_dlist(ElemType *buf, size_t length)
{
    DNode *head, *s, *r;//the head and tail pointer
    head = (DNode *)malloc(sizeof(DNode));//����һ��ͷ���
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
��ӡ˫����
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
�ж�˫�����Ƿ�Ϊ��
*/
int is_empty_dlinklist(DLinklist head)
{
    DNode *p = head->next;
    return p == head;
}

/*
����˫����ĳ���
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
