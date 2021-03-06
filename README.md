# Simple, low-cost, USB Oscilloscope

*This is a project created for the 2016 Facebook Hackathon.*

It consists of two pieces of software, host `C++` code and embedded `AVRLibC` code.

- `C++` code connects to the micro controller, communicates the settings (including number of channels) and receives the data sent over serial.
- `C` code runs on the microcontroller collecting data from the ADC and transmitting it to the host over serial.

## Technical Details

The hosted `C++` is written using `Qt` and acts as the oscilloscope's interface. It shows:

- A graph of each of the channels
- Calculations about the signals
  - Duty Cycle
  - Frequency

It allows you to edit:

- The number of channels being sampled
  - *Note that the sample rate decreases as you add more channels as the ADC is multiplexed.*
- The volts/division
- The time base

## Why is it useful?

The oscilloscope is terrible: It has a very low sample rate. However, it is horrendously cheap, for education it would be interesting for young students to get there hands on something rather than just being made to watch a teacher demonstrate the product. 