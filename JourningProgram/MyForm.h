#pragma once
#include <msclr/marshal_cppstd.h>
#include "JournalThing.h"


void RunSaveToFile();
namespace JourningProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;

	protected:

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
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(193, 44);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 0;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker1_ValueChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 81);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(523, 270);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(614, 94);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(594, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(253, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Choose The Day You Would Like to Look Back On ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(344, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(267, 31);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Journoling Program";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(117, 357);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(324, 127);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Click Me To Save!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 589);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Name = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	std::string SystemStringToStdString(System::String^ systemString) {
			return msclr::interop::marshal_as<std::string>(systemString);
		}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		String^ journalEntry = richTextBox1->Text;
		std::string stdJournalEntry = SystemStringToStdString(journalEntry);
		JournalHolder.MainText = stdJournalEntry;
		

		
	
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	

	
	JournalHolder.WriteToFile = true;
	RunSaveToFile();
}
private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

		String^ theDate = dateTimePicker1->Value.ToString("yyyy-MM-dd");
		std::string TheDateString = SystemStringToStdString(theDate);
	
}	
};
}
