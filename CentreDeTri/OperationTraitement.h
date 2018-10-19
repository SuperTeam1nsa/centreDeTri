#pragma once
//#include "UsineTraitement.h"
#include "Operation.h"
#include "Compteur.h"
class UsineTraitement;
class OperationTraitement :
	public Operation
{

public:
	OperationTraitement(UsineTraitement* usineT);
	OperationTraitement(OperationTraitement const& autre);
	virtual ~OperationTraitement();

	bool effectuerOperation(Dechet* dechet) override { return false; }
protected:
	void creerDechetTraiteRecyclable(Dechet* dechet);//inside via friend
	void creerDechetTraiteNonRecyclable(Dechet* dechet);
	void creerDechetTraiteCompostable(Dechet* dechet);
private:
	UsineTraitement *usineTraitement;

};
