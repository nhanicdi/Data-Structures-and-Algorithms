def bubbleSort(arr, n):
    for i in range(n-1):
        for j in range(n-1-i):
            if arr[j] > arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp

arr = [3, 8, 7, 6, 2, 5, 3, 19, 9, 10]
n = len(arr)

bubbleSort(arr, n)

for i in range(n-1):
    print(arr[i])