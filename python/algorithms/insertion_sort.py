def insertion_sort(arr):
    ''' 
    Sorts an array in ascending order using the insertion sort algorithm.
    Time Complexity: O(n^2)
    Args:
        arr (list): The list of elements to be sorted.
    '''
    for i in range(1, len(arr)):
        curr = arr[i]
        j = i - 1
        while j > -1 and curr < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = curr

    return arr

def main():
    # Example usage
    arr = [12, 11, 13, 5, 6]
    sorted_arr = insertion_sort(arr)
    print("Sorted array is:", sorted_arr)
    arr_doubled = [12, 11, 13, 5, 6, 12, 11, 13, 5, 6]
    sorted_arr_doubled = insertion_sort(arr_doubled)
    print("Sorted array with duplicates is:", sorted_arr_doubled)

if __name__ == "__main__":
    main()
