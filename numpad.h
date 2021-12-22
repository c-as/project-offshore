//0 Digital 26 PA4
//1 Digital 27 PA5
//2 Digital 28 PA6
//3 Digital 29 PA7
//4 Digital 30 PC7
//5 Digital 31 PC6
//6 Digital 32 PC5
//7 Digital 33 PC4

int numpad_laatste_rij = 0;
int numpad_laatste_kolom = 0;

void init_numpad(){
    DDRA |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    DDRC &= ~((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4));
}

void check_numpad(){
//    PORTA |= (1 << (4));
//
//    if(PINC & (1 << 7)){
//        numpad_laatste_ingedrukt_x = 1;
//    } else {
//        numpad_laatste_ingedrukt_x = 0;
//    }
//    return;

    for(int rij = 0; rij < 4; rij++){
        PORTA |= (1 << (4 + rij));

        for(int kolom = 0; kolom < 4; kolom++){
            if(PINC & (1 << (7 - kolom))){
                numpad_laatste_rij = rij;
                numpad_laatste_kolom = kolom;
                return;
            }
        }

        PORTA &= ~(1 << (4 + rij));
    }
}
