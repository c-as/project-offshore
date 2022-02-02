//RPWM PH6 Digital9 //motor 0 motor z-as
//LPWM PF5 Analog5

//IN1 Digital39 PG2 //motor 1 motor y-as
//IN2 Digital40 PG1

//IN3 Digital41 PG0 //motor 2 motor x-as
//IN4 Digital42 PL7


enum {MOTOR_X, MOTOR_Y, MOTOR_Z};

void alle_motors_uit(){
    PORTH &= ~(1 << 6);
	PORTF &= ~(1 << 5);
	PORTG &= ~((1 << 2) | (1 << 1) | (1 << 0));
	PORTL &= ~(1 << 7);
}

void init_motors(){
    DDRH |= (1 << 6);
	DDRF |= (1 << 5);
	DDRG |= (1 << 2) | (1 << 1) | (1 << 0);
	DDRL |= (1 << 7);

	alle_motors_uit();
}

void zet_motor(int motor, bool richting){
    alle_motors_uit();

    if(motor == MOTOR_Y){
        if(richting){
            PORTG |= (1 << 0);
        } else {
            PORTL |= (1 << 7);
        }
    }
    else if(motor == MOTOR_X){
        if(richting){
            PORTG |= (1 << 2);
        } else {
            PORTG |= (1 << 1);
        }
    }
    else if(motor == MOTOR_Z){
        if(richting){
            PORTF |= (1 << 5);
        } else {
            PORTH |= (1 << 6);
        }
    }
}
