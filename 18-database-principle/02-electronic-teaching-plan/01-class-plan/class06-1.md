# 06-1 上课计划  
---
## 1 回顾上节课  
---
```05-2
## 05-2
1. 连接查询  
2. 等值连接  
3. 自然连接
4. 与连接相关的复合查询   
5. 自身连接
6. 多表连接 
```

## 2 学生问题   
1. 


## 3 本节课内容      
- 嵌套查询
### 3.1 嵌套查询概念    
- 一个select-from-where语句称为一个查询块   
- 将一个查询块嵌套在另一个查询块的WHERE子句或HAVING短语的条件中的查询称为嵌套查询   
- 子查询的限制   
	- 不能使用ORDER BY子句  
	- order by只能作用于最终的查询结果  
- 层层嵌套反映了SQL的结构化  
- 有些嵌套查询可以用连接运算代替   
- 不相关子查询条件不依赖于父查询  
	-  是由里向外逐层处理。即每个子查询在上一级查询处理之前求解，子查询的结果用于建立其父查询的查找条件。  
- 相关子查询的查询条件依赖于父查询    
	- 首先取外层查询中表的第一个元组，根据它与内层查询相关的属性值处理内层查询，若WHERE子句返回值为真，则取此元组放入结果表；   
	- 然后再取外层表的下一个元组；   
	- 重复这一过程，直至外层表全部检查完为止。  
### 3.2 带有in谓词的子查询  
```SQL
-- 查询与“刘晨”在同一个系学习的学生。  
select sdept
from student  
where sname = '刘晨‘;
-- 查找所有在CS系的学习的学生  
select sno,sname,sdept
from student
where sdept = 'CS';
```

- 构造嵌套查询  
	- 将第一步查询嵌入到第二部查询的条件中   
	- 此查询为不相关子查询   

```SQL
SELECT  Sno，Sname，Sdept
    FROM  Student
    WHERE  Sdept  IN
           (SELECT Sdept
            FROM Student
            WHERE Sname= '刘晨')；
```

- 查询选修了课程名为“信息系统”的学生学号和姓名。   
	- 首先在Course关系中找出“信息系统”的课程号，结果为3号  
	- 然后在SC关系中找出选修了3号课程的学生学号   
	- 最后在Student关系中取出Sno和Sname   
```sql
SELECT Sno，Sname
 FROM    Student
 WHERE Sno  IN
          (SELECT Sno
           FROM    SC
           WHERE  Cno IN
                  (SELECT Cno
                   FROM Course
                   WHERE Cname= ‘信息系统’));
```
### 3.3 带有比较运算符的子查询   
- 当能确切知道内层查询返回单值时，可用比较运算符（>，<，=，>=，<=，!=或< >）。    
- 与ANY或ALL谓词配合使用   
- 找出每个学生超过他选修课程平均成绩的课程号。  
```SQL
SELECT Sno,  Cno
    FROM  SC  x
    WHERE Grade >=
               (SELECT AVG(Grade) 
	    FROM  SC y
                WHERE y.Sno = x.Sno);
```

- 可能的执行过程   
	- S1:从外层查询中取出SC的一个元组x，将元组x的Sno值（201215121）传送给内层查询。   
	- S2:执行内层查询，得到值88（近似值），用该值代替内层查询，得到外层查询：   
	- S3：执行这个查询，得到：201215121，1和201215121，3   
	- S4：外层查询取出下一个元组重复做上述1至3步骤，直到外层的SC元组全部处理完毕。结果为:  

### 3.4 带有ANY或ALL谓词的子查询   
- 谓词的语义  
	- ANY：任意一个值   
	- ALL：所有值    
	- 需要配合使用的运算符   
- 查询其他系中比信息系任意一个(其中某一个)学生年龄小的学生姓名和年龄。   
```SQL
SELECT Sname，Sage
    FROM    Student
    WHERE Sage < ANY 
                   (SELECT  Sage
                    FROM    Student
                    WHERE Sdept= ' IS ')
                   AND Sdept <> ' IS ' ; 
                   /* 注意这是父查询块中的条件 */
```

### 3.5 带有EXISTS谓词的子查询   
- EXISTS谓词  
	- 存在量词    
	- 带有EXISTS谓词的子查询不返回任何数据，只产生逻辑真值“true”或逻辑假值“false”。   
		- 若内层查询结果非空，则外层的WHERE子句返回真值   
		- 若内层查询结果为空，则外层的WHERE子句返回假值   
	- 由EXISTS引出的子查询，其目标列表达式通常都用`*` ，因为带EXISTS的子查询只返回真值或假值，给出列名无实际意义    
- 查询所有选修了1号课程的学生姓名。   
	- 思路分析  
		- 本查询涉及Student和SC关系。   
		- 在Student中依次取每个元组的Sno值，用此值去检查SC关系。  
		- 若SC中存在这样的元组，其Sno值等于此Student.Sno值，并且其Cno= '1'，则取此Student.Sname送入结果关系。   
```SQL
SELECT Sname
FROM  Student
WHERE EXISTS
      (SELECT *
       FROM SC      /*相关子查询*/
       WHERE Sno=Student.Sno AND  Cno= '1')；
```

- NOT EXISTS谓词   	
	- 若内层查询结果非空，则外层的WHERE子句返回假值   
	- 若内层查询结果为空，则外层的WHERE子句返回真值  

- 查询没有选修1号课程的学生姓名   
```SQL
SELECT Sname
FROM Student
WHERE NOT EXISTS
      (SELECT *
       FROM SC
       WHERE Sno = Student.Sno  
                      AND Cno='1')；
```

- 不同形式的查询间的替换  
	- 一些带EXISTS或NOT EXISTS谓词的子查询不能被其他形式的子查询等价替换   
	- 所有带IN谓词、比较运算符、ANY和ALL谓词的子查询都能用带EXISTS谓词的子查询等价替换。  
- 查询与”刘晨“在同一个系学习的学生   
```SQL 
SELECT  Sno，Sname，Sdept
    FROM  Student
    WHERE  Sdept  IN
           (SELECT Sdept
            FROM Student
            WHERE Sname= '刘晨')；
            
-- 或者  
SELECT Sno，Sname，Sdept
FROM Student S1
WHERE EXISTS
    （SELECT *
      FROM Student S2
      WHERE S2.Sdept = S1.Sdept AND
            S2.Sname = '刘晨'；
```

- 用EXISTS/NOT EXISTS实现全称量词(难点)   
	- SQL语言中没有全称量词$ \forall$ （For all）   
	- 可以把带有全称量词的谓词转换为等价的带有存在量词的谓词：$$ ( \forall)P \equiv \lnot (\exist x (\lnot P))$$  
- 查询选修了全部课程的学生姓名  
```SQL
SELECT Sname
FROM Student
WHERE NOT EXISTS
      SELECT *
      FROM Course
      WHERE NOT EXISTS
            (SELECT *
             FROM SC
             WHERE Sno= Student.Sno  AND 
                   Cno= Course.Cno）；
```

- 用EXISTS/NOT EXISTS实现逻辑蕴函(难点)
	- SQL语言中没有蕴函(implication)逻辑运算  
	- 可以利用谓词演算将逻辑蕴函谓词等价转换为：$$ p \to q \equiv \lnot p \lor q$$






## 4 课下要求  
1. 课下给大家一个练习题，自己练习    
2. 遇到问题及时向学委反馈，我会根据课表时间答疑    




