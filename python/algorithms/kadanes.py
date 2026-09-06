def kadanes(nums: list[int]) -> int:
    '''
    Kadanes algorithm: regular implemntation 
    Time complexity: O(n^2)
    '''
    maxSum = nums[0] 
    currSum = 0

    for n in nums:
        if currSum < 0:
            currSum = 0
        currSum += n
        maxSum = max(maxSum, currSum)

    return maxSum

def slidingWindow(nums: list[int]) -> list[int]:
    '''
    Kadanes algorithm: sliding window implementation
    Time complexity: O(n) 
    '''
    if not nums:
        return []

    max_sum = nums[0] 
    curr_sum = 0
    maxL, maxR = 0, 0
    l = 0

    for r in range(len(nums)):
        if curr_sum < 0:
            curr_sum = 0
            l = r

        curr_sum += nums[r]
        if curr_sum > max_sum:
            max_sum = curr_sum
            maxL, maxR = l, r 
    return [maxL, maxR]