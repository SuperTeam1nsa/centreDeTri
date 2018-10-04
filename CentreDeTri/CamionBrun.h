#pragma once
#include "Camion.h"
class CamionBrun :
	public Camion
{
public:
	CamionBrun() :Camion(50) {};
	~CamionBrun() {};
	bool ajouterDechet(DechetTraiteCompostable *d) { ajouterDechet(d); };
};
