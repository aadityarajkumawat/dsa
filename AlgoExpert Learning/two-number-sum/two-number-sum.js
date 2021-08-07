// O(n^2) time | O(1) space
function twoNumberSumV0(array, targetSum) {
    for (let i = 0; i < array.length; i++) {
        let first = array[i];

        for (let j = i + 1; j < array.length; j++) {
            let second = array[j];

            if (first + second === targetSum) {
                return [first, second];
            }
        }
    }

    return [];
}

// O(n) time | O(n) space
function twoNumberSumV1(array, targetSum) {
    let nums = {};
    for (let i = 0; i < array.length; i++) {
        let potentialMatch = targetSum - array[i];

        if (potentialMatch in nums) {
            return [potentialMatch, array[i]];
        } else {
            nums[array[i]] = true;
        }
    }

    return [];
}

// O(nlog(n)) time | O(1) space
function twoNumberSumV2(array, targetSum) {
    array.sort();

    let left = 0;
    let right = array.length - 1;

    while (left < right) {
        if (array[left] + array[right] == targetSum) {
            return [array[left], array[right]];
        } else if (array[left] + array[right] > targetSum) {
            right -= 1;
        } else if (array[left] + array[right] < targetSum) {
            left += 1;
        }
    }

    return [];
}

const array = [3, 1, 9, -1, 2, 7, 4];
const targetSum = 11;

console.log(twoNumberSumV0(array, targetSum));
console.log(twoNumberSumV1(array, targetSum));
console.log(twoNumberSumV2(array, targetSum));
