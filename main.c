#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include "motors.h"
#include "schakelaars.h"
#include "rotoencoder.h"
#include "omrekenen_cm_slagen.h"
#include "beweeg_naar_posi"
#include "display_shield.h"
#include "segment_display.h"
#include "numpad.h"
#include "leds.h"
#include "reset.h"
#include "interrupt.h"

int main(void)
{
    init_motors();
    init_schakelaars();
    init_rotoencoder();
    init_display_shield(false);
    init_segment_display();
    init_numpad();
    init_leds();
    reset();
    init_interrupt();


    while(1)
    {
        //verplaats_ton();
        //init_beweeg_naar_posi();
        //omrekening();

    }

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
