
// 2520 is evenly divisible by all of [1:10]
// Find the smallest positive number evenly divisible by all of [1:20]

#include<iostream>
using std::cout; using std::endl;

#include<utility>
using std::pair;

class Mult
{
public:

  [[nodiscard]] static constexpr pair<int, int> divmod(int num, int den)
  {
    int const quotient = num / den;
    int const remainder = num - (quotient * den);
    return pair<int,int>{quotient, remainder};
  };

  [[nodiscard]] static inline constexpr bool EvenlyDivisible(pair<int, int> const divmod)
  {
    return (0 == divmod.second);
  };
  
};


int main()
{

  int i = 2520; 
  while(1)
  {
    bool Divisible = true;
    for(int j = 2; j <= 20; j++)
    {
      if(!Mult::EvenlyDivisible(Mult::divmod(i,j))){ Divisible = false;  break; }
    }
    if(Divisible){ cout << "i: " << i << endl; return 0; }
    i += 20; 
  }
  
}
