### <font color="#2f3640">实验四&emsp;树及其应用——二叉树的遍历</font>

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;2019.10.24

#### <font color="#273c75">需求分析</font>

##### <font color="#40739e">问题描述</font>
很多涉及二叉树操作的算法都是以二叉树遍历为基础的。本实验要求编写程序，对一棵给定的二叉树进行先、中、后三种次序的遍历。


##### <font color="#40739e">基本要求</font>
以二叉链表为存储结构，实现二叉树的先、中、后三种次序的递归遍历。


#### <font color="#273c75">项目设计</font>

##### <font color="#40739e">数据结构</font>
二叉树


##### <font color="#40739e">设计思路</font>
<img src="https://raw.githubusercontent.com/wookpecker/images/master/recursion.JPG" width="600" />
```
void creatTree(TreeNode &root){
	char input;
	cin>>input;
	//递归基
	if(input=='#'){
		root=NULL;
	}else{
//	  TreeNode root;//此处不需要在重新定义，否则树就会变成一个个节点，之间无联系
	  root=(Node *)malloc(sizeof(Node));
	  root->data=input;
	  //创建左子树
	  creatTree(root->lclird);
	  //创建右子树
	  creatTree(root->rclird);
	}
}
```
$\color{red}{非递归实现遍历：}$
<img src="https://raw.githubusercontent.com/wookpecker/images/master/binaryTree.PNG" width="600" />
```
/*非递归遍历(先序迭代遍历)*/
void PreIteatorOrder(TreeNode T){
	if(T==NULL){
		return;
	}else{
		stack<TreeNode> S;
		//先把根节点放进栈中
		S.push(T);
		while(!S.empty()){
		    //从栈中取出节点，输出该节点的数据
			TreeNode temp=S.top();
			cout<<temp->data<<" ";
			S.pop();
			if(temp->rclird){
			    //如果有右子树，则右子树入栈
				S.push(temp->rclird);
			}
			if(temp->lclird){
			    //如果有左子树，则左子树入栈
				S.push(temp->lclird);
			}
		}
	}	
} 
```

<img src="https://raw.githubusercontent.com/wookpecker/images/master/Stack.JPG" width="700" />
**操作步骤：①先把根节点放进栈中**
**$\qquad$$\qquad$②从栈中取出节点，输出该节点的数据**
**$\qquad$$\qquad$③如果有右子树，则右子树入栈，如果有左子树，则左子树入栈**
**$\qquad$$\qquad$④直到栈为空一直执行操作$\color{red}{②③}$**


```
/*非递归遍历(中序迭代遍历)*/
void MidIteatorOrder(TreeNode T){
	if(T==NULL){
		return;
	}else{
		stack<TreeNode> S;
//		S.push(T);
		TreeNode temp=T; 		
		
		while(!S.empty() || temp){
			//访问树的最左端的节点，入栈 
		while(temp!=NULL){
				S.push(temp);
				temp=temp->lclird;
		}
//			if(temp->rclird==NULL){
//				temp=S.top();
//			    cout<<temp->data<<" ";
//			    S.pop();
//			}
			//访问树的最左端的节点，出栈 
			temp=S.top();
			cout<<temp->data<<" ";
			S.pop();
			
			//访问右子树 
//			if(temp->rclird!=NULL){
//				S.push(temp->rclird);
				temp=temp->rclird;
//				continue;
//			}
//			temp=S.top();
		}
	}	
}
```
<img src="https://raw.githubusercontent.com/wookpecker/images/master/Middle.JPG" width="700" />
**操作步骤：①先把根节点放进栈中**
**$\qquad$$\qquad$②把左子树的左节点都放入栈中**
**$\qquad$$\qquad$③从栈中取出节点，输出数据，把该节点置为该节点的右节点**
**$\qquad$$\qquad$④直到栈为空一直执行操作且节点为空$\color{red}{②③}$**
```
/*非递归遍历(后序迭代遍历)(双栈实现)*/
void BackIteatorOrder(TreeNode T){
	if(T==NULL){
		return;
	}else{
		stack<TreeNode> first;
		stack<TreeNode> last;
		TreeNode temp=T;
		first.push(temp);
		while(!first.empty()){
			temp=first.top();
			if(temp->lclird!=NULL&&temp->rclird!=NULL){
				first.pop();
				first.push(temp->lclird);
				first.push(temp->rclird);
				last.push(temp);
			}
			if(temp->lclird==NULL&&temp->rclird==NULL){
				first.pop();
				last.push(temp);
			}
			if(temp->lclird!=NULL&&temp->rclird==NULL){
			    first.pop();
				first.push(temp->lclird);
				last.push(temp);	
			}
			if(temp->lclird==NULL&&temp->rclird!=NULL){
			    first.pop();
				first.push(temp->rclird);
				last.push(temp);	
			}
		}
		while(!last.empty()){
			temp=last.top();
			cout<<temp->data<<" ";
			last.pop();
		}
	}
} 
```
<img src="https://raw.githubusercontent.com/wookpecker/images/master/first.JPG" width="600" />
<img src="https://raw.githubusercontent.com/wookpecker/images/master/two.JPG" width="600" />

```
/*非递归遍历(层序遍历)*/
void levelOrder(TreeNode T){
	TreeNode temp;
	temp=T;
	queue<TreeNode> level;
	//先把根节点放进队列中
	level.push(temp);
	while(!level.empty()){
	    //从队列中取出节点，输出该节点的数据
		temp=level.front();
		cout<<temp->data<<" ";
		level.pop();
		if(temp->lclird){
		    //如果有左子树，则左子树入栈
			level.push(temp->lclird);
		}
		if(temp->rclird){
		    //如果有右子树，则右子树入栈
			level.push(temp->rclird);
		}
	}
} 
```
<img src="https://raw.githubusercontent.com/wookpecker/images/master/Queue.JPG" width="700" />
**操作步骤：①先把根节点放进队列中**
**$\qquad$$\qquad$②从队列中取出节点，输出该节点的数据**
**$\qquad$$\qquad$③如果有左子树，则左子树入栈，如果有右子树，则右子树入栈**
**$\qquad$$\qquad$④直到栈为空一直执行操作$\color{red}{②③}$**

#### <font color="#273c75">测试结果</font>

- 测试一
<img src="https://raw.githubusercontent.com/wookpecker/images/master/test.JPG" width="700" />



#### <font color="#273c75">总结分析</font>

##### <font color="#40739e">回顾</font>
①:在先序迭代遍历时先进右子树时和层序遍历先进左子树时搞混，后来才明白栈先进后出，队列先进先出
②:中序遍历时，直接将节点指针置为该节点的右子树
##### <font color="#40739e">时间复杂度</font>
生成递归树：O($n^2$)$\implies$层序输入法(队列)
层序遍历：O(n)
迭代遍历：O(n)
##### <font color="#40739e">空间复杂度</font>
存储一个栈或者队列的空间


##### <font color="#40739e">经验和体会</font>
**①多层递归的使用，要注意递归要能结束**
**②栈："先进后出"  队列："先进先出"**
**③迭代遍历时要先进右节点，层序遍历要先进左节点**
**④创建二叉树时，依次创建每个二叉树节点，所以传参时，依次传入每个节点的指针**
**⑤中序迭代遍历时，每遍历依次节点后，无论有无右节点，都将下一次遍历的节点指针指向右节点**










