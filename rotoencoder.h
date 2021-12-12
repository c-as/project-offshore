#define CLK_HOOG PINH & (1<<4)
#define DT_HOOG PINH & (1<<3)

int rotoencoder_clock = 0;

bool prev_CLK;

void init_rotoencoder(){
    //zet input
    DDRH &= ~((1 << PH4) | (1 << PH3));

    prev_CLK = CLK_HOOG;
}

void check_rotoencoder(){
    bool current_CLK = CLK_HOOG;

    if(current_CLK != prev_CLK){
        if(current_CLK != DT_HOOG){
            rotoencoder_clock++;
        } else {
            rotoencoder_clock--;
        }
    }

    prev_CLK = current_CLK;
}
