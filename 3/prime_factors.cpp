#include<iostream>
using std::endl; using std::cout;
#include<vector>
using std::vector;

class Prime
{

public:
  [[nodiscard]] static vector<int> FindPrimeFactors(int value)
  {

    return vector<int>{};
  }  

  [[nodiscard]] static vector<int> Sieve(int value)
  {
    vector<bool> n = {false};
    vector<int> pv;
    
    for(int i = 2; i < value; i++)
    {
      if(n[i]) continue;

      pv.push_back(i);
      int test = i;
      while(test < value)
      {
	n[test] = true;
	test += i;
      }	
    }
        
    return pv;
  }
  
};


int main()
{
  for(int i : Prime::Sieve(100))
  {
    cout << i << ", ";
  }
  cout << endl;


}
