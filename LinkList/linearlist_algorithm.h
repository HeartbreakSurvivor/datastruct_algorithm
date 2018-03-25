#pragma once
#include "linklist.h"

#define abs(a) ((a)>0)?(a):-(a)

//����������ص��㷨
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
18.��ͷָ��ΪL�ķ�ѭ��˫����ÿ��������prev��nexe��data���⻹��һ��freq��ÿ����һ��Locate(L,x)����֮�󣬶�Ӧ�Ľ���freq��1�������������еĽ�㰴��freq�ݼ���˳�����У�
ͬʱ������ʹ��Ľ�����Ƶ����ͬ�Ľ��ǰ�棬�Ա�Ƶ�����ʵĽ�����ǿ�����ͷ��
*/
DLinklist Locate_list(DLinklist L, ElemType x);
int find_backwards_k(Linklist L, int k);
void del_same_absoulte(Linklist L, int n);
LNode* find_middle(Linklist L);
int is_loop_list(Linklist L);
Linklist divide_list(Linklist L, ElemType threshold);
LNode* inverse_k_list(Linklist L, int k);
bool is_palindrome(Linklist L);
