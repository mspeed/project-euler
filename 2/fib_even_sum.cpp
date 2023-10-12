// Find the sum of the even terms of the fibonacci sequence, up to a given ceiling.

// Even entries follow two odd entries and hence occur every 3 entries. 

#include<algorithm>
using std::pair;

#include<iostream>
using std::cout; using std::endl;

using vect = pair<int, int>;
using matrix = pair<vect, vect>;

struct la
{
  [[nodiscard]] constexpr static inline vect& Update(vect& v, const matrix& m)
  {
    vect tmp;    
    tmp.first  = (m.first.first  * v.first) + (m.second.first  * v.second);
    tmp.second = (m.first.second * v.first) + (m.second.second * v.second);
    v.first = tmp.first;
    v.second = tmp.second;
    return v;
  }

  static void pretty_print(const vect& v)
  {
    cout << "[" << v.first  << "]" << "\r\n";
    cout << "[" << v.second << "]" << endl;
  }

  static void pp(const vect& v)
  {
    cout << "[" << v.first << ", " << v.second << "]" << endl;
  }
};


int main()
{
  vect state { 0, 1 };
  matrix const update { {0, 1} , {1, 1} };

  uint64_t even_sum = 0;

  state = la::Update(state, update);
  state = la::Update(state, update);
  state = la::Update(state, update);
  
  // Brute force it.
  while(state.first <= 4000000)
  {
    //cout << state.first << endl;
    even_sum += state.first;
    state = la::Update(state, update); // ->odd
    state = la::Update(state, update); // ->odd
    state = la::Update(state, update); // ->even
  }

  cout << "Sum of even terms: " << even_sum << endl;
  
}
