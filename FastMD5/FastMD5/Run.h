

private: void runOnCpuOnly(){
		if(toFill.empty()){
				MessageBox::Show(gcnew String("No jobs in queue/map"));	
			}else{
				resetCounters();
				map<string, string>::iterator it;
				MD5 md5;
				int i = 0;	


				for (it = toFill.begin(); it != toFill.end(); it++){					
					string filepath = msclr::interop::marshal_as<std::string>(gcnew String(it->first.c_str()));
					filenamelabel->Text = gcnew String(String::Concat("Processing: " + msclr::interop::marshal_as<System::String^>(filepath)));

					std::ifstream infile(filepath);
					if(infile.good()){		

						string hashed = md5.digestFile(&filepath[0u]);
						std::transform(hashed.begin(), hashed.end(),hashed.begin(), ::toupper);
						dataGridView1->Rows[i]->Cells[3]->Value = msclr::interop::marshal_as<System::String^>(hashed);

						////////////////////COMPARE///////////////////////////////////					
						if(msclr::interop::marshal_as<std::string>(dataGridView1->Rows[i]->Cells[3]->Value->ToString())
							==msclr::interop::marshal_as<std::string>(dataGridView1->Rows[i]->Cells[2]->Value->ToString())){
							dataGridView1->Rows[i]->Cells[5]->Value = gcnew String("Correct");
							dataGridView1->Rows[i]->Cells[5]->Style->BackColor = System::Drawing::Color::Green;
							incrementGood();
						}
						/////////////////////////////////////////////////////////////

						changeRich(String::Concat("File: " + msclr::interop::marshal_as<System::String^>(filepath)
						+ " Hash: " + msclr::interop::marshal_as<System::String^>(hashed)));					
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
			}
}