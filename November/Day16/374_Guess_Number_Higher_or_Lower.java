/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int start=0;
        int end=n;
        while(start<=end){
            int mid= (end - start)/2+ start;
            if(guess(mid)==0)return mid;
            else if(guess(mid)==-1)end=mid-1;
            else start=mid+1;
        }
        return 0;
        }
}
