#include "pch.h"
#include "MyForm.h"


#include <Windows.h>
using namespace maxmatching; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}



//using namespace System;
//using namespace System::Windows::Forms;
//
//[STAThreadAttribute]
//
//int main(array<String^>^ args) {
//	Application::SetCompatibleTextRenderingDefault(false);
//	Application::EnableVisualStyles();
//
//	maxmatching::MyForm form;
//	Application::Run(% form);
//}