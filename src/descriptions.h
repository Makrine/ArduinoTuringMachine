#include <avr/pgmspace.h>
// 0 power 2
const char string_0[] PROGMEM = "7";
const char string_1[] PROGMEM = "0X#";
const char string_2[] PROGMEM = "65";

const char string_3[] PROGMEM = "_11";
const char string_4[] PROGMEM = "D15";
const char string_5[] PROGMEM = "D15";

const char string_6[] PROGMEM = "X12";
const char string_7[] PROGMEM = "D11";
const char string_8[] PROGMEM = "D16";

const char string_9[] PROGMEM = "D13";
const char string_10[] PROGMEM = "D12";
const char string_11[] PROGMEM = "D04";

const char string_12[] PROGMEM = "X12";
const char string_13[] PROGMEM = "D13";
const char string_14[] PROGMEM = "D15";

const char string_15[] PROGMEM = "D04";
const char string_16[] PROGMEM = "D04";
const char string_17[] PROGMEM = "D11";
const char *const desc0n[] PROGMEM = 
{
  string_0, string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8, string_9, string_10, string_11,
  string_12, string_13, string_14, string_15, string_16, string_17
};

// even
const char string_0_e[] PROGMEM = "4";
const char string_1_e[] PROGMEM = "01#";
const char string_2_e[] PROGMEM = "32";

const char string_3_e[] PROGMEM = "D11";
const char string_4_e[] PROGMEM = "D11";
const char string_5_e[] PROGMEM = "D13";

const char string_6_e[] PROGMEM = "D10";
const char string_7_e[] PROGMEM = "D10";
const char string_8_e[] PROGMEM = "D12";

const char *const descEven[] PROGMEM = 
{
  string_0_e, string_1_e, string_2_e, string_3_e, string_4_e, string_5_e, string_6_e, string_7_e, string_8_e
};



// palindrome
const char string_0_p[] PROGMEM = "8";
const char string_1_p[] PROGMEM = "01#";
const char string_2_p[] PROGMEM = "67";

const char string_3_p[] PROGMEM = "_11";
const char string_4_p[] PROGMEM = "_12";
const char string_5_p[] PROGMEM = "D16";

const char string_6_p[] PROGMEM = "D11";
const char string_7_p[] PROGMEM = "D11";
const char string_8_p[] PROGMEM = "D03";

const char string_9_p[] PROGMEM = "D12";
const char string_10_p[] PROGMEM = "D12";
const char string_11_p[] PROGMEM = "D05";

const char string_12_p[] PROGMEM = "_04";
const char string_13_p[] PROGMEM = "D17";
const char string_14_p[] PROGMEM = "D16";

const char string_15_p[] PROGMEM = "D04";
const char string_16_p[] PROGMEM = "D04";
const char string_17_p[] PROGMEM = "D10";

const char string_18_p[] PROGMEM = "D17";
const char string_19_p[] PROGMEM = "_04";
const char string_20_p[] PROGMEM = "D16";
const char *const pal[] PROGMEM = 
{
  string_0_p, string_1_p, string_2_p, string_3_p, string_4_p, string_5_p, string_6_p, string_7_p, string_8_p, string_9_p, string_10_p, string_11_p,
  string_12_p, string_13_p, string_14_p, string_15_p, string_16_p, string_17_p, string_18_p, string_19_p, string_20_p
};

// howTo/About
const char str1[] PROGMEM = " ";
const char str2[] PROGMEM = "How To/About";
const char str3[] PROGMEM = "\n________\n";
const char str4[] PROGMEM = "This is an U";
const char str5[] PROGMEM = "niversal Tur";
const char str6[] PROGMEM = "ing Machine ";
const char str7[] PROGMEM = "Simulator ma";
const char str8[] PROGMEM = "de by Makrin";
const char str9[] PROGMEM = "e Tskipurish";
const char str10[] PROGMEM = "vili. She's ";
const char str11[] PROGMEM = "a totally co";
const char str12[] PROGMEM = "ol character";
const char str13[] PROGMEM = " B-)\n";
const char str14[] PROGMEM = "# is 'enter'";
const char str15[] PROGMEM = "Basically ev";
const char str16[] PROGMEM = "erything els";
const char str17[] PROGMEM = "e quite stra";
const char str18[] PROGMEM = "ightforward/";
const char str19[] PROGMEM = "given. Press";
const char str20[] PROGMEM = " any key to ";
const char str21[] PROGMEM = "go back to t";
const char str22[] PROGMEM = "he main menu";
const char *const how[] PROGMEM = 
{
  str1, str2, str3, str4, str5, str6, str7, str8, str9,
  str10, str11, str12, str13, str14, str15, str16, str17, str18, str19,
  str20, str21, str22
};


// start menu
const char start1[] PROGMEM = "\n";
const char start2[] PROGMEM = "Start Menu";
const char start3[] PROGMEM = "\n________\n";
const char start4[] PROGMEM = " \n";
const char start5[] PROGMEM = "1: Choose al";
const char start6[] PROGMEM = "gorithm\n";
const char start7[] PROGMEM = "2: Add Algor";
const char start8[] PROGMEM = "ithm\n";
const char start9[] PROGMEM = "3: How-to";

const char *const start[] PROGMEM = 
{
  start1, start2, start3, start4, start5, start6, start7, start8, start9,
};

// choose menu
const char choose1[] PROGMEM = "\n";
const char choose2[] PROGMEM = "Choose Algor";
const char choose3[] PROGMEM = "ithm\n";
const char choose4[] PROGMEM = "________\n";
const char choose5[] PROGMEM = "\n";
const char choose6[] PROGMEM = "1: {0^2^n | ";
const char choose7[] PROGMEM = "n>=0}\n";
const char choose8[] PROGMEM = "2: Even\n";
const char choose9[] PROGMEM = "3: Palindrom";
const char choose10[] PROGMEM = "e\n";
const char choose11[] PROGMEM = "0: Back To M";
const char choose12[] PROGMEM = "enu\n";

const char *const choose[] PROGMEM = 
{
  choose1, choose2, choose3, choose4, choose5, choose6, choose7, choose8, choose9, choose10, choose11, choose12
};

// add menu
const char add1[] PROGMEM = "\n";
const char add2[] PROGMEM = "Add Algorith";
const char add3[] PROGMEM = "m\n";
const char add4[] PROGMEM = "________\n";
const char add5[] PROGMEM = "\n";
const char add6[] PROGMEM = "1: Start\n";
const char add7[] PROGMEM = "0: Back To M";
const char add8[] PROGMEM = "enu\n";

const char *const add[] PROGMEM = 
{
  add1, add2, add3, add4, add5, add6, add7, add8
};

// results
const char res1[] PROGMEM = "Your result:";
const char res2[] PROGMEM = " \n\nFinal ";
const char res3[] PROGMEM = "word:\n";
const char res4[] PROGMEM = "1. Another w";
const char res5[] PROGMEM = "ord\n";
const char res6[] PROGMEM = "0: Back To M";
const char res7[] PROGMEM = "enu";


const char *const res[] PROGMEM = 
{
  res1, res2, res3, res4, res5, res6, res7
};

// wrong char
const char wrong1[] PROGMEM = "WRONG Char, ";
const char wrong2[] PROGMEM = "try again, p";
const char wrong3[] PROGMEM = "ress any key";
const char wrong4[] PROGMEM = "\n";


const char *const wrong[] PROGMEM = 
{
  wrong1, wrong2, wrong3, wrong4
};

// press a key
/*const char press1[] PROGMEM = "press a num ";
const char press2[] PROGMEM = "on the keypa";
const char press3[] PROGMEM = "d...\n";


const char *const pressKey[] PROGMEM = 
{
  press1, press2, press3
};
*/
char buffer[12];
