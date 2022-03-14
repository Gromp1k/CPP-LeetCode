#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>    // std::sort
#include <stack> // stack
using std::cout;
using std::string;
using std::vector;
using std::map;;
using std::stack;

//https://leetcode.com/problems/palindrome-number/
template<typename T>
std::string toString(const T& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
bool isPalindrome(int x){
    //sol2
        if (x < 0) return false;
        int rev=0, digit=0, input = x;
        do{
            digit = x % 10;
            x /= 10;
            rev += digit;
            if (x!=0) rev *= 10;
        }
        while(x!=0);
        return input == rev;
}

//https://leetcode.com/problems/roman-to-integer/
int romanToInt(string s){
    int res = 0, sub=0;
    using vals = std::unordered_map<char, int>;
    static vals values{ 
        {'I',1}, 
        {'V',5}, 
        {'X',10}, 
        {'L', 50}, 
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    bool isFirst = true;
    for(int i = s.length()-1; i >= 0 ; --i){
        if(isFirst){
            res += values[s[i]];
            isFirst = false;
        }
        else{
            if(values[s[i]] < values[s[i+1]]) res -= values[s[i]];
            else res += values[s[i]];
        }
        cout << res << '\n';
    }
    return res;
}

//https://leetcode.com/problems/longest-common-prefix/
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==1) return string(strs[0]);
    string prefix = "";
    int min_word_lenght = strs[0].length();
    for(string s: strs) if(s.length() < min_word_lenght) min_word_lenght = s.length();
    string pattern = strs[0];
    //pattern = pattern.substr(0,min_word_lenght);
    for(int j = 0 ; j < min_word_lenght; ++j){
        char c = strs[0][j];
        for(int i = 1 ; i < strs.size(); ++i)
           if(c != strs[i][j]) return prefix;
        prefix+=c;
    }
    return prefix;  
}

//https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
int mostWordsFound(vector<string>& sentences) {
    int cnt = INT_MIN;
    for(auto sent: sentences){
         int words = 1;
         for(int i = 0; i < sent.length(); ++i )
            if (sent[i]==' ')words++;
         cnt = (cnt < words) ? words : cnt;
    }
    return cnt;
}

//https://leetcode.com/problems/a-number-after-a-double-reversal/
void reverse(int &num){
    int tmp = num;
    int n = 0;
    while(tmp!= 0){
        int digit = tmp % 10;
        n = n*10+digit;
        tmp /= 10;
    }
    num = n;
}
bool isSameAfterReversals(int num) {
    int tmp = num;
    reverse(tmp);
    reverse(tmp);
    if(tmp == num) return true;
    return false;
}

//https://leetcode.com/problems/valid-parentheses/
int countValidWords(string sentence) {
    vector<string> tokens;
    string temp = "";      
    for(auto c: sentence)
    {
        if(c==' ')
        {
            if(temp!="")
                tokens.push_back(temp);
            temp = "";
            continue;
        }
        temp += c;
    }
    if(temp!="")
        tokens.push_back(temp);
    
    int count = 0;
    for(auto str: tokens)
    {
        bool stop = true;
        bool hyphen = false;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='0' and str[i]<='9')
            {
                stop = false;
                break;
            }
            if(str[i]<='z' and str[i]>='a')
                continue;
            if(str[i]=='-' and ((i==0 or i==str.length()-1) or hyphen or !(str[i-1]>='a' and str[i-1]<='z') or !(str[i+1]>='a' and str[i+1]<='z')))
            {
                stop = false;
                break;
            }
            if(str[i]=='-')
            {
                hyphen = true;
            }
            if((str[i]=='.' or str[i]=='!' or str[i]==',') and i!=str.length()-1)
            {
                stop = false;
                break;
            }
                
        }
        if(stop)
            count++;
    }
    return count;
}

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
int removeDuplicates(vector<int>& v){
    int ptr = 0, i = 1, n = v.size();
    while(i < n){
        if(v[i] != v[ptr]) v[++ptr] = v[i];
        i++;
    }
    return ptr+1;
}

//https://leetcode.com/problems/valid-parentheses/
bool isValid(string s){
    std::stack<char> t;
        for(auto i:s) 
        {
            if(i == '(' || i =='{' || i == '[') t.push(i);
            else
            {
                if(t.empty() ||
                  (t.top() == '(' && i != ')') ||
                  (t.top() == '{' && i != '}') || 
                  (t.top() == '[' && i != ']')) return false;
                t.pop();
            }
        }
    return t.empty(); // if stack is empty then it is valid, otherwise no
}

//https://leetcode.com/problems/counting-words-with-a-given-prefix/
int prefixCount(vector<string>& words, string pref) {
    int cnt = 0;
    for(string w: words)
        if(w.length()>=pref.length() && (w.substr(0,pref.length()) == pref)) cnt++; 
    return cnt;
}

//https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
int isPrefixOfWord(string sentence, string searchWord) {
        
}