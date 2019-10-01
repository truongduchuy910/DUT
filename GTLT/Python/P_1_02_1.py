def solve(n):
    data = [];
    for i in range(n):
        data.append(0)
    i = n - 1
    while i >= 0:
        if data[i] == 0:
            print(data)
            data[i] = 1
            for j in range(i + 1, n):
                data[j] = 0
            i = n - 1
        else: 
            i -= 1
    print(data)
solve(input("Input n: "))


