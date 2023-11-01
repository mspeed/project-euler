
#include<iostream>
using std::endl; using std::cout;

#include<vector>
using std::vector;


class cSieve
{
public:

  struct sPrimeInfo
  {
    //vector<bitset<64>}}
    vector<bool> Sieve;
    vector<uint64_t> Primes;
  };

  [[nodiscard]] static sPrimeInfo& GetNthPrime(int N, sPrimeInfo& P)
  {
    // N'th prime is not divisible by the N-1 primes that precede it.
    
    // Do we really want 10k stack frames? Probably not.

    if(N) P = GetNthPrime(N-1, P);      

    // Find the Nth prime using the sieve in P.
    P.Primes.push_back(N);
    
    return P;
  };
  
  


};


int main()
{

  cSieve::sPrimeInfo mPI;

  mPI = cSieve::GetNthPrime(5, mPI);


  for(uint64_t i : mPI.Primes) cout << i << ", " << endl; 
  


}
