CREATE DATABASE db_std
USE db_std

CREATE TABLE Student
(
    id int primary key,
    name varchar(50),
    roll int,
    sem varchar(50),
    dob date
)

INSERT INTO Student VALUES (1, 'Nam', 22, 'Fourth', '2000-01-01')
INSERT INTO Student VALUES (2, 'Ashish', 05, 'Fourth', '2000-01-02')
INSERT INTO Student VALUES (3, 'Parish', 25, 'Fourth', '2000-01-03')
INSERT INTO Student VALUES (4, 'Sameer', 26, 'Third', '2000-01-04')
INSERT INTO Student VALUES (5, 'Srijal', 43, 'Third', '2000-01-05')
SELECT * FROM Student

INSERT INTO Student VALUES (1, 'Ram', 12, 'Third', '2000-01-01')
INSERT INTO Student VALUES (2, 'Hari', 13, 'Second', '2000-01-03')
SELECT * FROM Student

ALTER TABLE Student ADD math int, science int, english int
SELECT * FROM Student

UPDATE Student SET math = 70, science = 59, english = 90 WHERE id = 1
UPDATE Student SET math = 50, science = 60, english = 40 WHERE id = 2
UPDATE Student SET math = 00, science = 12, english = 39 WHERE id = 3
UPDATE Student SET math = 88, science = 65, english = 12 WHERE id = 4
UPDATE Student SET math = 12, science = 34, english = 56 WHERE id = 5
SELECT * FROM Student

ALTER TABLE Student DROP COLUMN dob
SELECT * FROM Student

ALTER TABLE Student ALTER COLUMN math float
ALTER TABLE Student ALTER COLUMN science float
ALTER TABLE Student ALTER COLUMN english float
UPDATE Student SET math = 69.89, science = 59.07, english = 90.5 WHERE id = 1
SELECT * FROM Student

DROP TABLE Student

USE master
DROP DATABASE db_std

SELECT * FROM Student