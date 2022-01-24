//reset functie

//Led Bezig Digital7 PH4

void reset()
{
    LED_BEZIG_AAN;

    zet_motor(100, MOTOR_Z);

    while(1)
    {
        if(Z_AS_END_SWITCH_BOVEN_INGEDRUKT)
        {
            zet_motor(0, MOTOR_Z);

            zet_motor(100, MOTOR_X);
            break;
        }
    }

    while(1)
    {
        if(X_AS_END_SWITCH_INGEDRUKT)
        {
            zet_motor(0, MOTOR_X);

            zet_motor(100, MOTOR_Y);

            rotoencoder_clock_x = 0;
            break;
        }
    }

    while(1)
    {
        if(Y_AS_END_SWITCH_INGEDRUKT)
        {
            zet_motor(0, MOTOR_Y);

            rotoencoder_clock_y = 0;
            break;
        }
    }
    return 0;
}
