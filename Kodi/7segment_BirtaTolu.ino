

/*
- PRINTING NUMBERS TO THE DISPLAY
- Tutorial: HOW TO SET UP SEVEN SEGMENT DISPLAYS ON THE ARDUINO
- https://www.circuitbasics.com/arduino-7-segment-display-tutorial
*/

#include "SevSeg.h"
SevSeg sevseg;  // create object. To use additional displays, you can create another object and call the relevant functions for that object.

void setup(){
    
    byte numDigits = 1;       // The number of digits on your display. single digit display, set it to 1. 4 digit display, set this to 4
    
    byte digitPins[] = {};    // defines the ground pins when using a 4 digit 
    
    /* This declares an array that defines which Arduino pins are connected to each segment of the display. 
    The order is alphabetical (A, B, C, D, E, F, G, DP where DP is the decimal point). 
    So in this case, Arduino pin 6 connects to segment A etc. */
    
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    
    bool resistorsOnSegments = true;   // true if your current limiting resistors are in series with the segment pins. 
                                       // If the resistors are in series with the digit pins, set this to false. Set this to true when using multi-digit displays.

    byte hardwareConfig = COMMON_CATHODE;       // This sets the type of display.
    
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);  // The display is initialized 
    
    sevseg.setBrightness(90);  //  brightness of the display. It can be adjusted from 0 to 100.
}

void loop(){
       /* function prints the number to the display.
        For example, to print the number “4.999”, you would use sevseg.setNumber(4999, 3).  
        The second parameter (the 3) defines where the decimal point is located. 
        If the second argument is -1 or omitted, there will be no decimal place. */
        
        sevseg.setNumber(4);            // function prints the number to the display.
        sevseg.refreshDisplay();        // required at the end of the loop section to continue displaying the number.
}
