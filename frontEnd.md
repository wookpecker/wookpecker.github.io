#前端知识点总结

1.HTML的基本结构:
```html
                  <html>
                <head></head>
                  <body></body>
                 </html>
```
****

2.HTML的标签:  
```html
 - 2.1  <p></p>                       段落
 - 2.2  <hx></hx>                     添加标题
 - 2.3  <strong></strong>             斜体
 - 2.4  <em></em>                     加粗
 - 2.5  <span></span>                 为文字添加一些单独格式
 - 2.6  <q></q>                       引用短文本
 - 2.7  <blockquote></blockquote>     长文本引用
 - 2.8  <br/>                         换行符
 - 2.9  &nbsp                         为文本中添加空格
 - 3.0  <hr>                          为文本添加横线
 - 3.1  <address></address>           为文本中添加地址，字体默认为斜体
 - 3.2  <code></code>                 添加小段代码
 - 3.3  <pre></pre>                   添加大段代码
 - 3.4  <ul></ul>                     添加新闻信息列表（无序列表）
 - 3.5  <ol></ol>                     添加微博热搜排行榜（有序列表）
 - 3.6  <div></div>                   让代码在文本中分块显示
 - 3.7  <table></table>               在网页上添加表格
 - 3.8  <caption></caption>           为表格添加标题和摘要
 - 3.9  <a herf="网址"></a>               在网页中添加超链接
 - 4.0  <a herf="网址" target="_blank">文本</a> 在网页中添加超链接(打开新的浏览窗口)
 - 4.1  <a herf="mailto:邮箱地址？cc=抄送地址1;抄送地址2;抄送地址3;&subject=添加邮件主题&body=添加邮件内容">发送</a>      秘密便捷的向其他发送邮件
 - 4.2  <a herf="mailto:邮箱地址？bcc=密件抄送地址1;密件抄送地址2;&subject=添加邮件主题&body=添加邮件内容">发送</a>      秘密便捷的向其他发送密报
 - 4.3  <img src="图片地址" alt=""下载失败的显示文本 title="提示文本"/>    在网页中插入图片
 - 4.4  <form method="传送方式" action="服务器文件">  //使用表单标签，和用户交互
 - 4.5  <form><input type="text/password" name="名称" value="文本"></form>  文本输入框、密码输入框
 - 4.6  <form><textarea rows="列数" cols="行数">文本</textarea> </form>     添加一个可编辑多行的文本框
 - 4.7  <form><input type="radio/checkbox" value="值" name="名称" check="checked"></form>  单选框
 - 4.8  <form><input type="checkbox" value="值" name="名称" check="checked"></form>  复选框
 - 4.9  <section><option value="传给电脑的值" selected="selected">显示的文本</option> </section> 下拉列表
 - 5.0  <section multiple="multiple"><option value="传给电脑的值" selected="selected">显示的文本</option></section> 
 - 5.1  <input type="submit" value="提交">    提交按钮
 - 5.2  <input type="reset" value="重置">    重置按钮
 - 5.3  <label for="控件id名称">             表单控件
```
****

3.标签选择器:

```html
      html当中的标签，<p>,<body>,<h1>,<img>等等这些标签。
             语法:p{} h1{} img{} 
             例子:p{
                   color:red;
                   font-size:10px;
                   font-style:normal;
           }
```
****

4.类选择器:

```html
语法:<span class=”类选择器的名字”></span>
                .类选择器的名字{} 
           例子:<span class=”oneday”>
               .oneday{
                      color:green;
                      font-size:0.625rem;
                      ...
}
```
****

5.id选择器:

```html
语法:<span id=”id名称”>
               #id名称{}
    例子:<span id=”ideas”>
        #ideas{
                color:black;
                font-style:normal;
                   ...
      }
```

**类选择器和id选择器的区别**:

 - 类选择器能被运用多次
 - 标签选择器不能被多次运用，因为id不能一样
 ****

6.子选择器:

```html
语法:  . +子代选择器名字+>+父代选择器的名字{}(类选择器当中)
           例子:.food>oneday{
                            color:white;
                            font-size:1em;
}
```
****

7.后代选择器:
```html
语法:  .  +子代选择器名字+空格+父代选择器的名字{}(类选择器当中)
             例子:.food oneday{   
color:white;
                            font-size:1em;
}
```

**子选择器和后代选择器的区别**:

- 子选择器为指定的第一代后代
- 后代选择器为所有的后代选择器都设置
****

8.通用选择器: 
```html  
语法: *{}
               例子*{
                     color:blue;
}
```
****

9.伪选择符:
```html
a:hover{}
              <a herf=”网址”></a>
```
****
10.分组选择器:
```
h1,span{color:red;}
```
****
