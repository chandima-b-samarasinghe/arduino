/*  Ultrasonic Sensor
 *  Pins => [Vcc,Trigger,Echo,GND]
 *  Chandima B Samarasinghe
 */

#define ECHOPIN 6 //the pin which is used to get echo feedback
#define TRIGPIN 5 //the pin which is used to produce ultrasonic bursts

void setup() {
 Serial.begin(9600); //setting the serial connection
 pinMode(ECHOPIN, INPUT);
 pinMode(TRIGPIN, OUTPUT);
}

void loop() {
 //Start ranging- generating a trigger of 10us bursts
 // produced signal would looks like, _|-----|
 digitalWrite(TRIGPIN, LOW); delayMicroseconds(2); digitalWrite(TRIGPIN, HIGH); delayMicroseconds(10); digitalWrite(TRIGPIN, LOW);
 
 //distance calculation
 float distance=pulseIn(ECHOPIN,HIGH); //pulseIn() function return the time in microsecs (the time for reach the echo), and assigned it to distance variable
 distance=distance/58.8235; //using simple math, 2*DISTANCE=(speed_of_sound)*(time_in_miliseconds)*10^(-6)*10^2; ==> DISTANCE=(340*distance)/10000; ==> DISTANCE=distance/58.8235;
 Serial.print(distance); //print the distance in serial monitor
 Serial.println(" cm");
 delay(200); //delay 200mili seconds
}
