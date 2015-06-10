/*******************************************************************************
/
/   Filename:   ksz8895.c
/
*******************************************************************************/

#include <xc.h>
#include "tcpip/tcpip.h"
#include "ksz8895.h"
#include "softspi.h"


//==============================================================================

int KSZ8895Init()
{
    uint8_t readData;

    // Read chip family ID to verify SPI bus functionality. ---------
    do {
        // Read contents of register 0x00.
        while (KSZ8895ReadReg(0x00, &readData) != 0);
    }
    while (readData != 0x95);

    // Write/Read/Verify the start switch bit. ----------------------
    do {
        // Write "Start Switch" bit to register 0x01.
        while (KSZ8895WriteReg(0x01, 0x01) != 0);
        // Read contents of register 0x01.
        while (KSZ8895ReadReg(0x01, &readData) != 0);
    }
    while ((readData & 0x01) != 0x01);   // Verify "Start Switch" bit is set.

    return 0;
}

//==============================================================================

int KSZ8895ReadReg(uint8_t address, uint8_t *data)
{
    uint32_t rxData;
    
    SOFTSPI_TRANSFER readCmd =
    {
        .dev = SOFTSPI_KSZ8895,
        .txDat = 0x00030000 | (((uint32_t)address) << 8),
        .rxBuf = &rxData,
        .numOfBits = 24,
        .freq = 50000,
    };

    if (SoftSPIXfer(&readCmd) != 0)
    {
        return -1;
    }

    // TODO: Make this function non-blocking.

    while (!readCmd.xferDone);      // Wait for transfer to complete.
    *data = rxData & 0x000000FF;

    return 0;
}

//==============================================================================

int KSZ8895WriteReg(uint8_t address, uint8_t data)
{
    SOFTSPI_TRANSFER xfer =
    {
        .dev = SOFTSPI_KSZ8895,
        .txDat = 0x00020000 | (((uint32_t)address) << 8) | data,
        .rxBuf = 0,
        .numOfBits = 24,
        .freq = 50000,
        .xferDone = 0
    };

    return SoftSPIXfer(&xfer);
}

//==============================================================================

void KSZ8895Reset()
{
    LATDbits.LATD5 = 0;     // Low
    DelayMs(100);           // Allow time for capacitive load to switch.
    LATDbits.LATD5 = 1;     // High
    DelayMs(300);           // Allow time for switch to power up.
}

