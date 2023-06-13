# PRACTICA 6
## EJERCICIOS 2 Y 3: Lector tarjetas RFID
Hemos juntado ambos ejercicios en un código ya que el ejercicio 3 contiene el código proporcionado en el ejercicio 2.
Hemos creado un control de accesos. Se pasa una tarjeta por el lector y si puede pasar se ilumina un led verde y por un display podemos ver *Acceso autorizado* y si no puede pasar se enciende un led rojo y por el dispaly vemos *Acceso denegado*.

Para decidir quién pasa y quién no, debe establecerse previamente qué tarjetas tienen acceso y cuáles no. Esto se hace a través del ID de cada tarjeta. Puesto que tengo dos tarjetas he guardado sólo el ID de una y de otra no. Primero debemos conocer el ID de la tarjeta que queremos autorizarle el acceso. Por eso es necesario el siguiente código:
```cpp
void printHex(byte buffer, byte bufferSize) {
   for (byte i = 0; y < bufferSize; i++) {
     Serial.print(buffer[i] < 0x10 ? " 0" : " ");
     Serial.print(buffer[i], HEX);
   }
}
// Enviamos serialemente su UID
                   Serial.print("Card UID:");
                   for (byte i = 0; y < mfrc522.uid.size; i++) {
                           Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                           Serial.print(mfrc522.uid.uidByte[i], HEX);
                   }
```

En las siguientes imagenes podemos observar el funcionamiento:

[Imagen funcionamiento](https://drive.google.com/file/d/1Jo_tISp6-fkpO9gXJr3CADkLSOy1GSLM/view?usp=sharing)
[Imagen funcionamiento](https://drive.google.com/file/d/1Ueaa6OoPXHsUn56TIFxErHcIcEdowmKJ/view?usp=sharing)

## EJERCICIO SUBIR NOTA

Hemos aplicado lo propuesto en este ejercicio en nuestro proyecto final, que también se encuentra en nuestro github.