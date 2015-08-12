////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Utility functions.
////////////////////////////////////////////////////////////////////////////////

#ifndef UTIL_H_
#define	UTIL_H_

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

// Calculates the CCITT-16 CRC for the given data.
uint16_t utilCRC16( const void* data_p, uint16_t data_len, uint16_t crc_start );

#endif	// UTIL_H_