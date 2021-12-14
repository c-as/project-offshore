//pin CLK PA0 Digital22
//pin DT PA1 Digital23

#define CLK_HOOG PINA & (1<<0)
#define DT_HOOG PINA & (1<<1)

int rotoencoder_clock = 0;

bool prev_CLK;

void init_rotoencoder(){
    //zet input
    DDRA &= ~((1 << 0) | (1 << 1));

    prev_CLK = CLK_HOOG;
}

void check_rotoencoder(){
    bool current_CLK = CLK_HOOG;
    bool current_DT = DT_HOOG;

    if(current_CLK != prev_CLK){
        if(current_CLK != current_DT){
            rotoencoder_clock++;
        } else {
            rotoencoder_clock--;
        }
    }

    prev_CLK = current_CLK;
}
