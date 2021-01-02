def binarySearch(arr, l, r, x):
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binarySearch(arr, l, mid - 1, x)
        else:
            return binarySearch(arr, mid + 1, r, x)
    else:
        return -1

arr = [1, 2, 3, 4, 5, 6]
x = 6
n = len(arr)

result = binarySearch(arr, 0, n-1, x)
if result == -1:
    print("Element is not present in array")
else:
    print("Element is present at index", result)
