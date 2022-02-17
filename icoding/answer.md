# icoding复习 1
## 链表 倒数查找

1. 已知一个带有表头结点的单链表, 假设链表只给出了头指针L。在不改变链表的前提下，请设计一个尽可能高效的算法，
查找链表中倒数第k个位置上的结点（k为正整数）。
函数原型为：int lnk_search(LinkList L, int k, ElemType* p_ele)
若查找成功，函数通过指针参数 p_ele 返回该结点 data 域的值，此时函数返回 1；否则，函数返回 0。相关定义如下：
```cpp
struct _lnklist{undefined
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

#include
#include
#include "list.h" // 请不要删除，否则检查不通过

int lnk_search(LinkList L, int k, ElemType* p_ele){undefined
    int i, length;
    Node *p;
    
    
    for(i = 0, p = L; p; i++)
        p = p->next;
        
    length = i;
    if(length == 0 || length < k)    return 0;
    
    for(i = 0, p = L; i <= length - k; i++)//!!取等,注意边界 
        p = p->next;
        
    *p_ele = p->data;
    
     return 1;
}
```

## 2. 链表 合并

设线性表A=(a1, a2,…,am)，B=(b1, b2,…,bn)，试写一个按下列规则合并A、B为线性表C的算法，使得：
C= (a1, b1,…,am, bm, bm+1, …,bn) 当m≤n时；
或者
C= (a1, b1,…,an, bn, an+1, …,am) 当m>n时。
线性表A、B、C均以单链表作为存储结构，且C表利用A表和B表中的结点空间构成。
注意：单链表的长度值m和n均未显式存储。

函数的原型如下：
```cpp
void lnk_merge(LinkList A, LinkList B, LinkList C)
即将A和B合并为C，其中 C 已经被初始化为空单链表
相关定义如下：
//注意:线性表可以是链表 
struct _lnklist{undefined
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;
#include
#include
#include "list.h" // 请不要删除，否则检查不通过

void lnk_merge(LinkList A, LinkList B, LinkList C){undefined
    Node *p, *q, *c;
    bool flag = true;//小写!python大写首字母 不用包含bool头文件 
    
    c = C;//c尾指针 
    p = A->next;
    q = B->next;
    
    while(p && q){undefined
        if(flag){undefined
            c->next = p;
            c = p;
            p = p->next;
            flag = false;
        } 
        else{undefined
            c->next = q;
            c = q;
            q = q->next;
            flag = true;
        }
    }
    
    if(p)
        c->next = p;
    else
        c->next = q;
        
    free(A);
    free(B);//!!
}

```
## 3. 顺序表 删除指定范围
设计一个高效的算法，从顺序表L中删除所有值介于x和y之间(包括x和y)的所有元素（假设y>=x），
要求时间复杂度为O(n)，空间复杂度为O(1)。
函数原型如下：
```cpp
void del_x2y(SeqList *L, ElemType x, ElemType y);
相关定义如下：

struct _seqlist{undefined
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;


#include "list.h" // 请不要删除，否则检查不通过
#include
#include

void del_x2y(SeqList *L, ElemType x, ElemType y){undefined
    int i, j = 0;
     
    for(i = 0; i < L->last; i++){undefined
        if(L->elem[i] < x || L->elem[i] > y)
            L->elem[j++] = L->elem[i];    

    L->last = j - 1;//不用设置delta增量记录删除的数量 
}
```

## 4. 链表 删除范围内结点

已知线性表中的元素（整数）以值递增有序排列，并以单链表作存储结构。
试写一高效算法，删除表中所有大于mink且小于maxk的元素（若表中存在这样的元素），
分析你的算法的时间复杂度。

链表结点定义如下：
```cpp
struct _lnklist{undefined
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;//结构标记 
typedef struct _lnklist *LinkList;//!! 
函数原型如下：
void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)

#include "list.h" // 请不要删除，否则检查不通过
#include
#include

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk){undefined
    Node *p, *temp;
    
    for(p = L->next; p; p = p->next){undefined
        if(p->data < maxk && p->data > mink){undefined
            temp = p;
            p = p->next;
            free(p);
        }
        if(p->data > maxk)
            break;
    }
}
//解法2为指针跟踪技术 
void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
{undefined
    Node *p, *pre;
    pre = L;
    p = L->next;
    for (; p;) {undefined
        if (p->data > mink && p->data < maxk) {undefined
            pre->next = p->next;
            free(p);
            p = pre->next;

        } else {undefined
            pre = p;
            p = p->next;
        }
    }
}
```

## 5. 顺序表 删除重复

编写算法，在一非递减的顺序表L中，删除所有值相等的多余元素。
要求时间复杂度为O(n)，空间复杂度为O(1)。
函数原型如下：
```cpp
void del_dupnum(SeqList *L)

相关定义如下：
struct _seqlist{undefined
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

#include "list.h" // 请不要删除，否则检查不通过
#include
#include


//这里是线性表中的顺序表,不是链表! 
void del_dupnum(SeqList *L){undefined
    int i, j = 0, delta = 0;
    //一次遍历达到时间复杂度 
    for(i = 0; i < L->last; i++){undefined
        if(L->elem[i] != L->elem[i+1])
            L->elem[j++] = L->elem[i];
        else
            delta++;
    }
    
    L->last -= delta;
}
//解法2 不用设置delta增量 
void del_dupnum(SeqList* L)
{undefined
    int i, j = 1;
    for (i = 1; i <= L->last; i++) {undefined
        if (L->elem[i] != L->elem[i - 1]) {undefined
            L->elem[j++] = L->elem[i];
        }
    }
    L->last = j - 1;
}
```

## 6. 顺序表 数据调整

已知顺序表L中的数据元素类型为int。设计算法将其调整为左右两部分，
左边的元素（即排在前面的）均为奇数，右边所有元素（即排在后面的）均为偶数，
并要求算法的时间复杂度为O(n),空间复杂度为O（1）。

函数原型如下：
```cpp
void odd_even(SeqList *L);

相关定义如下：
struct _seqlist{undefined
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

#include "list.h" // 请不要删除，否则检查不通过
#include
#include

#define N 2 
//题目描述不清晰
//偶数内部排序顺序未知 
void odd_even(SeqList *L){undefined
    int i, j;
    int x;
    
    for(i = 0, j = 0; i < L->last && i + 1 != L->last - j; i++){undefined
    //for的另一种写法for (i = 0, j = 0; i <= L->last - j; i++) { 
        if(!(L->elem[i] % N)){//偶数 
            x = L->elem[L->last-j];
            L->elem[L->last-j] = L->elem[i];
            L->elem[i] = x;
            i--;
            j++;
        }
    }
}
```

# icoding复习 2 

## 1. 栈 后缀表达式计算
(1)如果是操作数，直接入栈
(2)如果是操作符op，连续出栈两次，得到操作数x 和 y,计算 x op y，并将结果入栈。
```cpp
#define Stack_Size 50
typedef struct{undefined
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType *x);
void init_stack(Stack *S);
其中，栈初始化的实现为：
void init_stack(Stack *S){undefined
    S->top = -1;
}
需要完成的函数定义为：int compute_reverse_polish_notation(char *str);
函数接收一个字符指针，该指针指向一个字符串形式的后缀表达式，函数返回该表达式的计算结果。

#include
#include
#include "list.h" // 请不要删除，否则检查不通过

//字符指针!!!!!!!!!!!!
//易错 
int compute_reverse_polish_notation(char* str)//光秃秃的*str 怎么用要知道 
{
    int i = 0;
    Stack S;
    //没必要*S 
    init_stack(&S);
    ElemType _push, num1, num2;
    
    //str[i]等价于*(str+i) 
    while (str[i] != '\0') {undefined
    //    先判空 再判空格 再判数字和符号 数字判断是几位数 
        if (str[i] != ' ') {undefined
            
            if (str[i] >= '0' && str[i] <= '9') { //!!
                _push = 0;
                
                while (str[i] != ' ') {undefined
                    _push *= 10;
                    _push += (str[i] - '0'); 
                    //一个数字一个数字的压入 , 判断位数 
                    i++;
                }
                push(&S, _push);
                //每次_push会变, push函数里面top会++
                //切记 
            } else {undefined
                //格外小心弹出来的顺序
                //先弹出来的符号对它作用 
                pop(&S, &num2);
                pop(&S, &num1);
            switch (str[i]) {undefined
                case '+': {undefined
                    num1 += num2;//注意两个操作数的顺序 
                    break;//!!!!!
                }
                case '-': {undefined
                    num1 -= num2;
                    break;
                }
                case '*': {undefined
                    num1 *= num2;
                    break;
                }
                case '/': {undefined
                    if(num2)//判除数 
                        num1 /= num2;
                    break;
                }
                case '%': {undefined
                    if(num2) 
                        num1 %= num2;
                    break;
                }
            }
            push(&S, num1);
            }
        }
        i++;
    }
    pop(&S, &num1);
    //最后的返回值也要弹出来 
    return num1;
}
```

## 2. 队列 循环链表表示队列
假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针），请完成下列任务：
```cpp
1: 队列初始化，成功返回真，否则返回假： bool init_queue(LinkQueue *LQ);
2: 入队列，成功返回真，否则返回假： bool enter_queue(LinkQueue *LQ, ElemType x);
3: 出队列，成功返回真，且*x为出队的值，否则返回假 bool leave_queue(LinkQueue *LQ, ElemType *x);
typedef struct _QueueNode {undefined
    ElemType data;          /*数据域*/
    struct _QueueNode *next;      /*指针域*/
}LinkQueueNode, *LinkQueue;
#include
#include
#include "list.h" // 请不要删除，否则检查不通过

bool init_queue(LinkQueue *LQ){undefined
    
    //注意这里是给*LQ分配空间,不是LQ; 类比Node *p对于p的空间分配 
    if(!(*LQ = (LinkQueue)malloc(sizeof(LinkQueueNode)))) return false;
    
    (*LQ)->next = *LQ;
    return true;
}
//!!!
bool enter_queue(LinkQueue *LQ, ElemType x){undefined
    LinkQueueNode *p;
    
    if(!(p = (LinkQueueNode *)malloc(sizeof(LinkQueueNode)))) return false;
    
    p->data = x;
    //LQ为队尾指针
    //这一步顺序不要颠倒,循环队列连接到头结点 
    p->next = (*LQ)->next;
    //尾插入 
    (*LQ)->next = p;
    *LQ = p; 
    
    return true; 
}
  
//!!!
bool leave_queue(LinkQueue* LQ, ElemType* x)
{undefined
    LinkQueueNode *first, *p;
    //first为头结点 
    first = (*LQ)->next;
    if (first == *LQ)
        return false;
    //注意的是头节点为空, 并且是自然形成的
    
    p = first->next;
    *x = p->data;
    if (p != *LQ) //这种情况只有一个尾结点可以释放
        first->next = p->next;
    else {//!!!
        *LQ = (*LQ)->next;//LQ变为头结点,尾指针指向头结点 
        (*LQ)->next = *LQ; //自己构成空循环
    }
    free(p);
    return true;
}
```






 









# icoding复习 3
## 1. 不调用库函数，自己实现字符串的比较操作：该操作当比较的两个字符是都是字母，且两个字符互为大小写
（如a和A、e和E）时认为两个字符相同，否则不同，其比较结果按这两个字符的原值确定。函数的返回值规定如下：
返回值 < 0：第一个不匹配的字符在 ptr1 中的值低于 ptr2 中的值

返回值 == 0：两个字符串的内容相等

返回值 > 0：第一个不匹配的字符在 ptr1 中的值大于在 ptr2 中的值
```cpp
int str_compare(const char* ptr1, const char* ptr2);
#include
#include
#include "dsstring.h" //请不要删除，否则检查不通过
//又是字符串操作!!!! 
int str_compare(const char* ptr1, const char* ptr2){
    int i;
    // a == 97 A == 65 
    for(i = 0; ptr1[i] && ptr2[i]; i++){
        if(ptr1[i] != ptr2[i]){//字符相等就继续,不等判断大小写关系 
            if(ptr1[i] + 'a' - 'A' == ptr2[i] || ptr2[i]+'a'-'A' == ptr1[i])
                continue;//这一步可以分开写,没有判断是否ptr1[i]和ptr2[i]为字母,但是icoding监测可以通过
                //其实当两个字符恰好相差32就不行了 
            else
                return ptr1[i]-ptr2[i];
        }
    }
    //后面的代码可以略掉 
    if(ptr1[i])
        return (int)ptr1[i];
    else
        return (int)ptr2[i];
     
}
//解法2 icoding检测数据不全 ! 100
int str_compare(const char* ptr1, const char* ptr2)
{
    // a == 97 A == 65 
    int i;
    for (i = 0; ptr1[i] != '\0' || ptr2[i] != '\0';) {
        if (ptr1[i] == ptr2[i] )  //判断字符是否相等 
            i++;
        else if(ptr1[i] <= 'z' && ptr1[i] >= 'a'&& ptr1[i] - 32 == ptr2[i])
        //判断是否为大小写不同的相同字母, (如果同为相同的大写或者相同的小写之前检测了), 
            i++;
        else if(ptr2[i] <= 'z' && ptr2[i] >= 'a'&& ptr2[i] - 32 == ptr1[i])
            i++;
        else
            return ptr1[i] - ptr2[i];//可以自动转换为int
        //注意点第二三个if是必要的, 不能直接判断ptr1[1] -ptr2[i] == +-32 , 也有可能有ASC码正好相差32的非字母字符 
    }
    return 0;
}

//90+问题代码
int str_compare(const char* ptr1, const char* ptr2)
{
    char a, b;
    int i;
    for (i = 0; ptr1[i] != '\0' && ptr2[i] != '\0'; i++) {
        a = ptr1[i];
        b = ptr2[i];
        if (a <= 'Z' && a >= 'A' && b <= 'z' && b >= 'a')
            a = a - 'A' + 'a';//有问题, 这部分的意思是a为大写, b同时也为字母并且为小写 , 那么
            //a转化为小写并且与b比较, 但是如果值不等的话会改变返回值大小 
        if (b <= 'Z' && b >= 'A' && a <= 'z' && a >= 'a')
            b = b - 'A' + 'a';
        if (a == b)
            continue;
        else
            return a - b;
    }
    return ptr1[i] - ptr2[i];
} 
```

## 2.串替换

in，原始字符串，保持不变; out, 存放替换结果的字符串; outlen，out空间的大小
oldstr，要替换的旧字符串; newstr，替换成的新字符串
函数返回成功替换的次数，即有多少个子串被成功替换
在替换过程中，任何情况下所得字符串（及结束符）不应该超过 outlen，
如果某次替换所得字符串的长度超过 outlen，则不进行这次替换操作，整个替换操作结束。如：
原始串为 "aaabbbccc"，outlen 为14, oldstr 为 "c"，newstr 为 "333" 时，
两次替换后得 "aaabbb333333c"，此时字符串占用空间为14字节。
如果再进行替换，则会超出 out 所占用的空间，所以停止替换操作。
此时函数应该返回 2, out指向的串为 "aaabbb333333c"
再如：原始串为 "aaabbbccc"，outlen 为10, oldstr 为 "bb"，
newstr 为 "123456"，进行替换后所得的串应该为 "aaa123456" 
（长度为9）与结束符一共占 10 个字节，此时函数应该返回 1
```cpp
#include "dsstring.h"
#include
#include

int get_len(const char *str){
    int i;
    for(i = 0; str[i]; i++)
        ;
    return i;
}
//另一种写法
int get_len(const char* s)
{
    int i = 0;
    while (*(s + i)) {
        i++;
    }
    return i;
    //返回值是实际长度, 不包括空字符
} 

//理解:旧串换新串,每一个新串要求能够全部放下并且不忽略尾部空字符, 操作的是字符指针...! 
int str_replace(const char* in, char* out, int outlen, const char* oldstr, const char* newstr)
{
    int i, j = 0, ostr, nstr = 0;//i 指示in, j指示out. 
    int n = 0;
    
    if(outlen <= 0) return false; 
    
    //out需要分配空间??? 不需要..... 
    //下面思路整理:
    //in的字符不与oldstr第一个字符匹配,直接复制, 进入下一轮循环 
    //判断剩余空间是否足够, 一种溢出是新串字符加out内已有字符长度溢出,一种是in剩余字符加out已有字符溢出,直接剩余全部复制
    //空间足够,判断字符是否匹配,判断匹配成功,那么ostr指向oldstr最后一个'\0' 
    //执行换串操作 ,n++ 
    //最后如果串换完并且in中字符全部复制完但是j没有达到outlen-2,放空字符 
    for(i = 0; i < get_len(in) && j < outlen - 1;){
    //对于j,总长度为outlen, 最后一个下标为outlen-1,最后一个位置放'\0' ,所以j最大取outlen-2 
    
        if(in[i] != oldstr[0]){
            out[j++] = in[i++];
            continue; 
        }
            
        if(j + get_len(newstr) >= outlen - 1 || get_len(in) - i + j >= outlen - 1)
        {//先看剩余空间可以换串吗 ,如果不能就剩余全部复制 
            for(; j < outlen;)
                out[j++] = in[i++];l
            return n;
        }
        
        for(ostr = 0; otsr < get_len(oldstr); ostr++)
            if(oldstr[ostr] != in[i+ostr])
                break;
                
        if(ostr == get_len(oldstr) - 1){//if(!(oldstr[ostr]))等价 
            for(nstr = 0; j < get_len(newstr); j++)
                out[j] = newstr[nstr++];
            n++;
            i += get_len(oldstr);
        }
        else
            out[j++] = in[i++]; 
    }
    
    for(; j < outlen - 1; j++)
        out[j] = '\0';
    out[j] = '\0';

    return n;
}
```

## 3. 块链串 
#include
#include
#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符

typedef struct _block {
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct {
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;

//字符串初始化函数：
void blstr_init(BLString *T) {
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}
这些定义已包含在头文件 dsstring.h 中，请实现块链串的子串查找操作：

bool blstr_substr(BLString src, int pos, int len, BLString *sub);
src为要查找的字符串
pos为子串开始的下标
len为子串的长度
sub在函数调用运行前指向一个已经初始化好的空串，在函数返回时，sub指向串src从第pos个字符起长度为len的子串
函数查找成功返回true，参数不正确返回 false
#include
#include
#include "dsstring.h" // 请不要删除，否则检查不通过
```cpp

//满分代码

!!!!操作字符串长度 
int len(const char* s)
{
    int q = 0;
    while (*s != '\0') {//可以简化while(*s++) q++;
        q++;
        s++;//!!!
    }
    return q;
}
//易错点分析:
//1. 对于字符指针的操作, len函数书写
//2. 对于块的个数边界条件判定
//3. 对于块指针操作,分类讨论
//4. 尾指针置空,空白地方用'#'填充 

int StrAssign(BLString* S, const char* cstr)
{//将cstr复制到块链串S中
 
    int i, j, k, len;
    Block *p, *q;
    len = strlen(cstr); //len为链串的长度
    if (len == 0)
        return 0;
    S->len = len;
    
    j = len / BLOCK_SIZE; //j为链串的结点数 ,也就是块个数` 
    if (len % BLOCK_SIZE)
        j++;
        
    for (i = 0; i < j; i++) {
        p = (Block*)malloc(sizeof(Block));
        if (!p)
            return 0;//可以简化
            
        //k指示每一个块内部字符ch[]下标
        for (k = 0; k < BLOCK_SIZE && *cstr; k++) //将字符串ctrs中的字符赋值给链串的数据域
            *(p->ch + k) = *cstr++;//!!!!!!
            
        if (i == 0) //如果是第一个结点
            S->head = q = p; //头指针指向第一个结点
        else {//q为跟踪指针 
            q->next = p;
            q = p;
        }
        if (!*cstr) //如果是最后一个链结点
        {
            S->tail = q; //将尾指针指向最后一个结点
            q->next = NULL; //将尾指针的指针域置为空
            for (; k < BLOCK_SIZE; k++) //最后一个结点用'#'填充
                *(q->ch + k) = BLS_BLANK;
        }
    }
    return 1;
}
bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    char* t;
    if (pos < 0 || pos >= src.len || len < 1)
        return false;
    int n = pos / BLOCK_SIZE, h = pos % BLOCK_SIZE;
    Block* temp = src.head;
    
    for (int i = 0; i < n; i++)
        temp = temp->next;//temp直接指向pos位置那个块 
    
    char str[100];
    int i = 0;
    while (i < len) {
        if (h >= BLOCK_SIZE) {
            temp = temp->next;
            h = 0;
        } 
        else {
            if (!temp || temp->ch[h] == BLS_BLANK)
                break;
            str[i++] = temp->ch[h++];
        }
    }
    str[i] = '\0';
    StrAssign(sub, str);
    return true;
}
```

# icoding复习 4
## 1. 矩阵加法
实现三元组表示的两个稀疏矩阵的加法。
```cpp
#define MAXSIZE 100 //假设非零元个数的最大值为100
typedef struct {
    int i,j;                //非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;                //非零元的值
}Triple;
typedef struct {
    Triple data[MAXSIZE];    // 非零元三元组表
    int    m, n, len;        // 矩阵的行数、列数和非零元个数
}TSMatrix;
```
pM, pN, pQ 分别指向三个矩阵，当 pM 和 pN 两个矩阵不可加时，函数返回 false，
否则函数返回 true，且 pQ 指向两个矩阵的和。

```cpp
#include "tsmatrix.h"
#include
#include

bool add_matrix(const TSMatrix* pM, const TSMatrix* pN, TSMatrix* pQ)
{
    if(pM->m != pN->m || pM->n != pN->n) return false;
    
    pQ->m = pM->m;
    pQ->n = pM->n;
    //记得检查结构体赋值!! 
    int i, j, k = 0;
    for(i = 0, j = 0; i < pM->len && j < pN->len;){
        if(pM->data[i].i == pN->data[j].i){
            if(pM->data[i].j == pN->data[j].j){
                if(pM->data[i].e + pN->data[j].e){
                    pQ->data[k].e = pM->data[i].e + pN->data[j].e;
                    pQ->data[k].i = pM->data[i].i;
                    pQ->data[k].j = pM->data[i].j;
                    k++; i++; j++;
                }
                else{//这个else可以不要,前面的if里面的i++和j++可以提出来 
                    i++; j++;
                }
            }
            else if(pM->data[i].j < pN->data[j].j){
                pQ->data[k].e = pM->data[i].e;
                pQ->data[k].i = pM->data[i].i;
                pQ->data[k].j = pM->data[i].j;
                k++; i++;
            }
            else{
                pQ->data[k].e = pN->data[j].e;
                pQ->data[k].i = pN->data[j].i;
                pQ->data[k].j = pN->data[j].j;
                k++; j++;
            }
        }
        else if(pM->data[i].i < pN->data[j].i){
            pQ->data[k].e = pM->data[i].e;
            pQ->data[k].i = pM->data[i].i;
            pQ->data[k].j = pM->data[i].j;
            k++; i++;
        }
        else{
            pQ->data[k].e = pN->data[j].e;
            pQ->data[k].i = pN->data[j].i;
            pQ->data[k].j = pN->data[j].j;
            k++; j++;            
        }    
    } 
    while(i < pM->len){
        pQ->data[k].e = pM->data[i].e;
        pQ->data[k].i = pM->data[i].i;
        pQ->data[k].j = pM->data[i].j;
        k++; i++;        
    }
    while(j < pN->len){
        pQ->data[k].e = pN->data[j].e;
        pQ->data[k].i = pN->data[j].i;
        pQ->data[k].j = pN->data[j].j;
        k++; j++;        
    }
    pQ->len = k;
    return true;
}
```

## 2. 十字链表
```cpp
typedef int ElemType;
// 非零元素结点结构
typedef struct OLNode
{
    int row,col;
    ElemType value;
    struct OLNode *right,*down;
}OLNode,*OLink;
// 十字链表结构
typedef struct
{
    OLink *rowhead,*colhead;
    int rows,cols,nums;
}CrossList, *PCrossList;

1）实现十字链表的初始化操作：
int init_cross_list(PCrossList L, const ElemType *A, int m, int n);
其中 L 指向 CrossList 结构，且各成员已被初始化为0；
A 为 ElemType 类型  数组中第一个元素的地址，元素的个数为 m×n 个，按行优先存储
（即A[0] 为十字链表第1行第1列的元素；
A[1] 为第1行第2列的元素，A[n] 为第2行第1列的元素，A[n+1] 为第2行第2个元素）；

m 表示十字链表的行数，n 表示十字链表的列数。
init_cross_list 函数将 ElemType 数组中非0元素保存到十字链表中，函数返回非 0 元素的个数。

2）实现十字链表的删除操作：
int del_cross_list(PCrossList L, ElemType k);
其中 L 指向 要处理的 CrossList 结构，k 为要删除的元素；
del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。


掌握!!!!!! 
int init_cross_list(PCrossList L, const ElemType* A, int m, int n)
{
    int i, j, k = 0;
    OLNode *p, *q;

    L->cols = n;
    L->rows = m;
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //下面这个是个很奇怪的数组可以认为是指针数组 
    if (!(L->rowhead = (OLink*)malloc(m * sizeof(OLink))))//也可以return 0;....icoding不会检测..... 
        ;
    if (!(L->colhead = (OLink*)malloc(n * sizeof(OLink))))
        ;

    for (i = 0; i < m; i++)
        L->rowhead[i] = NULL;

    for (i = 0; i < n; i++)
        L->colhead[i] = NULL;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i * n + j] != 0) {
                k++;
                if (!(p = (OLNode*)malloc(sizeof(OLNode))))
                    ;
                p->col = j;
                p->row = i;
                p->value = A[i * n + j];
                //!!!
                if (L->rowhead[i] == NULL || L->rowhead[i]->col > j) {
                    p->right = L->rowhead[i]; //头插法
                    L->rowhead[i] = p;
                } else {
                    q = L->rowhead[i];
                    while (q->right && q->right->col < j)
                        q = q->right;
                    p->right = q->right;
                    q->right = p;
                }
                
                if (L->colhead[j] == NULL || L->colhead[j]->row > i) {
                    p->down = L->colhead[j];
                    L->colhead[j] = p;
                } else {
                    q = L->colhead[j];
                    while (q->down && q->down->row < i)
                        q = q->down;
                    p->down = q->down;
                    q->down = p;
                }
            }
        }
    }
    L->nums = k;
    return L->nums;
} //init


int del_cross_list(PCrossList L, ElemType k)
{
    int num = 0;
    int i, j;
    OLNode *p, *q, *s;
    OLNode *x, *y, *z;

    for (i = 0; i < L->rows; i++) {
        p = L->rowhead[i];
        q = p;
        while (p) {
            if (p->value == k && p == q) {//第一个结点(不设头结点) 
                L->rowhead[i] = L->rowhead[i]->right;
                free(p);
                p = L->rowhead[i];
                num++;
            } else if (p->value == k) {
                s = p;
                q->right = p->right;
                free(p);
                p = q->right;
                num++;
            } else {
                q = p;
                p = p->right;
            }
        }
    }
    //下面的for可以不要,icoding根本不得检测纵向的链.......................................................... 
    for (j = 0; j < L->cols; j++) {
        x = L->colhead[j];
        y = x;
        while (x) {
            if (x->value == k && x == y) {
                L->colhead[j] = L->colhead[j]->down;
                x = x->down;
                free(y);
            } else if (x->value == k) {
                y->down = x->down;
                z = x;
                free(z);
            } else {
                y = x;
                x = x->down;
            }
        }
    }

    L->nums -= num;
    return num;
}
```

# icoding复习 5

## 1. 先序遍历 
```cpp
已知二叉树按照二叉链表方式存储，利用栈的基本操作写出先序遍历非递归形式的算法：
void pre_order(BiTree root);
二叉树的相关定义如下：
typedef int DataType;
typedef struct Node{undefined
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;
遍历所使用栈的相关操作如下：
#define Stack_Size 50
typedef BiTNode* ElemType;
typedef struct{undefined
    ElemType elem[Stack_Size];
    //BiTNode*  elem[Stack_Size]
    int top;
}Stack;
void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false
```
在遍历过程中，pre_order函数需要调用 visit_node 函数来实现对结点的访问，该函数声明如下：
```cpp
void visit_node(BiTNode *node);
#include
#include
#include "bitree.h" //请不要删除，否则检查不通过

大概率考原题和改编!!!!!! 

void pre_order(BiTree root){undefined
    if(!root) return;
    Stack *S;
    
    BiTNode *p;
    
    init_stack(S);
    push(S, root->data);
    while(!is_empty(S)){undefined
        pop(S, &p);
        visit_node(p);
        
        if(p->left)
            push(S, p->left);
        if(p->right){undefined
            push(S, p->right);
        }
    } 
}
//解法2, 声明为Stack S; 
void pre_order(BiTree root)
{undefined
    Stack S;
    BiTNode *p, *q;

    //    S.top = -1; 初始化应该会赋值
    p = root;
    init_stack(&S);

    if (p == NULL)
        return;
    do {undefined
        if (p) {undefined
            visit_node(p);//先序遍历的核心,先访问根节点 
            push(&S, p);
            p = p->left;
        } else {undefined
            pop(&S, &p);
            p = p->right;
        }
    } while (p || !(is_empty(&S)));
}

//中序遍历
void InOrder(BiTNode *root){undefined
    Stack *S; BiTNode *p;
    init_stack(S);
    if(!root ) return;
    while(p || !is_empty(S)){undefined
        while(p){undefined
            push(S, p);
            p = p->left;
        }
        if(!is_empty(S)){undefined
            pop(S, &p);
            visit_node(p);
            p = p->right;
        }
    }
} 

//后序遍历非递归 难 
void PostOrder(BiTNode *root){undefined
    Stack *S; BiTNode *p, *r; bool flag;
    init_stack(S);
    p = root;
    do{undefined
        while(p){undefined
            push(S, p);
            p = p->left;
        }
        r = NULL;
        flag = true;
        
        while(!is_empty(S) && flag){undefined
            top(S, &p);
            if(p->right == r){undefined
                visit_node(p);
                pop(S, &p);
                r = p;
            }
            else{undefined
                p = p->right;
                flag = false;
            }
        }
    }while(!is_empty(S));
} 
```

## 2. 路径 
假设二叉树采用二叉链表方式存储， root指向根结点，node 指向二叉树中的一个结点，
编写函数 path，计算root到 node 之间的路径，（该路径包括root结点和 node 结点）。path 函数声明如下：
bool path(BiTNode* root, BiTNode* node, Stack* s);
其中，root指向二叉树的根结点，node指向二叉树中的另一结点，s 为已经初始化好的栈，
该栈用来保存函数所计算的路径，如正确找出路径，则函数返回 true，此时root在栈底，node在栈顶；
```cpp
#include "bitree.h" //请不要删除，否则检查不通过
#include
#include

bool path(BiTNode* root, BiTNode* node, Stack* s){undefined
    BiTNode *p, *q;
    
    if(!root || !node)    return false;
    p = root;
    if(p == node){undefined
        push(s, p);
        return true;
    }
    
    while(p || !is_empty(s)){undefined
        while(p){//先压入再判断 
            push(s, p);
            if(p == node)
                return true;
            
            p = p->left;
        }
        top(s, &p);
        if(p->right == q || p->right == NULL){undefined
            q = p;
            top(s, &p);
            p = NULL;
        }
        else
            p = p->right;
    }
    return true;
}
```

## 3. 共同祖先

假设二叉树采用二叉链表方式存储， root指向根结点，p所指结点和q所指结点为二叉树中的两个结点，
编写一个计算它们的最近的共同祖先，函数定义如下：
BiTNode * nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q);
其中 root 指向二叉树的根结点，p 和 q 分别指向二叉树中的两个结点。
提示：在完成本题时，可利用 path 函数获取p和q两个结点到根结点之间的路径，
之后再计算两条公共路径得出最近的共同祖先。path函数及栈相关定义如下：
```cpp

#include
#include
#include "bitree.h" //请不要删除，否则检查不通过

BiTNode * nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q){undefined
    if(!root || !p || !q) return NULL;
    Stack *s1, *s2;
    init_stack(s1); init_stack(s2);
    path(root, p, s1);
    path(root, q, s2);
    for(int i = 0; s1->elem[i] == s2->elem[i]; i++) 
        ;
    return s1->elem[i-1];
} 

4. 树转二叉树
使用队列，编写transfrom函数，将普通树转换成对应的二叉树。二叉树的相关定义如下：
typedef int DataType;
typedef struct Node{undefined
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;

普通树节点 的定义如下：
#define MAX_CHILDREN_NUM 5
struct _CSNode
{undefined
    DataType data;
    struct _CSNode *children[MAX_CHILDREN_NUM];
};
typedef struct _CSNode CSNode;
其中，子树的根节点的指针存放在children数组的前k个元素中，即如果children[i]的值为NULL，
而children[i-1]不为NULL，则表明该结点只有i棵子树，子树根结点分别保存在children[0]至children[i-1]中。
队列相关定义及操作如下：
struct __Queue
{undefined
    int i, j; //指向数组内元素的游标
    void **array;//这个就是提示!!!!!!!!!!!!!!!!!!!!!!!!!!! 
};
typedef struct __Queue Queue;

Queue* create_queue(); //创建队列
bool is_empty_queue(Queue *tree); //队为空返回true,不为空时返回false
void* del_queue(Queue *tree); //结点指针出队
void add_queue(Queue *tree, void *node); //结点指针入队
void free_queue(Queue *tree); //释放队列
transform函数定义如下：

BiTNode* transform(CSNode *root);
其中 root 为普通树的根结点，函数返回该树对应二叉树的根结点。


#include
#include
#include "bitree.h" //请不要删除，否则检查不通过 
 
BiTNode* transform(CSNode *root){undefined
    if(!root) return NULL;
    
    Queue *que, *bque;
    
    BiTNode *p;
    //二叉树根结点创立 
    //小心点, 记得分配空间 
    //为什么想到建立二叉树结点?
    //普通树结点和二叉树结点无法强制类型转换 
    p = (BiTNode *)malloc(sizeof(struct Node));
    p->data = root->data;
    p->left = p->right = NULL;
     
    
    que = create_queue();
    bque = create_queue();
    //建立双队目的在于建立有序二叉结点序列 
    add_queue(que, root);
    add_queue(bque, p);
    
    //注意这个while怎么处理好孩子与孙子关系的, 没用递归!!! 
    while(!is_empty_queue(que)){undefined
        BiTree bq;//创建二叉树队列头结点(根结点) 
        bq = del_queue(bque);
        CSNode *q;
        q = del_queue(que);
        //第一次执行该操作就相当于建立了二叉树的根
        
        int i = 0; 
        BiTNode *former = NULL;
        
        for(i = 0; i < MAX_CHILDREN_NUM; i++){undefined
            if(q->children[i]){//判存在 
                BiTNode *bnode = (BiTNode *)malloc(sizeof(struct Node));
                bnode->data = q->children[i]->data;
                bnode->left = bnode->right = NULL; 
        
                //放置结点位置
                if(i == 0){undefined
                    bq->left = bnode;
                }
                else{//兄弟变为孩子了可怜 
                    former->right = bnode;
                }
                former= bnode;
                 
                add_queue(bque, bnode);
                add_queue(que, q->children[i]);
            }
        }     
    }
    free(que->array);
    free(que);
    free(bque->array);
    free(bque);
    
    return p;
}
```

# icoding复习 6

## 1. 邻接表1
```cpp
试在邻接表存储结构上实现图的基本操作 insert_vertex 和 insert_arc，相关定义如下：
typedef int VertexType;
typedef enum{
    DG, UDG
}GraphType;
typedef struct ArcNode{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;
int locate_vertex(ListGraph* G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(ListGraph *G, VertexType v);
bool insert_arc(ListGraph *G, VertexType v, VertexType w);
```
当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
```cpp
//写下locate函数
int locate_vertex(ListGraph *G, VertexType v){
    int i;
    for(i = 0; i < G->vexnum; i++)
        if(G->vertex[i].data == v)
            return i;
    return -1;
} 


#include
#include
//记得加这个头文件消除黄色警告 
#include "graph.h" //请勿删除，否则检查不通过
bool insert_vertex(ListGraph *G, VertexType v){
    int  i = 0;
    //2个易错点: 指针置空,可以省略; 点运算符!!务必区分 
    i = locate_vertex(G, v);
    if(i != -1) return false;
    G->vertex[G->vexnum].data = v;
    G->vertex[G->vexnum].firstarc = NULL;
    G->vexnum++;
    return true; 
}

bool insert_arc(ListGraph *G, VertexType v, VertexType w){
    int i = locate_vertex(G, v);
    int j = locate_vertex(G, w);
    
    //点不存在 
    if(i == -1 || j == -1) return false;
    //边已经存在
    ArcNode *p = G->vertex[i].firstarc;
    for(; p; p = p->nextarc)
        if(p->adjvex == j)
            return false; 
        
    ArcNode *q;
    p = G->vertex[i].firstarc;
    if(!(q = (ArcNode *)malloc(sizeof(ArcNode)))) return false;    
    q->adjvex = j;
    if(!p){
        G->vertex[i]->firstarc = q;
        q->nextarc = NULL;
    }
    else{
        q->nextarc = p->nextarc;
        p->nextarc = q; 
    }
    G->arcnum++; 
    return true;
}

//第一次的思路
bool insert_arc(ListGraph *G, VertexType v, VertexType w){
    int i, j;
    ArcNode *p;
    
    i = locate_vertex(G, v);
    j = locate_vertex(G, w);
    
    //判结点是否存在,不存在就返回false 
    if(i == -1|| j == -1)
        return false;
        
    //判边是否存在,存在就返回false 
    //需要注意的是p->adjvex = j这个判断条件,一个是int类型,一个是不要把这个判断条件放到for里面 
    for(p = G->vertex[i].firstarc;  p; p = p->nextarc)
        if(p->adjvex == j)     return false;
    
    //!!!!!需要注意的是这里是单项插入,不考虑有向无向
    //插入到方向就是v-->w 
//    for(p = G->vertex[j].firstarc;  p; p = p->nextarc)
//    if(p->adjvex == i)  return false;

    
//    if(G->type == UDG){
//        p->nextarc = G->vertex[j].firstarc->nextarc;
//        p->adjvex = v;
//        G->vertex[j].firstarc = p; 
//    }

//!!!别忘了分配空间,这个是建立一个新的节点 
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = j;
    G->arcnum++; 
    if(!G->vertex[i].firstarc)//空的情况 
        G->vertex[i].firstarc = p;
    else{//头插 G->vertex[i].firstarc是头结点 
        p->nextarc = G->vertex[i].firstarc->nextarc;
        G->vertex[i].firstarc = p;
    }
    return true;    
} 
```

## 2. 邻接表2

试在邻接表存储结构上实现图的基本操作 del_vertex，相关定义如下：
```cpp
typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct ArcNode{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v); //删除顶点 v
```
当成功删除顶点或边时，函数返回true，否则（如顶点或边不存在、删除边时顶点v或w不存在）返回false。
```cpp
#include  
#include
#include "graph.h" //请勿删除，否则检查不通过
bool del_vertex(ListGraph* G, VertexType v){
    int i = locate_vertex(G, v), j;
    if(i == -1) return false;
    j = i;
    ArcNode *p, *q;
    
    
    for(p = G->vertex[i].firstarc; p;){
        q = p;
        p = p->nextarc;
        free(q);
        G->arcnum--;
    } 
    free(G->vertex[i].firstarc); G->arcnum--;//在最后丢表头, 注意点, 这里不能理解为没有数据的头结点 
    
    for(; i < G->vexnum; i++)
        G->vertex[i] = G->vertex[i+1];
    G->vexnum--;
    
    for(i = 0; i < G->vexnum; i++){
        for(p = G->vertex[i].firstarc, q = p; p->adjvex != j && p ;q = p, p = p->nextarc)
            ;
        if(p->adjvex == j){
            if(p == G->vertex[i].firstarc)
                G->vertex[i].firstarc = p->nextarc;//隐含q == p 
            else
                q->nextarc = p->nextarc;
            free(p);
            G->arcnum--;
        } 
    }
}

//答案如下 
//思路整理
//1. 定位该节点是否存在,若存在
//2. 删除该结点以之为弧尾的链表, 挨着删,最后删除表头, 边数减少 
//3. 结点序列前移, 结点总数减少 
//4. 遍历邻接表找以删除结点为弧头的链, 删除... 
bool del_vertex(ListGraph* G, VertexType v)
{
    int i, j = locate_vertex(G, v);
    if (j == -1) //检查是否存在该节点
        return false; 
    
    //先删除从该节点出发的边和该节点
    while (G->vertex[j].firstarc) { 
        ArcNode* p = G->vertex[j].firstarc;
        if (p->nextarc) { //先free表头结点后面的
            ArcNode* q = p->nextarc;
            p->nextarc = q->nextarc;
            free(q);
        } else {
            free(p); //free表头结点
            G->vertex[j].firstarc = NULL;
        }
        G->arcnum--; //边的数量-1
    }
    G->vexnum--; //结点的数量-1
    for (i = j; i < G->vexnum; i++) { //表头结点中，后面的向前移动
        G->vertex[i] = G->vertex[i + 1];
    }
    
    //再删除到该节点的边
    for (i = 0; i < G->vexnum; i++) {
        ArcNode *p = G->vertex[i].firstarc, *pNode = NULL;
        ArcNode* q; //存储要被删掉的结点
        while (p) {
            if (p->adjvex == j) { //P的下个结点是V
                if (!pNode) { //P是表头结点
                    q = G->vertex[i].firstarc;
                    G->vertex[i].firstarc = p->nextarc;
                }
                else {
                    pNode->nextarc = p->nextarc;
                    q = p;
                }
                p = p->nextarc;
                free(q);
                G->arcnum--;
            } else {
                pNode = p;
                p = p->nextarc;
            }
        }
    }
    return true;
}
```

## 3. 邻接矩阵

试在邻接矩阵存储结构上实现图的基本操作 matrix_insert_vertex 和matrix_insert_arc，相关定义如下：
```cpp
typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct{
    VertexType vertex[MAX_VERTEX_NUM]; //顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int vexnum, arcnum;   //图的当前顶点数和弧数
    GraphType type;     //图的种类标志
}MatrixGraph;

int matrix_locate_vertex(MatrixGraph *MG, VertexType vex); //返回顶点 v 在vertex数组中的下标，
//如果v不存在，返回-1
bool matrix_insert_vertex(MatrixGraph *G, VertexType v);
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w);
```
当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
```cpp
#include  
#include "graph.h" // 请不要删除，否则检查不通过

bool matrix_insert_vertex(MatrixGraph *G, VertexType v){
    int i = matrix_locate_vertex(G, v);
    
    if(i != -1 || G->vexnum == MAX_VERTEX_NUM - 1) return false;
    
    G->vertex[G->vexnum] = v;
    for(i = 0; i < G->vexnum; i++){
        G->arcs[G->vexnum][i] = 0;
        G->arcs[i][G->vexnum] = 0;
    }
    G->arcnum++;
    return true;
}

bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w){
    int i = matrix_locate_vertex(G, v);
    int j = matrix_locate_vertex(G, w);
    
    if(i == -1 || j == -1 || G->arcs[i][j] == 1) return false;
//如果加上判断图的类型 
//    if(G->type == UDG &&( G->arcs[i][j] == 1 || G->arcs[j][i] == 1))
//        return false;
//    else if(G->arcs[i][j] == 1)    
//        return false;
    G->arcs[i][j] = 1;
    if(G->type == UDG)
        G->arcs[j][i] = 1;
    G->arcnum++;
    return true;
}
```

# icoding复习 7

## 1. 哈希表创建
```cpp

typedef enum{
    HASH_OK,
    HASH_ERROR,
    HASH_ADDED,
    HASH_REPLACED_VALUE,
    HASH_ALREADY_ADDED,
    HASH_DELETED,
    HASH_NOT_FOUND,
} HASH_RESULT;
typedef struct __HashEntry HashEntry;
struct __HashEntry{
    union{
        char  *str_value;
        double dbl_value;
        int    int_value;
    } key;
    union{
        char  *str_value;
        double dbl_value;
        int    int_value;
        long   long_value;
        void  *ptr_value;
    } value;
    HashEntry *next;
};
struct __HashTable{
    HashEntry **bucket;        
    int size;
    HASH_RESULT last_error;
};
typedef struct __HashTable HashTable;
// 创建大小为hash_size的哈希表，创建成功后返回HashTable类型的指针，否则返回NULL。
HashTable *create_hash(int hash_size);
```

哈希表相关说明：

HASH_RESULT 类型为相关函数的返回类型

HashEntry 为哈希表所保存元素（即键值对 《key, value》）类型

HashTable 为哈希表，其中 bucket 指向大小为size的、元素类型为 HashEntry*的指针数组

哈希表采用链地址法处理冲突

请实现 create_hash 函数，创建指定大小的哈希表。
```cpp
#include
#include
#include "hash.h"

HashTable* create_hash(int size){
    HashTable *table;
    
    if(!(table = (HashTable *)malloc(sizeof(HashTable)))) return false;
    
    if(!(table->bucket = (HashTable *)malloc(size * sizeof(HashEntry *)))){
        free(table); return false;
    }
    table->size = size;
    table->last_error = HASH_OK;
    return table; 
}
```
必考!!! 

## 2. 哈希表添加
```cpp
// 向哈希表中添加元素，其中键类型为char*， 元素类型为int。
HASH_RESULT hash_add_int(HashTable * table, const char * key, int value);
哈希表相关说明：
HASH_RESULT 类型为相关函数的返回类型
HashEntry 为哈希表所保存元素（即键值对 《key, value》）类型
HashTable 为哈希表，其中 bucket 指向大小为size的、元素类型为 HashEntry*的指针数组
```

哈希表采用链地址法处理冲突
请实现 hash_add_int 函数，向哈希表中添加元素，其中键类型为char*， 元素类型为int。
在添加过程中，如果要添加的键值key已在哈希表中，且对应的值value也已存在，则函数返回 HASH_ALREADY_ADDED；
如果要添加的键值key已在哈希表中，但对应的值value不同，函数将value值更新到哈希表中，之后返回 HASH_REPLACED_VALUE
如果要添加的键值key不在哈希表中，则函数创建 HashEntry 类型，并将其加入到哈希表中，且函数返回 HASH_ADDED。
本题所用的哈希函数如下：
```cpp
long hash_string(const char *str){
    ...
}

HASH_RESULT hash_add_int(HashTable *table, const char *key, int value){
    int i = hash_string(key) % table->size;
    HashEntry *p;
    
    p = table->bucket[i];
    
    if(!p){//该关键字不存在 
        p = (HashEntry *)malloc(sizeof(HashEntry)); // 判空略
        strcpy(p->key.str_value, key);
        p->value.int_value = value; 
        table->bucket[i] = p;
        
        return HASH_ADDED;
    }
    //关键字存在,先判断关键字是否相等,再判断值;如果关键字不等那么最后还要链地址添加
    while(p){
        if(strcmp(p->key.str_value, key)){
            if(p->value.int_value == value){
                return HASH_ALREADY_ADDED;
            }
            else{
                p->value.int_value = value;
                return HASH_REPLACED_VALUE;
            }
        }
        else
            p = p->next;
    } 
    HashEntry *q = (HashEntry *)malloc(sizeof(HashEntry)); // 判空略
    q->key = (char *)malloc(sizeof(char) *strlen(key));//判空类似前面的 
    
    strcpy(q->key.str_value, key);
    q->value.int_value = value;
    p->next = q;
    q->next = NULL;
    return HASH_ADDED; 
}
```

## 3. AVL添加
平衡二叉树，是一种二叉排序树，其中每个结点的左子树和右子树的高度差至多等于1。
它是一种高度平衡的二叉排序树。现二叉平衡树结点定义如下：
```cpp
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
} node_t;
//请实现平衡二叉树的插入算法：

//向根为 root 的平衡二叉树插入新元素 val，成功后返回新平衡二叉树根结点
node_t *avl_insert(node_t *root, int val);

#include
#include
#include "avl.h"

int get_height(node_t *p){
    if(!p)
        return 0;
    else
        return p->height;
}

node_t* avl_insert(node_t *root, int val){
//首先清晰字母定义;
//val新插入结点元素值,height高度!!! 
//定义查找过程中出现的距离插入结点最近的平衡因子不为零的结点A
//定义A的孩子结点为B,需要旋转的结点
//定义插入节点为s,s的值为val
//平衡因子:左子树减去右子树深度 

    node_t *s, *A, *B, *C, *p, *fp;
    //依次:插入点, 失衡点(也可能是旋转点),旋转点,旋转点(也可能是插入点=s),动点,跟踪点
    int i, k;//平衡因子 
    
    s = (node_t *)malloc(sizeof(node_t));
    if(!s) return NULL;
    
    s->val = val;
    s->left = s->parent = s->right = NULL;
    s->height = 1;
    
    //类似于指针跟踪技术,p为动指针,A为跟踪指针 
    A = root; A->parent = NULL;
    p = root; p->parent = NULL;
    
    //找出A 
    if(!p)
        root = s;
    else{
        while(p){
            //先找出最近的A->height!=0的结点, 就是最后的失衡点
            i = get_height(p->left) - get_height(p->right); 
            if(i){
                A = p;
                A->parent = p->parent;
            }
            //fp跟踪p,因为下一步p会往下移动,p最终指向s的那一层 
            fp = p;
            if(val < p->val)
                p = p->left;
            else
                p = p->right;
            }//p最终指向NULL就退出循环     
    } 
    
    //插入, 此时fp是p的前一个结点,p指向空 
    if(val < fp->val)
        fp->left = s;
    else
        fp->right = s;
        
    //确定旋转结点B,修改A的平衡因子
    if(val < A->val)
        B = A->left;
    else
        B = A->right;

    A->height++;
    
    //修改路径B到s的高度, B在A的下一层 
    p = B; // p最终指向s, 之前指向的是s这一层,但是是空

    while(p != s){
        p->height++;
        if(val < p->val)
            p = p->left; 
        else
            p = p->right;    
    }
    //最终s的高度没有++的 , 初始值赋为1 
        
    
    //调整完高度就修改结点和指针, 首先需要判断失衡类型
    //分为LL,LR,RR,RL
    //结点A,B平衡因子在修改指针的过程中会变化,但是路径上的结点不会
    //指针修改包括s结点指针和原来双亲结点指针 
    i = get_height(A->left) - get_height(A->right);
    k = get_height(B->left) - get_height(B->right); 
    
    if(i == 2 && k == 1){//LL
        //B作为旋转结点
        //先改结点指针, 此时s插入在B的左子树下, 原来可以认为B左右子树,A右子树均为空
        A->left = B->right;
        B->right = A;
        
        //考虑原来A结点的指针,改成B后相应的指针也要改变,下面同理
        if(A->parent == NULL)
            root = B;
        else if(A->parent->left == A)
            A->parent->left = B;
        else
            A->parent->right = B;        
    }
    else if(i == -2 && k == -1){//RR
        A->right = B->left;
        B->left = A;
        
        if(A->parent == NULL)
            root = B;
        else if(A->parent->left == A)
            A->parent->left = B;
        else
            A->parent->right = B;    
    }
    else if(i == 2 && k == -1){//LR
        //此时认为C的左右子树空,B逆时针旋转,A顺时针旋转, s插入C的左子树或者右子树 
        //如果C结点也是空,也就是说B右子树空,那么直接插入C=s为B右子树,此时A右子树也是空的 
        C = B->right;
        B->right = C->left;
        A->left = C->right;
        C->left = B;
        C->right = A;
        
        if(A->parent == NULL)
            root = C;
        else if(A->parent->left == A)
            A->parent->left = C;
        else
            A->parent->right = C;
    }
    else if(i == -2 && k == 1){//RL 
        //和LR一样,画图来看就好
        C = B->left;
        A->right = C->left;
        B->left = C->right;
        C->left = A;
        C->right = B;
        
        if(A->parent == NULL)
            root = C;
        else if(A->parent->left == A)
            A->parent->left = C;
        else
            A->parent->right = C;
    }
    return root;
}
```

# icoding复习 8

## 1. 堆辅助函数

二叉堆是完全二叉树或者是近似完全二叉树。二叉堆有两种：最大堆和最小堆。

最大堆(大顶堆)：父结点的键值总是大于或等于任何一个子节点的键值，即最大的元素在顶端；
最小堆(小顶堆)：父结点的键值总是小于或等于任何一个子节点的键值，即最小的元素在顶端。
二叉堆子结点的大小与其左右位置无关。
二叉堆一般用数组来表示。例如，根节点在数组中的位置是0，第n个位置的子节点分别在2n+1和 2n+2。
因此，第0个位置的子节点在1和2，1的子节点在3和4。以此类推。这种存储方式便于寻找父节点和子节点。
在二叉堆上可以进行插入节点、删除节点、取出值最小的节点、减小节点的值等基本操作。
```cpp
“最小堆”的定义如下：
typedef struct _otherInfo
{
    int i;
    int j;
}OtherInfo;

typedef struct _minHeapNode
{
    int value;
    OtherInfo otherInfo;
}MinHeapNode, *PMinHeapNode;

typedef struct _minPQ {
    PMinHeapNode heap_array; // 指向堆元素数组
    int heap_size; // 当前堆中的元素个数
    int capacity;  //堆数组的大小
}MinHeap, *PMinHeap;
请实现最小堆的四个辅助函数：

int parent(int i); //返回堆元素数组下标为 i 的结点的父结点下标
int left(int i);  //返回堆元素数组下标为 i 的结点的左子结点下标
int right(int i);  //返回堆元素数组下标为 i 的结点的右子结点下标
void swap_node(MinHeapNode *x, MinHeapNode *y);  //交换两个堆元素的值


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
重点区别
1. PMinHeapNode heap_array
2. MinHeapNode *heap_array
3. MinHeapNode heap_array[capacity]//三者等价,前两者没分配空间

对于heap_array[i].value,记得点运算符, 因为这个不是指针了!!!!!
 ```
```cpp
#include
#include
#include "minbinheap.h" // 请不要删除，否则检查不通过

int parent(int i){
    return (i - 1) / 2; 
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
void swap_node(MinHeapNode *x, MinHeapNode *y){
    int value;
    int i, j;
    
    value = y->value;
    i = y->otherInfo.i;
    j = y->otherInfo.j;
    
    y->value = x->value;
    y->otherInfo.i = x->otherInfo.i;
    y->otherInfo.j = x->otherInfo.j;
    
    x->value = value;
    x->otherInfo.i = i;
    x->otherInfo.j = j;
    
    return;
}
```

## 2. 堆初始化
请实现最小堆的初始化函数：
```cpp
void init_min_heap(PMinHeap pq, int capacity);
其中 pq指向堆，capacity为堆元素数组的初始化大小。

void init_min_heap(PMinHeap pq, int capacity){//小根堆, 小的在上面 
//题目没有明确 
//    pq = (PMinHeap)malloc(sizeof(MinHeap));
//    if(!pq) return;
    
    if(!(pq->heap_array = (PMinHeapNode)malloc(sizeof(MinHeapNode) * capacity))){
        free(pq); return;
    }
    pq->capacity = capacity;
    pq->heap_size = 0;
    //return;
}
```

## 3. 堆化
请实现最小堆的“堆化”函数：
void min_heapify(PMinHeap pq, int i);
其中 pq指向堆，i 为堆元素在数组中的下标。该函数假设元素i对应的子树都已经是最小堆
（符合最小堆的要求），但元素i为根的子树并不是最小堆，
min_heapify将对元素i及其子树的各结点进行调整，使其为一个最小堆。
```cpp
void min_heapify(PMinHeap pq, int i){
    int j = parent(i);
    //if(pq->heap_array[i].value > pq->heap_array[j].value) return;
    for(; j >= 0 && pq->heap_array[i].value > pq->heap_array[j].value; i = j, j = parent(i))
        swap_node(&pq->heap_array[i], &(pq->heap_array[j]));
}

void min_heapify(PMinHeap pq, int i){//一行 
    for(int j = parent(i); j >= 0 && pq->heap_array[i].value > pq->heap_array[j].value; i = j, j = parent(i))swap_node(&(pq->heap_array[i]), &(pq->heap_array[j]));}
 ```   
    
## 4. 堆元素插入
请实现最小堆的元素插入函数：
```cpp
bool heap_insert_value(PMinHeap pq, int value);
其中 pq指向堆，value 为要插入的堆元素。

bool heap_insert_value(PMinHeap pq, int value){//小根堆,子树关键字大于等于根的关键字 
    //if(pq->heap_size == pq->capacity - 1) return false;
    
    int i, j;
    i = pq->heap_size;
    j = parent(i);
    pq->heap_array[i].value = value;
    while(i){
        if(value < pq->heap_array[j].value){
            swap_node(&(pq->heap_array[i]), &(pq->heap_array[j]));
            i = j;
            j = parent(i);
        }
        else{
            pq->heap_size++;
            return true;
        }
    }    
}
```

## 5. 数组合并
假设有 n 个长度为 k 的已排好序（升序）的数组，请设计数据结构和算法，
将这 n 个数组合并到一个数组，且各元素按升序排列。即实现函数：

 void merge_arrays(const int* arr, int n, int k, int* output);
其中 arr 为按行优先保存的 n 个长度都为 k 的数组，output 为合并后的按升序排列的数组，大小为 n×k。

时间要求(评分规则)，当 n > k 时：
满分：时间复杂度不超过 O(n×k×log(n))
75分：时间复杂度不超过 O(n×k×log(n)×k)
59分：其它，如：时间复杂度为 O(n2×k2) 时。
```cpp
#include
#include
//建立大根堆(大的在上面)  
void build_bigroot(int *a, int i, int size){
//参数说明:a传入的数组,i待排序元素开始位置,size数组元素个数(长度)
    int j, s;
    //j是i的孩子指针,s暂存排序的元素
    
    //不设监视哨,所以从'0'(i)开始排序,孩子为2*i+1 
    j = 2 * i + 1;
    s = a[i];
    
    while(j < size){//可以设置bool变量测试是否筛选完毕,减小时间复杂度 
    //不可以取等哈 ,0开始的
    
        //存在右子树并且右子树更大,那么筛选右子树 
        if(j + 1 < size && a[j+1] > a[j])
            j++; 
        
        if(s >= a[j])
            break;
        else{//如果大的记录在下,那么上浮 
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        } 
    }
    //最后把筛选完成后的数据放在合适位置
    a[i] = s; 
}

void merge_arrays(const int *arr, int n, int k, int* output){
    //说明一下arr为const int类型,不能改动,所以只好浪费时空复制出来在变动
    int i, size, x;
    size = n * k;
    int a[size];
    //大根堆是大的在上,没有什么其他要求.堆排后大的放大到最后,形成升序排列的小根堆 
    
    for(i= 0; i < size; i++)
        a[i] = arr[i];
    //建立大根堆 
    for(i = size / 2 -1; i >= 0; i--)
        build_bigroot(a, i , size);
    //堆排 
    for(i = size - 1; i >=1; i--){
        x = a[0];
        a[0] = a[i];
        a[i] = x;
        build_bigroot(a, 0, i);
    } 
    for(i = 0; i < size; i++)
        output[i] = a[i];
} 
```