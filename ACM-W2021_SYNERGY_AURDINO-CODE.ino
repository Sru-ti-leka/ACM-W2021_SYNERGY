int inByte;
void setup()
{ 
  pinMode(A0,OUTPUT);
  pinMode(2,OUTPUT);
   pinMode(8,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A2,INPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}
int sensorValue ;
int tempsensorValue;
int tempmin;
int tempmax;
int i=0;
int nmin;
int nmax;
int kmin;
int kmax;
int pmax;
int pmin;
int psensorValue;
int ksensorValue;
int nnsensorValue;
int getcrop()
{
  Serial.println("=================================");
Serial.println("Temperature and Humidity Monitoring");
Serial.println("Type of crop\n1.Rice\n2.Wheat\n3.Tomato\n4.Sugarcane\n5.Ragi");  
  while (Serial.available() == 0){
  }int inByte = Serial.parseInt();
  return inByte;
 i=0;}
void getdata()
{
   Serial.print("Temprature:");
  Serial.println(tempsensorValue);
Serial.print("Light sensor: ");
  Serial.println(sensorValue);
  Serial.print("Nitrogen level:");
  Serial.println(nnsensorValue);
Serial.print("Potassium level:");
  Serial.println(nnsensorValue);
Serial.print("Phosphorous level:");
  Serial.println(nnsensorValue);
  i=0;
}
int celsius()
{ return map(((analogRead(A4) - 20) * 3.04), 0, 1023, 23 , 125); 
}
void loop()
{int j;
  if(i==1)
    j=getcrop();
   else if (i == 2)
     getdata();
 i=Serial.parseInt();
 if( j == 1){
tempmin =25; 
tempmax =35;
nmin=15;
nmax=20;
kmax=20;
kmin=15;
pmin=20;
pmax=30;
}
else if ( j == 2)
{
tempmin = 20;
tempmax = 25;
nmin=100;
nmax = 100;
kmin=60;
kmax=64;
}
else if( j == 3){
tempmin =21; 
tempmax =24;
nmax=200;
nmin=200;
kmin=250;
kmax=252;
}
else if( j == 4){
tempmin =27;
tempmax =27;
nmax=150;
nmin=150;
kmin=80;
kmax=83;
}
else if( j == 5){
tempmin =25;
tempmax =30;
nmin=60;
nmax=60;
kmin=30;
kmax=33;
}
tempsensorValue = celsius();    
  if (tempsensorValue < tempmin){
  digitalWrite(3,HIGH);
  }
  else if (tempsensorValue > tempmax){
    digitalWrite(3,LOW);}
    sensorValue = analogRead(A0);    
    if(sensorValue > 30){ 
  digitalWrite(2,LOW); }
else {
digitalWrite(2,HIGH);
 }
 nnsensorValue = analogRead(A2);    
 if(nnsensorValue >nmax ){
 digitalWrite(8,LOW);}
  else if(nnsensorValue<nmin){
   digitalWrite(8,HIGH);  
}
 ksensorValue = analogRead(A3);    
  if(ksensorValue >kmax ){
 digitalWrite(4,LOW);
   }
  else if(ksensorValue<kmin){
digitalWrite(4,HIGH); }
  psensorValue = analogRead(A1);    
if(psensorValue >pmax ){
 digitalWrite(7,LOW);
   } else if(psensorValue<pmin){
    digitalWrite(7,HIGH);
  } }
