#include <Keyboard.h>


byte rows[] = {3,2,0}; // add row pins here
byte cols[] = {4,12};  // col pins here

const int rowCount = sizeof(rows)/sizeof(rows[0]);
const int colCount = sizeof(cols)/sizeof(cols[0]);

byte keys[colCount][rowCount];

// add keymap here
static const String keymap[colCount][rowCount] = {
    {"MEAT ", "CHECK  ", "MEAT_ "},
    {"CHEQUE ", "MiiT_ ", "CZECH"}
  };

void setup() {
  Serial.begin(115200);

  for(int i=0; i < rowCount; i++){
    pinMode(rows[i], INPUT);  
  }

  
  for(int i=0; i < colCount; i++){
    pinMode(cols[i], INPUT_PULLUP);  
  }
}

void loop() {
  //Keyboard.print("yeet \n");
  for(int i=0; i < colCount; i++){
    byte curCol = cols[i];
    pinMode(curCol, OUTPUT);
    digitalWrite(curCol, LOW);

    for(int j=0; j < rowCount; j++){
      byte curRow = rows[j];
      pinMode(curRow, INPUT_PULLUP);
      keys[i][j] = digitalRead(curRow);
      pinMode(curRow, INPUT);
    }
  pinMode(curCol, INPUT);
  }
  
  Serial.println("Matrix: ");
  for(int i=0; i < colCount; i++){
    for(int j=0; j<rowCount; j++){
      if(!keys[i][j] == true){
      Keyboard.print(keymap[i][j]);
      }
      Serial.print(keys[i][j]);
      Serial.print(F(", "));
      }
    Serial.print("\n");
  }
  delay(100);
}
