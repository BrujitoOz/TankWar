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
		Image^ imgplayer = gcnew Bitmap("tanques.png");
		Image^ imgfondo = gcnew Bitmap("fondov2.jpg");
		Image^ imgheli = gcnew Bitmap("Helicop.png");
		Image^ imgtorret = gcnew Bitmap("torretas.png");
		Image^ imgbalas = gcnew Bitmap("balas.png");
		Image^ imgshut = gcnew Bitmap("disparot.png");
		Image^ imgbum = gcnew Bitmap("explociones.png");
		Image^ imgTV = gcnew Bitmap("TVida.png");
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblShowName;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lblPtos;
	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;


			 Image^ imgitems = gcnew Bitmap("items.png");
	public:
		MyForm(void) {
			InitializeComponent();
			objjuego = new Juego();
			objjuego->Init(CreateGraphics());
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblShowName = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblPtos = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->lblName);
			this->panel1->Location = System::Drawing::Point(38, 44);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 133);
			this->panel1->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(60, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Guardar Partida";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::Label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(60, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Cargar Partida";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::Label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(60, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Iniciar Partida";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::Label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(57, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Location = System::Drawing::Point(4, 20);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(47, 13);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"Nombre:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nombre:";
			this->label1->Visible = false;
			// 
			// lblShowName
			// 
			this->lblShowName->AutoSize = true;
			this->lblShowName->Location = System::Drawing::Point(54, 9);
			this->lblShowName->Name = L"lblShowName";
			this->lblShowName->Size = System::Drawing::Size(53, 13);
			this->lblShowName->TabIndex = 2;
			this->lblShowName->Text = L"John Doe";
			this->lblShowName->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(133, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Puntos:";
			this->label5->Visible = false;
			// 
			// lblPtos
			// 
			this->lblPtos->AutoSize = true;
			this->lblPtos->Location = System::Drawing::Point(172, 9);
			this->lblPtos->Name = L"lblPtos";
			this->lblPtos->Size = System::Drawing::Size(13, 13);
			this->lblPtos->TabIndex = 4;
			this->lblPtos->Text = L"0";
			this->lblPtos->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(210, 8);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Vida:";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(237, 8);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"5";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->lblPtos);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lblShowName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (objjuego != NULL) {
			Graphics^ g = this->CreateGraphics();
			BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
			buffer->Graphics->Clear(Color::White);
			objjuego->Run(buffer->Graphics, imgplayer, imgfondo, imgheli, imgtorret, imgbalas, imgitems,  imgshut,  imgbum, imgTV);

			//cambiamos puntuacion
			this->lblPtos->Text = objjuego->GetPuntos().ToString();
			this->label9->Text = objjuego->GetVida().ToString();
			if (objjuego->GetPausa())
			{
				this->panel1->Visible = true;
				this->panel1->Enabled = true;
			}
			else {
				this->panel1->Visible = false;
				this->panel1->Enabled = false;

			}
			if (objjuego->GetVida() == 0) {
			//	Close();
			}

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
		if (e->KeyCode == Keys::Space)
			objjuego->Disparar(CreateGraphics());

		if (e->KeyCode == Keys::P)
			objjuego->SetPausa(!objjuego->GetPausa());

	}
	private: System::Void Label2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox1->Enabled = false;
		this->textBox1->Visible = false;


		//Obtenemos el nombre
		/*msclr::interop::marshal_context context;

		std::string nameStd = context.marshal_as<std::string>(this->textBox1->Text);
		objjuego->SetNombre(nameStd);*/

		this->lblShowName->Visible = true;
		this->label1->Visible = true;
		this->label9->Visible = true;
		this->label5->Visible = true;
		this->lblPtos->Visible = true;

		this->lblShowName->Text = this->textBox1->Text;

		objjuego->SetPausa(false);

	}

    // grabar partida
	private: System::Void Label4_Click(System::Object^ sender, System::EventArgs^ e) {
		objjuego->GrabarPartida();
		MessageBox::Show("Partida Guardada");
	}

    // cargar partida
	private: System::Void Label3_Click(System::Object^ sender, System::EventArgs^ e) {
		objjuego->CargarPartida();
	}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}