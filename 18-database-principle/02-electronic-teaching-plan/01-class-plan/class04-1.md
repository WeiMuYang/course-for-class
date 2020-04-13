# 04-2 上课计划  
---
## 1 回顾上周  
---
```04-1
## 04-1
1. 基本表如何插入数据  
2. 数据库的备份和恢复    
3. 基本表的修改 
4. 简单查询  
```

## 2 学生问题   
1. 重修的雪梨任务    


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
- 基本用法  
```SQL
-- 选择两列  
select Sno,Sname
from Student;
-- 按表顺序显示
select *
from Student;
-- 算术运算及列名
select Sname,2020-Sage Birthday
from Student;
-- 调用函数
select count(Sname) 学生人数
from Student;
-- 添加字符串
select Sname,'2017'
from Student;
-- 取消重复
select distinct Sno
from SC；
```

- where条件   
```SQL
-- 比较大小
select Sname，Sage
from Student
where Sage < 20;

-- 确定范围 between ... and ...
select Sname
from Student
where Sage between 20 and 23;  
-- 确定集合 in / not in  
select Sname
from Student 
where Sdept in ('IS','MA','CS')；
-- 字符串匹配  
select Sname
from Student
where Sname like '刘%';
-- where Sname like '欧阳__';

-- 若包含转义字符一定要指明
select Cno, Cname
from Course
where Sname like 'DB\_Design' escape '\';
```

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
-- order by | asc  desc
select Sno, Grade 
from SC
where Cno = '3'
order by Grade desc;
-- order by Sdept,Sage desc;
```




## 4 课下要求  
1. 把select语句练习一遍  
2. **雪梨任务及时做 **  
3. 遇到问题及时向学委反馈，我会根据课表时间答疑    




