# 06-2 上课计划  
---
## 1 回顾上节课  
---
```06-1
## 06-1
1. 带有in谓词的子查询  
2. 带有比较运算符的子查询  
3. 带有any(some)或all谓词的子查询
```

## 2 学生问题   
1. exercise数据库发到群里了  
2. 答案做完的学生找我要   


## 3 本节课内容      
- 嵌套查询
- 集合并交叉 
### 3.1 带有EXISTS谓词的子查询   
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
- 查询至少选修了学生201215122选修的全部课程的学生号码  
  - 用逻辑蕴函表达：查询学号为x的学生，对所有的课程y，只要201215122学生选修了课程y，则x也选修了y。   
  - 形式化表示：  
    - 用P表示谓词 “学生201215122选修了课程y”  
    - 用q表示谓词 “学生x选修了课程y”  
    - 则上述查询为: $(\forall y)p \to q$    
  - 等价变换：   
    - $ (\forall y)p \to q \equiv \lnot( \exist y(\lnot(p \to q))$   
    - $ \equiv \lnot (\exist y( \lnot(\lnot p \lor q))) $   
    - $  \equiv \exist y (p \land \lnot q)$  
	- 变换后语义：不存在这样的课程y，学生201215122选修了y，而学生x没有选。   
```sql
SELECT  DISTINCT Sno
FROM  SC SCX
WHERE NOT EXISTS
     (SELECT *
      FROM SC SCY
      WHERE SCY.Sno = ' 201215122 '  
      AND NOT EXISTS 
          (SELECT *
           FROM SC SCZ
           WHERE SCZ.Sno = SCX.Sno 
           AND SCZ.Cno=SCY.Cno))；
```

### 3.2 并操作   
- 形式  
```SQL
<查询块>
 UNION
<查询块>
```

- 参加UNION操作的各结果表的列数必须相同；对应项的数据类型也必须相同  
- UNION：将多个查询结果合并起来时，系统自动去掉重复元组。  
- UNION ALL：将多个查询结果合并起来时，保留重复元组   
- 查询计算机科学系的学生及年龄不大于19岁的学生。   
```SQL 
SELECT *
FROM Student
WHERE Sdept= 'CS'
UNION
SELECT *
FROM Student
WHERE Sage<=19；

SELECT  DISTINCT  *
FROM Student
WHERE Sdept= 'CS'  OR  Sage<=19；
```

### 3.3 交操作  
- 查询计算机科学系的学生与年龄不大于19岁的学生的交集(INTERSECT) 。   
```SQL
SELECT *
FROM Student
WHERE Sdept='CS' 
INTERSECT
SELECT *
FROM Student
WHERE Sage<=19 

SELECT *
FROM Student
WHERE Sdept= 'CS'
      AND Sage<=19；
```

### 3.4 差操作    
- 查询计算机科学系的学生与年龄不大于19岁的学生的差集。    
```SQL
SELECT *
FROM Student
WHERE Sdept='CS'
EXCEPT
SELECT  *
FROM Student
WHERE Sage <=19; 

SELECT *
FROM Student
WHERE Sdept= 'CS' 
      AND Sage>19；

```


- ORDER BY子句只能用于对最终查询结果排序，不能对中间结果排序  
- 任何情况下，ORDER BY子句只能出现在最后  
- 对集合操作结果排序时，ORDER BY子句中用数字指定排序属性  


## 4 课下要求  
1. 把练习题做了，谁做完了找我要答案       
2. 下周丁蕾蕾老师会给大家讲解一些重点题目  
3. 遇到问题及时向学委反馈，我会根据课表时间答疑    




