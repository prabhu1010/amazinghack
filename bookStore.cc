#include "bookStore.h"

extern outerMap book;
	map<int, innerMap >::iterator it;
	map<string, string>::iterator inner_it;

/*************************************************************************/
void bookStore::PrintBookList()
{

	map<int, innerMap >::iterator it;
	map<string, string>::iterator inner_it;
  for ( it=book.begin() ; it != book.end(); it++ ) {
  	cout << "\nelement " << (*it).first << endl;
    for( inner_it=(*it).second.begin(); inner_it != (*it).second.end(); inner_it++)
    	cout << (*inner_it).first << " => " << (*inner_it).second << endl;
  }
}

/*************************************************************************/
void bookStore::outerInsert(int id) {
book.insert(make_pair (id, innerMap()));
//book[id] = innerMap;
}

/*************************************************************************/
void bookStore::innerInsert(int id, string attr, string value) {
book[id].insert (make_pair (attr, value));
}

/*************************************************************************/
void bookStore::innerModify(int id, string attr, string value) {
  for ( it=book.begin() ; it != book.end(); it++ ) {
	if ((*it).first == id) {
		map<string, string>::iterator mod_it = (*it).second.find(attr); 
		mod_it->second = value;
		break;
	}
  }
}

/*************************************************************************/
void bookStore::initializer() {

  string line;
  ifstream myfile(MASTERFILE);
  string lastID = "";
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
		//cout << "Currline: "<<line << endl;

		stringstream ss(line);
		char delimiter = ',';
		string token;
		int nToken=0;
			int intToken;
			string attrToken, valToken;
		while(getline(ss, token, delimiter)) {
			if (nToken == 0) {
				intToken = atoi(token.c_str());
				//cout<<nToken<<" "<<intToken<<endl;
				nToken++;
				continue;
			}
			if (nToken == 1) {
				attrToken = token; 
				cout<<nToken<<" "<<attrToken<<endl;
				nToken++;
				continue;
			}
			if (nToken == 2) {
				valToken = token; 
				cout<<nToken<<" "<<valToken<<endl;
				nToken = 0;
				innerInsert(intToken, attrToken, valToken);
				stringstream stoken; 
				stoken << intToken;
				lastID = stoken.str();
			}
		}
    }
	//COMMENTED FOR TESTING...NEEDS TO BE UNCOMMENTED
	//system("date +%s >b lastchecked.file"); //STORE LAST DATA UPDATION TIME
    myfile.close();
  }
  else cout << "Unable to open file"; 
}	

void bookStore::Listener() {
	string inputFile = "candidates.file";
//	while (1) {
//		system("sleep 30");	
		//system("filepicker.sh");
        ReadWaitingFiles();
//	}//end of loop
}

void bookStore::ReadWaitingFiles() {

  string line;
  ifstream myfile(CANDIDATESFILE);
  if (myfile.is_open()) {
    while (getline (myfile,line) ) {
		cout<<"Waiting file is "<<line<<endl;
		UpdateAndNotify(line);
  	}
  }
  myfile.close();

}

void bookStore::UpdateAndNotify(string file) {
  cout<<"Dealing with updates for file "<<file<<endl;
  string line;
  ifstream myfile(file.c_str());
  string lastID = "";

  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
		cout << "Curr record: "<<line << endl;
		stringstream ss(line);
		char delimiter = ',';
		string token;
		int nToken = 0;
		int intToken;
		string attrToken, valToken;
		while(getline(ss, token, delimiter)) {
			if (nToken == 0) {
				intToken = atoi(token.c_str());
			    nToken++;
			    continue;
			}		
			if (nToken == 1) {
				attrToken = token;
			    nToken++;
			    continue;
			}		
			if (nToken == 2) {
				valToken = token; 
				nToken = 0;
				cout<<intToken<<attrToken<<valToken<<endl;
				innerModify(intToken, attrToken, valToken);
			}		
  		}
  }
  myfile.close();
  }
}

int main() {
/*
	bookStore *MybookStore;
	MybookStore->initializer();
	MybookStore->PrintBookList();
	MybookStore->innerModify(9999,"title","Andre");
	MybookStore->PrintBookList();
*/

	bookStore MybookStore;
	MybookStore.initializer();
	MybookStore.PrintBookList();
//	MybookStore.innerModify(1000,"authors","Kambli");
//	MybookStore.PrintBookList();
	MybookStore.Listener();
	MybookStore.PrintBookList();

	return 1;
}
