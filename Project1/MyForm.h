#pragma once

namespace Project1 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace MySql::Data::MySqlClient;
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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  textBox2;



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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(411, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(456, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"cari";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(10, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L" ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(9, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(225, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"String Matching dengan KMP";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 83);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(519, 139);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellClick_1);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 228);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(519, 117);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(543, 357);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	
	MySqlDataAdapter ^ sda = gcnew MySqlDataAdapter();
	BindingSource^ bSource = gcnew BindingSource();

	Char ToUpperCase(char text) {

		text &= 0xdf;
		return text;
	}

	Char ToLowerCase(char huruf) {

		huruf &= 0x20;
		return huruf;
	}


	void prefix(int m, char P[], int kmp[])
	{
		int k = 0, q;
		kmp[1] = 0;
		for (q = 2; q <= m; q++)
		{
			while (k>0 && P[k + 1] != P[q])
			{
				k = kmp[k];
			}
			if (P[k + 1] == P[q])
			{
				k++;
			}
			kmp[q] = k;
		}
	}
	


	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int i,w,row_num,length_txt, length_pat,a,b,kmp[100],x=0,q;
		String^ isi;
		char T[10000];
		char P[100];
		String^ pattern = textBox1->Text;
		row_num = dataGridView1->RowCount-1;
		int result[100],ketemu;
		for (w = 0; w < row_num; w++) {
			ketemu = 0;
			isi = dataGridView1->Rows[w]->Cells["isi"]->Value + "";
			length_txt = isi->Length;
			
			length_pat = pattern->Length;
			for (a = 1; a <= length_txt; a++)//merubah indeks dari 0 menjadi 1
			{
				T[a] = isi[a - 1];
			}

			for (b = 1; b <= length_pat; b++)//merubah indeks dari 0 menjadi 1
			{
				P[b] = pattern[b - 1];
			}
			//KMPSearch(isi, pattern);

			prefix(length_pat, P, kmp);

			q = 0;
			for (i = 1; i <= length_txt; i++)
			{
				while (q>0 && P[q + 1] != T[i] )
				{
					q = kmp[q];
				}
			
				if (P[q + 1] == T[i] || P[q + 1]== ToUpperCase(T[i]) || P[q + 1]== ToLowerCase(T[i]))
				{
					q++;
				}
				
				if (q == length_pat)
				{
					x = 1;
					MessageBox::Show("Found pattern at index " + (i + 1 - length_pat) + " in file number " + (w+1));
					q = kmp[q];
				}

			}

		}
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void textBox2_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void dataGridView1_CellClick_1(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	textBox2->Text = dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value + "";
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	String^ constring = L"datasource=localhost;port=3306;username=root;password=";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from kmp_abstrak.abstrak;", conDataBase);
	MySqlDataReader^ myReader;

	try {
		DataTable^ dbdataset = gcnew DataTable();
		sda->SelectCommand = cmdDataBase;
		
		sda->Fill(dbdataset);
		

		bSource->DataSource = dbdataset;
		dataGridView1->DataSource = bSource;
		sda->Update(dbdataset);

	}
	catch (Exception^ex) {
		MessageBox::Show(ex->Message);
	}
}
};
}
