////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief EMC1412 Temperature Sensor driver.
////////////////////////////////////////////////////////////////////////////////

#ifndef EMC1412_H_
#define	EMC1412_H_

// *****************************************************************************
// ************************** System Include Files *****************************
// *****************************************************************************

#include <xc.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// *****************************************************************************
// ************************** User Include Files *******************************
// *****************************************************************************

// *****************************************************************************
// ************************** Defines ******************************************
// *****************************************************************************

// *****************************************************************************
// ************************** Declarations *************************************
// *****************************************************************************

// *****************************************************************************
// ************************** Function Prototypes ******************************
// *****************************************************************************

// Perform the EMC1412 Task - the internal and external temperature sensor
// value are read into module data.
void EMC1412Task( void );

// The internal temperature sensor value (LSB = 0.01 C).
int16_t EMC1412IntTempGet();

// The external temperature sensor value (LSB = 0.01 C).
int16_t EMC1412ExtTempGet();

#endif	// EMC1412_H_
