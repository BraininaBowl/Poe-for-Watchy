#include <Watchy.h> //include the Watchy library
#include "PTSerif_Bold10pt7b.h"
#include "PTSerif_Regular10pt7b.h"
        

class WatchFace : public Watchy { //inherit and extend Watchy class
  public:
    void drawWatchFace() { //override this method to customize how the watch face looks
      
      int16_t  x1, y1, testx, curx, cury, lineheight, counter;
      uint16_t w, h;
      String mins[] = {"zero", "one", "two", "three", "four", "five", 
      String pretext[] = {"Once", "upon", "a"};
      String text[] = {"midnight"};
      String posttext[] = {"dreary,", "while", "I", "pondered,", "weak", "and", "weary,", "over", "many", "a", "quaint", "and", "curious", "volume", "of", "forgotten", "lore."};
      int16_t arraylength[] = {3,1,17};
      
      //drawbg
      display.fillScreen(GxEPD_WHITE);

      //draw time
      display.setTextColor(GxEPD_BLACK);
      display.setTextWrap(false);

      lineheight = 24;
      curx = 6;
      cury = 6 + lineheight;

      display.setFont(&PTSerif_Regular10pt7b);
      for (int i=0; i<arraylength[0]; i++) {
        display.getTextBounds(pretext[i], 0, 0, &x1, &y1, &w, &h);
        testx = curx + w;
        if (testx > 194){
          curx = 6;
          cury += lineheight; 
        }
        display.setCursor(curx,cury);
        curx += w + 5;
        display.print(pretext[i]);
      }

      display.setFont(&PTSerif_Bold10pt7b);
      for (int i=0; i<arraylength[1]; i++) {
        display.getTextBounds(text[i], 0, 0, &x1, &y1, &w, &h);
        testx = curx + w;
        if (testx > 194){
          curx = 6;
          cury += lineheight; 
        }
        display.setCursor(curx,cury);
        curx += w + 5;
        display.print(text[i]);
      }

      display.setFont(&PTSerif_Regular10pt7b);
      for (int i=0; i<arraylength[2]; i++) {
        display.getTextBounds(posttext[i], 0, 0, &x1, &y1, &w, &h);
        testx = curx + w;
        if (testx > 194){
          curx = 6;
          cury += lineheight; 
        }
        display.setCursor(curx,cury);
        curx += w + 5;
        display.print(posttext[i]);
      }

    
    }
};

WatchFace m; //instantiate your watchface

void setup() {
  m.init(); //call init in setup
}

void loop() {
  // this should never run, Watchy deep sleeps after init();
}
