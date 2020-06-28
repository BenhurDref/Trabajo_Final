#pragma once

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormularioInstrucciones
	/// </summary>
	public ref class FormularioInstrucciones : public System::Windows::Forms::Form
	{
	public:
		FormularioInstrucciones(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormularioInstrucciones()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormularioInstrucciones::typeid));
			this->SuspendLayout();
			// 
			// FormularioInstrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(688, 361);
			this->Name = L"FormularioInstrucciones";
			this->Text = L"FormularioInstrucciones";
			this->Load += gcnew System::EventHandler(this, &FormularioInstrucciones::FormularioInstrucciones_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormularioInstrucciones_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
