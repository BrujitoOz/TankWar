#pragma once
#include <vector>


#include "Player.h"
#include "Enemigo.h"
#include "Items.h"
#include "LinkedList.h"
#include "Heli.h"
#include "Torreta.h"
#include "Bala.h"
#include "DisparoT.h"
#include "Explocion.h"
#include "TVida.h"
#include "Pillation.h"

#include "PuntuacionFile.h"
#include "PartidaFile.h"

#include "AuxPunt.h"


enum direccion { arriba, abajo, izquierda, derecha, ninguno };
class Juego {
	Player* player;
	LinkedList<Enemigo*> enemigos;
	LinkedList<Items*> items;
	LinkedList<Heli*> helicopteros;
	LinkedList<Torreta*> torretas;
	LinkedList<DisparoT*> shott;
	LinkedList<Explocion*> bum;
	Pillation<TVida*> pila1;
	Pillation<TVida*> pila2;
	Pillation<TVida*> pila3;
	Pillation<TVida*> pila4;
	Pillation<TVida*> pila5;
	Pillation<TVida*> pila6;

	int puntos;
	int vidas = 1;
	string nombre;

	bool pausa;
	PuntuacionFile*  puntuacion;
	PartidaFile* partida;

public:
	Juego();
	~Juego();
	void Init(Graphics^ g);
	void Run(Graphics^ g, Image^ imgplayer, Image^ imgfondo, Image^ imgheli, Image^ imgtorret, Image^imgbalas, Image^ imgitems, Image^ imgshut, Image^ imgbum, Image^ imgTV);
	void Mover_player(direccion movimiento, Graphics^ g);
	
	bool Colision(Base* player, Base* disco);
	void Disparar(Graphics^ g);


	void GrabarPuntuacion();
	vector<AuxPunt> GetPuntuaciones();
	void GrabarPartida();
	void CargarPartida();
	int GetVida();
	void SetPausa(bool pausa);
	bool GetPausa();
	int GetPuntos();
	void SetNombre(string nombre);
	string GetNombre();

};
Juego::Juego() {
	puntos = 0;
	puntuacion = new PuntuacionFile();
	partida = new PartidaFile();
	pausa = true;
}
Juego::~Juego() {
	delete player;
}
void Juego::Init(Graphics^ g) {
	player = new Player();
	player->SetX(500);
	player->SetY(100);
	String^ s = gcnew String(player->GetPathIMG());
	Image^ img = gcnew Bitmap(s);
	player->SetA(img->Width);
	player->SetL(img->Height);
	player->SetColumnaMax(4);
	player->SetFilaMax(1);
	player->SetEliminar(false);

	Torreta* torret;
	for (int i = 0; i < 6; i++)
	{
		torret = new Torreta();
		torret->SetX(i*300);
		torret->SetY(g->VisibleClipBounds.Bottom - 150);
		torret->SetColumnaMax(4);
		torret->SetFilaMax(1);
		torret->SetVidas(4);
		if (i < 3) torret->SetIndiceColumna(3);
		else torret->SetIndiceColumna(0);
		torret->SetEliminar(false);
		torretas.AddFirst(torret);
	} 
	TVida* vida1;
	for (int i = 0; i < 4; i++)
	{
		vida1 = new TVida();
		vida1->SetX(40);
		vida1->SetY(g->VisibleClipBounds.Bottom - 20);
		vida1->SetColumnaMax(4);
		vida1->SetFilaMax(1);
		vida1->SetIndiceColumna(rand() % 4);
		vida1->SetEliminar(false);
		pila1.push(vida1);
	}
	TVida* vida2;
	for (int i = 0; i < 4; i++)
	{
		vida2 = new TVida();
		vida2->SetX(40+300);
		vida2->SetY(g->VisibleClipBounds.Bottom - 20);
		vida2->SetColumnaMax(4);
		vida2->SetFilaMax(1);
		vida2->SetIndiceColumna(rand() % 4);
		vida2->SetEliminar(false);
		pila2.push(vida2);
	}
	TVida* vida3;
	for (int i = 0; i < 4; i++)
	{
		vida3 = new TVida();
		vida3->SetX(40+600);
		vida3->SetY(g->VisibleClipBounds.Bottom - 20);
		vida3->SetColumnaMax(4);
		vida3->SetFilaMax(1);
		vida3->SetIndiceColumna(rand() % 4);
		vida3->SetEliminar(false);
		pila3.push(vida3);
	}
	TVida* vida4;
	for (int i = 0; i < 4; i++)
	{
		vida4 = new TVida();
		vida4->SetX(80+900);
		vida4->SetY(g->VisibleClipBounds.Bottom - 20);
		vida4->SetColumnaMax(4);
		vida4->SetFilaMax(1);
		vida4->SetIndiceColumna(rand() % 4);
		vida4->SetEliminar(false);
		pila4.push(vida4);
	}
	TVida* vida5;
	for (int i = 0; i < 4; i++)
	{
		vida5 = new TVida();
		vida5->SetX(80+1200);
		vida5->SetY(g->VisibleClipBounds.Bottom - 20);
		vida5->SetColumnaMax(4);
		vida5->SetFilaMax(1);
		vida5->SetIndiceColumna(rand() % 4);
		vida5->SetEliminar(false);
		pila5.push(vida5);
	}
	TVida* vida6;
	for (int i = 0; i < 4; i++)
	{
		vida6 = new TVida();
		vida6->SetX(80+1500);
		vida6->SetY(g->VisibleClipBounds.Bottom - 20);
		vida6->SetColumnaMax(4);
		vida6->SetFilaMax(1);
		vida6->SetIndiceColumna(rand() % 4);
		vida6->SetEliminar(false);
		pila6.push(vida6);
	}
}


void Juego::Run(Graphics^ g, Image^ imgplayer, Image^ imgfondo, Image^ imgheli,Image^ imgtorret, Image^imgbalas, Image^ imgitems, Image^ imgshut, Image^ imgbum, Image^ imgTV) {
	g->DrawImage(imgfondo, g->VisibleClipBounds);
	player->Draw(g, imgplayer, imgbalas);

	if (pausa)
		return;

	Items* aux;
	Heli* heli;
	DisparoT* shutt;
	Explocion* boom;
	Bala* balita;
	int random = rand() % 60;
	int qtd;
	int auxqdt;

	if (random == 4|| random == 5 || random == 6)
	{
		int tip = 1 + rand() % 4;
		aux = new Items();
		aux->SetX(rand() % 1500);
		aux->SetY(rand() % 800);
		aux->SetEliminar(false);
		aux->SetColumnaMax(7);
		aux->SetFilaMax(1);
		aux->SetA(20);
		aux->SetL(20);
		aux->Cambiar_tipo(tip);
		items.AddFirst(aux);
	}
	if (random == 10 || random == 11 || random ==12)
	{
		qtd = rand() % 6;
		int disx;
		int disy;
		int qtd2 = 0;
		for (Iterator<Torreta*> aux = torretas.Begin(); aux != torretas.End(); aux++)
		{
			if (qtd < 3 && qtd == qtd2)
			{
				Torreta* e = *aux;
				e->SetIndiceColumna(1);
				e->Draw(g, imgtorret);
				 disx = e->GetX();
				 disy =e->GetY();
				 auxqdt = qtd;
				 break;
			}
			if (qtd >= 3 && qtd == qtd2)
			{
				
				Torreta* e = *aux;
				
				e->SetIndiceColumna(2);
				e->Draw(g, imgtorret);
				disx = e->GetX();
				disy = e->GetY();
				auxqdt = qtd;
				break;
			}
			qtd2 = qtd2 + 1;
		}
		shutt = new DisparoT();
		shutt->SetY(disy);
		if (qtd < 3)
		{
			shutt->SetX(disx + 60);
			shutt->SetDX(-15);
			shutt->SetDY(-15);
		}
		else
		{
			shutt->SetX(disx + 150);
			shutt->SetDX(15);
			shutt->SetDY(-15);
		}
		shutt->SetEliminar(false);
		shutt->SetA(imgshut->Width);
		shutt->SetL(imgshut->Height);
		shott.AddFirst(shutt);
	}
	vector<int> aEliminar;

	for (Iterator<Items*> aux = items.Begin(); aux != items.End(); aux++)
	{
		Items* e = *aux;
		e->Dibujar(g, imgitems);

		// se detectan colisiones entre player e items
		if (!e->GetEliminar() && Colision(player, e))
		{
			e->SetEliminar(true);
			aEliminar.push_back(aux.getPos());
			// items.DeletePos(i);
			// le añadimos una bala al jugador en su cola
			player->AddBala(e->Retornar_tipo());

		}
	}

	// se eliminan las monedas
	for (int i = 0; i < aEliminar.size(); i++)
		items.DeletePos(aEliminar[i]);

	if (random == 3)
	{
		heli = new Heli();
		heli->SetEliminar(false);
		heli->SetX(0);
		heli->SetY(500);
		heli->SetDX(5);
		heli->SetDY(0);
		heli->SetFilaMax(4);
		heli->SetColumnaMax(1);
		helicopteros.AddFirst(heli);
	}
	for (Iterator<Heli*> aux = helicopteros.Begin(); aux != helicopteros.End(); aux++)
	{
		Heli* e = *aux;
		e->Draw(g, imgheli);
		e->Move(g);

		if(player->getCurrentBala() != nullptr)
			if (!e->GetEliminar() && Colision(player->getCurrentBala(), e))
			{
				e->SetEliminar(true);
				puntos=puntos+50;
				player->removeCurrentBala();
				GrabarPuntuacion();
			}
		
	}
	for (Iterator<DisparoT*> aux = shott.Begin(); aux != shott.End(); aux++)
	{
		DisparoT* e = *aux;
		if (e->GetEliminar() == false) {
			e->Dibujar(g, imgshut);
			e->Mover(g);
			if (!e->GetEliminar() && Colision(player, e))
			{

				boom = new Explocion();
				boom->SetX(e->GetX() - 15);
				boom->SetY(e->GetY() - 15);
				boom->SetEliminar(false);
				boom->SetColumnaMax(8);
				boom->SetFilaMax(4);
				boom->SetIndiceFila(3);
				bum.AddFirst(boom);

				e->SetEliminar(true);

				vidas--;
				if (vidas == 0)
				{
					player->SetEliminar(true);
					GrabarPuntuacion();
				}
			}
		}
	}
	int qtd3 = 0;
	int cont = 0;
	for (Iterator<Torreta*> aux = torretas.Begin(); aux != torretas.End(); aux++)
	{

		Torreta* e = *aux;
		if (random == 10 || random == 11)
		{
			if (qtd3 <3 && auxqdt == qtd3)
			{
				e->SetIndiceColumna(0);
			}
			if (qtd3 >= 3 && auxqdt == qtd3)
			{
				e->SetIndiceColumna(3);
			}
		}
		if (player->getCurrentBala() != nullptr)
			if (!e->GetEliminar() && Colision(player->getCurrentBala(), e))
			{
				if ((cont ==5 && player->getCurrentBala()->Retornar_tipo() == pila1.top()->GetIndiceColumna()+1) || 
					(cont == 4 && player->getCurrentBala()->Retornar_tipo() == pila2.top()->GetIndiceColumna() + 1) ||
					(cont == 3 && player->getCurrentBala()->Retornar_tipo() == pila3.top()->GetIndiceColumna() + 1) ||
					(cont == 2 && player->getCurrentBala()->Retornar_tipo() == pila4.top()->GetIndiceColumna() + 1) ||
					(cont == 1 && player->getCurrentBala()->Retornar_tipo() == pila5.top()->GetIndiceColumna() + 1) ||
					(cont == 0 && player->getCurrentBala()->Retornar_tipo() == pila6.top()->GetIndiceColumna() + 1) 	)
				{
					e->SetVidas(e->GetVidas() - 1);
					//puntos++;
					boom = new Explocion();
					boom->SetX(e->GetX() + 15);
					boom->SetY(e->GetY() + 15);
					boom->SetEliminar(false);
					boom->SetColumnaMax(8);
					boom->SetFilaMax(4);
					if (player->getCurrentBala()->Retornar_tipo() == 4)  boom->SetIndiceFila(1);
					if (player->getCurrentBala()->Retornar_tipo() == 1)  boom->SetIndiceFila(3);
					if (player->getCurrentBala()->Retornar_tipo() == 2)  boom->SetIndiceFila(0);
					if (player->getCurrentBala()->Retornar_tipo() == 3)  boom->SetIndiceFila(2);

					bum.AddFirst(boom);
					player->removeCurrentBala();

					//GrabarPuntuacion();
					if (e->GetVidas() == 0)
					{
						e->SetEliminar(true);
						puntos = puntos + 1000;
						player->removeCurrentBala();
						
					}
					if (cont ==5 )pila1.pop();
					if (cont == 4 )pila2.pop();
						if (cont == 3 )pila3.pop();
							if (cont == 2 )pila4.pop();
								if (cont == 1) pila5.pop();
									if (cont == 0 )pila6.pop();
				}

				
				
			}
		
		e->Draw(g, imgtorret);
		qtd3 = qtd3 + 1;
		cont = cont + 1;
	}
	
	for (Iterator<Explocion*> aux = bum.Begin(); aux != bum.End(); aux++)
	{
		Explocion* e = *aux;
		e->Draw(g, imgbum);
			
	}
	
	if (!pila1.empty()) pila1.top()->Draw(g, imgTV);
	if (!pila2.empty()) pila2.top()->Draw(g, imgTV);
	if (!pila3.empty()) pila3.top()->Draw(g, imgTV);
	if (!pila4.empty()) pila4.top()->Draw(g, imgTV);
	if (!pila5.empty()) pila5.top()->Draw(g, imgTV);
	if (!pila6.empty()) pila6.top()->Draw(g, imgTV);
}
bool Juego::Colision(Base* b1, Base* b2) {
	Rectangle r1 = Rectangle(b1->GetX(), b1->GetY(), b1->GetL(), b1->GetL());
	Rectangle r2 = Rectangle(b2->GetX(), b2->GetY(), b2->GetA(), b2->GetL());
	bool inter = r2.IntersectsWith(r1);
	return inter;
}
void Juego::Mover_player(direccion movimiento, Graphics^ g) {
	
	if (pausa)
		return;
	
	if (movimiento == direccion::abajo)
		player->MoveDown(g);
	if (movimiento == direccion::arriba)
		player->MoveUp(g);
	if (movimiento == direccion::derecha)
		player->MoveRight(g);
	if (movimiento == direccion::izquierda)
		player->MoveLeft(g);
}


void Juego::Disparar(Graphics^ g)
{
	player->ShotPlayer();
}

void Juego::GrabarPuntuacion()
{
	puntuacion->Grabar(this->nombre, puntos, vidas);
}


std::vector<std::string> split(const std::string& s, char delim) {
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}




vector < AuxPunt > Juego::GetPuntuaciones()
{
	vector<string>  puntuaciones =  puntuacion->ListaPuntuacion();
	vector<AuxPunt>  puntuacionesOrdenadas;

	std::vector<std::string> nombres;
	std::vector<std::string> puntos;

	for (int i = 0; i < puntuaciones.size(); i++)
	{
		std::vector<std::string> values = split(puntuaciones[i], ',');
		nombres.push_back(values[0]);
		puntos.push_back(values[1]);
	}

	auto compare = [](string s1, string s2) {

		int i1 = std::stoi(s1);
		int i2 = std::stoi(s2);

		if (i1 < i2)
			return true;

		return false;
	};


	for (int i = 0; i < puntuaciones.size() - 1; i++)
	{
		string s1 = puntos[i];

		for (int j = i + 1; j < puntuaciones.size(); j++)
		{
			string s2 = puntos[j];

			if (compare(s1, s2))
			{
				string aux = puntos[i];
				puntos[i] = puntos[j];
				puntos[j] = aux;

				string aux1 = nombres[i];
				nombres[i] = nombres[j];
				nombres[j] = aux1;
			}

		}

	}

	for (int i = 0; i < puntuaciones.size(); i++) {

		AuxPunt ap;
		ap.nombre = nombres[i];
		ap.puntos = puntos[i];
		puntuacionesOrdenadas.push_back(ap);
	}

	return puntuacionesOrdenadas;

}											  
inline void Juego::GrabarPartida()
{
	partida->Grabar(nombre, player,helicopteros,torretas);
}

inline void Juego::CargarPartida()
{

	partida = new PartidaFile();

	partida->CargarPartida();

	player->SetX(partida->getX());
	player->SetY(partida->getY());

	partida->CargarPartida();
	
	LinkedList<Heli*> guardados = partida->getHelicopteros();

	while (!helicopteros.empty())
		helicopteros.DeleteFirst();

	for (Iterator<Heli*> aux = guardados.Begin(); aux != guardados.End(); aux++)
	{
		Heli* e = *aux;
		helicopteros.AddFirst(e);
	}

	/*LinkedList<Torreta*> guardadosT = partida->geTorretas();

	while (!torretas.empty())
		torretas.DeleteFirst();

	for (Iterator<Torreta*> aux = guardadosT.Begin(); aux != guardadosT.End(); aux++)
	{
		Torreta* e = *aux;
		torretas.AddFirst(e);
	}*/

	pausa = false;
}


void Juego::SetPausa(bool pausa)
{
	this->pausa = pausa;
}

bool Juego::GetPausa()
{
	return this->pausa;
}

 int Juego::GetPuntos()
{
	return puntos;
}
 int Juego::GetVida()
 {
	 return vidas;
 }
 void Juego::SetNombre(string nombre)
{
	 this->nombre = nombre;
}

 string Juego::GetNombre()
{
	return this->nombre;
}
