#pragma once

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


namespace maxmatching {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(56, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите размер графа: ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(56, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(211, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Введите элементы графа:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(515, 195);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(236, 52);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Сгенерировать граф \r\nс помощью случайных чисел";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(54, 409);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(395, 21);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Результат поска максимального паросочетания:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(515, 525);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(236, 52);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Сохранить результат \r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(515, 455);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(236, 52);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Получить результат";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(60, 125);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dataGridView1->RowHeadersWidth = 40;
			this->dataGridView1->Size = System::Drawing::Size(347, 236);
			this->dataGridView1->TabIndex = 9;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->ColumnHeadersVisible = false;
			this->dataGridView2->Location = System::Drawing::Point(147, 452);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(158, 173);
			this->dataGridView2->TabIndex = 10;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(515, 125);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(236, 52);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Ввести элементы графа самостоятельно";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(258, 32);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 12;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(824, 665);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Поиск максимального паросочетания";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		
	int n;

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}


private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}   

private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	n = (int)numericUpDown1->Value;
	int n_last_first_part = n / 2;

	if (n == 0) { MessageBox::Show("Введите размер графа!"); }

	dataGridView1->RowCount = n;
	dataGridView1->ColumnCount = n;
	dataGridView1->TopLeftHeaderCell->Value = "Граф G";

	//srand(time(0));
	for (int i = 0; i < n; i++) {					//формирование матрицы смежности М
		for (int j = 0; j < n; j++) {				//для самостоятельного заполнения
			dataGridView1->Rows[i]->Cells[j]->Value = 0;
		}
		dataGridView1->Rows[i]->HeaderCell->Value = System::Convert::ToString(i + 1);
		dataGridView1->Columns[i]->HeaderCell->Value = System::Convert::ToString(i + 1);
	}

}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		n = (int)numericUpDown1->Value;
		int n_last_first_part = n / 2;
		
		if (n == 50) { MessageBox::Show("Предупреждение: максимальный размер графа = 50"); }
		if (n == 0) { MessageBox::Show("Введите размер графа!"); }

		dataGridView1->RowCount = n;
		dataGridView1->ColumnCount = n;
		dataGridView1->TopLeftHeaderCell->Value = "Граф G";

		srand(time(0));
		for (int i = 0; i < n; i++) {					//формирование матрицы смежности М
			for (int j = 0; j < n; j++) {
				
				
				if (j < n_last_first_part && i < n_last_first_part) {
					dataGridView1->Rows[i]->Cells[j]->Value = 0;
				}
				else {
					if (j >= n_last_first_part && i >= n_last_first_part) {
						dataGridView1->Rows[i]->Cells[j]->Value = 0;
					}
					else {
						if (i == j) dataGridView1->Rows[i]->Cells[j]->Value = 0;
						else {
							dataGridView1->Rows[i]->Cells[j]->Value = rand() % 2;
							dataGridView1->Rows[j]->Cells[i]->Value = dataGridView1->Rows[i]->Cells[j]->Value;
						}
					}
				}		
			}
			dataGridView1->Rows[i]->HeaderCell->Value = System::Convert::ToString(i + 1);
			dataGridView1->Columns[i]->HeaderCell->Value = System::Convert::ToString(i + 1);
			
		}

}

	   bool DFS(int v, int n, int* tops_visited, int* matching) {
		   if (tops_visited[v] == 1) return false;
		   tops_visited[v] = 1;
		   for (int i = 0; i < n; i++) {

			   Object^ tmp = dataGridView1->Rows[v]->Cells[i]->Value;
			   int tmp_int = System::Convert::ToInt64(tmp);

			   if (tmp_int > 0) {
				   if ((matching[i] == -1) || (DFS(matching[i], n, tops_visited, matching))) {
					   matching[i] = v;
					   return true;
				   }

			   }

		   }
		   return false;
	   }


private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

	  

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (n == 0) { MessageBox::Show("Введите размер графа!"); }

	int flag_orient = 0;
	for (int i = 0; i < n; i++) {					
		for (int j = 0; j < n; j++) {
			if (i != j) {
				Object^ tmp1 = dataGridView1->Rows[j]->Cells[i]->Value;
				int tmp1_int = System::Convert::ToInt64(tmp1);

				Object^ tmp2 = dataGridView1->Rows[i]->Cells[j]->Value;
				int tmp2_int = System::Convert::ToInt64(tmp2);

				if (tmp1_int != tmp2_int) {
					flag_orient++;
				}
			}
			
		}
	}
	if (flag_orient > 0) MessageBox::Show("Предупреждение: задан ориентированный граф");

		int* tops_visited = (int*)malloc(n * sizeof(int*));

		int* matching = (int*)malloc(n * sizeof(int*));
		memset(matching, -1, n * sizeof(int*));


		for (int i = 0; i < n; i++) {						//алг Куна
			for (int i_i = 0; i_i < n; i_i++) {
				tops_visited[i_i] = 0;
			}

			DFS(i, n, tops_visited, matching);
		}

		int n_last_first_part = n / 2;
		
		
		int* mas_already_output = (int*)malloc(n * sizeof(int*));
		memset(mas_already_output, 0, n * sizeof(int*));

		int flag_already_out = 0;

		int size_dataGridView2 = 0;
		
			for (int i = 0; i < n; i++) {
				if (matching[i] + 1 != 0) {

					flag_already_out = 0;

					for (int i_already = 0; i_already < n; i_already++) {
						if (matching[i] + 1 == mas_already_output[i_already]) flag_already_out = 1;
					}
					if (flag_already_out == 1) continue;

					mas_already_output[i] = i + 1;
					size_dataGridView2++;
				}
			}
		

		this->dataGridView2->ColumnCount = 2;
		this->dataGridView2->RowCount = size_dataGridView2;

		

		int i_row = 0;
		for (int i = 0; i < n; i++) {
			if (matching[i] + 1 != 0) {

				flag_already_out = 0;

				for (int i_already = 0; i_already < n; i_already++) {
					if (matching[i] + 1 == mas_already_output[i_already]) flag_already_out = 1;
				}

				if (flag_already_out == 1) continue;

				this->dataGridView2->Rows[i_row]->Cells[0]->Value = matching[i]+1;
				this->dataGridView2->Rows[i_row]->Cells[1]->Value = i + 1;
				i_row++;
			}		
		}
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (n == 0) { MessageBox::Show("Введите размер графа!"); }
	else {
		int n_last_first_part = n / 2;
		FILE* file;

		file = fopen("max_matching.txt", "w");

		int size_dataGridView2 = dataGridView2->RowCount;

		for (int i = 0; i < size_dataGridView2; i++) {
			for (int j = 0; j < 2; j++) {

				Object^ tmp = dataGridView2->Rows[i]->Cells[j]->Value;
				int tmp_el = System::Convert::ToInt64(tmp);

				fprintf(file, "%d", tmp_el);
				if (j == 0) fprintf(file, " - ");
			}

			fprintf(file, "\n");
		}
		fclose(file);

		MessageBox::Show("Результат успешно сохранен в файл.");
	}
}



private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}

};
}
