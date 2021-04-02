/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x<10)return true;
        long long cnt=0,y=x;

        while(x){
            cnt = cnt*10+x%10;
            x/=10;
        }
        return cnt==y;
    }
};
// @lc code=end

