# 05-2 上课计划  
---
## 1 回顾上节课  
---
```05-1
## 05-1
1. 空值查询  
2. 多重条件查询  
3. 排序
4. 聚集函数   
5. 分组查询  
```

## 2 学生问题   
1. 雪梨作业延期    
2. 重修的学生实验手册发到我的QQ邮箱(有学生没有发)    
3. 课程组要求，答疑放在课下，每周就是上课


## 3 本节课内容      
- 过PPT
- 连接查询  
- 嵌套查询
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

```SQL
-- 聚集函数的错误  
select sno, min(grade)
from sc;  -- error

select sno, grade
from sc 
where grade in(select min(grade)
               from sc)

-- 13.连接查询  
-- a. 等值连接  
select student.*, sc.*
from student, sc
where student.sno = sc.sno;

-- b. 自然连接  
select  sc.sno,  cno,  grade
from student, sc
where student.sno = sc.sno;

-- c. 连接和选择复合运算  
select student.sno, sname
from student, sc
where student.sno = sc.sno
      and sc.cno = '2'
      and sc.grade > 82;

-- d. 自身连接  
-- 课程的先修课的先修课  

select F.cno,  S.cpno
from course F,course S
where F.cpno = S.cno;

-- e.外连接  

select course.*, sno, grade
from course, sc
where course.cno = sc.cno;


select course.*, sno, grade
from course right outer join  sc
on course.cno = sc.cno;

-- f. 多表连接  
-- 学生的学号、姓名、课程名、成绩
select student.sno, sname, cname, grade 
from student,  course, sc 
where sc.cno = course.cno
      and student.sno = sc.sno
      
```




## 4 课下要求  
1. 课下给大家一个练习题，自己练习    
2. 遇到问题及时向学委反馈，我会根据课表时间答疑    




