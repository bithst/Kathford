USE db_kathford_lab

CREATE TABLE Student(
	id INT PRIMARY KEY,
	name VARCHAR(100),
	address VARCHAR(100),
	roll INT
)

INSERT INTO Student VALUES(1, 'Ashish', 'Madhyapur Thimi', 1)
INSERT INTO Student VALUES(2, 'Sameer', 'Madhyapur Thimi', 2)
INSERT INTO Student VALUES(3, 'Srijal', 'Sukedhara', 3)
INSERT INTO Student VALUES(4, 'Neha', 'Kadhaghari', 4)
INSERT INTO Student VALUES(5, 'Ruxana', 'Kalopul', 5)
INSERT INTO Student VALUES(6, 'Parish', 'Madhyapur Thimi', 6)
INSERT INTO Student VALUES(7, 'Ram', 'Kathmandu', 7)
INSERT INTO Student VALUES(8, 'Hari', 'Kathmandu', 8)

-- 1. Create a view to display all the record whose id is greater than 20.
CREATE VIEW vw_student AS SELECT * FROM Student WHERE id > 20
SELECT * FROM vw_student

-- 2. Insert one record from view.
INSERT INTO vw_student VALUES(15, 'NamKong', 'Kalopul', 23)
INSERT INTO vw_student VALUES(21, 'NamKong', 'Kalopul', 23)
INSERT INTO vw_student VALUES(22, 'Kritika', 'Asan', 24)

-- 3. Delete one record from view.
DELETE FROM vw_student WHERE id = 6
DELETE FROM vw_student WHERE id = 21

-- 4. Update one record from view.
UPDATE vw_student SET roll = 5 WHERE id = 1
UPDATE vw_student SET roll = 69 WHERE id = 22

-- 5. Create a trigger on Student that automatically displays the record when any record is inserted.
CREATE TRIGGER tg_display ON Student FOR INSERT AS
BEGIN
SELECT * FROM Student
END

-- 6. Create a stored procedure that displays student record for different address passed as argument.
CREATE PROCEDURE sp_display
@address VARCHAR(100)
AS
BEGIN
SELECT * FROM Student WHERE address = @address
END

EXECUTE sp_display @address = 'Kathmandu'

SELECT * FROM Student
