CREATE DATABASE lab
USE lab

CREATE TABLE Employee
(
	empid int primary key,
	empname varchar(100),
	post varchar(50),
	salary float,
	deptno int
)

INSERT INTO Employee VALUES(1, 'Ashish', 'HOD', 50000, 1)
INSERT INTO Employee VALUES(2, 'Parish', 'Lecturer', 20000, 1)
INSERT INTO Employee VALUES(3, 'Nam', 'Librarian', 20, 2)
INSERT INTO Employee VALUES(4, 'Sameer', 'Accountant', 10000, 3)
INSERT INTO Employee VALUES(5, 'Ram', 'Lecturer', 10000, 4)
SELECT * FROM Employee

UPDATE Employee SET salary = 50000 WHERE post = 'Lecturer'
SELECT * FROM Employee

SELECT empname, post FROM Employee

DELETE FROM Employee WHERE post = 'Librarian'
SELECT * FROM Employee

SELECT * FROM Employee ORDER BY salary ASC

SELECT * FROM Employee ORDER BY salary DESC

SELECT DISTINCT deptno FROM Employee

UPDATE Employee SET salary = salary * 1.25 WHERE post = 'Lecturer'
SELECT * FROM Employee

UPDATE Employee SET deptno = 17 WHERE empname = 'Ram'
SELECT * FROM Employee

DELETE FROM Employee WHERE salary < 20000
SELECT * FROM Employee

SELECT empname FROM Employee WHERE empname LIKE 'R%'

SELECT empname FROM Employee WHERE empname LIKE 'R%' OR empname LIKE 'A%'

SELECT empname FROM Employee WHERE empname LIKE 'R__'

SELECT empname FROM Employee WHERE empname LIKE '_a%'

SELECT empname FROM Employee WHERE empname LIKE '_[^a]%'