#pragma once
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <PowrProf.h>
#include <string>
#include <sstream>
#include <msclr\marshal_cppstd.h>


bool applyVideoTimeout(DWORD);
int showVideoTimeout();
using namespace System::Runtime::InteropServices;

char * and_SysStringToChar(System::String^ string)
{
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}

System::String^ toSystemString(std::string  stdString){
	return msclr::interop::marshal_as<System::String^>(stdString);
}

namespace courseWorkWithWindows {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

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
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 187);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(71, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Battery status:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(71, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"AC/Battery:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(71, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"battery life:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(71, 64);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"battery left:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(71, 81);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Battery full:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(71, 98);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(110, 20);
			this->textBox1->TabIndex = 6;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(173, 187);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"getValue";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(259, 13);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Before start value:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(357, 13);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(33, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"value";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(262, 98);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"label8";
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(601, 328);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		};
		bool applyVideoTimeout(DWORD newtimeOut)
		{
			SYSTEM_POWER_POLICY powerPolicy;
			DWORD ret;
			DWORD size = sizeof(SYSTEM_POWER_POLICY);

			ret = CallNtPowerInformation(SystemPowerPolicyAc, nullptr, 0, &powerPolicy, size);

			if ((ret != ERROR_SUCCESS) || (size != sizeof(SYSTEM_POWER_POLICY)))
			{
				return false;
			}

			powerPolicy.VideoTimeout = newtimeOut;
			ret = CallNtPowerInformation(SystemPowerPolicyAc, &powerPolicy, size, nullptr, 0);

			if ((ret != ERROR_SUCCESS))
			{
				return false;
			}

			return true;
		}
		int showVideoTimeout()
		{
			SYSTEM_POWER_POLICY powerPolicy;
			DWORD ret;
			DWORD size = sizeof(SYSTEM_POWER_POLICY);

			ret = CallNtPowerInformation(SystemPowerPolicyAc, nullptr, 0, &powerPolicy, size);

			if ((ret != ERROR_SUCCESS) || (size != sizeof(SYSTEM_POWER_POLICY)))
			{
				return 0;
			}

			std::cout << powerPolicy.VideoTimeout << std::endl;
			return powerPolicy.VideoTimeout;
		}
		/**
		* The AC power status
		*/
		string getACLineStatusString(BYTE ACLineStatus) {
			switch (ACLineStatus) {
			case (0) : return "Offline";
			case (1) : return "Online";
			default: return "Unknown";
			}
		}
		/**
		* The battery charge status
		*/
		string getBatteryFlagString(BYTE BatteryFlag) {
			switch (BatteryFlag) {
			case (1) : return "High, more than 66 percent";
			case (2) : return "Low, less than 33 percent";
			case (4) : return "Critical, less than five percent";
			case (8) : return "Charging";
			case ((byte)128) : return "No system battery";
			default: return "Unknown";
			}
		}
		/**
		* The percentage of full battery charge remaining
		*/
		string getBatteryLifePercent(BYTE BatteryLifePercent) {
			return and_SysStringToChar((BatteryLifePercent == (byte)255) ? "Unknown" : BatteryLifePercent + "%");
		}
		/**
		* The number of seconds of battery life remaining
		*/
		string getBatteryLifeTime(DWORD BatteryLifeTime) {
			return and_SysStringToChar((BatteryLifeTime == -1) ? "Unknown" : BatteryLifeTime + " seconds");
		}
		/**
		* The number of seconds of battery life when at full charge
		*/
		string getBatteryFullLifeTime(DWORD BatteryFullLifeTime) {
			return and_SysStringToChar((BatteryFullLifeTime == -1) ? "Unknown" : BatteryFullLifeTime + " seconds");
		}
		int updateValuesBattery()
		{
			SYSTEM_POWER_STATUS lpSysPwrStatus;
			GetSystemPowerStatus(&lpSysPwrStatus);
			label1->Text = "Battery status:\t"+toSystemString(getACLineStatusString(lpSysPwrStatus.BatteryFlag));
			label2->Text = "AC/Battery:\t" + toSystemString(getBatteryFlagString(lpSysPwrStatus.ACLineStatus));
			label3->Text = "battery life:\t" + toSystemString(getBatteryLifePercent(lpSysPwrStatus.BatteryLifePercent));
			label4->Text = "battery left:\t" + toSystemString(getBatteryLifeTime(lpSysPwrStatus.BatteryLifeTime));
			label5->Text = "Battery full:\t" + toSystemString(getBatteryFullLifeTime(lpSysPwrStatus.BatteryFullLifeTime));
			return 1;
		}

#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 int x = showVideoTimeout();
				 label7->Text = x.ToString();
				 x = updateValuesBattery();
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 label8->Text = textBox1->Text;
			 timer1->Start();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 DWORD output = strtol( and_SysStringToChar(label8->Text), 0, 0);
			 applyVideoTimeout(output);
			 updateValuesBattery();
}
private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 DWORD launchValues = strtol(and_SysStringToChar(label7->Text), 0, 0);
			 applyVideoTimeout(launchValues);
}
};
}
