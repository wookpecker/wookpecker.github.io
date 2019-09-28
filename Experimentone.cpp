#include <iostream>
/*�����ڴ��malloc������Ҫ��ͷ�ļ�*/
#include "malloc.h"
/*����һЩ���� */
/*���������ʼ����*/
#define BASECAPACITY 10
 /*�����������������*/
 #define DECAPACITY 10
 /*��������������з��صĳ���*/
 #define OK 1
 /*�����������ʧ�ܷ��صĳ���*/
 #define FALSE 0 
 /*����������д��󷵻صĳ���*/
 #define ERROR 0 
 /*�����ڴ�������������صĳ���*/
 #define OVERFLOW -2
 /*����Ԫ�ص�����*/
 typedef  int ElemType; 
 /*���庯������ֵ������*/
 typedef  int Status; 
 /*����˳�������Ҫ�Ľṹ��*/
 typedef struct{
 	/*˳��������*/
 	ElemType *elem;
 	/*��ǰ����ĵ�ǰ����*/
 	int length;
 	/*��ǰ�����������*/
 	int capacity;
 }SqList; 
    /*��������ʼ��˳���*/
    Status InitList(SqList &L){
       	L.elem=(ElemType*)malloc(BASECAPACITY*sizeof(ElemType));
       	L.capacity=BASECAPACITY;
       	L.length=0;
       	return OK;
	   } 
    /*��˳������ָ����ŵ�Ԫ��,i�����±�Ϊi��Ԫ�أ�����i+1��λ��*/
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
    /*��˳�����ɾ��ָ����ŵ�Ԫ�أ�i��������±�Ϊi��Ԫ�أ���Ϊ��i+1��Ԫ��*/   
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
	/*��ȡ����Ԫ�صķ���*/ 
	void visit(ElemType e){
	   	 printf("%d  ",e);
	   }
    /*��ȡ˳����е�Ԫ��*/
    Status ListTraverse(SqList L){
       	 for(int i=0;i<=L.length-1;i++){
       	 	visit(L.elem[i]);
			}
			return OK;
	   } 
    /*��ȡ˳�����Ԫ�����ֵ*/
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
    /*��ȡ˳����е���Сֵ*/
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
    /*����˳����е�Ԫ��*/
    void LocateElem(SqList L,ElemType e){
       	bool exist=false;
       	for(int i=1;i<L.length;i++){
       		if(*(L.elem+i-1)==e){
       			exist=true;
			   }
		   }
		if(exist==true){
			printf("��˳����д���%d���Ԫ��\n",e);
		}else{
			printf("��˳����в�����%d���Ԫ��\n",e);
		}
	} 
	   Status swap(ElemType &a,ElemType &b){
	   	int t=a;
	   	a=b;
	   	b=t;
	   	return OK;
	   }
    /*����Ԫ�ذ���������(ð������)*/
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
    /*����Ԫ�ؽ�������*/ 
    void ElemInverse(SqList &L){
         for(int m=0;m<(L.length)/2;m++){
		 swap(*(L.elem+m),*(L.length-m-1+L.elem));
		 } 
	   }
	/*����Ԫ�����÷�����:�ݹ�ʵ��*/
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
    /*˳��������*/
    Status InputElem(SqList &L){
       	int a;
       	int i=0;
       	while(scanf("%d",&a)){
       		InsertElem(L,i++,a);
		   }
		return OK;
	   } 
	/*��������˳���ļ򵥺ϲ�(ֱ�ӽ���������ϲ��Ϳ���)*/
	SqList UnionList(SqList L,SqList Q){
    	SqList U;
    	/*�ռ����Ĵ�СΪǰ����˳���ĳ������*/ 
    	U.elem=(ElemType *)malloc((L.length+Q.length)*sizeof(ElemType));
    	U.length=0;
    	for(int i=0;i<L.length;i++){
    		/*����һ��˳����Ƶ�������˳�����*/ 
    		*(U.elem+i)=*(L.elem+i);
    		U.length=U.length+1;
		}
		for(int j=0;j<Q.length;j++){
			/*���ڶ���˳����Ƶ�������˳�����*/
			*(U.elem+L.length+j)=*(Q.elem+j);
			U.length=U.length+1;
		} 
		return U;
	}
    /*�����ź��������ȥ����С��ͬ��Ԫ��*/
    Status NoSame(SqList &L){
    	for(int i=1;i<L.length-1;i++){
    		if(*(L.elem+i)==*(L.elem+i-1)){
    			DeleteElem(L,i);
    			/*ÿɾ��һ��Ԫ��(��i��Ԫ��)�󣬻�Ҫ��ԭ˳���ĵ�(i)��Ԫ�غ͵�(i+2)��Ԫ�ؽ��жԱȣ�����Ҫ���м�������*/
    			i--;
			}
		}
		return OK; 
	}
	/*�߱Ƚϱ�����*/
	SqList UnionList_2(SqList L,SqList Q){
		SqList U;
		/*�ռ����Ĵ�СΪǰ����˳���ĳ������*/ 
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
    /*ʵ����������˳���ĺϲ����ϲ���Ҳ���򣬲���ֻ����˳������ظ�Ԫ�ص�һ��*/    
	SqList Synthesis(){
	    SqList L;
	    SqList Q;
	    InitList(Q);
	    InitList(L);
	    printf("�������һ��˳���:\n"); 
	    InputElem(L);
		ElemBubbling(L);
		/*�����������Ҫ����ջ����������ܽ����ڴ�����*/ 
	    fflush(stdin);
	    printf("������ڶ���˳���:\n");
	    InputElem(Q);
    	ElemBubbling(Q);
    	SqList U=UnionList(L,Q);
		ElemBubbling(U);    	
    	NoSame(U);
    	return U;
	}
	 /*ʵ����������˳���ĺϲ����ϲ���Ҳ���򣬲���ֻ����˳������ظ�Ԫ�ص�һ��*/
	SqList Synthesis_2(){
		SqList L;
	    SqList Q;
	    InitList(Q);
	    InitList(L);
	    printf("�������һ��˳���:\n"); 
	    InputElem(L);
		ElemBubbling(L);
		/*�����������Ҫ����ջ����������ܽ����ڴ�����*/ 
	    fflush(stdin);
	    printf("������ڶ���˳���:\n");
	    InputElem(Q);
    	ElemBubbling(Q);
    	SqList U=UnionList_2(L,Q);
    	return U;
	} 
using namespace std;
int main(){
	printf("------------------------------------------------����һ----------------------------------------------\n"); 
	printf("\n"); 
	SqList L;
	printf("------------------------------˳����ʼ��-------------------------------\n"); 
	InitList(L);
	printf("��ǰ˳���ĳ���Ϊ:%d\n",L.length);
    printf("��ǰ˳��������Ϊ:%d\n",L.capacity);
    printf("------------------------------˳���Ԫ�صĲ���-------------------------------\n"); 
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
	printf("��ǰ˳���ĳ���Ϊ:%d\n",L.length);
    printf("��ǰ˳��������Ϊ:%d\n",L.capacity);
    ListTraverse(L);
    printf("\n");
    printf("------------------------------˳���Ԫ�ص�ɾ��-------------------------------\n");
    DeleteElem(L,1); 
    printf("��ǰ˳���ĳ���Ϊ:%d\n",L.length);
    printf("��ǰ˳��������Ϊ:%d\n",L.capacity);
    ListTraverse(L);
    printf("\n");
    printf("------------------------------˳���Ԫ�ص���ֵ����-------------------------------\n");
	ElemType Max=MaxElem(L);
    ElemType Min=MinElem(L);
    printf("˳�������ֵΪ:%d\n",Max); 
    printf("˳������СֵΪ:%d\n",Min);
	printf("------------------------------˳���Ԫ�صĲ���-------------------------------\n");
    LocateElem(L,8);
	printf("------------------------------˳���Ԫ�ص�����-------------------------------\n");
	printf("����ǰ������:");
	ListTraverse(L);
	printf("\n");
	printf("���ú������:");
	ElemInverse_2(L);
	ListTraverse(L);
	printf("\n");
	printf("����������:");
	ElemBubbling(L);
	ListTraverse(L);
	printf("\n");
	printf("------------------------------------------------�����----------------------------------------------\n"); 
	printf("\n");
	SqList M=Synthesis_2(); 
	printf("�ϲ�֮���˳���:\n");
    ListTraverse(M);	 
}
