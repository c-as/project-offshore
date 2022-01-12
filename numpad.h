//0 Digital 26 PA4
//1 Digital 27 PA5
//2 Digital 28 PA6
//3 Digital 29 PA7
//4 Digital 30 PC7
//5 Digital 31 PC6
//6 Digital 32 PC5
//7 Digital 33 PC4

int numpad_codes[4][4] = {
    {1,2,3,11},
    {4,5,6,12},
    {7,8,9,13},
    {15,0,16,14}

};

int numpad_laatste_rij = 0;
int numpad_laatste_kolom = 0;

void init_numpad(){
    //PORTA |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
}

void check_numpad(){
    DDRA |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    DDRC &= ~((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4));
    PORTA &= ~((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
    PORTC |= (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4);

    for(int rij = 0; rij < 4; rij++){
        if(!(PINC & (1 << 7 - rij))){
            numpad_laatste_rij = rij;
            break;
        }
    }

    DDRA &= ~((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
    DDRC |= (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4);
    PORTA |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    PORTC &= ~((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4));

    for(int kolom = 0; kolom < 4; kolom++){
        if(!(PINA & (1 << 4 + kolom))){
            numpad_laatste_kolom = kolom;
            break;
        }
    }
}

int numpad_keycode(){
    return numpad_codes[numpad_laatste_rij][numpad_laatste_kolom];
}
