# 07-2 上课计划  
---
## 1 回顾上节课  
---
```07-1
## 07-1
1. 数据插入 
2. 数据修改
3. 数据删除 
4. 空值处理
```

## 2 学生问题   
1. exercise练习题    
2. 插入多条数据   
3. 32)查询至多有两名男生的班级(帅绍康)   
  - 大家都先做一下,下节课讲   
  - 搜集一下比较难懂题目, 下周一前发给各班学委,再发给我    


## 3 本节课内容      
- 视图的创建与删除   
- 查询视图  
- 更新视图  
- 视图的作用       
### 3.1  视图定义   
- 视图的特点  
	- 虚表，是从一个或几个基本表（或视图）导出的表  
	- 只存放视图的定义，不会出现数据冗余  
	- 基表中的数据发生变化，从视图中查询出的数据也随之改变    
- 基于视图的操作  
	- 查询  
	- 删除  
	- 受限更新  
	- 定义基于该视图的新视图  
```SQL 
CREATE VIEW <视图名> [(<列名>  [，<列名>]…)]
AS <子查询>
[WITH CHECK OPTION]；
```

- 子查询不允许含有ORDER BY子句和DISTINCT短语  
- WITH CHECK OPTION    
	- 透过视图进行增删改操作时，不得破坏视图定义中的谓词条件（即子查询中的条件表达式）    
```SQL
-- 从单个基本表导出,只是去掉了基本表的某些行和某些列,保留了码————行列子集视图
CREATE VIEW IS_Student
AS 
SELECT  Sno, Sname, Sage
FROM    student
WHERE  Sdept= 'IS'
WITH CHECK OPTION  
```

- 建立信息系选修了1号课程的学生视图。  
```SQL  
CREATE VIEW  IS_S1(Sno，Sname，Grade)
AS 
SELECT Student.Sno，Sname，Grade
FROM  Student，SC
WHERE Student.Sno=SC.Sno  AND
               Sdept= 'IS' AND
                  SC.Cno= '1'；
```

- 建立信息系选修了1号课程且成绩在90分以上的学生视图。   
```SQL
CREATE VIEW IS_S2
AS
SELECT Sno，Sname，Grade
FROM  IS_S1
WHERE  Grade>=90；
```

- 将学生的学号及他的平均成绩定义为一个视图。    
```SQL
CREATE  VIEW S_G(Sno，Gavg)
AS  
SELECT  Sno，AVG(Grade)
FROM  SC
GROUP BY Sno；
```

### 3.2  删除视图      
```sql
DROP VIEW <视图名> [CASCADE]；
```

- 该语句从数据字典中删除指定的视图定义  
- 由该视图导出的其他视图定义仍在数据字典中，但已不能使用，必须显式删除  
- 删除基表时，由该基表导出的所有视图定义都必须显式删除  
- 如果CASCADE选项，则删除该视图时会把由它导出的视图一块删除    

### 3.3 查询视图  
- 从用户角度：查询视图与查询基本表相同  
- DBMS实现视图查询的方法  
	- 实体化视图（View Materialization）  
		- 有效性检查：检查所查询的视图是否存在   
		- 执行视图定义，将视图临时实体化，生成临时表  
		- 查询视图转换为查询临时表  
		- 查询完毕删除被实体化的视图(临时表)    
	- 视图消解法  
		- 进行有效性检查，检查查询的表、视图等是否存在。如果存在，则从数据字典中取出视图的定义  
		- 把视图定义中的子查询与用户的查询结合起来，转换成等价的对基本表的查询  
		- 执行修正后的查询  

- 在信息系学生的视图中找出年龄小于20岁的学生。  
```SQL
SELECT   Sno，Sage
FROM      IS_Student
WHERE   Sage<20；
```

- 视图消解法   
	- 转换后的查询语句为   
```SQL
SELECT  Sno，Sage       
FROM  Student
WHERE  Sdept= 'IS'  AND  Sage<20；
```

- 在S_G视图中查询平均成绩在90分以上的学生学号和平均成绩。  
```SQL
SELECT  *
FROM    S_G
WHERE  Gavg>=90；
-- 查询转换  
SELECT   Sno，AVG(Grade)
FROM      SC
GROUP BY  Sno；
HAVING   AVG(Grade)>=90；
```

### 3.3 更新视图  
- 用户角度：更新视图与更新基本表相同  
- DBMS实现视图更新的方法  
	- 视图实体化法（View Materialization）  
	- 视图消解法（View Resolution）  
- 指定WITH CHECK OPTION子句后  
	- DBMS在更新视图时会进行检查，防止用户通过视图对不属于视图范围内的基本表数据进行更新  
- 将信息系学生视图IS_Student中学号201215122的学生姓名改为“刘辰”   
```SQL
UPDATE  IS_Student
SET  Sname= '刘辰'
WHERE  Sno= '201215122'；  
-- 转换后的语句  
UPDATE  student
SET  Sname= '刘辰'
WHERE  Sno= ' 201215122 '  AND  Sdept = ‘IS’；
```

- 一些视图是不可更新的，因为对这些视图的更新不能唯一地有意义地转换成对相应基本表的更新(对两类方法均如此)   
- 视图S_G为不可更新视图。  
```SQL  
CREATE VIEW  S_G (Sno，Gavg)
AS 
SELECT  Sno，AVG(Grade)
FROM    SC
GROUP  BY  Sno；

-- 如下更新语句  
UPDATE  S_G
SET Gavg=90
WHERE  Sno= ‘201215121’；
-- 无论实体化法还是消解法都无法将其转换成对基本表SC的更新
```

### 3.4 视图作用  
- 视图能够简化用户的操作  
- 视图使用户能以多种角度看待同一数据  
- 视图对重构数据库提供了一定程度的逻辑独立性  
- 视图能够对机密数据提供安全保护  
- 适当的利用视图可以更清晰的表达查询  




## 4 课下要求  
1. 把练习题做了，谁做完了找我要答案       
2. 遇到问题及时向学委反馈，我会根据课表时间答疑    




