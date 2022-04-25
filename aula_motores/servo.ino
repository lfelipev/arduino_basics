#include <Servo.h> 
Servo Servo1; 
int Recebido; 
int posicao; 

void setup(){
    Servo1.attach(3);
    Serial.begin(9600); 
}

void loop(){
    if (Serial.available() > 0) { 
        Recebido = Serial.read(); 
        if (Recebido == '+'){ 
            posicao = posicao + 10; 
            Serial.println(posicao); 
        }
    
        if (Recebido == '-'){
            posicao = posicao - 10;
            Serial.println(posicao); 
        }
        Servo1.write(posicao); 
    }
}