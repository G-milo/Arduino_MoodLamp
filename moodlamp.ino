// Constants for LDR sensor pin and thresholds
const int ldrPin = 2;
int brightThreshold = 200;  // Will be dynamically adjusted based on real-world brightness
const int darkThreshold = 0;   // Adjust this value for dark conditions

// Constants for temperature sensor pin and thresholds
const int lm35Pin = A1; // Analog input pin connected to the LM35 sensor
const int LDRPin = A0;
int hotThreshold = 50;  // Will be dynamically adjusted based on real-world temperature
const int coldThreshold = 20; // Temperature threshold for cold (in Celsius)

// Constants for RGB module pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

float voltage;   // Variable to store the voltage reading
float celcius,celcius1;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(LDRPin, INPUT);

  // Set pin modes for RGB module
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read the LDR sensor value
  int ldrValue = analogRead(ldrPin);
  int ldrValue2 = analogRead(LDRPin);

  // Read the LM35 sensor value
   // get the temperature and convert it to celsius
int temp = analogRead(lm35Pin);
int temp2 = temp * 0.48828125;
int temp3 = temp2 / 100 ;
// Convert ADC reading to voltage (assuming 5V reference)
  
// Print the sensor values to Serial Monitor
Serial.println("");
Serial.print("LDR Value: ");
Serial.println(ldrValue2);
Serial.print("celcius: ");
Serial.print(temp);
Serial.println(" C");

if(ldrValue2<400 && temp<70){
  setColor(150,100,0);
  //Hayag ug Bugnaw
  //Yellow
}
else if(ldrValue2<400 && temp>70){
  setColor(255,0,0);
  //Hayag ug Init
  //Puwa
}
else if(ldrValue2>900 && temp<70){
  setColor(0,0,255);
 //Ngitngit ug Bugnaw
 //BLUE
}
else if(ldrValue2>900 && temp>60){
  setColor(100,0,125);
  //Ngitngit ug Init
  //BAYULET
}
else{
  setColor(100,100,100);
  //default
  //Puti
}

delay(1000);
}

// Function to set the RGB module color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
