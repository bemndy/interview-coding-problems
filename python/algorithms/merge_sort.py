def merge_sort(arr, i, r):
    ''' 
    Sorts an array in ascending order using the merge sort algorithm.
    Time Complexity: O(n log n) 
    Args:
        arr (list): The list of elements to be sorted.
    '''
    if i>= r:
        return arr
    j = (i + r) // 2
    merge_sort(arr, i, j)
    merge_sort(arr, j + 1, r)
    merge(arr, i, j, r)

    return arr

def merge(arr, i, j, r):
    # Merge two sorted subarrays
    left = arr[i:j + 1]
    right = arr[j + 1: r + 1]
    k = i
    while left and right:
        if left[0] <= right[0]:
            arr[k] = left.pop(0)
        else:
            arr[k] = right.pop(0)
        k += 1
    while left:
        arr[k] = left.pop(0)
        k += 1
    while right:
        arr[k] = right.pop(0)
        k += 1

    return arr

def main():
    # Example usage
    arr = [12, 11, 13, 5, 6]
    sorted_arr = merge_sort(arr, 0, len(arr) - 1)
    print("Sorted array is:", sorted_arr)
    arr_doubled = [12, 11, 13, 5, 6, 12, 11, 13, 5, 6]
    sorted_arr_doubled = merge_sort(arr_doubled, 0, len(arr_doubled) - 1)
    print("Sorted array with duplicates is:", sorted_arr_doubled)

if __name__ == "__main__":
    main()
