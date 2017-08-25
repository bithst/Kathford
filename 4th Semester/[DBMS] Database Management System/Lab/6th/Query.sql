USE lab

CREATE TABLE employee(
	ename VARCHAR(100) PRIMARY KEY,
	street VARCHAR(50),
	city VARCHAR(50)	
)

CREATE TABLE company(
	cname VARCHAR(100) PRIMARY KEY,
	city VARCHAR(50)
)

CREATE TABLE works(
	ename VARCHAR(100) REFERENCES employee(ename),
	cname VARCHAR(100) REFERENCES company(cname),
	salary float
)

CREATE TABLE manages(
	ename VARCHAR(100) REFERENCES employee(ename),
	mname VARCHAR(100) REFERENCES employee(ename)
)

-- 1
SELECT ename, count(*) FROM works GROUP BY ename HAVING count(*) >= 2

-- 2
SELECT cname FROM works WHERE salary IN (SELECT min(salary) FROM works)

-- 3
SELECT ename FROM works WHERE salary >= ALL (SELECT salary FROM works WHERE ename = 'rita')

-- 4
SELECT ename FROM employee WHERE city IN (SELECT city FROM employee WHERE ename = 'rita' OR ename = 'sita')

-- 5
SELECT mname, count(*) FROM manager GROUP BY mname

-- 6
SELECT city, count(*) FROM company GROUP BY city HAVING count(*) >= 20
