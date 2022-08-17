// demo: set_mask_filter_send
// this demo will show you how to use mask and filter
#include <SPI.h>
String incomingByte;
#define CAN_2515
// #define CAN_2518FD

// Set SPI CS Pin according to your hardware

#if defined(SEEED_WIO_TERMINAL) && defined(CAN_2518FD)
// For Wio Terminal w/ MCP2518FD RPi Hat：
// Channel 0 SPI_CS Pin: BCM 8
// Channel 1 SPI_CS Pin: BCM 7
// Interupt Pin: BCM25
const int SPI_CS_PIN  = BCM8;
const int CAN_INT_PIN = BCM25;
#else

// For Arduino MCP2515 Hat:
// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 10;
const int CAN_INT_PIN = 2;
#endif


#ifdef CAN_2518FD
#include "mcp2518fd_can.h"
mcp2518fd CAN(SPI_CS_PIN); // Set CS pin
#endif

#ifdef CAN_2515
#include "mcp2515_can.h"
mcp2515_can CAN(SPI_CS_PIN); // Set CS pin
#endif  
unsigned char len = 0;
unsigned char buf[8];


                         
unsigned char flagRecv = 0;
void setup() {
    Serial.begin(115200);
    while(!Serial){};
    while (CAN_OK != CAN.begin(CAN_250KBPS)) {             // init can bus : baudrate = 500k
        Serial.println("CAN init fail, retry...");
        delay(100);
    }
    Serial.println("CAN init ok!");
    //demarre_moteur();
    int inChar = Serial.read();
    attachInterrupt(digitalPinToInterrupt(CAN_INT_PIN), MCP2515_ISR, FALLING);

}

void MCP2515_ISR() {
  flagRecv = 1;
  CAN.readMsgBuf(&len, buf);   

}
    

void loop() {
      if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readString();
    //Serial.println(incomingByte);
    if (incomingByte.toInt() == 1){
    demarre_moteur();
    }
    else if (incomingByte.toInt() == 2){
      arret_moteur();
  
  }
  
     }
       
 if (flagRecv) {   
        flagRecv = 0;
           if (incomingByte.toInt() == 3){
       if (CAN.getCanId()== 0x3e1){
                  Serial.println("ID: 0x3E1");
                  Serial.print("Régime Moteur :  ");
                  Serial.print(regime_moteur(buf[0],buf[1]));
                  Serial.println(" Tr/min");
                  Serial.print("Vitesse : ");
                  Serial.print(vitesse(buf[2],buf[3]));
                  Serial.println(" Km/h");
                  Serial.print("Rapport de vitesse : ");
                  Serial.println(boitedevitesse(buf[4]));
                  Serial.print("Etat moteur : ");
                  Serial.println(etat_moteur(buf[5]));
                     
            }
        
  }
     else if (incomingByte.toInt() == 4){
               if (CAN.getCanId()== 0x3e3){
                  Serial.println("ID: 0x3E3");
                  Serial.print("Temp Eau : ");
                  Serial.print(tempeau(buf[1]));
                  Serial.println("°C");
                  Serial.print("Capteur de température D'eau : ");
                  Serial.println(capEau(buf[2]));
                  Serial.print("Capteur de température d’huile : ");
                  Serial.println(capHuile(buf[3]));
                  Serial.print("Capteur de température d’Air : ");
                  Serial.println(capAir(buf[4]));
                  
                 
               }
      }   
//        Serial.println("\r\n-------------------------------------------------");
//        if (CAN.getCanId()== 0x3e1){
//                  Serial.println("ID: 0x3E1");
//                  Serial.print("Régime Moteur :  ");
//                  Serial.print(regime_moteur(buf[0],buf[1]));
//                  Serial.println(" Tr/min");
//                  Serial.print("Vitesse : ");
//                  Serial.print(vitesse(buf[2],buf[3]));
//                  Serial.println(" Km/h");
//                  Serial.print("Rapport de vitesse : ");
//                  Serial.println(boitedevitesse(buf[4]));
//                  Serial.print("Etat moteur : ");
//                  Serial.println(etat_moteur(buf[5]));
//                     
//            }
//         if (CAN.getCanId()== 0x3e3){
//                  Serial.println("ID: 0x3E3");
//                  Serial.print("Temp Eau : ");
//                  Serial.print(tempeau(buf[1]));
//                  Serial.println("°C");
//                  Serial.print("Capteur de température D'eau : ");
//                  Serial.println(capEau(buf[2]));
//                  Serial.print("Capteur de température d’huile : ");
//                  Serial.println(capHuile(buf[3]));
//                  Serial.print("Capteur de température d’Air : ");
//                  Serial.println(capAir(buf[4]));
//                  
//                 
//                }
//                   Serial.println("\r\n");
  }                       

                                                                                          


}  


void demarre_moteur(){
  unsigned char stmp[8] = {0x01};
  CAN.sendMsgBuf(0x101, 0, sizeof(stmp), stmp);
  Serial.println("Démarrage du Moteur\n");
 
  }
void arret_moteur(){
  unsigned char stmp[8] = {0x03};
  CAN.sendMsgBuf(0x101, 0, sizeof(stmp), stmp);
  Serial.println("Arret moteur\n");
 
  }

 unsigned int regime_moteur(unsigned int buf_0,unsigned int buf_1)
 {
  unsigned int reg = ((buf_1 + (buf_0<<8))/10);
  
  return reg;
  } 

unsigned int vitesse(unsigned int buf_2,unsigned int buf_3)
 {
  unsigned int vitesse = (buf_3 + (buf_2<<8))/100;
  return vitesse;
  } 
 String boitedevitesse(unsigned char buf_4){
   String boitedevitesse ;
   buf_4= (buf_4&0xf0) ;
   String x = String(buf_4,HEX);
   if (String(buf_4,HEX)== "10"){
        boitedevitesse = "R";
        Serial.println("R");
        }
   else if(String(buf_4,HEX)== "20"){
        boitedevitesse = "Point Mort";
        }
   else if(String(buf_4,HEX)== "30"){
        boitedevitesse = "Vitesse 5";
        }
   else if(String(buf_4,HEX)== "40"){
        boitedevitesse = "Vitesse 4";
        }
   else if(String(buf_4,HEX)== "50"){
        boitedevitesse = "Vitesse 3";
        }
   else if(String(buf_4,HEX)== "60"){
        boitedevitesse = "Vitesse 2";
        }
   else if(String(buf_4,HEX)== "70"){
        boitedevitesse = "Vitesse 1";
        }                  
    return boitedevitesse;
  } 


 String etat_moteur(unsigned char buf_5)
 {
  String Etat ;
  //Serial.println(buf_5,HEX);
   
  if (buf_5== 00){
        Etat = "Moteur Arrêté";
        }
  else if(buf_5== 01){
        Etat = "Moteur Allumé";
        }
  return Etat;
   }
String tempeau(unsigned char buf_1){
    buf_1 = buf_1 & 0xff;
    String tempeau = String(buf_1, DEC);
    return tempeau ;
  }
String capEau(unsigned char buf_2){
    String capEau;
    if (buf_2== 0){
          capEau = "Capteur Présent";
        }
    else if (buf_2 == 255){
          capEau = "Capteur Absent";
      }
    return capEau ;
  }
  String capHuile(unsigned char buf_3){
    String capHuile;
    if (buf_3== 0){
          capHuile = "Capteur Présent";
        }
    else if (buf_3 == 255){
          capHuile = "Capteur Absent";
      }
    return capHuile ;
  }
  String capAir(unsigned char buf_4){
    String capAir;
    if (buf_4== 0){
          capAir = "Capteur Présent";
        }
    else if (buf_4 == 255){
          capAir = "Capteur Absent";
      }
    return capAir ;
  }


/*********************************************************************************************************
    END FILE
*********************************************************************************************************/
