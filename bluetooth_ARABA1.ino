#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX
char data;

#define MotorR1 7
#define MotorR2 8
#define MotorRE 6
#define MotorL1 4
#define MotorL2 3
#define MotorLE 5 


void setup(){
 pinMode(MotorL1, OUTPUT);
 pinMode(MotorL2, OUTPUT);
 pinMode(MotorLE, OUTPUT);
 pinMode(MotorR1, OUTPUT);
 pinMode(MotorR2, OUTPUT);
 pinMode(MotorRE, OUTPUT);

 Serial.begin(9600);
mySerial.begin(9600);
 
}

void ileri(){  

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 150); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 150); 
  

}

void geri(){  
  
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRE, 150); 
  
  digitalWrite(MotorL1, 0); 
  digitalWrite(MotorL2, 1); 
  analogWrite(MotorLE, 150); 


  
}

void sag(){ 
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRE, 150); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE,150); 


  
  
}

void sol(){ 
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 150); 

  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLE, 150); 

}

void dur(){ 

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, LOW);
  

}

void loop() {
  if(mySerial.available()> 0){
  data = mySerial.read();
  Serial.println(data);

}
if(data == 'F'){            
 ileri();
}
 
else if(data == 'B'){      
  geri();
}
 
else if(data == 'L'){      
  sol();
}
 
else if(data == 'R'){     
 sag();
}
 
else if(data == 'S'){      
dur();
}
}
