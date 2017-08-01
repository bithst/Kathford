USE lab

DROP TABLE Employee
DROP TABLE Company
DROP TABLE Works
DROP TABLE Manages

CREATE TABLE Employee
(
	ename VARCHAR(100) PRIMARY KEY,
	street VARCHAR(50),
	city VARCHAR(50)
)
CREATE TABLE Company
(
	cname VARCHAR(100) PRIMARY KEY,
	city VARCHAR(50)
)
CREATE TABLE Works
(
	ename VARCHAR(100) REFERENCES Employee(ename), -- ON DELETE CASCADE
	cname VARCHAR(100) REFERENCES Company(cname), -- ON DELETE CASCADE
	PRIMARY KEY(ename, cname), -- Makes these fields the primary key for the table
	salary FLOAT
)
CREATE TABLE Manages
(
	ename VARCHAR(100) REFERENCES Employee(ename) PRIMARY KEY, -- ON DELETE CASCADE
	managername VARCHAR(100) REFERENCES Employee(ename)
)

INSERT INTO Employee VALUES ('Namkong', 'Kalopul', 'Kathmandu')
INSERT INTO Employee VALUES ('Neha', 'Kadhaghari', 'Kathmandu')
INSERT INTO Employee VALUES ('Ram', 'Madhyapur Thimi', 'Bhaktapur')
INSERT INTO Employee VALUES ('Parish', 'Madhyapur Thimi', 'Bhaktapur')
INSERT INTO Employee VALUES ('Srijal', 'Sukedhara', 'Kathmandu')

INSERT INTO Company VALUES ('Kathford', 'Lalitpur')
INSERT INTO Company VALUES ('NCIT', 'Lalitpur')
INSERT INTO Company VALUES ('Khowpa', 'Bhaktapur')
INSERT INTO Company VALUES ('St. Xaviers', 'Kathmandu')
INSERT INTO Company VALUES ('KIST', 'Kathmandu')
INSERT INTO Company VALUES ('Small Bank Coorporation', 'Jhapa')

INSERT INTO Works VALUES ('Neha', 'Kathford', 20000)
INSERT INTO Works VALUES ('Ram', 'St. Xaviers', 20000)
INSERT INTO Works VALUES ('Ram', 'Kathford', 10000)
INSERT INTO Works VALUES ('Parish', 'Khowpa', 1500)
INSERT INTO Works VALUES ('Parish', 'Small Bank Coorporation', 1000)
INSERT INTO Works VALUES ('Srijal', 'KIST', 15000)
INSERT INTO Works VALUES ('Srijal', 'Kathford', 50000)
INSERT INTO Works VALUES ('Parish', 'NCIT', 1000)
INSERT INTO Works VALUES ('Neha', 'NCIT', 10000)

INSERT INTO Manages VALUES('Parish', 'Neha')
INSERT INTO Manages VALUES('Neha', 'Srijal')
INSERT INTO Manages VALUES('Ram', 'Neha')

SELECT ename FROM Works	-- Show all records that work in atleast one company. Includes repeated data.
SELECT Employee.ename FROM Employee JOIN Works ON Employee.ename = Works.ename	-- Still shows the repeated names.

SELECT ename FROM Employee EXCEPT SELECT ename FROM Works
SELECT Employee.ename FROM Employee LEFT OUTER JOIN Works ON Employee.ename = Works.ename WHERE Works.ename IS NULL

UPDATE Employee SET city = 'Kathmandu' WHERE ename = 'Ram'
UPDATE Employee SET street = 'Kalopul' WHERE ename = 'Ram'

SELECT E.ename FROM Employee E JOIN Works W ON E.ename = W.ename JOIN Company C ON W.cname = C.cname WHERE E.city = C.city

SELECT * FROM Employee
SELECT * FROM Company
SELECT * FROM Works
SELECT * FROM Manages