--1、创建名为factory的数据库 
create database factory
--2、创建名为d_w的模式
create schema d_w
--3、（1）创建部门表
create table d_w.department
(
  D_id char(9) primary key,
  D_name varchar(10) unique,
  Address varchar(20),
  D_num smallint,
  D_time datetime,
  MW_id char(12)
);
--3、（2）创建员工表
create table d_w.worker
(
  W_id char(12) primary key,
  D_id char(9),
  W_name varchar(10) not null,
  W_sex char(2),
  W_age smallint,
  W_address varchar(50),
  D_pid char(12),
  foreign key (D_id) references d_w.department,
  foreign key (D_pid) references d_w.worker
);
--4、修改部门表，增加部门职能列，列名：Functionn，数据类型为Varchar，长度50。
alter table d_w.department
add Functionn varchar(50)
--5、修改员工表，将员工姓名W_name的数据类型改为Char型，长度仍然为10。
alter table d_w.worker
alter column W_name char(10)
--6、在员工表的W_name列创建名为wor_name的唯一型降序索引。
create unique index wor_name on d_w.worker(W_name desc)
--7、在部门表的D_id列创建名为dep_id的聚簇升序索引（假如之前没有聚簇索引）。
create clustered index dep_id on d_w.department(D_id asc)
--8、删除员工表worker。
drop table d_w.worker

--注意：MW_id的外码应该在两个表建好之后用修改表的方法添加
alter table d_w.department
add foreign key (MW_id) references d_w.worker(W_id)
--注意：7/8两道题不能执行，因为7已有聚簇索引、8题有部门表参照此表。

