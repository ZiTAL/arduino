#define COUNT 5
#define ADDRESS 19

char s[COUNT][ADDRESS];
char t[COUNT][ADDRESS];

void setup()
{
    Serial.begin(115200);
}

void loop()
{
        
    for(int i=0; i<COUNT; i++)
    {
      String b = "123456789012345678";
      b.toCharArray(s[i], ADDRESS);
    }

    for(int i=0; i<COUNT; i++)
    {
      String b = s[i];
      b.toCharArray(t[i], ADDRESS);
    }
    printArray(t);

    for(int i=0; i<COUNT; i++)
    {
      String b = "ABCDEFGHIJKLMNÑOPQ";
      b.toCharArray(s[i], ADDRESS);
    }

    for(int i=0; i<COUNT; i++)
    {
      String b = s[i];
      b.toCharArray(t[i], ADDRESS);
    }    

    printArray(t);
    delay(1000);  
}

int printArray(char array[COUNT][ADDRESS])
{
    for(int i=0; i<COUNT; i++)
    {
        String obj = array[i];
        //if(obj!="")
            Serial.println(obj);
    }
}
