#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "Player.h"

// #include <msclr/marshal_cppstd.h>

using namespace std;
class PartidaFile
{
	string fileName;


	// varaibles auxiliares que se utlizan para cargar la partida
	int playerX, playerY;
	LinkedList<Heli*> helicopteros;
	LinkedList<Torreta*> torretas;


public:
	PartidaFile();
	void Grabar(string name, Player* player, LinkedList<Heli*> heli, LinkedList<Torreta*> torretas);
	void CargarPartida();
	std::vector<std::string> split(const std::string& s, char delim);
	~PartidaFile();
	int getX();
	int getY();
	LinkedList<Heli*> getHelicopteros();
	LinkedList<Torreta*> geTorretas();

};

PartidaFile::PartidaFile()
{
	fileName = "partida.txt";
}
void PartidaFile::Grabar(string name, Player* player, LinkedList<Heli*> helicopteros, LinkedList<Torreta*> torretas)
{
	std::ofstream outf(fileName, std::ios_base::trunc);
	if (outf.is_open())
	{
		string lineaPlayer = name + "," + std::to_string(player->GetX()) + "," + std::to_string(player->GetY());

		//se guardan datos del jugador
		outf << lineaPlayer << "\n";

		// guardamos los helicopteros
		outf << helicopteros.size() << "\n";

		for (Iterator<Heli*> aux = helicopteros.Begin(); aux != helicopteros.End(); aux++)
		{
			Heli* h = *aux;
		    
			string lineaHeli = std::to_string(h->GetX()) + "," + std::to_string(h->GetY());

			//se guardan datos de los helicopteros
			outf << lineaHeli << "\n";

		}

		//guardamos las torretas
		outf << torretas.size() << "\n";

		for (Iterator<Torreta*> aux = torretas.Begin(); aux != torretas.End(); aux++)
		{
			Torreta* t = *aux;

			string lineaTorreta = std::to_string(t->GetX()) + "," + std::to_string(t->GetY()) + "," + std::to_string(t->GetVidas());

			//se guardan datos de los helicopteros
			outf << lineaTorreta << "\n";

		}

		outf.flush();
		outf.close();
	}
}

std::vector<std::string> PartidaFile::split(const std::string& s, char delim = ',') {
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
		// elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
	}
	return elems;
}



void PartidaFile::CargarPartida()
{
	std::string linePlayer;
	std::ifstream inf(fileName, std::ios_base::in);
	if (inf.is_open())
	{
		inf >> linePlayer;

		// picar el string linePlayer por las , para obtener los valores 
		std::vector<std::string> values = split(linePlayer);

		playerX = std::stoi(values[1]);
		playerY = std::stoi(values[2]);


		// se obtienen la cantidad de helicopteros para poder leer sus coordenadas
		int cantHelicopteros = 0;
		inf >> cantHelicopteros;

		for (int i = 0; i < cantHelicopteros; i++)
		{
			std::string lineHelicoptero;
			inf >> lineHelicoptero;

			std::vector<std::string> valuesH = split(lineHelicoptero);


			int HeliX = std::stoi(valuesH[0]);
			int HeliY = std::stoi(valuesH[1]);

			Heli* heli = new Heli();
			heli->SetEliminar(false);
			heli->SetX(HeliX);
			heli->SetY(HeliY);
			heli->SetDX(5);
			heli->SetDY(0);
			heli->SetFilaMax(4);
			heli->SetColumnaMax(1);
			helicopteros.AddFirst(heli);


		}


		// se obtienen la cantidad de helicopteros para poder leer sus coordenadas
		int cantTorretas = 0;
		inf >> cantTorretas;

		for (int i = 0; i < cantTorretas; i++)
		{

			std::string lineT;
			inf >> lineT;

			std::vector<std::string> valuesT = split(lineT);

			int tx = std::stoi(valuesT[0]);
			int ty = std::stoi(valuesT[1]);
			int vida = std::stoi(valuesT[2]);

			Torreta *torret = new Torreta();
			torret->SetX(tx);
			torret->SetY(ty);
			torret->SetColumnaMax(4);
			torret->SetFilaMax(1);
			torret->SetVidas(vida);
			if (i < 3) torret->SetIndiceColumna(3);
			else torret->SetIndiceColumna(0);
			torret->SetEliminar(false);
			torretas.AddFirst(torret);


		}



		
		inf.close();
	}

}

PartidaFile::~PartidaFile()
{
}

inline int PartidaFile::getX()
{
	return playerX;
}

inline int PartidaFile::getY()
{
	return playerY;
}

inline LinkedList<Heli*> PartidaFile::getHelicopteros()
{
	return helicopteros;
}

inline LinkedList<Torreta*> PartidaFile::geTorretas()
{
	return torretas;
}
