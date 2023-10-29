// Find the largest palindromic number made by the product of two three-digit numbers.

#include<stack>
using std::stack;

#include<string>
using std::string;

#include<iostream>
using std::cout; using std::endl;

#include<utility>
using std::pair;

#include<optional>
using std::optional;

class Pal
{
public:

  [[nodiscard]] static bool IsPalindrome(int val)
  {
    stack<char> vals;
    string const num = std::to_string(val);
    int const N = num.size();

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


  [[nodiscard]] static optional<pair<int, int>> DigitProducts(int DigitCount)
  {
    int const UpperLimit = pow(10,DigitCount)-1;
    int const LowerLimit = pow(10, DigitCount-1);

    for(int i = UpperLimit; i>=LowerLimit; i--)
    {
      for(int j = i; j >= LowerLimit; j--)
      {
	if(IsPalindrome(i*j)) return pair<int, int>{i,j};
      }
    }
    
    return std::nullopt;
  }


};

int main(int argc, char* argv[])
{
  if(2 != argc)
  {
    cout << argv[0] << " <digit count>" << endl;
    return -1;
  }
  int const DigitCount = atoi(argv[1]);
  
  optional<pair<int,int>> rv = Pal::DigitProducts(DigitCount);
  
  if(rv.has_value())
  {    
    cout << rv.value().first << " * " << rv.value().second;
    cout << " = " << (rv.value().first*rv.value().second) << endl;
  }
  else cout << "No palindromes found." << endl;

  return 0;
}
