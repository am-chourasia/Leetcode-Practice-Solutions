/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function(people) {
    const queue = [];
    people.sort((a, b) => a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
    people.forEach(person => {
        queue.splice(person[1], 0, person);
    })
    return queue;
};