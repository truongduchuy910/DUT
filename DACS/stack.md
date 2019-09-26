### Hướng Dẫn Sử Dụng Danh Sách Liên Kết
#### Khai báo
    List tên_List;
##### Định Dạng Dữ Liệu Cho Lớp List
Thêm đoạn mã vào ngay trước hàm main()

    struct Data
    {
        kiểu_dữ_liệu1 thuộc_tính1;
        kiểu_dữ_liệu2 thuộc_tính2;
        kiểu_dữ_liệu3 thuộc_tính3;
        ...        
    };
##### insertFirst: Thêm một đối tượng vào đầu danh sách
Tạo đối_tượng_mới

    Data đối_tượng_mới;

Ghi dữ liệu cho đối_tượng_mới

    đối_tượng_mới.thuộc_tính1 = giá_trị;
    đối_tượng_mới.thuộc_tính2 = giá_trị;
    đối_tượng_mới.thuộc_tính3 = giá_trị;

Đẩy đối_tượng_mới vào Lớp tên_List

    tên_List.insertFirst(đối_tượng_mới);

##### insertLast: Thêm một đối tượng cuối danh sách
Tạo đối_tượng_mới

    Data đối_tượng_mới;

Ghi dữ liệu cho đối_tượng_mới

    đối_tượng_mới.thuộc_tính1 = giá_trị;
    đối_tượng_mới.thuộc_tính2 = giá_trị;
    đối_tượng_mới.thuộc_tính3 = giá_trị;

Đẩy đối_tượng_mới vào Lớp tên_List

    tên_List.insertLast(đối_tượng_mới);

##### tên_List[vị_trí] : Lấy dữ liệu của đối tượng tại vị_trí
Lưu ý kiểu trả về là Data

    tên_List[vị_trí];
    //Kiểu dữ liệu của biến trên là Data
