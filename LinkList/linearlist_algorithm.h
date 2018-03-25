#pragma once
#include "linklist.h"

#define abs(a) ((a)>0)?(a):-(a)

//各种链表相关的算法
void delete_x_in_linklist(Linklist &L, ElemType x);
void delete_x_forward(Linklist L, ElemType x);
void delete_x_tail(Linklist L, ElemType x);
void recursive_print(Linklist L);
Linklist del_min_linklist(Linklist L);
Linklist reverse_list_1(Linklist L); 
Linklist reverse_list_2(Linklist L);
void sort_linklist(Linklist L);
Linklist search_list_common(Linklist L1, Linklist L2);
void min_delete_list(Linklist L);
Linklist split_list(Linklist A);
void del_duplicate(Linklist L);
Linklist merge_list(Linklist La, Linklist Lb);
Linklist get_common_list(Linklist A, Linklist B);
Linklist get_union(Linklist La, Linklist Lb);
bool is_subsequence(Linklist La, Linklist Lb);
bool is_symmetry(DLinklist L);
Linklist link_cyclelist(Linklist CL1, Linklist CL2);
void Del_min_all(Linklist CL);

/*
18.设头指针为L的非循环双链表，每个结点除了prev，nexe，data以外还有一个freq，每进行一次Locate(L,x)运算之后，对应的结点的freq加1，并且让链表中的结点按照freq递减的顺序排列，
同时最近访问过的结点放在频度相同的结点前面，以便频繁访问的结点总是靠近表头。
*/
DLinklist Locate_list(DLinklist L, ElemType x);
int find_backwards_k(Linklist L, int k);
void del_same_absoulte(Linklist L, int n);
LNode* find_middle(Linklist L);
int is_loop_list(Linklist L);
Linklist divide_list(Linklist L, ElemType threshold);
LNode* inverse_k_list(Linklist L, int k);
bool is_palindrome(Linklist L);
