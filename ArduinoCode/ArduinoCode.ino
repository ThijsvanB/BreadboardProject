#define USB_IN_PIN 4
#define USB_OUT_PIN 7

#define BAUD_RATE 110
#define BIT_DURATION 1000000 / BAUD_RATE

#define CONFIRMATION_BYTE 0b01010101

int input = 0;

void setup() { 
  pinMode(USB_IN_PIN, INPUT_PULLUP);
  pinMode(USB_OUT_PIN, OUTPUT);

  digitalWrite(USB_OUT_PIN, HIGH);
  
  Serial.begin(9600);
  Serial.println("Started");
}

int readByte() {
  Serial.println("Reading byte");
  int byte = 0;
  for(int i = 0; i < 9; i++) {
    int input = digitalRead(4);
    if(i != 0) {
      byte += input << i - 1;
    }
    delayMicroseconds(BIT_DURATION);
  }
  Serial.print("Byte read:");
  Serial.println(byte);

  sendByte(CONFIRMATION_BYTE);

  return byte;
}

void sendByte(unsigned char byte) {
  Serial.println("Sending conformation Byte");

  digitalWrite(USB_OUT_PIN, LOW);
  delayMicroseconds(BIT_DURATION);

  for(int i = 0; i < 8; i++) {
    digitalWrite(USB_OUT_PIN, ((byte >> i) & 1));
    delayMicroseconds(BIT_DURATION);
  }

  digitalWrite(USB_OUT_PIN, HIGH);
  Serial.print("Sent Byte: ");
  Serial.println(byte);
}

void loop() {
  input = digitalRead(4);
  
  if (input == 0) {
    int byte = readByte();
  }
}
