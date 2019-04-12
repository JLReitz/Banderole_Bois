#include "EmulatorControl_UI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MailboxEmulator::EmulatorControl_UI form;
	Application::Run(%form);
	return 0;
}
