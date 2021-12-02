#include <avr/io.h>
#define AAN PF1
#define UIT PF2
#define X PF1
#define Y PF2
#define MIN PF1
#define PLUS PF1
#define START PF1
#define NOODSTOP PF2

int main(void)
{
    DDRF &= ~(1 << AAN);
    DDRF &= ~(1 << UIT);
    DDRF &= ~(1 << X);
    DDRF &= ~(1 << Y);
    DDRF &= ~(1 << X);
    DDRF &= ~(1 << Y);
    DDRF &= ~(1 << MIN);
    DDRF &= ~(1 << PLUS);
    DDRF &= ~(1 << START);
    DDRF &= ~(1 << NOODSTOP);


    // Insert code

    while(1)
    {
        if(!(PINF & (1 << AAN)))
        {

        }
    }
    ;

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
