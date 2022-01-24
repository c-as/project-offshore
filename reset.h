//reset functie

//Led Bezig Digital7 PH4

void reset()
{
    zet_motor(100, MOTOR_Z);

    LED_AAN_AAN;

    while(1)
    {
        if(Z_AS_END_SWITCH_BOVEN_INGEDRUKT)
        {
            break;
        }
    }

    LED_MAGNEET_AAN;

    zet_motor(100, MOTOR_X);

    zet_motor(100, MOTOR_X);

    while(1)
    {
        if(X_AS_END_SWITCH_INGEDRUKT)
        {
            break;
        }
    }

    LED_BEZIG_AAN;

    zet_motor(0, MOTOR_X);

    zet_motor(100, MOTOR_Y);

    rotoencoder_clock_x = 0;

    while(1)
    {
        if(Y_AS_END_SWITCH_INGEDRUKT)
        {

            break;
        }
    }

    LED_GEREED_AAN;

    zet_motor(0, MOTOR_Y);

    rotoencoder_clock_y = 0;


    return;
}
