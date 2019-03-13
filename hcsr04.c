/*
    Amr Wa
    03/12/2019
    https://wantronics.blogspot.com/
*/

#define trig 4 //use this to define the trig pin #
#define echo 3 // use this to define the echo pin #

double timingUS = 0; // this will store time we obtain from the sensor signal in microseconds
double distance =0; // this will store the calculated distance between our sensor and an object


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(trig, OUTPUT); // this defined nature of the pin.
    pinMode(echo, INPUT); // this defined nature of the pin as input pin.
}


void loop() {
    digitalWrite(trig,LOW); //we initialize the trig pin
    delayMicroseconds(2); // hold trig low for 2ms
    digitalWrite(trig,HIGH); // this will initialization the triggering process
    delayMicroseconds(10); // this keep the signal high for 10us
    digitalWrite(trig,LOW); //this will shutdown the trigger process
    timingUS= pulseIn(echo, HIGH); // obtain the time from Echo in microseconds
    distance = (timingUS/2)*(0.034); // 0.034 is the speed of sound in cm microseconds. This will measure the objects distance from the Ultrasonic sensor to the object The echo
    Serial.println(distance); //display the distance on the serial terminal, we needed to know this to verify whethere the measurments were correct or not
    delay(1000); // to delay the display by milliseconds
}
