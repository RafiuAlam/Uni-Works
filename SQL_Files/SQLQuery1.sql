create database BrensDenDB
use BrensDenDB

-------------------------------- ADMIN ----------------------------------------


CREATE TABLE admin (
    admin_id INT identity(0,1) PRIMARY KEY,
    admin_username VARCHAR(50) UNIQUE NOT NULL,
    admin_password VARCHAR(100) NOT NULL,
    admin_first_name VARCHAR(50) not null,
    admin_last_name VARCHAR(50) not null,
    admin_email VARCHAR(100) not null,
    admin_phone VARCHAR(20) not null
);

select * from Admin
--drop table Admin

-------------------------------- CUSTOMER ----------------------------------------

CREATE TABLE customer (
    cus_id INT identity(1000,1) PRIMARY KEY,
cus_user_name VARCHAR(50) not null,
    cus_first_name VARCHAR(50) not null,
    cus_last_name VARCHAR(50) not null,
    cus_email VARCHAR(100) UNIQUE not null,
    cus_phone VARCHAR(20) not null,
    cus_address VARCHAR(200) not null,
    cus_password varchar(50) not null,
    cus_image nvarchar(200) null
);

select * from customer
--drop table customer


-------------------------------- SELLER ----------------------------------------


CREATE TABLE SELLER (
    seller_id INT identity(3000,1) PRIMARY KEY,
    cus_id int foreign key references customer(cus_id) not null,
num_Of_pro int not null,
s_date datetime not null,
);

select * from SELLER
--drop table SELLER

-------------------------------- VISITOR ----------------------------------------

CREATE TABLE VISITOR (
    vis_id INT identity(5000,1) PRIMARY KEY,
vis_first_name VARCHAR(50) not null,
vis_last_name VARCHAR(50) not null,
vis_email VARCHAR(100) UNIQUE not null

);



select * from VISITOR
--drop table VISITOR


-------------------------------- APARTMENT ----------------------------------------


CREATE TABLE APARTMENT (
    ap_id INT identity(400,1) PRIMARY KEY not null,
IsActive bit DEFAULT 0,
    ap_location VARCHAR(100)  NULL,
    ap_building_name VARCHAR(100) null,
    ap_num_bedrooms VARCHAR(100) null,
    ap_num_bathrooms VARCHAR(100) null,
ap_num_parkings VARCHAR(100) null,
    ap_square_feet DECIMAL(10, 2) null,
    ap_rent_amount DECIMAL(10, 2) null,
ap_upload_type varchar(100) null,
    ap_image1 varchar(max) null,
ap_date datetime null,
ap_des  VARCHAR(100) null
);

select * from APARTMENT
--drop table APARTMENT



-------------------------------- PROPERTY ----------------------------------------


CREATE TABLE PROPERTY (
    pro_id INT identity(20200,1) PRIMARY KEY,
    pro_location VARCHAR(100) NOT NULL,
    pro_square_feet DECIMAL(10, 2) not null,
    pro_selling_amount DECIMAL(10, 2) not null,
    pro_is_sold VARCHAR(10) DEFAULT 'NO',
    seller_id int foreign key references seller(seller_id) not null,
pro_image1 nvarchar(100) null,
pro_image2 nvarchar(100) null,
pro_image3 nvarchar(100) null,
pro_image4 nvarchar(100) null,
pro_verified varchar(10) DEFAULT 'NO',
pro_date datetime not null,
);

select * from PROPERTY
--drop table PROPERTY

-------------------------------- Booking ----------------------------------------


CREATE TABLE renting (
    r_id INT identity(5000,1) PRIMARY KEY,
    cus_id INT foreign key references customer(cus_id) not null,
    ap_id INT foreign key references apartment(ap_id) not null,
    r_date DATE not null,
    check_in_date DATE not null,
    check_out_date DATE not null,
    total_amount DECIMAL(10, 2) not null
);

select * from renting
--drop table renting

--------------------------------  Transactions ----------------------------------------


CREATE TABLE transactions (
    transaction_id INT identity(6000,1) PRIMARY KEY,
    customer_id INT foreign key references customer(cus_id) not null,
    transaction_date date not null,
    tran_amount DECIMAL(10, 2) not null,
    transaction_type VARCHAR(50) not null,
    tran_description VARCHAR(200) not null
);

select * from transactions
--drop table Transactions

--------------------------------  wishlist ----------------------------------------


CREATE TABLE wishlist (
    wishlist_id INT identity(7000,1) PRIMARY KEY,
    customer_id INT foreign key references customer(cus_id) not null,
    apartment_id INT foreign key references apartment(ap_id) not null,
    added_date date null
);

SELECT * from wishlist
--drop table wishlist
--------------------------------  Review Host ----------------------------------------

CREATE TABLE review_host (
    review_id INT identity(8000,1) PRIMARY KEY,
cus_id INT foreign key references customer(cus_id) not null,
    visitor_id INT foreign key references visitor(vis_id) not null,
    rating INT not null,
    comment varchar(500)not null,
    review_date date null,
);

SELECT * from review_host
--drop table review_host


--------------------------------  Maintenance ----------------------------------------

CREATE TABLE maintenance (
    maintain_id INT identity(9000,1) PRIMARY KEY,
cus_id INT foreign key references customer(cus_id) not null,
    apartment_id INT foreign key references apartment(ap_id) not null,
    comment varchar(500)not null,
    maintain_date date null
);

SELECT * from maintenance
--drop table Maintenance

--------------------------------  notifications ----------------------------------------

CREATE TABLE notifications (
   notification_id INT identity(10000,1) PRIMARY KEY,
   sender int not null,
   receiver int not null,
   notification_text VARCHAR(500) not null,
   noti_status VARCHAR(100) null
);

SELECT * from notifications
--drop table notifications