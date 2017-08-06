#include "MainForm.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <Windows.h>
#include "Markup.h"
#include <map>
#include <string>  
#include <fstream>

using namespace System::Windows::Forms;
using namespace std;
using namespace System; 

map<string, string> m;
string filepath;
class XML{
	public:
		void setTarget(char[]);
		XML(string file);
		void Process(void);
		map<string, string> returnMap(void);
};
XML::XML(string file){
	filepath = file;
}
map<string, string> XML::returnMap(void){
	return m;
}
void XML::Process(void){
	try{
		CMarkup xml;
		bool bSuccess = xml.Load(MCD_T(filepath));
		if (bSuccess){
			m.clear();
			xml.FindElem(); //entries
			xml.IntoElem();
			while(xml.FindElem(MCD_T("entry"))){
				xml.IntoElem();

				xml.FindElem(MCD_T("name"));
				std::string strTitle = xml.GetData();				
				xml.FindElem(MCD_T("hash"));
				std::string strTitle2 = xml.GetData();

				m.insert(pair<string, string>(strTitle, strTitle2));
			
				xml.OutOfElem();
			}
		}else{
			MessageBox::Show(gcnew String("Failure to load XML document"));
		}
	}catch(std::exception e){
		MessageBox::Show(gcnew String("Failure to load XML document"));
	}
}