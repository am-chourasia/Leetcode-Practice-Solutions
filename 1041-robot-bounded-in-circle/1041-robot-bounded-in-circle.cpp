class Solution {
    struct Point{
        int x, y;
    };
    enum Direction{
        up, right, down, left
    };
    void move(Direction& direction, Point& p){
        int& x = p.x;
        int& y = p.y;
        if(direction == up)
            y++;
        else if(direction == right)
            x++;
        else if(direction == down)
            y--;
        else
            x--;
    }
    void changeDirection(Direction& direction, Direction turn){
        if(direction == up)
            direction = turn == left ? left : right;
        else if(direction == right)
            direction = turn == left ? up : down;
        else if(direction == down)
            direction = turn == left ? right : left; 
        else
            direction = turn == left ? down : up;
    }
public:
    bool isRobotBounded(string instructions) {
        Direction direction = up;
        Point position;
        position.x = position.y = 0;
        // traversing 4 times:
        
        for(int traversal = 1; traversal <= 4; traversal++){
            for(char instruction: instructions){
                switch(instruction){
                    case 'G':
                        move(direction, position);
                        break;
                    case 'L':
                        changeDirection(direction, left);
                        break;
                    case 'R':
                        changeDirection(direction, right);
                        break;
                }
            }
        }
        if(position.x == 0 && position.y == 0)
            return true;
        return false;
    }
};