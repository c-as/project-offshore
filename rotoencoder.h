//pin CLK_X PA0 Digital22
//pin DT_X PA1 Digital23
//pin CLK_Y PA2 Digital24
//pin DT_Y PA3 Digital25

#define CLK_HOOG_X PINA & (1 << 0)
#define DT_HOOG_X PINA & (1 << 1)
#define CLK_HOOG_Y PINA & (1 << 2)
#define DT_HOOG_Y PINA & (1 << 3)

int rotoencoder_clock_x = 0;
int rotoencoder_clock_y = 0;

bool prev_CLK_X;
bool prev_CLK_Y;

void init_rotoencoder(){
    //zet input
    DDRA &= ~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3));

    prev_CLK_X = CLK_HOOG_X;
    prev_CLK_Y = CLK_HOOG_Y;
}

void check_rotoencoders(){
    bool current_CLK_X = CLK_HOOG_X;
    bool current_DT_X = DT_HOOG_X;

    if(current_CLK_X != prev_CLK_X){
        if(current_CLK_X != current_DT_X){
            rotoencoder_clock_x++;
        } else {
            rotoencoder_clock_x--;
        }
    }

    prev_CLK_X = current_CLK_X;

    bool current_CLK_Y = CLK_HOOG_Y;
    bool current_DT_Y = DT_HOOG_Y;

    if(current_CLK_Y != prev_CLK_Y){
        if(current_CLK_Y != current_DT_Y){
            rotoencoder_clock_y++;
        } else {
            rotoencoder_clock_y--;
        }
    }

    prev_CLK_Y = current_CLK_Y;
}
