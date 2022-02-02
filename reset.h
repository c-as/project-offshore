//reset functie

//Led Bezig Digital7 PH4

void reset()
{
    zet_motor(MOTOR_Z, false);

    LED_AAN_AAN;

    while(1)
    {
        if(Z_AS_END_SWITCH_BOVEN_INGEDRUKT)
        {
            break;
        }
    }

    LED_MAGNEET_AAN;

    alle_motors_uit();

    zet_motor(MOTOR_Y, false);

    rotoencoder_clock_x = 0;

    while(1)
    {
        if(Y_AS_END_SWITCH_INGEDRUKT)
        {

            break;
        }
    }

    alle_motors_uit();

    LED_INPUT_Y_AAN;

    zet_motor(MOTOR_X, false);

    while(1)
    {
        if(X_AS_END_SWITCH_INGEDRUKT)
        {
            break;
        }
    }

    LED_INPUT_X_AAN;

    alle_motors_uit();

    LED_GEREED_AAN;

    rotoencoder_clock_y = 0;

    return;
}
