/**
 * @param {number[]} target
 * @param {number[]} arr
 * @return {boolean}
 */
var canBeEqual = function(target, arr) {
    target.sort((a, b) => a - b);
    arr.sort((a, b) => a - b);
    const len = target.length;
    for(let i = 0; i < len; i++)
        if(target[i] !== arr[i])
            return false;
    return true;
};