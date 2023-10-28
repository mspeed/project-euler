// Find the largest palindromic number made by the product of two three-digit numbers.

#include<stack>
using std::stack;

#include<string>
using std::string;

#include<iostream>
using std::cout; using std::endl;

class Pal
{
public:

  template<int N>
  [[nodiscard]] static bool IsPalindrome(int val)
  {
    stack<char> vals;
    string const num = std::to_string(val);

    int i;
    for(i = 0; i < (N>>1); i++)
    {
      vals.push(num[i]);
    }
    if(N&1) i++;
    for(    ; i < N; i++)
    {
      if(vals.top() != num[i]) return false;
      vals.pop();
    }

    return true;
    
  };


};

int main()
{
  int const test = 1234325;
  cout << "test: " << test << " is ";
  if(!Pal::IsPalindrome<7>(test)) cout << "not ";
  cout << "palindromic." << endl;

}
