/*
  Alexander Le
  IBM Z Ambassador
  09.03.14
    - Proposed text interaction created using C++11
    - Establishes a terminal shell like experience
      for a modern transition to Zowe systems w/ VScode
*/

// Preprocessor Directives
#include <iostream>
#include <memory> 
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <typeinfo>
#include <chrono>
#include <ctime>
#include <new>
#include <thread>
#include <vector>
#include <algorithm>

// Namespace Declarations
using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

// Function Prototypes
void fast(string, unsigned long, unsigned long);
void intro();

// Classes
class Telnet3270{
  private:
    string Zid = "";
    string pwd = "";
    bool registered = 0; 
    string n1 = "";
    string n2 = "";
    int age = 0;
    string email = "";
  public:
    // Default constructor  
    Telnet3270() { intro(); }
    // Process initial input - list initilize class properties
    Telnet3270(string z, string p, bool r): Zid(z), pwd(p), registered(r){}
    // Register user - list initilize class properties
    Telnet3270(string f, string l, int a, string e): n1(f), n2(l), age(a), email(e) {}

};

// Driver 
int main() 
{
   Telnet3270 client; 
  
   return EXIT_SUCCESS; 
}

void intro()
{
  // Sync time
  time_t rawtime;
  time (&rawtime);
  struct tm * timeinfo;
  char buffer[80];
  timeinfo = localtime(&rawtime);
  
  bool x = 1;
  while(x)
  {
    // Program greeting
    fast("    ZZZZZZZZ\\ ZZZZZZZ\\ZZZ\\     ZZ\\       ZZZZZZZZ\\       ZZ\\      ZZ\\ ZZZZZZZZ\\ ZZ\\      ZZ | \n", 15000, 0);
    fast("    \\_ZZ  _|ZZ  __ZZ\\ ZZZ\\    ZZZ |      \\____ZZ  |      ZZZ\\    ZZZ |\\__ZZ  __|ZZZ\\    ZZZ | \n", 15000, 0);
    fast("      ZZ |  ZZ |  ZZ |ZZZZ\\  ZZZZ |          ZZ  /       ZZZZ\\  ZZZZ |   ZZ |   ZZZZ\\  ZZZZ | \n", 15000, 0);
    fast("      ZZ |  ZZZZZZZ\\ |ZZ\\ZZ\\ZZ ZZ |         ZZ  /        ZZ\\ZZ\\ZZ ZZ |   ZZ |   ZZ\\ZZ\\ZZ ZZ | \n", 15000, 0);
    fast("      ZZ |  ZZ  __ZZ\\ ZZ \\ZZZ  ZZ |        ZZ  /         ZZ \\ZZZ  ZZ |   ZZ |   ZZ \\ZZZ  ZZ | \n", 15000, 0);
    fast("      ZZ |  ZZ |  ZZ |ZZ |\\Z  /ZZ |       ZZ  /          ZZ |\\Z  /ZZ |   ZZ |   ZZ |\\Z  /ZZ | \n", 15000, 0);
    fast("    ZZZZZZ\\ ZZZZZZZ  |ZZ | \\_/ ZZ |      ZZZZZZZZ\\       ZZ | \\_/ ZZ |   ZZ |   ZZ | \\_/ ZZ | \n", 15000, 0);
    fast("    \\______|\\_______/ \\__|     \\__|      \\________|      \\__|     \\__|   \\__|   \\__|     \\__| \n\n", 15000, 0);
    break;
  }

    // Craft a string buffer with the current time from system.
  fast("\nIt is currently: ", 15000, 0);
  strftime(buffer,sizeof(buffer),"%A, the %d of %B %G \nThe current time is: %r",timeinfo);
  string str(buffer);

  fast(str, 15000, 0);
  cout << flush;

  // Countdown to Z Day!
  string date = "";

  char i1 = '1';
  char i2 = '5';
  char * a = &i1;
  char * b = &i2;
  date[0] = *a;
  date[1] = *b;
  // Compute the days until Z Day
  if(str[12] == *a && str[13] == *b){

    // If Z Day then announce so, if not, show days until Z Day. 
    fast("\n\nITS Z DAY!!!", 15000, 0);
  } else {
    cout << "\n\nWe have 15 - " << str[12] << str[13] <<  " days until Z Day! [It already happened]\nGo to https://ibmzday.bemyapp.com/2020 to see the replays!\n\n";
  }

  char regex = 'n';
  fast("Have you registered for IBM's Master the Mainframe? [y/n]: ", 15000, 0);
  cin >> regex; 
  if(regex == 'y'){
    fast("\nIncredible! Hope to see you participate in the challenges, stay tuned! \n\n", 15000, 0);
  } else {
    fast("\nWell you really should!\n\nIt's packed full of essential skills that you should learn like:\n     COBOL\n     REXX\n     JCL\n     PYTHON\n     ANISIBLE\n    ZOWE\n\nPlease register at https://masterthemainframe.com, we hope to see you soon! \n\n", 15000, 0);
  }

  fast("Created by Alexander Le, IBM Z Ambassador 20' \nIBM Z ~ Open | On | Secure\n", 15000, 0);
}

// UI function - access a thread to print text fast
void fast(string text, unsigned long delay, unsigned long postDelay = 1500000)
{
  cout << " " << flush;
  // Loop through each character of the string
  for (unsigned int i = 0; i < text.length(); i++)
  {
    // Print one character
    cout << "\b \b" << text[i] << ' ' << flush;
    usleep(delay);
  }
  // Blink cursor for the post delay
  for (unsigned long post = postDelay; post > 0; post -= 500000)
  {
    cout << "\b " << flush;
    usleep(250000);
    cout << "\b" << flush;
    usleep(250000);
  }
  // Clear cursor
  cout << "\b \b" << flush;
}
// clear text
void Clear()
{
  const short height = 50;
  fast(string(height * 2, '\n'), 10000, 0);
  for (int i = 0; i < height; i++)
  {
    cout << "\033[F" << flush;
  }
}
