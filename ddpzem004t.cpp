/* 1.0.0 VERSION */

#include "ddpzem004t.h"

DDPzem004t::DDPzem004t(int led)
{
	this->_led = led;
}

void DDPzem004t::init(PZEM004T *pzem, IPAddress ip)
{
	pzem->setAddress(ip);
}

float DDPzem004t::getVoltage(PZEM004T *pzem, IPAddress ip)
{
	int i = 0;
	float r = -1.0;
	do
	{
		r = pzem->voltage(ip);
		wdt_reset();
		i++;
	} while (i < MAX_ATTEMPTS && r < 0.0);
	return r;
}

float DDPzem004t::getCurrent(PZEM004T *pzem, IPAddress ip)
{
	int i = 0;
	float r = -1.0;
	do
	{
		r = pzem->current(ip);
		wdt_reset();
		i++;
	} while (i < MAX_ATTEMPTS && r < 0.0);
	return r;
}

float DDPzem004t::getPower(PZEM004T *pzem, IPAddress ip)
{
	int i = 0;
	float r = -1.0;
	do
	{
		r = pzem->power(ip);
		wdt_reset();
		i++;
	} while (i < MAX_ATTEMPTS && r < 0.0);
	return r;
}

float DDPzem004t::getEnergy(PZEM004T *pzem, IPAddress ip)
{
	int i = 0;
	float r = -1.0;
	do
	{
		r = pzem->energy(ip);
		wdt_reset();
		i++;
	} while (i < MAX_ATTEMPTS && r < 0.0);
	return r;
}

DDPZEM004TVal DDPzem004t::getValues(PZEM004T *pzem, IPAddress ip)
{
	DDPZEM004TVal ret;
	ret.voltage = getVoltage(pzem, ip);
	ret.current = getCurrent(pzem, ip);
	ret.power = getPower(pzem, ip);
	ret.energy = getEnergy(pzem, ip);
	ret.success = ret.voltage >= 0.0 && ret.voltage >= 0.0 && ret.voltage >= 0.0 && ret.voltage >= 0.0;
	return ret;
}