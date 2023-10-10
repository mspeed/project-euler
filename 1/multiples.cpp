// Find the sum of all the multiples of 3 or 5, below 1000.

// Find the number of 3's.
// Find the number of 5's.
// Find the number of multiples of both 3 & 5.

// 3Sum= 3 * (1 + 2 + 3 + ...)
// 5Sum= 5 * (1 + 2 + 3 + ...)
// Overlap sum = 15 * (1 + 2 + 3 + ...)

// Subtract multiples of product of each factor to annul duplicates.

#include<iostream>
using std::cout; using std::endl;

class Multiples
{
  [[nodiscard]] static constexpr int FindCount(int Factor, int UpperLimit)
  {
    return (UpperLimit-1) / Factor;
  }

  [[nodiscard]] static constexpr int FindTriangularNumber(int Rows)
  {
    return (Rows*(Rows+1))>>1;
  }

public:
  [[nodiscard]] static constexpr int FindSumOfMultiples(int Factor, int UpperLimit)
  {
    return Factor * FindTriangularNumber(FindCount(Factor, UpperLimit));
  }  
};


int main()
{
  int const factor1     = 3;
  int const factor2     = 5;
  int const upper_limit = 1000;

  int const SumOfMultiples = Multiples::FindSumOfMultiples(factor1,         upper_limit)
                           + Multiples::FindSumOfMultiples(factor2,         upper_limit)
                           - Multiples::FindSumOfMultiples(factor1*factor2, upper_limit);
      
  cout << "Sum of multiples is: " << SumOfMultiples << endl;

  return 0;
}
