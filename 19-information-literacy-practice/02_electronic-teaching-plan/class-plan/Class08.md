# 08 上课计划  
### 1.1 杂事       
- 发布雪梨任务      
- 进入雪梨同步课，加入方式有错误       
- 打开同步课，催促大家加入同步课     
- 虚拟机的雪梨作业不留了   
- 虚拟机安装成功的，可以按照PPT上的操作练练     




### 1.2 回顾上节课内容        
[Class07](./course-summary/Class07-20191014.txt)       
```
## 07       
1. VMware Workstation的安装      （安装软件）  
2. 安装tools                                   （安装软件）      
3. 虚拟机的应用——网络设置         （掌握）    
4. 虚拟机的应用——快照                （掌握）  
5. 虚拟机的应用——共享文件         （掌握）  
```

### 1.3 学生遇到问题     
1. office没有激活的找售后激活     
2. 虚拟机出问题了的，多尝试        
3. 注意作业的提交方式，不是提交附件，截图时直接截取控制台即可        



## 2 DOS    
### 2.1  DOS简介及基本知识           
#### 2.1.1 盘符、光标、目录、路径   
- **盘符**是DOS、WINDOWS系统对于磁盘存储设备的标识符   
- **光标**所谓光标，就是DOS窗口中用来标志输入字符位置的一个符号(或标志，这也就是光标这个词的来源)     
- **目录**就是桌面操作系统中的文件夹    
- **路径**是用户在磁盘上寻找文件时，所历经的目录线路，在dos路径中用\  但是参数中用 / 不可混淆         
#### 2.1.2 文件名、文件通配符、文件属性     
- 在DOS中，**文件名**的长度限制为8个字符的文件名和3个字符的扩展名。     
- **文件通配符**是为了让DOS命令便于批量处理DOS文件，而采用的一种文件名的符号替换方法。     
- **文件属性**文件的性质：文档属性、隐藏属性、系统文件属性、只读属性等    


#### 2.1.3 可执行文件    
- 可执行文件常见的有三类：EXE、COM和BAT（D盘）   
```shell
c:
cd \
dir >2.txt   #拒绝访问:因为只有管理员才能对C盘进行操作   
# 将一下三行复制到*.bat文件中 
d:
cd \
dir >2.txt  
```
**注意：**以上命令除了BAT在D盘演示，剩下的都在C盘       
### 2.2  DOS命令       
#### 2.2.1 目录操作    
>切换盘符命令X:    
```shell
d:
D:
```

>改变当前目录cd(change directory)       
```shell
dir /?
dir
cd Users
dir
cd YangWeibin    
dir
cd AppData   
cd \
# 相对路径
cd Users\YangWeibin\AppData
cd \  
# 相对路径
cd d:Users\YangWeibin\AppData     
cd \
# 绝对路径
cd d:\Users\YangWeibin\AppData     
cd ..
```
>建立子目录md(make directory)    
```shell
cd \
# 清屏
cls
md Student   
dir s* 
md d:\Users\YangWeibin\‘学号’ 
```
>删除子目录rd(remove directory)    
```shell
rd d:\Users\YangWeibin\‘学号’ 
dir
rd Student
# 目录不是空的。
rd /s Student
# Student, 是否确认(Y/N)? y
```
>显示磁盘目录dir(directory)    
```shell
cd \ 
cls 
dir
dir bin
dir Users  
dir d:/Users/YangWeibin # 无效开关 - "Users"。
# 因为在DOS命令中，路径用\,而/后面跟参数，对于一些不含参数的命令，这两个不加以区分，都是代表路径上分割目录的，但是对于带参数的命令，容易报错   
cd \
dir /p # 分屏 
dir /w # 仅显示文件或者[目录名]     
dir /a:d # 仅显示目录  
dir /o:d # 日期排序   
dir /o:s # 大小排序  
dir /s   # 显示目录及子目录，显示内容很长：Ctrl+c结束进程   
dir d:\Program" "Files /p /o:d /s # 路径上的空格需要用双引号，引起来  
```

#### 2.2.2 文件操作    
>复制文件命令copy      
```shell
d:
cd \
copy con test.txt # 将控制台（Console）内容复制到test.txt中  
My name is yang
My Id is 999
^Z # Ctrl + Z 结束   
copy test.txt Student    # 相对路径
copy d:\Student\test.txt d:\Users # 绝对路径    
copy con test1.txt
111
^Z
copy d:\*.txt d:\Student
# d:\test - 副本.txt
# d:\test.txt
# 覆盖 d:\Student\test.txt 吗? (Yes/No/All): Yes
# d:\test1.txt
# 已复制         3 个文件。  
cd Student 
copy d:\*.txt  # 目的路径可以不写，那么目的路径就是当前路径  
d:\test - 副本.txt
# 覆盖 d:\Student\test - 副本.txt 吗? (Yes/No/All): All
# d:\test.txt
# d:\test1.txt
# 已复制         3 个文件。  
dir >testclass.txt
```
>文件改名命令ren(rename)    
```shell
ren test1.txt 测试.txt     
```
>删除命令del(delete)    
```shell
cd ..
del test.txt
dir Student
del \Student\*.txt
```
>移动命令move    
```shell
move test1.txt Student
# 移动了         1 个文件。
```
>文件内容列表type    
```shell
type Student\test1.txt   

```
>文件属性命令attrib     
```shell
attrib Student\test1.txt
# A                    D:\Student\test1.txt
attrib +R Student\test1.txt  
attrib Student\test1.txt
# A    R               D:\Student\test1.txt
attrib -R +S Student\test1.txt
# A  S                 D:\Student\test1.txt   

attrib 1025.txt
# A   H                D:\1025.txt
D:\>attrib +S 1025.txt
# 未重置隐藏文件 - D:\1025.txt
# 组织——文件夹和搜索选项——查看”，然后勾选“显示隐藏的文件、文件夹和驱动器”选项，取消勾# 选“隐藏受保护的操作系统文件”选项，点击确定, 重置文件夹。
```

#### 2.2.3 其他操作      
>清屏 cls      
```shell
cls
```
>显示及修改日期date    
```shell
date 
# 当前日期: 2019/10/20 周日
# 输入新日期: (年月日) 2019/10/19
# 客户端没有所需的特权。(需要以管理员权限运行)
```
>格式化 format      
```shell
format 〈盘符：〉[/S][/4][/Q]   # 磁盘格式化命令（不予演示）
```
>ipconfig       
```shell
ipconfig /?  # 显示帮助信息
ipconfig /all
```

**注意：**以上命令都在D盘演示，因为C修改C盘的内容需要管理员权限       
#### 2.2.4 删除剩余txt   
```shell 
d:
del d:\Student\test1.txt
del d:\Users\test.txt
del d:\test.txt
```
## 3 课下作业   
- 雪梨同步课会及时发布    



 

 
















