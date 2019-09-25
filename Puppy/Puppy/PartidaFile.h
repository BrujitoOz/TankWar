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


public:
	PartidaFile();
	void Grabar(System::String^ name, Player* player);
	void CargarPartida();
	std::vector<std::string> split(const std::string& s, char delim);
	~PartidaFile();
	int getX();
	int getY();
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


	std::ofstream outf(fileName, std::ios_base::trunc);
	if (outf.is_open())
	{
		string lineaPlayer = nameStd + "," + std::to_string(player->GetX()) + "," + std::to_string(player->GetY());

		//se guardan datos del jugador
		outf << lineaPlayer << "\n";


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