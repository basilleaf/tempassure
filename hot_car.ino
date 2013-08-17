char inByte = '0';         // incoming serial byte
const int ledPin =  12;      // the number of the LED pin

void setup()
{
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);      

  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
}

void loop()
{
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    Serial.print(inByte);
    
    if (inByte == '1') {
        digitalWrite(ledPin, HIGH); 
    }
    else {
        digitalWrite(ledPin, LOW); 
    }    
  }
}
