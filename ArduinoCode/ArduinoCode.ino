int input = 0;
int previnput = 0;

void setup() { 
  pinMode(4, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.println("Started");
}

int readByte() {
  int byte = 0;
  for(int i = 0; i < 9; i++) {
    int input = digitalRead(4);
    if(i != 0) {
      byte += input << i - 1;
    }
    Serial.println("Bit read:");
    Serial.println(input);
    delay(9);
  }
  return byte;
}

void loop() {
  input = digitalRead(4);
  
  if (input == 0) {
    Serial.println("Start reading");
    int byte = readByte();
    Serial.println(byte);
    Serial.println("End reading");
  }
}
