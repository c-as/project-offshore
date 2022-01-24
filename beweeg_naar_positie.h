
//beweeg naar positie

void beweeg_naar_positie()
{
    zet_motor(100, MOTOR_X);

    while(1)
    {
        if(1) //x rotoencoder positie gelijk aan doel x positie
        {
            zet_motor(0, MOTOR_X);
            break;
        }
    }

    zet_motor(100, MOTOR_Y);

    while(1)
    {
        if(1) //y rotoencoder positie gelijk aan doel y positie
        {
            zet_motor(100, MOTOR_Y);
            break;
        }
    )
}

