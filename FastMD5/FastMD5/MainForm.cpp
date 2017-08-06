#include "MainForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace System::Runtime::InteropServices;

[STAThread]
void main(array<String^>^ args) {
	int length = args->Length;
	char** argv = new char*[length];
	if(length>0){
		try{
			ofstream myfile;
			for(int i = 0; i < length; i++)
			{
				argv[i] = (char*)Marshal::StringToHGlobalAnsi(args[i]).ToPointer();
				if(strlen(argv[0])!=0){
					myfile.open ("FastMD5Temp.txt");
					myfile << argv[0];
				}			
			 }
			myfile.close();
		}catch(Exception^ e){}
	}

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FastMD5::MainForm form;
	Application::Run(%form);
}