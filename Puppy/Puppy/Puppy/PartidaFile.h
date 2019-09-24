#pragma once
#include <fstream>
#include <vector>
#include <string>


#include "Player.h"

// #include <msclr/marshal_cppstd.h>

using namespace std;
class PartidaFile
{
	string fileName;


	// varaibles auxiliares que se utlizan para cargar la partida
	int playerX, playerY;


public:
	PartidaFile();
	void Grabar(System::String^ name, Player* player);
	void CargarPartida();
	~PartidaFile();
};

PartidaFile::PartidaFile()
{
	fileName = "partida.txt";
}
void PartidaFile::Grabar(System::String^ name, Player* player)
{
	//Obtenemos el nombre
	// msclr::interop::marshal_context context;

	// std::string nameStd = context.marshal_as<std::string>(name);

	std::string nameStd = "Pepe";


	std::ofstream outf(fileName, std::ios_base::app);
	if (outf.is_open())
	{
		string lineaPlayer = nameStd + "," + std::to_string(player->GetX()) + "," + std::to_string(player->GetY());

		//se guardan datos del jugador
		outf << lineaPlayer << "\n";


		outf.flush();
		outf.close();
	}
}


void PartidaFile::CargarPartida()
{
	std::string linePlayer;
	std::ifstream inf(fileName, std::ios_base::in);
	if (inf.is_open())
	{
		inf >> linePlayer;

		// picar el string linePlayer por las , para obtener los valores 
		

		
		inf.close();
	}

}

PartidaFile::~PartidaFile()
{
}

