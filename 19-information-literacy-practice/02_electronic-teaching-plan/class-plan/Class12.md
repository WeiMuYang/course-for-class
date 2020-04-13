# 12 上课计划  
### 1.1 杂事         
- 安装git      
- Markdown文档的PPT有误    
- 如何删除Github仓库   
- 安装Xmind   
- **本章节讲解不如就直接从克隆仓库，中间有各种Git命令操作，到最后提交push结束**    
- 详细看实验手册  

### 1.2 回顾上节课内容        
[Class11](../course-summary/Class11-20191111.txt)       
```
## 11          
1. Github和Git的基本介绍                   （了解）  
2. 注册Github账号                          （了解）   
3. 关注一些账号和项目                       （理解）   
4. 浏览以及新建Github仓库                   （理解、掌握）   
5. 在线编辑README.md文档以及删除Github仓库   （理解）   
6. git工具下载与安装并设置Git Bash环境       （了解）   
7. 简单的Git命令使用以及配置用户信息          （掌握）      
```

### 1.3 学生遇到问题     
1. 任务的问题   
2. 代码块和代码段  
3. 完整文件名，英文下的插入符号   


## 2 Git与Github        
### 2.2 Git工具       
1. 安装Git工具  
2. Git工具命令行  
```shell
git --help
```
3. 设置Git Bash环境及用户信息   

### 2.3 Git命令  
#### 2.3.1 仓库的初始化   
```shell
# 在当前目录新建一个 Git 代码库
git init

# 下载一个项目和它的整个代码历史
# url 格式: https://github.com/[userName]/reposName
git clone [url]
```
#### 2.3.2 新建文件添加暂存区     
1. 在一个仓库目录位置鼠标右击，选择`Git Bash Here`    
2. 在文件夹内新建一个文件`Demo1.py`，然后添加暂存区    
```shell
git add Demo1.py   Demo2.py 
```
**注意：**暂存区的文件左下角是红色的叹号    

#### 2.3.3 将文件由暂存区添加仓库       
```shell
git commit -m "添加Demo1"  
```
**注意：**添加仓库之后，文件的右下角是蓝色的对号    
#### 2.3.4 文件重命名      
```shell
git mv Demo1.py demo.py
```

#### 2.3.5 继续提交   
```shell
git commit -m "修改成demo.py"
```
**注意：**每次修改文件信息都要提交

#### 2.3.6 修改文件内容  
1. 在文件内容中添加如下代码：    
```python
print('hello world!')
```
2. 将修改好的文件继续提交：    
此处不能直接就提交暂存区，只这样写会出错   
```shell
git commit -m "修改demo"
```
必须先添加暂存区，再提交仓库   
```shell
# 先添加到暂存区
git add demo.py
# 提交到仓库  
git commit -m "修改demo"
```
**注意：**文件的左下角出现红色叹号有两种情况，一种是当你新创建文件放入仓库时，一种是当修改工作区文件时。   

#### 2.3.7 删除文件   
```shell
# 删除文件
git rm demo.py   
# 将删除文件信息提交仓库  
git commit -m "删除demo.py"
```
**注意：**进一步说明仓库存放的是文件的修改信息，并不是文件本身  

#### 2.3.8 找回文件   
1. 查看分支    
```shell
# 查看分支状态  
 git status
```
2. 查看历史版本   
```shell
# 查看历史版本  
git log
git log --oneline
# 7d4cf49 (HEAD -> master) 删除demo.py
# 9425f54 修改demo
# 5173654 修改成demo.py
# 5c7702e 添加Demo1
```
**注意：**越新提交的越靠前   
3. 根据备注信息回退到历史版本    
```shell
# 回退  
git reset --hard 9425f54 
```
**注意：**文件的状态已经改变      
4. 拣出仓库   
```shell
# 拣出仓库 
git checkout 9425f54
```

### 2.3 团队协作   
1. 创建组织    
2. 填写组织信息   
3. 邀请成员   
4. 继续填写组织信息   
5. 创建仓库   
6. 填写仓库信息   
7. 添加成员   
8. 设置成员权限   
9. 接收邀请   
10. 添加成功   
11. 开启协作之旅   


## 3 将代码段和代码块讲一下   



## 4 课下作业   
- 发布一次和Github有关的雪梨任务    




