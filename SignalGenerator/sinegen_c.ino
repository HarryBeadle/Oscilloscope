#define TAB_LENGTH 32

int pwmPin = 11;
int potPin = 0;
int cos_index = 0;

// cosine
int cos_table[] = {125, 123, 120, 114, 107, 98, 87, 76, 65, 53, 42, 31, 22, 15, 9, 6, 5, 6, 9, 15, 22, 31, 42, 53, 65, 76, 87, 98, 107, 114, 120, 123};

// rising sawtooth
//int cos_table[] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248};

int next_sinusoid(){
  if (cos_index == TAB_LENGTH-1){
    cos_index = 0;
  }
  else{
    cos_index++;
  }
  
  return cos_table[cos_index];
}

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pwmPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //analogWrite(pwmPin, analogRead(potPin)/4);
  analogWrite(pwmPin, next_sinusoid());
  delay(4);              // wait for x ms
}

