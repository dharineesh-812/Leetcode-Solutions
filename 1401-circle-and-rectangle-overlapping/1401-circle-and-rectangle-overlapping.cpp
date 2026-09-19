class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int cx = max(x1 , min(xCenter , x2)) - xCenter;
        int cy = max(y1 , min(yCenter , y2)) - yCenter;

        return cx * cx + cy * cy <= radius * radius;
    }
};