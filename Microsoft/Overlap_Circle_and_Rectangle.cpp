class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        int nx,ny;

        if(xCenter<=x1) nx=x1;
        else if(xCenter>=x2) nx=x2;
        else nx=xCenter;

        if(yCenter<=y1) ny=y1;
        else if(yCenter>=y2) ny=y2;
        else ny=yCenter;

        int d=(nx-xCenter)*(nx-xCenter) + (ny-yCenter)*(ny-yCenter);
        radius=radius*radius;

        if(d>radius) return false;

        return true;
    }
};