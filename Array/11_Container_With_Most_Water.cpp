class Solution {
public:
    int maxArea(vector<int>& height) {
        int mostWater = 0, lp = 0, rp = height.size() - 1;

        while (lp < rp) {
            int width = rp - lp;
            int minHeight = min (height[lp], height[rp]);
            int currWater = width * minHeight;

            mostWater = max (currWater, mostWater);

            (height[lp] < height[rp]) ? lp++ : rp--;
        }
        return mostWater;
    }
};