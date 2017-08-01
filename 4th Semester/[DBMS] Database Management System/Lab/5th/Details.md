# Title
Basic data constratints and joins

# Objective
To be familiar with primary and foreign key constraints and various join operation

# Problem
Consider the following relational schemas:  
```
	Employee(ename_, street, city)
	Company(cname_, city)
	Works(ename_, cname_, salary)
	Manages(ename_, managername)
```
Write SQL statements for:
1. Create above relational schema and link them by primary key and foreign key.
2. Insert any five records in each relation.
3. Find the name of employee who works in atleast one company.
4. Find the name of all employees who aren't appointed to any company.
5. Modify the database so that 'Ram' now lives in 'Kathmandu'.
6. Delete all tuple in 'Work' relation for empoyee of 'Small Bank Corporation'.
7. Find the name of employe in database who live in same city as the company for which they work.
8. Find the company with smallest payroll.
9. Find the total no. of employees working under each manager.
10. Find the name of employees who work in atleast two companies.