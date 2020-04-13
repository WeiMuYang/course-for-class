--����Library���ݿ�
create database Library
--�л�LibraryΪ��ǰ���ݿ�
use Library
--�ڵ�ǰ���ݿ��д�����
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
--��������
--book������
insert into book 
values('445501','TP3/12','���ݿ⵼��','��ǿ','��ѧ������',17.90)
insert into book 
values('445502','TP3/12','���ݿ⵼��','��ǿ','��ѧ������',17.90)
insert into book 
values('445503','TP3/12','���ݿ⵼��','��ǿ','��ѧ������',17.90)
insert into book 
values('332211','TP5/10','���������','��ΰ','�ߵȽ���������',18.00)
insert into book 
values('112266','TP3/12','FoxBASE','����','���ӹ�ҵ������',23.60)
insert into book 
values('665544','TS7/21','�ߵ���ѧ','����','�ߵȽ���������',20.00)
insert into book 
values('114455','TR95/12','���Դ���','��ҵ','������ѧ������',20.80)
insert into book 
values('113388','TR7/90','��ѧӢ��','����','�廪��ѧ������',12.50)
insert into book 
values('446601','TP4/13','���ݿ����','������','�����ʵ������',22.50)
insert into book 
values('446602','TP4/13','���ݿ����','������','�����ʵ������',22.50)
insert into book 
values('446603','TP4/13','���ݿ����','������','�����ʵ������',22.50)
insert into book 
values('449901','TP4/14','FoxPro��ȫ','�ܺ�','��ѧ������',32.70)
insert into book 
values('449902','TP4/14','FoxPro��ȫ','�ܺ�','��ѧ������',32.70)
insert into book 
values('118801','TP4/15','���������','������','�ߵȽ���������',21.80)
insert into book 
values('118802','TP4/15','���������','������','�ߵȽ���������',21.80)
--reader������
insert into reader
values('111','��Ϣϵ','��ά��','Ů','����','1��¥424')
insert into reader
values('112','�ƻ�ϵ','����','��','������','2��¥316')
insert into reader
values('113','����ϵ','����','��','��ʦ','3��¥105')
insert into reader
values('114','��Ϣϵ','�ܻ���','��','��ʦ','1��¥316')
insert into reader
values('115','��Ϣϵ','������','��','����ʦ','1��¥224')
insert into reader
values('116','��Ϣϵ','����','��','������','1��¥318')
insert into reader
values('117','�����ϵ','��С��','��','����','1��¥214')
insert into reader
values('118','�����ϵ','������','��','����','1��¥216')
insert into reader
values('119','�����ϵ','������','��','����','1��¥318')
insert into reader
values('120','����ó��','��ѩ','��','������','4��¥506')
insert into reader
values('121','����ó��','��ˬ','Ů','��ʦ','4��¥510')
insert into reader
values('122','����ó��','����','Ů','��ʦ','4��¥512')
insert into reader
values('123','�ƻ�ϵ','��Сϼ','Ů','����','2��¥202')
insert into reader
values('124','�ƻ�ϵ','�캣','��','��ʦ','2��¥210')
insert into reader
values('125','�ƻ�ϵ','��Ӣ��','��','������','2��¥212')

--borrow������
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


--�������ݺ���book���в���������

insert into book 
values('446604','TP311/561','Python���������ʵ��','����ƽ','��е��ҵ������',69.00)
insert into book 
values('446605','TP311/561','Python���������ʵ��','����ƽ','��е��ҵ������',69.00)
insert into book 
values('446606','TP311/561','Python���������ʵ��','����ƽ','��е��ҵ������',69.00)
--ɾ�����ݿ�Library
use master
drop database Library
--������������+���챸�ݽ������ݻָ�

--���챸�ݺ���book���в���������
use Library
insert into book 
values('446607','TP311/579','��������ԭ��','����ɺ','�廪��ѧ������',36.00)
insert into book 
values('446608','TP311/579','��������ԭ��','����ɺ','�廪��ѧ������',36.00)
insert into book 
values('446609','TP311/590','����������ṹ','Ԭ����','�廪��ѧ������',43.00)
insert into book 
values('446610','TP311/590','����������ṹ','Ԭ����','�廪��ѧ������',43.00)

--����������־����

--ɾ��book��������
delete from book where bno='446605'
delete from book where bno='446606'

--����������־����


--������������+���챸��+������־���ݻ�ԭ���ݿ�