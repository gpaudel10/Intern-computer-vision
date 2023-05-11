def anagram(s, t):
    if len(s) != len(t):
        return False
    
    for char in t:
        if char in s:
            s = s.replace(char, '', 1)
        else:
            return False
    
    return len(s) == 0

s = "rat"
t = "car"

result = anagram(s, t)
print(result)

# time complexity = O(n^2)
# space complexity  = O(1)