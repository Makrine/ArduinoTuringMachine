#include <Keypad.h>

// Keypad Setup
char keys[4][4] = {
  {'1','2','3', '_'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte pin_rows[] = {A5, A4, 2, 3};
byte pin_column[] = {4, 5, 6, 7};

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, 4, 4);
