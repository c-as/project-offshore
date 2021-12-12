int rotoencoder_graden = 0;

bool rotoencoder_a = false;
bool rotoencoder_b = false;
bool rotoencoder_allebei = false;

void init_rotoencoder(){
    //zet input
    DDRH &= ~((1 << PH4) | (1 << PH3));
}

void check_rotoencoder(){
    //a
    if(PINH & (1<<PH4) && PINH & (1<<PH3) && !rotoencoder_allebei){
       rotoencoder_allebei = true;
        if(rotoencoder_a){
            rotoencoder_graden += 18;
        } else if (rotoencoder_b){
            rotoencoder_graden -= 18;
        }
    }

    if(!(PINH & (1<<PH4) && PINH & (1<<PH3)) && rotoencoder_allebei){
       rotoencoder_allebei = false;
    }

    //b
    if(PINH & (1<<PH4) && !rotoencoder_a){
        rotoencoder_a = true;
    } else {
        rotoencoder_a = false;
    }

    if(PINH & (1<<PH3) && !rotoencoder_b){
        rotoencoder_b = true;
    } else {
        rotoencoder_b = false;
    }
}
