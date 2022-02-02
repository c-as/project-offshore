#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
//#include "motors.h"
#include "motors_simpel.h"
#include "schakelaars.h"
#include "rotoencoder.h"
#include "leds.h"
#include "segment_display.h"
#include "input.h"
#include "omrekenen_cm_slagen.h"
//#include "beweeg_naar_positie.h"
#include "display_shield.h"
#include "numpad.h"
#include "reset.h"
#include "noodstop.h"
#include "interrupt.h"
//#include "verplaats_ton.h"
#include "tests.h"

int main(void)
{
    init_motors();
    init_schakelaars();
    //init_rotoencoder();
    //init_display_shield(false);
    //init_segment_display();
    //init_numpad();
    init_leds();
    init_interrupt();

    //test_schakelaars();
    //test_leds();

    reset();

    return 0;
}


//cordinaat opgeven waar ton staat
//cordinaat opgeven waar ton naar toe moet
//motor x-as aansturen
//stoppen als afstandsmeter bij eerste x-coordinaat is
//y-as juist aantal keer draaien
//z-as motor aan
//z-as motor uit als drukschakelaar in ingedrukt
//elektromagneet aan

//motor y-as aan adere kant op draaien
//motor x-as draaien
//motor y-as draaien
//motor z-as draaien
//elektromagneet uit
//motor y-as draaien
