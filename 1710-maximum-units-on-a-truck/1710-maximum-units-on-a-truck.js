/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
var maximumUnits = function(boxTypes, truckSize) {
    boxTypes.sort((a, b) => b[1] - a[1]);
    return boxTypes.reduce((acc, box) => {
        if(truckSize >= box[0])
            acc += box[0] * box[1];
        else 
            acc += truckSize * box[1];   
        truckSize = Math.max(0, truckSize - box[0]);
        return acc;
    }, 0);
};