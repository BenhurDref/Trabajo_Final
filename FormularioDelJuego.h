#pragma once
#include"CJugador.h"
#include"CArregloBalaJugador.h"
#include"CArregloEnemigoAlfa.h"
#include"CArregloEnemigoBeta.h"
#include"CArregloBalaEnemigo.h"
#include"CPresidenteC.h"
#include"COficial.h"
#include"FormularioGanaste.h"
#include"FormularioPerdiste.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormularioDelJuego
	/// </summary>
	public ref class FormularioDelJuego : public System::Windows::Forms::Form
	{
	public:
		FormularioDelJuego(char _dificultad, int _tiempo, int _vidas, int _puntajeparainvisibilidad)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			objJugador = new Jugador(50, 50);
			objArregloBalaJugador = new ArregloBalaJugador();

			objArregloEnemigoAlfa = new ArregloEnemigoAlfa();
			objArregloEnemigoBeta = new ArregloEnemigoBeta();

			objArregloBalaEnemigo = new ArregloBalaEnemigo();

			objOficial = new Oficial(0, 0, 'D', 1);
			objPresidenteC = new PresidenteC(this->Width-40, 0, 'D', 2);

			tiempototalbeta = r.Next(1, 6) * 10;
			temporizadorbeta = 0;

			ntotal = r.Next(10, 31);
			nalfa = r.Next(1, ntotal);
			nbeta = ntotal - nalfa;

			contadorkills = 0;
			nivel = r.Next(1, 3);
			if (nivel == 1)nivel = 1;
			if (nivel == 2)nivel = -1;


			this->dificultad = _dificultad;
			this->minutos = _tiempo;
			this->vidas = _vidas;
			this->segundos = 0;
			//this->puntajeparainvisibilidad = _puntajeparainvisibilidad;

			puntajenivel1 = 0;
			puntajenivelmenos1 = 0;
			puntajetotal = 0;

			frecuenciaalfa = r.Next(1, 11) * 10;
			frecuenciabeta = r.Next(1, 11) * 10;

			/*bmpJugadorInvisible = gcnew Bitmap("JugadorInvisible.png");*/

			if (nivel == 1) {
				bmpJugador = gcnew Bitmap("personaje (1).png");
				bmpFondo = gcnew Bitmap("Mundo-1.png");
				bmpBalaJugador = gcnew Bitmap("Mensajes.png");
				bmpEnemigoAlfa = gcnew Bitmap("EnemigoAlfa_C.png");
				auxcambiodecolorbeta = r.Next(1, 5);
				if (auxcambiodecolorbeta == 1)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta1_C.png");
				if (auxcambiodecolorbeta == 2)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta2_C.png");
				if (auxcambiodecolorbeta == 3)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta3_C.png");
				if (auxcambiodecolorbeta == 4)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta4_C.png");
				/*bmpEnemigoAlfaInvisible = gcnew Bitmap("EnemigoAlfaInvisible.png");*/
				bmpBalaEnemigo = gcnew Bitmap("BalaEnemigo_C.png");
				bmpPersonajePlus1_C = gcnew Bitmap("PersonajePlus1_C.png");
				bmpPersonajePlus2_C = gcnew Bitmap("PersonajePlus2_C.png");
				ntotal1 = ntotal;
			}
			if (nivel == -1) {
 				bmpJugador = gcnew Bitmap("personaje (1).png");
				bmpFondo = gcnew Bitmap("Mundo(2).jpg");
				bmpBalaJugador = gcnew Bitmap("Mensajes.png");
				bmpEnemigoAlfa = gcnew Bitmap("EnemigoAlfa_MA.png");
				auxcambiodecolorbeta = r.Next(1, 5);
				if (auxcambiodecolorbeta == 1)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta1_MA.png");
				if (auxcambiodecolorbeta == 2)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta2_MA.png");
				if (auxcambiodecolorbeta == 3)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta3_MA.png");
				if (auxcambiodecolorbeta == 4)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta4_MA.png");
				//bmpEnemigoAlfaInvisible = gcnew Bitmap("EnemigoAlfaInvisible.png");
				bmpBalaEnemigo = gcnew Bitmap("BalaEnemigo_MA.png");
				ntotalmenos1 = ntotal;
			}


		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormularioDelJuego()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		Jugador* objJugador;
		ArregloBalaJugador* objArregloBalaJugador;
		BalaJugador* objBalaJugador;

		ArregloEnemigoAlfa* objArregloEnemigoAlfa;
		EnemigoAlfa* objEnemigoAlfa;

		ArregloEnemigoBeta* objArregloEnemigoBeta;
		EnemigoBeta* objEnemigoBeta;

		ArregloBalaEnemigo* objArregloBalaEnemigo;
		BalaEnemigo* objBalaEnemigo;

		Oficial *objOficial;
		PresidenteC* objPresidenteC;

		Bitmap^ bmpJugador;
		Bitmap^ bmpFondo;
		Bitmap^ bmpBalaJugador;
		Bitmap^ bmpEnemigoAlfa;
		Bitmap^ bmpEnemigoBeta;
		Bitmap^ bmpEnemigoAlfaInvisible;
		Bitmap^ bmpBalaEnemigo;
		Bitmap^ bmpPersonajePlus1_C;
		Bitmap^ bmpPersonajePlus2_C;
		Bitmap^ bmpJugadorInvisible;

		int x, y, auxdireccion;
		char direccion;
		Random r;
		int ntotal, nalfa, nbeta;

		int contalfa = 0;
		int contbeta = 0;

		int ntotal1, ntotalmenos1;

		int temporizadoremigoalfa = 0;
		int temporizadornemigobeta = 0;
		int temporizadorinvisibilidadalfa = 0;
		int temporizadorinvisibilidadjugador = 0;


		int frecuenciaalfa;
		int frecuenciabeta;

		int auxcambiodecolorbeta;
		int tiempototalbeta;
		int temporizadorbeta;

		int contadorkills = 0;
		int killsnivel1 = 0;
		int killsnivelmenos1 = 0;
		int contadorkillsparcial = 0;

		int nivel;
		int nivelescompletados;
		
		char dificultad;
		int minutos;
		int segundos;
		int vidas;

		int puntajeparainvisibilidad;
		int puntajenivel1;
		int puntajenivelmenos1;
		int puntajetotal;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblVidas;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  lblTiempo;
	private: System::Windows::Forms::Timer^  timer2;
private: System::Windows::Forms::Label^  lblPuntaje;
private: System::Windows::Forms::Label^  label4;

	private: System::ComponentModel::IContainer^  components;
			 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormularioDelJuego::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(54, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas";
			this->label1->Click += gcnew System::EventHandler(this, &FormularioDelJuego::label1_Click);
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(106, 25);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(35, 13);
			this->lblVidas->TabIndex = 1;
			this->lblVidas->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(420, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Tiempo";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Location = System::Drawing::Point(479, 25);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(35, 13);
			this->lblTiempo->TabIndex = 3;
			this->lblTiempo->Text = L"label4";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FormularioDelJuego::timer2_Tick);
			// 
			// lblPuntaje
			// 
			this->lblPuntaje->AutoSize = true;
			this->lblPuntaje->Location = System::Drawing::Point(808, 25);
			this->lblPuntaje->Name = L"lblPuntaje";
			this->lblPuntaje->Size = System::Drawing::Size(35, 13);
			this->lblPuntaje->TabIndex = 5;
			this->lblPuntaje->Text = L"label4";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(749, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Puntaje";
			// 
			// FormularioDelJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 628);
			this->Controls->Add(this->lblPuntaje);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->label1);
			this->Name = L"FormularioDelJuego";
			this->Text = L"FormularioDelJuego";
			this->Load += gcnew System::EventHandler(this, &FormularioDelJuego::FormularioDelJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormularioDelJuego::PresionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormularioDelJuego::SoltarTecla);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		//Creo las herramientas necesarias para trabajar en el formulario
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		//Dibujo el fondo
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, 1000, 667);

		//Muevo y Dibujo al jugador
		if (nivel == 1) {
			/*if (puntajetotal >= puntajeparainvisibilidad&&temporizadorinvisibilidadjugador<=100) {
				objJugador->Mover_Invisble(buffer, bmpJugadorInvisible);
				objJugador->Dibujar_Invisible(buffer, bmpJugadorInvisible);
				temporizadorinvisibilidadjugador++;
			}
			else {*/
				objJugador->Mover(buffer, bmpJugador);
				objJugador->Dibujar(buffer, bmpJugador);
			/*if (temporizadorinvisibilidadjugador >= 100 && temporizadorinvisibilidadjugador <= 160) {
				if (temporizadorinvisibilidadjugador >= 160)temporizadorinvisibilidadjugador = 0;
				temporizadorinvisibilidadjugador++;
			}*/
		}
		if (nivel == -1) {
			/*if (puntajetotal >= puntajeparainvisibilidad&&temporizadorinvisibilidadjugador <= 100) {
				objJugador->Mover_Invisble(buffer, bmpJugadorInvisible);
				objJugador->Dibujar_Invisible(buffer, bmpJugadorInvisible);
				temporizadorinvisibilidadjugador++;
			}
			else {*/
				objJugador->Mover(buffer, bmpJugador);
				objJugador->Dibujar(buffer, bmpJugador);
			}
			if (temporizadorinvisibilidadjugador >= 100 && temporizadorinvisibilidadjugador <= 160) {
			/*	if (temporizadorinvisibilidadjugador >= 160)temporizadorinvisibilidadjugador = 0;
				temporizadorinvisibilidadjugador++;
			}*/
		}

		//Movimiento y Dibujado de las balas del jugador
		for (int i = 0; i < objArregloBalaJugador->Get_N(); i++) {
			//Obtengo mi bala de mi arreglo de balas
			objBalaJugador=objArregloBalaJugador->Obtener_Bala(i);
			//¿Qué pasa si las balas llegan al extremo? Se eliminan
			if (objBalaJugador->get_direccion() == 'D') {
				if (objBalaJugador->get_x() + objBalaJugador->get_ancho()*0.03 >= buffer->Graphics->VisibleClipBounds.Width)objArregloBalaJugador->Eliminar_Bala(i);
			}
			if (objBalaJugador->get_direccion() == 'A') {
				if (objBalaJugador->get_x() <= 0)objArregloBalaJugador->Eliminar_Bala(i);
			}
			if (objBalaJugador->get_direccion() == 'W') {
				if (objBalaJugador->get_y() <= 0)objArregloBalaJugador->Eliminar_Bala(i);
			}
			if (objBalaJugador->get_direccion() == 'S') {
				if (objBalaJugador->get_y() + objBalaJugador->get_alto()*0.03 >= buffer->Graphics->VisibleClipBounds.Height)objArregloBalaJugador->Eliminar_Bala(i);
			}
			//Muevo y dibujo las balas
			objBalaJugador->Mover(buffer, bmpBalaJugador);
			objBalaJugador->Dibujar(buffer, bmpBalaJugador);

			//Colisiones con los enemigos Alfa
			for (int j = 0; j < objArregloEnemigoAlfa->Get_N(); j++) {
				objEnemigoAlfa = objArregloEnemigoAlfa->Get_EnemigoAlfa(j);
				if (ColisionUsando_InsertectsWith(objBalaJugador->get_x(), objBalaJugador->get_y(), objBalaJugador->get_ancho()*0.03, objBalaJugador->get_alto()*0.03, objEnemigoAlfa->get_x(), objEnemigoAlfa->get_y(), objEnemigoAlfa->get_ancho()*0.7, objEnemigoAlfa->get_alto()*0.7)) {
					objArregloEnemigoAlfa->Eliminar_Enemigo(j);
					objArregloBalaEnemigo->Eliminar_BalaEnemigo(j);
					objArregloBalaJugador->Eliminar_Bala(i);
					//ntotal--;
					contadorkills++;
					contadorkillsparcial++;
					puntajetotal = puntajetotal + 200;
					if (nivel == 1) {
						puntajenivel1 = puntajenivel1 + 200;
						killsnivel1++;
					}
					if (nivel == -1) {
						puntajenivelmenos1 = puntajenivelmenos1 + 200;
						killsnivelmenos1++;
					}
				}
			}

			//Colisiones con los enemigos Beta
			for (int k = 0; k < objArregloEnemigoBeta->Get_N(); k++) {
				objEnemigoBeta = objArregloEnemigoBeta->Get_EnemigoBeta(k);
				if (ColisionUsando_InsertectsWith(objBalaJugador->get_x(), objBalaJugador->get_y(), objBalaJugador->get_ancho()*0.03, objBalaJugador->get_alto()*0.03, objEnemigoBeta->get_x(), objEnemigoBeta->get_y(), objEnemigoBeta->get_ancho()*0.7, objEnemigoBeta->get_alto()*0.7)) {
					objArregloEnemigoBeta->Eliminar_Enemigo(k);
					objArregloBalaJugador->Eliminar_Bala(i);
					//ntotal--;
					contadorkills++;
					contadorkillsparcial++;
					puntajetotal = puntajetotal + 100;
					if (nivel == 1) {
						puntajenivel1 = puntajenivel1 + 100;
						killsnivel1++;
					}
					if (nivel == -1) {
						puntajenivelmenos1 = puntajenivelmenos1 + 100;
						killsnivelmenos1++;
					}
				}
			}
		}

		//Creacion de enemigos alfa cada cierto tiempo
		if (temporizadoremigoalfa % frecuenciaalfa == 0&&contalfa<nalfa) {
			contalfa++;
			x = r.Next(0, this->Width - 100);
			y = r.Next(0, this->Height - 100);
			auxdireccion = r.Next(1, 5);
			if (auxdireccion == 1)direccion = 'W';
			if (auxdireccion == 2)direccion = 'S';
			if (auxdireccion == 3)direccion = 'D';
			if (auxdireccion == 4)direccion = 'A';
			objEnemigoAlfa = new EnemigoAlfa(x, y, direccion, 1);
			objBalaEnemigo = new BalaEnemigo(x, y, direccion);
			objArregloEnemigoAlfa->Agregar_Enemigo(objEnemigoAlfa);
			objArregloBalaEnemigo->Agregar_BalaEnemigo(objBalaEnemigo);
		}

		//Dinámica de los enemigos alfa
		for (int i = 0; i < objArregloEnemigoAlfa->Get_N(); i++) {
			objEnemigoAlfa = objArregloEnemigoAlfa->Get_EnemigoAlfa(i);

			//Pregunto si el enemigo alfa llega al extremo. Si lo hace, cambia su desplazamiento
			if (objEnemigoAlfa->get_x() + objEnemigoAlfa->get_ancho()*0.7 >= buffer->Graphics->VisibleClipBounds.Width)objEnemigoAlfa->change_dx();
			if (objEnemigoAlfa->get_x() <= 0)objEnemigoAlfa->change_dx();
			if (objEnemigoAlfa->get_y() + objEnemigoAlfa->get_alto()*0.7 >= buffer->Graphics->VisibleClipBounds.Height)objEnemigoAlfa->change_dy();
			if (objEnemigoAlfa->get_y() <= 0)objEnemigoAlfa->change_dy();

			//En estos if pregunto que si llegan a los bordes, cambien de dirección
			if ((objEnemigoAlfa->get_direccion() == 'S') && (objEnemigoAlfa->get_y() + objEnemigoAlfa->get_alto()*0.7 >= buffer->Graphics->VisibleClipBounds.Height))objEnemigoAlfa->set_direccion('W');
			if ((objEnemigoAlfa->get_direccion() == 'W') && (objEnemigoAlfa->get_y() <= 0))objEnemigoAlfa->set_direccion('S');
			if ((objEnemigoAlfa->get_direccion() == 'A') && (objEnemigoAlfa->get_x() <= 0))objEnemigoAlfa->set_direccion('D');
			if ((objEnemigoAlfa->get_direccion() == 'D') && (objEnemigoAlfa->get_x() + objEnemigoAlfa->get_ancho()*0.7 >= buffer->Graphics->VisibleClipBounds.Width))objEnemigoAlfa->set_direccion('A');
			
			//Movimiento y dibujado del enemigo alfa
			/*if (temporizadorinvisibilidadalfa >= 200 && temporizadorinvisibilidadalfa <= 300) {
				objEnemigoAlfa->MoverInvisible(buffer, bmpEnemigoAlfaInvisible, 1);
				objEnemigoAlfa->DibujarInvisible(buffer, bmpEnemigoAlfaInvisible, 1);
			}
			else {*/
				objEnemigoAlfa->Mover(buffer, bmpEnemigoAlfa, 1);
				objEnemigoAlfa->Dibujar(buffer, bmpEnemigoAlfa, 1);
		}

		if (dificultad == 'A') {
			//Bala de los enemigos
			for (int i = 0; i < objArregloBalaEnemigo->Get_N(); i++) {
				//Obtengo la bala y adicionalmente a mi enemigo
				objBalaEnemigo = objArregloBalaEnemigo->Get_BalaEnemigo(i);
				objEnemigoAlfa = objArregloEnemigoAlfa->Get_EnemigoAlfa(i);

				//Cuando la bala llega al extremo, edito sus valores
				if (objBalaEnemigo->get_direccion() == 'S'&&objBalaEnemigo->Get_y() + objBalaEnemigo->Get_alto()*0.1 >= buffer->Graphics->VisibleClipBounds.Height + 20) {
					objBalaEnemigo->set_x(objEnemigoAlfa->get_x());
					objBalaEnemigo->set_y(objEnemigoAlfa->get_y());
					objBalaEnemigo->set_direccion(objEnemigoAlfa->get_direccion());
				}
				if (objBalaEnemigo->get_direccion() == 'W'&&objBalaEnemigo->Get_y() + objBalaEnemigo->Get_alto()*0.1 <= 0) {
					objBalaEnemigo->set_x(objEnemigoAlfa->get_x());
					objBalaEnemigo->set_y(objEnemigoAlfa->get_y());
					objBalaEnemigo->set_direccion(objEnemigoAlfa->get_direccion());
				}
				if (objBalaEnemigo->get_direccion() == 'A'&&objBalaEnemigo->Get_x() + objBalaEnemigo->Get_ancho()*0.1 <= -20) {
					objBalaEnemigo->set_x(objEnemigoAlfa->get_x());
					objBalaEnemigo->set_y(objEnemigoAlfa->get_y());
					objBalaEnemigo->set_direccion(objEnemigoAlfa->get_direccion());
				}
				if (objBalaEnemigo->get_direccion() == 'D'&&objBalaEnemigo->Get_x() + objBalaEnemigo->Get_ancho()*0.1 >= buffer->Graphics->VisibleClipBounds.Width + 20) {
					objBalaEnemigo->set_x(objEnemigoAlfa->get_x());
					objBalaEnemigo->set_y(objEnemigoAlfa->get_y());
					objBalaEnemigo->set_direccion(objEnemigoAlfa->get_direccion());
				}
				//Muevo la bala del enemigo
				objBalaEnemigo->Mover(buffer, bmpBalaEnemigo);
				//Dibujo la bala del enemigo
				objBalaEnemigo->Dibujar(buffer, bmpBalaEnemigo);

				//Colisión contra el jugador
				if (ColisionUsando_InsertectsWith(objJugador->get_x(), objJugador->get_y(), objJugador->get_ancho()*1.1, objJugador->get_alto()*1.1, objBalaEnemigo->Get_x(), objBalaEnemigo->Get_y(), objBalaEnemigo->Get_ancho()*0.03, objBalaEnemigo->Get_alto()*0.03)) {
					objJugador->set_x(50);
					objJugador->set_y(50);
					objBalaEnemigo->set_x(objEnemigoAlfa->get_x());
					objBalaEnemigo->set_y(objEnemigoAlfa->get_y());
					objBalaEnemigo->set_direccion(objEnemigoAlfa->get_direccion());
					vidas--;
				}
			}
		}

		//Creación de enemigo Beta cada cierto tiempo
		if (temporizadornemigobeta % frecuenciabeta == 0 && contbeta < nbeta) {
			contbeta++;
			x = r.Next(0, this->Width - 100);
			y = r.Next(0, this->Height - 100);
			auxdireccion = r.Next(1, 5);
			if (auxdireccion == 1)direccion = 'W';
			if (auxdireccion == 2)direccion = 'S';
			if (auxdireccion == 3)direccion = 'D';
			if (auxdireccion == 4)direccion = 'A';
			objEnemigoBeta = new EnemigoBeta(x, y, direccion, 2);
			objArregloEnemigoBeta->Agregar_Enemigo(objEnemigoBeta);
		}
		//Dinámica de los enemigos beta
		for (int i = 0; i < objArregloEnemigoBeta->Get_N(); i++) {
			//Obtengo un enemigo beta de mi arreglo de enemigos beta
			objEnemigoBeta = objArregloEnemigoBeta->Get_EnemigoBeta(i);
			//Pregunto si el enemigo beta llega a los extremos. Si lo hace, el desplazamiento cambia
			if (objEnemigoBeta->get_x() + objEnemigoBeta->get_ancho()*0.7 >= buffer->Graphics->VisibleClipBounds.Width)objEnemigoBeta->change_dx();
			if (objEnemigoBeta->get_x() <= 0)objEnemigoBeta->change_dx();
			if (objEnemigoBeta->get_y() + objEnemigoBeta->get_alto()*0.7 >= buffer->Graphics->VisibleClipBounds.Height)objEnemigoBeta->change_dy();
			if (objEnemigoBeta->get_y() <= 0)objEnemigoBeta->change_dy();
			//Pregunto que si llegan a los bordes, cambian de direccion
			if ((objEnemigoBeta->get_direccion() == 'S') && (objEnemigoBeta->get_y() + objEnemigoBeta->get_alto()*0.7 >= buffer->Graphics->VisibleClipBounds.Height))objEnemigoBeta->set_direccion('W');
			if ((objEnemigoBeta->get_direccion() == 'W') && (objEnemigoBeta->get_y() <= 0))objEnemigoBeta->set_direccion('S');
			if ((objEnemigoBeta->get_direccion() == 'A') && (objEnemigoBeta->get_x() <= 0))objEnemigoBeta->set_direccion('D');
			if ((objEnemigoBeta->get_direccion() == 'D') && (objEnemigoBeta->get_x() + objEnemigoBeta->get_ancho()*0.7 >= buffer->Graphics->VisibleClipBounds.Width))objEnemigoBeta->set_direccion('A');
			//Muevo el enemigo beta
			objEnemigoBeta->Mover(buffer, bmpEnemigoBeta, 2);
			//Dibujo el enemigo beta
			objEnemigoBeta->Dibujar(buffer, bmpEnemigoBeta, 2);
		}
		//El cambio de color de mis enemigos Beta
		if (temporizadorbeta >= tiempototalbeta) {
			tiempototalbeta = r.Next(1, 16) * 10;
			delete bmpEnemigoBeta;
			temporizadorbeta = 0;
			auxcambiodecolorbeta = r.Next(1, 5);
			if (nivel == 1) {
				if (auxcambiodecolorbeta == 1)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta1_C.png");
				if (auxcambiodecolorbeta == 2)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta2_C.png");
				if (auxcambiodecolorbeta == 3)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta3_C.png");
				if (auxcambiodecolorbeta == 4)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta4_C.png");
			}
			if (nivel == -1) {
				if (auxcambiodecolorbeta == 1)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta1_MA.png");
				if (auxcambiodecolorbeta == 2)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta2_MA.png");
				if (auxcambiodecolorbeta == 3)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta3_MA.png");
				if (auxcambiodecolorbeta == 4)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta4_MA.png");
			}
		}

		if (contadorkills >= ntotal/2 && nivel==1) {
			if (objOficial!=nullptr) {
				if (objOficial->get_x() + objOficial->get_ancho()*0.7 < objJugador->get_x()) {
					objOficial->set_direccion('D');
					objOficial->set_dx(3);
				}
				if (objOficial->get_x() > objJugador->get_x() + objJugador->get_ancho()*1.1) {
					objOficial->set_direccion('A');
					objOficial->set_dx(-3);
				}
				if (objOficial->get_y() + objOficial->get_alto()*0.7 < objJugador->get_y()) {
					objOficial->set_direccion('S');
					objOficial->set_dy(3);
				}
				if (objOficial->get_y() > objJugador->get_y() + objJugador->get_alto()*1.1) {
					objOficial->set_direccion('W');
					objOficial->set_dy(-3);
				}
				if (ColisionUsando_InsertectsWith(objJugador->get_x(), objJugador->get_y(), objJugador->get_ancho()*1.1, objJugador->get_alto()*1.1, objOficial->get_x(), objOficial->get_y(), objOficial->get_ancho()*0.7, objOficial->get_alto()*0.7)) {
					vidas--;
					objJugador->set_x(50);
					objJugador->set_y(50);
				}
				objOficial->Mover(buffer, bmpPersonajePlus1_C, 1);
				objOficial->Dibujar(buffer, bmpPersonajePlus1_C, 1);
			}

			if (objPresidenteC != nullptr) {
				if (objPresidenteC->get_x() + objPresidenteC->get_ancho()*0.7 < objJugador->get_x()) {
					objPresidenteC->set_direccion('D');
					objPresidenteC->set_dx(3);
				}
				if (objPresidenteC->get_x() > objJugador->get_x() + objJugador->get_ancho()*1.1) {
					objPresidenteC->set_direccion('A');
					objPresidenteC->set_dx(-3);
				}
				if (objPresidenteC->get_y() + objPresidenteC->get_alto()*0.7 < objJugador->get_y()) {
					objPresidenteC->set_direccion('S');
					objPresidenteC->set_dy(3);
				}
				if (objPresidenteC->get_y() > objJugador->get_y() + objJugador->get_alto()*1.1) {
					objPresidenteC->set_direccion('W');
					objPresidenteC->set_dy(-3);
				}
				if (ColisionUsando_InsertectsWith(objJugador->get_x(), objJugador->get_y(), objJugador->get_ancho()*1.1, objJugador->get_alto()*1.1, objPresidenteC->get_x(), objPresidenteC->get_y(), objPresidenteC->get_ancho()*0.7, objPresidenteC->get_alto()*0.7)) {
					vidas--;
					objJugador->set_x(50);
					objJugador->set_y(50);
				}
				objPresidenteC->Mover(buffer, bmpPersonajePlus2_C, 2);
				objPresidenteC->Dibujar(buffer, bmpPersonajePlus2_C, 2);
			}


		}


		//Imprimo el numero de vidas que tengo
		lblVidas->Text = Convert::ToString(vidas);

		//Imprimo mi puntaje actual
		lblPuntaje->Text = Convert::ToString(puntajetotal);

		//Aumento mis contadores
		temporizadoremigoalfa++;
		//temporizadorinvisibilidadalfa++; if (temporizadorinvisibilidadalfa == 300)temporizadorinvisibilidadalfa = 0;
		temporizadornemigobeta++;
		temporizadorbeta++;

		if (vidas == 0) {
			timer1->Enabled = false;
			this->Hide();
			FormularioPerdiste^ miformularioperdiste = gcnew FormularioPerdiste();
			miformularioperdiste->ShowDialog();
			this->Close();
		}


		//¿Qué pasa si estoy en el nivel 1 y elimino a todos los enemigos
		if (nivel == 1) {
			if (killsnivel1 == ntotal1) {
				nivelescompletados++;
				if (nivelescompletados == 2) {
					timer1->Enabled = false;
					this->Hide();
					FormularioGanaste^ miformulariognaste = gcnew FormularioGanaste();
					miformulariognaste->ShowDialog();
					this->Close();
				}
				nivel = nivel*-1;
				contadorkillsparcial = 0;
				delete objJugador;
				objJugador = new Jugador(50, 50);
				delete objArregloBalaJugador;
				objArregloBalaJugador = new ArregloBalaJugador();
				delete objArregloEnemigoAlfa;
				objArregloEnemigoAlfa = new ArregloEnemigoAlfa();
				delete objArregloEnemigoBeta;
				objArregloEnemigoBeta = new ArregloEnemigoBeta();
				delete objArregloBalaEnemigo;
				objArregloBalaEnemigo = new ArregloBalaEnemigo();
				temporizadoremigoalfa = 0;
				temporizadornemigobeta = 0;
				//temporizadorinvisibilidadalfa = 0;
				ntotal = r.Next(10, 31);
				nalfa = r.Next(1, ntotal);
				nbeta = ntotal - nalfa;
				ntotalmenos1 = ntotal;
				bmpJugador = gcnew Bitmap("Jugador_MA.png");
				bmpFondo = gcnew Bitmap("FonditoMedioAmbiente.jpg");
				bmpBalaJugador = gcnew Bitmap("BalaJugador_MA.png");
				bmpEnemigoAlfa = gcnew Bitmap("EnemigoAlfa_MA.png");
				auxcambiodecolorbeta = r.Next(1, 5);
				if (auxcambiodecolorbeta == 1)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta1_MA.png");
				if (auxcambiodecolorbeta == 2)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta2_MA.png");
				if (auxcambiodecolorbeta == 3)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta3_MA.png");
				if (auxcambiodecolorbeta == 4)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta4_MA.png");
				//bmpEnemigoAlfaInvisible = gcnew Bitmap("EnemigoAlfaInvisible.png");
				bmpBalaEnemigo = gcnew Bitmap("BalaEnemigo_MA.png");
				frecuenciaalfa = r.Next(1, 11) * 10;
				contalfa = 0;
				contbeta = 0;
			}
		}
		//¿Qué pasa si estoy en el nivel -1 y elimino a todos los enemigos?
		if (nivel == -1) {
			if (killsnivelmenos1 ==ntotalmenos1) {
				nivelescompletados++;
				if (nivelescompletados == 2) {
					timer1->Enabled = false;
					this->Hide();
					FormularioGanaste^ miformulariognaste = gcnew FormularioGanaste();
					miformulariognaste->ShowDialog();
					this->Close();
				}
				nivel = nivel*-1;
				contadorkillsparcial = 0;
				delete objJugador;
				objJugador = new Jugador(50, 50);
				delete objArregloBalaJugador;
				objArregloBalaJugador = new ArregloBalaJugador();
				delete objArregloEnemigoAlfa;
				objArregloEnemigoAlfa = new ArregloEnemigoAlfa();
				delete objArregloEnemigoBeta;
				objArregloEnemigoBeta = new ArregloEnemigoBeta();
				delete objArregloBalaEnemigo;
				objArregloBalaEnemigo = new ArregloBalaEnemigo();
				temporizadoremigoalfa = 0;
				temporizadornemigobeta = 0;
				//temporizadorinvisibilidadalfa = 0;
				ntotal = r.Next(10, 31);
				nalfa = r.Next(1, ntotal);
				nbeta = ntotal - nalfa;
				ntotal1 = ntotal;
				bmpJugador = gcnew Bitmap("Jugador_C.png");
				bmpFondo = gcnew Bitmap("FonditoCorrupto.jpg");
				bmpBalaJugador = gcnew Bitmap("BalaJugador_C.png");
				bmpEnemigoAlfa = gcnew Bitmap("EnemigoAlfa_C.png");
				auxcambiodecolorbeta = r.Next(1, 5);
				if (auxcambiodecolorbeta == 1)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta1_C.png");
				if (auxcambiodecolorbeta == 2)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta2_C.png");
				if (auxcambiodecolorbeta == 3)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta3_C.png");
				if (auxcambiodecolorbeta == 4)bmpEnemigoBeta = gcnew Bitmap("EnemigoBeta4_C.png");
				//bmpEnemigoAlfaInvisible = gcnew Bitmap("EnemigoAlfaInvisible.png");
				bmpBalaEnemigo = gcnew Bitmap("BalaEnemigo_C.png");
				bmpPersonajePlus1_C = gcnew Bitmap("PersonajePlus1_C.png");
				bmpPersonajePlus2_C = gcnew Bitmap("PersonajePlus2_C.png");
				frecuenciabeta = r.Next(1, 11) * 10;
				contalfa = 0;
				contbeta = 0;
			}
		}

		if (contadorkillsparcial != ntotal&&minutos == 0&&segundos==0) {
			timer1->Enabled = false;
			this->Hide();
			FormularioPerdiste^ miformularioperdiste = gcnew FormularioPerdiste();
			miformularioperdiste->ShowDialog();
			this->Close();
		}
		//Renderizo el buffer y luego elimino los objetos creados
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;


	}
	private: System::Void PresionarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode){
		case Keys::Up:
			objJugador->set_direccion('W');
			break;
		case Keys::Down:
			objJugador->set_direccion('S');
			break;
		case Keys::Right:
			objJugador->set_direccion('D');
			break;
		case Keys::Left:
			objJugador->set_direccion('A');
			break;
		case Keys::Space:
			if (objJugador->retorna_ultimatecla() == ' ') {
				objBalaJugador = new BalaJugador(objJugador->get_x(), objJugador->get_y(), 'S');
				objArregloBalaJugador->Agregar_Bala(objBalaJugador);
			}
			else {
				objBalaJugador = new BalaJugador(objJugador->get_x(), objJugador->get_y(), objJugador->retorna_ultimatecla());
				objArregloBalaJugador->Agregar_Bala(objBalaJugador);
			}
			break;
		}
	}
	private: System::Void SoltarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		objJugador->set_direccion(' ');
	}
	bool ColisionUsando_InsertectsWith(int obj1X, int obj1Y, int obj1A, int obj1L, int obj2X, int obj2Y, int  obj2A, int obj2L)
	{
	 System::Drawing::Rectangle rectObj1 = System::Drawing::Rectangle(obj1X, obj1Y, obj1A, obj1L);
	 System::Drawing::Rectangle rectObj2 = System::Drawing::Rectangle(obj2X, obj2Y, obj2A, obj2L);
	 return rectObj1.IntersectsWith(rectObj2);
	}
	private: System::Void FormularioDelJuego_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	lblTiempo->Text = Convert::ToString(minutos+": "+segundos);
	if (segundos == 0) {
		segundos = 1;
		minutos--;
	}
	segundos--;
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
} 
