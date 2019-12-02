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

--Thêm dữ liệu
--Desk
Insert into Desk(DeskID) values (1),(2),(3),(4),(5),(6),(7),(8),(9),(10),(11),(12),(13),(14),(15),(16),(17),(18),(19),(20)
--Menu
Insert into Menu(FoodName,Cost) values
('Saffron',10000),
('Caviar',34.5000),
('Oysters',60),
('White Truffle',330000),
('Iberico Ham',3500),
('Wagyu Beef',600),
('Kopi Luwak Coffee',700),
('Foie Gras',2500),
('Pho',1.5)
--BILL
Insert into BILL(DeskID) values (1,0),(2,0)
--ADDFOOD
Insert into ADDFOOD(FoodID,Quantity,DeskID,BillID) values
(5001,2,1,1000),
(5002,1,1,1000),
(5003,2,2,1001),
(5002,1,2,1001)



--Ví dụ về câu lệnh Select
--Hiển thị danh sách các bàn còn trống (Available = true)
use qlNhaHang
select DeskID,Available from Desk
where Available = 1
--Gọi món(insert vào table ADDFOOD)
Insert into ADDFOOD(FoodID,Quantity,DeskID,BillID) values
(5003,2,2,1001),
(5002,1,2,1001)
--Update trạng thái hóa đơn thành đã trả tiền
Update BILL
set Payment = 1
Where BillID = 1000 --Hóa đơn có BillID = 1000 sau khi đã trả tiền sẽ được update sang True(đã trả tiền)
--Xóa các BillID sau khi đã thanh toán 
--Ví dụ: Hóa đơn có BillID = 1000 đã thanh toán thì sẽ bị xóa
Delete from ADDFOOD
from BILL
where ADDFOOD.BillID = BILL.BillID AND BILL.Payment = 1
