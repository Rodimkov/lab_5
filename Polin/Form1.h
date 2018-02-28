#pragma once
#include "..//lab_5_link/Polinom.h"
#include "msclr\marshal_cppstd.h"
#include <string>
#include <string.h>

namespace Polin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	Polinom apperand1,apperand2;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(79, 60);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(432, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(79, 101);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(432, 20);
			this->textBox2->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(79, 208);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(432, 20);
			this->textBox3->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(562, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(667, 429);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 check();

			 }

			 void check()
			 {

			 }

			 void insert1()
			 {

					string temp1;

					TMonom tmp = {0,0,0,0};
					TMonom oy = {0,0,0,0};


					temp1 = msclr::interop::marshal_as<string>(textBox1->Text);



					for(int i = 0; i < temp1.length() ; i++)
					{

						if( temp1[i] >= '0' && temp1[i] <= '9' ) 
						{
							char qwe = temp1[i];
							tmp.coeff = atoi(&qwe);
						}


						if( temp1[i] == 'x')
						{
							
							if( i != temp1.length() - 1)
							{
								if( temp1[i+1] == '^')
								{
									i = i + 2 ;
									char qwe = temp1[i];
									tmp.x = atoi(&qwe);
								}
								else
									tmp.x = 1;
							}
							else
								tmp.x = 1;					
						}
						else if( temp1[i] == 'y')
						{
							
							if( i != temp1.length() - 1)
							{
								if( temp1[i+1] == '^')
								{
									i = i + 2 ;
									char qwe = temp1[i];
									tmp.y = atoi(&qwe);
								}
								else
									tmp.y = 1;
							}
							else
								tmp.y = 1;					
						}
						else if( temp1[i] == 'z')
						{
							
							if( i != temp1.length() - 1)
							{
								if( temp1[i+1] == '^')
								{
									i = i + 2 ;
									char qwe = temp1[i];
									tmp.z = atoi(&qwe);
								}
								else
									tmp.z = 1;
							}
							else
								tmp.z = 1;					
						}
						else

						if(temp1[i] == '+')
						{
							apperand1.Insbyorder(tmp);
							tmp = oy;
						}
					}
					// tmp пуст
					apperand1.Insbyorder(tmp);
					tmp = oy;



					Polinom app;
					app = apperand1;
					app.Reset();
					tmp = app.Getcurr();
					textBox3->Text = System::Convert::ToString(tmp.coeff) + "*x^" +  System::Convert::ToString(tmp.x) + "*y^" +  System::Convert::ToString(tmp.y) + "*z^" +  System::Convert::ToString(tmp.z);


			 }

			 void insert2()
			 {
				//temp2 = msclr::interop::marshal_as<string>(textBox2->Text);
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 insert1();
				 insert2();
			 }
};
}

