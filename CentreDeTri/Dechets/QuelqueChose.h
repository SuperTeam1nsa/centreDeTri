#pragma once
#include "../Dechet.h"
class QuelqueChose :
	public Dechet
{
public:
	QuelqueChose() :Dechet(10, "Un gros tas sombre et plutot lourd", 0, "noir", INCONNU, 10, false, false) {};
	~QuelqueChose() {};
};