#include "FormularioPrincipal.h"  
using namespace System;
using namespace System::Windows::Forms;
void main(array<String^>^ arg){
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew TrabajoFinal::FormularioPrincipal);
}