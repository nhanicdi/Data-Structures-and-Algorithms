def select(arr, i):
    min_idx = i
    for j in range(0, i):
        if(arr[j] < arr[min_idx]):
            min_idx = j
    return min_idx

def selectionSort(arr):
    n = len(arr)
    for i in range(n-1,0, -1):
        j = select(arr,i)

        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp

arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
selectionSort(arr)
print(arr)