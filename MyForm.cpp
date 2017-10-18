#include "MyForm.h"
#include "Windows.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	courseWorkWithWindows::MyForm form;
	Application::Run(%form);

}