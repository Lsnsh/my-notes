/**
 * 66. 加一
 * // https://leetcode-cn.com/problems/plus-one/submissions/
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
    let carry = 1;
    let length = digits.length;

    for (let i = length - 1; i >= 0; i--) {
        digits[i] += carry;
        carry = Math.floor(digits[i] / 10);
        digits[i] %= 10;
    }

    if (carry === 1) {
        digits.splice(0, 0, carry);
    }

    return digits;
};

console.log('[0] + 1 = ', plusOne([0]));
console.log('[1,2,3] + 1 = ', plusOne([1, 2, 3]));
console.log('[1,2,9] + 1 = ', plusOne([1, 2, 9]));
console.log('[1,9,3] + 1 = ', plusOne([1, 9, 3]));
console.log('[9,9,3] + 1 = ', plusOne([9, 9, 3]));
console.log('[1,9,9] + 1 = ', plusOne([1, 9, 9]));
console.log('[9,9,9] + 1 = ', plusOne([9, 9, 9]));
