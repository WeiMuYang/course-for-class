# 05-1 上课计划  
---
## 1 回顾上周  
---
```04-1
## 04-2
1. select 简单查询  
2. where 条件的使用  
3. 范围、集合
4. 字符串、转义字符 
```

## 2 学生问题   
1. 虚拟机使用失败  
	- 重装虚拟机，再装SQLserver   
2. 转义字符  
	- 而C中定义了一些字母前加"\"来表示常见的那些不能显示的ASCII字符，如\0,\t,\n等，就称为转义字符，因为后面的字符，都不是它本来的ASCII字符意思了，\为换码字符，可以将通配符转义。       
3. 雪梨作业进不去  
	- 换个浏览器试试     
4. 重修的学生实验手册发到我的QQ邮箱    


## 3 本节课内容      
- 数据查询  
- 实际操作
### 3.1 数据查询    
- 基本语法   
```
select [all|distinct] <目标列表达式> [，<目标列表达式>] ...
from <表名或视图名> [，<表名或视图名>]...
[where <条件表达式>]
[group by <列名> [,<列名>]]...
[having <内部函数表达式>]
[order by <列名> [asc|desc][，<列名>[asc|desc]]...]
```

- 子句功能  
	- select子句与from子句是必选子句  
	- select：列出查询的结果  
	- from：指明所访问的对象  
	- where：指定查询条件   
	- group by：将查询的结果按指定的字段取值分组  
	- having：筛选出满足条件的组  
	- order by：按指定字段的值，以升序降序排列查询结果    
### 3.2 单表查询  


- 空值查询(IS NULL)   
```SQL
select Sno, Cno
from SC 
where Grade is null;
```

- 多重条件查询  
```SQL
select Sname
from Student
where Sdept = 'CS' and Sage < 20;
```

- 排序  
```sql
select sno, grade
from sc
where cno = '3'
order by grade desc;

select sno, grade
from sc
where cno = '1'
order by grade  desc;

select *
from student 
order by sdept, sage desc;
```

- 11. 聚集函数   
```sql

select COUNT(  sno)
from sc;

select AVG(grade)
from sc
where cno = '1';

select SUM(ccredit)
from sc, course
where sno = '200215121' and sc.cno = course.cno;

select max(grade)
from sc;

select *
from sc
where grade > AVG(grade);
```

- 12. 分组查询  
```sql
select cno , COUNT(sno) 选课人数
from sc
group by cno;

select sno
from sc
where  COUNT(*) >=2   -- error
group by sno
```


## 4 课下要求  
1. 课下给大家一个练习题，自己练习    
2. 遇到问题及时向学委反馈，我会根据课表时间答疑    




