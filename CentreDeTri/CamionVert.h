#pragma once
#include "Camion.h"
class CamionVert :
	public Camion
{
public:
	CamionVert() :Camion(40) {};
	~CamionVert() {};
	bool ajouterDechet(DechetTraiteNonRecyclable *d) { ajouterDechet(d); };

};
