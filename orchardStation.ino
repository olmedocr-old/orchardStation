/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG        // Optional, this enables more detailed prints
#define TINY_GSM_MODEM_SIM800

// Default heartbeat interval for GSM is 60
// If you want override this value, uncomment and set this option:
//#define BLYNK_HEARTBEAT 30

#include <TinyGsmClient.h>
#include <BlynkSimpleSIM800.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "76cbb4b6dea54a68927dbe179bb79a88";

// Your GPRS credentials
// Leave empty, if missing user or pass
char apn[]  = "internetmas";
char user[] = "";
char pass[] = "";

// Hardware Serial on Mega, Leonardo, Micro
//#define SerialAT Serial1

// or Software Serial on Uno, Nano
#include <SoftwareSerial.h>
SoftwareSerial SerialAT(2, 3); // RX, TX

TinyGsm modem(SerialAT);

void setup()
{
  // Debug console
  Serial.begin(9600);
  delay(10);

  // Set GSM module baud rate
  SerialAT.begin(9600);
  delay(3000);

  // Restart takes quite some time
  Serial.println("Initializing modem...");
  modem.restart();

  Blynk.config(modem, auth);

  Blynk.connectNetwork(apn, user, pass);

  Blynk.connect();  

  // TODO: add error handling

  modem.callNumber("+34660083731");
  modem.sendSMS("+34687608127", "Hola, soy MR Olmedo haciendo magia una vez mas. Un saludo desde mi Arduino NANO");
  modem.sendSMS("+34678274152", "Hola, soy MR Olmedo haciendo magia una vez mas. Un saludo desde mi Arduino NANO");
  modem.sendSMS("+34628761525", "Hola, soy MR Olmedo haciendo magia una vez mas. Un saludo desde mi Arduino NANO");

}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function! 
  Serial.println(Blynk.connected());
}
