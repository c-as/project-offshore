
//beweeg naar positie

void beweeg_naar_positie(struct coordinaat coord)
{
    if(coord.x > rotoencoder_clock_x){
        zet_motor(100, MOTOR_X);
    } else {
        zet_motor(-100, MOTOR_X);
    }

    while(1)
    {
        if(rotoencoder_clock_x == coord.x) //x rotoencoder positie gelijk aan doel x positie
        {
            zet_motor(0, MOTOR_X);
            break;
        }
    }

    if(coord.y > rotoencoder_clock_y){
        zet_motor(100, MOTOR_Y);
    } else {
        zet_motor(-100, MOTOR_Y);
    }

    while(1)
    {
        if(rotoencoder_clock_y == coord.y) //y rotoencoder positie gelijk aan doel y positie
        {
            zet_motor(0, MOTOR_Y);
            break;
        }
    }
}

