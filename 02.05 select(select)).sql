--1
select Name
from Departments
where Building = (
    select Building
    from Departments
    where Name = 'Cardiology'
)


--2

select Name
from Departments
where Building in (
    select Building
    from Departments
    where Name in ('Gastroenterology', 'General Surgery')
)
and Name not in ('Gastroenterology', 'General Surgery');

--3 

select top 1 D.Name
from Departments D
join Donations DN on D.Id = DN.DepartmentId
group by D.Name
order by sum(DN.Amount) asc;

--4 

select Surname
from Doctors
where Salary > (
    select Salary
    from Doctors
    where Name = 'Thomas' and Surname = 'Gerada'
);

--5 

select W.Name
from Wards W
where W.Places > (
    select avg(WR.Places)
    from Wards WR
    join Departments D on WR.DepartmentId = D.Id
    where D.Name = 'Microbiology'
);

--6

select Name + ' ' + Surname as FullName
from Doctors
where Salary + Premium > (
    select Salary + Premium + 100
    from Doctors
    where Name = 'Anthony' and Surname = 'Davis'
);

--7 

select distinct D.Name
from Doctors Doc
join DoctorsExaminations DE on Doc.Id = DE.DoctorId
join Wards W on DE.WardId = W.Id
join Departments D on W.DepartmentId = D.Id
where Doc.Name = 'Joshua' and Doc.Surname = 'Bell';

--8 

select S.Name
from Sponsors S
where S.Id not in (
    select SponsorId
    from Donations D
    join Departments Dept on D.DepartmentId = Dept.Id
    where Dept.Name in ('Neurology', 'Oncology')
);

--9 

select distinct Doc.Surname
from Doctors Doc
join DoctorsExaminations DE on Doc.Id = DE.DoctorId
where DE.StartTime >= '12:00' and DE.EndTime <= '15:00';
