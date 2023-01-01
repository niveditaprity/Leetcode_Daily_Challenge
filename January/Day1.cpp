class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        stringstream ss(s);
        string word;

        vector<string>words;

        while(ss >> word)
        {
            words.push_back(word);
        }

        if(words.size() != pattern.size()){
            return false;
        }

        unordered_map<char , string>m;
        set<string>used;


        for(int i = 0; i < words.size(); i++)
        {
            if(m.count(pattern[i]))
            {
                if(m[pattern[i]] != words[i])
                {
                    return false;
                }
            }
            else
            {
                if(used.find(words[i]) != used.end())
                {
                    return false;
                }
            }

            m[pattern[i]] = words[i];
            used.insert(words[i]);
        }

        return true;
    }
};