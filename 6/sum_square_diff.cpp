#include<iostream>
using std::cout; using std::endl;

// Find the difference between the sum of squares and square of sums.

class Prods
{
public:
  [[nodiscard]] static constexpr uint64_t SumOfSquares(int UpperLimit)
  {
    uint64_t Sum = 0;
    for(uint64_t i = 1; i <= UpperLimit; i++)
    {
      Sum += (i*i);
    }
    return Sum;
  };

  [[nodiscard]] static inline constexpr uint64_t SquareOfSum(int UpperLimit)
  {
    uint64_t const Sum = (UpperLimit *(UpperLimit+1))>>1;
    return Sum*Sum;
  };


  [[nodiscard]] static inline constexpr uint64_t Diff(int UpperLimit)
  {
    return SquareOfSum(UpperLimit) - SumOfSquares(UpperLimit);
  }

};



int main(int argc, char* argv[])
{
  if(2 != argc){ cout << argv[0] << " <UpperLimit>" << endl; return -1; }

  int const UpperLimit = atoi(argv[1]);

  cout << "SumOFSquares: " << Prods::SumOfSquares(UpperLimit) << endl;
  cout << "SquareOfSum: " << Prods::SquareOfSum(UpperLimit) << endl;

  cout << "Difference: " << Prods::Diff(UpperLimit) << endl;



}


