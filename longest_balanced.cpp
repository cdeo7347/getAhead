#include <string>
using namespace std;

size_t longest_balanced(std::string str) {
  if (str.length() <= 1) return 0;
  
  int curMax;
  vector<int> longest(str.size(), 0);
  
  for (int i = 1; i < str.length(); i++)
  {
    if (str[i] == ')' && i - longest[i - 1] - 1 >= 0 &&
    str[i - longest[i - 1] - 1] == '(')
    {
       longest[i] = longest[i - 1] + 2 +  
                ((i - longest[i - 1] - 2 >= 0)  
                ? longest[i - longest[i - 1] - 2] : 0); 
                    curMax = max(longest[i], curMax);
    }
  }
  return curMax;
}
int main() 
{ 
    string s = "((()()"; 
    cout << longest_balanced(s) << endl; 
  
    s = "()(()))))"; 
    cout << longest_balanced(s) << endl ; 
  
    return 0; 
} 
