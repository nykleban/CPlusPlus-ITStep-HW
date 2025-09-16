--1
select d.Name, d.Surname, s.Name from Doctors d
join DoctorsSpecializations ds on ds.DoctorId = d.Id
join Specializations s on s.Id = ds.SpecializationId
--2
select d.Surname, (d.Salary + d.Premium) as TotalSalary
from Doctors d
where d.Id not in (
    select v.DoctorId 
    from Vacations v 
    where getdate() between v.StartDate and v.EndDate)
--3
select w.Name from Wards w
join Departments d on w.DepartmentId = d.Id
where d.Name = 'Intensive Treatment'
--4
select distinct d.Name from Departments d
join Donations don on d.Id = don.DepartmentId
join Sponsors s on don.SponsorId = s.Id
where s.Name = 'Umbrella Corporation'
--5
select d.Name as Department, s.Name as Sponsor, don.Amount, don.Date from Donations don
join Departments d on don.DepartmentId = d.Id
join Sponsors s on don.SponsorId = s.Id
where don.Date >= GETDATE() - 30
--6
--неможливо, адже нема зв'язку або таблиці
--7
--неможливо, адже нема зв'язку або таблиці
--8
select distinct d.Name as Department, doc.Name as DoctorName, doc.Surname as DoctorSurname from Departments d
join Donations don on d.Id = don.DepartmentId
join Wards w on d.Id = w.DepartmentId
join Doctors doc on /* неможливо, адже нема зв'язку */
where don.Amount > 100000;
--9
select distinct d.Name from Departments d
join Wards w on d.Id = w.DepartmentId
join Doctors doc on /* неможливо, адже нема зв'язку */
where doc.Premium = 0 or doc.Premium is null;
--10
--неможливо, адже нема зв'язку або таблиці
--11
--неможливо, адже нема зв'язку або таблиці
--12
--неможливо, адже нема зв'язку або таблиці










