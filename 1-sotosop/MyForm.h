#pragma once
#include "filter.hpp"
#include <msclr/marshal_cppstd.h>
#include <opencv2/highgui/highgui.hpp>
#include <cuda_runtime.h>

#include <opencv2/videoio.hpp>

namespace My1sotosop {

	using namespace System;
	using namespace System::Threading;
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
			cudaSetDevice(0);
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

	private: String^ file_path = "";
	private: int chosen_filter = 1;
	private: void* d_input_global = NULL;
	private: void* d_output_global = NULL;
	private: int prevSize = 0;

	private: System::Windows::Forms::RadioButton^ grayscale;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RadioButton^ contrast;
	private: System::Windows::Forms::Label^ c_value;
	private: System::Windows::Forms::RadioButton^ saturation;
	private: System::Windows::Forms::TextBox^ cvalue;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ filter_button;
	private: System::Windows::Forms::PictureBox^ output_image;
	private: System::Windows::Forms::CheckBox^ camera_status;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	private: System::Windows::Forms::RadioButton^ boxBlur;
	private: System::Windows::Forms::RadioButton^ edge_detection;










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
			this->boxBlur = (gcnew System::Windows::Forms::RadioButton());
			this->camera_status = (gcnew System::Windows::Forms::CheckBox());
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
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->edge_detection = (gcnew System::Windows::Forms::RadioButton());
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
			this->panel1->Controls->Add(this->edge_detection);
			this->panel1->Controls->Add(this->boxBlur);
			this->panel1->Controls->Add(this->camera_status);
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
			// boxBlur
			// 
			this->boxBlur->AutoSize = true;
			this->boxBlur->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boxBlur->Location = System::Drawing::Point(27, 283);
			this->boxBlur->Name = L"boxBlur";
			this->boxBlur->Size = System::Drawing::Size(89, 24);
			this->boxBlur->TabIndex = 12;
			this->boxBlur->TabStop = true;
			this->boxBlur->Text = L"box blur";
			this->boxBlur->UseVisualStyleBackColor = true;
			this->boxBlur->CheckedChanged += gcnew System::EventHandler(this, &MyForm::boxBlur_CheckedChanged);
			// 
			// camera_status
			// 
			this->camera_status->AutoSize = true;
			this->camera_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->camera_status->Location = System::Drawing::Point(25, 51);
			this->camera_status->Name = L"camera_status";
			this->camera_status->Size = System::Drawing::Size(115, 29);
			this->camera_status->TabIndex = 11;
			this->camera_status->Text = L"Camera\?";
			this->camera_status->UseVisualStyleBackColor = true;
			this->camera_status->CheckedChanged += gcnew System::EventHandler(this, &MyForm::camera_status_CheckedChanged);
			// 
			// filter_button
			// 
			this->filter_button->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->filter_button->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->filter_button->Location = System::Drawing::Point(89, 392);
			this->filter_button->Name = L"filter_button";
			this->filter_button->Size = System::Drawing::Size(132, 38);
			this->filter_button->TabIndex = 10;
			this->filter_button->Text = L"Filter!";
			this->filter_button->UseVisualStyleBackColor = false;
			this->filter_button->Click += gcnew System::EventHandler(this, &MyForm::filter_button_Click);
			// 
			// c_value
			// 
			this->c_value->AutoSize = true;
			this->c_value->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->c_value->Location = System::Drawing::Point(23, 356);
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
			this->saturation->Location = System::Drawing::Point(27, 252);
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
			this->cvalue->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->cvalue->CausesValidation = false;
			this->cvalue->Enabled = false;
			this->cvalue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cvalue->Location = System::Drawing::Point(102, 353);
			this->cvalue->Name = L"cvalue";
			this->cvalue->Size = System::Drawing::Size(54, 27);
			this->cvalue->TabIndex = 7;
			this->cvalue->Text = L"1";
			this->cvalue->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::cvalue_KeyPress);
			// 
			// contrast
			// 
			this->contrast->AutoSize = true;
			this->contrast->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contrast->Location = System::Drawing::Point(27, 221);
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
			this->label2->Location = System::Drawing::Point(22, 163);
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
			this->grayscale->Location = System::Drawing::Point(27, 191);
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
			this->filename_placeholder->Location = System::Drawing::Point(22, 88);
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
			this->choose_file->Location = System::Drawing::Point(24, 116);
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
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			// 
			// edge_detection
			// 
			this->edge_detection->AutoSize = true;
			this->edge_detection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->edge_detection->Location = System::Drawing::Point(27, 312);
			this->edge_detection->Name = L"edge_detection";
			this->edge_detection->Size = System::Drawing::Size(184, 24);
			this->edge_detection->TabIndex = 13;
			this->edge_detection->TabStop = true;
			this->edge_detection->Text = L"sobel edge detection";
			this->edge_detection->UseVisualStyleBackColor = true;
			this->edge_detection->CheckedChanged += gcnew System::EventHandler(this, &MyForm::edge_detection_CheckedChanged);
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
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
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
	} else if (cvalue->Text->Length > 1 && e->KeyChar != 8) {
		e->Handled = true;
	}
}
private: System::Void grayscale_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = dynamic_cast<RadioButton^>(sender);
	if (selectedRadioButton->Checked) {
		chosen_filter = 1;
		cvalue->Enabled = false;
		cvalue->BackColor = System::Drawing::SystemColors::ButtonShadow;
	}
}
private: System::Void contrast_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = dynamic_cast<RadioButton^>(sender);
	if (selectedRadioButton->Checked) {
		chosen_filter = 2;
		cvalue->Enabled = true;
		cvalue->BackColor = System::Drawing::SystemColors::ScrollBar;
	}
}
private: System::Void saturation_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = dynamic_cast<RadioButton^>(sender);
	if (selectedRadioButton->Checked) {
		chosen_filter = 3;
		cvalue->Enabled = true;
		cvalue->BackColor = System::Drawing::SystemColors::ScrollBar;
	}
}
private: System::Void boxBlur_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = dynamic_cast<RadioButton^>(sender);
	if (selectedRadioButton->Checked) {
		chosen_filter = 4;
		cvalue->Enabled = true;
		cvalue->BackColor = System::Drawing::SystemColors::ScrollBar;
	}
}
private: System::Void edge_detection_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = dynamic_cast<RadioButton^>(sender);
	if (selectedRadioButton->Checked) {
		chosen_filter = 5;
		cvalue->Enabled = false;
		cvalue->BackColor = System::Drawing::SystemColors::ButtonShadow;
	}
}
private: System::Void filter_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (file_path != "") backgroundWorker1->RunWorkerAsync();
	else MessageBox::Show("You haven't chose an image!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error) ;
}



private: System::Void processImage() {
	msclr::interop::marshal_context context;
	std::string path_now = context.marshal_as<std::string>(file_path);

	cv::Mat input_image = cv::imread(path_now);
	cv::Mat shown_image(input_image.size(), CV_8UC3);

	void* d_input = d_input_global;
	void* d_output = d_output_global;

	int currentSize = input_image.cols * input_image.rows * sizeof(uchar3);

	// Allocate memory on the GPU
	if (d_input == NULL || d_output == NULL) {
		cudaMalloc(&d_input, currentSize);
		cudaMalloc(&d_output, currentSize);
		prevSize = currentSize;

	}
	else if (prevSize != currentSize) {

		// Free memory on the GPU
		cudaFree(d_input);
		cudaFree(d_output);

		// Allocate new memory on the GPU
		cudaMalloc(&d_input, currentSize);
		cudaMalloc(&d_output, currentSize);

		prevSize = currentSize;
	}


	if (chosen_filter == 1)
		applyFilter(input_image, shown_image, (uchar3*)d_input, (uchar3*)d_output, chosen_filter, path_now, 0, true);
	else applyFilter(input_image, shown_image, (uchar3*)d_input, (uchar3*)d_output, chosen_filter, path_now, System::Convert::ToInt32(cvalue->Text), true);

	Bitmap^ bmp;
	mat2bmp(shown_image, bmp);
	
	set2outputDelegate^ set2outputDel = gcnew set2outputDelegate(this, &MyForm::set2output);
	output_image->Invoke(set2outputDel, bmp);

	input_image.release();
	shown_image.release();

	d_input_global = d_input;
	d_output_global = d_output;
}

private: System::Void mat2bmp(const cv::Mat& mat_input, Bitmap^& bmp_output) {
	bmp_output = gcnew System::Drawing::Bitmap(
		mat_input.cols, mat_input.rows, mat_input.step,
		System::Drawing::Imaging::PixelFormat::Format24bppRgb,
		(System::IntPtr)mat_input.data);
}

private: delegate void set2outputDelegate(Bitmap^% bmp);

private: System::Void set2output(Bitmap^% bmp) {
	output_image->Image = bmp;
	output_image->Refresh();
}

private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	if (d_input_global != NULL) {
		void* d_input = d_input_global;
		cudaFree(d_input);
	}
	if (d_output_global != NULL) {
		void* d_output = d_output_global;
		cudaFree(d_output);
	}
}
private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	backgroundWorker1->ReportProgress(0);
	processImage();
}
private: System::Void backgroundWorker1_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
	if (e->ProgressPercentage == 0) {
		filter_button->Enabled = false;
		filter_button->BackColor = System::Drawing::SystemColors::ButtonShadow;

		choose_file->Enabled = false;
		choose_file->BackColor = System::Drawing::SystemColors::ButtonShadow;
	}
}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	filter_button->Enabled = true;
	filter_button->BackColor = System::Drawing::SystemColors::ButtonFace;

	choose_file->Enabled = true;
	choose_file->BackColor = System::Drawing::SystemColors::ScrollBar;
}
private: System::Void camera_status_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (camera_status->Checked) {
		backgroundWorker2->RunWorkerAsync();
		filter_button->Enabled = false;
		filter_button->BackColor = System::Drawing::SystemColors::ButtonShadow;

		choose_file->Enabled = false;
		choose_file->BackColor = System::Drawing::SystemColors::ButtonShadow;
	}
	else {
		filter_button->Enabled = true;
		filter_button->BackColor = System::Drawing::SystemColors::ButtonFace;

		choose_file->Enabled = true;
		choose_file->BackColor = System::Drawing::SystemColors::ScrollBar;
		output_image->Image = nullptr;
	}

}

private: System::Void processVideo() {
	cv::VideoCapture cap(0);

	if (!cap.isOpened()) {
		MessageBox::Show("Camera won't open!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	cv::Mat input_frame;
	cap.read(input_frame);
	cv::Mat output_frame(input_frame.size(), CV_8UC3);

	void* d_input = d_input_global;
	void* d_output = d_output_global;

	//cv::imshow("camera", input_frame);
	int currentSize = input_frame.cols * input_frame.rows * sizeof(uchar3);

	// Allocate memory on the GPU
	if (d_input == NULL || d_output == NULL) {
		cudaMalloc(&d_input, currentSize);
		cudaMalloc(&d_output, currentSize);
		prevSize = currentSize;

	}
	else if (prevSize != currentSize) {

		// Free memory on the GPU
		cudaFree(d_input);
		cudaFree(d_output);

		// Allocate new memory on the GPU
		cudaMalloc(&d_input, currentSize);
		cudaMalloc(&d_output, currentSize);

		prevSize = currentSize;
	}


	while (camera_status->Checked) {
		int int_cvalue = cvalue->Text == "" ? 1 : System::Convert::ToInt32(cvalue->Text);
		applyFilter(input_frame, output_frame, (uchar3*)d_input, (uchar3*)d_output, chosen_filter, "no_save", int_cvalue, false);

		Bitmap^ bmp;
		mat2bmp(output_frame, bmp);

		set2outputDelegate^ set2outputDel = gcnew set2outputDelegate(this, &MyForm::set2output);
		output_image->Invoke(set2outputDel, bmp);

		cap.read(input_frame);
	}

	input_frame.release();
	output_frame.release();

	d_input_global = d_input;
	d_output_global = d_output;
}
private: System::Void backgroundWorker2_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	processVideo();
}





};
}
