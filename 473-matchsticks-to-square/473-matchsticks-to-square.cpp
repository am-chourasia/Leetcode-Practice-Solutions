class Solution {
    int side;
    array<int, 4> sideLength;
    bool isPossible(int index, vector<int>& matchsticks){
        int len = matchsticks.size();
        if(index == len)
            return sideLength[0] == sideLength[1] && sideLength[1] == sideLength[2];
        int stick = matchsticks[index];
        for(int i = 0; i < 4; i++){
            if(sideLength[i] + stick <= side){
                sideLength[i] += stick;
                if(isPossible(index + 1, matchsticks))
                    return true;
                sideLength[i] -= stick;
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        side = perimeter / 4;
        if(perimeter != side * 4)
            return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return isPossible(0, matchsticks);
    }
};