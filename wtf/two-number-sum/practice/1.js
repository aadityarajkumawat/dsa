function twoNumberSum(arr, target) {
    let hashMap = {};
    for (let i = 0; i < arr.length; i++) {
        let num = arr[i];
        let otherHalf = target - num;
        if (otherHalf in hashMap) {
            return [hashMap[otherHalf], i];
        }
        hashMap[num] = i;
    }
    return [];
}
