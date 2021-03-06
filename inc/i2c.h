////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Inter-Integrated Circuit (I2C) driver.
////////////////////////////////////////////////////////////////////////////////

#ifndef I2C_H_
#define I2C_H_

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

typedef enum {
    I2C_DRV_STATUS_WAIT = 0,    // Waiting for I2C bus access.
    I2C_DRV_STATUS_BUSY,        // Transfer in progress.
    I2C_DRV_STATUS_DONE,        // Transfer complete.
    I2C_DRV_STATUS_ERROR,       // Transfer error.
} I2C_DRV_STATUS;

typedef struct {
    uint8_t         dev;        // I2C bus target device, address dependent.
    uint32_t        freq;       // I2C clock frequency.
    uint8_t         rw;         // 0 = Write, 1 = Read
    uint8_t         addr;       // I2C register address.
    uint8_t         numBytes;   // Number of bytes to write/read.
    uint8_t         *buf;       // Pointer to transmit/receive buffer.
    I2C_DRV_STATUS  *status;    // Pointer to status flag.
} I2C_TRANSFER;

// *****************************************************************************
// ************************** Declarations *************************************
// *****************************************************************************

// *****************************************************************************
// ************************** Function Prototypes ******************************
// *****************************************************************************

////////////////////////////////////////////////////////////////////////////////
/// @brief  Queue an I2C transfer (read or write).
///
/// @param  xfer
///             Pointer to control and communication data.
///
/// @return Identification of transfer queue success.
///             -1 - \p xfer data is invalid.
///             0  - I2C transfer already in progress.
///             1  - Queue of I2C transfer successful.
///
/// This function queues I2C data for transfer.  The calling function must not
/// modify data reference by \p xfer until the transfer is complete.  Transfer
/// completion can be identified by the calling function by inspecting
/// \p xfer->status.  A value of \e DONE or \e ERROR identifies transfer
/// completion.
////////////////////////////////////////////////////////////////////////////////
int16_t I2CXfer( I2C_TRANSFER *xfer );

#endif  // I2C_H_



