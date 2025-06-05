#pragma once

#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <string>

#include "/Users/Lelya/cc++/Individual_project/Library/User/user.h"
#include "/Users/Lelya/cc++/Individual_project/Library/TVector/tvector.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	private:
		TVector<User>* users;
	public:
		Login(void)
		{
			InitializeComponent();
			users = new TVector<User>();
			LoadUsers();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
				delete users;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	protected:

	private: System::Windows::Forms::TextBox^ textBoxPassword;
	protected:

	protected:

	private: System::Windows::Forms::Button^ buttonLogin;
	private: System::Windows::Forms::Button^ buttonRegistration;
	private: System::Windows::Forms::Label^ labelLogin;
	private: System::Windows::Forms::Label^ labelPassword;



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
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonLogin = (gcnew System::Windows::Forms::Button());
			this->buttonRegistration = (gcnew System::Windows::Forms::Button());
			this->labelLogin = (gcnew System::Windows::Forms::Label());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Location = System::Drawing::Point(129, 89);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(154, 22);
			this->textBoxLogin->TabIndex = 0;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(129, 188);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(154, 22);
			this->textBoxPassword->TabIndex = 1;
			// 
			// buttonLogin
			// 
			this->buttonLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonLogin->Location = System::Drawing::Point(149, 235);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = System::Drawing::Size(104, 44);
			this->buttonLogin->TabIndex = 2;
			this->buttonLogin->Text = L"Sign in";
			this->buttonLogin->UseVisualStyleBackColor = true;
			this->buttonLogin->Click += gcnew System::EventHandler(this, &Login::buttonLogin_Click);
			// 
			// buttonRegistration
			// 
			this->buttonRegistration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonRegistration->Location = System::Drawing::Point(129, 311);
			this->buttonRegistration->Name = L"buttonRegistration";
			this->buttonRegistration->Size = System::Drawing::Size(154, 31);
			this->buttonRegistration->TabIndex = 3;
			this->buttonRegistration->Text = L"Create account";
			this->buttonRegistration->UseVisualStyleBackColor = true;
			this->buttonRegistration->Click += gcnew System::EventHandler(this, &Login::buttonRegistration_Click);
			// 
			// labelLogin
			// 
			this->labelLogin->AutoSize = true;
			this->labelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelLogin->Location = System::Drawing::Point(122, 37);
			this->labelLogin->Name = L"labelLogin";
			this->labelLogin->Size = System::Drawing::Size(96, 38);
			this->labelLogin->TabIndex = 4;
			this->labelLogin->Text = L"Login";
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPassword->Location = System::Drawing::Point(122, 137);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(162, 38);
			this->labelPassword->TabIndex = 5;
			this->labelPassword->Text = L"Password";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 374);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->labelLogin);
			this->Controls->Add(this->buttonRegistration);
			this->Controls->Add(this->buttonLogin);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->textBoxLogin);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void LoadUsers() {
		std::ifstream file("C:\\Users\\Lelya\\cc++\\Individual_project\\Library\\User\\users_data.csv");
		if (!file.is_open()) {
			System::Windows::Forms::MessageBox::Show("The file not found", "Error", 
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);
			return;
		}

		std::string line;
		while (std::getline(file, line)) {
			size_t first_delim_pos = line.find(';');
			if (first_delim_pos == std::string::npos) {
				System::Windows::Forms::MessageBox::Show("There is not ;", "Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
				continue;
			}

			size_t second_delim_pos = line.find(';', first_delim_pos + 1);
			if (second_delim_pos == std::string::npos) {
				System::Windows::Forms::MessageBox::Show("There is not second ;", "Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
				continue;
			}

			std::string login = line.substr(0, first_delim_pos);
			std::string password = line.substr(first_delim_pos + 1, second_delim_pos - first_delim_pos - 1);
			std::string status_str = line.substr(second_delim_pos + 1);

			
			UserStatus status = UserStatus::Other;
			if (status_str == "Director") {
				status = UserStatus::Director;
			}
			else if (status_str == "Administrator") {
				status = UserStatus::Administrator;
			}
			else if (status_str == "Librarian") {
				status = UserStatus::Librarian;
			}
			
			users->push_back(User(login, password));
		}
		file.close();
		/*
		std::string line;
		while (std::getline(file, line)) {
			size_t delimiter_pos = line.find(';');
			std::string login = line.substr(0, delimiter_pos);
			std::string password = line.substr(delimiter_pos + 1);
			
			users->push_back(User(login, password));
		}
		file.close();
		*/
	}

	private: System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string login = msclr::interop::marshal_as<std::string>(textBoxLogin->Text);
		std::string password = msclr::interop::marshal_as<std::string>(textBoxPassword->Text);
		if (login == "" || password == "") {
			System::Windows::Forms::MessageBox::Show("Enter your username and password!", "Error",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);
			return;
		}

		try {
			User temporary_user(login, password);
			bool found = false;
			for (size_t i = 0; i < users->size(); i++) {
				if (users->at(i) == temporary_user) {
					found = true;
					break;
				}
			}
			if (found) {
				textBoxLogin->Text = "";
				textBoxPassword->Text = "";
				System::Windows::Forms::MessageBox::Show("You successfully logged in", "Success");
			}
			else {
				textBoxLogin->Text = "";
				textBoxPassword->Text = "";
				System::Windows::Forms::MessageBox::Show("Incorrect login or password", "Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}
		catch (const std::exception& ex) {
			MessageBox::Show(gcnew System::String(ex.what()), "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void buttonRegistration_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::MessageBox::Show("There will be registation window", "Success");
}
};
}
