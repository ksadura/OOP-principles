#include "PickUp.h"

void PickUp::SetParameters(int mag, int sol)
{
	noMagnets = mag;
	noSolenoids = sol;

}

PickUp& PickUp::operator+=(int n)
{
	noMagnets += n;
	noSolenoids += n;

	return *this;
}