/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        while (left < right) {  // At least two elem in array
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {  // Top at (mid, right]
                left = mid + 1;  // will not overflow
            } else {  // Top at [left, mid]
                right = mid;
            }
        }
        int peak = left;
        if (mountainArr.get(peak) == target) {
            return peak;
        }
        int idx1 = search(target, mountainArr, 0, peak - 1, true);
        int idx2 = search(target, mountainArr, peak + 1, mountainArr.length() - 1, false);
        return idx1 == -1 ? idx2 : idx1;
    }

private:
    int search(int target, MountainArray &mountainArr, int left, int right, bool isAsc) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cur = mountainArr.get(mid);
            if (cur == target) { 
                return mid;
            } else if (cur < target) {
                if (isAsc) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                if (isAsc) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return mountainArr.get(left) == target ? left : -1;
    }
};