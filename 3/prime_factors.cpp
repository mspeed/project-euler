#include<iostream>
using std::endl; using std::cout;
#include<vector>
using std::vector;

#include<algorithm>
using std::reverse;

#include<cmath>
using std::sqrt;

class Prime
{

public:
  
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


  [[nodiscard]] static vector<uint64_t> FindPrimeFactors(uint64_t value)
  {
    uint64_t const approx_sqrt = static_cast<uint64_t>(sqrt(value));
    vector<bool> n;
    n.reserve(approx_sqrt);
    vector<uint64_t> p;

    for(uint64_t i = 2; i <= value; i++)
    {
      if(n[i]) continue;
      if(i > (value>>1)) i = value;

      // Divide by the prime.
      uint64_t quotient = value/i;
      uint64_t remainder = value - (quotient*i);

      // If we're divisible by this prime, stash the prime and reduce the value
      while(!remainder) 
      {
	value = quotient;
	p.push_back(i);
	
	quotient = value/i;
	remainder = value - (quotient*i);
      }

      if(1 == value) return p;
      
      uint64_t sieve_mul = i;
      while(sieve_mul <= approx_sqrt)
      {
	n[sieve_mul] = true;
	sieve_mul += i;
      }	
    }
    
    return vector<uint64_t>{value};
  }

  [[nodiscard]] static uint64_t FindLargestPrimeFactor(uint64_t value)
  {
    return *(FindPrimeFactors(value).end()-1);
  }
  
};


int main(int argc, char* argv[])
{
  //if(2!=argc){ cout << argv[0] << " <testint>" << endl; return 0; }
  //int const testval = atoi(argv[1]);
  uint64_t const testval = 600851475143;

  //for(int i : Prime::FindPrimeFactors(testval)) cout << i << ", ";
  //cout << endl;
  
  cout << "Largest prime factor: " << Prime::FindLargestPrimeFactor(testval) << endl;
  

}
