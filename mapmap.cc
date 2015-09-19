#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string, string> innerMap;
typedef map<int, innerMap> mainMap;

mainMap book;


void print()
{
  map<int, innerMap >::iterator it;
  map<string, string>::iterator inner_it;

  for ( it=book.begin() ; it != book.end(); it++ ) {
    cout << "\n\nNew element\n" << (*it).first << endl;
    for( inner_it=(*it).second.begin(); inner_it != (*it).second.end(); inner_it++)
      cout << (*inner_it).first << " => " << (*inner_it).second << endl;
  }
}

int main (int argc, char *argv[])
{

book.insert (make_pair (13579, innerMap ()));
book[13579].insert (make_pair ("title", "freakonomics"));
book[13579].insert (make_pair ("authors", "Levitt & Dubner"));
book[13579].insert (make_pair ("release date","20-09-2011"));
book[13579].insert (make_pair ("list price", "7 USD"));
book[13579].insert (make_pair ("publisher","William Morrow"));

book.insert (make_pair (1248, innerMap ()));
book[1248].insert (make_pair ("title", "Effective Java"));
book[1248].insert (make_pair ("authors", "Joshua Bloch"));
book[1248].insert (make_pair ("list price", "10 USD"));
book[1248].insert (make_pair ("publisher", "Addison-Wesley"));

print();
}
