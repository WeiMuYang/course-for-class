--1��������Ϊfactory�����ݿ� 
create database factory
--2��������Ϊd_w��ģʽ
create schema d_w
--3����1���������ű�
create table d_w.department
(
  D_id char(9) primary key,
  D_name varchar(10) unique,
  Address varchar(20),
  D_num smallint,
  D_time datetime,
  MW_id char(12)
);
--3����2������Ա����
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
--4���޸Ĳ��ű����Ӳ���ְ���У�������Functionn����������ΪVarchar������50��
alter table d_w.department
add Functionn varchar(50)
--5���޸�Ա������Ա������W_name���������͸�ΪChar�ͣ�������ȻΪ10��
alter table d_w.worker
alter column W_name char(10)
--6����Ա�����W_name�д�����Ϊwor_name��Ψһ�ͽ���������
create unique index wor_name on d_w.worker(W_name desc)
--7���ڲ��ű��D_id�д�����Ϊdep_id�ľ۴���������������֮ǰû�о۴���������
create clustered index dep_id on d_w.department(D_id asc)
--8��ɾ��Ա����worker��
drop table d_w.worker

--ע�⣺MW_id������Ӧ������������֮�����޸ı�ķ������
alter table d_w.department
add foreign key (MW_id) references d_w.worker(W_id)
--ע�⣺7/8�����ⲻ��ִ�У���Ϊ7���о۴�������8���в��ű���մ˱�

