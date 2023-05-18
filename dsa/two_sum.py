
def twosum(nums, target):
    n = len(nums)
    for i in range(n - 1):
        for j in range(i + 1, n):
            if nums[i] + nums[j] == target:
                return [i, j]
            
nums = [3, 2, 4]
target = 6
print(twosum(nums, target))

# time complexity = O(n^2)
# space complexity = O(1)