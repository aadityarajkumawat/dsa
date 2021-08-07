// O(n) time | O(d) space
function productSum(array, multiplier = 1) {
    let sum = 0;
    for (let element of array) {
        if (typeof element === "object") {
            sum += productSum(element, multiplier + 1);
        } else {
            sum += element;
        }
    }
    return sum * multiplier;
}
