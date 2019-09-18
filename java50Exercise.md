## java经典50题##

***1. 题目：古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子对数为多少？***
  分析过程：第一个月 1对
            第二个月 1对
            第三个月 2对
            第四个月 3对
            第五个月 4对
            第六个月 6对
            第七个月 9对
            第八个月 13对
            第九个月 19对
            ...
   突破口：在算这个月多增加的兔子数的时候寻找三个月前兔子的数量，使用递归算法
   java代码实现
```java
     import java.io.InputStreamReader;
     import java.util.Scanner;
    public class TheOne {
    	public static int Input() {   //输入你所要求的月数(静态方法，用类名可以直接调用)
    		Scanner a=new Scanner(System.in);
    		int b=a.nextInt();
    		return b;
    	}
    	public int theNumberOfRabbit(int i){    //计算该月有多少对兔子
    		int s;
    		if(i>2){
    	         s=theNumberOfRabbit(i-1)+theNumberOfRabbit(i-3);//递归的调用
    		     return s;   }
    		else
    		return 1;
    	}
       public static void main(String[] args) {
    		// TODO Auto-generated method stub
    		TheOne a=new TheOne();
    		int b=Input();
    	    System.out.println(a.theNumberOfRabbit(b));	
    	    }
    }
```
**知识点：递归的调用，输入类Scanner的使用。**
**注意点：在这里第一个月和第二个月都只有一对兔子**
****
***2. 题目：判断101-200之间有多少个素数，并输出所有素数。***
   分析过程：素数的定义为只能被本身和1整除
   突破口：通过循环遍历来实现
           先使用方法来判断这个数是不是素数
java代码实现
```java
    public class TheTwo {
    	public boolean primerNumber(int b){   //判断一个数是不是素数
    		boolean a = true;
    		if(b==1)
    			return a;
    		else {
    		for(int i=2;i<b;i++){
    			if(b%i==0){
    				a=false;
    				break;   
    			   }
    		}
    		return a;
    	}
    }
    
    	public static void main(String[] args) {
    		// TODO Auto-generated method stub
    		TheTwo a=new TheTwo();
    		int s=0;
    		int b=0;
    		for(int i=101;i<=200;i++){
    			if(a.primerNumber(i)){
    				System.out.print(i);
    				System.out.print(" ");
    				b++;
    				if(b%5==0){       //每输出五个数换一行
    					System.out.println();
    				}
    				s=s+i;           //累加求和
    			}
    		}
    		System.out.println();
    		System.out.println("这些素数的和是"+s);
    	}
    }
```
**知识点：for循环的使用，如何判断一个数是不是素数**
****
***拓展：在键盘上任意输入两个数(均是大于零的整数)，通过程序按顺序输出相应的素数及其素数的和***
拓展java实现代码
```java
    import java.util.Scanner;
    public class numberTwo {
    	public boolean primerNumber(int b){   //判断一个数是不是素数
    		boolean a = true;
    		if(b==1)
    			return a;
    		else {  for(int i=2;i<b;i++){
    			if(b%i==0){
    				a=false;
    				break;   
    			   }
    		}
    		return a;
    	}
    }
    	public static int Input(){  //输入你所要求的两个数(静态方法，用类名可以直接调用)
    		Scanner a=new Scanner(System.in);
    		int b=a.nextInt();
    		return b;
    	}
    	public static void main(String[] args) {
    		int a=Input();
    		int b=Input();
    		numberTwo c=new numberTwo();
    		int s=0;
    		for(int i=a;i<=b;i++){
    			if(c.primerNumber(i)){
    				System.out.print(i);
    				System.out.print(" ");
    				b++;
    				if(b%5==0){      //每输出五个数换一行
    					System.out.println();
    				}
    				s=s+i;           //累加求和
    			}
    		}
    		System.out.println();
    		System.out.println("这些素数的和是"+s);
    
    	}
    }
```
****
**3. 题目：打印出所有的”水仙花数”，所谓”水仙花数”是指一个三位数，其各位数字立方和等于该数本身。例如：153是一个”水仙花数”，因为153=1的三次方+5的三次方+3的三次方**
     分析过程：实现要实现将一个三位数的个位十位百位分别求出来
               再将个位数的三次方、十位数的三次方、百位数的三次方相加
               最后验证这两个数是否相等
     突破口：如何提取出一个三位数的个位十位百位
            1）直接将这个数对10、100依次取余
            2）建立一个循环，对10取余后除以10
    java代码实现1：
```java
     public class TheThird {
    	//判断一个数是不是水仙花数
    	public boolean perfectNumber(int a){
    		boolean b=false;
    		int e,f,g,t,s;
    		/*
    		    想法一：已知一个数是三位数，直接按实例数来取余除数进行求解
    		*/
    		e=a/100;      //百位
    		f=a%100;
    		g=f/10;       //十位
    		t=f%10;       //个位
    		s=e*e*e+g*g*g+t*t*t;
    		if(a==s)
    			b=true;
    		return b;
    		
    	}
        
        	public static void main(String[] args) {
        		// TODO Auto-generated method stub
        		TheThird a=new TheThird();
        		int b=1,s=0;
        		for(int i=100;i<1000;i++){
        			if(a.perfectNumber(i)){
        				System.out.print(i);
        				System.out.print(" ");
        				b++;
        				if(b%5==0)
        					System.out.println();
        				s+=i;
        			}
        		}
        		System.out.println("三位数水仙花数的和为"+s);
        	}
        }
```
java代码实现2：
```java
    public class TheThirdTwo {
    	public boolean perfectNumber2(int b){    //判断一个数是不是水仙花数
    		boolean a=false;
    		int i=0,s=0;
    		int c=b;       //这里要保存b的，因为等下b会一直变化，不利于循环的控制
    		/*
    		        想法二： 先按个位、十位、百位依次取出
                                         个位3，153%10=3
                                         十位5,153/10=15,15%10=5
                                         百位1,15/10=1，1%10=1
    		*/
    		while(b>0){
    			i=b%10;
    			s=s+i*i*i;
    			b=b/10;
    		}
    		if(s==c)
    		   a=true;
    		return a;
    	}
    	public static void main(String[] args) {
    		// TODO Auto-generated method stub
    		TheThirdTwo a=new TheThirdTwo();
    		int b=1,s=0;
    		for(int i=100;i<1000;i++){
    			if(a.perfectNumber2(i)){
    				System.out.print(i);
    				System.out.print(" ");
    				b++;
    				if(b%5==0)
    					System.out.println();
    				s+=i;
    			}
    		}
    		System.out.println("三位数水仙花数的和为"+s);
    	}
    }
```


    







