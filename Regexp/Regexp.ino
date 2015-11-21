#include <Regexp.h>

// called for each match
void match_callback(const char * match,          // matching string (not null-terminated)
                      const unsigned int length,   // length of matching string
                      const MatchState & ms)      // MatchState in use (to get captures)
{
char cap [512];   // must be large enough to hold captures
  
  Serial.print ("Matched: ");
  Serial.write ((byte *) match, length);
  Serial.println ();
  
  for (byte i = 0; i < ms.level; i++)
    {
    Serial.print ("Capture "); 
    Serial.print (i, DEC);
    Serial.print (" = ");
    ms.GetCapture (cap, i);
    Serial.println (cap); 
    }  // end of for each capture  
}  // end of match_callback 

void setup()
{
  Serial.begin (9600);
  Serial.println ();
  unsigned long count;

  // what we are searching (the target)
  char buf [] = "OK+DISISOK+DISC:4C000215:74278BDAB64445208FOC720EAF059935:FFEOFFE1C5:78A5048CECAC:-0620K+DISC:4C000215:74278BDAB64445208F0C720EAf059935:FFFE0FFE1C5:78A50485AF2D:-0580K+DISCE";

  // match state object
  MatchState ms (buf);

  // original buffer
  Serial.println (buf);

  // search for three letters followed by a space (two captures)
  //count = ms.GlobalMatch ("(%a+)(_)", match_callback);
  count = ms.GlobalMatch ("\+DISC\:(%w+\:%w+\:%w+\:%w+)\:([%w\-]+)", match_callback);
  // \+DISC\:(\w+\:\w+\:\w+\:\w+)\:([\w\-]+)

  // show results
  Serial.print ("Found ");
  Serial.print (count);            // 8 in this case
  Serial.println (" matches.");
}  // end of setup  

void loop()
{
}
