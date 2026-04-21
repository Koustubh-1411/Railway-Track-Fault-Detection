#include <TinyGPS++.h>
#include <HardwareSerial.h>

// Pins
#define TRIG 5
#define ECHO 18
#define VIB 4
#define BUZZER 23

HardwareSerial gpsSerial(2);   // RX2=16, TX2=17
HardwareSerial gsmSerial(1);   // RX=26, TX=27

TinyGPSPlus gps;

long duration;
float distance_mm;
int vibration;

String latitude = "0";
String longitude = "0";

bool smsSent = false; // prevent repeat

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(VIB, INPUT);
  pinMode(BUZZER, OUTPUT);

  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
  gsmSerial.begin(9600, SERIAL_8N1, 26, 27);

  delay(3000);

  Serial.println("Initializing GSM...");
  initGSM();
}

void loop() {

  // 🔹 Ultrasonic
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH, 30000);
  distance_mm = (duration * 0.034 / 2) * 10;

  //  Vibration
  vibration = digitalRead(VIB);

  //  GPS
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isValid()) {
    latitude = String(gps.location.lat(), 6);
    longitude = String(gps.location.lng(), 6);
  }

  //  Serial Output
  Serial.print("Distance: ");
  Serial.print(distance_mm);
  Serial.print(" mm | Vib: ");
  Serial.print(vibration);
  Serial.print(" | Lat: ");
  Serial.print(latitude);
  Serial.print(" | Lon: ");
  Serial.println(longitude);

  //  Condition
  if (distance_mm < 200 && vibration == HIGH && !smsSent) {
    Serial.println("ALERT TRIGGERED");

    digitalWrite(BUZZER, HIGH);

    sendSMS();

    smsSent = true;  // send only once
  }

  if (distance_mm > 300) {
    smsSent = false; // reset condition
    digitalWrite(BUZZER, LOW);
  }

  //  GSM Debug Output
  while (gsmSerial.available()) {
    Serial.write(gsmSerial.read());
  }

  delay(500);
}

//  GSM INIT FUNCTION
void initGSM() {
  sendCommand("AT", 1000);
  sendCommand("AT+CMGF=1", 1000);   // Text mode
  sendCommand("AT+CSCS=\"GSM\"", 1000);
  sendCommand("AT+CNMI=1,2,0,0,0", 1000);
}

//  SEND SMS FUNCTION
void sendSMS() {
  Serial.println("Sending SMS...");

  gsmSerial.println("AT+CMGF=1");
  delay(1000);

  gsmSerial.println("AT+CMGS=\"+917209144342\""); //  PUT YOUR NUMBER
  delay(2000);

  String msg = "ALERT!\n";
  msg += "Distance: " + String(distance_mm) + " mm\n";
  msg += "Location:\n";
  msg += "https://maps.google.com/?q=" + latitude + "," + longitude;

  gsmSerial.print(msg);
  delay(500);

  gsmSerial.write(26); // CTRL+Z
  delay(5000);

  Serial.println("SMS SENT COMMAND");
}

// 🔹 COMMAND FUNCTION
void sendCommand(String cmd, int delayTime) {
  gsmSerial.println(cmd);
  delay(delayTime);

  while (gsmSerial.available()) {
    Serial.write(gsmSerial.read());
  }
}