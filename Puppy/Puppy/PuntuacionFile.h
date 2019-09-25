#pragma once
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class PuntuacionFile
{
	string fileName;

public:
	PuntuacionFile();
	void Grabar(string nombre, int puntos, int vidas);
	vector<string> ListaPuntuacion();
	~PuntuacionFile();
};

PuntuacionFile::PuntuacionFile()
{
	fileName = "puntuacion.txt";
}
void PuntuacionFile::Grabar(string nombre, int puntos, int vidas)
{
	string linea = nombre + "," + std::to_string(puntos)+","+std::to_string(vidas);

	std::ofstream outf(fileName, std::ios_base::app);
	if (outf.is_open())
	{
		outf << linea << "\n";
		outf.flush();
		outf.close();
	}
}
vector<string> PuntuacionFile::ListaPuntuacion()
{
	vector<string> lineas;

	std::string line;
	std::ifstream inf(fileName, std::ios_base::in);
	if (inf.is_open())
	{
		while (inf >> line)
		{
			lineas.push_back(line);
		}
		inf.close();
	}

	return lineas;
}

PuntuacionFile::~PuntuacionFile()
{
}

