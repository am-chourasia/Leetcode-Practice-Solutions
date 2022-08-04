class Solution {
    public int mirrorReflection(int p, int q) {
      int direction = 0;
      int point = 0;
      do {
        point = point + q;
        direction = direction ^ 1;
      } while (point % p != 0);
      
      if(direction == 0)
        return 2;
      int boxes = point / p;
      if(boxes % 2 == 0)
        return 0;
      return 1;
    }
}