//1     E       Digital44   PL5
//2     D       Digital45   PL4
//3     DP      Digital46   PL3
//4     C       Digital47   PL2
//5     G       Digital48   PL1
//6     DIG4    Digital49   PL0
//7     B       Digital50   PB3
//8     DIG3    Digital51   PB2
//9     DIG2    Digital52   PB1
//10    F       Digital53   PB0
//11    A       Analog15    PK7
//12    DIG1    Analog14    PK6

static unsigned int segmentcodes[] = {
	0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6
};

void init_segment_display(){
    //zet digits input
    DDRL &= ~(1 << 0);
    DDRB &= ~((1 << 1) | (1 << 2));
    DDRK &= ~(1 << 6);

    //zet segments output
    DDRL |= ((1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5));
    DDRB |= ((1 << 0) | (1 << 3));
    DDRK |= (1 << 7);

    //reset segments
    PORTL &= ~((1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5));
    PORTB &= ~((1 << 0) | (1 << 3));
    PORTK &= ~(1 << 7);
}

void segment_display(char data, int digit){
    //zet digit naar output
    switch(digit){
    case 0:
        DDRK |= (1 << 6);
        break;
    case 1:
        DDRB |= (1 << 1);
        break;
    case 2:
        DDRB |= (1 << 2);
        break;
    case 3:
        DDRL |= (1 << 0);
        break;
    }

    //zet segments
    //a
    PORTK |= (1 << 7) & data;
    //b
    PORTB |= (1 << 3) & data;
    //c
    PORTL |= (1 << 2) & data;
    //d
    PORTL |= (1 << 4) & data;
    //e
    PORTL |= (1 << 5) & data;
    //f
    PORTB |= (1 << 0) & data;
    //g
    PORTL |= (1 << 1) & data;
    //dp
    PORTL |= (1 << 3) & data;

    _delay_us(1);

    //reset digits
    DDRL &= ~(1 << 0);
    DDRB &= ~((1 << 1) | (1 << 2));
    DDRK &= ~(1 << 6);

    //reset segments
    PORTL &= ~((1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5));
    PORTB &= ~((1 << 0) | (1 << 3));
    PORTK &= ~(1 << 7);
}

void segment_display_getal(unsigned int getal)
{
	for (int i = 0; i < 4; i++)
	{
		segment_display(segmentcodes[getal%10], i);
		getal /= 10;
	}
}
