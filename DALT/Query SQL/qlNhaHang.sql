use qlNhaHang
create table DESK
(
   DeskID int primary key,
   Available bit default('1')
)
create table BILL
(
   BillID int identity(1000,1) primary key,
   DeskID int,
   Payment bit default('0'),
   --payment kiểu true false để biết trạng thái thanh toán
   Total money
   -- total
)
create table MENU
(
   FoodID int identity(5000,1) primary key,
   --foodId
   FoodName nvarchar(50) not null unique,
   --name
   Cost money not null
)
create table ADDFOOD
(
   AddFoodID int primary key identity(1,1),
   FoodID int,
   Quantity int not null,
   DeskID int,
   BillID int
)
GO
alter table BILL
add
   constraint fk_Bill_Desk
   foreign key (DeskID)
   references Desk(DeskID)
GO
alter table ADDFOOD
add 
   constraint fk_AddFood_Menu
   foreign key (FoodID)
   references Menu(FoodID),
   constraint fk_AddFood_Desk
   foreign key (DeskID)
   references Desk(DeskID),
   constraint fk_Goimon_Bill
   foreign key (BillID)
   references Bill(BillID)

