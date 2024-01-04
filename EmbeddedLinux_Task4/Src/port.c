#include "AVR_reg.h"
#include "bit_math.h"
#include "portCfg.h"
#include "port.h"

#define concat(p7,p6,p5,p4,p3,p2,p1,p0)     helper(p7,p6,p5,p4,p3,p2,p1,p0)
#define helper(p7,p6,p5,p4,p3,p2,p1,p0)     0b##p7##p6##p5##p4##p3##p2##p1##p0    

#if(CONFIGURATION_STYLE == PRE_COMPILE)
    
    Port_enumError_t portInit(void) {
        Port_enumError_t errorStatus = port_enumNotOk;
        
    #if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        errorStatus = port_enumNotOk;
        *DDRA_REG = concat(PA7_DIRECTION,PA6_DIRECTION,PA5_DIRECTION,PA4_DIRECTION,PA3_DIRECTION,PA2_DIRECTION,PA1_DIRECTION,PA0_DIRECTION);
        *PORTA_REG = concat(PA7_STATE,PA6_STATE,PA5_STATE,PA4_STATE,PA3_STATE,PA2_STATE,PA1_STATE,PA0_STATE);
        errorStatus = port_enumOk;
    #elif
        #error "wrong port num"
    #endif

    #if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        errorStatus = port_enumNotOk;
        *DDRB_REG = concat(PB7_DIRECTION,PB6_DIRECTION,PB5_DIRECTION,PB4_DIRECTION,PB3_DIRECTION,PB2_DIRECTION,PB1_DIRECTION,PB0_DIRECTION);
        *PORTB_REG = concat(PB7_STATE,PB6_STATE,PB5_STATE,PB4_STATE,PB3_STATE,PB2_STATE,PB1_STATE,PB0_STATE);
        errorStatus = port_enumOk;
    #endif

    #if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
        errorStatus = port_enumNotOk;
        *DDRC_REG = concat(PC7_DIRECTION,PC6_DIRECTION,PC5_DIRECTION,PC4_DIRECTION,PC3_DIRECTION,PC2_DIRECTION,PC1_DIRECTION,PC0_DIRECTION);
        *PORTC_REG = concat(PC7_STATE,PC6_STATE,PC5_STATE,PC4_STATE,PC3_STATE,PC2_STATE,PC1_STATE,PC0_STATE);
        errorStatus = port_enumOk;
    #endif

    #if (PORTS_NUM == PORTS_A_B_C_D)
        errorStatus = port_enumNotOk;
        *DDRD_REG = concat(PD7_DIRECTION,PD6_DIRECTION,PD5_DIRECTION,PD4_DIRECTION,PD3_DIRECTION,PD2_DIRECTION,PD1_DIRECTION,PD0_DIRECTION);
        *PORTD_REG = concat(PD7_STATE,PD6_STATE,PD5_STATE,PD4_STATE,PD3_STATE,PD2_STATE,PD1_STATE,PD0_STATE);
        errorStatus = port_enumOk;
    #endif
        return errorStatus;
    }

#elif(CONFIGURATION_STYLE == POST_COMPILE)
    
    pinConfigStruct_t portConfigArr [PORTS_NUM][8];

    Port_enumError_t portInit(void) {
        Port_enumError_t errorStatus = port_enumNotOk;
        volatile u8 *DDR_regPtr = NULL, *PORT_regPtr = NULL;
        for(u8 port = port_enumPortA; port < PORTS_NUM; port++) {
            switch(port) {
    #if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
                case port_enumPortA:
                    DDR_regPtr = DDRA_REG;
                    PORT_regPtr = PORTA_REG;
                break;
    #endif
    #if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
                case port_enumPortB:
                    DDR_regPtr = DDRB_REG;
                    PORT_regPtr = PORTB_REG;
                break;
    #endif
    #if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
                case port_enumPortC:
                    DDR_regPtr = DDRC_REG;
                    PORT_regPtr = PORTC_REG;
                break;
    #endif
    #if (PORTS_NUM == PORTS_A_B_C_D)
                case port_enumPortD:
                    DDR_regPtr = DDRD_REG;
                    PORT_regPtr = PORTD_REG;
                break;
    #endif
                default:
                    errorStatus = port_enumWrongPort;
            }
            if((DDR_regPtr == NULL) || (PORT_regPtr == NULL)){
			    errorStatus = port_enumWrongPort;
		    }
		    else {
                for(u8 pin = port_enumP0; pin <= port_enumP7; pin++) {
                    switch(portConfigArr[port][pin].pinConfig) {
                        case pin_enumOutput:
                            SET_BIT(*DDR_regPtr,pin);
                            break;
                        case pin_enumInput:
                            CLR_BIT(*DDR_regPtr,pin);
                            break;
                    }
                    switch(portConfigArr[port][pin].pinState) {
                        case pin_enumOutput:
                            SET_BIT(*PORT_regPtr,pin);
                            break;
                        case pin_enumInput:
                            CLR_BIT(*PORT_regPtr,pin);
                            break;
                    }                
                }
                errorStatus = port_enumOk;
            }
        }
        return errorStatus;
    }
#endif

