void test_leds(){
    alle_leds_aan();
}

void test_schakelaars(){
    while(1){
        alle_leds_uit();
        if(X_AS_END_SWITCH_INGEDRUKT) LED_AAN_AAN;
        if(Y_AS_END_SWITCH_INGEDRUKT) LED_NOODSTOP_AAN;
        if(Z_AS_END_SWITCH_BOVEN_INGEDRUKT) LED_INPUT_X_AAN;
        if(Z_AS_END_SWITCH_ONDER_INGEDRUKT) LED_INPUT_Y_AAN;
    }
}
