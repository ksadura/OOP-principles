#include "PCH.h"
#include "PICKUP.h"

void PickUp::SetParameters(int mag,int sol)
{
	quantity_of_magnets = mag;
	quantity_of_solenoids = sol;

}

PickUp& PickUp::operator+=(int n)
{
	quantity_of_magnets += n;
	quantity_of_solenoids += n;
	return *this;
}