use qlNhaHang
create table Ban
(
   TableID nvarchar(10) primary key,
   --tableId lấy làm số bàn luôn
   Stt nvarchar(10) default('empty')
   --Status
   --availale kiểu true false
)
create table Bill
(
   So_Bill nvarchar(10) primary key,
   --billId
   TableID nvarchar(10),
   Xuat datetime null,
   --payment kiểu true false để biết trạng thái thanh toán
   Total money
   -- total
)
create table Menu
(
   FoodID nvarchar(10) primary key,
   --foodId
   TenMon nvarchar(50) not null unique,
   --name
   Cost money not null
)
create table GoiMon
(
   Sott int primary key identity,
   --so tt
   FoodID nvarchar(10),
   SL int not null,
   --quantity
   TableID nvarchar(10),
   --tableId
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

