/**
 *
 * @param {number} $data
 * @param {{data: number, left: any, right: any}} $left
 * @param {{data: number, left: any, right: any}} $right
 * @returns
 */
function Node($data = 0, $left = null, $right = null) {
    let data = $data;
    let left = $left;
    let right = $right;

    return { data, left, right };
}

module.exports = { Node };
