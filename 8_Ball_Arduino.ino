/*
   8_Ball_Arduino
   Turn your Arduino into a 8 Ball toy!
   __    __     __     __   __     __  __     ______   ______     ______
  /\ "-./  \   /\ \   /\ "-.\ \   /\ \/\ \   /\__  _\ /\  ___\   /\  ___\
  \ \ \-./\ \  \ \ \  \ \ \-.  \  \ \ \_\ \  \/_/\ \/ \ \  __\   \ \___  \
   \ \_\ \ \_\  \ \_\  \ \_\\"\_\  \ \_____\    \ \_\  \ \_____\  \/\_____\
    \/_/  \/_/   \/_/   \/_/ \/_/   \/_____/     \/_/   \/_____/   \/_____/
                               ______   ______
                              /\__  _\ /\  __ \
                              \/_/\ \/ \ \ \/\ \
                                 \ \_\  \ \_____\
                                  \/_/   \/_____/
   __    __     __     _____     __   __     __     ______     __  __     ______
  /\ "-./  \   /\ \   /\  __-.  /\ "-.\ \   /\ \   /\  ___\   /\ \_\ \   /\__  _\
  \ \ \-./\ \  \ \ \  \ \ \/\ \ \ \ \-.  \  \ \ \  \ \ \__ \  \ \  __ \  \/_/\ \/
   \ \_\ \ \_\  \ \_\  \ \____-  \ \_\\"\_\  \ \_\  \ \_____\  \ \_\ \_\    \ \_\
    \/_/  \/_/   \/_/   \/____/   \/_/ \/_/   \/_/   \/_____/   \/_/\/_/     \/_/

  MinutesToMidnight
  Now with more fun in every byte!

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>
// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7
#define BLACK 0x0

int die = 1;  //stores the die position

void setup()
{
        // set up the LCD's number of columns and rows:
        lcd.begin(16, 2);
        lcd.clear();
        lcd.setBacklight(WHITE);
        die = random(1, 21);
}

void loop()
{
        uint8_t buttons = lcd.readButtons();
        if (buttons)
        {
                if (buttons & BUTTON_SELECT)
                {
                        die = random(1, 21);
                        lcd.clear();
                        for (int i = 0; i < 5; i++) //Blink backlight
                        {
                                delay(50);
                                lcd.setBacklight(BLACK);
                                delay(50);
                                lcd.setBacklight(WHITE);
                        }
                }
        }

        switch (die)
        {
        case 1:
                // set the cursor to column 0, line 0
                lcd.setCursor(0, 0);
                lcd.print(F("It is certain   "));
                lcd.setCursor(0, 1);
                lcd.print(F("                "));
                break;
        case 2:
                lcd.setCursor(0, 0);
                lcd.print(F("It is decidedly "));
                lcd.setCursor(0, 1);
                lcd.print(F("so, number 1    "));
                break;
        case 3:
                lcd.setCursor(0, 0);
                lcd.print(F("Without a doubt "));
                lcd.setCursor(0, 1);
                lcd.print(F("I think...      "));
                break;
        case 4:
                lcd.setCursor(0, 0);
                lcd.print(F("There are four  "));
                lcd.setCursor(0, 1);
                lcd.print(F("lights! 00000100"));
                break;
        case 5:
                lcd.setCursor(0, 0);
                lcd.print(F("Have you seen my"));
                lcd.setCursor(0, 1);
                lcd.print(F("fortune cookie? "));
                break;
        case 6:
                lcd.setCursor(0, 0);
                lcd.print(F("As I see it, yes"));
                lcd.setCursor(0, 1);
                lcd.print(F("42 is the answer"));
                break;
        case 7:
                lcd.setCursor(0, 0);
                lcd.print(F("Most likely     "));
                lcd.setCursor(0, 1);
                lcd.print(F("                "));
                break;
        case 8:
                lcd.setCursor(0, 0);
                lcd.print(F("Do you smell    "));
                lcd.setCursor(0, 1);
                lcd.print(F("fire?           "));
                break;
        case 9:
                lcd.setCursor(0, 0);
                lcd.print(F("Yes, I do love  "));
                lcd.setCursor(0, 1);
                lcd.print(F("U235 !!!!!      "));
                break;
        case 10:
                lcd.setCursor(0, 0);
                lcd.print(F("Signs point to  "));
                lcd.setCursor(0, 1);
                lcd.print(F("somewhere       "));
                break;
        case 11:
                lcd.setCursor(0, 0);
                lcd.print(F("Reply hazy try  "));
                lcd.setCursor(0, 1);
                lcd.print(F("again           "));
                break;
        case 12:
                lcd.setCursor(0, 0);
                lcd.print(F("Ask again later "));
                lcd.setCursor(0, 1);
                lcd.print(F("I'm too busy now"));
                break;
        case 13:
                lcd.setCursor(0, 0);
                lcd.print(F("Don't count on  "));
                lcd.setCursor(0, 1);
                lcd.print(F("it              "));
                break;
        case 14:
                lcd.setCursor(0, 0);
                lcd.print(F("My reply is no  "));
                lcd.setCursor(0, 1);
                lcd.print(F("way...  ;-)     "));
                break;
        case 15:
                lcd.setCursor(0, 0);
                lcd.print(F("Better not tell "));
                lcd.setCursor(0, 1);
                lcd.print(F("you now         "));
                break;
        case 16:
                lcd.setCursor(0, 0);
                lcd.print(F("Cannot predict  "));
                lcd.setCursor(0, 1);
                lcd.print(F("the weather!    "));
                break;
        case 17:
                lcd.setCursor(0, 0);
                lcd.print(F("My sources say  "));
                lcd.setCursor(0, 1);
                lcd.print(F("there is $ there"));
                break;
        case 18:
                lcd.setCursor(0, 0);
                lcd.print(F("I am a Arduino  "));
                lcd.setCursor(0, 1);
                lcd.print(F("hear me roar!!! "));
                break;
        case 19:
                lcd.setCursor(0, 0);
                lcd.print(F("Outlook not good"));
                lcd.setCursor(0, 1);
                lcd.print(F("Use Thunderbird!"));
                break;
        case 20:
                lcd.setCursor(0, 0);
                lcd.print(F("I process,      "));
                lcd.setCursor(0, 1);
                lcd.print(F("therefore I am  "));
                break;
        default:
                lcd.setCursor(0, 0);
                lcd.print(F("ERROR!!!        "));
                lcd.setCursor(0, 1);
                lcd.print(F("ERROR!!!        "));
                break;
        }
}
