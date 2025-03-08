// Define blink durations in milliseconds
#define DOT 200
#define DASH 550
#define LETTER_SPACE 550
#define WORD_SPACE 1500

// Function to blink LED for dot or dash
void blinkMorseCode(char symbol) {
  if (symbol == '.') {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(DOT);
  } else if (symbol == '-') {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(DASH);
  }
  digitalWrite(LED_BUILTIN, LOW);
  delay(DOT);  
}

// Function to blink a letter in Morse code
void blinkLetter(const char* morse) {
  while (*morse) {
    blinkMorseCode(*morse);
    morse++;
  }
  delay(LETTER_SPACE);  // Space between letters
}

// Setup function runs once
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// Loop function runs repeatedly
void loop() {
  blinkLetter("-.");    // N
  blinkLetter("..");    // I
  blinkLetter(".-.");   // R
  blinkLetter("--");    // M
  blinkLetter(".-");    // A
  blinkLetter(".-..");  // L

  delay(WORD_SPACE);  // Space between repetitions
}
