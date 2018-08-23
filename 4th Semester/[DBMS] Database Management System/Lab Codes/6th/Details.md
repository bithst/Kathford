# Title
Nested Queries

# Objective
To be familiar with Nested Queries in SQL

# Problems
Given relational schema:
```
	employee(ename, street, city)
	works(ename, cname, salary)
	company(cname, city)
	manages(ename, mname)
```
1. Find the name of employees who work in more than two companies
2. Find the name of employee having minimum payroll
3. Display all record of `employee` who have `salary` greater than that of 'Rita'.
4. Display all record of `employee` whose `city` is that of 'Rita' or 'Sita'.
5. Find the total number of `employee` working under each `manager`.
6. Display all the `city` which have more than 1 `companies`.