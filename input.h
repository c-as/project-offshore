struct coordinaat{
    int x;
    int y;
};

enum {X_AS, Y_AS};

struct coordinaat input_coordinaat(){
    LED_BEZIG_UIT;

    int geselecteerd = -1;
    struct coordinaat doel = {0, 0};
    bool gereed = false;

    while(1){
            //display getal
        switch(geselecteerd){
        case -1:
            segment_display_getal(9999);
            LED_INPUT_X_UIT;
            LED_INPUT_Y_UIT;
            break;
        case X_AS:
            LED_INPUT_X_AAN;
            LED_INPUT_Y_UIT;
            segment_display_getal(doel.x);
            break;
        case Y_AS:
            LED_INPUT_X_UIT;
            LED_INPUT_Y_AAN;
            segment_display_getal(doel.y);
            break;
        }

        if(doel.x > 0 && doel.y > 0){
            gereed = true;
            LED_GEREED_AAN;
        }

            //check voor input
        int input = krijg_input();
        if(input > -1){
            switch(input){
            case 11:
                geselecteerd = X_AS;
                break;
            case 12:
                geselecteerd = Y_AS;
                break;

            if(geselecteerd > -1){
                if(input > -1 && input < 10){
                        //nummer input
                   switch(geselecteerd){
                    case X_AS:
                        doel.x *= 10 + input;
                        break;
                    case Y_AS:
                        doel.y *= 10 + input;
                    }
                } else {
                    switch(input){
                        //anders
                    case 15://backspace
                        switch(geselecteerd){
                            case X_AS:
                                doel.x /= 10;
                                break;
                            case Y_AS:
                                doel.y /= 10;
                                break;
                        }
                    case 16: //gereed
                        if(gereed){
                            LED_INPUT_X_UIT;
                            LED_INPUT_Y_UIT;
                            LED_GEREED_UIT;
                            return doel;
                        }
                        break;

                        }
                    }
                }
            }
        }
    }
}
