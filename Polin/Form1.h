#pragma once
#include "..//lab_5_link/Polinom.h"
#include "msclr\marshal_cppstd.h"
#include <string.h>

namespace Polin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	Polinom apperand1,apperand2,res;
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

	protected: 


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;




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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(263, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 48);
			this->button1->TabIndex = 3;
			this->button1->Text = L"добавить в первый полином";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(145, 55);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"0";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(145, 81);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(145, 107);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"0";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(145, 133);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 7;
			this->textBox4->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"коэффициент";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"степень \"x\"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(48, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"степень \"y\"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(48, 136);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"степень \"z\"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(48, 272);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"label5";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(263, 104);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 49);
			this->button2->TabIndex = 13;
			this->button2->Text = L"добавить во второй полином";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(48, 305);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"label6";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(473, 58);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 16;
			this->button3->Text = L"+";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(473, 87);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 24);
			this->button4->TabIndex = 17;
			this->button4->Text = L"-";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(473, 117);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 18;
			this->button5->Text = L"*";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(48, 353);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"label7";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(362, 262);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(154, 42);
			this->button6->TabIndex = 20;
			this->button6->Text = L"записать результать в первый операнд ";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(362, 310);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(154, 42);
			this->button7->TabIndex = 21;
			this->button7->Text = L"записать результать во второй операнд ";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(667, 429);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void input()
		{
			TMonom tmp;
			label5->Text = "";
			label6->Text = "";
			apperand1.Reset();
			if(!apperand1.isEnd())
			{
				tmp = apperand1.Getcurr();

				
				label5->Text +=  System::Convert::ToString(tmp.coeff);
				if(tmp.x !=0)
					label5->Text +=  "*x^" + System::Convert::ToString(tmp.x);
				if(tmp.y !=0)
					label5->Text +=  "*y^" + System::Convert::ToString(tmp.y);					
				if(tmp.z !=0)
					label5->Text +=  "*z^" + System::Convert::ToString(tmp.z);					
				
				label5->Text += " ";								
												
				apperand1.GoNext();

				for(;!apperand1.isEnd();apperand1.GoNext())
				{
					tmp = apperand1.Getcurr();
					if(tmp.coeff > 0)
						label5->Text += "+" + System::Convert::ToString(tmp.coeff);
					else 
						label5->Text +=  System::Convert::ToString(tmp.coeff);
					if(tmp.x !=0)
						label5->Text +=  "*x^" + System::Convert::ToString(tmp.x);
					if(tmp.y !=0)
						label5->Text +=  "*y^" + System::Convert::ToString(tmp.y);					
					if(tmp.z !=0)
						label5->Text +=  "*z^" + System::Convert::ToString(tmp.z);	
					label5->Text += " ";								

				}
			}

			apperand2.Reset();
			if(!apperand2.isEnd())
			{
				tmp = apperand2.Getcurr();

				
				label6->Text +=  System::Convert::ToString(tmp.coeff);
				if(tmp.x !=0)
					label6->Text +=  "*x^" + System::Convert::ToString(tmp.x);
				if(tmp.y !=0)
					label6->Text +=  "*y^" + System::Convert::ToString(tmp.y);					
				if(tmp.z !=0)
					label6->Text +=  "*z^" + System::Convert::ToString(tmp.z);					
				
				label6->Text += " ";								
												
				apperand2.GoNext();

				for(;!apperand2.isEnd();apperand2.GoNext())
				{
					tmp = apperand2.Getcurr();
					if(tmp.coeff > 0)
						label6->Text += "+" + System::Convert::ToString(tmp.coeff);
					else 
						label6->Text +=  System::Convert::ToString(tmp.coeff);
					if(tmp.x !=0)
						label6->Text +=  "*x^" + System::Convert::ToString(tmp.x);
					if(tmp.y !=0)
						label6->Text +=  "*y^" + System::Convert::ToString(tmp.y);					
					if(tmp.z !=0)
						label6->Text +=  "*z^" + System::Convert::ToString(tmp.z);	
					label6->Text += " ";								

				}
			}
		}

		void inres()
		{
			label7->Text = "";
			TMonom tmp;
			res.Reset();
			tmp = res.Getcurr();
			if(!res.isEnd())
			{

				
				label7->Text +=  System::Convert::ToString(tmp.coeff);
				if(tmp.x !=0)
					label7->Text +=  "*x^" + System::Convert::ToString(tmp.x);
				if(tmp.y !=0)
					label7->Text +=  "*y^" + System::Convert::ToString(tmp.y);					
				if(tmp.z !=0)
					label7->Text +=  "*z^" + System::Convert::ToString(tmp.z);					
				
				label7->Text += " ";								
				res.GoNext();

				for(;!res.isEnd();res.GoNext())
				{
					tmp = res.Getcurr();
					if(tmp.coeff > 0)
						label7->Text += "+" + System::Convert::ToString(tmp.coeff);
					else 
						label7->Text +=  System::Convert::ToString(tmp.coeff);
					if(tmp.x !=0)
						label7->Text +=  "*x^" + System::Convert::ToString(tmp.x);
					if(tmp.y !=0)
						label7->Text +=  "*y^" + System::Convert::ToString(tmp.y);					
					if(tmp.z !=0)
						label7->Text +=  "*z^" + System::Convert::ToString(tmp.z);

					label7->Text += " ";								
							

				}
			}
		}



private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 string str = msclr::interop::marshal_as<string>(textBox1->Text) + 
							 msclr::interop::marshal_as<string>(textBox2->Text) + 
							 msclr::interop::marshal_as<string>(textBox3->Text) + 
							 msclr::interop::marshal_as<string>(textBox4->Text);

			 TMonom tmp;

			 char s = str[0];
			 tmp.coeff = System::Convert::ToDouble(str[0]) - 48.0;
			 tmp.x = System::Convert::ToInt32(str[1]) - 48 ;
			 tmp.y = System::Convert::ToInt32(str[2]) - 48 ;
			 tmp.z = System::Convert::ToInt32(str[3]) - 48;
			 
			 apperand1.Insbyorder(tmp);

			 input();
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

			 string str = msclr::interop::marshal_as<string>(textBox1->Text) + 
							msclr::interop::marshal_as<string>(textBox2->Text) + 
							msclr::interop::marshal_as<string>(textBox3->Text) + 
							msclr::interop::marshal_as<string>(textBox4->Text);

			 TMonom tmp;
			 char s = str[0];
			 tmp.coeff = System::Convert::ToDouble(str[0]) - 48.0;
			 tmp.x = System::Convert::ToInt32(str[1]) - 48 ;
			 tmp.y = System::Convert::ToInt32(str[2]) - 48 ;
			 tmp.z = System::Convert::ToInt32(str[3]) - 48;
			 
			 apperand2.Insbyorder(tmp);

			 input();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 res = apperand1 + apperand2;
			 inres();
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			label7->Text = "";
			label5->Text = "";
			label6->Text = "";
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 res = apperand1 - apperand2;
			 inres();
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 res = apperand1 + apperand2;
			 inres();
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 apperand1 = res;
			 input();
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 apperand1 = res;
			 input();
		 }
};
}

