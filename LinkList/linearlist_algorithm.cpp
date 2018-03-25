#include "stdafx.h"
#include "linearlist_algorithm.h"
#include <stack>

/*
1.设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
*/
void delete_x_in_linklist(Linklist &L, ElemType x)
{
    LNode *p, **head = &L;//保存头结点指针,之前的错误就在于直接使用 *head=L,只是单纯的把指针复制，
    //那样只是修改了指针p，而L没有动
    if (*head == nullptr) return;
    if ((*head)->data == x) {
        p = *head;
        *head = (*head)->next;//把指向当前结点的指针指向下一个结点，因此不会断链
        free(p);
        delete_x_in_linklist(*head, x);
    }
    else {
        delete_x_in_linklist((*head)->next, x);
    }
}
//这里坑死我。一不小心写错
//void delete_x_in_linklist(Linklist &L, ElemType x)
//{
//    LNode *p;//保存头结点指针
//    if (L == nullptr) return;
//    if (L->data == x) {
//        p = L;
//        L = L->next;//把指向当前结点的指针指向下一个结点，因此不会断链
//        free(p);
//        delete_x_in_linklist(L, x);
//    }
//    else {
//        delete_x_in_linklist(L->next, x);
//    }
//}

/*
2.设计一个算法在带头结点的单链表L中，删除所有值为x的结点，并且释放其内存。
*/
//从头至尾找到要删除的元素，删除掉它，需要使用2个指针，pre用于保存当前被删除结点的前一个结点
void delete_x_forward(Linklist L, ElemType x)
{
    LNode *p = L->next, *pre = L, *q;
    while (p!=nullptr)
    {
        if (p->data == x) {
            q = p;
            p = p->next;//这里有疑问，这个pre其实没必要要
            pre->next = p;
            free(q);
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}
//尾插法删除指定元素，不是指定的元素插入到链表头的尾部，尾插法可以保证插入后顺序不变
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
            free(q);//暂存、更新工作指针、删除
        }
    }
    r->next = nullptr;//收尾工作要做好
}

/*
3.设计一个算法从尾到头输出链表的值
*/
void recursive_print(Linklist L)
{
    if (L->next != nullptr)
        recursive_print(L->next);
    std::cout << L->data << " ";
}

/*
4.设计一个算法在带头结点的单链表中删除一个最小值结点，假设最小结点唯一
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
5.设计一个算法将单链表就地逆转，要求空间复杂度为O(1)
*/
//头插法逆置
Linklist reverse_list_1(Linklist L)
{
    LNode *p, *r;
    p = L->next;
    L->next = nullptr;//断开头结点的链接，独立出来
    while (p!=nullptr)
    {
        r = p->next;//摘掉第一个结点，保存其下一个结点的指针
        p->next = L->next;//采用头插法插入到新的头结点后面
        L->next = p;
        p = r;//使用暂存的指针r重置工作指针p
    }
    return L;
}
//三个指针逆置
Linklist reverse_list_2(Linklist L)
{
    LNode *pre, *p = L->next, *r = p->next;
    //初试让p和r分别指向第一个结点和第二个结点
    p->next = nullptr;//先独立出第一个结点
    while (r!=nullptr)
    {
        pre = p;
        p = r;
        r = r->next;//r继续迭代
        p->next = pre;//逆转指针，使得其中两个结点改变链接方式
    }
    L->next = p;//让头结点指向逆转后的最后一个结点
    return L;
}

/*
6.有一个带头结点的单链表L,设计算法使其元素有序递增。
*/
void sort_linklist(Linklist L)
{
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = nullptr;//构造一个只含头结点和第一个结点的链表
    p = r;
    while (p!=nullptr)
    {
        r = p->next;
        pre = L;//每次更新pre，使其指向新建的有序表头，以便顺序比较查找.
        while (pre->next!=nullptr && pre->next->data<p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;//找到合适的位置，然后将p插入
        pre->next = p;
        p = r;//将刚才暂存的p->next来替换p
    }
}

/*
7.给出两个单链表，设计算法找出两个链表的公共结点
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
        if (longlist == shortlist)//如果指针相同，即指向了同一个位置，就代表有公共结点了
            return shortlist;
        else
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
    return nullptr;//没有公共结点
}
/*
8.有一个带头结点的单链表，设计算法按照递增的顺序输出其元素，并删除所有结点。
*/
void min_delete_list(Linklist L)
{
    while (L->next!=nullptr)
    {
        LNode *pre = L;
        LNode *p = pre->next;
        while (p->next!=nullptr)
        {
            if (p->next->data < pre->next->data) {//如果p的下一个比p的data要小
                pre = p;//保存当前最小的结点的位置
            }
            p = p->next;
        }
        std::cout << pre->next->data << " ";//输出最小的元素
        LNode* u = pre->next;
        pre->next = u->next;//删除那个最小值的结点
        free(u);
    }
    free(L);//删除头结点
}

/*
9.设计算法将一个带头结点的单链表分解成两个带头结点的单链表A和B，使得A中只包含原表中序号
为奇数的元素，B表中只包含原表中序号为偶数的元素，且元素之间的相对顺序不能改变。
*/
Linklist split_list(Linklist A)
{
    LNode *B = (LNode*)malloc(sizeof(LNode)); B->next = nullptr; //申请链表B的头结点
    int cnt = 0;//计数值
    LNode *ra = A, *rb = B;//申请两个工作指针指向链表A和B表尾
    LNode *p = A->next;
    A->next = nullptr;//置A为空表
    while (p)
    {
        //先将奇数的插入到A
        ra->next = p;
        ra = p;
        p = p->next;
        if (!p)
            break;
        //再将偶数的元素插入到B
        rb->next = p;
        rb = p;
        p = p->next;
    }
    ra->next = nullptr;
    rb->next = nullptr;//尾插法的收尾工作要做好
    return B;//返回新创建的链表B
}

/*
10.在一个递增有序的单链表中，设计算法来去掉相同的元素，使得表中没有重复的元素。
*/
void del_duplicate(Linklist L)
{
    LNode *p = L->next, *q;//链表删除元素的时候，一般都需要定义两个指针
    if (p == nullptr) return;
    while (p->next!=nullptr)
    {
        q = p->next;//先指向下一个，用于p和p的下一个进行比较和删除
        if (p->data != q->data) {
            p = p->next;
        }
        else
        {
            p->next = q->next;//直接跳过q，指向q->next，然后直接删除q
            free(q);
        }
    }
}

/*
11.若有两个元素按值递增排列的单链表，编写算法将其合并成一个按值递减的单链表
*/
Linklist merge_list(Linklist La, Linklist Lb)
{
    if (La == nullptr && Lb) return Lb;
    if (Lb == nullptr && La) return La;
    LNode *r, *pa = La->next, *pb = Lb->next;
    La->next = nullptr;//先将链表A的头结点独立出来
    while (pa&&pb)
    {
        if (pa->data <= pb->data) {
            r = pa->next;//保存pa的后继先，应该pa要被插入到La中去了
            pa->next = La->next;//插入pa到La中
            La->next = pa;
            pa = r;
        }
        else {
            r = pb->next;//保存pb的后继先，应该pb要被插入到La中去了
            pb->next = La->next;//插入pb到La中
            La->next = pb;
            pb = r;
        }
    }
    if (pa)
        pb = pa;//统一使用pb来进行最后的收尾
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
12.若A和B是两个带头结点的递增有序的单链表，设计算法将A和B的公共元素挑出来组成新的链表C,要求不能破坏A和B的结点。
*/
Linklist get_common_list(Linklist A, Linklist B)
{
    LNode *pa = A->next, *pb = B->next, *rc;
    LNode *C = (LNode*)malloc(sizeof(LNode));
    C->next = nullptr;//新建链表头C
    rc = C;//尾插法，保存C的尾指针
    while (pa&&pb)
    {
        if (pa->data == pb->data) {
            LNode *s = (LNode *)malloc(sizeof(LNode));//申请新的结点存放公共值
            s->data = pa->data;
            rc->next = s;
            rc = s;//更新尾指针
            pa = pa->next;//更新pa和pb指针，指向下一个结点
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
13.已知两个链表A和B分别表示两个集合，其元素递增排列，编写函数求A和B的交集，并存放在A中,其余结点都删除掉。
*/
Linklist get_union(Linklist La, Linklist Lb)
{
    LNode *pa = La->next, *pb = Lb->next;
    La->next = nullptr;//将La的头结点独立出来
    LNode *r = La, *temp;
    while (pa&&pb)
    {
        if (pa->data == pb->data)
        {
            r->next = pa;//将pa插入到La的结尾
            r = pa;
            pa = pa->next;
            temp = pb;//暂存pb，然后将其删除
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
    //释放掉剩下的结点
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
    free(Lb);//删除掉Lb链表头结点
    r->next = nullptr;
    return La;
}
/*
14.设两个整数序列A=a1,a2,a3,a4...an, B=b1,b2,b3,..bn，分别已经存入了A和B两个链表中，判断B是否是A的子序列。
*/
bool is_subsequence(Linklist La, Linklist Lb)
{
    LNode *pa = La->next, *pb = Lb->next;
    LNode *pre = pa;//暂存pa的位置，匹配不成功的时候，好回到上一个位置
    while (pa&&pb)
    {
        if (pa->data == pb->data) {
            pa = pa->next;
            pb = pb->next;
        }
        else {
            pb = Lb->next;
            pre = pre->next;//匹配失败，之前保存的点往前移，并且赋值给工作指针pa
            pa = pre;
        }
    }
    //若pb为空，这说明pb已经走到链表尽头，即匹配成功
    return pb == nullptr ? true : false;
}

/*
15.设计一个算法来判断带头结点的循环双链表是否是对称的。
*/
bool is_symmetry(DLinklist DL)
{
    DNode *p = DL->next, *q = DL->prev;//循环链表可以支持双向查找
    while (p!=q && q->next!=p)//这里需要区分结点个数是奇数还是偶数，若是偶数的时候，p和q的位置一直走到互换位置之后就说明对称了
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
16.有两个循环单链表，链表头指针分别是CL1，CL2。编写函数将h2链接到h1的后面，要求链接后的链表仍然是循环单链表的形式
*/
Linklist link_cyclelist(Linklist CL1, Linklist CL2)
{
    LNode *p, *q;
    p = CL1;
    while (p->next != CL1)//找到CL1的尾指针
        p = p->next;
    q = CL2;
    while (q->next != CL2)//找到CL2的尾指针
        q = q->next;
    p->next = CL2;
    q->next = CL1;
    return CL1;
}

/*
17.设有一个带头结点的循环单链表，其结点值均为正整数，设计一个算法，反复找出最小值的结点并且输出，然后删除它，直到单链表为空，再删除头结点
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
18.设头指针为L的非循环双链表，每个结点除了prev，nexe，data以外还有一个freq，每进行一次Locate(L,x)运算之后，对应的结点的freq加1，并且让链表中的结点按照freq递减的顺序排列，
同时最近访问过的结点放在频度相同的结点前面，以便频繁访问的结点总是靠近表头。
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
真题！！！
19.已知一个带头结点的单链表，在不改变链表的情况下，设计算法找到倒数第k个位置上的值，输出其data，若找不到，返回0
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
20.用单链表保存m个整数，结点结构为[data][link]，且|data|<=n，设计一个算法对于
链表中data的绝对值相同的结点，仅保留第一次出现的结点，而删除其余相同的结点。
*/
void del_same_absoulte(Linklist L, int n)
{
    LNode *p=L, *r;
    int *buf, m;
    buf = (int*)malloc(sizeof(int)*(n+1));//申请临时数组用于标记当前链表中的所有数
    memset(buf,0,sizeof(int)*(n+1));
    while (p->next != nullptr)
    {
        int m = abs(p->next->data);
        if (*(buf + m) == 0) {
            *(buf + m) = 1;
            p = p->next;
        }
        else {
            r = p->next;//保存p的后继结点
            p->next = r->next;
            free(r);//然后删除它
        }
    }
}

/*
21.对于一个带头结点的单链表，找到其中的中间结点。
*/
LNode* find_middle(Linklist L)
{
    LNode *fast = L->next;
    LNode *slow = fast;//定义一快一慢两个指针
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;//快指针每次走两步
        slow = slow->next;//慢指针每次走一步
    }
    return slow;//慢指针即是中间指针
}

/*
22.判断一个链表是否有环，如果有环的话就返回进入环的第一个结点的值，无环的话返回-1。
*/
int is_loop_list(Linklist L)
{
    if (!L->next)//空链表
        return -1;
    LNode * slow = L->next;
    //LNode * fast = slow->next;//注意while循环的判断条件是slow不等于fast，所以起始条件需要让slow和fast不等
    LNode * fast = slow;//注意while循环的判断条件是slow不等于fast，所以起始条件需要让slow和fast不等
    while (fast && fast->next)
    {
        slow= slow->next;        //慢指针走一步
        fast= fast->next->next;  //快指针走两步
        if (slow == fast)//链表有环，开始查找进入环的第一个结点的值
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
23.有一个带头结点的链表，我们需要用一个特定的阈值来对它进行分化，即小于或等于这个阈值的结点移动到最前面，大于该值的
结点移到后面，并且需要保证两类结点的内部关系不变。
例子： {1,4,2,5} 阈值：3
分化后结果：{1,2,4,5}
*/
Linklist divide_list(Linklist L, ElemType threshold)
{
    if (L->next == nullptr) return nullptr;
    //申请两个链表头，分别保存较大和较小的结点
    LNode *minlist = nullptr, *maxlist = nullptr;
    LNode *minhead = nullptr, *maxhead = nullptr;
    LNode *p = L->next, *q;
    L->next = nullptr;//将原有的头结点独立出来
    while (p)
    {
        q = p->next;//先将p的下一个结点保存起来
        p->next = nullptr;//然后将这个结点独立出来
        if (p->data <= threshold) {
            if (minlist == nullptr) {//插入到minlist中去
                minlist = p;
                minhead = p;
            }
            else {
                minlist->next = p;
                minlist = p;//更新minlist尾指针
            }
        }
        else {
            if (maxlist == nullptr) {
                maxlist = p;
                maxhead = p;
            }
            else {
                maxlist->next = p;
                maxlist = p;//更新maxlist尾指针
            }
        }
        p = q;//p继续比较下一个
    }
    if (minlist != nullptr)
        minlist->next = maxhead;
    //将min和max链表链接到L头结点上去
    L->next = (minhead != nullptr )? minhead : maxhead;
    return L;
}

/*
24.有一个单链表，请设计一个算法，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。例如
链表1->2->3->4->5->6->7->8->null，K=3这个例子。调整后为，3->2->1->6->5->4->7->8->null。因为K==3，所以每
三个节点之间逆序，但其中的7，8不调整，因为只有两个节点不够一组。给定一个单链表的头指针head,同时给定K值，返
回逆序后的链表的头指针。
*/
LNode* inverse_k_list(Linklist L, int k)
{
    if (!L->next || !L || k < 2) return L;
    LNode *p = L->next;
    L->next = nullptr;//先将头结点独立出来
    LNode *r = L;//保存新建立的链表的尾指针
    LNode *phead = nullptr;//记录每次截取k个元素过程中的头结点
    int count = 0;//用来记录已经选择的结点
    while (1)
    {
        phead = p;//先保存k个元素的第一个结点的位置
        while (p && count<k)//p一直往后找k个结点,也顺便可以当成找到的k个结点的结束位置
        {
            p = p->next;
            count++;
        }
        if (p == nullptr && count < k)//
            break;
        count = 0;
        //插入到新的链表中去
        while (phead!=p)
        {
            LNode *tmp = phead->next;
            phead->next = r->next;
            r->next = phead;
            phead = tmp;//phead指向下一个结点
        }
        //找到新插入链表的表尾指针
        while (r->next)
        {
            r = r->next;
        }
    }
    r->next = phead;
    return L;
}

/*
25.编写一个函数，检查链表是否为回文。回文链表结构如下：1->2->3->2->1为回文结构，1->2->3->1不是回文结构。
即回文结构是左右对称的。
*/
bool is_palindrome(Linklist L)
{
    if (!L->next) return false;
    LNode *p = L->next;
    std::stack<ElemType> stack;//创建一个栈用于保存数据
    while (p)
    {
        stack.push(p->data);
        p = p->next;
    }
    p = L->next;//从头开始再和栈中的比较
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
