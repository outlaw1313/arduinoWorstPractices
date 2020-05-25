const int analogSignal = A0; //подключение аналогового сигнального пина
const int digitalSignal = 11; //подключение цифрового сигнального пина
const int redLed = 2;
const int greenLed = 3;
boolean noGas; //переменная для хранения значения о присутствии газа
int gasValue = 0; //переменная для хранения количества газа

const int TRIG_PIN = 12;
const int ECHO_PIN = 13;

const int buttonPin = 9;     // the number of the pushbutton pin
const int ledPin =  10;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status



void setup() {
  pinMode(digitalSignal, INPUT); //установка режима пина

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); //инициализация Serial порта
}


void loop() {
  noGas = digitalRead(digitalSignal); //считываем значение о присутствии газа
  gasValue = analogRead(analogSignal); // и о его количестве

  //вывод сообщения
  Serial.print("There is ");
  if (noGas) Serial.print("no gas");
  else Serial.print("gas");
  Serial.print(", the gas value is ");
  Serial.println(gasValue);
  if (gasValue > 30) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  }

  long duration, distanceCm, distanceIn;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);

  // convert the time into a distance
  distanceCm = duration / 29.1 / 2 ;
  distanceIn = duration / 74 / 2;

  if (distanceCm <= 0)
  {
    Serial.println("Out of range");
  }
  else
  {
    Serial.print(distanceCm);
    Serial.print("cm");
    Serial.println();
  }

  if (distanceCm >= 40) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  } else if (distanceCm >= 30 && distanceCm < 40) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  } else if (distanceCm >= 20 && distanceCm < 30) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  } else if (distanceCm >= 10 && distanceCm < 20) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  } else if (distanceCm >= 1 && distanceCm < 10) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }

  buttonState = digitalRead(buttonPin);
  // Show the state of pushbutton on serial monitor
  Serial.println(buttonState);
  // 1
  // 2



  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  delay(300); //задержка 1 с
}
