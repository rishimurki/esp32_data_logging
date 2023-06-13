// Libraries for DHT 11 sensor
#include <DHT.h>
#include <DHT_U.h>

// Libraries for date and time(ntp client and wifi)
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <time.h>

// Libraries for SD card
#include "FS.h"
#include "SD.h"
#include <SPI.h>

// Libraries for LCD 
#include <LiquidCrystal_I2C.h>
// setting up lcd address , number of rows and columns
LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset = 19800; // GMT offset in seconds (5:30 hours)

#define DHTPIN 33
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer, gmtOffset);


// Define CS pin for the SD card module
#define SD_CS 5
// Save reading number on RTC memory
RTC_DATA_ATTR int readingID = 0;

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("connecting to");
  lcd.setCursor(0, 1);
  lcd.print("chenab....");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi connected");
  delay(1500);
  // initializing NTP client
  timeClient.begin();
  // intializing DHT sensor
  dht.begin();


  // Initialize SD card
  SD.begin(SD_CS);  
  if(!SD.begin(SD_CS)) {
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE) {
    Serial.println("No SD card attached");
    return;
  }
  Serial.println("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("ERROR - SD card initialization failed!");
    return;    // init failed
  }
  lcd.clear();
  // If the data.txt file doesn't exist
  // Create a file on the SD card and write the data labels
  File file = SD.open("/data.txt");
  if(!file) {
    Serial.println("File doens't exist");
    Serial.println("Creating file...");
    writeFile(SD, "/data.txt", "Reading ID, Date, Temperature \r\n");
  }
  else {
    Serial.println("File already exists");  
  }
  file.close();
}


// funtion to get time stamp
String getCurrentTime() {
  timeClient.update();
  // Local time strores the epoch time( time in seconds from 1990)
  time_t localTime = timeClient.getEpochTime();
  struct tm* timeInfo = localtime(&localTime);

  // creating a variable timestr that stores the date and time
  char timeStr[20];
  // sprintf(timeStr, "%02d:%02d:%02d", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec, timeInfo->tm_wday);
  sprintf(timeStr, "%02d:%02d %02d/%02d/%04d", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900);


  return String(timeStr);
}

// function to get temperature and humidity readings from sensors
String getSensorData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // creating a string data that stores both temperature and humidity in a string
  String data = String(temperature) + " C  " + String(humidity) + " %";
  return data;
}


// function to Write to the SD card which the the input parameters (where to store , path and the message)
void writeFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if(!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if(file.print(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();
}

// function to Append data to the SD card 
void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);
  lcd.clear();
  lcd.setCursor(0, 0);
  File file = fs.open(path, FILE_APPEND);
  if(!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if(file.print(message)) {
    lcd.print("data saved to");
    lcd.setCursor(0, 1);
    lcd.print("SD card");
    Serial.println("Message appended");

  } else {
    Serial.println("Append failed");
  }
  file.close();
}



// main loop
void loop() {
  lcd.clear();
  // we create three string variables which store the time stamp, sensor data and message to be appended in the sd  card
  String currentTime = getCurrentTime();
  lcd.setCursor(0, 0);
  lcd.print(currentTime);
  String sensorData = getSensorData();
  lcd.setCursor(0, 1);
  lcd.print(sensorData);
  String message = String(readingID)+","+currentTime+" ,"+ sensorData+ "/r/n";
  Serial.println(currentTime);
  Serial.println(message);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("saving data to");
  lcd.setCursor(0, 1);
  lcd.print("SD card");
  delay(1000);
  // we append the m,essage in data.txt file in the sd card
  appendFile(SD, "/data.txt", message.c_str());
 
   readingID++;
  delay(100000);
}
