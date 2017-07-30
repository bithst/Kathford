USE lab

CREATE TABLE table1
(
	name VARCHAR(100),
	address VARCHAR(100)
)

CREATE TABLE table2
(
	name VARCHAR(100),
	address VARCHAR(100)
)

INSERT INTO table1 VALUES('ashish', 'bhaktapur')
INSERT INTO table1 VALUES('parish', 'bhaktapur')
INSERT INTO table1 VALUES('sameer', 'kahmandu')
INSERT INTO table1 VALUES('srijal', 'lalitpur')
INSERT INTO table1 VALUES('nam', 'kathmandu')
SELECT * FROM table1

INSERT INTO table2 VALUES('ashish', 'bhaktapur')
INSERT INTO table2 VALUES('parish', 'bhaktapur')
INSERT INTO table2 VALUES('neha', 'kathmandu')
INSERT INTO table2 VALUES('ruxana', 'pokhara')
INSERT INTO table2 VALUES('ram', 'butwal')
SELECT * FROM table2

-- SELECT * FROM table1 UNION ALL SELECT * FROM table2
SELECT * FROM table1 UNION SELECT * FROM table2

SELECT name FROM table1 UNION SELECT name FROM table2

SELECT name FROM table1 EXCEPT SELECT name FROM table2

SELECT COUNT(*) AS total_data FROM table1