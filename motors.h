//motor code

ISR(TIMER0_OVF_vect)
{
	if (OCR0A == 0 && OCR0B == 0)
	{
		PORTH &= ~(1<<PH6);
		PORTF &= ~(1<<PF5);
	}
	else if (OCR0A != 0)
	{
		PORTF &= ~(1<<PF5);
		PORTH |= (1<<PH6);
	}
	else if (OCR0B != 0)
	{
		PORTH &= ~(1<<PH6);
		PORTF |= (1<<PF5);
	}
}

ISR(TIMER0_COMPA_vect)
{
	if (OCR0A != 255)
	{
		PORTH &= ~(1<<PH6);
	}
}

ISR(TIMER0_COMPB_vect)
{
	if (OCR0B != 255)
	{
		PORTF &= ~(1<<PF5);
	}
}

void init_motors(){
    //output
	DDRH |= (1<<PH6);
	DDRF |= (1<<PF5);

	//laag
	PORTH &= ~(1<<PH6);
	PORTF &= ~(1<<PF5);

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

void zet_motor(int percentage)
{
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

