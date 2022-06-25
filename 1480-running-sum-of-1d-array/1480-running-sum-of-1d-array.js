/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let ret = []
    nums.reduce((accumulator, currentValue, index, arr) => ret[index] = arr[index] + accumulator, 0);
    return ret;
};