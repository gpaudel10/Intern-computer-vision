
def duplicate(nums):
        n = len(nums)
        for i in range (n):
            for j in range(i+1,n):
                if nums[i] == nums[j]:
                    return True
        return False



nums =  [1,1,1,3,3,4,3,2,4,2]
print(duplicate(nums)) 

# time complexity = O(n^2)
# space complexity = O(1)

def duplicate(nums):
    numset = set()
    for num in nums:
        if num in numset:
            return True
        numset.add(num)
    return False

# time complexity = O(n)
# space complexity = O(n)