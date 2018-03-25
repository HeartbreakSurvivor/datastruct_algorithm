#pragma once
#include "stdafx.h"

/*
线性表的链式实现
author: halo.zhang
date: 2018/3/17
*/

#define MAXSIZE  100
typedef int ElemType;

//单链表节点结构
typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode;
typedef struct LNode* Linklist;

//双链表节点结构
typedef struct DNode {
    ElemType data;
    struct DNode* prev;
    struct DNode* next;
}DNode, *DLinklist;

/*
链表基本操作 
*/
//建立一个不带头结点的单链表
extern Linklist create_Linklist(ElemType *buf, size_t length);
//尾插法建立一个单链表
extern Linklist create_Linklist_from_tail(ElemType *buf, size_t length);
//头插法建立一个单链表
extern Linklist create_linklist_from_head(ElemType *buf, size_t length);
/*
 创建一个带环的单链表
 offset: 代表最后一个节点应该指向前面的第几个节点 
*/
extern Linklist create_cycle_linklist(ElemType *buf, size_t length, int offset);
/*
创建一个循环单链表
*/
Linklist create_loop_list(ElemType *buf, size_t length);
//销毁一个单链表
extern void destroy_linklist(Linklist L);
//在单链表中查找某个元素,并且返回指向该节点的指针
extern LNode* locate_x_in_linklist(Linklist L, ElemType x);
//遍历链表，输出每个节点的值
extern void traverse_linklist(Linklist L);
//遍历循环单链表，输出每个节点的值
void traverse_cycle_list(Linklist L);
//在链表末尾插入一个节点
extern bool insert_node_linklist(Linklist L, ElemType x);
//删除单链表中某个指定的值
extern bool delete_node_linklist(Linklist L, ElemType x);
//获取链表的长度(不包含头结点)
extern int get_length_linklist(Linklist L);

/*
***********************************双链表篇************************************
*/
//创建一个带头结点的循环双链表
DLinklist create_loop_dlist(ElemType *buf, size_t length);
//打印双链表
void traverse_dlinklist(DLinklist head);
//判断双链表是否为空
int is_empty_dlinklist(DLinklist head);
//计算双链表的长度
int get_length_dlinklist(DLinklist head);