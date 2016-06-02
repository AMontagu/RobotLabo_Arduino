// 
// 
// 

#include "LightActionner.h"

LightActionner::LightActionner(char* actionName, int lightPin, int num_leds, int brightness, int* gamma, int delay, int first_arg, int second_arg)
{
	this->actionnerName = actionName;
	this->actionnerFamily = actionerFamily::lightActioner;
	this->lightPin = lightPin;
	this->num_leds = num_leds;
	this->brightness = brightness;
	this->gamma = gamma;
	this->isSetupVar = false;
	this->delaytime = delay;
	this->first_arg = first_arg;
	this->second_arg = second_arg;
	this->strip = Adafruit_NeoPixel(this->num_leds, this->lightPin, first_arg + second_arg);
	//this->setup();
}

LightActionner::LightActionner(const LightActionner &la) : Actioner(la) {
	this->actionnerName = la.actionnerName;
	this->actionnerFamily = la.actionnerFamily;
	this->lightPin = la.lightPin;
	this->num_leds = la.num_leds;
	this->brightness = la.brightness;
	this->gamma = la.gamma;
	this->delaytime = la.delaytime;
	this->first_arg = la.first_arg;
	this->second_arg = la.second_arg;
	this->setup();
}

LightActionner::LightActionner()
{
}

LightActionner ::~LightActionner()
{
}

bool LightActionner::setup(void)
{
	strip.setBrightness(this->brightness);
	strip.begin();
	strip.show();
	this->isSetupVar = true;
	return this->isSetupVar;
}

bool LightActionner::isSetup(void)
{
	return this->isSetupVar;
}

void LightActionner::doAction(int actionNumber)
{
	colorWipe(strip.Color(255, 0, 0), brightness); // Red
	colorWipe(strip.Color(0, 255, 0), brightness); // Green
	colorWipe(strip.Color(0, 0, 255), brightness); // Blue
	colorWipe(strip.Color(0, 0, 0, 255), brightness); // White

	whiteOverRainbow(20, 75, 5);

	pulseWhite(5);

	// fullWhite();
	// delay(2000);

	rainbowFade2White(3, 3, 1);
}

void LightActionner::reset(void)
{
}

char* LightActionner::getActionerName(void)
{
	return nullptr;
}

int LightActionner::getActionerType(void)
{
	return 0;
}

void LightActionner::colorWipe(uint32_t c, uint8_t wait)
{
	for (uint16_t i = 0; i<strip.numPixels(); i++) {
		strip.setPixelColor(i, c);
		strip.show();
		delay(wait);
	}
}

void LightActionner::pulseWhite(uint8_t wait)
{
	for (int j = 0; j < 256; j++) {
		for (uint16_t i = 0; i<strip.numPixels(); i++) {
			strip.setPixelColor(i, strip.Color(0, 0, 0, gamma[j]));
		}
		delay(wait);
		strip.show();
	}

	for (int j = 255; j >= 0; j--) {
		for (uint16_t i = 0; i<strip.numPixels(); i++) {
			strip.setPixelColor(i, strip.Color(0, 0, 0, gamma[j]));
		}
		delay(wait);
		strip.show();
	}
}

void LightActionner::rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops)
{
	float fadeMax = 100.0;
	int fadeVal = 0;
	uint32_t wheelVal;
	int redVal, greenVal, blueVal;

	for (int k = 0; k < rainbowLoops; k++) {

		for (int j = 0; j<256; j++) { // 5 cycles of all colors on wheel

			for (int i = 0; i< strip.numPixels(); i++) {

				wheelVal = Wheel(((i * 256 / strip.numPixels()) + j) & 255);

				redVal = red(wheelVal) * float(fadeVal / fadeMax);
				greenVal = green(wheelVal) * float(fadeVal / fadeMax);
				blueVal = blue(wheelVal) * float(fadeVal / fadeMax);

				strip.setPixelColor(i, strip.Color(redVal, greenVal, blueVal));

			}

			//First loop, fade in!
			if (k == 0 && fadeVal < fadeMax - 1) {
				fadeVal++;
			}

			//Last loop, fade out!
			else if (k == rainbowLoops - 1 && j > 255 - fadeMax) {
				fadeVal--;
			}

			strip.show();
			delay(wait);
		}

	}



	delay(500);


	for (int k = 0; k < whiteLoops; k++) {

		for (int j = 0; j < 256; j++) {

			for (uint16_t i = 0; i < strip.numPixels(); i++) {
				strip.setPixelColor(i, strip.Color(0, 0, 0, gamma[j]));
			}
			strip.show();
		}

		delay(2000);
		for (int j = 255; j >= 0; j--) {

			for (uint16_t i = 0; i < strip.numPixels(); i++) {
				strip.setPixelColor(i, strip.Color(0, 0, 0, gamma[j]));
			}
			strip.show();
		}
	}

	delay(500);
}

void LightActionner::whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength)
{
	if (whiteLength >= strip.numPixels()) whiteLength = strip.numPixels() - 1;

	int head = whiteLength - 1;
	int tail = 0;

	int loops = 3;
	int loopNum = 0;

	static unsigned long lastTime = 0;


	while (true) {
		for (int j = 0; j<256; j++) {
			for (uint16_t i = 0; i<strip.numPixels(); i++) {
				if ((i >= tail && i <= head) || (tail > head && i >= tail) || (tail > head && i <= head)) {
					strip.setPixelColor(i, strip.Color(0, 0, 0, 255));
				}
				else {
					strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
				}

			}

			if (millis() - lastTime > whiteSpeed) {
				head++;
				tail++;
				if (head == strip.numPixels()) {
					loopNum++;
				}
				lastTime = millis();
			}

			if (loopNum == loops) return;

			head %= strip.numPixels();
			tail %= strip.numPixels();
			strip.show();
			delay(wait);
		}
	}
}

void LightActionner::fullWhite()
{
	for (uint16_t i = 0; i<strip.numPixels(); i++) {
		strip.setPixelColor(i, strip.Color(0, 0, 0, 255));
	}
	strip.show();
}

void LightActionner::rainbowCycle(uint8_t wait)
{
	uint16_t i, j;

	for (j = 0; j<256 * 5; j++) { // 5 cycles of all colors on wheel
		for (i = 0; i< strip.numPixels(); i++) {
			strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
		}
		strip.show();
		delay(wait);
	}
}

void LightActionner::rainbow(uint8_t wait)
{
	uint16_t i, j;

	for (j = 0; j<256; j++) {
		for (i = 0; i<this->strip.numPixels(); i++) {
			strip.setPixelColor(i, Wheel((i + j) & 255));
		}
		strip.show();
		delay(wait);
	}
}

uint32_t LightActionner::Wheel(byte WheelPos)
{
	WheelPos = 255 - WheelPos;
	if (WheelPos < 85) {
		return this->strip.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
	}
	if (WheelPos < 170) {
		WheelPos -= 85;
		return this->strip.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
	}
	WheelPos -= 170;
	return this->strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

uint8_t LightActionner::red(uint32_t c)
{
	return (c >> 8);
}

uint8_t LightActionner::green(uint32_t c)
{
	return (c >> 16);
}

uint8_t LightActionner::blue(uint32_t c)
{
	return (c);
}
