def partition(arry, low, high):
    i = low - 1
    pivot = arry[high]
    for j in range(low , high):
        if arry[j] <= pivot:
            i = i + 1
            arry[i], arry[j] = arry[j], arry[i]
    arry[i + 1], arry[high] = arry[high], arry[i + 1]
    return (i + 1)

def QuickSort(arry, low, high):
    if low < high:
        pi = partition(arry, low, high)
        QuickSort(arry, low, pi - 1)
        QuickSort(arry, pi + 1, high)

arr = [10, 3, 18, 9, 4, 7, 15]
n = len(arr)
QuickSort(arr, 0, n - 1)
print ("The Sorted array is: ")
for i in range(n):
    print ("%d" %arr[i]),
