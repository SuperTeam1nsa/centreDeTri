#pragma once
#include "CamionBleu.h"
#include"CamionBrun.h"
#include "CamionVert.h"
#include <iostream>

class Depot
{
public:
	Depot() :totalIDTCompostable(0), totalIDTNonRecyclable(0), totalIDTRecyclable(0) {};
	~Depot() {};
	CamionBleu* getCamionBleu() const { return new CamionBleu(); }
	CamionBrun* getCamionBrun() const { return new CamionBrun(); }
	CamionVert* getCAmionVert() const { return new CamionVert(); }
	void depotDechetsTraites(CamionVert* camion) { totalIDTNonRecyclable += camion->viderCamion(); }
	void depotDechetsTraites(CamionBleu* camion) { totalIDTRecyclable += camion->viderCamion(); }
	void depotDechetsTraites(CamionBrun* camion) { totalIDTCompostable += camion->viderCamion(); }
	std::ostream& operator <<(std::ostream& out) const {
		out << std::endl << --DEPOT-- << std::endl << "totalIDTRecyclable	:" << totalIDTRecyclable
			<< std::endl << "totalIDTNonRecyclable	:" << totalIDTNonRecyclable
			<< std::endl << "totalIDTCompostable	:" << totalIDTCompostable;
		return out;
	}

private:
	int totalIDTRecyclable;
	int totalIDTNonRecyclable;
	int totalIDTCompostable;

};
