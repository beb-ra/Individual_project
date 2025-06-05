#pragma once
// Copyright 2025 Guseva Olga

#include <string>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include "/Users/Lelya/cc++/Individual_project/Library/User/user.h"
#include "/Users/Lelya/cc++/Individual_project/Library/TVector/tvector.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
		~Login()
		{
			if (components)
			{
				delete components;
				delete users;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	protected:
	protected:
	private: System::Windows::Forms::Label^ LoginText;
	private: System::Windows::Forms::Label^ PasswordText;
	private: System::Windows::Forms::Button^ buttonEnterLogPass;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->LoginText = (gcnew System::Windows::Forms::Label());
			this->PasswordText = (gcnew System::Windows::Forms::Label());
			this->buttonEnterLogPass = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Location = System::Drawing::Point(171, 151);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(203, 22);
			this->textBoxLogin->TabIndex = 0;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(171, 280);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(203, 22);
			this->textBoxPassword->TabIndex = 1;
			// 
			// LoginText
			// 
			this->LoginText->AutoSize = true;
			this->LoginText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LoginText->Location = System::Drawing::Point(164, 86);
			this->LoginText->Name = L"LoginText";
			this->LoginText->Size = System::Drawing::Size(96, 38);
			this->LoginText->TabIndex = 3;
			this->LoginText->Text = L"Login";
			// 
			// PasswordText
			// 
			this->PasswordText->AutoSize = true;
			this->PasswordText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PasswordText->Location = System::Drawing::Point(164, 223);
			this->PasswordText->Name = L"PasswordText";
			this->PasswordText->Size = System::Drawing::Size(162, 38);
			this->PasswordText->TabIndex = 4;
			this->PasswordText->Text = L"Password";
			// 
			// buttonEnterLogPass
			// 
			this->buttonEnterLogPass->Location = System::Drawing::Point(213, 348);
			this->buttonEnterLogPass->Name = L"buttonEnterLogPass";
			this->buttonEnterLogPass->Size = System::Drawing::Size(97, 49);
			this->buttonEnterLogPass->TabIndex = 5;
			this->buttonEnterLogPass->Text = L"Enter";
			this->buttonEnterLogPass->UseVisualStyleBackColor = true;
			this->buttonEnterLogPass->Click += gcnew System::EventHandler(this, &Login::buttonEnterLogPass_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(606, 462);
			this->Controls->Add(this->buttonEnterLogPass);
			this->Controls->Add(this->PasswordText);
			this->Controls->Add(this->LoginText);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->textBoxLogin);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: void LoadUsers() {
	/*
	std::ifstream file("\\Users\\Lelya\\cc++\\Individual_project\\Library\\User\\users_data.txt");
	if (!file.is_open()) {
		System::Windows::Forms::MessageBox::Show(
			"The file not found!", "Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		size_t delimiter_pos = line.find(' ');
		std::string login = line.substr(0, delimiter_pos);
		std::string password = line.substr(delimiter_pos + 1);
		users->push_back(User(login, password));
	}
	file.close();
	*/
}
	private: System::Void buttonEnterLogPass_Click(System::Object^ sender, System::EventArgs^ e) {
		/*
		std::string login = msclr::interop::
			marshal_as<std::string>(textBoxLogin->Text);
		std::string password = msclr::interop::
			marshal_as<std::string>(textBoxPassword->Text);
		if (login == "" || password == "") {
			System::Windows::Forms::MessageBox::Show(
				"Enter your username and password!", "Error",
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
				System::Windows::Forms::MessageBox::Show(
					"You successfully logged in", "Success");
			}
			else {
				System::Windows::Forms::MessageBox::Show(
					"The user is not registered!", "Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}
		catch (const std::exception& ex) {
			MessageBox::Show(gcnew System::String(ex.what()), "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		*/
	}
};
}
