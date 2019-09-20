#pragma once
#include "Juego.h"
namespace Puppy {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public Form {
		Juego* objjuego;
		Image^ imgplayer = gcnew Bitmap("tanque.png");
		Image^ imgfondo = gcnew Bitmap("fondov2.jpg");
		Image^ imgheli = gcnew Bitmap("Helicop.png");
		Image^ imgtorret = gcnew Bitmap("Torreta.jpg");
	public:
		MyForm(void) {
			InitializeComponent();
			objjuego = new Juego();
			objjuego->Init();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (objjuego != NULL) {
			Graphics^ g = this->CreateGraphics();
			BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
			buffer->Graphics->Clear(Color::White);
			objjuego->Run(buffer->Graphics, imgplayer, imgfondo, imgheli, imgtorret);
			buffer->Render(g);
			delete espacioBuffer;
			delete g;
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left)
			objjuego->Mover_player(direccion::izquierda, CreateGraphics());
		if (e->KeyCode == Keys::Right)
			objjuego->Mover_player(direccion::derecha, CreateGraphics());
		if (e->KeyCode == Keys::Up)
			objjuego->Mover_player(direccion::arriba, CreateGraphics());
		if (e->KeyCode == Keys::Down)
			objjuego->Mover_player(direccion::abajo, CreateGraphics());
	}
	};
}