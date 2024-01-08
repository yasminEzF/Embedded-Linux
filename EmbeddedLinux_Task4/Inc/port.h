#ifndef PORT_H_
#define PORT_H_

typedef enum {
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	port_enumOk = 0,
	/**
	 *@brief : NULL Pointer is passed
	 */
	port_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */
	port_enumWrongPort,
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	port_enumWrongPin,
	/**
	 *@brief : Select Configuration type Not Found .
	 */
	port_enumWrongConfig,
	/**
	 *@brief : Select pin state type Not Found .
	 */
	port_enumWrongPinState,
	/**
	 *@brief : generalized error
	 */
	port_enumNotOk

}Port_enumError_t;

Port_enumError_t portInit(void);

#endif /* PORT_H_ */

/*#if ((PORTS_NUM == PORT_A)||(PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))
            
#endif

#if ((PORTS_NUM == PORTS_A_B)||(PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))

#endif

#if ((PORTS_NUM == PORTS_A_B_C)||(PORTS_NUM == PORTS_A_B_C_D))

#endif

#if (PORTS_NUM == PORTS_A_B_C_D)

#endif
*/
