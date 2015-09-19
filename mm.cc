#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<int, string> innerMap;
typedef map<double, innerMap> mainMap;

mainMap m;


void print()
{
  map<double, innerMap >::iterator it;
  map<int, string>::iterator inner_it;

  for ( it=m.begin() ; it != m.end(); it++ ) {
    cout << "\n\nNew element\n" << (*it).first << endl;
    for( inner_it=(*it).second.begin(); inner_it != (*it).second.end(); inner_it++)
      cout << (*inner_it).first << " => " << (*inner_it).second << endl;
  }
}

int main (int argc, char *argv[])
{

  // First insert an element into outermap
  m.insert (make_pair (2.4, innerMap ()));
  // Now insert elements into innermap
  m[2.4].insert (make_pair (3, "two"));
  m[2.4].insert (make_pair (5, "five"));

  // print elements in the mainMap
  print();
    
}

