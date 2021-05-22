// O(n) time | O(1) space
function validateSubsequenceV0(array, sequence) {
    let arrIdx = 0;
    let seqIdx = 0;

    while (arrIdx < array.length && seqIdx < sequence.length) {
        if (array[arrIdx] === sequence[seqIdx]) {
            seqIdx += 1;
        }

        arrIdx += 1;
    }

    return seqIdx === sequence.length;
}

// O(n) time | O(1) space
function validateSubsequenceV1(array, sequence) {
    let seqIdx = 0;

    for (let i = 0; i < array.length; i++) {
        if (seqIdx === sequence.length) {
            break;
        }

        if (array[i] === sequence[seqIdx]) {
            seqIdx += 1;
        }
    }

    return seqIdx === sequence.length;
}

const array = [4, 2, -1, 8, 0, 5, 9, 7];
const sequence = [2, -1, 0, 9];

console.log(validateSubsequenceV0(array, sequence));
console.log(validateSubsequenceV1(array, sequence));
