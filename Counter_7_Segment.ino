int incrementButton = A0;
int decrementButton = A1;

int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int segmentPins[7] = {a, b, c, d, e, f, g};

const int digits[10][7] = {
  // A,B,C,D,E,F,G
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

int counter = 0;
int incrementState;
int decrementState;

void setup(){
  Serial.begin(9600);

  pinMode(incrementButton, INPUT);
  pinMode(decrementButton, INPUT);

  for(int i = 0; i < 7; i++){
    pinMode(segmentPins[i], OUTPUT);
  }

}

void display(int number){
  for (int i = 0; i < 7; i++){
    digitalWrite(segmentPins[i], digits[number][i]);
  }
}

void loop(){
  display(counter);
  incrementState = digitalRead(incrementButton);
  if(incrementState){
    if(counter == 9){
      counter = 0;
    }
    else{
      counter += 1;
    }
    display(counter);
    delay(200);
  }
  decrementState = digitalRead(decrementButton);
   if(decrementState){
    if(counter == 0){
      counter = 9;
    }
    else{
      counter -= 1;
    }
    
    display(counter);
    delay(200);
  }
}
