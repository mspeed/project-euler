
#include<iostream>
using std::endl; using std::cout;

#include<vector>
using std::vector;

#include<array>
using std::array;


template<int HIGHEST_TEST_VALUE>
class cSieve
{
public:

  struct sPrimeInfo
  {
    sPrimeInfo(){ for(bool b : Sieve){ b = false; } }
    array<bool, HIGHEST_TEST_VALUE> Sieve;
    vector<uint64_t> Primes;
  };

  [[nodiscard]] static sPrimeInfo& GetNthPrime(int N, sPrimeInfo& P)
  {
    if(N >= HIGHEST_TEST_VALUE) return P;
    // N'th prime is not divisible by the N-1 primes that precede it.
    if(!N){ P.Primes.push_back(1); P.Sieve[0] = true; return P; }
    // Do we really want 10k stack frames? Probably not.

    // Find the Nth prime using the sieve in P.
    P = GetNthPrime(N-1, P);      
    
    uint64_t const LastPrime = P.Primes[P.Primes.size()-1];

    cout << "LastPrime: " << LastPrime << endl;
    
    uint64_t PrimeTest = LastPrime + 1;
    while(P.Sieve[PrimeTest])
    {
      cout << "P.Sieve[" << PrimeTest << " = " << P.Sieve[PrimeTest] << endl;
      PrimeTest++;      
    }

    cout << "PrimeTest leads to: " << PrimeTest << endl;

    P.Primes.push_back(PrimeTest);
    P.Sieve[PrimeTest] = true;
    
    uint64_t ClearIndex = PrimeTest;
    
    while(ClearIndex < HIGHEST_TEST_VALUE)
    {
      cout << "Setting sieve[" << ClearIndex << "] to true." << endl;
      P.Sieve[ClearIndex] = true;
      ClearIndex += PrimeTest;
    }
    
    return P;
  };
  
  


};


int main()
{

  
  cSieve<20>::sPrimeInfo mPI;
  

  mPI = cSieve<20>::GetNthPrime(5, mPI);


  for(uint64_t i : mPI.Primes) cout << i << ", " << endl;

  cout << "Found: " << mPI.Primes.size() << " primes." << endl;
  //cout << "Last prime: " << *(mPI.Primes.end()--) << endl;
  


}
