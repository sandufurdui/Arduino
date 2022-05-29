#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>



//#define WIFI_SSID "Laritex"
//#define WIFI_PASSWORD "067332309"
//#define FIREBASE_HOST "https://esp1-88d49-default-rtdb.europe-west1.firebasedatabase.app/"
//#define FIREBASE_AUTH "wjhl6JIZlXMqONEsKdqp3bI2rjoFI0zPPkPbR1TS"

#include <ESP8266WiFi.h>
//#include <idk.h>
//#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "https://esp-test-e5fbd-default-rtdb.europe-west1.firebasedatabase.app/"
#define FIREBASE_AUTH "w9aXyDVfPz0ayEDkj5ehMZn1Ipx4dOYPdMRgTKab"
#define WIFI_SSID "Laritex"
#define WIFI_PASSWORD "067332309"

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
  // set value
  Firebase.setFloat("number", 42.0);
  // handle error
//  if (Firebase.failed()) {
//      Serial.print("setting /number failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  delay(1000);
  
  // update value
  Firebase.setFloat("number", 43.0);
  // handle error
//  if (Firebase.failed()) {
//      Serial.print("setting /number failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  delay(1000);

  // get value 
//  Serial.print("number: ");
//  Serial.println(Firebase.getFloat("number"));
  delay(1000);

  // remove value
//  Firebase.remove("number");
//  delay(1000);

  // set string value
  Firebase.setString("message", "hello world");
  // handle error
//  if (Firebase.failed()) {
//      Serial.print("setting /message failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  delay(1000);
  
  // set bool value
//  Firebase.setBool("truth", false);
  // handle error
//  if (Firebase.failed()) {
//      Serial.print("setting /truth failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  delay(1000);

  // append a new value to /logs
//  String name = Firebase.pushInt("logs", n++);
  // handle error
//  if (Firebase.failed()) {
//      Serial.print("pushing /logs failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
  Serial.print("pushed: /logs/");
//  Serial.println(name);
//  delay(1000);
}