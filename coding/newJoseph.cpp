#include <iostream>
/*分配内存的malloc函数需要的头文件*/
#include "malloc.h"
using namespace std;
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
 /*
  *LNode是创建节点时运用(需要分配内存)
  *LinkList是创建一个新的链表时候运用的
  *Pointer是创建一个临时指针时候运用的，运用完毕是记得释放指针内存 
  */
 typedef struct LNode{
	int num;
	ElemType password;
	bool leaveRank;
	struct LNode *next;
}LNode,*LinkList,*Point;
/*约瑟夫环的创建并初始化*/
LinkList InitList(){
	LinkList L;
	L=(LNode *)malloc(sizeof(LNode));
	return L;
} 
/*尾插法进行输入约瑟夫环*/
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
/*循环链表中元素的遍历*/ 
void TraverseList(LinkList L){
	Point start;
	printf("%d,%d\n",L->num,L->password);
//	printf("aaaaaaaaaaaaaaaaa\n");
	start=L->next;
	//无法遍历到头指针所指向的元素 
	while(start != L){
		printf("%d,%d\n",start->num,start->password);
		start=start->next;
	}
//	printf("qqqqqqqqqq");
	free(start);
}
/*出列人编号的输出*/
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
/*在指定位置上插入节点并存储数据*/
 Status InsertElem(LinkList *L,int t,ElemType e){
 	LNode *newPoint;
 	newPoint=(LNode *)malloc(sizeof(LNode));
 	newPoint->num=t+1;
 	newPoint->leaveRank=0;
 	newPoint->password=e;
	LNode *p;
 	p=*L;
	 //当插入第一个位置时 
	 if(t==0){
 		newPoint->next=p;
		while(p->next!=*L){
			p=p->next;
		} 
		*L=newPoint;
		p->next=*L;
	 }else{
	 	//插入的位置不在第一个元素时 
	    for(int i=1;i<t;i++){
		p=p->next;
	}
	newPoint->next=p->next;
	p->next=newPoint;
	 }
	 free(p);
	 //当考虑到t>n时 
// 	if(t>n){
// 		t=t%n;
//	 }
	//将后面元素的位置加一 
	Point old;
	old=newPoint->next;
	while(old!=*L){
	    old->num++;
		old=old->next;
	}
	free(old);
	
	return OK;
 }
 /*删除指定位置的节点并且返回这个节点的密码值*/
 Status DeleteElem(LinkList *L,int index) {
 	Point ptr = *L;
 	if (index < 1 || index > (*L)->num) {
 		return -1;
	}
	//当被删除的是头节点时 
	if(index == 1){
		//循环链表里面只有一个元素时 
	 	if (ptr->next == *L){
	 		free(*L);
		} else {
			//找到尾节点 
			while (ptr->next != *L) {
				ptr = ptr->next;
			}
			//将尾节点指向第2个节点 
			ptr->next = (*L)->next;
			free(*L);
			//将头指针指向第2个元素 
			*L = ptr->next;
			//将后面的元素序号都加上一 
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
    //找到第i-1个元素 
	for(int i = 0; i < index - 2; i++) {
 		ptr = ptr->next;
	}
	//将第i-1个元素指向第i+1个元素 
	Point temp = ptr;
	ptr->next = ptr->next->next;
	//将这个元素后面的序号自加 
	while(temp->next!=(*L)){
		temp->num++;
		temp=temp->next;
	}
	free(temp);
	return OK;
 }
 /*元素的查找，按照这个人的密码去查找*/
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
 /*元素最大值的查找*/
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
/*求元素的最小值*/ 
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
/*将循环链表逆置*/
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
/*两个数的交换 */
Status swap(ElemType &a,ElemType &b){
	   	int t=a;
	   	a=b;
	   	b=t;
	   	return OK;
}
/*两个布尔值的交换*/
Status swap(bool &a,bool &b){
	   	bool t=a;
	   	a=b;
	   	b=t;
	   	return OK;
}
/*循环链表的排序(按照密码大小进行排序)冒泡排序*/
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
    printf("请输入人数:\n");
	int n;
    scanf("%d",&n);
    fflush(stdin);
    printf("请输入第一次用的密码:\n");
	int m;
    scanf("%d",&m);
    fflush(stdin);
    printf("对应人数的密码:\n");
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
