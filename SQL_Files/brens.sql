Create database brensdenDB
use brensdenDB

CREATE TABLE users(
    user_id INT identity(1000,1) PRIMARY KEY,
	user_name VARCHAR(50) not null,
    first_name VARCHAR(50) not null,
    last_name VARCHAR(50) not null,
    email VARCHAR(100) UNIQUE not null,
    phone VARCHAR(20) not null,
    address VARCHAR(200) not null,
    password varchar(50) not null,
    image nvarchar(200) null
);

select * from users
