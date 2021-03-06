//motor code

//RPWM PH6 Digital9 //motor 0 motor z-as
//LPWM PF5 Analog5

//IN1 Digital39 PG2 //motor 1 motor y-as
//IN2 Digital40 PG1

//IN3 Digital41 PG0 //motor 2 motor x-as
//IN4 Digital42 PL7


volatile int actieve_motor = -1;

//enum {MOTOR_Z, MOTOR_Y, MOTOR_X};

ISR(TIMER0_OVF_vect)
{
	if (OCR0A == 0 && OCR0B == 0)
	{
		PORTH &= ~(1 << 6);
        PORTF &= ~(1 << 5);
        PORTG &= ~((1 << 2) | (1 << 1) | (1 << 0));
        PORTL &= ~(1 << 7);
	}
	else if (OCR0A != 0)
	{
        if(actieve_motor == 0){
            PORTH |= (1 << 6);
            PORTF &= ~(1 << 5);

        }
        if(actieve_motor == 1){
            PORTG |= (1 << 2);
            PORTG &= ~(1 << 1);
        }
        if(actieve_motor == 2){
            PORTG |= (1 << 0);
            PORTL &= ~(1 << 7);
        }


	}
	else if (OCR0B != 0)
	{
        if(actieve_motor == 0){
            PORTH &= (1 << 6);
            PORTF |= ~(1 << 5);

        }
        if(actieve_motor  == 1){
            PORTG &= (1 << 2);
            PORTG |= ~(1 << 1);
        }
        if(actieve_motor == 2){
            PORTG &= (1 << 0);
            PORTL |= ~(1 << 7);
	    }
	}
}

ISR(TIMER0_COMPA_vect)
{
	if (OCR0A != 255)
	{
		PORTH &= ~(1 << 6);
        PORTG &= ~((1 << 2) | (1 << 0));
	}
}

ISR(TIMER0_COMPB_vect)
{
	if (OCR0B != 255)
	{
        PORTF &= ~(1 << 5);
        PORTG &= ~(1 << 1);
        PORTL &= ~(1 << 7);
	}
}

void init_motors(){
    //output
	DDRH |= (1 << 6);
	DDRF |= (1 << 5);
	DDRG |= (1 << 2) | (1 << 1) | (1 << 0);
	DDRL |= (1 << 7);

	//laag
	PORTH &= ~(1 << 6);
	PORTF &= ~(1 << 5);
	PORTG &= ~((1 << 2) | (1 << 1) | (1 << 0));
	PORTL &= ~(1 << 7);

	//mode 0
	TCCR0A = 0;
	//div 64
	TCCR0B = (0<<CS02) | (1<<CS01) | (1<<CS00);

	//reset output compare
	OCR0A = 0;
	OCR0B = 0;

	// interrupts
	TIMSK0 = (1<<OCIE0B) | (1<<OCIE0A) | (1<<TOIE0);

	sei();
}

void zet_motor(int percentage, int motor)
{
    actieve_motor = motor;

	if (percentage >= -100 && percentage <= 100)
	{

		if (percentage >= 0)
		{
			OCR0B = 0;
			OCR0A = (255*percentage)/100;
		}
		else
		{
			OCR0A = 0;
			OCR0B = (255*percentage)/-100;
			//OCR0z = 0;
		}


	}

}

