ISR(INT0_vect){
    check_noodstop();
    check_rotoencoders();
}

void init_interrupt(){
    EIMSK |= (1 << INT0);

    sei();
}
