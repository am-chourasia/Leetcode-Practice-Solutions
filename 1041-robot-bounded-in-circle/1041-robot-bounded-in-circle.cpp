class Solution {
    enum Direction{
        up, right, down, left
    };
    void changeDirection(Direction& dir, Direction turn){
        if(dir == left)
            dir = turn == left ? down : up;
        else if(dir == right)
            dir = turn == left ? up : down;
        else if(dir == up)
            dir = turn == left ? left : right;
        else 
            dir = turn == left ? right : left;
    }
    void move(Direction& dir, int& x, int& y){
        if(dir == up)
            y++;
        else if(dir == down)
            y--;
        else if(dir == right)
            x++;
        else 
            x--;
    }
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        Direction direction = up;
        for(char instruction: instructions){
            switch(instruction){
                case 'G':
                    move(direction, x, y);
                    break;
                case 'L':
                    changeDirection(direction, left);
                    break;
                case 'R':
                    changeDirection(direction, right);
                    break;
            }
            cout << x << " " << y << "\t" << direction << endl;
        }
        if(x == 0 and y == 0)
            return true;
        // if the resultant vector is not in the north direction,
        // the robot always stays in a loop
        if(direction != up) 
            return true; 
        return false;
    }
};