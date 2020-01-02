# Hướng dẫn sử dụng lớp Polynomial

## Tổng quan

Lớp `Polynomial` giúp khai báo các biến để sử dụng như một đa thức. Gồm các thao tác như nhập xuất bằng std::cin, std::cout, các phép toán cơ bản,...

## Chi tiết

### Các hàm sử dụng chung

    Polynomial();
    ~Polynomial();
    bool set(const int, const double);
    double operator[](int) const;
    int getSize() const;
    Polynomial &operator=(const Polynomial &);

### `Polynomial();`

### `~Polynomial();`

### `bool set(const int, const double);`

### `double operator[](int) const;`

### `int getSize() const;`

### `Polynomial &operator=(const Polynomial &);`

### Các hàm bạn

    friend ostream &operator<<(ostream &, const Polynomial &);
    friend istream &operator>>(istream &, Polynomial &);
    friend Polynomial operator+(const Polynomial &, const Polynomial &);
    friend Polynomial operator-(const Polynomial &, const Polynomial &);
    friend Polynomial operator*(const Polynomial &, const Polynomial &);
    friend Polynomial operator/(const Polynomial &, const Polynomial &);
    friend Polynomial operator%(const Polynomial &, const Polynomial &);

### `friend ostream &operator<<(ostream &, const Polynomial &);`

### `friend istream &operator>>(istream &, Polynomial &);`

### `friend Polynomial operator+(const Polynomial &, const Polynomial &);`

### `friend Polynomial operator-(const Polynomial &, const Polynomial &);`

### `friend Polynomial operator*(const Polynomial &, const Polynomial &);`

### `friend Polynomial operator/(const Polynomial &, const Polynomial &);`

### `friend Polynomial operator%(const Polynomial &, const Polynomial &);`

### Các hàm không cho phép truy xuất

    Term *position(const int);
    bool isEmpty();

#### `Term *position(const int);`

Tìm và trả về địa chỉ của Nút có bậc bằng với tham số truyền vào. Nếu không có thì trả về `NULL`

### Các biến dữ liệu

    Term *start;
    int size;

#### `Term *start`;

Dùng để lưu địa chỉ của Nút bắt đầu. Có giá trị `NULL` nếu danh sách là rỗng.

#### `int size`;

Dùng để lưu số phần tử của danh sách.
