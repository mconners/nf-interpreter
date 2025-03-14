//
// Copyright (c) .NET Foundation and Contributors
// Portions Copyright (c) Microsoft Corporation.  All rights reserved.
// See LICENSE file in the project root for full license information.
//

#ifndef DRIVERS_GPIO_DECL_H
#define DRIVERS_GPIO_DECL_H

#if defined(__GNUC__)
#define __int64 long long
#endif
typedef unsigned __int64 CLR_UINT64;

#define GPIO_PIN_NONE 0xFFFFFFFF

#define GPIO_ATTRIBUTE_NONE        0x00
#define GPIO_ATTRIBUTE_INPUT       0x01
#define GPIO_ATTRIBUTE_OUTPUT      0x02
#define GPIO_ATTRIBUTE_ALTERNATE_A 0x04
#define GPIO_ATTRIBUTE_ALTERNATE_B 0x08

// from declaration at src\Windows.Devices.Gpio\win_dev_gpio_native.h
typedef enum __nfpack GpioPinDriveMode
{
    GpioPinDriveMode_Input = 0,
    GpioPinDriveMode_InputPullDown = 1,
    GpioPinDriveMode_InputPullUp = 2,
    GpioPinDriveMode_Output = 3,
    GpioPinDriveMode_OutputOpenDrain = 4,
    GpioPinDriveMode_OutputOpenDrainPullUp = 5,
    GpioPinDriveMode_OutputOpenSource = 6,
    GpioPinDriveMode_OutputOpenSourcePullDown = 7,
} GpioPinDriveMode;

// from declaration at src\Windows.Devices.Gpio\win_dev_gpio_native.h
// TODO replace GpioPinDriveMode with this one when Windows.Devices.Gpio is removed
// typedef enum __nfpack PinMode
// {
//     PinMode_Input = 0,
//     PinMode_InputPullDown = 1,
//     PinMode_InputPullUp = 2,
//     PinMode_Output = 3,
//     PinMode_OutputOpenDrain = 4,
//     PinMode_OutputOpenDrainPullUp = 5,
//     PinMode_OutputOpenSource = 6,
//     PinMode_OutputOpenSourcePullDown = 7,
// } PinMode;

// from declaration at src\Windows.Devices.Gpio\win_dev_gpio_native.h
typedef enum __nfpack GpioPinValue
{
    GpioPinValue_Low = 0,
    GpioPinValue_High = 1,
} GpioPinValue;

enum GPIO_INT_EDGE
{
    GPIO_INT_NONE = 0,
    GPIO_INT_EDGE_LOW = 1,
    GPIO_INT_EDGE_HIGH = 2,
    GPIO_INT_EDGE_BOTH = 3,
    GPIO_INT_LEVEL_HIGH = 4,
    GPIO_INT_LEVEL_LOW = 5
};

// struct GPIO_FLAG_RESISTOR
// {
//     GPIO_PIN      Pin;
//     bool          ActiveState;
//     GPIO_RESISTOR Resistor;
// };

typedef void (*GPIO_INTERRUPT_SERVICE_ROUTINE)(GPIO_PIN pin, bool pinState, void *pArg);

bool CPU_GPIO_Initialize();
bool CPU_GPIO_Uninitialize();

void CPU_GPIO_DisablePin(GPIO_PIN Pin, GpioPinDriveMode driveMode, uint32_t alternateFunction);

//
// CPU_GPIO_EnableOutputPin
//
// Parameters :-
//
// Pin
//   The number of the input pin to be enabled.
// InitialState
//   Inial value of pin
// GpioPinDriveMode
//   Pin resistor driver mode
//
// Return Value
//   true if the specified pin was successfully enabled as output; otherwise, false.
//
bool CPU_GPIO_EnableOutputPin(GPIO_PIN Pin, GpioPinValue InitialState, GpioPinDriveMode driveMode);

//
// CPU_GPIO_EnableInputPin
//
// Parameters :-
//
// pinNumber
//   The number of the input pin to be enabled.
// Debounce milisecs
//   A value you can set to greater than 0 to enable glitch filtering (debouncing) for the number of millissecs
// pin_ISR
//   A pointer to a function that is called when an interrupt is generated.
// PIN_isr_Param
//   A programmer-defined parameter that is passed to the assigned interrupt service routine (ISR).
// intEdge
//   A value that indicates the transition edge or state on which the interrupt is called.
// driveMode
//   A value that specifies the resistor state to be used for the enabled pin, must be a valid input drive mode.
// Return Value
//   true if the specified pin was successfully enabled; otherwise, false.
//
bool CPU_GPIO_EnableInputPin(
    GPIO_PIN pinNumber,
    CLR_UINT64 debounceTimeMilliseconds,
    GPIO_INTERRUPT_SERVICE_ROUTINE pin_ISR,
    void *isr_Param,
    GPIO_INT_EDGE intEdge,
    GpioPinDriveMode driveMode);

//  Return current gpio pin state
GpioPinValue CPU_GPIO_GetPinState(GPIO_PIN Pin);

//  Set state of output gpio pin
void CPU_GPIO_SetPinState(GPIO_PIN Pin, GpioPinValue PinState);

//
// CPU_GPIO_TogglePinState
//
// Parameters :-
//
// pinNumber
//   The number of the output pin for which the state is to be toggled.
// Return Value
//
void CPU_GPIO_TogglePinState(GPIO_PIN pinNumber);

//  Check if pin is already reserved
//  Returns true if pin is already reserved
bool CPU_GPIO_PinIsBusy(GPIO_PIN Pin);

//  Reserved or Unreserve gpio pin
//  if clearing reserve always return true
//  If reserving pin then return false if already reserved
bool CPU_GPIO_ReservePin(GPIO_PIN Pin, bool fReserve);

//  Return count of gpio pins avaiable
int32_t CPU_GPIO_GetPinCount();

// Get / Set the pin debounce time in millisecs
uint32_t CPU_GPIO_GetPinDebounce(GPIO_PIN Pin);
bool CPU_GPIO_SetPinDebounce(GPIO_PIN pinNumber, CLR_UINT64 debounceTimeMilliseconds);

// Validate pin and set drive mode
// return true if pin ok
bool CPU_GPIO_SetDriveMode(GPIO_PIN pinNumber, GpioPinDriveMode driveMode);

// Check if drive mode supported
// return true if drive mode supported
bool CPU_GPIO_DriveModeSupported(GPIO_PIN pinNumber, GpioPinDriveMode driveMode);

//  ==== Not implemented/used ====
// Retrieves an array containing the attributes of all the GPIO pins.
// void   CPU_GPIO_GetPinsMap(uint8_t* pins, size_t size);

// Retrieves the resistor modes supported by a designated GPIO pin.
// uint8_t  CPU_GPIO_GetSupportedResistorModes(GPIO_PIN pin);

// Retrieves the interrupt edge modes supported by a designated GPIO pin.
// uint8_t  CPU_GPIO_GetSupportedInterruptModes(GPIO_PIN pin);

// Retrieves the GPIO attributes of a specified pin. ( none=0, input=1, output=2, altA=4, altB=8 etc )
// uint32_t CPU_GPIO_Attributes(GPIO_PIN Pin);

#endif // DRIVERS_GPIO_DECL_H
