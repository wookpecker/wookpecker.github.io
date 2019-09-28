#include <iostream>
/*�����ڴ��malloc������Ҫ��ͷ�ļ�*/
#include "malloc.h"
using namespace std;
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
 /*
  *LNode�Ǵ����ڵ�ʱ����(��Ҫ�����ڴ�)
  *LinkList�Ǵ���һ���µ�����ʱ�����õ�
  *Pointer�Ǵ���һ����ʱָ��ʱ�����õģ���������Ǽǵ��ͷ�ָ���ڴ� 
  */
 typedef struct LNode{
	int num;
	ElemType password;
	bool leaveRank;
	struct LNode *next;
}LNode,*LinkList,*Point;
/*Լɪ�򻷵Ĵ�������ʼ��*/
LinkList InitList(){
	LinkList L;
	L=(LNode *)malloc(sizeof(LNode));
	return L;
} 
/*β�巨��������Լɪ��*/
Status InsertWholeElem_E(LinkList L,int n){
	Point end;
	ElemType b;
	int i=0;
	  while(scanf("%d",&b)){
     	if(i==0){
     		L->leaveRank=0;
     		L->num=i+1;
     		L->password=b;
			L->next=L;
     		end=L;
		 }else{
		 	LNode *curr;
            curr=(LNode *)malloc(sizeof(LNode));
            curr->num=i+1;
            curr->password=b;
            curr->leaveRank=0;
            end->next=curr;
            curr->next=L;
            end=curr;
            }
            i++;
	    }
	 free(end);
	 return OK;
 }
/*ѭ��������Ԫ�صı���*/ 
void TraverseList(LinkList L){
	Point start;
	printf("%d,%d\n",L->num,L->password);
//	printf("aaaaaaaaaaaaaaaaa\n");
	start=L->next;
	//�޷�������ͷָ����ָ���Ԫ�� 
	while(start != L){
		printf("%d,%d\n",start->num,start->password);
		start=start->next;
	}
//	printf("qqqqqqqqqq");
	free(start);
}
/*�����˱�ŵ����*/
Status  RankNumbers(LinkList L,int m,int n){
	int i=1,count=0;
	LNode *p;
    p=L;
    int q=m;
	while(count<n){
	if(p->leaveRank!=0){
		p=p->next;
        continue;
	}else if((i%q==0)){
		q=q+p->password;
		printf("%d ",p->num);
		count++;
//        if(count==n){
//        	break;
//		}
		p->leaveRank=1;
		p=p->next;
		i++;
	}else{
		p=p->next;
		i++;
	}
  }	
  return OK;	
} 
/*��ָ��λ���ϲ���ڵ㲢�洢����*/
 Status InsertElem(LinkList *L,int t,ElemType e){
 	LNode *newPoint;
 	newPoint=(LNode *)malloc(sizeof(LNode));
 	newPoint->num=t+1;
 	newPoint->leaveRank=0;
 	newPoint->password=e;
	LNode *p;
 	p=*L;
	 //�������һ��λ��ʱ 
	 if(t==0){
 		newPoint->next=p;
		while(p->next!=*L){
			p=p->next;
		} 
		*L=newPoint;
		p->next=*L;
	 }else{
	 	//�����λ�ò��ڵ�һ��Ԫ��ʱ 
	    for(int i=1;i<t;i++){
		p=p->next;
	}
	newPoint->next=p->next;
	p->next=newPoint;
	 }
	 free(p);
	 //�����ǵ�t>nʱ 
// 	if(t>n){
// 		t=t%n;
//	 }
	//������Ԫ�ص�λ�ü�һ 
	Point old;
	old=newPoint->next;
	while(old!=*L){
	    old->num++;
		old=old->next;
	}
	free(old);
	
	return OK;
 }
 /*ɾ��ָ��λ�õĽڵ㲢�ҷ�������ڵ������ֵ*/
 Status DeleteElem(LinkList *L,int index) {
 	Point ptr = *L;
 	if (index < 1 || index > (*L)->num) {
 		return -1;
	}
	//����ɾ������ͷ�ڵ�ʱ 
	if(index == 1){
		//ѭ����������ֻ��һ��Ԫ��ʱ 
	 	if (ptr->next == *L){
	 		free(*L);
		} else {
			//�ҵ�β�ڵ� 
			while (ptr->next != *L) {
				ptr = ptr->next;
			}
			//��β�ڵ�ָ���2���ڵ� 
			ptr->next = (*L)->next;
			free(*L);
			//��ͷָ��ָ���2��Ԫ�� 
			*L = ptr->next;
			//�������Ԫ����Ŷ�����һ 
			Point tarve;
			tarve=*L;
			while(tarve->next!=(*L)){
				tarve->num--;
				tarve=tarve->next;
			}
			tarve->num--;
			free(tarve);
		}
		return OK;
   }
    //�ҵ���i-1��Ԫ�� 
	for(int i = 0; i < index - 2; i++) {
 		ptr = ptr->next;
	}
	//����i-1��Ԫ��ָ���i+1��Ԫ�� 
	Point temp = ptr;
	ptr->next = ptr->next->next;
	//�����Ԫ�غ��������Լ� 
	while(temp->next!=(*L)){
		temp->num++;
		temp=temp->next;
	}
	free(temp);
	return OK;
 }
 /*Ԫ�صĲ��ң���������˵�����ȥ����*/
 int LocateElem(LinkList L,ElemType e){
 	Point curr;
 	curr=L;
 	int i=1;
 	if(e==curr->password){
 	    return i;	
	 }
	 curr=L->next;
 	while(curr!=L){
	    i++;
 		if(e==curr->password){
 			return i;
		 } 
	 }
	 return 0;
 }
 /*Ԫ�����ֵ�Ĳ���*/
ElemType MaxElem(LinkList L){
	if(L->next==L){
		return L->password;
	}
	ElemType max;
	Point curr;
	curr=L;
	max=curr->password;
	while(curr->next!=L){
		if(max<curr->password){
			max=curr->password;
		}
		curr=curr->next;
	}
	if(curr->password>max){
		max=curr->password;
	}
	return max;
} 
/*��Ԫ�ص���Сֵ*/ 
ElemType MinElem(LinkList L){
	if(L->next==L){
		return L->password;
	}
	ElemType min;
	Point curr;
	curr=L;
	min=curr->password;
	while(curr->next!=L){
		if(min>curr->password){
			min=curr->password;
		}
		curr=curr->next;
	}
	if(curr->password<min){
		min=curr->password;
	}
	return min;
} 
/*��ѭ����������*/
Status ListInverse(LinkList L){
	if(L->next==L || L->next==NULL){
		return OK;
	}
	Point old,curr,preserve;
	old=L;
	curr=L->next;
	while(curr!=L){
		preserve=curr->next;
		curr->next=old;
		old=curr;
		curr=preserve;
	}
	curr->next=old;
	free(old);
	free(curr);
	free(preserve);
	return OK;
} 
/*�������Ľ��� */
Status swap(ElemType &a,ElemType &b){
	   	int t=a;
	   	a=b;
	   	b=t;
	   	return OK;
}
/*��������ֵ�Ľ���*/
Status swap(bool &a,bool &b){
	   	bool t=a;
	   	a=b;
	   	b=t;
	   	return OK;
}
/*ѭ�����������(���������С��������)ð������*/
Status ListBubbling(LinkList L,int n){
	Point temp;
	    for(int i=0;i<n-1;i++){
		    temp=L;
       		for(int j=0;j<n-1-i;j++){
       			if(temp->password>temp->next->password){
       				swap(temp->password,temp->next->password);
       				swap(temp->leaveRank,temp->next->leaveRank);
				   }
				   temp=temp->next;
			   }
		   }
		   free(temp);
		   return OK; 
}
int main(){
	LinkList L=InitList();
//	cout<<L<<"\n"; 
    printf("����������:\n");
	int n;
    scanf("%d",&n);
    fflush(stdin);
    printf("�������һ���õ�����:\n");
	int m;
    scanf("%d",&m);
    fflush(stdin);
    printf("��Ӧ����������:\n");
	InsertWholeElem_E(L,n);
	TraverseList(L);
	printf("\n");
	printf("111111111111111111111\n");
	InsertElem(&L,0,5);
	TraverseList(L);
	printf("bianli\n");
	DeleteElem(&L,1);
	TraverseList(L);
	printf("oooooooooooooooooo\n");
//	ListInverse(L);
//	TraverseList(L);
	ListBubbling(L,n);
	TraverseList(L);
	printf("%d\n",MaxElem(L)); 
	printf("%d\n",MinElem(L)); 
//	printf("%d",LocateElem(L,2));
//	RankNumbers(L,m,n);	
}
