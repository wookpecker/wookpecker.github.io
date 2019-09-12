# 数据结构
[TOC]
##数学模型(ADT)介绍
ADT List{
    &emsp;&emsp; 数据对象：D{${a_i}$ | ${a_i}$$\in$ElemSet,i=1,2,3$\cdots$,n$\geq$0 }
    &emsp;&emsp; 数据关系：R1={$<$${a_i-1}$,${a_i}$$>$|${a_i}$$\in$D,i=2,3$\cdots$,n}
    &emsp;&emsp; 基本操作：
    &emsp;&emsp;&emsp;InitList(&L)
    &emsp;&emsp;&emsp;&emsp;操作结果：构造一个空的线性表L
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;DestroyList(&L)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
    &emsp;&emsp;&emsp;&emsp;操作结果：销毁线性表L
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;ClearList(&L)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
    &emsp;&emsp;&emsp;&emsp;操作结果：将L重置为空表
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;ListEmpty(L)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
    &emsp;&emsp;&emsp;&emsp;操作结果：若L为空表，则返回TRUE，否则返回FALSE
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;ListLength(L)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
    &emsp;&emsp;&emsp;&emsp;操作结果：返回L中数据元素的个数
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;GetElem(L,i,&e)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在,1$\leq$i$\leq$ListLength(L)
    &emsp;&emsp;&emsp;&emsp;操作结果：用e返回L中第i个数据元素的值
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;LocateElem(L,e,compare())
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在,compare()是数据元素判定函数
    &emsp;&emsp;&emsp;&emsp;操作结果：返回L中第1个与e满足compare()方法的数据元素的位序。如果没有找到该值，返回0
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;PriorElem(L,cur_e,&pre_e)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
    &emsp;&emsp;&emsp;&emsp;操作结果：若cur_e是L的数据元素，而且不是第一个，则pre_e返回它的前驱，否则操作失败，pre_e无定义
    &emsp;&emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;NextElem(L,cur_e,&next_e)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
    &emsp;&emsp;&emsp;&emsp;操作结果：若cur_e是L的数据元素，而且不是最后一个，则next_e返回它的后继，否则操作失败，next_e无定义
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;ListInsert(&L,i,e)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在,1$\leq$i$\leq$istLength(L)+1
    &emsp;&emsp;&emsp;&emsp;操作结果：在L中第i个位置之前插入新的数据元素e,L的当前长度加1
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;ListDelete(&L,i,&e)
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在且非空,1$\leq$i$\leq$ListLength(L)
    &emsp;&emsp;&emsp;&emsp;操作结果：删除L的第i个数据元素,并且用e返回这个值，L的当前长度减1
    &emsp;&emsp;&emsp;
    &emsp;&emsp;&emsp;ListTraverse(L,visit())
    &emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
    &emsp;&emsp;&emsp;&emsp;操作结果：依次对L的每一个数据元素调用函数visit(),如果visit()失败，则操作失败
    &emsp;&emsp;&emsp;

         }ADT List

##几种常见的设置
###1.常量预定义
`#define TRUE 1`
`#define FALSE 0`
`#define OK 1`:执行一切正常
`#define ERROR 0`:执行出现错误
`#define INFEASIBLE -1`:操作不可行时返回
`#define OVERFLOW -2`:数据溢出时返回
###2.类型的预定义
`typedef Statu int`:当代码中出现`Statu`时，编译时编译器自动用`int`替代
`typedef ElemType int`:当代码中出现`ElemType`时，编译时编译器自动用`int`替代
`typedef struct Sqlist{}`当代码中出现`Sqlist`时，编译时编译器自动用`struct`替代
###3.结构体的定义
```
struct stu{
   ElemType *elem;//定义指针变量
   int length;
   int listsize;
   ···
}
```
###4.结构体元素的定义与调用

```
   stu sequence;
   //结构体变量的定义直接使用 结构体名字+变量名字 
   sequence.length;
   //结构体的调用使用 . 来调用相关变量
```

##顺序表
###1.顺序表的准备工作
如图所示：
![线性表的图示](https://note.youdao.com/web/#/file/WEBfa1f3607a714e1c7c4b4bfc6e8ffeb33/image/WEBe105aed05af2ccc271ef8592f1659966/)
线性表所需要的变量或者数组有
&emsp;&emsp;&emsp;1）存储线性表的数组
&emsp;&emsp;&emsp;2）数组的当前长度
&emsp;&emsp;&emsp;3）数组的存储容量
&emsp;&emsp;&emsp;4）线性数组的分配增量
可以定义如下结构体:
```
#define LIST_INIT_SIZE 100//数组的初始分配量
#define LISTINCREMENT 10//数组的存储空间分配增量
typedef struct SqList{
            ElemType *elem;//定义指针变量
            int length;
            int listsize;
    } 
```
###2.顺序表的ADT实现

####&emsp;&emsp;&emsp;1.InitList(&L)
&emsp;&emsp;&emsp;&emsp;操作结果：构造一个空的线性表L
&emsp;&emsp;&emsp;
```C++
    //构造一个空的线性表L
        Status InitList(SqList &L){
            L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
            if(!L.elem) 
               return OVERFLOW;
            else{
            L.length=0;
            L.listsize=LIST_INIT_SIZE;
            return OK;
            }
        }
```
####&emsp;&emsp;&emsp;2.DestroyList(&L)
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
&emsp;&emsp;&emsp;&emsp;操作结果：销毁线性表L
&emsp;&emsp;&emsp;
```C++
    Status DestroyList(SqList &L){
       delete [] L.elem;//释放数组空间
       L.length=0;
       L.sizelist=0;
       return OK;
    }
```
####&emsp;&emsp;&emsp;3.ListEmpty(L)
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
&emsp;&emsp;&emsp;&emsp;操作结果：若L为空表，则返回TRUE，否则返回FALSE
&emsp;&emsp;&emsp;
```C++
    Status ListEmpty(L){
       if(L.length==0)
         return OK;
        else
        return FLASE;
    }
```
####&emsp;&emsp;&emsp;4.ClearList(SqList &L)
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
&emsp;&emsp;&emsp;&emsp;操作结果：将L重置为空表
&emsp;&emsp;&emsp;
```
   Status ClearList(SqList &L){
      L.length==0;
      return OK;
   } 
```
####&emsp;&emsp;&emsp;5.ListLength(L)
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
&emsp;&emsp;&emsp;&emsp;操作结果：返回L中数据元素的个数
&emsp;&emsp;&emsp;
```
   Status ListLength(SqList L){
     return L.length;
   }
```
####&emsp;&emsp;&emsp;6.GetElem(L,i,&e)
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在,1$\leq$i$\leq$ListLength(L)
&emsp;&emsp;&emsp;&emsp;操作结果：用e返回L中第i个数据元素的值
```
   ElemType GetElem(SqList L,int i,ElemType &e){
      if(e<0||e>L.length) 
        return ERROR;
    //原理：线性表物理+逻辑都是按照顺序排列，使用能按照规律查找其地址
      e=*(L.elem+(i-1));
        return OK;
   }
```
####&emsp;&emsp;&emsp;7.LocateElem(L,e,compare())
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在,compare()是数据元素判定函数
&emsp;&emsp;&emsp;&emsp;操作结果：返回L中第1个与e满足compare()方法的数据元素的位序。如果没有找到该值，返回0
```
   Status compare(ElemType i,ElemType e){
      	if(i==e)
	       return OK;
     	else
	       return FALSE; 
   }
   int LocateElem(SqList L,ElemType e,Status compare(ElemType i,ElemType e)){
	  int a=0;
	  ElemType n;
	  for(int i=0;i<L.length;i++){
	    	n=*(L.elem+i-1);
	    	a=compare(n,e);
		    if(a==1){
		    	return OK;
		 }
	}
	return FALSE;
}
```
####&emsp;&emsp;&emsp;8.PriorElem(L,cur_e,&pre_e)
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
&emsp;&emsp;&emsp;&emsp;操作结果：若cur_e是L的数据元素，而且不是第一个，则pre_e返回它的前驱，否则操作失败，pre_e无定义
```
    ElemType PriorElem(SqList L,ElemType cur_e,ElemType &pre_e){
        for(int i=2;i<L.length;i++){
        	if(cur_e==*(L.elem+i-1)){
        		pre_e=*(L.elem+i-2);
        		return OK;
			} 
		}
			return FALSE;	
	}
```
####&emsp;&emsp;&emsp;9.NextElem(L,cur_e,&next_e)
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
&emsp;&emsp;&emsp;&emsp;操作结果：若cur_e是L的数据元素，而且不是最后一个，则next_e返回它的后继，否则操作失败，next_e无定义
```
   	ElemType NextElem(SqList L,ElemType cur_e,ElemType &next_e){
        for(int i=1;i<L.length-1;i++){
        	if(cur_e==*(L.elem+i-1)){
        		next_e=*(L.elem+i);
        		return OK;
			} 
		}
			   return FALSE;	
	}
```
####&emsp;&emsp;&emsp;10.ListInsert(&L,i,e)
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在,1$\leq$i$\leq$istLength(L)+1
&emsp;&emsp;&emsp;&emsp;操作结果：在L中第i个位置之前插入新的数据元素e,L的当前长度加1
```
   	Status ListDelete(SqList &L,int i,ElemType &e){
		if(i>L.listsize||i<0)
			return FALSE;
		e=*(L.elem+i-1);
		for(int n=0;n<L.length-i;n++){
			*(L.elem+i-1-n)=*(L.elem+i-2-n);
		}
		return OK;
	}
```
####&emsp;&emsp;&emsp;11.ListTraverse(L,visit())
&emsp;&emsp;&emsp;&emsp;初始条件：线性表L已存在
&emsp;&emsp;&emsp;&emsp;操作结果：依次对L的每一个数据元素调用函数visit(),如果visit()失败，则操作失败
```
   Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}
Status ListTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
    return OK;
}
```
####C++代码完整版:
```
    #include <iostream>
#include"malloc.h"
using namespace std;
#define LIST_INIT_SIZE  100//数组的初始分配量
#define LISTINCREMENT  10//数组的存储空间分配增量
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef  int ElemType;
typedef  int Status;
      //顺序表的准备 
typedef struct SqList{
   ElemType *elem;//定义指针变量
   int length;
   int listsize;
};
        //操作结果：构造一个空的线性表L
        Status InitList_Sq(SqList &L){
            L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//使用malloc时，必须要有头文件 #include"malloc.h"
            if(!L.elem) 
               return OVERFLOW;
            else{
            L.length=0;
            L.listsize=LIST_INIT_SIZE;
            return OK;
            }
          }
        //初始条件：线性表L已存在
        //操作结果：销毁线性表L
        void DestroyList(SqList &L){
             delete [] L.elem;//释放数组空间,必须指明在L下的数组 
             L.length=0;
             L.listsize=0;
    }
        // 初始条件：线性表L已存在。  
        //操作结果：若L为空表，则返回TRUE,否则返回FALSE。
		Status ListEmpty(SqList L){
            if(L.length==0)
               return OK;
            else
               return FALSE;
    }
        Status ClearList(SqList &L){
            L.length==0;
            return OK;
   } 
        //初始条件：线性表L已存在。
        //操作结果：返回L中数据元素个数
		Status  ListLength(SqList L){
            return L.length;
   }
        //初始条件：线性表L已存在，1≤i≤ListLength(L)。
        //操作结果：用e返回L中第i个数据元素的值
		ElemType GetElem(SqList L,int i,ElemType &e){
               if(e<0||e>L.length) 
                  return ERROR;
               //原理：线性表物理+逻辑都是按照顺序排列，使用能按照规律查找其地址
               e=*(L.elem+(i-1));
                   return OK;
   }
        //初始条件：线性表已存在，compare()是数据元素判定函数。
        //操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。
		Status compare(ElemType i,ElemType e){
        	if(i==e)
	           return OK;
	        else
	           return FALSE; 
  }
        int LocateElem(SqList L,ElemType e,Status compare(ElemType i,ElemType e)){
	        int a=0;
	        ElemType n;
	        for(int i=0;i<L.length;i++){
		       n=*(L.elem+i-1);
		       a=compare(n,e);
		       if(a==1){
			   return OK;
		}
	}
	          return FALSE;
}
        // 初始条件：线性表L已存在。  
        //操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
		ElemType PriorElem(SqList L,ElemType cur_e,ElemType &pre_e){
        	for(int i=2;i<L.length;i++){
        		if(cur_e==*(L.elem+i-1)){
        			pre_e=*(L.elem+i-2);
        			return OK;
				  } 
			}
			return FALSE;	
		}
		//初始条件：线性表已存在。
        //操作结果:若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。
		ElemType NextElem(SqList L,ElemType cur_e,ElemType &next_e){
        	for(int i=1;i<L.length-1;i++){
        		if(cur_e==*(L.elem+i-1)){
        			next_e=*(L.elem+i);
        			return OK;
				  } 
			}
			return FALSE;	
		}
		//初始条件：线性表L已存在，1≤i≤ListLength(L)+1。
        //操作结果：在L中第i个位置之前插入新的数据元素e,L的长度加1。
		Status ListInsert(SqList &L,int i,ElemType e){
			if(i>L.listsize||i<0)
			  return ERROR;
			int newsize;
			ElemType *newelem;
			if(L.length==L.listsize){
				newsize=LIST_INIT_SIZE+LISTINCREMENT;
				newelem=(ElemType *)realloc(L.elem,newsize*sizeof(ElemType));
				if(!newelem) 
				   return OVERFLOW;
				L.elem=newelem;
				L.listsize=L.listsize+LISTINCREMENT;
			}
			int p;
			//将这几个数都往外移一位
			for(p=0;p>=L.listsize-i;p--){
				*(L.elem+L.length-i)=*(L.elem+L.length-1-i);
			}
			*(L.elem+i-1)=e; 
            L.length=L.length+1;
			return OK;
		}
		//初始条件：线性表L已存在且非空，1≤i≤ListLength(L)。
        //操作结果：删除L的第i个数据元素，并用e返回其值,L的长度减1。
		Status ListDelete(SqList &L,int i,ElemType &e){
			if(i>L.listsize||i<0)
			  return FALSE;
			e=*(L.elem+i-1);
			for(int n=0;n<L.length-i;n++){
				*(L.elem+i-1-n)=*(L.elem+i-2-n);
			}
			return OK;
		}
		   Status visit(ElemType c){
             printf("%d ",c);
             return OK;
}
		/* 初始条件：顺序线性表L已存在 */
        /* 操作结果：依次对L的每个数据元素输出 */
    Status ListTraverse(SqList L){
	   int i;
       for(i=0;i<L.length;i++)
              visit(L.data[i]);
        printf("\n");
        return OK;
}
         
int main(){
	
}
```
```
  #include <iostream>
/*分配内存的malloc函数需要的头文件*/
#include "malloc.h"
/*定义一些常量 */
/*定义数组初始容量*/
#define BASECAPACITY 1
 /*定义数组的增加容量*/
 #define DECAPACITY 10
 /*定义程序正常运行返回的常数*/
 #define OK 1
 /*定义程序运行失败返回的常量*/
 #define FALSE 0 
 /*定义程序运行错误返回的常数*/
 #define ERROR 0 
 /*定义内存中数据溢出返回的常数*/
 #define OVERFLOW 
 /*定义元素的类型*/
 typedef  int ElemType; 
 /*定义函数返回值的类型*/
 typedef  int Status; 
 /*定义顺序表所需要的结构体*/
 typedef struct{
 	/*顺序表的数组*/
 	ElemType *elem;
 	/*当前数组的当前长度*/
 	int length;
 	/*当前数组的总容量*/
 	int capacity;
 }SqList; 
       /*创建并初始化顺序表*/
       Status InitList(SqList &L){
       	L.elem=(ElemType*)malloc(BASECAPACITY*sizeof(ElemType));
       	L.capacity=BASECAPACITY;
       	L.length=0;
       	return OK;
	   } 
       /*在顺序表插入指定序号的元素,i代表下标为i的元素，即第i+1个位置*/
       Status InsertElem(SqList &L,int i,ElemType e){
       	if(i>L.length || i<0){
       		return FALSE;
		   }  
		if(L.length==L.capacity){
		    ElemType *newelem;
		    L.capacity+=DECAPACITY;
			newelem=(ElemType *)realloc(L.elem,sizeof(ElemType)*L.capacity);
			L.elem=newelem;
		}
		for(int n=0;n<L.length-i;n++){
			*(L.elem+L.length-n)=*(L.elem+L.length-1-n);
		}
		*(L.elem+i)=e;
		L.length+=1;
		return OK;
	   } 
       /*在顺序表中删除指定序号的元素，i代表的是下标为i的元素，即为第i+1个元素*/
       ElemType e;
       ElemType DeleteElem(SqList &L,int i){
       	if(i<0 || i>=L.length){
       		return ERROR;
		   }
		e=*(L.elem+i-1);
		for(int n=0;n<L.length-i;n++){
			*(L.elem+i+n)=*(L.elem+i+n+1);
		}
        return e;
	   }
	   /*读取表中元素的方法*/ 
	   void visit(ElemType e){
	   	 printf("%d\n",e);
	   }
       /*读取顺序表中的元素*/
       Status ListTraverse(SqList L){
       	 for(int i=0;i<L.length-1;i++){
       	 	visit(L.elem[i]);
			}
			return OK;
	   } 
       /*获取顺序表中元素最大值和最小值*/
       
 /**/
 /**/
 
using namespace std;
int main(){
	SqList L;
	InitList(L);
	InsertElem(L,0,1);
	printf("%d\n",L.length);
	printf("%d\n",L.capacity);
	InsertElem(L,1,2);
	printf("%d\n",L.length);
	printf("%d\n",L.capacity);
	printf("%d\n",L.elem[0]);
	printf("%d\n",L.elem[1]);
	InsertElem(L,2,3);
	DeleteElem(L,1);
	printf("%d\n",L.elem[0]);
	printf("%d\n",L.elem[1]);
	ListTraverse(L);
}
```



