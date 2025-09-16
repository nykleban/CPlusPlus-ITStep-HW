--1
select COUNT(*) AS MoreThan10 from Wards
where Places > 10;
--2
select d.Building, count(w.Id) as WardCount from Departments d
join Wards w on d.Id = w.DepartmentId
group by d.Building;
--3
select d.Name, count(w.Id) as WardCount from Departments d
join Wards w on d.Id = w.DepartmentId
group by d.Name;
--4
select d.Name, SUM(doc.Premium) as Nadbavka from Doctors doc
join DoctorsExaminations de on de.DoctorId = doc.Id
join Wards w on de.WardId = w.Id
join Departments d on d.Id = w.DepartmentId
group by d.Name
--5
select d.Name from Departments d
join Wards w on d.Id = w.DepartmentId
join DoctorsExaminations de on w.Id = de.WardId
group by d.Name
having count(distinct de.DoctorId) >= 5;
--6
select doc.Name, SUM(doc.Premium+doc.Salary) as NadbavkaAndSalary from Doctors doc
group by doc.Name
--7
select AVG(doc.Premium+doc.Salary) as AvgDochid from Doctors doc
--8
select w.Name as MinMiscia from Wards w
where w.Places = (select min(w.Places) from Wards w);
--9
select d.Building, d.Name from Departments d
join Wards w on d.Id = w.DepartmentId
where d.Building in (1,6,7,8) and w.Places>10
group by d.Building, d.Name
having sum(w.Places)>100;