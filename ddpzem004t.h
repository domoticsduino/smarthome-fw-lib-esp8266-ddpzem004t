/* 1.0.0 VERSION */

#ifndef ddpzem004t_h
#define ddpzem004t_h

#include <SoftwareSerial.h> // Arduino IDE <1.6.6
#include <PZEM004T.h>

#define MAX_ATTEMPTS 1

struct DDPZEM004TVal
{
	float current = 0.0;
	float voltage = 0.0;
	float power = 0.0;
	float energy = 0.0;
	bool success;
	const char *errorMsg;
};

class DDPzem004t
{
private:
	int _led;
	float getVoltage(PZEM004T *, IPAddress);
	float getCurrent(PZEM004T *, IPAddress);
	float getPower(PZEM004T *, IPAddress);
	float getEnergy(PZEM004T *, IPAddress);

public:
	DDPzem004t(int);
	DDPZEM004TVal getValues(PZEM004T *, IPAddress);
	void init(PZEM004T *, IPAddress);
};

#endif