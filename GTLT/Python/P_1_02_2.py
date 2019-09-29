def solve(n, k):
    data = [];
    for value in range(n):
        data.append(value + 1)
    i = k - 1
    while i >= 0:
        max_value = n - k + i + 1
        if data[i] < max_value:
            print(data[:k])
            data[i] += 1
            for j in range(i + 1, n):
                data[j] = data[j - 1] + 1
            i = k - 1
        else:
            i -= 1
    print(data[:k])

n = int(input("n: "))
k = int(input("k: "))
solve(n,k)
