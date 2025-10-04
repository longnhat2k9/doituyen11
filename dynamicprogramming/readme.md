# Problem List

## Bài 1: Dãy con tăng dài nhất (LIS)
Cho mảng số nguyên A[] có n phần tử. Tìm độ dài của đoạn con dài nhất tăng ngặt. Dãy con không bắt buộc phải liên tiếp

### Input Format
- Dòng đầu tiên là n
- Dòng thứ 2 gồm n phần tử của mảng A[]

### Constrains
- 1 &le; n &le; 1000
- 1 &le; A[i] &le; 1000 

### Output Format
In ra độ dài của dãy

### Sample Input 0
```
14
128 104 53 876 660 961 754 775 290 231 224 915 392 994
```

### Sample Output
```
6
```

## Bài 2: Bài toán xếp balo (01 Knapsack)

Một tên trộm có 1 cái túi có thể mang các đồ vật với trọng lượng tối đa là V. Hiện tại tên trộm muốn lựa chọn các đồ vật trong n đồ vật để ăn trộm, mỗi đồ vật có trọng lượng w[i], giá trị v[i]. Hãy xác đink tổng giá trị lớn nhất của các đồ vật mà tên trộm có thể lựa chọn để trọng lượng không vượt quá V.

### Input Format
- Dòng đầu ghi 2 số n và V
- Dòng tiếp theo ghi n số của mảng w
- Dòng cuối ghi n số của mảng v

### Constrain
- V &le; 1000
- n &le; 1000
- 1 &le; w[i], v[i] &le; 500

### Output Format
In ra giá trị lớn nhất có thể đạt được

### Sample Input 0
```
6 22
39 44 4 59 91 70
47 26 92 33 6 69
```

### Sample Output 0
```
92
```

## Bài 3: Tập con có tổng bằng S (Subset Sum)

Cho mảng số nguyên A[] gồm n phần tử và số nguyên dương s. Hãy xác định xem có thể tạo ra một tập con có tổng các phần tử S hay không? Mỗi phần tử chỉ sử dụng tối đa 1 lần.

### Input Format
- Dòng đầu gồm 2 số n và s.
- Dòng thứ 2 gồm n phần tử của mảng A[]

### Constrains
- 1 &le; n &le; 200
- 1 &le; s &le; 50000
- 1 &le; A[i] &le; 500

### Output Format
In ra 1 nếu có tập con của A có tổng bằng s, ngược lại in ra 0

### Sample Input 0
```
8 92
69 16 82 170 31 24 45 112
```

### Sample Output 0
```
1
```

# Solution List

|Problem|Solution|
|---|---|
|1|[lis.cpp](./lis.cpp)|
|2|[knapsack.cpp](./knapsack.cpp)|
|3|[subsum.cpp](./subsum.cpp)