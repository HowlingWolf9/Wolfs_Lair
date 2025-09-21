create table student(roll_no int, name varchar(25), class varchar(5), age int);
insert into student values(19, "athul", "CSA", 20);
select * from student;
describe student;
update student set name = "Athul" where name = "athul";
