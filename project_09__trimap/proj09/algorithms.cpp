#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;
#include<iterator>
using std::ostream_iterator; using std::back_inserter;
#include<algorithm>
using std::copy; using std::upper_bound; using std::find;
#include<initializer_list>
using std::initializer_list;

// operator<< for vector as a function. Mostly you've seen
// this already, just a small variation
ostream& operator<<(ostream& out, const vector<long>& v){
  ostringstream oss;
  copy(v.begin(), v.end(), ostream_iterator<long>(oss, ","));
  string s = oss.str();
  out << s.substr(0, s.size()-1);
  return out;
}

// a structure to play with. Later for the harder stuff
struct My_Struct{
  long x = 0;
  long y = 0;
  
  // your basic constructors
  My_Struct() = default;
  My_Struct(long xval, long yval) : x(xval), y(yval) {} ;
};

// lt_struct_2nd_member takes a value we are looking for and a My_Struct
// to compare it with using lessthan. Compares on 2nd element of
// a My_Struct. Returns a bool. Useful for work in the hard stuff
bool lt_struct_2nd_member(const long& val, const My_Struct& ms){
  return val < ms.y;
}

// working with initializer_list. Use it to copy elements
// into another container. Great for ctor's . Kind of like
// a vector but only good for copying (no indexing for example)
// It is templated, must indicate the type.
// #include<initializer_list>
void IL_to_vector(initializer_list<long> il, vector<long>&v ){
  copy(il.begin(), il.end(), back_inserter(v) );
}


int main (){

  /***** basic stuff *****/
  vector<long> v;

  // first arg received as an initializer_list in the function
  // Could use it to fill more complicated stuff (hint, hint).
  IL_to_vector({1,3,5,7,11,13,17,19,29,31}, v);
  cout << to_string(v) << endl;
  
  vector<long>::iterator pos;
  pos = v.begin();
  v.insert(pos,123);
  cout << v << endl;
  v.erase(pos);
  cout << v << endl;
  
  // in a sorted vector, find the one that is greater
  // a binary search
  pos = upper_bound(v.begin(), v.end(), 13);
  cout << *pos << endl; // 17

  // even if the value is not there, return iterator to the greater value
  pos = upper_bound(v.begin(), v.end(), 23);
  cout << *pos << endl; // 29

  // check if it's there, insert if not
  //   *caution*, what are the edge cases not being accounted for here?
  //   what about pos == v.begin() ?? pos == v.end()?? what if not there??
  // insert does so *before* the iterator argument, works well with upper_bound
  if ( *(pos - 1) != 23){   // *pos == 29, *(pos - 1) == 19
    cout << *(pos - 1) << endl;
    v.insert(pos, 23);
    cout << v << endl;
  }

  // linear, not binary, search. Returns .end() if not found.
  pos = find(v.begin(), v.end(), 33);
  if (pos != v.end() )
    cout << *pos << endl;
  else
    cout << "33 not there" << endl;

  
  /***** more compilcated stuff ******/


  // hand sorted on second element of each My_Struct element in vector v_s
  // something to play with
  vector<My_Struct> v_s = { {3,1}, {0,2}, {7,3} };

  // upper_bound requires a lessthan compare operator for each element in the vector.
  // We don't have one for My_Struct elements, so we write a function
  //  lt_struct_2nd_member (it's at the top of this file)
  // Looking for My_Struc with second value (y) of 2, binary search
  vector<My_Struct>::iterator ms_pos;  
  ms_pos = upper_bound(v_s.begin(), v_s.end(), 2, lt_struct_2nd_member);

  cout << "Upper Bound " << endl;
  if (ms_pos != v_s.end() ){
    cout << (*ms_pos).x << ":" << (*ms_pos).y << endl;
    // cout << ms_pos->x << ":" << ms_pos->y << endl;  // shortcut equivalent to above
  }
  else{
    cout << "Not Found" << endl;
  }

  // basic linear find using a loop structure, looking for My_Struct with
  // first value (x) of 3
  My_Struct* ptr = nullptr; // a My_Struct* (pointer)
  for (auto itr=v_s.begin(); itr!=v_s.end(); ++itr){
    if (itr->x == 3){
      ptr = &(*itr);  // itr is an iterator, *itr is a My_Struct, &(*itr) is the address
    }
  }

  cout << "Linear " << endl;
  if (ptr != nullptr)
    cout <<  ptr->x << "::" << ptr->y <<endl;
  else
    cout << "Not found" << endl;
}

/* 
OK, probably a bit beyond us but here is the way to do linear search using an STL
algorithm. find_if takes a function but only one argument. We use a lamba and capture (in
the []) the value we are looking for and search that way. If you find this terrifying,
use the linear search above
*/

My_Struct* use_find_if(vector<My_Struct>& v, long val){
  vector<My_Struct>::iterator pos;
  auto find_pos = find_if(v.begin(), v.end(),
		[&val](My_Struct s){
		  return s.x == val;
		}
		);
  if (find_pos == v.end() )
    return nullptr;
  else
    return &(*find_pos);
}
  
