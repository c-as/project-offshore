//voor multifunctionshield

#define SDI_HOOG PORTH |= (1 << 5)
#define SDI_LAAG PORTH &= ~(1 << 5)

#define SHIFT_HOOG PORTH |= (1 << 4)
#define SHIFT_LAAG PORTH &= ~(1 << 4)

#define LATCH_HOOG PORTG |= (1 << 5)
#define LATCH_LAAG PORTG &= ~(1 << 5)

int buffer_getal = 0;

ISR(TIMER2_OVF_vect){
    shield_display_getal(buffer_getal);
}

static unsigned int segmentcodes_shield[] = {
	~0xFC, ~0x60, ~0xDA, ~0xF2,
	~0x66, ~0xB6, ~0xBE, ~0xE0,
	~0xFE, ~0xF6, ~0xEE, ~0x3E,
	~0x9C, ~0x7A, ~0x9E, ~0x8E
};

void init_display_shield(bool gebruik_clock){
    DDRH |= (1 << 5) | (1 << 4);
    DDRG |= (1 << 5);

    SHIFT_LAAG;
    LATCH_LAAG;

    if(gebruik_clock){
        //timer 2 8 bit
        //mode 0
        TCCR2A = 0;
        //div
        TCCR2B = (1<<CS22) | (0<<CS21) | (0<<CS20);
        //enable overflow interrupt
        TIMSK2 = (1<<TOIE0);
        sei();
    }
}

void send_data(char data)
{
	for (unsigned i = 0; i < 8; i++)
	{
		int bit = data & 1;

		if (bit)
		{
			SDI_HOOG;
		}
		else
		{
			SDI_LAAG;
		}

		SHIFT_HOOG;
		SHIFT_LAAG;

		data >>= 1;
	}
}

void send_enable(int display_nummer)
{
	send_data(0x10 << display_nummer);
}

void shield_display(char data, int display_nummer)
{
	send_data(data);
	send_enable(display_nummer);

	LATCH_HOOG;
	LATCH_LAAG;
}

void shield_display_getal(unsigned int getal)
{
	for (int i = 0; i < 4; i++)
	{
		shield_display(segmentcodes_shield[getal%10], i);
		getal /= 10;
	}
}

void shield_zet_getal(unsigned int getal)
{
    buffer_getal = getal;
}
