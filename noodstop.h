
void check_noodstop(){
    while(NOODSTOP_INGEDRUKT)
    {
        LED_NOODSTOP_AAN;
        //zet_motor(0, MOTOR_X);
        //zet_motor(0, MOTOR_Y);
        //zet_motor(0, MOTOR_Z);
    }
    LED_NOODSTOP_UIT;
}
