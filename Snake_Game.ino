#include <gamma.h>
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// Similar to F(), but for PROGMEM string pointers rather than literals
#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr

// define the wiring of the LED screen
#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// Fun Snake Splash screen Graphic 
const char snek1[][14][3] PROGMEM = {{{0, 0, 0}, {0, 0, 0}, {10, 0, 0}, {10, 0, 0}, {8, 8, 8}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
  {{0, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {8, 8, 8}, {10, 10, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
  {{0, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {8, 8, 8}, {10, 10, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
  {{10, 0, 0}, {8, 8, 8}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 0, 0}},
  {{10, 0, 0}, {10, 10, 10}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {0, 0, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 10}},
  {{10, 0, 0}, {10, 10, 10}, {10, 10, 10}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {0, 0, 0}, {10, 10, 0}, {0, 10, 0}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}},
  {{10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {0, 0, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 10, 10}, {0, 10, 10}},
  {{0, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}},
  {{0, 0, 0}, {0, 0, 0}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {7, 7, 7}, {0, 10, 10}, {0, 0, 0}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {7, 7, 7}, {7, 7, 7}, {0, 10, 10}, {0, 0, 0}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {7, 7, 7}, {7, 7, 7}, {0, 0, 0}, {0, 0, 0}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {7, 7, 7}, {7, 7, 7}, {0, 0, 0}, {0, 0, 0}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {7, 7, 7}, {0, 0, 0}, {0, 0, 0}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {17, 7, 7}, {17, 7, 7}, {0, 0, 0}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {17, 7, 7}, {0, 0, 0}}
};

const char snek2[][14][3] PROGMEM = {{{0, 0, 0}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {8, 8, 8}, {8, 8, 8}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
  {{8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {8, 8, 8}, {10, 10, 0}, {8, 8, 8}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
  {{8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {8, 8, 8}, {10, 10, 0}, {8, 8, 8}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {0, 0, 0}},
  {{10, 0, 0}, {8, 8, 8}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {8, 8, 8}},
  {{10, 0, 0}, {10, 10, 10}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {8, 8, 8}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 10}},
  {{10, 0, 0}, {10, 10, 10}, {10, 10, 10}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {8, 8, 8}, {10, 10, 0}, {0, 10, 0}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}},
  {{10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {8, 8, 8}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {8, 8, 8}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}},
  {{8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {8, 8, 8}, {8, 8, 8}, {7, 7, 7}, {0, 10, 10}, {8, 8, 8}, {8, 8, 8}},
  {{0, 0, 0}, {8, 8, 8}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {8, 8, 8}, {8, 8, 8}, {0, 0, 0}, {8, 8, 8}, {7, 7, 7}, {7, 7, 7}, {8, 8, 8}, {0, 0, 0}},
  {{0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {7, 7, 7}, {7, 7, 7}, {7, 7, 7}, {8, 8, 8}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {7, 7, 7}, {17, 7, 7}, {17, 7, 7}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {8, 8, 8}, {17, 7, 7}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {17, 7, 7}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {17, 7, 7}, {8, 8, 8}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {8, 8, 8}, {0, 0, 0}}
};

const char PROGMEM snek3[][14][3] PROGMEM = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
  {{8, 8, 8}, {10, 10, 10}, {10, 10, 10}, {10, 0, 0}, {10, 10, 0}, {8, 8, 8}, {8, 8, 8}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {8, 8, 8}},
  {{10, 0, 0}, {10, 10, 10}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
  {{10, 0, 0}, {8, 8, 8}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {8, 8, 8}},
  {{10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 10}},
  {{10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}},
  {{10, 0, 0}, {8, 8, 8}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {10, 10, 0}, {10, 10, 0}, {0, 10, 0}, {8, 8, 8}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}, {0, 10, 10}},
  {{10, 0, 0}, {10, 10, 10}, {8, 8, 8}, {10, 0, 0}, {10, 0, 0}, {10, 10, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {8, 8, 8}, {7, 7, 7}, {0, 10, 10}, {8, 8, 8}, {8, 8, 8}},
  {{8, 8, 8}, {10, 10, 10}, {10, 10, 10}, {10, 0, 0}, {10, 10, 0}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {0, 0, 0}, {8, 8, 8}, {7, 7, 7}, {7, 7, 7}, {8, 8, 8}, {0, 0, 0}},
  {{0, 0, 0}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {8, 8, 8}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {7, 7, 7}, {7, 7, 7}, {7, 7, 7}, {8, 8, 8}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {7, 7, 7}, {17, 7, 7}, {17, 7, 7}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {8, 8, 8}, {17, 7, 7}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {17, 7, 7}},
  {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {8, 8, 8}, {17, 7, 7}, {8, 8, 8}}
};

const uint16_t background = matrix.Color333(0, 0, 0);  //r==g=b=0
const uint16_t head_color = matrix.Color333(7, 5, 0);  //r=g=b=7
const uint16_t tail_color = matrix.Color333(7, 3, 0);  //r=g=b=7
const uint16_t fruit_color = matrix.Color333(0, 7, 0);  //g=7, r=b=0
const uint16_t bad_fruit_color = matrix.Color333(7, 0, 0);  //g=7, r=b=0
const uint16_t border_color = matrix.Color333(7, 0, 0);  //r=7, g=b=0

const uint8_t SCREEN_WIDTH = 32;
const uint8_t SCREEN_HEIGHT = 16;

const int CONTROL_L =  13;  //Move left
const int CONTROL_R =  12;  //Move right
//These 2 buttons behave from the snakes point of view.
//if CONTROL_L is pressed, snake should take a left turn
//If CONTROL_R is pressed, snake should take a right turn

int loop_ctr = 1;
int headX, headY, score;
uint8_t fruit[2][2][2];
uint8_t bad_fruits[4][2][2][2];  //[fruit_number][fruit_related_x][fruit_related_y][global_x/global_y]
int level = 0;
const int max_level = 2;
const int min_bad_fruits = 1;
const int score_increments = 100;
int score_bar[max_level + 1] = {300, 500, 700};  //add levels and number of bad fruits keep on increasing.
//currently, increments happen\
//level0 to 1 @ score 50+
//level 1-2 at score 100+
//level 2-3 at score 150+
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
bool gameOver, consumed_input, start_screen, reset_screen, level_screen, display_game_over;
eDirecton dir;

void setup() {
  pinMode(CONTROL_L, INPUT); //setting all LED's to listen for input signals. INPUT and OUTPUT are arduino default constants.
  pinMode(CONTROL_R, INPUT);
  //Setting game variables
  gameOver = false;
  consumed_input = true;
  start_screen = true;
  reset_screen = true;
  level_screen = true;
  display_game_over = true;
  dir = STOP;     //Player Direction
  headX = SCREEN_WIDTH / 2;      //place the head in the centre of the screen, initially
  headY = SCREEN_HEIGHT / 2;
  //Move these 2 lines of code to a funciton and call it from here as well as the logic function...
  atefruit();
  score = 0;
  nTail = 0;
  Serial.begin(115200);
  Serial.println("starting...");
  matrix.begin();
}

void loop() {
  while (start_screen) {
    // display start screen animation
    splash_screen();
  }
  while (level_screen) {
    print_level();
    read_controller_for_level();
  }
  if (reset_screen) {
    reset_screen = false;
    matrix.fillScreen(0);
  }
  read_input();
  if (loop_ctr == 200) {
    if (gameOver) { //Need to handle the after game completion. To show the score
      //gameIsOver();
      if(display_game_over){
        display_game_over = false;
        print_game_over();
      }
      show_score(score);
    } else {
      logic();
      set_screen_values();
    }
    consumed_input = true;
    loop_ctr = 1;
  }
  loop_ctr++;
  delay(1);
}

void upgrade_level(){
  level++;
  level_screen = true;
  print_level();
}

void atefruit() {
  // AB x and y posiitons of dot 1are #142 and #143
  // CD
  fruit[0][0][0] = (rand() % (SCREEN_WIDTH - 1));   //Ax
  fruit[0][0][1] = (rand() % (SCREEN_HEIGHT - 1));  //Ay

  fruit[0][1][0]  = fruit[0][0][0]  + 1; //Bx = Ax + 1
  fruit[0][1][1]  = fruit[0][0][1]; //By = Ay

  fruit[1][0][0] = fruit[0][0][0]; //Cx = Ax
  fruit[1][0][1] = fruit[0][0][1] + 1; //Cy = Ay+1

  fruit[1][1][0] = fruit[1][0][0] + 1; //Dx = Cx+1
  fruit[1][1][1] = fruit[1][0][1]; //Dy = Cy
  //Place a fruit somewhere on the screen..
  
  new_bad_fruits();
}

void new_bad_fruits(){
  for(int i=0; i<min_bad_fruits+level; i++){
    bad_fruits[i][0][0][0] = (rand() % (SCREEN_WIDTH - 1));   //Ax
    bad_fruits[i][0][0][1] = (rand() % (SCREEN_HEIGHT - 1));  //Ay

    bad_fruits[i][0][1][0]  = bad_fruits[i][0][0][0]  + 1; //Bx = Ax + 1
    bad_fruits[i][0][1][1]  = bad_fruits[i][0][0][1]; //By = Ay

    bad_fruits[i][1][0][0] = bad_fruits[i][0][0][0]; //Cx = Ax
    bad_fruits[i][1][0][1] = bad_fruits[i][0][0][1] + 1; //Cy = Ay+1

    bad_fruits[i][1][1][0] = bad_fruits[i][1][0][0] + 1; //Dx = Cx+1
    bad_fruits[i][1][1][1] = bad_fruits[i][1][0][1]; //Dy = Cy
  }
}

void set_screen_values() {
  //   Drawing borders END
  for (int i = 0; i < SCREEN_WIDTH; i++) {
    for (int j = 0; j < SCREEN_HEIGHT; j++) {
      if (i == headX && j == headY) {
        matrix.drawPixel(i, j, head_color);
      } else {
        bool print = false;
        //iterate AB and CD and draw those pixels here - i and j are Ax and Ay
        //      matrix.drawPixel(i, j, fruit_color);
        //draw the fruit
        for (int fxi = 0; fxi < 2; fxi++) {   //fxi => fruitX i
          for (int fyi = 0; fyi < 2; fyi++) { //fyi => fruity i 
            if (fruit[fxi][fyi][0] == i && fruit[fxi][fyi][1] == j) {
              matrix.drawPixel(i, j, fruit_color);
              print = true;
            }
          }
        }
        
        //draw the bad fruits...
        for(int bfi = 0; bfi < min_bad_fruits+level; bfi++){ //bfi = bad fruit index
          for (int fxi = 0; fxi < 2; fxi++) {   //fxi => fruitX i
            for (int fyi = 0; fyi < 2; fyi++) { //fyi => fruity i 
              if (bad_fruits[bfi][fxi][fyi][0] == i && bad_fruits[bfi][fxi][fyi][1] == j) {
                matrix.drawPixel(i, j, bad_fruit_color);
                print = true;
              }
            }
          }
        }

        for (int k = 0; k < nTail; k++) {   //Iterating the tail
          if (i == tailX[k] && j == tailY[k]) {
            matrix.drawPixel(i, j, tail_color);
            print = true;
          }
        }
        if (!print) {
          matrix.drawPixel(i, j, background);
        }
      }
    }
  }
}

void read_input() {
  bool l = digitalRead(CONTROL_L);
  bool r = digitalRead(CONTROL_R);
  if (!consumed_input) {
    return;
  }
  if (dir == RIGHT) {
    if (l) {
      dir = UP;
    }
    else if (r) {
      dir = DOWN;
    }
  } else if (dir == LEFT) {
    if (l) {
      dir = DOWN;
    }
    else if (r) {
      dir = UP;
    }
  } else if (dir == UP) {
    if (l) {
      dir = LEFT;
    }
    else if (r) {
      dir = RIGHT;
    }
  } else if (dir == DOWN) {
    if (l) {
      dir = RIGHT;
    }
    else if (r) {
      dir = LEFT;
    }
  } else {
    dir = RIGHT;
  }
  consumed_input = false;
}

void logic() {
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;

  tailX[0] = headX;
  tailY[0] = headY;

  for (int i = 1; i < nTail; i++) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
  switch (dir) {
    case LEFT:
      headX--;
      break;
    case RIGHT:
      headX++;
      break;
    case UP:
      headY--;
      break;
    case DOWN:
      headY++;
      break;
    default:
      break;
  }
  
  if (headX >= SCREEN_WIDTH) {   //Snake enters from the other side
    headX = 0;          //Setting to 1 since we have 1 pixel border
  } else if (headX < 0) {
    headX = SCREEN_WIDTH - 1;
  }
  if (headY >= SCREEN_HEIGHT) {
    headY = 0;
  } else if (headY < 0) {
    headY = SCREEN_HEIGHT - 1;
  }
  for (int i = 0; i < nTail; i++) {       //Self kill..!
    if (tailX[i] == headX && tailY[i] == headY) {
      gameOver = true;
      reset_screen = true;
    }
  }
  for (int fxi = 0; fxi < 2; fxi++) {
    for (int fyi = 0; fyi < 2; fyi++) {
      if (fruit[fxi][fyi][0] == headX && fruit[fxi][fyi][1] == headY) {
        score += score_increments;
        if(level < max_level && (score >= score_bar[level] ) ){
          upgrade_level();
        }
        nTail++;
        atefruit();
      }
    }
  }
  for(int bfi = 0; bfi < min_bad_fruits+level; bfi++){ //bfi = bad fruit index
    for (int fxi = 0; fxi < 2; fxi++) {   //fxi => fruitX i
      for (int fyi = 0; fyi < 2; fyi++) { //fyi => fruity i 
        if (bad_fruits[bfi][fxi][fyi][0] == headX && bad_fruits[bfi][fxi][fyi][1] == headY) {
          if(nTail > 0){
            score -= score_increments/2;
            nTail--;
            atefruit();
          }else{
            gameOver = true;
            reset_screen = true;
          }
        }
      }
    }
  }
}

// displays Level
void print_game_over() {
  for(int i=0; i<7; i++){
    matrix.fillScreen(0);
    if(i%2 == 0){
        matrix.setCursor(5,0);
        matrix.setTextSize(1);
        matrix.setTextColor(matrix.Color333(7,0,0));
        matrix.print('G');
        matrix.print('A');
        matrix.print('M');
        matrix.print('E');
        matrix.print(' ');
        matrix.print('O');
        matrix.print('V');
        matrix.print('E');
        matrix.print('R');
        delay(450);
      }
      delay(200);

  }
  matrix.fillScreen(0);
}

// displays Level
void print_level() {
  matrix.fillScreen(0);
  matrix.setCursor(1,0);
  matrix.setTextSize(1);
  matrix.setTextColor(matrix.Color333(0,7,0));
  matrix.print('L');
  matrix.print('E');
  matrix.print('V');
  matrix.print('E');
  matrix.print('L');
  matrix.print(' ');
  matrix.print(level+1);
  delay(200);
}

// print character on screen at location, with color dependent on color variable input
void print_char(char c, uint8_t x, uint8_t y, uint8_t color)
{
  // set location of drawing cursor
  matrix.setCursor(x, y);

  // color goes from red to magenta, values 0, 5.
  // set actual color to draw character based on color input
  if (color == 0)
    matrix.setTextColor((matrix.Color333(7, 0, 0)));
  else if (color == 1)
    matrix.setTextColor((matrix.Color333(7, 7, 0)));
  else if (color == 2)
    matrix.setTextColor((matrix.Color333(0, 7, 0)));
  else if (color == 3)
    matrix.setTextColor((matrix.Color333(0, 7, 7)));
  else if (color == 4)
    matrix.setTextColor((matrix.Color333(7, 7, 7)));
  else if (color == 5)
    matrix.setTextColor((matrix.Color333(7, 0, 7)));

  // print character to screen
  matrix.print(c);
  delay(100);
}

// display score on screen
void show_score(int c)
{
  // display "SCORE"
  char S = 'S';
  char C = 'C';
  char O = 'O';
  char R = 'R';
  char E = 'E';

  // subroutine called to print character at certain location, with color dependent on c variable
  print_char(S, 2, 1, (c) % 6);
  print_char(C, 8, 1, (c + 1) % 6);
  print_char(O, 14, 1, (c + 2) % 6);
  print_char(R, 20, 1, (c + 3) % 6);
  print_char(E, 26, 1, (c + 4) % 6);

  // display score value on screen
  matrix.setCursor(11, 8);
  matrix.print(score);
  matrix.swapBuffers(false);

  // delay between update and color shifting
  delay(100);
}


// start screen animation
void splash_screen() {

  // draw "SNAKE" on screen
  // S
  read_controller();
  matrix.drawPixel(12, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(13, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(14, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(12, 4, matrix.Color333(10, 10, 0));
  matrix.drawPixel(12, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(13, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(14, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(14, 6, matrix.Color333(0, 10, 10));
  matrix.drawPixel(14, 7, matrix.Color333(7, 7, 7));
  matrix.drawPixel(13, 7, matrix.Color333(7, 7, 7));
  matrix.drawPixel(12, 7, matrix.Color333(7, 7, 7));

  // N
  matrix.drawPixel(16, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(16, 4, matrix.Color333(10, 10, 0));
  matrix.drawPixel(16, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(16, 6, matrix.Color333(0, 10, 10));
  matrix.drawPixel(16, 7, matrix.Color333(7, 7, 7));
  matrix.drawPixel(17, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(18, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(18, 4, matrix.Color333(10, 10, 0));
  matrix.drawPixel(18, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(18, 6, matrix.Color333(0, 10, 10));
  matrix.drawPixel(18, 7, matrix.Color333(7, 7, 7));

  //A
  matrix.drawPixel(21, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(20, 4, matrix.Color333(10, 10, 0));
  matrix.drawPixel(22, 4, matrix.Color333(10, 10, 0));
  matrix.drawPixel(20, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(21, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(22, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(20, 6, matrix.Color333(0, 10, 10));
  matrix.drawPixel(22, 6, matrix.Color333(0, 10, 10));
  matrix.drawPixel(20, 7, matrix.Color333(7, 7, 7));
  matrix.drawPixel(22, 7, matrix.Color333(7, 7, 7));

  // K
  matrix.drawPixel(24, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(24, 4, matrix.Color333(10, 10, 0));
  matrix.drawPixel(24, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(24, 6, matrix.Color333(0, 10, 10));
  matrix.drawPixel(24, 7, matrix.Color333(7, 7, 7));
  matrix.drawPixel(25, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(25, 6, matrix.Color333(0, 10, 10));
  matrix.drawPixel(26, 4, matrix.Color333(10, 10, 0));
  matrix.drawPixel(26, 7, matrix.Color333(7, 7, 7));

  // E
  matrix.drawPixel(28, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(29, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(30, 3, matrix.Color333(10, 0, 0));
  matrix.drawPixel(28, 4, matrix.Color333(10, 10, 0));
  matrix.drawPixel(28, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(29, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(30, 5, matrix.Color333(0, 10, 0));
  matrix.drawPixel(28, 6, matrix.Color333(0, 10, 10));
  matrix.drawPixel(28, 7, matrix.Color333(7, 7, 7));
  matrix.drawPixel(29, 7, matrix.Color333(7, 7, 7));
  matrix.drawPixel(30, 7, matrix.Color333(7, 7, 7));


  // Draw animation frames on screen, after each frame, check if the start button was pressed.

  for (int k = 0; k < 3; k++)
  {
    for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 14; j++) {
        matrix.drawPixel(i + 1, j + 1, matrix.Color333(pgm_read_byte(&snek1[i][j][0]), pgm_read_byte(&snek1[i][j][1]), pgm_read_byte(&snek1[i][j][2])));
      }
    }
    delay(200);
    read_controller();
    if (!start_screen) {
      return;
    }

    for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 14; j++) {
        matrix.drawPixel(i + 1, j + 1, matrix.Color333(pgm_read_byte(&snek2[i][j][0]), pgm_read_byte(&snek2[i][j][1]), pgm_read_byte(&snek2[i][j][2])));
      }
    }
    delay(200);
    read_controller();
    if (!start_screen) {
      return;
    }
  }

  for (int i = 0; i < 14; i++) {
    for (int j = 0; j < 14; j++) {
      matrix.drawPixel(i + 1, j + 1, matrix.Color333(pgm_read_byte(&snek3[i][j][0]), pgm_read_byte(&snek3[i][j][1]), pgm_read_byte(&snek3[i][j][2])));
    }
  }
  delay(1000);
  read_controller();
  if (!start_screen) {
    return;
  }
}

void read_controller() {
  bool l = digitalRead(CONTROL_L);
  bool r = digitalRead(CONTROL_R);
  if (l || r) {
    start_screen = false;
  }
}

void read_controller_for_level() {
  bool l = digitalRead(CONTROL_L);
  bool r = digitalRead(CONTROL_R);
  if (l || r) {
    level_screen = false;
  }
}
