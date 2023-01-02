
// ----------------------------------- brute force approach -------------------------------------
// Time complexity -: O(n)
// Space complexity -: O(n)

class Solution {
public:
    bool detectCapitalUse(string word) {

        vector<char>ans;      // O(n) use the exstra space

        for(int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            ans.push_back(ch);
        }

        if(ans.size() == 1 || ans.size() == 0)
        {
            return true;
        }

        bool upper = false;
        bool lower = false;

        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] >= 'A' && ans[i] <= 'Z')
            {
                upper = true;
            }
            else
            {
                upper = false;
                break;
            }
        }

        if(upper || lower)
        {
            return true;
        }

        bool upperAll = false;
        bool lowerAll = false;

        for(int i = 1; i < ans.size(); i++)
        {
            if(ans[i] >= 'a' && ans[i] <= 'z')
            {
                upperAll = true;
            }
            else
            {
                upperAll = false;
                break;
            }
        }

        if(upperAll || lowerAll)
        {
            return true;
        }

        return false;

    }
};




// ----------------------------------- optimize approach -------------------------------------
// Time complexity -: O(n)
// Space complexity -: O(1)


class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool upperWord = true , lowerWord = true;

        if(word.size() == 0 || word.size() == 1)
        {
            return true;
        }

        for(int i = 1; i < word.size(); i++)
        {
            if(isupper(word[i]))
            {
                lowerWord = false;
            }

            if(islower(word[i]))
            {
                upperWord = false;
            }
        }

        return lowerWord || (upperWord && isupper(word[0]));
    }
};


