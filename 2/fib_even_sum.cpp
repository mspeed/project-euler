// Find the sum of the even terms of the fibonacci sequence, up to a given ceiling.
#include<algorithm>
using std::pair;

#include<iostream>
using std::cout; using std::endl;

using vect = pair<int, int>;
using matrix = pair<vect, vect>;

struct la
{
  [[nodiscard]] static inline vect& Update(vect& v, matrix& m)
  {
    vect tmp;    
    tmp.first  = (m.first.first  * v.first) + (m.second.first  * v.second);
    tmp.second = (m.first.second * v.first) + (m.second.second * v.second);
    v.first = tmp.first;
    v.second = tmp.second;
    return v;
  }

  static void pretty_print(vect& v)
  {
    cout << "[" << v.first  << "]" << endl;
    cout << "[" << v.second << "]" << endl;
  }

  static void pp(vect& v)
  {
    cout << "[" << v.first << ", " << v.second << "]" << endl;
  }
};


int main()
{
  vect state { 0, 1 };
  matrix update { {0, 1} , {1, 1} };

  for(int i = 0; i < 10; i++)
  {
    la::pp(state);  
    state = la::Update(state, update);
  }
}
