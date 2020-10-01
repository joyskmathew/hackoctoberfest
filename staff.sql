create table staff(
    staff_name text[20] not null,
    staff_id varchar[4] primary key not null,
    department text[2] not null,
    age integer  check(age>25 and age<75) not null
);

insert into staff(staff_name,staff_id,department,age) values("Arun","A101","CS",30);
insert into staff(staff_name,staff_id,department,age) values("Ajesh","A201","IT",50);
insert into staff(staff_name,staff_id,department,age) values("Anil","A403","EC",45);
insert into staff(staff_name,staff_id,department,age) values("Sunil","A901","EE",58);
insert into staff(staff_name,staff_id,department,age) values("Aji","A501","CS",34);
insert into staff(staff_name,staff_id,department,age) values("Harish","A106","ME",33);

alter table staff add column DOB date;
update staff set dob="1990-05-24" where staff_id="A101";
update staff set dob="1970-04-14" where staff_id="A201";
update staff set dob="1960-05-20" where staff_id="A403";
update staff set dob="1962-01-26" where staff_id="A901";
update staff set dob="1986-07-04" where staff_id="A501";
update staff set dob="1987-09-24" where staff_id="A106";

update staff set age=60 where staff_id="A403";

select * from staff where department="CS";

delete from staff where age<35;

select staff_id,staff_name from staff order by age desc;

select staff_name as name,staff_id,department as dept,age from staff;

select staff_name,department from staff where department="EC" or department="ME";

select avg(age) from staff;

select upper(staff_name),lower(department) from staff;

update staff set age=age+1;

select * from staff;