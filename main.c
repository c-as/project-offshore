#include <avr/io.h>
#include <avr/io.h>s
#include <avr/interrupt.h>
#include <util/delay.h>
#include "knoppen.h"
#include "motors.h"

int main(void)
{
    init_knoppen();
    init_motors();

    while(1)
    {
        if(AAN_KNOP_INGEDRUKT)
        {

        }
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
