#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define MASTERFILE "file1.csv"
#define CANDIDATESFILE "candidates.file"
typedef map<string, string> innerMap;
typedef map<int, innerMap> outerMap;
outerMap book;

class bookStore {

private:

public:

	bookStore()  { }
	void outerInsert(int id); 
	void innerInsert(int id, string attr, string value); 
	void innerModify(int id, string attr, string value); 
	void PrintBookList();
	void initializer();
	void Listener();
	void ReadWaitingFiles();
	void UpdateAndNotify(string s);
};
