#pragma once
#include "Player.h"
#include "Enemigo.h"

#include "Items.h"

#include "ListDisco.h"
#include "Disco.h"

#include "QueueBala.h"
#include "Bala.h"

enum direccion { arriba, abajo, izquierda, derecha, ninguno };
class Juego {
	Player* player;
	Enemigo* enemigo;
	QueueBala<Bala>* MyQueueBala;
	ListDisco<Disco>* MyDiskList;

public:
	Juego() {
		//MyDiskList = new ListDisco<Disco>();
		MyQueueBala = new QueueBala<Bala>();

	}
	~Juego() { delete player; }
	void Init();
	void Run(Graphics^ g, Image^ imgplayer, Image^ imgfondo);
	void Mover_player(direccion movimiento, Graphics^ g);
	bool Colision(Base* player, Base* obj);
};
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

	enemigo = new Enemigo();
	enemigo->SetX(250);
	enemigo->SetY(500);
	enemigo->SetDX(14);
	enemigo->SetDY(0);
	enemigo->SetA(25);
	enemigo->SetL(25);

}
void Juego::Run(Graphics^ g, Image^ imgplayer, Image^ imgfondo) {
	//g->DrawImage(imgfondo, g->VisibleClipBounds);
	player->Draw(g, imgplayer);
	enemigo->Move(g);
	enemigo->Draw(g);

	

	/*int rmonedas = rand() % 30;
	if (rmonedas <= 5) {
		Disco* disco = new Disco();
		disco->SetX(rand() % 1500);
		disco->SetY(rand() % 800);
		disco->SetEliminar(false);
		disco->SetA(20);
		disco->SetL(12);
		MyDiskList->AddFirst(disco);
	}
	MyDiskList->DrawCircleFiguraAll(g, Color::Yellow);*/
		


}
bool Juego::Colision(Base* player, Base* obj) {
	Rectangle r1 = Rectangle(player->GetX(), player->GetY(), player->GetL(), player->GetL());
	Rectangle click = Rectangle(obj->GetX(), obj->GetY(), obj->GetA(), obj->GetL());
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