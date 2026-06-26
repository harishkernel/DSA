#include <bits/stdc++.h>
using namespace std;

void dfs(string word, vector<string>& temp, unordered_map<string, int>& mpp, vector<vector<string>>& ans) {
    int step = mpp[word];

    if(step == 0) {
        vector<string> path = temp;
        reverse(path.begin(), path.end());
        ans.push_back(path);
        return;
    }

    for(int i = 0; i < word.length(); i++) {
        char original = word[i];
        for(char c = 'a'; c <= 'z'; c++) {
            word[i] = c;
            if(word != temp.back() && mpp.find(word) != mpp.end() && mpp[word] == step-1) {
                temp.push_back(word);
                dfs(word, temp, mpp, ans);
                temp.pop_back();
            }
        }
        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    /**
     * Approach:
     * do bfs and put all seq words in a data-structure preferrably map with lvls
     * then dfs / backtrack from end --> begin so that invalid sequences arent constructed to avoid TLE's
     */

     // 1
    vector<vector<string>> ans;

    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return ans;

    queue<pair<string, int>> q;
    unordered_map<string, int> mpp;
    mpp[beginWord] = 0;
    unordered_set<string> vis(wordList.begin(), wordList.end());

    q.push({beginWord, 0});

    while(!q.empty()) {
        auto[prevWord, step] = q.front();
        q.pop();
    
        for(int i = 0; i < prevWord.length(); i++) {
            string copy = prevWord;
            for(char c = 'a'; c <= 'z'; c++) {
                // construct a new string and check if not in map and in vis
                copy[i] = c;
                if(copy != prevWord && vis.find(copy) != vis.end() && mpp.find(copy) == mpp.end()) {
                    mpp[copy] = step+1;
                    q.push({copy, step+1});
                    vis.erase(copy);
                }
            }
        }
    }

    // if endWord not in map as bfs wasnt able to reach it
    if(mpp.find(endWord) == mpp.end()) {
        return ans;
    }

    // 2
    vector<string> temp = {endWord};
    dfs(endWord, temp, mpp, ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> ans = findLadders(beginWord, endWord, wordList);

    for(auto& path : ans) {
        for(auto& word : path)
            cout << word << " ";
        cout << '\n';
    }
    return 0;
}