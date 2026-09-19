class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        
        int x = max(x1, min(xCenter, x2));
        int y = max(y1, min(yCenter, y2));
        int a = x - xCenter;
        int b = y - yCenter;
        return a * a + b * b <= radius * radius;
    }
};
