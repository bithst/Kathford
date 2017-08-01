USE lab

-- Creating the table
CREATE TABLE Employee
(
	eid INT PRIMARY KEY,
	ename VARCHAR(100),
	address VARCHAR(100),
	salary FLOAT
)
SELECT * FROM Employee

INSERT INTO Employee VALUES(1, 'ashish', 'kathmandu', 15000)
INSERT INTO Employee VALUES(2, 'nam', 'butwal', 10000)
INSERT INTO Employee VALUES(3, 'parish', 'pokhara', 11000)
INSERT INTO Employee VALUES(4, 'sameer', 'kathmandu', 15000)
INSERT INTO Employee VALUES(5, 'srijal', 'kathmandu', 20000)
INSERT INTO Employee VALUES(6, 'neha', 'pokhara', 18000)
INSERT INTO Employee VALUES(7, 'ruxana', 'butwal', 12000)
INSERT INTO Employee VALUES(8, 'sushant', 'butwal', 18000)
INSERT INTO Employee VALUES(9, 'ram', 'pokhara', 15000)
INSERT INTO Employee VALUES(10, 'hari', 'kathmandu', 16000)
SELECT * FROM Employee

SELECT MIN(salary) AS minimum_salary FROM Employee

SELECT MAX(salary) AS maximum_salary FROM Employee

SELECT AVG(salary) AS average_salary FROM Employee

SELECT SUM(salary) AS total_salary FROM Employee

SELECT COUNT(*) AS total_employees FROM Employee
SELECT COUNT(DISTINCT ename) AS total_distinct_empname FROM Employee

SELECT address, MIN(salary) AS minimum_salary FROM Employee GROUP BY address

SELECT address, MAX(salary) AS maximum_salary FROM Employee GROUP BY address

SELECT address, AVG(salary) AS average_salary FROM Employee GROUP BY address

-- filter and then group
SELECT address, AVG(salary) AS average_salary FROM Employee WHERE address != 'butwal' GROUP BY address
-- group and then filter
SELECT address, AVG(salary) AS average_salary FROM Employee GROUP BY address HAVING address != 'butwal'

SELECT address, MAX(salary) AS maximum_salary FROM Employee WHERE salary > 15000 GROUP BY address

SELECT address, MAX(salary) AS maximum_salary FROM Employee GROUP BY address HAVING MAX(salary) > 15000

SELECT * FROM Employee