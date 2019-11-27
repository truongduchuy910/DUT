use qlNhaHang
create table Ban
(
   TableID nvarchar(10) primary key,
   Stt nvarchar(10) default('empty') --Status
)
create table Bill
(
   So_Bill nvarchar(10) primary key,
   TableID nvarchar(10),
   Xuat datetime null,
   Total money
)
create table Menu
(
   FoodID nvarchar(10) primary key,
   TenMon nvarchar(50) not null unique,
   Cost money not null
)
create table GoiMon
(
   Sott int primary key identity, --so tt
   FoodID nvarchar(10),
   SL int not null,
   TableID nvarchar(10),
   So_Bill nvarchar(10)
)
GO
alter table Bill
add
   constraint fk_Bill_Ban
   foreign key (TableID)
   references Ban(TableID)
GO
alter table GoiMon
add 
   constraint fk_Goi_Menu
   foreign key (FoodID)
   references Menu(FoodID),
   constraint fk_Goimon_Table
   foreign key (TableID)
   references Ban(TableID),
   constraint fk_Goimon_Bill
   foreign key (So_Bill)
   references Bill(So_Bill)

