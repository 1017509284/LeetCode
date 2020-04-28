
#include <iostream>
#include <vector>
#include <string>
using namespace  std;
class Solution {
private:
    vector<string> res;
public:
    const string letterMap[10]={" ",
                         "",
                         "abc",
                         "def",
                         "ghi",
                         "jkl",
                         "mno",
                         "pqrs",
                         "tuv",
                         "wxyz"};
    void letterCombinations(const string &digits,int index,const string &s)
    {
        if(index == digits.size())
        {
            res.push_back(s);
            return;
        }
        char c=digits[index];
        string letters=letterMap[c-'0'];

        for(int i=0;i<letters.size();i++)
            letterCombinations(digits,index+1,s+letters[i]);

        return;
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        letterCombinations(digits,0,"");
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> str;
    str=s.letterCombinations("23");
    for(string q:str)
        cout<<q<<" ";
    cout<<endl;
}
