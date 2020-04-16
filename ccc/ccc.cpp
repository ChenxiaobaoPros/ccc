// ccc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
} book = { "C 语言", "RUNOOB", "编程语言", 123456 };

struct bs {
    int a : 8;
    int b : 2;
    int c : 6;
}data;

union Data
{
    int i;
    float f;
    char  str[20];
};

////在这个位域定义中，a 占第一字节的 4 位，后 4 位填 0 表示不使用，
////b 从第二字节开始，占用 4 位，c 占用 4 位。
//struct bss {
//    unsigned a : 4;
//    unsigned : 4;    /* 空域 不能使用*/
//    unsigned b : 4;    /* 从下一单元开始存放 */
//    unsigned c : 4
//};

int max(int x, int y)
{
    return x > y ? x : y;
}

// 回调函数
void populate_array(int* array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
        array[i] = getNextValue();
}

// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}

/* 函数声明 */
void printBook(struct Books book);

void printsBook(struct Books* book);



int main()
{
    printf("*******************变量指针*******************************\n");
    //变量指针
    int a = 12;//变量
    int* pa = &a;//去指针 int* p (c++)和 int *p(c)在编译器看是一样的、只是风格不同
    printf("变量： %i\n", a);
    printf("变量的指针： %i\n", pa);//&取地址符、表示变量a的地址
    printf("根据指针取内存中的变量值： %i\n", *&a); //*是取内存符  *p是指取在地址p的内存 p是指针
    printf("根据指针取内存中的变量值： %i\n", *pa);
    printf("变量的指针： %i\n", &*pa);

    printf("*******************数组指针*******************************\n");

    //复杂变量指针
    char l[3] = { 'c','b','a' }; //在栈上分配、等价于char a1 ={'c','b','a','\0'};
    char* pp = &l[0];
    char* p = new char[3]{ 'c','b','a' };// 在堆上分配，返回首元素的地址
    printf("变量(栈)： %c\n", l[0]);
    printf("首地址指针(栈)： %i\n", pp); //
    printf("根据首地址指针取内存(栈)： %c\n", *pp); //
    printf("根据首地址指针取内存索引1(栈)： %c\n", *(pp+1)); //

    printf("----------------------------------------------------------\n");

    printf("首地址指针的指针(堆)： %i\n", &p); //
    printf("根据首地址指针取内存(堆)： %c\n", *p);//
    printf("根据首地址指针取内存索引1(堆)： %c\n", *(p+1));//
 
    printf("*******************函数指针*******************************\n");

    /* p 是函数指针 */
    int (*pv)(int, int) = &max; // &可以省略
    int x, y, z, j;

    printf("请输入三个数字:\n");
    scanf("%d %d %d", &x, &y, &z);

    /* 与直接调用函数等价，d = max(max(a, b), c) */
    j = pv(pv(x, y), z);

    printf("最大的数字是: %d\n", j);

    printf("*******************回调函数*******************************\n");

    int myarray[10];

    populate_array(myarray, 10, getNextRandomValue);

    for (int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");

    printf("*******************字符串*******************************\n");

    char str1[12] = "Hello";
    char str2[12] = "World";
    char str3[12];
    int  len;

    /* 复制 str1 到 str3 */
    strcpy(str3, str1);
    printf("strcpy( str3, str1) :  %s\n", str3);

    /* 连接 str1 和 str2 */
    strcat(str1, str2);
    printf("strcat( str1, str2):   %s\n", str1);

    /* 连接后，str1 的总长度 */
    len = strlen(str1);
    printf("strlen(str1) :  %d\n", len);


    printf("*******************结构体*******************************\n");
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
    
    Books book1;
    /* Book1 详述 */
    strcpy(book1.title, "C Programming");
    strcpy(book1.author, "Nuha Ali");
    strcpy(book1.subject, "C Programming Tutorial");
    book1.book_id = 6495407;
    /* 输出 Book1 信息 */
    printf("Book 1 title : %s\n", book1.title);
    printf("Book 1 author : %s\n", book1.author);
    printf("Book 1 subject : %s\n", book1.subject);
    printf("Book 1 book_id : %d\n", book1.book_id);

    /* 输出 Book1 信息 */
    printBook(book1);

    //指向结构的指针
    printsBook(&book1);

    printf("*******************位域结构体*******************************\n");
    //位域
    struct bs {
        unsigned a : 1;
        unsigned b : 3;
        unsigned c : 4;
    } bit, * pbit;
    bit.a = 1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b = 7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.c = 15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    printf("%d,%d,%d\n", bit.a, bit.b, bit.c);    /* 以整型量格式输出三个域的内容 */
    pbit = &bit;    /* 把位域变量 bit 的地址送给指针变量 pbit */
    pbit->a = 0;    /* 用指针方式给位域 a 重新赋值，赋为 0 */
    pbit->b &= 3;    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit->c |= 1;    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
    printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c);    /* 用指针方式输出了这三个域的值 */

    printf("*******************共用体*******************************\n");

    union Data data;

    data.i = 10;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %f\n", data.f);

    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);

    return 0;
}
//函数可以先声明在后面实现
void printBook(struct Books book)
{
    printf("Book title : %s\n", book.title);
    printf("Book author : %s\n", book.author);
    printf("Book subject : %s\n", book.subject);
    printf("Book book_id : %d\n", book.book_id);
}
void printsBook(struct Books* book)
{
    printf("Book title : %s\n", book->title);
    printf("Book author : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book book_id : %d\n", book->book_id);
}

