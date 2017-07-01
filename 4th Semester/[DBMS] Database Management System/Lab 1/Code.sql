CREATE DATABASE db_lab_1
USE db_lab_1

CREATE TABLE tbl_student
(
	sid int,
	sname varchar(50),
	roll int,
	class int,
	dob date,
	math foat,
	science float,
	english float
)

INSERT INTO tbl_student VALUES (1001, 'Namkong Hang Kirat', 01, 13, '2000-01-01', 92, 99, 40)
INSERT INTO tbl_student VALUES (1002, 'Ashish Shrestha', 02, 13, '2000-01-02', 66, 77, 88)
INSERT INTO tbl_student VALUES (1003, 'Parish Shrestha', 03, 13, '2000-01-03', 67, 76, 77)
INSERT INTO tbl_student VALUES (1004, 'Sameer Prajapati', 04, 10, '2000-01-04', 85, 91, 80)
INSERT INTO tbl_student VALUES (1005, 'Hari', 05, 10, '2000-01-01', 12, 34, 56)
INSERT INTO tbl_student(sid, sname) VALUES (1006, 'Ram')

SELECT * FROM tbl_student

SELECT * FROM tbl_student WHERE sid > 1002

SELECT * FROM tbl_student WHERE sid > 1002 AND sid < 1006

SELECT * FROM tbl_student WHERE class = 10

SELECT * FROM tbl_student WHERE sid != 1001
SELECT * FROM tbl_student WHERE sid <> 1001

SELECT * FROM tbl_student WHERE (math + science + english) > 80

SELECT *, (math + science + english) AS total FROM tbl_student

SELECT * FROM tbl_student WHERE math > 40 AND science > 40 AND english > 40

UPDATE tbl_student SET math = math * 1.15

UPDATE tbl_student SET sname = 'Rambo' WHERE sname = 'Ram'

UPDATE tbl_student SET math = math + 5 WHERE math < 40 AND math >= 35

DELETE FROM tbl_student WHERE sname = 'Rambo'

DELETE FROM tbl_student WHERE math < 40 OR science < 40 OR english < 40

DROP TABLE tbl_student