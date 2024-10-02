#include <Servo.h>
#include <Keypad.h>

int buttonState = 0;
int pirState = 0;
int ultState = 0;
bool buttonEnabled = true; // Flag to track if the button is enabled
Servo myServo;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {1, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad customKeypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const char *password = "1231";

#define BUZZER_PIN 10 // Buzzer connected to pin 10

void setup()
{
  pinMode(2, INPUT);
  pinMode(11, INPUT); // PIR sensor connected to pin 11
  pinMode(13, INPUT); // ULTRAsonic sensor connected to pin 13
  pinMode(BUZZER_PIN, OUTPUT); // Set buzzer pin as output
  pinMode(LED_BUILTIN, OUTPUT);
  myServo.attach(12); // Attaching the servo to pin 12
}

void loop()
{
  buttonState = digitalRead(2);
  pirState = digitalRead(11);
  ultState = digitalRead(13);

  if (buttonState == HIGH && buttonEnabled) { // Check if the button is enabled
    digitalWrite(LED_BUILTIN, HIGH);
    openDoor(); // Call the function to open the door
    delay(2000); // Display for 2 seconds
    digitalWrite(LED_BUILTIN, LOW);
    buttonEnabled = false; // Disable the button
  } else if (pirState == HIGH) {
    // If motion is detected by PIR sensor
    lockDoor(); // Call the function to lock the door
  } else if (ultState == HIGH) {
     // If motion is detected by ultrasonic sensor
    lockDoor(); // Call the function to lock the door
  } else {
    // Check for keypad input
    char key = customKeypad.getKey();
    if (key != NO_KEY) {
      checkPassword(key);
    }
  }

  delay(10); // Delay a little bit to improve simulation performance
}

void openDoor() {
  // Control the servo to open the door
  myServo.write(180); // Assuming 180 degrees is the fully open position, adjust as needed
}

void lockDoor() {
  // Control the servo to lock the door
  myServo.write(0); // Assuming 0 degrees is the closed position, adjust as needed
  // Sound the buzzer
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000); // Sound buzzer for 1 second
  digitalWrite(BUZZER_PIN, LOW); // Turn off the buzzer
}

void checkPassword(char key) {
  static char enteredPassword[5] = ""; // Buffer for entered password
  static byte passwordIndex = 0; // Index of the next character in the entered password
  enteredPassword[passwordIndex++] = key; // Add the key to the entered password
  
  if (passwordIndex == 4) { // If the entered password is complete
    enteredPassword[4] = '\0'; // Null-terminate the entered password string
    if (strcmp(enteredPassword, password) == 0) { // Check if the entered password matches the correct password
      // If the password is correct, open the door, turn off the LED, and enable the button
      openDoor();
      digitalWrite(LED_BUILTIN, LOW);
      delay(2000); // Display for 2 seconds
      buttonEnabled = true; // Enable the button
    } else {
      // If the password is incorrect, clear the entered password buffer
      delay(2000); // Display for 2 seconds
    }
    // Reset the password buffer and index
    memset(enteredPassword, 0, sizeof(enteredPassword));
    passwordIndex = 0;
  }
}
