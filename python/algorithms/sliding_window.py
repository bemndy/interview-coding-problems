'''
Sliding window algorithm on close 
duplicate problem. Find K window where 
two elements in window are the same.
Time complexity: O(n)
Space complexity: O(1)
'''

def close_duplicate(arr, k):
    window = set()
    L = 0

    for R in range(len(arr)):
        if R - L + 1 > k:
            window.remove(arr[L])
            L += 1
        if arr[R] in window:
            return True
        window.add(arr[R])

    return False