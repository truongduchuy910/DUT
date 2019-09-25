#### Khai báo
    Files ten_stack;
##### Push
_Thêm một phần tử vào đầu danh sách_
###### Khởi tạo dữ liệu
_Kiểu dữ liệu File được định nghĩa như sau_

    struct File
    {
        int value;
    };

_Nên ta khai báo_

    File du_lieu_can_them;
    du_lieu_can_them.value = gia_tri;

###### Đẩy dữ liệu vào stack
    ten_tack.push(du_lieu_can_them);

##### Truy cập dữ liệu
###### Lấy kích thước stack
_Kiểu trả về là int_

    ten_stack.length;

###### Truy cập đến phần tử thứ i
_Kiểu trả về là File_

    ten_stack[i];

###### Lấy giá trị của phần tử thứ i
_Kiểu trả về là int

    ten_stack[i].value;

