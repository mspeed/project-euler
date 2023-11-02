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
    array<bool, HIGHEST_TEST_VALUE> Sieve = {false};
    vector<uint64_t> Primes;    
  };

  void static pp(sPrimeInfo const& P) 
  {
    cout << "Sieve: ";
    for(bool b : P.Sieve) cout << b << ", ";
    cout << endl << "Primes: ";
    for(uint64_t p : P.Primes) cout << p << ", ";
    cout << endl;
  }

  [[nodiscard]] static sPrimeInfo& GetNthPrime(int N, sPrimeInfo& P)
  {    
    if(!N){ P.Primes.push_back(1); P.Sieve[0] = true; return P; }

    // Do we really want 10k stack frames? Probably not.
    // Find the Nth prime using the sieve in P.
    P = GetNthPrime(N-1, P);      

    uint64_t PrimeTest = P.Primes[P.Primes.size()-1] + 1;
    while(P.Sieve[PrimeTest])
    {
      PrimeTest++;
      if(PrimeTest >= HIGHEST_TEST_VALUE)
      {
	cout << "Primes exceeded sieve length. " << endl;
	exit(-1);
      }
    }

    // Save this prime.  
    P.Primes.push_back(PrimeTest);
    
    uint64_t ClearIndex = PrimeTest;
    while(ClearIndex < HIGHEST_TEST_VALUE)
    {
      P.Sieve[ClearIndex] = true;
      ClearIndex += PrimeTest;
    }
    
    return P;
  };

};


#define SIEVE_SIZE 150000

int main(int argc, char* argv[])
{
  if(2!=argc){ cout << argv[0] << " <prime index>" << endl; return -1; }    
  int const PrimeIndex = atoi(argv[1]);
  
  cSieve<SIEVE_SIZE>::sPrimeInfo mPI;
  mPI = cSieve<SIEVE_SIZE>::GetNthPrime(PrimeIndex, mPI);

  cout << "Prime " << PrimeIndex << "= " << mPI.Primes[mPI.Primes.size()-1] << endl;

}
