### Ghi nhớ
    mov ah, 1
Gán giá trị nhập vào từ bàn phím cho al.
    mov ah, 2
Xuất giá trị từ dl ra màn hình.
    
#### I. Nhóm thanh ghi đa dụng : (General Register)
a. Thanh ghi AX : (Auxliary Register)

    Công dụng riêng dùng trong các phép toán số học, lưu kết quả của các phép toán *, chia, ...

b. Thanh ghi BX : (Base Regiser)

    Dùng trong phép định địa chỉ cơ sở của bộ nhớ, nó đóng vai trò như 1 thanh ghi địa chỉ offset của bộ nhớ

c. Thanh ghi CX : (Count Regiser)

    Dùng để chứa số vòng lặp trong chương trình, nó đóng vai tròn như một biến đếm cho việc lặp vòng. Ngoài ra, thanh ghi
    CL còn được dùng trong các phép dịch chuyển với số lần dịch chuyển là nội dung của thanh ghi CL.

d. Thanh ghi DX : (Data Regiser)
    Dùng để lưu trữ kết quả của phép toán * hoặc /, định địa chỉ cổng trong các lệnh xuất nhập cổng.

#### II. Nhóm thanh ghi đoạn : (Segiment regiset)
a. Thanh ghi CS : (Code Segment)

    Dùng để chứa địa chỉ Segment của đoạn mã của đoạn mã chương trình.

b. Thanh ghi DS : (Data Segment)

    Chứa địa chỉ Segment của đoạn dữ liệu

c. Thanh ghi ES : (Extra Segment)

    Chứa địa chỉ Segment của đoạn dữ liệu bổ sung. Như vậy nếu ta có hai đoạn dữ liệu thì một sẽ do thanh ghi DS và hai sẽ do thanh ghi ES quản lý.

d. Thanh ghi SS (Stack Segment)

    Dùng lưu địa chỉ Segment của đoạn Stack. Bốn thanh ghi này có thể truy xuất trên bốn đoạn khác nhau. Như vậy một chương trình làm việc cùng một lúc tối đa là bốn đoạn

III. Nhóm thanh ghi con trỏ và chỉ mục :

a. Thanh ghi SI : (Source Index)

Dùng để trỏ đến ô nhớ trong đoạn dữ liệu định bởi thanh ghi
DS, trong xử lí chuỗi thanh ghi SI dùng để trỏ đến địa chỉ bắt
đầu của chuỗi nguồn

b. Thanh ghi DI : (Distination Index)

Dùng để trỏ đến ô nhớ có địa chỉ Segment định bởi thanh ghi
ES, trong xử lí chuỗi nó dùng để trỏ đến địa chỉ của chuỗi đích

c. Thanh ghi SP : (Stack pointer)

Dùng để trỏ đến phần tử ở trên đỉnh của Stack

d. Thanh ghi BP : (Base pointer)

Dùng trong phép định địa chỉ cơ sở, trong việc truy xuất
phần tử trên Stack. Nó được dùng trong các phép gọi chương
trình con

e. Thanh ghi IP : (Instruction Pointer)

Chứa đến địa chỉ ô nhớ được định bởi thanh ghi CS để chỉ
đến mã lệnh của chương trình. Khi thực thi một lệnh CPU sẽ tự
động thay đổi nội dung của thanh ghi IP để trỏ đến lệnh kế tiếp
của chương trình, thanh ghi này không bị tác động trực tiếp bởi
các lệnh. Vì vậy, nó thường không có mặt trong những lệnh của
hợp ngữ.

Những cặp thanh ghi thường đi chung :
DS : SI
ES : DI
SS : SP
SS : BP
CS : IP

IV. Thanh ghi cờ :

Mục đích của việc sử dụng cờ là việc chỉ ra trạng thái của CPU.
Để làm được điều đó bộ vi xử lí đã dành riêng ra một thanh ghi
gọi là thanh ghi cờ. Những bit trên thanh ghi này được gọi là các
cờ . Có hai loại cờ : Cờ trạng thái, cờ điều khiển
Cờ trạng thái phản ánh kết quả của phép toán
Cờ điều khiển dùng để cho phép hay không cho phép một thao tác
nào đó
Chúng ta chỉ quan tâm đến nhóm cờ trạng thái gồm 6 cờ là :
CF, AF, SF, OF, PF, ZF.

a. Cờ CF : (Carry Flag) " Cờ nhớ "

Cờ CF được bật lên một nếu kết quả của phép toán có mượn
hay có nhớ đối với bít cao

b. Cờ AF : (Awiliary Flag) " Cờ nhớ phụ "

Bật lên một khi có mượn hay có nhớ ở bít 3

c. Cờ SF : (Sign Flag) " Cờ dấu "

Cờ SF được bật lên một nếu như kết quả của một phép tính có
bít cao nhất bằng một (số âm)

d. Cờ OF : (Over Flag) " Cờ tràn "

Được bật lên một nếu như kết quả của phép toán có dấu bị sai
Ví dụ :
01010000 = AL (dương)
+ 01110000 = BL (dương)
11000000

e. Cờ PF : (Parity Flag) " Cờ chẵn le "

Cờ PF được bật lên một nếu như kết quả của một phép toán có
tổng 8 bít thấp là một số chẵn

f. Cờ ZF : (Zero Flag)

ZF = 1 nếu như kết quả của phép toán bằng không
Ví dụ :
AX = FFFFh
+
BX = FFFFh
1FFFEh
### Hết
