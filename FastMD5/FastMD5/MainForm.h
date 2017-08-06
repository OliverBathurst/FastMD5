#pragma once
#include "XML.h"
#include "MD5.h"
#include <vector>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

map<string,string> toFill;
boolean running = false;

int missingCount = 0, badCount = 0, goodCount = 0;
namespace FastMD5 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}
	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;

	private: System::Windows::Forms::Button^  openXML;

	private: System::Windows::Forms::Button^  run;
	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::ProgressBar^  progressBar1;


	private: System::Windows::Forms::Label^  filenamelabel;
	private: System::Windows::Forms::LinkLabel^  Web;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::Label^  good;
	private: System::Windows::Forms::Label^  bad;
	private: System::Windows::Forms::Label^  missing;
	private: System::Windows::Forms::Button^  Clear;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FileName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Hash;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ActualHash;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  status;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  other;

	private: System::ComponentModel::IContainer^  components;

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openXML = (gcnew System::Windows::Forms::Button());
			this->run = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FileName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hash = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ActualHash = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->other = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->filenamelabel = (gcnew System::Windows::Forms::Label());
			this->Web = (gcnew System::Windows::Forms::LinkLabel());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->good = (gcnew System::Windows::Forms::Label());
			this->bad = (gcnew System::Windows::Forms::Label());
			this->missing = (gcnew System::Windows::Forms::Label());
			this->Clear = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(32, 19);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(32, 19);
			// 
			// openXML
			// 
			this->openXML->Location = System::Drawing::Point(12, 12);
			this->openXML->Name = L"openXML";
			this->openXML->Size = System::Drawing::Size(126, 41);
			this->openXML->TabIndex = 2;
			this->openXML->Text = L"Open";
			this->openXML->UseVisualStyleBackColor = true;
			this->openXML->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// run
			// 
			this->run->Location = System::Drawing::Point(163, 12);
			this->run->Name = L"run";
			this->run->Size = System::Drawing::Size(126, 41);
			this->run->TabIndex = 3;
			this->run->Text = L"Run";
			this->run->UseVisualStyleBackColor = true;
			this->run->Click += gcnew System::EventHandler(this, &MainForm::run_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->ID, this->FileName, 
				this->Hash, this->ActualHash, this->status, this->other});
			this->dataGridView1->Location = System::Drawing::Point(12, 90);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 31;
			this->dataGridView1->Size = System::Drawing::Size(1440, 507);
			this->dataGridView1->TabIndex = 4;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// FileName
			// 
			this->FileName->HeaderText = L"File Name";
			this->FileName->MinimumWidth = 100;
			this->FileName->Name = L"FileName";
			this->FileName->ReadOnly = true;
			// 
			// Hash
			// 
			this->Hash->HeaderText = L"Correct Hash";
			this->Hash->Name = L"Hash";
			this->Hash->ReadOnly = true;
			// 
			// ActualHash
			// 
			this->ActualHash->HeaderText = L"Actual Hash";
			this->ActualHash->Name = L"ActualHash";
			this->ActualHash->ReadOnly = true;
			// 
			// status
			// 
			this->status->HeaderText = L"Time Completed(s)";
			this->status->Name = L"status";
			this->status->ReadOnly = true;
			this->status->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// other
			// 
			this->other->HeaderText = L"Comments";
			this->other->Name = L"other";
			this->other->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 975);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 25);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Good:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(312, 975);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Bad:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(551, 975);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Missing:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(6, 28);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(1440, 250);
			this->richTextBox1->TabIndex = 10;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::richTextBox1_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->richTextBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 603);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1440, 284);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Log";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 940);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1440, 23);
			this->progressBar1->TabIndex = 12;
			// 
			// filenamelabel
			// 
			this->filenamelabel->AutoSize = true;
			this->filenamelabel->Location = System::Drawing::Point(13, 901);
			this->filenamelabel->Name = L"filenamelabel";
			this->filenamelabel->Size = System::Drawing::Size(0, 25);
			this->filenamelabel->TabIndex = 15;
			// 
			// Web
			// 
			this->Web->AutoSize = true;
			this->Web->Location = System::Drawing::Point(1368, 975);
			this->Web->Name = L"Web";
			this->Web->Size = System::Drawing::Size(84, 25);
			this->Web->TabIndex = 16;
			this->Web->TabStop = true;
			this->Web->Text = L"Website";
			this->Web->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::Web_LinkClicked);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// good
			// 
			this->good->AutoSize = true;
			this->good->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->good->Location = System::Drawing::Point(74, 975);
			this->good->Name = L"good";
			this->good->Size = System::Drawing::Size(23, 25);
			this->good->TabIndex = 17;
			this->good->Text = L"0";
			// 
			// bad
			// 
			this->bad->AutoSize = true;
			this->bad->ForeColor = System::Drawing::Color::Red;
			this->bad->Location = System::Drawing::Point(365, 975);
			this->bad->Name = L"bad";
			this->bad->Size = System::Drawing::Size(23, 25);
			this->bad->TabIndex = 18;
			this->bad->Text = L"0";
			// 
			// missing
			// 
			this->missing->AutoSize = true;
			this->missing->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->missing->Location = System::Drawing::Point(636, 975);
			this->missing->Name = L"missing";
			this->missing->Size = System::Drawing::Size(23, 25);
			this->missing->TabIndex = 19;
			this->missing->Text = L"0";
			// 
			// Clear
			// 
			this->Clear->Location = System::Drawing::Point(1326, 893);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(126, 41);
			this->Clear->TabIndex = 20;
			this->Clear->Text = L"Clear";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &MainForm::Clear_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1464, 1009);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->filenamelabel);
			this->Controls->Add(this->missing);
			this->Controls->Add(this->bad);
			this->Controls->Add(this->good);
			this->Controls->Add(this->Web);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->run);
			this->Controls->Add(this->openXML);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"FastMD5";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
				std::ifstream infile("FastMD5Temp.txt");
				if(infile){				
					string str;
					string filepath;
					while (getline(infile, str)) {
						filepath = str;
					}
					changeRich(gcnew String("Attempting to load file: " + 
						msclr::interop::marshal_as<System::String^>(filepath)));
					infile.close();
					remove("FastMD5Temp.txt");
					parseFile(gcnew String(filepath.c_str()));
					interMed();
				}				
			 }
	private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				if(!running){
					 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)  
					 {  
							changeRich("Loading from: " + openFileDialog1->FileName);
							resetCounters();
							parseFile(gcnew String(openFileDialog1->FileName));
					 }  
				}else{
					MessageBox::Show(gcnew String("Process is currently running"));	
				}
	}
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {}
	private: void parseFile(String^ filepath){
			try{					
				XML *parse = new XML(msclr::interop::marshal_as<std::string>(filepath));
				parse->Process();
				toFill = parse->returnMap();
				map<string, string>::iterator it;

				dataGridView1->Rows->Clear();

				int i = 0;
				for (it = toFill.begin(); it != toFill.end(); it++)
				{
					dataGridView1->Rows->Add();		
					dataGridView1->Rows[i]->Cells[0]->Value = i;
					dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(it->first.c_str()); 

					string hash = msclr::interop::marshal_as<std::string>(gcnew String(it->second.c_str()));
					std::transform(hash.begin(), hash.end(),hash.begin(), ::toupper);

					dataGridView1->Rows[i]->Cells[2]->Value = gcnew String(hash.c_str());

					changeRich(gcnew String("Loaded File: " + dataGridView1->Rows[i]->Cells[1]->Value + " Hash: " + dataGridView1->Rows[i]->Cells[2]->Value));
					i++;
				}			
			}catch(Exception^ e){richTextBox1->Text += "Error: " + e + "\n";}
	}
	private: System::Void Clear_Click(System::Object^  sender, System::EventArgs^  e) {
			richTextBox1->Text = "";
	}
	public: void changeRich(String^ text){
			richTextBox1->Text += text + "\n";
	}
	private: void incrementMissing(){
			missingCount++;
			missing->Text = gcnew String(System::Convert::ToString(missingCount));
	}
	private: void incrementGood(){
			goodCount++;
			good->Text = gcnew String(System::Convert::ToString(goodCount));
	}
	private: void incrementBad(){
			badCount++;
			bad->Text= gcnew String(System::Convert::ToString(badCount));
	}
	private: void resetCounters(){
			goodCount = 0;
			badCount = 0;
			missingCount = 0;
			good->Text = gcnew String(System::Convert::ToString(goodCount));
			bad->Text = gcnew String(System::Convert::ToString(badCount));
			missing->Text = gcnew String(System::Convert::ToString(missingCount));
	}
	private: System::Void run_Click(System::Object^  sender, System::EventArgs^  e) {	
			if(!running){
				interMed();	
			}else{
				MessageBox::Show(gcnew String("Process is currently running"));	
			}
	}
	private: void interMed(){
			progressBar1->Value = 0;
			resetCounters();
			startProcess();
	}
	private: void startProcess(){
			if(toFill.empty()){
				MessageBox::Show(gcnew String("No jobs in queue/map"));	
			}else{	
				changeRich(String::Concat("Executing"));
				Thread^ oThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::runOnCpuOnly));
				oThread->Start();
			}
	}
	private: System::Void Web_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			system("start https://oliverbathurst.wordpress.com/");
	}
	private: void runOnCpuOnly(){	
			running = true;
			CheckForIllegalCrossThreadCalls = false;
			map<string, string>::iterator it;
			MD5 md5;
			int i = 0;	

			for (it = toFill.begin(); it != toFill.end(); it++){					
				string filepath = msclr::interop::marshal_as<std::string>(gcnew String(it->first.c_str()));
				
				filenamelabel->Text = gcnew String(String::Concat("Processing: " + msclr::interop::marshal_as<System::String^>(filepath)));

				std::ifstream infile(filepath);
				if(infile.good()){	
					auto t1 = Clock::now();
					/////////////////////////
					string hashed = md5.digestFile(&filepath[0u]);
					/////////////////////////
					auto t2 = Clock::now();
					//calculate difference
					String^ timeCompleted = msclr::interop::marshal_as<System::String^>(to_string(std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()/1000));

					//convert hash to uppercase
					std::transform(hashed.begin(), hashed.end(),hashed.begin(), ::toupper);
					//put hash in table
					dataGridView1->Rows[i]->Cells[3]->Value = msclr::interop::marshal_as<System::String^>(hashed);
					///print time completed
					dataGridView1->Rows[i]->Cells[4]->Value = timeCompleted;
					////////////////////COMPARE///////////////////////////////////					
					if(msclr::interop::marshal_as<std::string>(dataGridView1->Rows[i]->Cells[3]->Value->ToString())
						==msclr::interop::marshal_as<std::string>(dataGridView1->Rows[i]->Cells[2]->Value->ToString())){
						dataGridView1->Rows[i]->Cells[5]->Value = gcnew String("Correct");
						dataGridView1->Rows[i]->Cells[5]->Style->BackColor = System::Drawing::Color::Green;
						incrementGood();
					}else{
						dataGridView1->Rows[i]->Cells[5]->Value = gcnew String("Bad");
						dataGridView1->Rows[i]->Cells[5]->Style->BackColor = System::Drawing::Color::Red;
						incrementBad();
					}
					/////////////////////////////////////////////////////////////

					changeRich(String::Concat("File: " + msclr::interop::marshal_as<System::String^>(filepath)
					+ " Hash: " + msclr::interop::marshal_as<System::String^>(hashed) + " Completed in: " + timeCompleted + "s"));					
				}else{
					changeRich(String::Concat("File: " + msclr::interop::marshal_as<System::String^>(filepath)
					+ " does not exist"));
					incrementMissing();
					dataGridView1->Rows[i]->Cells[5]->Value = gcnew String("Missing");
					dataGridView1->Rows[i]->Cells[5]->Style->BackColor = System::Drawing::Color::Orange;
				}
				i++;

				int progress = (i/toFill.size())*100;
				if(progress>100){
					progressBar1->Value = 100;
				}else{
					progressBar1->Value = progress;
				}
			}
			filenamelabel->Text = gcnew String("Completed");
			running = false;
		}
};
}