/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    nums.reduce((accumulator, currentValue, index, array) => array[index] += accumulator);
    return nums;
};