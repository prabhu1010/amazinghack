#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//WE ARE NOT USING THIS
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
	cout <<mseconds<<endl;
    while (goal > clock());
}



int main() {
system("sleep 3");
cout<<"hi"<<endl;
return 1;
}
