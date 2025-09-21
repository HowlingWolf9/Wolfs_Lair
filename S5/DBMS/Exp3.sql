CREATE TABLE file_server (
    user_id INT,
    file_name VARCHAR(100),
    create_date DATE,
     PRIMARY KEY(user_id, file_name)
);

DESC file_server;

INSERT INTO file_server 
VALUES 
    (1, 'debug.txt' , '2024-06-01'),
    (1,'exp.txt','2024-07-01'),
    (1,'string.java','2024-07-10'),
    (2,'add.c','2024-08-01'), 
    (2,'sub.asm','2024-08-09'),
    (2,'sub2.Asm','2024-08-14'),
    (3,'even.c','2024-08-18'),
    (3,'fibonacci.c','2024-08-12'),
    (3,'Hello.txt','2024-08-27'),
    (3,'traffic.java','2024-08-09'),
    (4,'EMP.TXT','2024-08-21'),
    (4,'employee.txt','2024-08-19');

SELECT *
FROM file_server;

SELECT DISTINCT SUBSTRING_INDEX(file_name,'.',-1) 
AS 'Unique extensions'
FROM file_server;

SELECT 
    user_id,
    SUBSTRING_INDEX(file_name,'.',-1) AS 'Extension',
    COUNT(*) AS 'File Count'
FROM file_server
GROUP BY 
    user_id,
    Extension;

SELECT * 
FROM file_server
WHERE create_date
BETWEEN DATE_ADD('2024-08-15', INTERVAL -7 DAY)
AND DATE_ADD('2024-08-15', INTERVAL 7 DAY);

