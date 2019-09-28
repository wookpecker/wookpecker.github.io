# Git的使用
**版本控制系统都只能跟踪文件的改动**
1. 首先要自报名号，姓名和邮箱地址

```
    //下载Git后，找到GitBash打开
    //在$后面输入 
                $git config --global user.name "your name"
                $git config --global user.email "email address"
```

使用完git config --global命令后，电脑的Git都会按这个配置
****
2.然后找一个合适的目录来放文件
```
     //创建一个空目录比较合适
     //在$后面输入
                $mkdir testname
                $cd testname
```

创建目录完可以查找一下是否完成创建

```
    $pwd
    //可以查找当前目录下的文件夹名字
```
****
3.把创建好的文件夹变成Git能管理的文件夹
```
    $git init
```
****
4.把要添加的文件放在刚刚创建的文件中，一定要是刚刚创建的最后一个子目录，复制粘贴过去就可以
****
接下来要把文件放在Git仓库中

5.把文件添加到仓库

```
    $git add 文件名
    //写文件名时记得加后缀
```
****
6.把文件提交到仓库

```
    $git commit -m"写自己修改的一些内容的概括"
```
****
7.查看最近自己的仓库是否被修改
```
    $cd 文件夹名字
    $ls
    //查看文件夹里面的文件
    $git status
    //查看是否被修改
    $git diff
    //如果已经被修改，查看被修改的内容
```
****
8.查看提交的历史记录
```
    $git log
    //这时系统就会显示出提交的版本
    //如果遇到退不出的时候直接按Q就可以退出
    $git log--pretty=oneline
    //这时显示出来的就言简意赅，但是就是看不懂什么意思了
```
****
9.想要退回原来的某个版本
HEAD代表的是当前版本
HEAD^代表的是前一个版本或者后一个版本
HEAD^^代表的是前两个版本或者后两个版本

那么如何恢复到原来的那个版本呢？
```
    $git reset --hard HEAD^
    //回到前一个版本
    $git cat 文件名
    //一次显示整个文件
    $git relog
    //来查看commit id
    $git reset --id HEAD
    //这个可以让文件回到未来
```
****
10.想要撤销文件的修改操作怎么办

```
    $git checkout --文件名
    //撤销上一步操作
    $git reset HEAD<file>
    //撤销提交到缓存区的上一步操作
```
****
11.想要删除文件
```
   //提交一个新的文件把原来的文件覆盖
   $git rm 文件名
   //删除该文件
```
****
12.首先要创建SSH Key
```
    //打开GitBash软件，在上面输入下列的内容
    //下面的youremail@example.com为邮箱地址
    $ssh-kengen -t rsa -C "youremail@eample.com"
    //接下来在主目录下找到.ssh文件，里面有id_rsa和id_rsa.pub两个文件
    //上述两个文件即为SSH Key的秘钥对，id_rsa为私有id_rsa.pub为公有
    //然后进入github账户创建github账户并且登入，创建仓库
    //然后找到AccountSetting里的“SSH Keys”页面：然后，点“Add SSH      
    //Key”,填上任意Title，在Key文本框里粘贴id_rsa.pub文件的内容
```
****
13.把这些文件从仓库中传到远程仓库，就必须要和远程仓库产生关联，所以先关联远程仓库

```
    $git remote add origin git@github.com:wookpecker/文件名
    //上述wookpecker应该为自己的github账号名字
```
****
14.接下来我们要把内容推送到master分支上
第一次推送时
```
    $git push -u origin master
    //第一次推送要加上-u
    $git push origin master
    //以后每一次继续上传时只需要通过这个命令来上传
```
****
15.从远程仓库上克隆文件
```
    $git clone git @github.com:wookpecker/文件名
    //文件名为要克隆的文件名
    $Cloning into '文件夹名称'...
    //此处文件夹名字为本地的文件夹名字
```
****



