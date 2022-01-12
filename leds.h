//Led Aan Digital2 PE4
//Led Noodstop Digital3 PE5
//Led Input X Digital4 PG5
//Led Input Y Digital5 PE3
//Led Gereed Digital6 PH3
//Led Bezig Digital7 PH4
//Led Magneet Digital8 PH5

#define LED_AAN_AAN PORTE |= (1 << 4)
#define LED_AAN_UIT PORTE &= ~(1 << 4)

#define LED_NOODSTOP_AAN PORTE |= (1 <<5)
#define LED_NOODSTOP_UIT PORTE &= ~(1 << 5)

#define LED_INPUT_X_AAN PORTG |= (1 <<5)
#define LED_INPUT_X_UIT PORTG &= ~(1 << 5)

#define LED_INPUT_Y_AAN PORTE |= (1 <<3)
#define LED_INPUT_Y_UIT PORTE &= ~(1 << 3)

#define LED_GEREED_AAN PORTH |= (1 <<3)
#define LED_GEREED_UIT PORTH &= ~(1 << 3)

#define LED_BEZIG_AAN PORTH |= (1 <<4)
#define LED_BEZIG_UIT PORTH &= ~(1 << 4)

#define LED_MAGNEET_AAN PORTH |= (1 <<5)
#define LED_MAGNEET_UIT PORTH &= ~(1 << 5)

void init_leds(){
    //zet output
    DDRE |= ((1 << 3) | (1<< 4) | (1 << 5));
    DDRG |= (1 << 5);
    DDRH |= ((1 << 3) | (1 << 4) | (1 << 5));
}
