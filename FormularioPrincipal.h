#include "FormularioDelJuego.h"
#include"FormularioInstrucciones.h"

#pragma once

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormularioPrincipal
	/// </summary>
	public ref class FormularioPrincipal : public System::Windows::Forms::Form
	{
	public:
		FormularioPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			dificultad = ' ';
			vidas = 0;
			tiempo = 0;
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormularioPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  chckbPrincipiante;
	private: System::Windows::Forms::CheckBox^  chckbAvanzado;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		char dificultad;
		int vidas;
		int tiempo;
		int puntajeparainvisibilidad;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtTiempo;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtVidas;
	private: System::Windows::Forms::TextBox^  txtPuntaje;
	private: System::Windows::Forms::Label^  label3;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormularioPrincipal::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chckbPrincipiante = (gcnew System::Windows::Forms::CheckBox());
			this->chckbAvanzado = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtTiempo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtVidas = (gcnew System::Windows::Forms::TextBox());
			this->txtPuntaje = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(395, 365);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Instrucciones";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormularioPrincipal::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(660, 365);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(144, 53);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Jugar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormularioPrincipal::button2_Click);
			// 
			// chckbPrincipiante
			// 
			this->chckbPrincipiante->AutoSize = true;
			this->chckbPrincipiante->Location = System::Drawing::Point(439, 314);
			this->chckbPrincipiante->Name = L"chckbPrincipiante";
			this->chckbPrincipiante->Size = System::Drawing::Size(81, 17);
			this->chckbPrincipiante->TabIndex = 2;
			this->chckbPrincipiante->Text = L"Principiante";
			this->chckbPrincipiante->UseVisualStyleBackColor = true;
			this->chckbPrincipiante->CheckedChanged += gcnew System::EventHandler(this, &FormularioPrincipal::chckbPrincipiante_CheckedChanged);
			// 
			// chckbAvanzado
			// 
			this->chckbAvanzado->AutoSize = true;
			this->chckbAvanzado->Location = System::Drawing::Point(704, 314);
			this->chckbAvanzado->Name = L"chckbAvanzado";
			this->chckbAvanzado->Size = System::Drawing::Size(74, 17);
			this->chckbAvanzado->TabIndex = 3;
			this->chckbAvanzado->Text = L"Avanzado";
			this->chckbAvanzado->UseVisualStyleBackColor = true;
			this->chckbAvanzado->CheckedChanged += gcnew System::EventHandler(this, &FormularioPrincipal::chckbAvanzado_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(289, 272);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Tiempo";
			this->label1->Click += gcnew System::EventHandler(this, &FormularioPrincipal::label1_Click);
			// 
			// txtTiempo
			// 
			this->txtTiempo->Location = System::Drawing::Point(336, 269);
			this->txtTiempo->Name = L"txtTiempo";
			this->txtTiempo->Size = System::Drawing::Size(100, 20);
			this->txtTiempo->TabIndex = 5;
			this->txtTiempo->TextChanged += gcnew System::EventHandler(this, &FormularioPrincipal::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(487, 272);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Vidas";
			// 
			// txtVidas
			// 
			this->txtVidas->Location = System::Drawing::Point(531, 269);
			this->txtVidas->Name = L"txtVidas";
			this->txtVidas->Size = System::Drawing::Size(100, 20);
			this->txtVidas->TabIndex = 7;
			// 
			// txtPuntaje
			// 
			this->txtPuntaje->Location = System::Drawing::Point(735, 269);
			this->txtPuntaje->Name = L"txtPuntaje";
			this->txtPuntaje->Size = System::Drawing::Size(100, 20);
			this->txtPuntaje->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(688, 276);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Puntaje";
			// 
			// FormularioPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 561);
			this->Controls->Add(this->txtPuntaje);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtVidas);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtTiempo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chckbAvanzado);
			this->Controls->Add(this->chckbPrincipiante);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"FormularioPrincipal";
			this->Text = L"FormularioPrincipal";
			this->Load += gcnew System::EventHandler(this, &FormularioPrincipal::FormularioPrincipal_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dificultad != ' ') {
			if(txtVidas->Text!="")vidas = Convert::ToInt32(txtVidas->Text);
			if (txtTiempo->Text!="")tiempo = Convert::ToInt32(txtTiempo->Text);
			puntajeparainvisibilidad = Convert::ToInt32(txtPuntaje->Text);
			this->Hide();
			FormularioDelJuego^ miformulariodondeseguardaeljuego = gcnew FormularioDelJuego(dificultad,tiempo,vidas, puntajeparainvisibilidad);
			miformulariodondeseguardaeljuego->ShowDialog();
			this->Close();
		}
	}
	private: System::Void FormularioPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		FormularioInstrucciones^ miformularioinstrucciones = gcnew FormularioInstrucciones();
		miformularioinstrucciones->ShowDialog();
	}
	private: System::Void chckbPrincipiante_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		dificultad = 'P';
	}
private: System::Void chckbAvanzado_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	dificultad = 'A';
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
//hola
