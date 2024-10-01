int input = 0;
int previnput = 0;

void setup() { 
  pinMode(4, input);
  Serial.begin(9600);
}

void loop() {
  input = digitalRead(4);
  if (input != previnput) {
    previnput = input;
    Serial.println(input);
  }
}
