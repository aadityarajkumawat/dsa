numbers = [2, 4, 7, -1, 0, 3, 8, 6]


# O(n) time | O(n) space
def two_number_sum(arr, target):
    hash_map = {}
    for i in range(len(arr)):
        num = arr[i]
        other_half = target - num
        if other_half in hash_map:
            return [i, hash_map[other_half]]
        else:
            hash_map[num] = i
    return []


print(two_number_sum(numbers, 5))
