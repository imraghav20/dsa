#include <bits/stdc++.h>
using namespace std;

map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
vector<string> result;
void helper(string str, int i, string current){
    if(i==str.size()){
        result.push_back(current);
        return;
    }
    string letters = m[str[i]];
    for(int j=0; j<letters.size(); j++){
        helper(str, i+1, current+letters[i]);
    }
}
vector<string> letterCombinations(string digits) {
        if(digits.size() != 0){
            
        }
    }

int* getCharCountArray(char* str)
{
    int* count = (int*)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for (i = 0; *(str + i); i++)
        count[*(str + i)]++;
    return count;
}
