#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN_RFID 5
#define RST_PIN_RFID 17
// SCK RFID I SCK SD pin18
// MOSI RFID I MOSI SD pin23
// MISO RFID I MISO SD pin19 (amb resistència)

MFRC522 mfrc522(SS_PIN_RFID, RST_PIN_RFID); //Creamos el objeto para el RC522
void setup() 
{
    Serial.begin(115200); //Iniciamos la comunicación serial
    SPI.begin(); //Iniciamos el Bus SPI
    mfrc522.PCD_Init(); // Iniciamos el MFRC522
    Serial.println("Lectura del UID");
}
void loop() {
    // Revisamos si hay nuevas tarjetas presentes
    if ( mfrc522.PICC_IsNewCardPresent())
    {
        //Seleccionamos una tarjeta
        if ( mfrc522.PICC_ReadCardSerial())
        {
            // Enviamos serialemente su UID
            Serial.print("Card UID:");
            for (byte i = 0; i < mfrc522.uid.size; i++) 
            {
                Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                Serial.print(mfrc522.uid.uidByte[i], HEX);
            }
            Serial.println();
            // Terminamos la lectura de la tarjeta actual
            mfrc522.PICC_HaltA();
        }
    }
}

