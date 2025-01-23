# include<bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    unordered_map<string, int> mp;

    WordDictionary() {}

    void addWord(string word) { mp[word]++; }

    bool search(string word) {

        int n = word.size();

        vector<int> v;

        for (int i = 0; i < n; i++) {

            if (word[i] == '.')
                v.push_back(i);
        }

        if (v.size() == 0) {

            if (mp.find(word) != mp.end())
                return true;
            return false;
        } else if (v.size() == 1) {

            int ind = v[0];

            for (int j = 0; j <= 25; j++) {

                char ch = char(j + 'a');
                word[ind] = ch;

                if (mp.find(word) != mp.end())
                    return true;
            }
            return false;
        } else {

            int ind1 = v[0], ind2 = v[1];

            for (int i = 0; i <= 25; i++) {

                for (int j = 0; j <= 25; j++) {

                    char c1 = char(i + 'a'), c2 = char(j + 'a');
                    word[ind1] = c1;
                    word[ind2] = c2;

                    if (mp.find(word) != mp.end())
                        return true;
                }
            }

            return false;
        }
    }
};