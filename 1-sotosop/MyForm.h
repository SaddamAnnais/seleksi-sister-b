#pragma once
#include "filter.hpp"
#include <msclr/marshal_cppstd.h>
#include <opencv2\highgui\highgui.hpp>

namespace My1sotosop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr;
	using namespace msclr::interop;

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
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Label^ input_title;
	private: System::Windows::Forms::Label^ output_title;
	private: System::Windows::Forms::Button^ choose_file;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ filename_placeholder;

	private: String^ file_path;
	private: int chosen_filter = 1;

	private: System::Windows::Forms::RadioButton^ grayscale;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RadioButton^ contrast;
	private: System::Windows::Forms::Label^ c_value;
	private: System::Windows::Forms::RadioButton^ saturation;
	private: System::Windows::Forms::TextBox^ cvalue;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ filter_button;
	private: System::Windows::Forms::PictureBox^ output_image;






	protected:

	protected:

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
			this->title = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->filter_button = (gcnew System::Windows::Forms::Button());
			this->c_value = (gcnew System::Windows::Forms::Label());
			this->saturation = (gcnew System::Windows::Forms::RadioButton());
			this->cvalue = (gcnew System::Windows::Forms::TextBox());
			this->contrast = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->grayscale = (gcnew System::Windows::Forms::RadioButton());
			this->filename_placeholder = (gcnew System::Windows::Forms::Label());
			this->choose_file = (gcnew System::Windows::Forms::Button());
			this->input_title = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->output_image = (gcnew System::Windows::Forms::PictureBox());
			this->output_title = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->output_image))->BeginInit();
			this->SuspendLayout();
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->Location = System::Drawing::Point(253, 9);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(455, 66);
			this->title->TabIndex = 0;
			this->title->Text = L"Image FIlter using CUDA";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(25, 66);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::Tan;
			this->splitContainer1->Panel1->Controls->Add(this->panel1);
			this->splitContainer1->Panel1->Padding = System::Windows::Forms::Padding(6);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::Color::Tan;
			this->splitContainer1->Panel2->Controls->Add(this->panel2);
			this->splitContainer1->Panel2->ForeColor = System::Drawing::Color::Tan;
			this->splitContainer1->Panel2->Padding = System::Windows::Forms::Padding(6);
			this->splitContainer1->Size = System::Drawing::Size(957, 465);
			this->splitContainer1->SplitterDistance = 318;
			this->splitContainer1->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->filter_button);
			this->panel1->Controls->Add(this->c_value);
			this->panel1->Controls->Add(this->saturation);
			this->panel1->Controls->Add(this->cvalue);
			this->panel1->Controls->Add(this->contrast);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->grayscale);
			this->panel1->Controls->Add(this->filename_placeholder);
			this->panel1->Controls->Add(this->choose_file);
			this->panel1->Controls->Add(this->input_title);
			this->panel1->Location = System::Drawing::Point(9, 9);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(300, 447);
			this->panel1->TabIndex = 0;
			// 
			// filter_button
			// 
			this->filter_button->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->filter_button->Location = System::Drawing::Point(89, 392);
			this->filter_button->Name = L"filter_button";
			this->filter_button->Size = System::Drawing::Size(132, 38);
			this->filter_button->TabIndex = 10;
			this->filter_button->Text = L"Filter!";
			this->filter_button->UseVisualStyleBackColor = true;
			this->filter_button->Click += gcnew System::EventHandler(this, &MyForm::filter_button_Click);
			// 
			// c_value
			// 
			this->c_value->AutoSize = true;
			this->c_value->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->c_value->Location = System::Drawing::Point(23, 350);
			this->c_value->Name = L"c_value";
			this->c_value->Size = System::Drawing::Size(73, 20);
			this->c_value->TabIndex = 9;
			this->c_value->Text = L"C Value:";
			// 
			// saturation
			// 
			this->saturation->AutoSize = true;
			this->saturation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saturation->Location = System::Drawing::Point(27, 264);
			this->saturation->Name = L"saturation";
			this->saturation->Size = System::Drawing::Size(104, 24);
			this->saturation->TabIndex = 8;
			this->saturation->TabStop = true;
			this->saturation->Text = L"saturation";
			this->saturation->UseVisualStyleBackColor = true;
			this->saturation->CheckedChanged += gcnew System::EventHandler(this, &MyForm::saturation_CheckedChanged);
			// 
			// cvalue
			// 
			this->cvalue->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->cvalue->CausesValidation = false;
			this->cvalue->Enabled = false;
			this->cvalue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cvalue->Location = System::Drawing::Point(102, 347);
			this->cvalue->Name = L"cvalue";
			this->cvalue->Size = System::Drawing::Size(54, 27);
			this->cvalue->TabIndex = 7;
			this->cvalue->Text = "1";
			this->cvalue->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::cvalue_KeyPress);
			// 
			// contrast
			// 
			this->contrast->AutoSize = true;
			this->contrast->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contrast->Location = System::Drawing::Point(27, 234);
			this->contrast->Name = L"contrast";
			this->contrast->Size = System::Drawing::Size(91, 24);
			this->contrast->TabIndex = 6;
			this->contrast->TabStop = true;
			this->contrast->Text = L"contrast";
			this->contrast->UseVisualStyleBackColor = true;
			this->contrast->CheckedChanged += gcnew System::EventHandler(this, &MyForm::contrast_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(22, 176);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Filter";
			// 
			// grayscale
			// 
			this->grayscale->AutoSize = true;
			this->grayscale->Checked = true;
			this->grayscale->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grayscale->Location = System::Drawing::Point(27, 204);
			this->grayscale->Name = L"grayscale";
			this->grayscale->Size = System::Drawing::Size(102, 24);
			this->grayscale->TabIndex = 3;
			this->grayscale->TabStop = true;
			this->grayscale->Text = L"grayscale";
			this->grayscale->UseVisualStyleBackColor = true;
			this->grayscale->CheckedChanged += gcnew System::EventHandler(this, &MyForm::grayscale_CheckedChanged);
			// 
			// filename_placeholder
			// 
			this->filename_placeholder->AutoSize = true;
			this->filename_placeholder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->filename_placeholder->Location = System::Drawing::Point(22, 99);
			this->filename_placeholder->Name = L"filename_placeholder";
			this->filename_placeholder->Size = System::Drawing::Size(92, 25);
			this->filename_placeholder->TabIndex = 2;
			this->filename_placeholder->Text = L"Filename";
			// 
			// choose_file
			// 
			this->choose_file->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->choose_file->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->choose_file->Location = System::Drawing::Point(24, 127);
			this->choose_file->Name = L"choose_file";
			this->choose_file->Size = System::Drawing::Size(177, 30);
			this->choose_file->TabIndex = 1;
			this->choose_file->Text = L"choose_file";
			this->choose_file->UseVisualStyleBackColor = false;
			this->choose_file->Click += gcnew System::EventHandler(this, &MyForm::choose_file_Click);
			// 
			// input_title
			// 
			this->input_title->AutoSize = true;
			this->input_title->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_title->Location = System::Drawing::Point(17, 14);
			this->input_title->Name = L"input_title";
			this->input_title->Size = System::Drawing::Size(76, 41);
			this->input_title->TabIndex = 0;
			this->input_title->Text = L"Input";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel2->Controls->Add(this->output_image);
			this->panel2->Controls->Add(this->output_title);
			this->panel2->Location = System::Drawing::Point(9, 9);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(610, 447);
			this->panel2->TabIndex = 0;
			// 
			// output_image
			// 
			this->output_image->Location = System::Drawing::Point(20, 44);
			this->output_image->Name = L"output_image";
			this->output_image->Size = System::Drawing::Size(569, 386);
			this->output_image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->output_image->TabIndex = 2;
			this->output_image->TabStop = false;
			// 
			// output_title
			// 
			this->output_title->AutoSize = true;
			this->output_title->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output_title->ForeColor = System::Drawing::SystemColors::ControlText;
			this->output_title->Location = System::Drawing::Point(13, 14);
			this->output_title->Name = L"output_title";
			this->output_title->Size = System::Drawing::Size(95, 41);
			this->output_title->TabIndex = 1;
			this->output_title->Text = L"Output";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1006, 553);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->output_image))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void choose_file_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the OpenFileDialog class
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

	// Set the initial directory and filter properties of the dialog
	openFileDialog1->InitialDirectory = "C:\\";
	openFileDialog1->Filter = "Image files (*.bmp;*.jpg;*.jpeg;*.jpe;*.jp2;*.png)|*.bmp;*.jpg;*.jpeg;*.jpe;*.jp2;*.png";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;

	// Show the dialog
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Get the selected file path and name
		file_path = openFileDialog1->FileName;
		String^ fileName = openFileDialog1->SafeFileName;

		// Do something with the file path and name, such as display them in a textbox
		/*filename_placeholder->Text = filePath;*/
		choose_file->Text = fileName;
		output_image->Image = Image::FromFile(file_path);

	}
}

private: System::Void cvalue_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
		// If the key pressed is not a digit or a control key, suppress it
		e->Handled = true;
	}
}
private: System::Void grayscale_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = dynamic_cast<RadioButton^>(sender);
	if (selectedRadioButton->Checked) {
		// Do something when the radio button is selected
		chosen_filter = 1;
		cvalue->Enabled = false;
		cvalue->BackColor = System::Drawing::SystemColors::WindowFrame;
		cvalue->Text = "1";
	}
}
private: System::Void contrast_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = dynamic_cast<RadioButton^>(sender);
	if (selectedRadioButton->Checked) {
		// Do something when the radio button is selected
		chosen_filter = 2;
		cvalue->Enabled = true;
		cvalue->BackColor = System::Drawing::SystemColors::ScrollBar;
	}
}
private: System::Void saturation_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = dynamic_cast<RadioButton^>(sender);
	if (selectedRadioButton->Checked) {
		// Do something when the radio button is selected
		chosen_filter = 3;
		cvalue->Enabled = true;
		cvalue->BackColor = System::Drawing::SystemColors::ScrollBar;
	}
}
private: System::Void filter_button_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	std::string path_now = context.marshal_as<std::string>(file_path);
	cv::Mat shown_image;
	if (chosen_filter == 1) applyFilter(shown_image, chosen_filter, path_now, 0);
	else applyFilter(shown_image, chosen_filter, path_now, System::Convert::ToInt32(cvalue->Text));

	set2output(shown_image);
}
private: System::Void set2output(const cv::Mat& image) {
	Bitmap^ bmp;
	if (image.channels() == 1) {
		bmp = gcnew System::Drawing::Bitmap(
			image.cols, image.rows, image.step,
			System::Drawing::Imaging::PixelFormat::Format8bppIndexed,
			(System::IntPtr)image.data);
		// Set the color palette for the grayscale bitmap
		System::Drawing::Imaging::ColorPalette^ palette = bmp->Palette;
		for (int i = 0; i < 256; i++) {
			palette->Entries[i] = System::Drawing::Color::FromArgb(i, i, i);
		}
		bmp->Palette = palette;
	}
	else {
		bmp = gcnew System::Drawing::Bitmap(
			image.cols, image.rows, image.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			(System::IntPtr)image.data);
	}

	output_image->Image = bmp;
	output_image->Refresh();
}
};
}
