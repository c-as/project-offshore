void verplaats_ton(){
    struct coordinaat locatie_1 = input_coordinaat();

    beweeg_naar_positie(locatie_1);

    //pak ton
    zet_motor(-100, MOTOR_Z);

    while(1){
        if(Z_AS_END_SWITCH_ONDER_INGEDRUKT){
            break;
        }
    }

    zet_motor(0, MOTOR_Z);

    LED_MAGNEET_AAN;
    MAGNEET_AAN;

    _delay_ms(100);

    zet_motor(100, MOTOR_Z);

    while(1){
        if(Z_AS_END_SWITCH_BOVEN_INGEDRUKT){
            break;
        }
    }

    zet_motor(0, MOTOR_Z);

    struct coordinaat locatie_2 = input_coordinaat();

    beweeg_naar_positie(locatie_2);

    //zet ton neer
    zet_motor(-100, MOTOR_Z);

    _delay_ms(2000);

    zet_motor(0, MOTOR_Z);

    LED_MAGNEET_UIT;
    MAGNEET_UIT;

    _delay_ms(100);

    zet_motor(100, MOTOR_Z);

    while(1){
        if(Z_AS_END_SWITCH_BOVEN_INGEDRUKT){
            break;
        }
    }

    return;
}
