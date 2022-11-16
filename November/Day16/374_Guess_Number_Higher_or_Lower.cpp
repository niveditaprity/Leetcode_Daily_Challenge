/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
     int s = 1, e = n;
        while(s<=e)
        {
            int mid =s+(e-s)/2;
            int p = guess(mid);
            if(p == -1)
            {
                e = mid;
            }
            else if(p==1)
            {
                s=mid+1;
            }
            else if(p==0)
            {
                return mid;
            }
        }
        return 0;
    }
};