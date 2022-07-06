/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if(n == 0 || n == 1)
        return n;
    let prev = 1;
    let secondPrev = 0;
    let current = 0;
    
    for(let term = 2; term <= n; term++){
        current = prev + secondPrev;
        secondPrev = prev;
        prev = current;
    }
    
    return current;
};