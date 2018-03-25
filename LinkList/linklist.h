#pragma once
#include "stdafx.h"

/*
���Ա����ʽʵ��
author: halo.zhang
date: 2018/3/17
*/

#define MAXSIZE  100
typedef int ElemType;

//������ڵ�ṹ
typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode;
typedef struct LNode* Linklist;

//˫����ڵ�ṹ
typedef struct DNode {
    ElemType data;
    struct DNode* prev;
    struct DNode* next;
}DNode, *DLinklist;

/*
����������� 
*/
//����һ������ͷ���ĵ�����
extern Linklist create_Linklist(ElemType *buf, size_t length);
//β�巨����һ��������
extern Linklist create_Linklist_from_tail(ElemType *buf, size_t length);
//ͷ�巨����һ��������
extern Linklist create_linklist_from_head(ElemType *buf, size_t length);
/*
 ����һ�������ĵ�����
 offset: �������һ���ڵ�Ӧ��ָ��ǰ��ĵڼ����ڵ� 
*/
extern Linklist create_cycle_linklist(ElemType *buf, size_t length, int offset);
/*
����һ��ѭ��������
*/
Linklist create_loop_list(ElemType *buf, size_t length);
//����һ��������
extern void destroy_linklist(Linklist L);
//�ڵ������в���ĳ��Ԫ��,���ҷ���ָ��ýڵ��ָ��
extern LNode* locate_x_in_linklist(Linklist L, ElemType x);
//�����������ÿ���ڵ��ֵ
extern void traverse_linklist(Linklist L);
//����ѭ�����������ÿ���ڵ��ֵ
void traverse_cycle_list(Linklist L);
//������ĩβ����һ���ڵ�
extern bool insert_node_linklist(Linklist L, ElemType x);
//ɾ����������ĳ��ָ����ֵ
extern bool delete_node_linklist(Linklist L, ElemType x);
//��ȡ����ĳ���(������ͷ���)
extern int get_length_linklist(Linklist L);

/*
***********************************˫����ƪ************************************
*/
//����һ����ͷ����ѭ��˫����
DLinklist create_loop_dlist(ElemType *buf, size_t length);
//��ӡ˫����
void traverse_dlinklist(DLinklist head);
//�ж�˫�����Ƿ�Ϊ��
int is_empty_dlinklist(DLinklist head);
//����˫����ĳ���
int get_length_dlinklist(DLinklist head);