// Program showing battery voltage and percentage in the serial console.

#define led_pin 7 //Defining the pin to control the LED.

float batteryPercent = 0; //Creating a float for the battery percentage.

void setup(){
  pinMode(led_pin, OUTPUT); //Setting pinMode for the LED.
  Serial.begin(9600); //Beginning serial transmission.
  Serial.println("Ready !");
}

void loop(){
     digitalWrite(led_pin, LOW); //Turning the LED off.
    int valeur = analogRead(A0); //Reading A0 pin where the battery is connected.
    float voltage = (valeur * (5.00/1023.00) * 2)-4.42; //Voltage conversion, we need to multiply it by 2 to get the true voltage
	//because of the use of 2 resistors.
    Serial.println(voltage); //Printing out the voltage
    Serial.print("% de batterie : ");
	//Turning the voltage into a percentage
    voltage = voltage *100;
    batteryPercent = voltage /9;
    Serial.println(batteryPercent); //Print in the console the battery percentage
    Serial.println("");
	//If statement to define a blinking led if the battery goes below a defined voltage.
    if(voltage < 4.5){
         digitalWrite(led_pin, HIGH);
         delay(500);
         digitalWrite(led_pin, LOW);
         delay(500);
    }
    delay(100); //Code sleeping for 100ms, allowing for not that fast processing.
}