# O(n^2) time | O(1) space
def twoNumberSumV0(array, targetSum):
    for i in range(len(array) - 1):
        firstNum = array[i]

        for j in range(i + 1, len(array)):
            secondNum = array[j]

            if firstNum + secondNum == targetSum:
                return [firstNum, secondNum]

    return []


# O(n) time | O(n) space
def twoNumberSumV1(array, targetSum):
    nums = {}

    for num in array:
        potentialMatch = targetSum - num

        if potentialMatch in nums:
            return [potentialMatch, num]
        else:
            nums[num] = True

    return []


# O(nlog(n)) time | O(1) space
def twoNumberSumV2(array, targetSum):
    array.sort()
    left = 0
    right = len(array) - 1

    while left < right:
        currentSum = array[left] + array[right]

        if currentSum == targetSum:
            return [array[left], array[right]]
        elif currentSum < targetSum:
            left += 1
        elif currentSum > targetSum:
            right -= 1

    return []


array = [3, 1, 9, -1, 2, 7, 4]
targetSum = 11

print(twoNumberSumV0(array, targetSum))
print(twoNumberSumV1(array, targetSum))
print(twoNumberSumV2(array, targetSum))
