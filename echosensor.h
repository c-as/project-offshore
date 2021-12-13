//pin trig PE3 Digital5
//pin echo PG5 Digital4

#define TRIG_HOOG PORTE |= (1 << 3)
#define TRIG_LAAG PORTE &= ~(1 << 3)
#define ECHO_HOOG PING & (1 << 5)

int echosensor_ticks = 0;
int echosensor_mm = 0;
int echosensor_us = 0;
int timer1_beginwaarde = 63936;

ISR(TIMER1_OVF_vect){
    static int ticks = 0;
    static bool uitgezonden = false;
    static bool echo = false;
    if(uitgezonden){
        if(ECHO_HOOG){
            if(echo){
                ticks++;
            } else {
                echo = true;
            }
        } else {
            if (echo){
                uitgezonden = false;
                echo = false;
                echosensor_us = ticks * 100;
                echosensor_mm = echosensor_us / 6;
                echosensor_ticks = ticks;
                ticks = 0;
            }
        }
    } else {
        TRIG_LAAG;
        _delay_us(5);
        TRIG_HOOG;
        _delay_us(10);
        TRIG_LAAG;
        uitgezonden = true;
    }

	TCNT1 = timer1_beginwaarde;
}

void init_echosensor(){
    cli();
    DDRE |= (1 << 3);
    DDRG &= ~(1 << 5);

    //timer 1 16 bit
    //zet beginwaarde
    TCNT1 = timer1_beginwaarde;
    //mode 0
	TCCR1A = 0;
	//div 64
	TCCR1B = (0<<CS02) | (1<<CS01) | (1<<CS00);
    //enable overflow interrupt
	TIMSK1 = (1<<TOIE0);
	sei();
}
