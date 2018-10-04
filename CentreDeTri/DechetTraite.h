#pragma once
#include "Dechet.h"

class DechetTraite :
	public Dechet
{
protected:
	Dechet* dechet;

public:
	DechetTraite(Dechet* dechet);
	DechetTraite();
	~DechetTraite();
	const Dechet* getDechet() const { return dechet; };
};

