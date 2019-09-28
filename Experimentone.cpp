#include <iostream>
/*分配内存的malloc函数需要的头文件*/
#include "malloc.h"
/*定义一些常量 */
/*定义数组初始容量*/
#define BASECAPACITY 10
 /*定义数组的增加容量*/
 #define DECAPACITY 10
 /*定义程序正常运行返回的常数*/
 #define OK 1
 /*定义程序运行失败返回的常量*/
 #define FALSE 0 
 /*定义程序运行错误返回的常数*/
 #define ERROR 0 
 /*定义内存中数据溢出返回的常数*/
 #define OVERFLOW -2
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
		*(L.elem+i
		)=e;
		L.length+=1;
		return OK;
	} 
    /*在顺序表中删除指定序号的元素，i代表的是下标为i的元素，即为第i+1个元素*/   
    ElemType DeleteElem(SqList &L,int i){
	    ElemType e;
       	if(i<0 || i>=L.length){
       		return ERROR;
		   }
		e=*(L.elem+i-1);
		for(int n=0;n<L.length-i;n++){
			*(L.elem+i+n)=*(L.elem+i+1+n);
		}
		L.length=L.length-1;
        return e;
	   }
	/*读取表中元素的方法*/ 
	void visit(ElemType e){
	   	 printf("%d  ",e);
	   }
    /*读取顺序表中的元素*/
    Status ListTraverse(SqList L){
       	 for(int i=0;i<=L.length-1;i++){
       	 	visit(L.elem[i]);
			}
			return OK;
	   } 
    /*获取顺序表中元素最大值*/
    ElemType MaxElem(SqList L){
       	ElemType max;
       	max=*(L.elem);
       	for(int i=1;i<L.length;i++){
       		if(*(L.elem+i)>max){
       			max=*(L.elem+i);
			   }
		   }
		   return max;
	   }  
    /*获取顺序表中的最小值*/
    ElemType MinElem(SqList L){
       	ElemType min;
       	min=*(L.elem);
       	for(int i=1;i<L.length;i++){
       		if(*(L.elem+i)<min){
       			min=*(L.elem+i);
			   }
		   }
		   return min;
	   } 
    /*查找顺序表中的元素*/
    void LocateElem(SqList L,ElemType e){
       	bool exist=false;
       	for(int i=1;i<L.length;i++){
       		if(*(L.elem+i-1)==e){
       			exist=true;
			   }
		   }
		if(exist==true){
			printf("该顺序表中存在%d这个元素\n",e);
		}else{
			printf("该顺序表中不存在%d这个元素\n",e);
		}
	} 
	   Status swap(ElemType &a,ElemType &b){
	   	int t=a;
	   	a=b;
	   	b=t;
	   	return OK;
	   }
    /*将表元素按升序排序(冒泡排序)*/
    void ElemBubbling(SqList &L){
       	for(int i=0;i<L.length-1;i++){
       		for(int j=0;j<L.length-1-i;j++){
       			if(*(L.elem+j)>*(L.elem+j+1)){
       				swap(*(L.elem+j),*(L.elem+j+1));
				   }
			   }
		   }
		   return;
	   }
    /*将表元素进行逆置*/ 
    void ElemInverse(SqList &L){
         for(int m=0;m<(L.length)/2;m++){
		 swap(*(L.elem+m),*(L.length-m-1+L.elem));
		 } 
	   }
	/*将表元素逆置方法二:递归实现*/
	int i=0;
	void ElemInverse_2(SqList &L){
		if(i<L.length-i){
		   swap(*(L.elem+i),*(L.elem+L.length-i-1));
		   i++;
		   ElemInverse_2(L);
		}else{
		   return;
		}
	} 
    /*顺序表的输入*/
    Status InputElem(SqList &L){
       	int a;
       	int i=0;
       	while(scanf("%d",&a)){
       		InsertElem(L,i++,a);
		   }
		return OK;
	   } 
	/*两个有序顺序表的简单合并(直接将两个数组合并就可以)*/
	SqList UnionList(SqList L,SqList Q){
    	SqList U;
    	/*空间分配的大小为前两个顺序表的长度相加*/ 
    	U.elem=(ElemType *)malloc((L.length+Q.length)*sizeof(ElemType));
    	U.length=0;
    	for(int i=0;i<L.length;i++){
    		/*将第一个顺序表复制到第三个顺序表中*/ 
    		*(U.elem+i)=*(L.elem+i);
    		U.length=U.length+1;
		}
		for(int j=0;j<Q.length;j++){
			/*将第二个顺序表复制到第三个顺序表中*/
			*(U.elem+L.length+j)=*(Q.elem+j);
			U.length=U.length+1;
		} 
		return U;
	}
    /*对于排好序的数组去除大小相同的元素*/
    Status NoSame(SqList &L){
    	for(int i=1;i<L.length-1;i++){
    		if(*(L.elem+i)==*(L.elem+i-1)){
    			DeleteElem(L,i);
    			/*每删除一个元素(第i个元素)后，还要将原顺序表的第(i)个元素和第(i+2)个元素进行对比，所以要进行减减操作*/
    			i--;
			}
		}
		return OK; 
	}
	/*边比较边排序*/
	SqList UnionList_2(SqList L,SqList Q){
		SqList U;
		/*空间分配的大小为前两个顺序表的长度相加*/ 
    	U.elem=(ElemType *)malloc((L.length+Q.length)*sizeof(ElemType));
    	U.capacity=L.length+Q.length;
        U.length=0;
		int i=0,j=0,k=0;
		for(;(*(L.elem+i)<*(L.elem+L.length))&&(*(j+Q.elem)<*(Q.elem+Q.length-1))&&(k<U.capacity);k++){
		
				if( (*(L.elem+i)==*(L.elem+i+1)) &&i<L.length-1){
				i=i+1;
			}
			
			    if(( *(Q.elem+j)==*(Q.elem+j+1) )&&j<Q.length-1){
				j=j+1;
			}
			if(*(L.elem+i)<*(Q.elem+j)){
				*(U.elem+k)=*(L.elem+i);
				i++;
				U.length++;
			}else if(*(L.elem+i)>*(Q.elem+j)){
				*(U.elem+k)=*(Q.elem+j);
				j++;
				U.length++;
			}else{
				*(U.elem+k)=*(L.elem+i);
				U.length++;
				i++;
				j++;
			}
		}
		if(*(L.elem+i)==*(L.elem+L.length)){	    
			for(;j<Q.length;j++){
			if(*(Q.elem+j)==*(Q.elem+j+1))
				j=j+1; 
			*(U.elem+k)=*(Q.elem+j);
			k++;
			U.length++; 
			} 
		}else if(*(j+Q.elem)==*(Q.elem+Q.length)){
			for(;i<L.length;i++){ 
			if(*(L.elem+i)==*(L.elem+i+1))
				i=i+1;
			*(U.elem+k)=*(L.elem+i);
			k++; 
			U.length++;
			} 
		}
		return U;
	} 
    /*实现两个有序顺序表的合并，合并后也有序，并且只保留顺序表中重复元素的一个*/    
	SqList Synthesis(){
	    SqList L;
	    SqList Q;
	    InitList(Q);
	    InitList(L);
	    printf("请输入第一个顺序表:\n"); 
	    InputElem(L);
		ElemBubbling(L);
		/*连续输入操作要相清空缓存区，才能进行在此输入*/ 
	    fflush(stdin);
	    printf("请输入第二个顺序表:\n");
	    InputElem(Q);
    	ElemBubbling(Q);
    	SqList U=UnionList(L,Q);
		ElemBubbling(U);    	
    	NoSame(U);
    	return U;
	}
	 /*实现两个有序顺序表的合并，合并后也有序，并且只保留顺序表中重复元素的一个*/
	SqList Synthesis_2(){
		SqList L;
	    SqList Q;
	    InitList(Q);
	    InitList(L);
	    printf("请输入第一个顺序表:\n"); 
	    InputElem(L);
		ElemBubbling(L);
		/*连续输入操作要相清空缓存区，才能进行在此输入*/ 
	    fflush(stdin);
	    printf("请输入第二个顺序表:\n");
	    InputElem(Q);
    	ElemBubbling(Q);
    	SqList U=UnionList_2(L,Q);
    	return U;
	} 
using namespace std;
int main(){
	printf("------------------------------------------------问题一----------------------------------------------\n"); 
	printf("\n"); 
	SqList L;
	printf("------------------------------顺序表初始化-------------------------------\n"); 
	InitList(L);
	printf("当前顺序表的长度为:%d\n",L.length);
    printf("当前顺序表的容量为:%d\n",L.capacity);
    printf("------------------------------顺序表元素的插入-------------------------------\n"); 
	InsertElem(L,0,1);
	InsertElem(L,1,2);
	InsertElem(L,2,0);
	InsertElem(L,3,-9);
	InsertElem(L,4,19);
	InsertElem(L,5,109);
	InsertElem(L,6,18);
	InsertElem(L,7,16);
	InsertElem(L,8,12);
	InsertElem(L,9,1);
	InsertElem(L,10,10);
	printf("当前顺序表的长度为:%d\n",L.length);
    printf("当前顺序表的容量为:%d\n",L.capacity);
    ListTraverse(L);
    printf("\n");
    printf("------------------------------顺序表元素的删除-------------------------------\n");
    DeleteElem(L,1); 
    printf("当前顺序表的长度为:%d\n",L.length);
    printf("当前顺序表的容量为:%d\n",L.capacity);
    ListTraverse(L);
    printf("\n");
    printf("------------------------------顺序表元素的最值问题-------------------------------\n");
	ElemType Max=MaxElem(L);
    ElemType Min=MinElem(L);
    printf("顺序表的最大值为:%d\n",Max); 
    printf("顺序表的最小值为:%d\n",Min);
	printf("------------------------------顺序表元素的查找-------------------------------\n");
    LocateElem(L,8);
	printf("------------------------------顺序表元素的排序-------------------------------\n");
	printf("排序前的数组:");
	ListTraverse(L);
	printf("\n");
	printf("倒置后的数组:");
	ElemInverse_2(L);
	ListTraverse(L);
	printf("\n");
	printf("排序后的数组:");
	ElemBubbling(L);
	ListTraverse(L);
	printf("\n");
	printf("------------------------------------------------问题二----------------------------------------------\n"); 
	printf("\n");
	SqList M=Synthesis_2(); 
	printf("合并之后的顺序表:\n");
    ListTraverse(M);	 
}
