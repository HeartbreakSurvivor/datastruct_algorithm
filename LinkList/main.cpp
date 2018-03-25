// LinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linklist.h"
#include "linearlist_algorithm.h"
#include <iostream>

using namespace std;

LNode *head = nullptr;//头结点
LNode *head1 = nullptr;//头结点
LNode *chead = nullptr;//循环单链表头结点
LNode *chead1 = nullptr;//循环单链表头结点
LNode *cycle_head = nullptr;//带环的单链表头结点
LNode *testhead = nullptr;//头结点

DNode *dhead = nullptr;

//结点数据
ElemType buf[9] = { 1,2,3,4,5,6,7,8,9};
ElemType buf1[3] = { 332,26,12 };

int main()
{
    head = create_Linklist_from_tail(buf, sizeof(buf) / sizeof(ElemType));
    head1 = create_Linklist_from_tail(buf1,sizeof(buf1)/sizeof(ElemType));
    chead = create_loop_list(buf, sizeof(buf) / sizeof(ElemType));
    chead1 = create_loop_list(buf1, sizeof(buf1) / sizeof(ElemType));
    cycle_head = create_cycle_linklist(buf, sizeof(buf) / sizeof(ElemType), 5);

    traverse_linklist(head);
    traverse_linklist(head1);

    traverse_cycle_list(chead);
    traverse_cycle_list(chead1);
    /*******************单链表测试过的算法*****************/
    //delete_x_forward(head, 2);
    //delete_x_tail(head, 2);
    //del_min_linklist(head);
    //reverse_list_1(head);
    //reverse_list_2(head);
    //sort_linklist(head);
    //search_list_common();
    //min_delete_list(head);
    //head1 = split_list(head);
    //del_duplicate(head);
    //testhead = merge_list(head, head1);
    //testhead = get_common_list(head, head1);
    //testhead = get_union(head,head1);
    //bool bsubsequence = is_subsequence(head, head1);
    //testhead =  link_cyclelist(chead, chead1);
    //Del_min_all(chead1);
    //traverse_cycle_list(testhead);
    //find_backwards_k(head,3);
    //del_same_absoulte(head, 10);
    //LNode *middle =  find_middle(head);
    //int ret = is_loop_list(cycle_head);
    //head = divide_list(head,5);
    //bool ret = is_palindrome(head);
    //head = inverse_k_list(head, 3);

    
    traverse_linklist(head);
    //traverse_linklist(testhead);
    //traverse_linklist(head1);



    /***************循环双链表相关算法测试*****************/
    //dhead =  create_loop_dlist(buf, sizeof(buf) / sizeof(ElemType));
    //traverse_dlinklist(dhead);
    //bool issymmetry = is_symmetry(dhead);




    ////在不带头结点的链表中删除某个元素
    //head = create_Linklist(buf,sizeof(buf)/sizeof(ElemType));

    //recursive_print(head);

    //insert_node_linklist(head, 2);
    //insert_node_linklist(head, 12);
    //traverse_linklist(head);
    //delete_x_in_linklist(head, 2);
    //traverse_linklist(head);

    //s = locate_x_in_linklist(head, 1123);
    //cout << "node's value: " << s->data << endl;
    //delete_node_linklist(head,3);
    //traverse_linklist(head);
    //delete_node_linklist(head, 12);
    //traverse_linklist(head);



    /*

    void delete_x_forward(Linklist L, ElemType x);
    void delete_x_tail(Linklist L, ElemType x);

    */


    destroy_linklist(head);

    while (true)
    {

    }
    return 0;
}

