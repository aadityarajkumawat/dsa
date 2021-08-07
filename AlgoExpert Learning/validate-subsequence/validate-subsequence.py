# O(n) time | O(1) space
def validateSubsequenceV0(array, sequence):
    arrIdx = 0
    seqIdx = 0

    while arrIdx < len(array) and seqIdx < len(sequence):
        if array[arrIdx] == sequence[seqIdx]:
            seqIdx += 1

        arrIdx += 1

    return seqIdx == len(sequence)


# O(n) time | O(1) space
def validateSubsequenceV1(array, sequence):
    seqIdx = 0

    for value in array:
        if seqIdx == len(sequence):
            break
        if sequence[seqIdx] == value:
            seqIdx += 1

    return seqIdx == len(sequence)


array = [4, 2, -1, 8, 0, 5, 9, 7]
sequence = [2, -1, 0, 9]

print(validateSubsequenceV0(array, sequence))
print(validateSubsequenceV1(array, sequence))
