#pragma once
#include "Camion.h"

class CamionBleu :public Camion
{
public:
	CamionBleu() :Camion(30) {};
	~CamionBleu() {};
	bool ajouterDechet(DechetTraiteRecyclable *d) { ajouterDechet(d) };


};
