def selectionSort(arr, n):
    for i in range(n-1):
        min_idx = i
        for j in range(i+1, n):
            if (arr[j]<arr[min_idx]):
                min_idx = j
        temp = arr[i]
        arr[i] = arr[min_idx]
        arr[min_idx] = temp

arr = [3, 8, 6, 10, 12, 16, 19, 2, 5]
n = len(arr)

selectionSort(arr, n)

print(arr)