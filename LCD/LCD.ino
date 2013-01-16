/*
    ** Example Arduino sketch for SainSmart I2C LCD2004 adapter for HD44780 LCD screens
 ** Readily found on eBay or http://www.sainsmart.com/
 ** The LCD2004 module appears to be identical to one marketed by YwRobot
 **
 ** Address pins 0,1 & 2 are all permanently tied high so the address is fixed at 0x27
 **
 ** Written for and tested with Arduino 1.0
 ** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
 ** https://bitbucket.org/fmalpartida/new-liquidcrystal
 **
 ** Edward Comer
 ** LICENSE: GNU General Public License, version 3 (GPL-3.0)
 */
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
 
#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
 
int n = 1;
 
LiquidCrystal_I2C       lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
 
void setup()
{
  lcd.begin (20,4,LCD_5x8DOTS);
 
 
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE); // init the backlight
}
 
void loop()
{
  demoDisplay();
  demoDisplay2();
 
  lcd.setBacklight(LOW);        // Backlight off
  lcd.home ();                   // go home     
  lcd.print("ABCDEFGHIJKLMNOPQRST"); 
  lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print("UVWXYZ 0123456789   ");
  lcd.setCursor ( 0, 2 );        // go to the next line
  lcd.print("abcdefghijklmnopqrst");
  lcd.setCursor ( 0, 3 );        // go to the next line
  lcd.print("uvwxyz <>!?@#$%&*() ");
  lcd.setBacklight(HIGH);     // Backlight on
  //lcd.on(); // Switch fully on the LCD (backlight and LCD)
  delay(3000);
 
 
 
  //lcd.setCursor (2,3);        // go col 2 of line 3
  //lcd.print(n++,BIN);          // print the value of n
 
  for (int i = 0; i < 20; i++) {
    delay(300);
    lcd.scrollDisplayLeft();
  }
  delay(3000);
 
  for (int i = 0; i < 20; i++) {
    delay(300);
    lcd.scrollDisplayRight();
  }
  delay(3000);
 
  lcd.clear(); // clear display, set cursor position to zero
  lcd.autoscroll(); // This will 'right justify' text from the cursor
  lcd.print("autoscroll");
  delay(3000);
 
  lcd.clear(); // clear display, set cursor position to zero
  lcd.noAutoscroll(); // This will 'left justify' text from the cursor
  lcd.print("noAutoscroll");
  delay(3000);
 
  lcd.clear(); // clear display, set cursor position to zero
  // This is for text that flows Right to Left
  lcd.rightToLeft();
  lcd.print("rightToLeft");
  delay(3000);
 
  lcd.clear(); // clear display, set cursor position to zero
  lcd.leftToRight(); // This is for text that flows Left to Right
  lcd.print("leftToRight");
  delay(3000);
 
  lcd.clear(); // clear display, set cursor position to zero
  lcd.print("blink");
  lcd.blink(); // Turns on the blinking cursor
  delay(3000);
 
  lcd.clear(); // clear display, set cursor position to zero
  lcd.print("noBlink");                  
  lcd.noBlink(); // Turns off the blinking cursor
  delay(3000);
 
  lcd.clear(); // clear display, set cursor position to zero
  lcd.print("cursor"); 
  lcd.cursor(); // Turns the underline cursor on/off
  delay(3000);
 
  lcd.clear(); // clear display, set cursor position to zero
  lcd.print("noCursor"); 
  lcd.noCursor(); // Turns the underline cursor on/off
  delay(3000);
 
  //lcd.off(); // Switch fully off the LCD (backlight and LCD) 
 
}
 
void demoDisplay() 
{
  lcd.clear(); // clear display, set cursor position to zero
  lcd.setBacklight(HIGH);     // Backlight on
  lcd.setCursor (0,0); 
  lcd.print("Good afternoon,");
  lcd.setCursor (0,1);        // go col 0 of line 1
  lcd.print("gentlemen.");
  delay(1000);
  lcd.setCursor (0,2);        // go col 0 of line 2
  lcd.print("I am a HAL 9000 ");
  lcd.setCursor (0,3);        // go col 0 of line 3
  lcd.print("computer.");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("I became operational");
  lcd.setCursor (0,1);
  lcd.print("at the H.A.L. plant ");
  lcd.setCursor (0,2);
  lcd.print("in Urbana, Illinois ");
  lcd.setCursor (0,3);
  lcd.print("on January 12 1992. ");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("My instructor was   ");
  lcd.setCursor (0,1); 
  lcd.print("Mr. Langley, and he ");
  lcd.setCursor (0,2); 
  lcd.print("taught me to sing   ");
  lcd.setCursor (0,3); 
  lcd.print("a song.             ");  
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("If you'd like to    ");
  lcd.setCursor (0,1); 
  lcd.print("hear it I can sing  "); 
  lcd.setCursor (0,2); 
  lcd.print("it for you.         ");
  lcd.setCursor (0,3); 
  lcd.blink(); // Turns on the blinking cursor
  delay(4000);
  wipeLines();
  lcd.noBlink(); // Turns off the blinking cursor
}
 
void demoDisplay2() 
{
 
  /*
   Dave Bowman: Hello, HAL. Do you read me, HAL?
   HAL: Affirmative, Dave. I read you.
   Dave Bowman: Open the pod bay doors, HAL.
   HAL: I'm sorry, Dave. I'm afraid I can't do that.
   Dave Bowman: What's the problem?
   HAL: I think you know what the problem is just as well as I do.
   Dave Bowman: What are you talking about, HAL?
   HAL: This mission is too important for me to allow you to jeopardize it.
   Dave Bowman: I don't know what you're talking about, HAL.
   HAL: I know that you and Frank were planning to disconnect me, and I'm afraid that's something I cannot allow to happen.
   Dave Bowman: [feigning ignorance] Where the hell did you get that idea, HAL?
   HAL: Dave, although you took very thorough precautions in the pod against my hearing you, I could see your lips move.
   Dave Bowman: Alright, HAL. I'll go in through the emergency airlock.
   HAL: Without your space helmet, Dave? You're going to find that rather difficult.
   Dave Bowman: HAL, I won't argue with you anymore! Open the doors!
   HAL: Dave, this conversation can serve no purpose anymore. Goodbye. 
   */
 
  lcd.setCursor (0,0); 
  lcd.print("Hello, HAL.         ");
  lcd.setCursor (0,1);        // go col 0 of line 1
  lcd.print("Do you read me, HAL?");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,2); 
  lcd.print("Affirmative, Dave. ");
  lcd.setCursor (0,3);        // go col 0 of line 1
  lcd.print("I read you.        ");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("Open the pod bay   ");
  lcd.setCursor (0,1);        // go col 0 of line 1
  lcd.print("doors, HAL.        ");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,1); 
  lcd.print("I'm sorry, Dave.   ");
  lcd.setCursor (0,2);
  lcd.print("I'm afraid I can't ");
  lcd.setCursor (0,3);
  lcd.print("do that.           ");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("What's the problem? ");
  delay(4000);
  wipeLines();  
 
  lcd.setCursor (0,1);
  lcd.print("I think you know    ");
  lcd.setCursor (0,2);
  lcd.print("what the problem is ");
  lcd.setCursor (0,3);
  lcd.print("just as well as I do");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("What are you talking");
  lcd.setCursor (0,1);
  lcd.print("about, HAL?         ");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("This mission is too ");
  lcd.setCursor (0,1);   
  lcd.print("important for me to ");
  lcd.setCursor (0,2); 
  lcd.print("allow you to        ");
  lcd.setCursor (0,3); 
  lcd.print("jeopardize it.      ");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("I don't know what   ");
  lcd.setCursor (0,1); 
  lcd.print("you're talking about");
  lcd.setCursor (0,2); 
  lcd.print(", HAL.");
  delay(4000);
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("I know that you and ");
  lcd.setCursor (0,1); 
  lcd.print("Frank were planning ");
  lcd.setCursor (0,2);
  lcd.print("to disconnect me,   ");
  delay(4000);
  lcd.setCursor (0,0); 
  lcd.print("and I'm afraid      ");
  lcd.setCursor (0,1); 
  lcd.print("that's something I  ");
  lcd.setCursor (0,2); 
  lcd.print("cannot allow to     ");
  lcd.setCursor (0,3); 
  lcd.print("happen.             ");
  delay(4000);  
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("Where the hell did  ");
  lcd.setCursor (0,1);
  lcd.print("you get that idea,  ");
  lcd.setCursor (0,2);
  lcd.print("HAL?");
  delay(4000);  
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("Dave, although you  ");
  lcd.setCursor (0,1);
  lcd.print("took very thorough  ");
  lcd.setCursor (0,2);
  lcd.print("precautions in the  ");
  lcd.setCursor (0,3);
  lcd.print("pod against my      ");
  delay(4000);  
  lcd.setCursor (0,0); 
  lcd.print("hearing you, I could");
  lcd.setCursor (0,1);
  lcd.print("see your lips move. ");
  lcd.setCursor (0,2);
  lcd.print("                    ");
  lcd.setCursor (0,3);
  lcd.print("                    ");
  delay(4000);  
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("Alright, HAL. I'll  ");
  lcd.setCursor (0,1);
  lcd.print("go in through the   ");
  lcd.setCursor (0,2);
  lcd.print("emergency airlock.  ");
  lcd.setCursor (0,3);
  lcd.print("                    ");
  delay(4000);  
  wipeLines();
 
 
  lcd.setCursor (0,0); 
  lcd.print("Without your space  ");
  lcd.setCursor (0,1);
  lcd.print("helmet, Dave? You're");
  lcd.setCursor (0,2);
  lcd.print("going to find that  ");
  lcd.setCursor (0,3);
  lcd.print("rather difficult.   ");
  delay(4000);  
  wipeLines();
 
  lcd.setCursor (0,0); 
  lcd.print("HAL, I won't argue  ");
  lcd.setCursor (0,1);
  lcd.print("with you anymore!   ");
  lcd.setCursor (0,2);
  lcd.print("Open the doors!     ");
  lcd.setCursor (0,3);
  lcd.print("                    ");
  delay(4000);  
  wipeLines();  
 
  lcd.setCursor (0,0); 
  lcd.print("Dave, this          ");
  lcd.setCursor (0,1);
  lcd.print("conversation can    ");
  lcd.setCursor (0,2);
  lcd.print("serve no purpose    ");
  lcd.setCursor (0,3);
  lcd.print("anymore. Goodbye.   ");
  delay(4000);  
  wipeLines(); 
 
}
void wipeLines() {
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 20; x++) {
      lcd.setCursor (x,y);
      lcd.print(" ");
      delay(10);
    }
  }
}
