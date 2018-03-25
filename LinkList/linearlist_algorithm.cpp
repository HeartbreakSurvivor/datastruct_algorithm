#include "stdafx.h"
#include "linearlist_algorithm.h"
#include <stack>

/*
1.���һ���ݹ��㷨��ɾ������ͷ���ĵ�����L������ֵΪx�Ľ��
*/
void delete_x_in_linklist(Linklist &L, ElemType x)
{
    LNode *p, **head = &L;//����ͷ���ָ��,֮ǰ�Ĵ��������ֱ��ʹ�� *head=L,ֻ�ǵ����İ�ָ�븴�ƣ�
    //����ֻ���޸���ָ��p����Lû�ж�
    if (*head == nullptr) return;
    if ((*head)->data == x) {
        p = *head;
        *head = (*head)->next;//��ָ��ǰ����ָ��ָ����һ����㣬��˲������
        free(p);
        delete_x_in_linklist(*head, x);
    }
    else {
        delete_x_in_linklist((*head)->next, x);
    }
}
//��������ҡ�һ��С��д��
//void delete_x_in_linklist(Linklist &L, ElemType x)
//{
//    LNode *p;//����ͷ���ָ��
//    if (L == nullptr) return;
//    if (L->data == x) {
//        p = L;
//        L = L->next;//��ָ��ǰ����ָ��ָ����һ����㣬��˲������
//        free(p);
//        delete_x_in_linklist(L, x);
//    }
//    else {
//        delete_x_in_linklist(L->next, x);
//    }
//}

/*
2.���һ���㷨�ڴ�ͷ���ĵ�����L�У�ɾ������ֵΪx�Ľ�㣬�����ͷ����ڴ档
*/
//��ͷ��β�ҵ�Ҫɾ����Ԫ�أ�ɾ����������Ҫʹ��2��ָ�룬pre���ڱ��浱ǰ��ɾ������ǰһ�����
void delete_x_forward(Linklist L, ElemType x)
{
    LNode *p = L->next, *pre = L, *q;
    while (p!=nullptr)
    {
        if (p->data == x) {
            q = p;
            p = p->next;//���������ʣ����pre��ʵû��ҪҪ
            pre->next = p;
            free(q);
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}
//β�巨ɾ��ָ��Ԫ�أ�����ָ����Ԫ�ز��뵽����ͷ��β����β�巨���Ա�֤�����˳�򲻱�
void delete_x_tail(Linklist L, ElemType x)
{
    LNode *p = L->next, *r = L, *q;
    while (p!=nullptr)
    {
        if (p->data != x) {
            r->next = p;
            r = p;
            p = p->next;
        }
        else {
            q = p;
            p = p->next; 
            free(q);//�ݴ桢���¹���ָ�롢ɾ��
        }
    }
    r->next = nullptr;//��β����Ҫ����
}

/*
3.���һ���㷨��β��ͷ��������ֵ
*/
void recursive_print(Linklist L)
{
    if (L->next != nullptr)
        recursive_print(L->next);
    std::cout << L->data << " ";
}

/*
4.���һ���㷨�ڴ�ͷ���ĵ�������ɾ��һ����Сֵ��㣬������С���Ψһ
*/
Linklist del_min_linklist(Linklist L)
{
    LNode *pre = L, *p = L->next;
    LNode *minpre = pre, *minp = p;
    while (p!=nullptr)
    {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}

/*
5.���һ���㷨��������͵���ת��Ҫ��ռ临�Ӷ�ΪO(1)
*/
//ͷ�巨����
Linklist reverse_list_1(Linklist L)
{
    LNode *p, *r;
    p = L->next;
    L->next = nullptr;//�Ͽ�ͷ�������ӣ���������
    while (p!=nullptr)
    {
        r = p->next;//ժ����һ����㣬��������һ������ָ��
        p->next = L->next;//����ͷ�巨���뵽�µ�ͷ������
        L->next = p;
        p = r;//ʹ���ݴ��ָ��r���ù���ָ��p
    }
    return L;
}
//����ָ������
Linklist reverse_list_2(Linklist L)
{
    LNode *pre, *p = L->next, *r = p->next;
    //������p��r�ֱ�ָ���һ�����͵ڶ������
    p->next = nullptr;//�ȶ�������һ�����
    while (r!=nullptr)
    {
        pre = p;
        p = r;
        r = r->next;//r��������
        p->next = pre;//��תָ�룬ʹ�������������ı����ӷ�ʽ
    }
    L->next = p;//��ͷ���ָ����ת������һ�����
    return L;
}

/*
6.��һ����ͷ���ĵ�����L,����㷨ʹ��Ԫ�����������
*/
void sort_linklist(Linklist L)
{
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = nullptr;//����һ��ֻ��ͷ���͵�һ����������
    p = r;
    while (p!=nullptr)
    {
        r = p->next;
        pre = L;//ÿ�θ���pre��ʹ��ָ���½��������ͷ���Ա�˳��Ƚϲ���.
        while (pre->next!=nullptr && pre->next->data<p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;//�ҵ����ʵ�λ�ã�Ȼ��p����
        pre->next = p;
        p = r;//���ղ��ݴ��p->next���滻p
    }
}

/*
7.������������������㷨�ҳ���������Ĺ������
*/
Linklist search_list_common(Linklist L1, Linklist L2)
{
    LNode *longlist, *shortlist;
    int len1 = get_length_linklist(L1);
    int len2 = get_length_linklist(L2);
    int dist = 0;
    if (len1 > len2) {
        longlist = L1->next;
        shortlist = L2->next;
    }
    else {
        longlist = L2->next;
        shortlist = L1->next;
    }
    dist = abs(len1 - len2);
    while (dist--)
    {
        longlist = longlist->next;
    }
    while (longlist)
    {
        if (longlist == shortlist)//���ָ����ͬ����ָ����ͬһ��λ�ã��ʹ����й��������
            return shortlist;
        else
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
    return nullptr;//û�й������
}
/*
8.��һ����ͷ���ĵ���������㷨���յ�����˳�������Ԫ�أ���ɾ�����н�㡣
*/
void min_delete_list(Linklist L)
{
    while (L->next!=nullptr)
    {
        LNode *pre = L;
        LNode *p = pre->next;
        while (p->next!=nullptr)
        {
            if (p->next->data < pre->next->data) {//���p����һ����p��dataҪС
                pre = p;//���浱ǰ��С�Ľ���λ��
            }
            p = p->next;
        }
        std::cout << pre->next->data << " ";//�����С��Ԫ��
        LNode* u = pre->next;
        pre->next = u->next;//ɾ���Ǹ���Сֵ�Ľ��
        free(u);
    }
    free(L);//ɾ��ͷ���
}

/*
9.����㷨��һ����ͷ���ĵ�����ֽ��������ͷ���ĵ�����A��B��ʹ��A��ֻ����ԭ�������
Ϊ������Ԫ�أ�B����ֻ����ԭ�������Ϊż����Ԫ�أ���Ԫ��֮������˳���ܸı䡣
*/
Linklist split_list(Linklist A)
{
    LNode *B = (LNode*)malloc(sizeof(LNode)); B->next = nullptr; //��������B��ͷ���
    int cnt = 0;//����ֵ
    LNode *ra = A, *rb = B;//������������ָ��ָ������A��B��β
    LNode *p = A->next;
    A->next = nullptr;//��AΪ�ձ�
    while (p)
    {
        //�Ƚ������Ĳ��뵽A
        ra->next = p;
        ra = p;
        p = p->next;
        if (!p)
            break;
        //�ٽ�ż����Ԫ�ز��뵽B
        rb->next = p;
        rb = p;
        p = p->next;
    }
    ra->next = nullptr;
    rb->next = nullptr;//β�巨����β����Ҫ����
    return B;//�����´���������B
}

/*
10.��һ����������ĵ������У�����㷨��ȥ����ͬ��Ԫ�أ�ʹ�ñ���û���ظ���Ԫ�ء�
*/
void del_duplicate(Linklist L)
{
    LNode *p = L->next, *q;//����ɾ��Ԫ�ص�ʱ��һ�㶼��Ҫ��������ָ��
    if (p == nullptr) return;
    while (p->next!=nullptr)
    {
        q = p->next;//��ָ����һ��������p��p����һ�����бȽϺ�ɾ��
        if (p->data != q->data) {
            p = p->next;
        }
        else
        {
            p->next = q->next;//ֱ������q��ָ��q->next��Ȼ��ֱ��ɾ��q
            free(q);
        }
    }
}

/*
11.��������Ԫ�ذ�ֵ�������еĵ�������д�㷨����ϲ���һ����ֵ�ݼ��ĵ�����
*/
Linklist merge_list(Linklist La, Linklist Lb)
{
    if (La == nullptr && Lb) return Lb;
    if (Lb == nullptr && La) return La;
    LNode *r, *pa = La->next, *pb = Lb->next;
    La->next = nullptr;//�Ƚ�����A��ͷ����������
    while (pa&&pb)
    {
        if (pa->data <= pb->data) {
            r = pa->next;//����pa�ĺ���ȣ�Ӧ��paҪ�����뵽La��ȥ��
            pa->next = La->next;//����pa��La��
            La->next = pa;
            pa = r;
        }
        else {
            r = pb->next;//����pb�ĺ���ȣ�Ӧ��pbҪ�����뵽La��ȥ��
            pb->next = La->next;//����pb��La��
            La->next = pb;
            pb = r;
        }
    }
    if (pa)
        pb = pa;//ͳһʹ��pb������������β
    while (pb)
    {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
    return La;
}
/*
12.��A��B��������ͷ���ĵ�������ĵ���������㷨��A��B�Ĺ���Ԫ������������µ�����C,Ҫ�����ƻ�A��B�Ľ�㡣
*/
Linklist get_common_list(Linklist A, Linklist B)
{
    LNode *pa = A->next, *pb = B->next, *rc;
    LNode *C = (LNode*)malloc(sizeof(LNode));
    C->next = nullptr;//�½�����ͷC
    rc = C;//β�巨������C��βָ��
    while (pa&&pb)
    {
        if (pa->data == pb->data) {
            LNode *s = (LNode *)malloc(sizeof(LNode));//�����µĽ���Ź���ֵ
            s->data = pa->data;
            rc->next = s;
            rc = s;//����βָ��
            pa = pa->next;//����pa��pbָ�룬ָ����һ�����
            pb = pb->next;
        }
        else if(pa->data < pb->data) {
            pa = pa->next;
        }
        else
        {
            pb = pb->next;
        }
    }
    rc->next = nullptr;
    return C;
}
/*
13.��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������У���д������A��B�Ľ������������A��,�����㶼ɾ������
*/
Linklist get_union(Linklist La, Linklist Lb)
{
    LNode *pa = La->next, *pb = Lb->next;
    La->next = nullptr;//��La��ͷ����������
    LNode *r = La, *temp;
    while (pa&&pb)
    {
        if (pa->data == pb->data)
        {
            r->next = pa;//��pa���뵽La�Ľ�β
            r = pa;
            pa = pa->next;
            temp = pb;//�ݴ�pb��Ȼ����ɾ��
            pb = pb->next;
            free(temp);
        }
        else if (pa->data < pb->data) {
            temp = pa;
            pa = pa->next;
            free(temp);
        }
        else {
            temp = pb;
            pb = pb->next;
            free(temp);
        }
    }
    //�ͷŵ�ʣ�µĽ��
    while (pa)
    {
        temp = pa;
        pa = pa->next;
        free(temp);
    }
    while (pb)
    {
        temp = pb;
        pb = pb->next;
        free(temp);
    }
    free(Lb);//ɾ����Lb����ͷ���
    r->next = nullptr;
    return La;
}
/*
14.��������������A=a1,a2,a3,a4...an, B=b1,b2,b3,..bn���ֱ��Ѿ�������A��B���������У��ж�B�Ƿ���A�������С�
*/
bool is_subsequence(Linklist La, Linklist Lb)
{
    LNode *pa = La->next, *pb = Lb->next;
    LNode *pre = pa;//�ݴ�pa��λ�ã�ƥ�䲻�ɹ���ʱ�򣬺ûص���һ��λ��
    while (pa&&pb)
    {
        if (pa->data == pb->data) {
            pa = pa->next;
            pb = pb->next;
        }
        else {
            pb = Lb->next;
            pre = pre->next;//ƥ��ʧ�ܣ�֮ǰ����ĵ���ǰ�ƣ����Ҹ�ֵ������ָ��pa
            pa = pre;
        }
    }
    //��pbΪ�գ���˵��pb�Ѿ��ߵ�����ͷ����ƥ��ɹ�
    return pb == nullptr ? true : false;
}

/*
15.���һ���㷨���жϴ�ͷ����ѭ��˫�����Ƿ��ǶԳƵġ�
*/
bool is_symmetry(DLinklist DL)
{
    DNode *p = DL->next, *q = DL->prev;//ѭ���������֧��˫�����
    while (p!=q && q->next!=p)//������Ҫ���ֽ���������������ż��������ż����ʱ��p��q��λ��һֱ�ߵ�����λ��֮���˵���Գ���
    {
        if (p->data == q->data) {
            p = p->next;
            q = q->prev;
        }
        else {
            return false;
        }
    }
    return true;
}

/*
16.������ѭ������������ͷָ��ֱ���CL1��CL2����д������h2���ӵ�h1�ĺ��棬Ҫ�����Ӻ��������Ȼ��ѭ�����������ʽ
*/
Linklist link_cyclelist(Linklist CL1, Linklist CL2)
{
    LNode *p, *q;
    p = CL1;
    while (p->next != CL1)//�ҵ�CL1��βָ��
        p = p->next;
    q = CL2;
    while (q->next != CL2)//�ҵ�CL2��βָ��
        q = q->next;
    p->next = CL2;
    q->next = CL1;
    return CL1;
}

/*
17.����һ����ͷ����ѭ������������ֵ��Ϊ�����������һ���㷨�������ҳ���Сֵ�Ľ�㲢�������Ȼ��ɾ������ֱ��������Ϊ�գ���ɾ��ͷ���
*/
void Del_min_all(Linklist CL)
{
    LNode *p, *pre, *minp, *minpre;
    std::cout << "output min value: " << std::endl;
    while (CL->next!=CL)
    {
        p = CL->next;
        pre = CL;
        minp = p;
        minpre = pre;
        while (p!=CL)
        {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p; 
            p = p->next;
        }
        std::cout << " " << minp->data;
        minpre->next = minp->next;
        free(minp);
    }
    free(CL);
}

/*
18.��ͷָ��ΪL�ķ�ѭ��˫����ÿ��������prev��nexe��data���⻹��һ��freq��ÿ����һ��Locate(L,x)����֮�󣬶�Ӧ�Ľ���freq��1�������������еĽ�㰴��freq�ݼ���˳�����У�
ͬʱ������ʹ��Ľ�����Ƶ����ͬ�Ľ��ǰ�棬�Ա�Ƶ�����ʵĽ�����ǿ�����ͷ��
*/
DLinklist Locate_list(DLinklist L, ElemType x)
{
    //DNode *p = L->next, *q;
    //while (p&&p->data != x)
    //    p = p->next;
    //if (!p) exit(0);
    //freq++;
    return NULL;
}

/*
���⣡����
19.��֪һ����ͷ���ĵ������ڲ��ı����������£�����㷨�ҵ�������k��λ���ϵ�ֵ�������data�����Ҳ���������0
*/
int find_backwards_k(Linklist L, int k)
{
    LNode *p = L->next, *q = L->next;
    int count = 0;
    while (p!=nullptr)
    {
        if (count < k)
            count++;
        else
            q = q->next;
        p = p->next;
    }
    if (count < k) return 0;
    std::cout << "value: " << q->data;
    return 1;
}

/*
20.�õ�������m�����������ṹΪ[data][link]����|data|<=n�����һ���㷨����
������data�ľ���ֵ��ͬ�Ľ�㣬��������һ�γ��ֵĽ�㣬��ɾ��������ͬ�Ľ�㡣
*/
void del_same_absoulte(Linklist L, int n)
{
    LNode *p=L, *r;
    int *buf, m;
    buf = (int*)malloc(sizeof(int)*(n+1));//������ʱ�������ڱ�ǵ�ǰ�����е�������
    memset(buf,0,sizeof(int)*(n+1));
    while (p->next != nullptr)
    {
        int m = abs(p->next->data);
        if (*(buf + m) == 0) {
            *(buf + m) = 1;
            p = p->next;
        }
        else {
            r = p->next;//����p�ĺ�̽��
            p->next = r->next;
            free(r);//Ȼ��ɾ����
        }
    }
}

/*
21.����һ����ͷ���ĵ������ҵ����е��м��㡣
*/
LNode* find_middle(Linklist L)
{
    LNode *fast = L->next;
    LNode *slow = fast;//����һ��һ������ָ��
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;//��ָ��ÿ��������
        slow = slow->next;//��ָ��ÿ����һ��
    }
    return slow;//��ָ�뼴���м�ָ��
}

/*
22.�ж�һ�������Ƿ��л�������л��Ļ��ͷ��ؽ��뻷�ĵ�һ������ֵ���޻��Ļ�����-1��
*/
int is_loop_list(Linklist L)
{
    if (!L->next)//������
        return -1;
    LNode * slow = L->next;
    //LNode * fast = slow->next;//ע��whileѭ�����ж�������slow������fast��������ʼ������Ҫ��slow��fast����
    LNode * fast = slow;//ע��whileѭ�����ж�������slow������fast��������ʼ������Ҫ��slow��fast����
    while (fast && fast->next)
    {
        slow= slow->next;        //��ָ����һ��
        fast= fast->next->next;  //��ָ��������
        if (slow == fast)//�����л�����ʼ���ҽ��뻷�ĵ�һ������ֵ
        {
            fast = L->next;//
            while (fast!=slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast->data;
        }
    }
    return -1;
}

/*
23.��һ����ͷ��������������Ҫ��һ���ض�����ֵ���������зֻ�����С�ڻ���������ֵ�Ľ���ƶ�����ǰ�棬���ڸ�ֵ��
����Ƶ����棬������Ҫ��֤��������ڲ���ϵ���䡣
���ӣ� {1,4,2,5} ��ֵ��3
�ֻ�������{1,2,4,5}
*/
Linklist divide_list(Linklist L, ElemType threshold)
{
    if (L->next == nullptr) return nullptr;
    //������������ͷ���ֱ𱣴�ϴ�ͽ�С�Ľ��
    LNode *minlist = nullptr, *maxlist = nullptr;
    LNode *minhead = nullptr, *maxhead = nullptr;
    LNode *p = L->next, *q;
    L->next = nullptr;//��ԭ�е�ͷ����������
    while (p)
    {
        q = p->next;//�Ƚ�p����һ����㱣������
        p->next = nullptr;//Ȼ���������������
        if (p->data <= threshold) {
            if (minlist == nullptr) {//���뵽minlist��ȥ
                minlist = p;
                minhead = p;
            }
            else {
                minlist->next = p;
                minlist = p;//����minlistβָ��
            }
        }
        else {
            if (maxlist == nullptr) {
                maxlist = p;
                maxhead = p;
            }
            else {
                maxlist->next = p;
                maxlist = p;//����maxlistβָ��
            }
        }
        p = q;//p�����Ƚ���һ��
    }
    if (minlist != nullptr)
        minlist->next = maxhead;
    //��min��max�������ӵ�Lͷ�����ȥ
    L->next = (minhead != nullptr )? minhead : maxhead;
    return L;
}

/*
24.��һ�������������һ���㷨��ʹ��ÿK���ڵ�֮�����������󲻹�K���ڵ�һ�飬�򲻵�����󼸸��ڵ㡣����
����1->2->3->4->5->6->7->8->null��K=3������ӡ�������Ϊ��3->2->1->6->5->4->7->8->null����ΪK==3������ÿ
�����ڵ�֮�����򣬵����е�7��8����������Ϊֻ�������ڵ㲻��һ�顣����һ���������ͷָ��head,ͬʱ����Kֵ����
�������������ͷָ�롣
*/
LNode* inverse_k_list(Linklist L, int k)
{
    if (!L->next || !L || k < 2) return L;
    LNode *p = L->next;
    L->next = nullptr;//�Ƚ�ͷ����������
    LNode *r = L;//�����½����������βָ��
    LNode *phead = nullptr;//��¼ÿ�ν�ȡk��Ԫ�ع����е�ͷ���
    int count = 0;//������¼�Ѿ�ѡ��Ľ��
    while (1)
    {
        phead = p;//�ȱ���k��Ԫ�صĵ�һ������λ��
        while (p && count<k)//pһֱ������k�����,Ҳ˳����Ե����ҵ���k�����Ľ���λ��
        {
            p = p->next;
            count++;
        }
        if (p == nullptr && count < k)//
            break;
        count = 0;
        //���뵽�µ�������ȥ
        while (phead!=p)
        {
            LNode *tmp = phead->next;
            phead->next = r->next;
            r->next = phead;
            phead = tmp;//pheadָ����һ�����
        }
        //�ҵ��²�������ı�βָ��
        while (r->next)
        {
            r = r->next;
        }
    }
    r->next = phead;
    return L;
}

/*
25.��дһ����������������Ƿ�Ϊ���ġ���������ṹ���£�1->2->3->2->1Ϊ���Ľṹ��1->2->3->1���ǻ��Ľṹ��
�����Ľṹ�����ҶԳƵġ�
*/
bool is_palindrome(Linklist L)
{
    if (!L->next) return false;
    LNode *p = L->next;
    std::stack<ElemType> stack;//����һ��ջ���ڱ�������
    while (p)
    {
        stack.push(p->data);
        p = p->next;
    }
    p = L->next;//��ͷ��ʼ�ٺ�ջ�еıȽ�
    while (!stack.empty() && p)
    {
        if (p->data == stack.top()) {
            stack.pop();
            p = p->next;
        }
        else
            return false;
    }
    return true;
}
