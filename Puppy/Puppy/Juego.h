#pragma once
#include "Player.h"
#include "Enemigo.h"
#include "Items.h"
#include "LinkedList.h"
#include "Heli.h"
#include "Torreta.h"

enum direccion { arriba, abajo, izquierda, derecha, ninguno };
class Juego {
	Player* player;
	LinkedList<Enemigo*> enemigos;
	LinkedList<Items*> items;
	LinkedList<Heli*> helicopteros;
	LinkedList<Torreta*> torretas;
	Enemigo* enemigo;
	int puntos;
	//Disco* disco;
public:
	Juego();
	~Juego();
	void Init();
	void Run(Graphics^ g, Image^ imgplayer, Image^ imgfondo, Image^ imgheli, Image^ imgtorret);
	void Mover_player(direccion movimiento, Graphics^ g);
	void Mover_Enemigos(Graphics^ g);
	bool Colision(Base* player, Base* disco);
	void InitEnemigos(int ene);
	void Disparar(Graphics^ g);

};
Juego::Juego() {
	puntos = 0;
}
Juego::~Juego() {
	delete player;
}
void Juego::Init() {
	player = new Player();
	player->SetX(500);
	player->SetY(300);
	String^ s = gcnew String(player->GetPathIMG());
	Image^ img = gcnew Bitmap(s);
	player->SetA(img->Width);
	player->SetL(img->Height);
	player->SetColumnaMax(4);
	player->SetFilaMax(4);

	Torreta* torret;
	for (int i = 1; i < 7; i++)
	{
		torret = new Torreta();
		torret->SetX(i*300);
		torret->SetY(800);
		torret->SetColumnaMax(9);
		torret->SetFilaMax(1);
		torretas.AddFirst(torret);
	} 

	
}
void Juego::InitEnemigos(int ene) {
	Enemigo* aux;
	for (int i = 0; i < ene ; i++)
	{
		aux = new Enemigo();
		aux->SetX(250);
		aux->SetY(500);
		aux->SetDX(14);
		aux->SetDY(0);
		aux->SetA(25);
		aux->SetL(25);
		enemigos.AddFirst(aux);
	}
}

void Juego::Run(Graphics^ g, Image^ imgplayer, Image^ imgfondo, Image^ imgheli,Image^ imgtorret) {
	g->DrawImage(imgfondo, g->VisibleClipBounds);
	player->Draw(g, imgplayer);
	Items* aux;
	Heli* heli;

	int random = rand() % 30;
	//disco->Draw(g);
	
	if (random == 4|| random == 5 || random == 6)
	{
		int tip = 1 + rand() % 4;
		aux = new Items();
		aux->SetX(rand() % 1500);
		aux->SetY(rand() % 800);
		aux->SetEliminar(false);
		aux->SetA(20);
		aux->SetL(12);
		aux->Cambiar_tipo(tip);
		items.AddFirst(aux);
	}
	
	for (Iterator<Items*> aux = items.Begin(); aux != items.End(); aux++)
	{
		Items* e = *aux;
		e->Dibujar(g);

		// se detectan colisiones entre player e items
		if (!e->GetEliminar() && Colision(player, e))
		{
			e->SetEliminar(true);

			// items.DeletePos(i);
			// le añadimos una bala al jugador en su cola
			player->AddBala(e->Retornar_tipo());

		}
	}

	// se eliminan las monedas


	if (random == 3)
	{
		heli = new Heli();
		heli->SetEliminar(false);
		heli->SetX(0);
		heli->SetY(400);
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
				puntos++;
				player->removeCurrentBala();
			}

	}
	for (Iterator<Torreta*> aux = torretas.Begin(); aux != torretas.End(); aux++)
	{
		Torreta* e = *aux;
		e->Draw(g, imgtorret);
		
	}

	



}
bool Juego::Colision(Base* b1, Base* b2) {
	Rectangle r1 = Rectangle(b1->GetX(), b1->GetY(), b1->GetL(), b1->GetL());
	Rectangle click = Rectangle(b2->GetX(), b2->GetY(), b2->GetA(), b2->GetL());
	bool inter = click.IntersectsWith(r1);
	return inter;
}
void Juego::Mover_player(direccion movimiento, Graphics^ g) {
	if (movimiento == direccion::abajo)
		player->MoveDown(g);
	if (movimiento == direccion::arriba)
		player->MoveUp(g);
	if (movimiento == direccion::derecha)
		player->MoveRight(g);
	if (movimiento == direccion::izquierda)
		player->MoveLeft(g);
}

inline void Juego::Mover_Enemigos(Graphics^ g)
{
	for (Iterator<Enemigo*> it = enemigos.Begin(); it != enemigos.End(); it++)
	{
		Enemigo* e = *it;
		e->Move(g);
	}
}

void Juego::Disparar(Graphics^ g)
{
	player->ShotPlayer();
}


