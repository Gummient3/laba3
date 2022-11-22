#include <string>
#include <cmath>
#include <cstdarg> 
#include <stdarg.h>
#include <iostream>
#include <cstdarg>
#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using std::string;
	using System::String;

	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	/// 
	/// 
	/// 
	
	
	

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		void zeroFormat(System::Windows::Forms::TextBox^ txt, System::Object^ sender) {
			

			if (txt->Text->Contains("00") && txt->TextLength == 2) {
				txt->Text = "0";
				txt->SelectionStart = txt->Text->Length;
			}
			
			
		}

		void notleadingzero(System::Windows::Forms::TextBox^ txt, System::Object^ sender) {
			if (txt->Text == "01") {
				txt->Text = System::Convert::ToChar(49).ToString();

			}
			else if (txt->Text == "02") {
				txt->Text = System::Convert::ToChar(50).ToString();

			}
			else if (txt->Text == "03") {
				txt->Text = System::Convert::ToChar(51).ToString();

			}
			else if (txt->Text == "04") {
				txt->Text = System::Convert::ToChar(52).ToString();

			}
			else if (txt->Text == "05") {
				txt->Text = System::Convert::ToChar(53).ToString();

			}
			else if (txt->Text == "06") {
				txt->Text = System::Convert::ToChar(54).ToString();

			}
			else if (txt->Text == "07") {
				txt->Text = System::Convert::ToChar(55).ToString();

			}
			else if (txt->Text == "08") {
				txt->Text = System::Convert::ToChar(56).ToString();

			}
			else if (txt->Text == "09") {
				txt->Text = System::Convert::ToChar(57).ToString();

			}
			else {
				zeroFormat(txt, sender);
			}


		}

		void Clear(System::Windows::Forms::TextBox^ txt1, System::Windows::Forms::TextBox^ txt2, System::Windows::Forms::TextBox^ txt3, System::Windows::Forms::TextBox^ txt4, System::Windows::Forms::TextBox^ txt5, System::Windows::Forms::Label^ lbl1) {
			txt1->Text = "";
			txt2->Text = "";
			txt3->Text = "";
			txt4->Text = "";
			txt5->Text = "";
			label7->Text = "";
			
			
		}

		/*void Clear1(System::Windows::Forms::TextBox num, ...)
		{
			va_list ap;
			int j;
			double sum = 0;

			va_start(ap, num); 
			for (j = 0; j < ; j++) {
				va_arg(ap, double); 

			}
			va_end(ap);
		}
			*/


		void formatfunc(System::Windows::Forms::KeyPressEventArgs^ e, System::Windows::Forms::TextBox^ txt) {

			if ((e->KeyChar <= 47 || e->KeyChar >= 58) && e->KeyChar != 8)
			{
				e->Handled = true;
			}
			if (e->KeyChar == ',' && txt->TextLength == 0) {
				txt->Text = "0,";
				//txt->SelectionStart = txt->Text->Length;
			}
			if (e->KeyChar == ',') {
				String^ s = txt->Text->ToString();
				int counter = 0;
				for (int x = 0; x < txt->TextLength; x++) {
					if (s[x] == ',') { counter++; }
				}
				if (counter < 1) {
					txt->Text += ",";
				}
				//txt->SelectionStart = txt->Text->Length;

			}
			try {
				if (txt->Text->ToString()[0] != '-' && txt->TextLength >= 1 && e->KeyChar == '-') {
					txt->Text = "-" + txt->Text;
					txt->SelectionStart = txt->Text->Length;


				}
				else if (txt->Text->ToString()[0] == '-' && txt->TextLength >= 1 && e->KeyChar == '-') {
					String^ tmptxt = "";

					for (int i = 1;;) {
						tmptxt += txt->Text[i];
						i++;
						if (i == txt->TextLength) {
							txt->Text = tmptxt;
							break;
						}
					}
					//txt->SelectionStart = txt->Text->Length;


				}
			}
			catch (...) {

			}






			if (e->KeyChar == 45 && txt->TextLength == 0) {
				String^ s = txt->Text->ToString();
				int counter = 0;
				for (int x = 0; x < txt->TextLength; x++) {
					if (s[x] == '-') { counter++; }
				}
				if (counter < 1) {
					txt->Text += "-";
				}
				//txt->SelectionStart = txt->Text->Length;
			}
			if (txt->Text == "-," && txt->TextLength == 2) {
				txt->Text = "-0,";
				//txt->SelectionStart = txt->Text->Length;
			}






			txt->SelectionStart = txt->Text->Length;

		}

		array<String^>^ calc(double a, double b, double c) {
			array<String^>^ managedArray = gcnew array<String^>(3);
			
			
			//label8->Text = System::Convert::ToString(D) + " " +  System::Convert::ToString(a) + " " + System::Convert::ToString(b) +" " + System::Convert::ToString(c);
			
			if (a) {
				double D = (b * b) - (4 * a * c);
				if (D < 0) {
					managedArray[0] = "-";
					managedArray[1] = "-";
					managedArray[2] = "В данном уравнении нет\nдействительный корней.";
				}
				else if (D > 0) {

					managedArray[0] = System::Convert::ToString(round(((-b + sqrt(D)) / (2 * a)) * 10000) / 10000); // round(((-b + sqrt(D))/(2*a))*10000)/10000
					managedArray[1] = System::Convert::ToString(round(((-b - sqrt(D)) / (2 * a)) * 10000) / 10000);
					managedArray[2] = System::Convert::ToString("Дискриминант > 0 (" + System::Convert::ToString(D) + ")." + " Уравнение \nимеет два действительных корня.");
				}
				else {
					managedArray[0] = System::Convert::ToString(round(((-b + sqrt(D)) / (2 * a)) * 10000) / 10000); // round(((-b + sqrt(D))/(2*a))*10000)/10000
					managedArray[1] = System::Convert::ToString(round(((-b - sqrt(D)) / (2 * a)) * 10000) / 10000);
					managedArray[2] = System::Convert::ToString("Дискриминант == 0." + " Уравнение \nимеет два действительных корня.");

				}

				return managedArray;

			}
			else if(a == 0 && b != 0){

				managedArray[0] = System::Convert::ToString(round(((-c / b) * 10000)) / 10000);
				managedArray[1] = "-";
				managedArray[2] = "Линейное уравнение";
				textBox5->Visible = false;
				label5->Visible = false;

				return managedArray;
				

			}
			else if (a + b + c == 0) {
				textBox5->Visible = false;
				label5->Visible = false;
				textBox4->Visible = false;
				label4->Visible = false;


				managedArray[0] = "-";
				managedArray[1] = "-";
				managedArray[2] = "0 = 0";

				return managedArray;
			}
			
			
				
		} // end func

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(32, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(32, 75);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox2_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(32, 120);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox3_KeyPress);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(168, 75);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 3;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(314, 75);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 174);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Сброс";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(168, 174);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Решить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(314, 174);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Закрыть";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"b =";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"c =";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(22, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"a =";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(140, 78);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"x1 =";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(281, 78);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"x2 =";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(260, 37);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Корни уравнения";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(201, 120);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 14;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 222);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		

		textBox5->Visible = true;
		label5->Visible = true;
		textBox4->Visible = true;
		label4->Visible = true;

		label7->Text = "";
		
		notleadingzero(this->textBox1, sender);

		

		



	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		notleadingzero(this->textBox2, sender);

		textBox5->Visible = true;
		label5->Visible = true;
		textBox4->Visible = true;
		label4->Visible = true;
		label7->Text = "";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка сброс
		Clear(this->textBox1, this->textBox2, this->textBox3, this->textBox4, this->textBox5, this->label7 );




	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка закрыть 
	this->Close();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // кнопка решить
	try {
		
		textBox4->Text = calc(System::Convert::ToDouble(textBox1->Text), System::Convert::ToDouble(textBox2->Text), System::Convert::ToDouble(textBox3->Text))[0];
		textBox5->Text = calc(System::Convert::ToDouble(textBox1->Text), System::Convert::ToDouble(textBox2->Text), System::Convert::ToDouble(textBox3->Text))[1];
		label7->Text = calc(System::Convert::ToDouble(textBox1->Text), System::Convert::ToDouble(textBox2->Text), System::Convert::ToDouble(textBox3->Text))[2];
	}
	catch (...) {

	}

	if (System::Convert::ToString(textBox1->Text) == "" || System::Convert::ToString(textBox2->Text) == "" || System::Convert::ToString(textBox3->Text) == "") {

		label7->Text = "Все поля должны быть заполнены";
		textBox4->Text = "";
		textBox5->Text = "";
	}
	
	

	
	
	
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
	

	formatfunc(e, this->textBox1);
	
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	notleadingzero(this->textBox3, sender);

	textBox5->Visible = true;
	label5->Visible = true;
	textBox4->Visible = true;
	label4->Visible = true;
	label7->Text = "";
}
private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	formatfunc(e, this->textBox3);
}
private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	formatfunc(e, this->textBox2);
}


};
}
