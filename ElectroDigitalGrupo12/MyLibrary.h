#include <Ultrasonic.h>
#define TRIG 12
#define ECHO 11
Ultrasonic ultra(TRIG, ECHO);


class Info {
private:
  int Gled, Rled, TempSensor, Humidity, BuzzPin;
  float cm;
public:
  void Mode(int Gled, int Rled, int BuzzPin, int trigPin, int echoPin) { 
    Serial.begin(9600);
    pinMode(Gled, OUTPUT);     //Green Led
    pinMode(Rled, OUTPUT);     //Red Led
    pinMode(BuzzPin, OUTPUT);  //Buzzer
    pinMode(trigPin, OUTPUT);  //Ultrasonic Trig
    pinMode(echoPin, INPUT);   //Ultrasonic Echo
    digitalWrite(Rled, LOW);   //Red Off
    digitalWrite(Gled, LOW);   //Green OFF
    pinMode(9,OUTPUT);
    pinMode(BuzzPin, OUTPUT);
  }

  int SensorHumedad() {  
    delay(1000);
    Humidity = analogRead(A0);
    Serial.println("Humedad " + String(Humidity));
    return Humidity;
  }

  void LEDS(int Gled, int Rled) {  
    int read = SensorHumedad();
    if (read >= 850) {
      digitalWrite(Rled, HIGH);
      digitalWrite(Gled, LOW);
    } else if (read < 850) {
      digitalWrite(Rled, LOW);
      digitalWrite(Gled, HIGH);
    }
  }

  void bomba() {  
    int read = SensorHumedad();
    float cmU = NivelDeAgua(4);
    if (cmU >= 12) {
    } else {
      if (read >= 850) {
        digitalWrite(9, HIGH);
        digitalWrite(4, HIGH);

      } else if (read < 850) {
        digitalWrite(9, LOW);
        digitalWrite(4, LOW);
      }
    }
  }

  float NivelDeAgua(int BuzzPin) {
    cm = ultra.read(CM);
    if (cm >= 12) {
      digitalWrite(BuzzPin, HIGH);
      delay(200);
      digitalWrite(BuzzPin, LOW);
    }
    Serial.println("CM: " + String(cm));
    return cm;
  }
};