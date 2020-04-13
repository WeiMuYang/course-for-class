--创建Library数据库
create database Library
--切换Library为当前数据库
use Library
--在当前数据库中创建表
create table book
(
  bno char(6) primary key,
  cno char(10) not null,
  bname char(20) not null,
  bauthor char(10),
  bpress varchar(30),
  bprice numeric(6,2)
);
create table reader
(
  rno char(4) primary key,
  rdepartment char(10) not null,
  rname char(10) not null,
  rsex char(2),
  rtitle char(8),
  raddress varchar(20)
);
create table borrow
(
  bno char(6),
  rno char(4),
  bdate date,
  primary key (bno,rno,bdate),
  foreign key (bno) references book(bno),
  foreign key (rno) references reader(rno)
 );
--输入数据
--book表数据
insert into book 
values('445501','TP3/12','数据库导论','王强','科学出版社',17.90)
insert into book 
values('445502','TP3/12','数据库导论','王强','科学出版社',17.90)
insert into book 
values('445503','TP3/12','数据库导论','王强','科学出版社',17.90)
insert into book 
values('332211','TP5/10','计算机基础','李伟','高等教育出版社',18.00)
insert into book 
values('112266','TP3/12','FoxBASE','张三','电子工业出版社',23.60)
insert into book 
values('665544','TS7/21','高等数学','刘明','高等教育出版社',20.00)
insert into book 
values('114455','TR95/12','线性代数','孙业','北京大学出版社',20.80)
insert into book 
values('113388','TR7/90','大学英语','胡玲','清华大学出版社',12.50)
insert into book 
values('446601','TP4/13','数据库基础','马凌云','人民邮电出版社',22.50)
insert into book 
values('446602','TP4/13','数据库基础','马凌云','人民邮电出版社',22.50)
insert into book 
values('446603','TP4/13','数据库基础','马凌云','人民邮电出版社',22.50)
insert into book 
values('449901','TP4/14','FoxPro大全','周虹','科学出版社',32.70)
insert into book 
values('449902','TP4/14','FoxPro大全','周虹','科学出版社',32.70)
insert into book 
values('118801','TP4/15','计算机网络','黄力钧','高等教育出版社',21.80)
insert into book 
values('118802','TP4/15','计算机网络','黄力钧','高等教育出版社',21.80)
--reader表数据
insert into reader
values('111','信息系','王维利','女','教授','1号楼424')
insert into reader
values('112','财会系','李立','男','副教授','2号楼316')
insert into reader
values('113','经济系','张三','男','讲师','3号楼105')
insert into reader
values('114','信息系','周华发','男','讲师','1号楼316')
insert into reader
values('115','信息系','赵正义','男','工程师','1号楼224')
insert into reader
values('116','信息系','李明','男','副教授','1号楼318')
insert into reader
values('117','计算机系','李小峰','男','助教','1号楼214')
insert into reader
values('118','计算机系','许鹏飞','男','助工','1号楼216')
insert into reader
values('119','计算机系','刘大龙','男','教授','1号楼318')
insert into reader
values('120','国际贸易','李雪','男','副教授','4号楼506')
insert into reader
values('121','国际贸易','李爽','女','讲师','4号楼510')
insert into reader
values('122','国际贸易','王纯','女','讲师','4号楼512')
insert into reader
values('123','财会系','沈小霞','女','助教','2号楼202')
insert into reader
values('124','财会系','朱海','男','讲师','2号楼210')
insert into reader
values('125','财会系','马英明','男','副教授','2号楼212')

--borrow表数据
insert into borrow(rno,bno,bdate)
values('112','445501','1997-03-19')
insert into borrow(rno,bno,bdate)
values('125','332211','1997-02-12')
insert into borrow(rno,bno,bdate)
values('111','445503','1997-08-21')
insert into borrow(rno,bno,bdate)
values('112','112266','1997-03-14')
insert into borrow(rno,bno,bdate)
values('112','449901','1997-03-14')
insert into borrow(rno,bno,bdate)
values('114','665544','1997-10-21')
insert into borrow(rno,bno,bdate)
values('120','114455','1997-11-02')
insert into borrow(rno,bno,bdate)
values('120','118801','1997-10-18')
insert into borrow(rno,bno,bdate)
values('119','446603','1997-12-12')
insert into borrow(rno,bno,bdate)
values('112','445501','1997-10-23')
insert into borrow(rno,bno,bdate)
values('115','449902','1997-08-21')
insert into borrow(rno,bno,bdate)
values('118','118801','1997-09-10')


--完整备份后，在book表中插入新数据

insert into book 
values('446604','TP311/561','Python计算与编码实践','王江平','机械工业出版社',69.00)
insert into book 
values('446605','TP311/561','Python计算与编码实践','王江平','机械工业出版社',69.00)
insert into book 
values('446606','TP311/561','Python计算与编码实践','王江平','机械工业出版社',69.00)
--删除数据库Library
use master
drop database Library
--利用完整备份+差异备份进行数据恢复

--差异备份后，在book表中插入新数据
use Library
insert into book 
values('446607','TP311/579','计算机组成原理','蒋本珊','清华大学出版社',36.00)
insert into book 
values('446608','TP311/579','计算机组成原理','蒋本珊','清华大学出版社',36.00)
insert into book 
values('446609','TP311/590','计算机组成与结构','袁春风','清华大学出版社',43.00)
insert into book 
values('446610','TP311/590','计算机组成与结构','袁春风','清华大学出版社',43.00)

--进行事务日志备份

--删除book表中数据
delete from book where bno='446605'
delete from book where bno='446606'

--进行事务日志备份


--利用完整备份+差异备份+事务日志备份还原数据库