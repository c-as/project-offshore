//pin trig PA2 Digital24
//pin echo PA3 Digital25

#define TRIG_HOOG PORTA |= (1 << 2)
#define TRIG_LAAG PORTA &= ~(1 << 2)
#define ECHO_HOOG PINA & (1 << 3)

int echosensor_ticks = 0;

bool echo_last = false;
bool echo = false;
bool send = false;

ISR(INT0_vect){
    bool echo_current = ECHO_HOOG;
    if(echo_current != echo_last){
        if(echo_current && !echo){
            //begin met tellen
            TCNT1 = 0;
            echo = true;
        }
        if(!echo_current && echo){
            //stop met tellen
            echosensor_ticks = TCNT1;
            echo = false;
            send = false;
        }
        echo_last = echo_current;
    }
}

void init_echosensor(){
    DDRA |= (1 << 2);
    DDRA &= ~(1 << 3);

    EIMSK |= (1 << INT0);

    //timer 1 16 bit
    //mode 0
	TCCR1A = 0;
	//div 1024
	TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10);

	sei();
}

void check_echosensor(){
    if(send){
        return;
    }

    TRIG_LAAG;
    _delay_us(5);
    TRIG_HOOG;
    _delay_us(15);
    TRIG_LAAG;

    send = true;
}
