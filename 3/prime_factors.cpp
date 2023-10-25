#include<iostream>
using std::endl; using std::cout;
#include<vector>
using std::vector;

#include<algorithm>
using std::reverse;

class Prime
{

public:
  [[nodiscard]] static vector<uint64_t> FindPrimeFactors(uint64_t value)
  {

    return vector<uint64_t>{};
  }
  
  [[nodiscard]] static vector<uint64_t> Sieve(uint64_t value)
  {

    //cout << "Calling sieve for : " << value << endl;
    
    vector<bool> n;
    //for(int i = 0; i <= value; i++) n.push_back(false);
    n.reserve(value+1);
    vector<uint64_t> pv;
    
    for(uint64_t i = 2; i <= value; i++)
    {
      if(n[i]) continue;

      pv.push_back(i);
      uint64_t test = i;
      while(test <= value)
      {
	n[test] = true;
	test += i;
      }	
    }
        
    return pv;
  }

  [[nodiscard]] static uint64_t FindLargestPrimeFactor(uint64_t value)
  {
    vector<uint64_t> primes = Sieve(value >> 1);
    //std::reverse(primes.begin(), primes.end());

    cout << primes.size() << " primes in the sieve." << endl;

    for(int i : primes)
    {
      if(!(value % i)) return i;
    }
            
    return value;
  }
  
};


int main(int argc, char* argv[])
{
  if(2!=argc){ cout << argv[0] << " <testint>" << endl; return 0; }
  //int const testval = atoi(argv[1]);
  uint64_t const testval = 600851475143;

  vector<uint64_t> test = Prime::Sieve(testval);
  /*
  for(int i : test)
  {
    cout << i << ", ";
  }
  cout << endl;*/
  
  cout << "Largest prime factor: " << Prime::FindLargestPrimeFactor(testval) << endl;


}
