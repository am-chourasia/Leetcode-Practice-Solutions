/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    const len = cost.length;
    let dp0 = cost[0];
    let dp1 = cost[1];
    let temp;

    for(let i = 2; i < len; i++){
        temp = cost[i] + Math.min(dp0, dp1);
        dp0 = dp1;
        dp1 = temp;
    }

    return Math.min(dp0, dp1);
};