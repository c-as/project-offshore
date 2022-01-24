//noodstop Digital43 PL6
//Y-as end switch Digital37 PC0
//X-as end switch Digital36 PC1
//Z-as end switch boven Digital35 PC2
//Z-as end switch onder Digital34 PC3

#define NOODSTOP_INGEDRUKT (!(PINL & (1 << 6)))
#define Y_AS_END_SWITCH_INGEDRUKT (!(PINC & (1 << 0)))
#define X_AS_END_SWITCH_INGEDRUKT (!(PINC & (1 << 1)))
#define Z_AS_END_SWITCH_BOVEN_INGEDRUKT (!(PINC & (1 << 2)))
#define Z_AS_END_SWITCH_ONDER_INGEDRUKT (!(PINC & (1 << 3)))

void init_schakelaars(){
    //zet input
    DDRL &= ~(1 << 6);
    DDRC &= ~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3));
    //enable pullup
    PORTL |= (1 << 6);
    PORTC |= ((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3));
}
