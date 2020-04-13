# 07-1 上课计划  
---
## 1 回顾上节课  
---
```06-1
## 06-2
1. 带有EXISTS谓词的子查询 
2. 集合操作：并、交、叉
```

## 2 学生问题   
1. exercise练习题  
2. 答案做完的学生找我要   


## 3 本节课内容      
- 数据插入     
- 数据修改     
### 3.1 数据插入  
#### 3.1.1 插入元组  
```SQL
INSERT  
INTO <表名>  [(<属性列1>[，<属性列2 >…)]
VALUES (<常量1> [，<常量2>]    …           )
```

- 功能   
	- 将新的元组插入到指定表   
- into子句   
	- 指定要插入数据的表名及属性列   
	- 属性列的顺序可与表定义中的顺序不一致  
	- 没有指定属性列：表示要插入的是一条完整的元组，且属性列属性与表定义中的顺序一致  
	- 指定部分属性列：插入的元组在其余属性列上取空值  

- values子句   
	- 提供的值必须与into子句匹配   
		- 值的个数   
		- 值的类型  
```SQL
INSERT  INTO  Student  (Sno, Sname, Ssex, Sdept, Sage)
VALUES ('201215128'，'陈冬'，'男'，'IS'，18)；

INSERT  INTO  Student
VALUES ('201215126', '张成民', '男', 18, 'CS')；  
```
### 3.1.2  插入子查询   
```SQL
INSERT  INTO <表名>  [(<属性列1>[，<属性列2 >…)]
-- 子查询

CREATE  TABLE  Deptage
          (Sdept  CHAR(15) ,          /* 系名*/
           Avgage SMALLINT)；  /*学生平均年龄*/
           
INSERT  INTO  Deptage(Sdept，Avgage)
     SELECT  Sdept，AVG(Sage)   /**子查询*/
     FROM  Student
     GROUP BY Sdept；
```

## 3.2 修改数据   
```SQL
UPDATE  <表名>
SET  <列名>=<表达式>[，<列名>=<表达式>]…
[WHERE <条件>]；
```

- set子句   
	- 指定修改方式、要修改的列、修改后取值   
- where子句  
	- 指定修改元组，缺省表示要修改表中的所有元组  
- 功能  
	- 修改指定表中满足WHERE子句条件的元组    
```SQL
UPDATE   Student
SET    Sage = 22
WHERE   Sno=' 201215121 '； 


UPDATE   Student
SET   Sage= Sage+1;


UPDATE  SC
SET  Grade=0
WHERE  'CS'=
              (SELETE Sdept
               FROM  Student
               WHERE  Student.Sno = SC.Sno)；   
```
## 3.3 修改对完整性的影响   
- DBMS在执行修改语句时会检查修改操作是否破坏表上已定义的完整性规则   
	- 实体完整性   
		- 主码不允许修改  
	- 用户定义完整性   
		- NOT NULL约束  
		- UNIQUE约束  
		- 值域约束  
## 3.4 数据的删除  
```SQL  
DELETE
FROM   <表名>
[WHERE <条件>]；
```

- where子句  
	- 指定要删除的元组，缺省表示要删除表中的所有元组   
- 功能  
	- 删除指定表中满足WHERE子句条件的元组   
```SQL  
DELETE
FROM    Student
WHERE   Sno=' 201215128 '； 

DELETE
FROM    SC

DELETE
FROM    SC
WHERE  'CS' = 
               (SELECT Sdept
                 FROM student
                 WHERE student.Sno = SC.Sno) 
```

## 3.5 空值处理  
- 所谓空值就是“不知道”或“不存在”或无意义的值    
	- 空值的产生  
	- 空值的判断  
	- 空值的约束条件  
	- 空值的算术运算、比较运算和逻辑运算  
## 3.6 视图的定义  
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
CREATE  VIEW    <视图名>  [(<列名>  [，<列名>]…)]
AS  <子查询>
[WITH  CHECK  OPTION]；
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


## 4 课下要求  
1. 把练习题做了，谁做完了找我要答案       
2. 遇到问题及时向学委反馈，我会根据课表时间答疑    




