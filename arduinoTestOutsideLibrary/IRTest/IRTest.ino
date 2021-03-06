int irLeftAnalog = 0;
int irRightAnalog = 2;

const int arraySize = 10;

const int valeur5Left = 440; //valeur
const int valeur10Left = 270; //valeur
const int valeur15Left = 170; //valeur
const int valeur20Left = 135; //valeur
const int valeur30Left = 107;//valeur
const int valeur40Left = 75;//valeur
const int valeur50Left = 55;//valeur
const int valeur60Left = 40;//valeur
const int valeur70Left = 30;//valeur
const int valeur80Left = 25;//valeur

const float ratioLeft = 16;

const int tableauValeurLeft[arraySize] = { valeur5Left, valeur10Left, valeur15Left, valeur20Left, valeur30Left, valeur40Left, valeur50Left, valeur60Left, valeur70Left, valeur80Left };

const int valeur5Right = 650; //valeur
const int valeur10Right = 520; //valeur
const int valeur15Right = 380; //valeur
const int valeur20Right = 280; //valeur
const int valeur30Right = 200;//valeur
const int valeur40Right = 150;//valeur
const int valeur50Right = 120;//valeur
const int valeur60Right = 100;//valeur
const int valeur70Right = 70;//valeur
const int valeur80Right = 50;//valeur

const float ratioRight = 30;

const int tableauValeurRight[arraySize] = { valeur5Right, valeur10Right, valeur15Right, valeur20Right, valeur30Right, valeur40Right, valeur50Right, valeur60Right, valeur70Right, valeur80Right };

void setup() {
 pinMode(irLeftAnalog, INPUT);
 Serial.begin(9600);
}

void loop() {
  /*Serial.print("distance value sensor left = ");
  Serial.println(getValueLeft(irLeftAnalog));*/

  Serial.print("distance precision value sensor left = ");
  Serial.println(getPrecisionValue(irLeftAnalog, ratioLeft));
  delay(1000);


  /*Serial.print("distance value sensor right = ");
  Serial.println(getValueRight(irRightAnalog));*/

  Serial.print("distance precision value sensor right = ");
  Serial.println(getPrecisionValue(irRightAnalog, ratioRight));
  delay(1000);

  /*Serial.println("right");
  Serial.println(analogRead(irRightAnalog));
  delay(1000);*/

  /*Serial.println("left");
  Serial.println(analogRead(irLeftAnalog));*/
  delay(1000);
}

int getValueRight(int analogPin) {
  int compteur = 0, valeurPlusProcheCentimetre = 100, valeurPlusProcheZero = 1025;
  int valeurCompare[arraySize] = {};
  int analogValue = analogRead(analogPin);
  for (compteur = 0; compteur < arraySize; compteur++)
  {
    valeurCompare[compteur] = abs(analogValue - tableauValeurRight[compteur]);
    if (valeurCompare[compteur] < valeurPlusProcheZero)
    {
      valeurPlusProcheZero = valeurCompare[compteur];
      if(compteur < 4){
        valeurPlusProcheCentimetre = compteur * 5 + 5;
      }
      else{
        valeurPlusProcheCentimetre = (compteur-2) * 10 + 10;
      }
    }
  }
  //Serial.println(valeurPlusProcheCentimetre);

  return valeurPlusProcheCentimetre;
}

int getValueLeft(int analogPin) {
  int compteur = 0, valeurPlusProcheCentimetre = 100, valeurPlusProcheZero = 1025;
  int valeurCompare[arraySize] = {};
  int analogValue = analogRead(analogPin);
  for (compteur = 0; compteur < arraySize; compteur++)
  {
    valeurCompare[compteur] = abs(analogValue - tableauValeurLeft[compteur]);
    if (valeurCompare[compteur] < valeurPlusProcheZero)
    {
      valeurPlusProcheZero = valeurCompare[compteur];
      if(compteur < 4){
        valeurPlusProcheCentimetre = compteur * 5 + 5;
      }
      else{
        valeurPlusProcheCentimetre = (compteur-2) * 10 + 10;
      }
    }
  }
  //Serial.println(valeurPlusProcheCentimetre);

  return valeurPlusProcheCentimetre;
}

long getPrecisionValue(int analogPin, float ratio) {
  float distance = 0, volt = 0;
  int analogValue = analogRead(analogPin);
  volt = analogValue*0.0048828125;
  distance = 1 / (volt / ratio);
  //distance = 1 / (volt / 16);
  /*Serial.println(F("valeur recu par le capteur = "));
  Serial.println(analogValue);
  Serial.println(F("valeur en volt = "));
  Serial.println(volt);
  Serial.println(F("distance = "));
  Serial.println(distance);*/

  return distance;
}
