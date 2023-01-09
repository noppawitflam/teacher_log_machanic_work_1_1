// This code is blynk step



#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int tempo = 108;
int buzzer = 8;
int melody[] = {
  
  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  
  NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
  NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
  NOTE_C6,1
  
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;


int sw = 2;
int led[9] = {3, 4, 5, 6, 7, 9, 10, 11, 12};
int count_button = 0;
int last_count_button = 0;


void setup()
{
  pinMode(sw, INPUT);
  for (int i = 0; i < 9; i++)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);
  }
}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    checkCase(i);
  }
   for (int i = 0; i < 9; i++)
  {
    digitalWrite(led[i], LOW);
  }
}


void checkCase(int p_choice)
{
  switch (p_choice)
  {
    case 0: step_01(); break;
    case 1: step_02(); break;
    case 2: step_03(); break;
    case 3: step_04(); break;
    case 4: step_05(); break;
    case 5: step_06(); break;
    case 6: step_07(); break;
    case 7: step_08(); break;
  }
}

void step_01()
{
  // ไฟเรียงติด จาก lsb --> msb
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(200);
  }
}

void step_02()
{
  // ไฟเรียงดับ จาก lsb --> msb
  for (int i = 8; i >= 0; i--)
  {
    digitalWrite(led[i], LOW);
    delay(200);
  }
}

void step_03()
{
  // ไฟเรียงติดดับ จาก lsb --> msb
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(200);
    digitalWrite(led[i], LOW);
    delay(200);
  }
}

void step_04()
{
  // ไฟเรียงติดดับ จาก msb --> lsb
  for (int i = 8; i >= 0; i--)
  {
    digitalWrite(led[i], HIGH);
    delay(200);
    digitalWrite(led[i], LOW);
    delay(200);
  }
}

void step_05()
{
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(led[i], HIGH);
  }
  delay(500);
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(led[i], LOW);
  }
  delay(500);
}

void step_06()
{
  for (int x = 0; x < 3; x++)
  {
    for (int i = 0; i < 9; i++)
    {
      digitalWrite(led[i], HIGH);
    }
    delay(500);
    for (int i = 0; i < 9; i++)
    {
      digitalWrite(led[i], LOW);
    }
    delay(500);
  }
}


void step_07()
{
  for (int i = 0; i < 256; i++)
  {
    analogWrite(led[0], i);
    analogWrite(led[2], i);
    analogWrite(led[3], i);
    analogWrite(led[7], i);
    analogWrite(led[8], i);
    analogWrite(led[9], i);
    delay(50);
  }
}

void step_08()
{
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer, melody[thisNote], noteDuration*0.9);
    delay(noteDuration);
    noTone(buzzer);
  }
}
