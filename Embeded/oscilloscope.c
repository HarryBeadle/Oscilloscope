#include <avr/io.h>
#include <util/delay.h>

void init_uart(void)
{
    /* Configure UART0 baud rate, one start bit, 8-bit, no parity and one stop bit */
    UBRR0H = (F_CPU/(9600*16L)-1) >> 8;
    UBRR0L = (F_CPU/(9600*16L)-1);
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);
    UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

void init_adc(void)
{
    // Enable the ADC 
    ADCSRA |= _BV(ADEN);
    // Use a prescaler of 64
    ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
    // Left adjust
    ADMUX |= _BV(ADLAR);
    return;
}

void read_adc(void)
{
    // Initialise the reading
    ADCSRA |= _BV(ADSC);
    // Wait for the reading to finish
    while ((ADCSRA & _BV(ADSC))) continue;
}

int main(void)
{
    init_uart();
    init_adc();
    while (1) {
        read_adc();
        UDR0 = ADCH;
    }
}
