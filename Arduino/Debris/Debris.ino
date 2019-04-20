



/*
 * Incluir librerias para sensores de peso, pantalla LCD y Scheduler
 */
#include <HX711.h>
#include <LiquidCrystal.h>
#include <SimpleTimer.h>
/*
  Variables globales
*/
//LCD
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//Sensores de peso
const int CALIBRATION_FACTOR = 27400;
const int DOUT[] = {6, 5, 3};
const int CLK[] = {7, 4, 2};
HX711 S_PESO_ORG;
HX711 S_PESO_PET;
HX711 S_PESO_VID;

//Generales
SimpleTimer timer;
const int MESSAGE_TIME = 3000;
float pesoOrg = 0;
float pesoPet = 0;
float pesoVid = 0;
int cantOrg = 0;
int cantPet = 0;
int cantVid = 0; 

/*
 * Método setup.
 */
void setup() {
  //Iniciar Serial
  Serial.begin(9600);
  //Iniciar y Calibrar sensores de peso
  S_PESO_ORG.begin(DOUT[0], CLK[0]);
  S_PESO_PET.begin(DOUT[1], CLK[1]);
  S_PESO_VID.begin(DOUT[2], CLK[2]);
  S_PESO_ORG.set_scale(CALIBRATION_FACTOR);
  S_PESO_PET.set_scale(CALIBRATION_FACTOR);
  S_PESO_VID.set_scale(CALIBRATION_FACTOR);
  S_PESO_ORG.tare();
  S_PESO_PET.tare();
  S_PESO_VID.tare();
  //Iniciar LCD
  lcd.begin(16, 2);
  //Iniciar timer
  timer.setInterval(2000, sendDataToSerial); //Envía los datos cada hora 3600000
}

/*
 * Método loop.
 * Se repite infinitamente mientras esté encendido el Arduino.
 */
void loop() {
  timer.run();
  mainMessage(MESSAGE_TIME);
  displayDebrisStatus(MESSAGE_TIME, "ORGANICA", S_PESO_ORG, false);
  displayDebrisStatus(MESSAGE_TIME, "PET", S_PESO_PET, false);
  displayDebrisStatus(MESSAGE_TIME, "VIDRIO", S_PESO_VID, false);
  messageCode(MESSAGE_TIME, "debris.com", "1038473894829103");
  lcd.setCursor(0,0);
}

void mainMessage(int message_time){
  lcd.setCursor(0, 0);
  lcd.print("DEBRIS BASURERO");
  lcd.setCursor(0, 1);
  lcd.print("INTELIGENTE");
  delay(message_time);
  lcd.clear();

}

void displayDebrisStatus(int message_time, String debrisType, HX711 sensor, boolean buttonOpened){
  lcd.setCursor(0, 0);
  float quant = abs(sensor.get_units());
  quant *= 0.453592; //El sensor mide en libras, por lo cual se convierte a kg.
  if(quant > 7){
    lcd.print("VACIE PRONTO");
    lcd.setCursor(0, 1);
    lcd.print(debrisType + ":");
    lcd.print(quant);
    lcd.print("KG.");
  }
  else{
    lcd.print(debrisType);
    lcd.print(": "); 
    lcd.setCursor(0, 1);
    lcd.print(quant);
    lcd.print("KG.");
  }
  if(debrisType.equals("ORGANICA") && buttonOpened){
    pesoOrg = quant;
    cantOrg++;
  }
  if(debrisType.equals("PET") && buttonOpened){
    pesoPet = quant;
    cantPet++;
  }
  if(debrisType.equals("VIDRIO") && buttonOpened){
    pesoVid = quant;
    cantVid++;
  }
  delay(message_time);
  lcd.clear();

}

void messageCode(int message_time, String webpage, String code){
  lcd.setCursor(0, 0);
  lcd.print(webpage);
  lcd.setCursor(0, 1);
  lcd.print(code);
  delay(message_time);
  lcd.clear();
}

void sendDataToSerial(){
  Serial.print("#");
  Serial.print(pesoOrg);
  Serial.print(",");
  Serial.print(pesoPet);
  Serial.print(",");
  Serial.print(pesoVid);
  Serial.print(",");
  Serial.print(cantOrg);
  Serial.print(",");
  Serial.print(cantPet);
  Serial.print(",");
  Serial.print(cantVid);
  Serial.print("#");
  Serial.println();
}
