#include <iostream>
#include <Windows.h>
#include <map>
#include <string>  

using namespace System::Windows::Forms;
using namespace std;
using namespace System;

string filename, hashOfFile;


class Entry{
	public:
		Entry(string file, string hash);
};
Entry::Entry(string file, string hash){
	filepath = file;
	hashOfFile = hash;
}