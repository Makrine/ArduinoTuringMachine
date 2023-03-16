#define TAPE_LENGTH 20
#define STATE_NUM 10
#define ALPHA_LENGTH 12
#define VALUES 3

#include "myKeypad.h"
#include "descriptions.h"
#include "display.h"
#include "myEeprom.h"

void setup()
{   
  Serial.begin(9600);
  tft.initR(INITR_144GREENTAB);
  Serial.println("start");
  tft.fillScreen(ST77XX_YELLOW);
  tft.setCursor(30, 50);
  tft.setTextColor(ST77XX_BLUE);
  tft.setTextSize(1);
  tft.print("Turing Machine");
  tft.setCursor(58, 60);
  tft.print("By");
  tft.setCursor(45, 70);
  tft.print("Makrine");
  delay(1000);
  StartMenu();
}

const char empt = '_';
const char n = 'D';
enum States
{
    q0,
    q1,
    q2,
    q3,
    q4,
    q5,
    q6,
    q7,
    q8,
    qAcc,
    qRej
};

int numOfStates;
States currentState = States::q0;
int acc, rej;
int headIndex = 0;
char myWord[TAPE_LENGTH];

int alphaLength = 9;
char alphabet[ALPHA_LENGTH];

struct DescEachAlphaChar
{
    char alphaChar;
    char whatToDo[VALUES]; // write, dir, next
};

struct DescEachState
{
    int state;
    DescEachAlphaChar alphaDesc[ALPHA_LENGTH];
};

DescEachState description[STATE_NUM];


void StartMenu()
{
  display_freeram();
  ResetDisplay();
  for(int i = 0; i < 9; i++)
  {
    strcpy_P(buffer, (char *)pgm_read_word(&(start[i])));
    tft.print(buffer);
  }
  
  PressNumKeypad();

  char key = GetCharFromKeypad();
  bool rightKey = false;
  while(!rightKey)
  {
    if(key == '1') {ChooseAlgorithm(); rightKey = true;}
    else if(key == '2') {AddAlgorithm(); rightKey = true;}
    else if(key == '3') {HowTo(); rightKey = true;}
    else {key = GetCharFromKeypad();}
  }
}

void TM(bool addAlgo = false, bool cont = false, const char* const* algo = {})
{
  display_freeram();
  if(!cont)
  {
    if(addAlgo) GetDescription();
    else ReadFromGiven(algo);
  }
  //else alphabet[0] = help;
  GetWordInputKeypad();
  RunProgram();
  ResultDisplay();
}

void HowTo()
{
  display_freeram();
  ResetDisplay();
  for(int i = 0; i < 22; i++)
  {
    strcpy_P(buffer, (char *)pgm_read_word(&(how[i])));
    tft.print(buffer);
  }
  char key = GetCharFromKeypad();
  bool rightKey = false;
  while(!rightKey)
  {
    if(key != NO_KEY) {StartMenu(); rightKey = true;}
    else key = GetCharFromKeypad();
  }
}

void ChooseAlgorithm()
{
  display_freeram();
  ResetDisplay();
  for(int i = 0; i < 12; i++)
  {
    strcpy_P(buffer, (char *)pgm_read_word(&(choose[i])));
    tft.print(buffer);
  }

  PressNumKeypad();

  char key = GetCharFromKeypad();
  bool rightKey = false;
  while(!rightKey)
  {
    if(key == '1') {TM(false, false, desc0n); rightKey = true;}
    else if(key == '2') {TM(false, false, descEven); rightKey = true;}
    else if(key == '3') {TM(false, false, pal); rightKey = true;}
    else if(key == '0') {StartMenu(); rightKey = true;}
    else {key = GetCharFromKeypad();}
  }
}

void AddAlgorithm()
{
  display_freeram();
  ResetDisplay();
  for(int i = 0; i < 8; i++)
  {
    strcpy_P(buffer, (char *)pgm_read_word(&(add[i])));
    tft.print(buffer);
  }

  PressNumKeypad();

  char key = GetCharFromKeypad();
  bool rightKey = false;
  while(!rightKey)
  {
    if(key == '1') {TM(true); rightKey = true;}
    else if(key == '0') {StartMenu(); rightKey = true;}
    else key = GetCharFromKeypad();
  }

}

void PressNumKeypad()
{
  tft.setCursor(0, 70);
  tft.print("press a num on the keypad...\n");
  //for(int i = 0; i < 3; i++)
  //{
  //  strcpy_P(buffer, (char *)pgm_read_word(&(pressKey[i])));
  //  tft.print(buffer);
  //}
}

void ResultDisplay()
{
  display_freeram();
  ResetDisplay();
  for(int i = 0; i < 3; i++)
  {
    strcpy_P(buffer, (char *)pgm_read_word(&(res[i])));
    tft.print(buffer);
  }
  for(int i = 0; i < TAPE_LENGTH; i++){tft.print(myWord[i]);} 
  tft.println();
  if(currentState == States::qAcc) tft.println("\nACCEPTED!");
  else tft.println("\nREJECTED! :(\n");
  
  for(int i = 3; i < 7; i++)
  {
    strcpy_P(buffer, (char *)pgm_read_word(&(res[i])));
    tft.print(buffer);
  }

  char key = GetCharFromKeypad();
  bool rightKey = false;
  while(!rightKey)
  { 
    if(key == '1') {TM(false, true); rightKey = true;}
    else if(key == '0') {StartMenu(); rightKey = true;}
    else {key = GetCharFromKeypad();}
  }
  
}

void ReadFromGiven(const char* const* algo)
{
  display_freeram();
  ResetTM();
  memset(alphabet, 0, sizeof(alphabet));
  memset(description, 0, sizeof(description));
  memset(buffer, 0, sizeof(buffer));
  strcpy_P(buffer, (char *)pgm_read_word(&(algo[0])));
  numOfStates = (int)buffer[0] - 48;
  Serial.println();
  Serial.print("Num of states: ");
  Serial.print(numOfStates);
  Serial.println();

  strcpy_P(buffer, (char *)pgm_read_word(&(algo[1])));
  alphaLength = 0;
  Serial.print("Alphabet: ");
  Serial.println();

  for(int i = 0; i < ALPHA_LENGTH; i++)
  {
    if(isdigit(buffer[i]) || isalpha(buffer[i]) || buffer[i] == '*')
    {
      alphaLength++;
      alphabet[i] = buffer[i];
      Serial.print(alphabet[i]);
    }
    
  }
  writeCharArrayIntoEEPROM(0, alphabet, alphaLength);
  Serial.println();
  Serial.print("Alphabet length: ");
  Serial.print(alphaLength);
  Serial.println();
  Serial.print("Alphabet: ");
  Serial.println();
  for(int j = 0; j < alphaLength + 1; j++)
  {
      if(j == alphaLength)
        {
            alphabet[j] = empt;
        }
      Serial.print(alphabet[j]);
  }
  Serial.println();
  strcpy_P(buffer, (char *)pgm_read_word(&(algo[2])));
  acc = (int)buffer[0] - 48;
  rej = (int)buffer[1] - 48;
  int count = 3;
  for(int i = 0; i < numOfStates - 2; i++)
  {
    DescEachState descEachState;
    descEachState.state = i;
    Serial.print("State: ");
    Serial.print(i);
    Serial.println();
    for(int j = 0; j < alphaLength + 1; j++)
    {
        char writeC, dir, next;
        strcpy_P(buffer, (char *)pgm_read_word(&(algo[count])));
        writeC = buffer[0];
        dir = buffer[1];
        next = buffer[2];

        DescEachAlphaChar descEachAlphaChar; // what happens on each state. this has 3 elements: write(what char to write), go(left, right), nextState. 
        descEachAlphaChar.alphaChar = alphabet[j];
        descEachAlphaChar.whatToDo[0] = writeC;
        descEachAlphaChar.whatToDo[1] = dir;
        descEachAlphaChar.whatToDo[2] = next;

        descEachState.alphaDesc[j] = descEachAlphaChar;
    
        description[i] = descEachState;
        count++;

        Serial.print(descEachAlphaChar.alphaChar);
        Serial.print(", ");
        Serial.print(descEachAlphaChar.whatToDo[0]);
        Serial.print(", ");
        Serial.print(descEachAlphaChar.whatToDo[1]);
        Serial.print(", ");
        Serial.print(descEachAlphaChar.whatToDo[2]);
        Serial.println();
    }
  }
}


void STATE()
{
  display_freeram();
    CheckForEndDisplay();
    DescEachState descEachState;
    tft.print("STATE: ");
    tft.print(currentState);
    tft.println();
    for(int i = 0; i < TAPE_LENGTH; i++)
    {
      tft.print(myWord[i]);
      Serial.print(myWord[i]);
    } 
    tft.println();
    Serial.println();
    for(int i = 0; i < TAPE_LENGTH; i++)
    {
      if(i != headIndex){ tft.print(" "); Serial.print(" "); continue;}
      tft.print("^");
      Serial.print("^");
    } 
    tft.println();
    Serial.println();
    if(currentState == acc) currentState = States::qAcc;
    else if(currentState == rej) currentState = States::qRej;
    else 
    {
        descEachState = description[currentState];
        for(int i = 0; i < alphaLength + 1; i++)
        {
            DescEachAlphaChar descEachAlphaChar;

            descEachAlphaChar = descEachState.alphaDesc[i];
            if(myWord[headIndex] == descEachAlphaChar.alphaChar)
            {
                //write
                myWord[headIndex] = descEachAlphaChar.whatToDo[0] == n? myWord[headIndex] : descEachAlphaChar.whatToDo[0];

                //direction
                if(descEachAlphaChar.whatToDo[1] == '0') headIndex--;
                else headIndex++;

                //next state
                int next =  (int)descEachAlphaChar.whatToDo[2] - 48;
                States val = static_cast<States>(next);
                currentState = val;
                return;
}
                Serial.println();
                Serial.println(myWord[headIndex]);
                Serial.print(descEachAlphaChar.alphaChar);
                Serial.print(", ");
                Serial.print(descEachAlphaChar.whatToDo[0]);
                Serial.print(", ");
                Serial.print(descEachAlphaChar.whatToDo[1]);
                Serial.print(", ");
                Serial.print(descEachAlphaChar.whatToDo[2]);
                Serial.println();
}}
}
void RunProgram()
{   

    if(currentState == States::qAcc) {Serial.println("ACCEPTED!"); return;}
    else if(currentState == States::qRej) {Serial.println("REJECTED"); return;}

    STATE();

    RunProgram();
}

void GetWordInputKeypad()
{
  display_freeram();
  ResetTM();
  memset(myWord, 0, sizeof(myWord));
  ResetDisplay();
  int i = 0;
  readCharArrayFromEEPROM(0, alphabet, alphaLength);
  tft.print("Input alpha: ");
  for(int k = 0; k < alphaLength; k++)
  {
    tft.print(alphabet[k]);
  }
  tft.print("\nEnter word:\n");
  char key = GetCharFromKeypad();
  while (key != '#')
  {
    if(key == 'C') {GetWordInputKeypad(); return;}
    bool wrongChar = false;
    Serial.print(key);
    for(int j = 0; j < alphaLength; j++)
    {
      if(key == alphabet[j]) { wrongChar = false; break;}
      wrongChar = true;
    }
    if(wrongChar)
    {
      ResetDisplay();
      for(int i = 0; i < 4; i++)
      {
        strcpy_P(buffer, (char *)pgm_read_word(&(wrong[i])));
        tft.print(buffer);
      }
      char key = GetCharFromKeypad();
      if(key) {GetWordInputKeypad(); return;}
    }
    tft.print(key);
  
    myWord[i++] = key;
    key = GetCharFromKeypad();
  }
  tft.fillScreen(BLACK);
  tft.setCursor(0, 1);
  for(int j = 0; j < TAPE_LENGTH; j++)
  {
      if(j < i) myWord[i] = myWord[j];
      else myWord[j] = empt; 
  }

  for(int i = 0; i < TAPE_LENGTH; i++)
  {
     tft.print(myWord[i]);
  }
  tft.println();
  Serial.println();
}

char GetCharFromKeypad()
{
  char key = keypad.getKey();
  while(!key) {key = keypad.getKey();}
  return key;
}


void GetAlpha()
{
  display_freeram();
  memset(alphabet, 0, sizeof(alphabet));
  int i = 0;
  
  tft.print("Enter alphabet: ");
  char key = GetCharFromKeypad();
  while (key != '#')
  {
    if(key == 'C') {GetAlpha(); return;}
    tft.print(key);
    alphabet[i++] = key;
    key = GetCharFromKeypad();
  }
  alphaLength = i;

  for(int j = 0; j < alphaLength + 1; j++)
  {
      if(j == alphaLength)
        {
            alphabet[j] = empt;
        }
  }
  writeCharArrayIntoEEPROM(0, alphabet, alphaLength);
}

void GetDescription()
{
  display_freeram();
    ResetTM();
    ResetDisplay();

    tft.println("num of states: ");
    numOfStates = (int)GetCharFromKeypad() - 48;
    tft.println(numOfStates);
    GetAlpha();
    tft.println();
    tft.println("accept state: ");
    acc = (int)GetCharFromKeypad() - 48;
    tft.println(acc);
    tft.println("reject state: ");
    rej = (int)GetCharFromKeypad() - 48;
    tft.println(rej);

    for(int i = 0; i < numOfStates - 2; i++)
    {   
        DescEachState descEachState;
        descEachState.state = i;
        
        tft.print("for state ");
        tft.print(i);
        tft.println();
        for(int j = 0; j < alphaLength + 1; j++)
        {
            char key;
            CheckForEndDisplay();

            tft.print("if ");
            tft.println(alphabet[j]);

            char writeC, dir, next;

            tft.println("write:(A-empty, D-none, any)");
            writeC = GetCharFromKeypad();
            tft.println(writeC);

            tft.println("direction (0-L, 1-R):");
            dir = GetCharFromKeypad();
            tft.println(dir);

            tft.println("next state:");
            next = GetCharFromKeypad();
            tft.println(next);
            DescEachAlphaChar descEachAlphaChar; // what happens on each state. this has 3 elements: write(what char to write), go(left, right), nextState. 
            descEachAlphaChar.alphaChar = alphabet[j];
            descEachAlphaChar.whatToDo[0] = writeC;
            descEachAlphaChar.whatToDo[1] = dir;
            descEachAlphaChar.whatToDo[2] = next;
            descEachState.alphaDesc[j] = descEachAlphaChar;   
            description[i] = descEachState;
}}}
void ResetTM()
{
    currentState = States::q0;
    headIndex = 0;
}

void loop(){}
