#ifndef M328P_H
#define M328P_H

#include <stdint.h>

#define SYSCLK_DIV1   0
#define SYSCLK_DIV2   1
#define SYSCLK_DIV4   2
#define SYSCLK_DIV8   3
#define SYSCLK_DIV16  4
#define SYSCLK_DIV32  5
#define SYSCLK_DIV64  6
#define SYSCLK_DIV128 7
#define SYSCLK_DIV256 8

#define SET_SYSCLK(log2_of_prescalar) __asm__(      \
        "ldi r30, 0x61\n"                           \
        "ldi r31, 0x00\n"                           \
        "ldi r18, 0x80\n"                           \
        "st Z, r18\n"                               \
        "st Z, %0\n"                                \
        :                                           \
        : "r" ((uint8_t)log2_of_prescalar)          \
        : "r30", "r31", "r18");


// *********** REGISTERS ************

#define MEM(A) *((volatile uint8_t*)A)

#define PINB    MEM(0x23)
#define DDRB    MEM(0x24)
#define PORTB   MEM(0x25)
#define PINC    MEM(0x26)
#define DDRC    MEM(0x27)
#define PORTC   MEM(0x28)
#define PIND    MEM(0x29)
#define DDRD    MEM(0x2A)
#define PORTD   MEM(0x2B)
#define TIFR0   MEM(0x35)
#define TIFR1   MEM(0x36)
#define TIFR2   MEM(0x37)
#define PCIFR   MEM(0x3B)
#define EIFR    MEM(0x3C)
#define EIMSK   MEM(0x3D)
#define GPIOR0  MEM(0x3E)
#define EECR    MEM(0x3F)
#define EEDR    MEM(0x40)
#define EEARL   MEM(0x41)
#define EEARH   MEM(0x42)
#define GTCCR   MEM(0x43)
#define TCCR0A  MEM(0x44)
#define TCCR0B  MEM(0x45)
#define TCNT0   MEM(0x46)
#define OCR0A   MEM(0x47)
#define OCR0B   MEM(0x48)
#define GPIOR1  MEM(0x4A)
#define GPIOR2  MEM(0x4B)
#define SPCR    MEM(0x4C)
#define SPSR    MEM(0x4D)
#define SPDR    MEM(0x4E)
#define ACSR    MEM(0x50)
#define SMCR    MEM(0x53)
#define MCUSR   MEM(0x54)
#define MCUCR   MEM(0x55)
#define SPMCSR  MEM(0x57)
#define SPL     MEM(0x5D)
#define SPH     MEM(0x5E)
#define SREG    MEM(0x5F)
#define WDTCSR  MEM(0x60)
#define CLKPR   MEM(0x61)
#define PRR     MEM(0x64)
#define OSCCAL  MEM(0x66)
#define PCICR   MEM(0x68)
#define EICRA   MEM(0x69)
#define PCMSK0  MEM(0x6B)
#define PCMSK1  MEM(0x6C)
#define PCMSK2  MEM(0x6D)
#define TIMSK0  MEM(0x6E)
#define TIMSK1  MEM(0x6F)
#define TIMSK2  MEM(0x70)
#define ADCL    MEM(0x78)
#define ADCH    MEM(0x79)
#define ADCSRA  MEM(0x7A)
#define ADCSRB  MEM(0x7B)
#define ADMUX   MEM(0x7C)
#define DIDR0   MEM(0x7E)
#define DIDR1   MEM(0x7F)
#define TCCR1A  MEM(0x80)
#define TCCR1B  MEM(0x81)
#define TCCR1C  MEM(0x82)
#define TCNT1L  MEM(0x84)
#define TCNT1H  MEM(0x85)
#define ICR1L   MEM(0x86)
#define ICR1H   MEM(0x87)
#define OCR1AL  MEM(0x88)
#define OCR1AH  MEM(0x89)
#define OCR1BL  MEM(0x8A)
#define OCR1BH  MEM(0x8B)
#define TCCR2A  MEM(0xB0)
#define TCCR2B  MEM(0xB1)
#define TCNT2   MEM(0xB2)
#define OCR2A   MEM(0xB3)
#define OCR2B   MEM(0xB4)
#define ASSR    MEM(0xB6)
#define TWBR    MEM(0xB8)
#define TWSR    MEM(0xB9)
#define TWAR    MEM(0xBA)
#define TWDR    MEM(0xBB)
#define TWCR    MEM(0xBC)
#define TWAMR   MEM(0xBD)
#define UCSR0A  MEM(0xC0)
#define UCSR0B  MEM(0xC1)
#define UCSR0C  MEM(0xC2)
#define UBRR0L  MEM(0xC4)
#define UBRR0H  MEM(0xC5)
#define UDR0    MEM(0xC6)


// ******* BIT DEFINITIONS *******

#define PINB0 (1 << 0)
#define PINB1 (1 << 1)
#define PINB2 (1 << 2)
#define PINB3 (1 << 3)
#define PINB4 (1 << 4)
#define PINB5 (1 << 5)
#define PINB6 (1 << 6)
#define PINB7 (1 << 7)

#define DDB0 (1 << 0)
#define DDB1 (1 << 1)
#define DDB2 (1 << 2)
#define DDB3 (1 << 3)
#define DDB4 (1 << 4)
#define DDB5 (1 << 5)
#define DDB6 (1 << 6)
#define DDB7 (1 << 7)

#define PORTB0 (1 << 0)
#define PORTB1 (1 << 1)
#define PORTB2 (1 << 2)
#define PORTB3 (1 << 3)
#define PORTB4 (1 << 4)
#define PORTB5 (1 << 5)
#define PORTB6 (1 << 6)
#define PORTB7 (1 << 7)

#define PINC0 (1 << 0)
#define PINC1 (1 << 1)
#define PINC2 (1 << 2)
#define PINC3 (1 << 3)
#define PINC4 (1 << 4)
#define PINC5 (1 << 5)
#define PINC6 (1 << 6)

#define DDC0 (1 << 0)
#define DDC1 (1 << 1)
#define DDC2 (1 << 2)
#define DDC3 (1 << 3)
#define DDC4 (1 << 4)
#define DDC5 (1 << 5)
#define DDC6 (1 << 6)

#define PORTC0 (1 << 0)
#define PORTC1 (1 << 1)
#define PORTC2 (1 << 2)
#define PORTC3 (1 << 3)
#define PORTC4 (1 << 4)
#define PORTC5 (1 << 5)
#define PORTC6 (1 << 6)

#define PIND0 (1 << 0)
#define PIND1 (1 << 1)
#define PIND2 (1 << 2)
#define PIND3 (1 << 3)
#define PIND4 (1 << 4)
#define PIND5 (1 << 5)
#define PIND6 (1 << 6)
#define PIND7 (1 << 7)

#define DDD0 (1 << 0)
#define DDD1 (1 << 1)
#define DDD2 (1 << 2)
#define DDD3 (1 << 3)
#define DDD4 (1 << 4)
#define DDD5 (1 << 5)
#define DDD6 (1 << 6)
#define DDD7 (1 << 7)

#define TOV0  (1 << 0)
#define OCF0A (1 << 1)
#define OCF0B (1 << 2)

#define TOV1  (1 << 0)
#define OCF1A (1 << 1)
#define OCF1B (1 << 2)
#define ICF1  (1 << 5)

#define TOV2  (1 << 0)
#define OCF2A (1 << 1)
#define OCF2B (1 << 2)

#define PCIF0 (1 << 0)
#define PCIF1 (1 << 1)
#define PCIF2 (1 << 2)

#define INTF0 (1 << 0)
#define INTF1 (1 << 1)

#define INT0 (1 << 0)
#define INT1 (1 << 1)

#define GPIOR00 (1 << 0)
#define GPIOR01 (1 << 1)
#define GPIOR02 (1 << 2)
#define GPIOR03 (1 << 3)
#define GPIOR04 (1 << 4)
#define GPIOR05 (1 << 5)
#define GPIOR06 (1 << 6)
#define GPIOR07 (1 << 7)

#define EERE  (1 << 0)
#define EEPE  (1 << 1)
#define EEMPE (1 << 2)
#define EERIE (1 << 3)
#define EEPM0 (1 << 4)
#define EEPM1 (1 << 5)

#define EEDR0 (1 << 0)
#define EEDR1 (1 << 1)
#define EEDR2 (1 << 2)
#define EEDR3 (1 << 3)
#define EEDR4 (1 << 4)
#define EEDR5 (1 << 5)
#define EEDR6 (1 << 6)
#define EEDR7 (1 << 7)

#define EEAR0 (1 << 0)
#define EEAR1 (1 << 1)
#define EEAR2 (1 << 2)
#define EEAR3 (1 << 3)
#define EEAR4 (1 << 4)
#define EEAR5 (1 << 5)
#define EEAR6 (1 << 6)
#define EEAR7 (1 << 7)


#define EEAR8 (1 << 0)
#define EEAR9 (1 << 1)

#define PSRSYNC (1 << 0)
#define PSRASY  (1 << 1)
#define TSM     (1 << 7)

#define WGM00  (1 << 0)
#define WGM01  (1 << 1)
#define COM0B0 (1 << 4)
#define COM0B1 (1 << 5)
#define COM0A0 (1 << 6)
#define COM0A1 (1 << 7)

#define CS00  (1 << 0)
#define CS01  (1 << 1)
#define CS02  (1 << 2)
#define WGM02 (1 << 3)
#define FOC0B (1 << 6)
#define FOC0A (1 << 7)

#define TCNT0_0 (1 << 0)
#define TCNT0_1 (1 << 1)
#define TCNT0_2 (1 << 2)
#define TCNT0_3 (1 << 3)
#define TCNT0_4 (1 << 4)
#define TCNT0_5 (1 << 5)
#define TCNT0_6 (1 << 6)
#define TCNT0_7 (1 << 7)

#define OCR0A_0 (1 << 0)
#define OCR0A_1 (1 << 1)
#define OCR0A_2 (1 << 2)
#define OCR0A_3 (1 << 3)
#define OCR0A_4 (1 << 4)
#define OCR0A_5 (1 << 5)
#define OCR0A_6 (1 << 6)
#define OCR0A_7 (1 << 7)

#define OCR0B_0 (1 << 0)
#define OCR0B_1 (1 << 1)
#define OCR0B_2 (1 << 2)
#define OCR0B_3 (1 << 3)
#define OCR0B_4 (1 << 4)
#define OCR0B_5 (1 << 5)
#define OCR0B_6 (1 << 6)
#define OCR0B_7 (1 << 7)

#define GPIOR10 (1 << 0)
#define GPIOR11 (1 << 1)
#define GPIOR12 (1 << 2)
#define GPIOR13 (1 << 3)
#define GPIOR14 (1 << 4)
#define GPIOR15 (1 << 5)
#define GPIOR16 (1 << 6)
#define GPIOR17 (1 << 7)

#define GPIOR20 (1 << 0)
#define GPIOR21 (1 << 1)
#define GPIOR22 (1 << 2)
#define GPIOR23 (1 << 3)
#define GPIOR24 (1 << 4)
#define GPIOR25 (1 << 5)
#define GPIOR26 (1 << 6)
#define GPIOR27 (1 << 7)

#define SPR0 (1 << 0)
#define SPR1 (1 << 1)
#define CPHA (1 << 2)
#define CPOL (1 << 3)
#define MSTR (1 << 4)
#define DORD (1 << 5)
#define SPE  (1 << 6)
#define SPIE (1 << 7)

#define SPI2X (1 << 0)
#define WCOL  (1 << 6)
#define SPIF  (1 << 7)

#define SPDR0 (1 << 0)
#define SPDR1 (1 << 1)
#define SPDR2 (1 << 2)
#define SPDR3 (1 << 3)
#define SPDR4 (1 << 4)
#define SPDR5 (1 << 5)
#define SPDR6 (1 << 6)
#define SPDR7 (1 << 7)

#define ACIS0 (1 << 0)
#define ACIS1 (1 << 1)
#define ACIC  (1 << 2)
#define ACIE  (1 << 3)
#define ACI   (1 << 4)
#define ACO   (1 << 5)
#define ACBG  (1 << 6)
#define ACD   (1 << 7)

#define SE  (1 << 0)
#define SM0 (1 << 1)
#define SM1 (1 << 2)
#define SM2 (1 << 3)

#define PORF  (1 << 0)
#define EXTRF (1 << 1)
#define BORF  (1 << 2)
#define WDRF  (1 << 3)

#define IVCE  (1 << 0)
#define IVSEL (1 << 1)
#define PUD   (1 << 4)
#define BODSE (1 << 5)
#define BODS  (1 << 6)

#define SPMEN  (1 << 0)
#define PGERS  (1 << 1)
#define PGWRT  (1 << 2)
#define BLBSET (1 << 3)
#define RWWSRE (1 << 4)
#define SIGRD  (1 << 5)
#define RWWSB  (1 << 6)
#define SPMIE  (1 << 7)

#define WDP0 (1 << 0)
#define WDP1 (1 << 1)
#define WDP2 (1 << 2)
#define WDE  (1 << 3)
#define WDCE (1 << 4)
#define WDP3 (1 << 5)
#define WDIE (1 << 6)
#define WDIF (1 << 7)

#define CLKPS0 (1 << 0)
#define CLKPS1 (1 << 1)
#define CLKPS2 (1 << 2)
#define CLKPS3 (1 << 3)
#define CLKPCE (1 << 7)

#define PRADC    (1 << 0)
#define PRUSART0 (1 << 1)
#define PRSPI    (1 << 2)
#define PRTIM1   (1 << 3)
#define PRTIM0   (1 << 5)
#define PRTIM2   (1 << 6)
#define PRTWI    (1 << 7)

#define CAL0 (1 << 0)
#define CAL1 (1 << 1)
#define CAL2 (1 << 2)
#define CAL3 (1 << 3)
#define CAL4 (1 << 4)
#define CAL5 (1 << 5)
#define CAL6 (1 << 6)
#define CAL7 (1 << 7)

#define PCIE0 (1 << 0)
#define PCIE1 (1 << 1)
#define PCIE2 (1 << 2)

#define ISC00 (1 << 0)
#define ISC01 (1 << 1)
#define ISC10 (1 << 2)
#define ISC11 (1 << 3)

#define PCINT0 (1 << 0)
#define PCINT1 (1 << 1)
#define PCINT2 (1 << 2)
#define PCINT3 (1 << 3)
#define PCINT4 (1 << 4)
#define PCINT5 (1 << 5)
#define PCINT6 (1 << 6)
#define PCINT7 (1 << 7)

#define PCINT8  (1 << 0)
#define PCINT9  (1 << 1)
#define PCINT10 (1 << 2)
#define PCINT11 (1 << 3)
#define PCINT12 (1 << 4)
#define PCINT13 (1 << 5)
#define PCINT14 (1 << 6)

#define PCINT16 (1 << 0)
#define PCINT17 (1 << 1)
#define PCINT18 (1 << 2)
#define PCINT19 (1 << 3)
#define PCINT20 (1 << 4)
#define PCINT21 (1 << 5)
#define PCINT22 (1 << 6)
#define PCINT23 (1 << 7)

#define TOIE0  (1 << 0)
#define OCIE0A (1 << 1)
#define OCIE0B (1 << 2)


#define TOIE1  (1 << 0)
#define OCIE1A (1 << 1)
#define OCIE1B (1 << 2)
#define ICIE1  (1 << 5)

#define TOIE2  (1 << 0)
#define OCIE2A (1 << 1)
#define OCIE2B (1 << 2)

#define ADCL0 (1 << 0)
#define ADCL1 (1 << 1)
#define ADCL2 (1 << 2)
#define ADCL3 (1 << 3)
#define ADCL4 (1 << 4)
#define ADCL5 (1 << 5)
#define ADCL6 (1 << 6)
#define ADCL7 (1 << 7)

#define ADCH0 (1 << 0)
#define ADCH1 (1 << 1)
#define ADCH2 (1 << 2)
#define ADCH3 (1 << 3)
#define ADCH4 (1 << 4)
#define ADCH5 (1 << 5)
#define ADCH6 (1 << 6)
#define ADCH7 (1 << 7)

#define ADPS0 (1 << 0)
#define ADPS1 (1 << 1)
#define ADPS2 (1 << 2)
#define ADIE  (1 << 3)
#define ADIF  (1 << 4)
#define ADATE (1 << 5)
#define ADSC  (1 << 6)
#define ADEN  (1 << 7)

#define ADTS0 (1 << 0)
#define ADTS1 (1 << 1)
#define ADTS2 (1 << 2)
#define ACME  (1 << 6)

#define MUX0  (1 << 0)
#define MUX1  (1 << 1)
#define MUX2  (1 << 2)
#define MUX3  (1 << 3)
#define ADLAR (1 << 5)
#define REFS0 (1 << 6)
#define REFS1 (1 << 7)

#define ADC0D (1 << 0)
#define ADC1D (1 << 1)
#define ADC2D (1 << 2)
#define ADC3D (1 << 3)
#define ADC4D (1 << 4)
#define ADC5D (1 << 5)

#define AIN0D (1 << 0)
#define AIN1D (1 << 1)

#define WGM10  (1 << 0)
#define WGM11  (1 << 1)
#define COM1B0 (1 << 4)
#define COM1B1 (1 << 5)
#define COM1A0 (1 << 6)
#define COM1A1 (1 << 7)

#define CS10  (1 << 0)
#define CS11  (1 << 1)
#define CS12  (1 << 2)
#define WGM12 (1 << 3)
#define WGM13 (1 << 4)
#define ICES1 (1 << 6)
#define ICNC1 (1 << 7)

#define FOC1B (1 << 6)
#define FOC1A (1 << 7)

#define TCNT1L0 (1 << 0)
#define TCNT1L1 (1 << 1)
#define TCNT1L2 (1 << 2)
#define TCNT1L3 (1 << 3)
#define TCNT1L4 (1 << 4)
#define TCNT1L5 (1 << 5)
#define TCNT1L6 (1 << 6)
#define TCNT1L7 (1 << 7)

#define TCNT1H0 (1 << 0)
#define TCNT1H1 (1 << 1)
#define TCNT1H2 (1 << 2)
#define TCNT1H3 (1 << 3)
#define TCNT1H4 (1 << 4)
#define TCNT1H5 (1 << 5)
#define TCNT1H6 (1 << 6)
#define TCNT1H7 (1 << 7)

#define ICR1L0 (1 << 0)
#define ICR1L1 (1 << 1)
#define ICR1L2 (1 << 2)
#define ICR1L3 (1 << 3)
#define ICR1L4 (1 << 4)
#define ICR1L5 (1 << 5)
#define ICR1L6 (1 << 6)
#define ICR1L7 (1 << 7)

#define ICR1H0 (1 << 0)
#define ICR1H1 (1 << 1)
#define ICR1H2 (1 << 2)
#define ICR1H3 (1 << 3)
#define ICR1H4 (1 << 4)
#define ICR1H5 (1 << 5)
#define ICR1H6 (1 << 6)
#define ICR1H7 (1 << 7)

#define OCR1AL0 (1 << 0)
#define OCR1AL1 (1 << 1)
#define OCR1AL2 (1 << 2)
#define OCR1AL3 (1 << 3)
#define OCR1AL4 (1 << 4)
#define OCR1AL5 (1 << 5)
#define OCR1AL6 (1 << 6)
#define OCR1AL7 (1 << 7)

#define OCR1AH0 (1 << 0)
#define OCR1AH1 (1 << 1)
#define OCR1AH2 (1 << 2)
#define OCR1AH3 (1 << 3)
#define OCR1AH4 (1 << 4)
#define OCR1AH5 (1 << 5)
#define OCR1AH6 (1 << 6)
#define OCR1AH7 (1 << 7)

#define OCR1BL0 (1 << 0)
#define OCR1BL1 (1 << 1)
#define OCR1BL2 (1 << 2)
#define OCR1BL3 (1 << 3)
#define OCR1BL4 (1 << 4)
#define OCR1BL5 (1 << 5)
#define OCR1BL6 (1 << 6)
#define OCR1BL7 (1 << 7)

#define OCR1BH0 (1 << 0)
#define OCR1BH1 (1 << 1)
#define OCR1BH2 (1 << 2)
#define OCR1BH3 (1 << 3)
#define OCR1BH4 (1 << 4)
#define OCR1BH5 (1 << 5)
#define OCR1BH6 (1 << 6)
#define OCR1BH7 (1 << 7)

#define WGM20  (1 << 0)
#define WGM21  (1 << 1)
#define COM2B0 (1 << 4)
#define COM2B1 (1 << 5)
#define COM2A0 (1 << 6)
#define COM2A1 (1 << 7)

#define CS20  (1 << 0)
#define CS21  (1 << 1)
#define CS22  (1 << 2)
#define WGM22 (1 << 3)
#define FOC2B (1 << 6)
#define FOC2A (1 << 7)

#define TCNT2_0 (1 << 0)
#define TCNT2_1 (1 << 1)
#define TCNT2_2 (1 << 2)
#define TCNT2_3 (1 << 3)
#define TCNT2_4 (1 << 4)
#define TCNT2_5 (1 << 5)
#define TCNT2_6 (1 << 6)
#define TCNT2_7 (1 << 7)

#define OCR2_0 (1 << 0)
#define OCR2_1 (1 << 1)
#define OCR2_2 (1 << 2)
#define OCR2_3 (1 << 3)
#define OCR2_4 (1 << 4)
#define OCR2_5 (1 << 5)
#define OCR2_6 (1 << 6)
#define OCR2_7 (1 << 7)

#define TCR2BUB (1 << 0)
#define TCR2AUB (1 << 1)
#define OCR2BUB (1 << 2)
#define OCR2AUB (1 << 3)
#define TCN2UB  (1 << 4)
#define AS2     (1 << 5)
#define EXCLK   (1 << 6)

#define TWBR0 (1 << 0)
#define TWBR1 (1 << 1)
#define TWBR2 (1 << 2)
#define TWBR3 (1 << 3)
#define TWBR4 (1 << 4)
#define TWBR5 (1 << 5)
#define TWBR6 (1 << 6)
#define TWBR7 (1 << 7)

#define TWPS0 (1 << 0)
#define TWPS1 (1 << 1)
#define TWS3  (1 << 3)
#define TWS4  (1 << 4)
#define TWS5  (1 << 5)
#define TWS6  (1 << 6)
#define TWS7  (1 << 7)

#define TWGCE (1 << 0)
#define TWA0  (1 << 1)
#define TWA1  (1 << 2)
#define TWA2  (1 << 3)
#define TWA3  (1 << 4)
#define TWA4  (1 << 5)
#define TWA5  (1 << 6)
#define TWA6  (1 << 7)

#define TWD0 (1 << 0)
#define TWD1 (1 << 1)
#define TWD2 (1 << 2)
#define TWD3 (1 << 3)
#define TWD4 (1 << 4)
#define TWD5 (1 << 5)
#define TWD6 (1 << 6)
#define TWD7 (1 << 7)

#define TWIE  (1 << 0)
#define TWEN  (1 << 2)
#define TWWC  (1 << 3)
#define TWSTO (1 << 4)
#define TWSTA (1 << 5)
#define TWEA  (1 << 6)
#define TWINT (1 << 7)

#define TWAM0 (1 << 0)
#define TWAM1 (1 << 1)
#define TWAM2 (1 << 2)
#define TWAM3 (1 << 3)
#define TWAM4 (1 << 4)
#define TWAM5 (1 << 5)
#define TWAM6 (1 << 6)

#define MPCM0 (1 << 0)
#define U2X0  (1 << 1)
#define UPE0  (1 << 2)
#define DOR0  (1 << 3)
#define FE0   (1 << 4)
#define UDRE0 (1 << 5)
#define TXC0  (1 << 6)
#define RXC0  (1 << 7)

#define TXB80  (1 << 0)
#define RXB80  (1 << 1)
#define UCSZ02 (1 << 2)
#define TXEN0  (1 << 3)
#define RXEN0  (1 << 4)
#define UDRIE0 (1 << 5)
#define TXCIE0 (1 << 6)
#define RXCIE0 (1 << 7)

#define UCPOL0  (1 << 0)
#define UCSZ00  (1 << 1)
#define UCPHA0  (1 << 1)
#define UCSZ01  (1 << 2)
#define UDORD0  (1 << 2)
#define USBS0   (1 << 3)
#define UPM00   (1 << 4)
#define UPM01   (1 << 5)
#define UMSEL00 (1 << 6)
#define UMSEL01 (1 << 7)

#define UBRR0_0 (1 << 0)
#define UBRR0_1 (1 << 1)
#define UBRR0_2 (1 << 2)
#define UBRR0_3 (1 << 3)
#define UBRR0_4 (1 << 4)
#define UBRR0_5 (1 << 5)
#define UBRR0_6 (1 << 6)
#define UBRR0_7 (1 << 7)

#define UBRR0_8  (1 << 0)
#define UBRR0_9  (1 << 1)
#define UBRR0_10 (1 << 2)
#define UBRR0_11 (1 << 3)

#define UDR0_0 (1 << 0)
#define UDR0_1 (1 << 1)
#define UDR0_2 (1 << 2)
#define UDR0_3 (1 << 3)
#define UDR0_4 (1 << 4)
#define UDR0_5 (1 << 5)
#define UDR0_6 (1 << 6)
#define UDR0_7 (1 << 7)

/*
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7

#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6

#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5
#define DDC6 6

#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6

#define PIND0 0
#define PIND1 1
#define PIND2 2
#define PIND3 3
#define PIND4 4
#define PIND5 5
#define PIND6 6
#define PIND7 7

#define DDD0 0
#define DDD1 1
#define DDD2 2
#define DDD3 3
#define DDD4 4
#define DDD5 5
#define DDD6 6
#define DDD7 7

#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7

#define TOV0 0
#define OCF0A 1
#define OCF0B 2

#define TOV1 0
#define OCF1A 1
#define OCF1B 2
#define ICF1 5

#define TOV2 0
#define OCF2A 1
#define OCF2B 2

#define PCIF0 0
#define PCIF1 1
#define PCIF2 2

#define INTF0 0
#define INTF1 1

#define INT0 0
#define INT1 1

#define GPIOR00 0
#define GPIOR01 1
#define GPIOR02 2
#define GPIOR03 3
#define GPIOR04 4
#define GPIOR05 5
#define GPIOR06 6
#define GPIOR07 7

#define EERE 0
#define EEPE 1
#define EEMPE 2
#define EERIE 3
#define EEPM0 4
#define EEPM1 5

#define EEDR0 0
#define EEDR1 1
#define EEDR2 2
#define EEDR3 3
#define EEDR4 4
#define EEDR5 5
#define EEDR6 6
#define EEDR7 7


#define EEAR0 0
#define EEAR1 1
#define EEAR2 2
#define EEAR3 3
#define EEAR4 4
#define EEAR5 5
#define EEAR6 6
#define EEAR7 7

#define EEAR8 0
#define EEAR9 1

#define PSRSYNC 0
#define PSRASY 1
#define TSM 7

#define WGM00 0
#define WGM01 1
#define COM0B0 4
#define COM0B1 5
#define COM0A0 6
#define COM0A1 7

#define CS00 0
#define CS01 1
#define CS02 2
#define WGM02 3
#define FOC0B 6
#define FOC0A 7

#define TCNT0_0 0
#define TCNT0_1 1
#define TCNT0_2 2
#define TCNT0_3 3
#define TCNT0_4 4
#define TCNT0_5 5
#define TCNT0_6 6
#define TCNT0_7 7

#define OCR0A_0 0
#define OCR0A_1 1
#define OCR0A_2 2
#define OCR0A_3 3
#define OCR0A_4 4
#define OCR0A_5 5
#define OCR0A_6 6
#define OCR0A_7 7

#define OCR0B_0 0
#define OCR0B_1 1
#define OCR0B_2 2
#define OCR0B_3 3
#define OCR0B_4 4
#define OCR0B_5 5
#define OCR0B_6 6
#define OCR0B_7 7

#define GPIOR10 0
#define GPIOR11 1
#define GPIOR12 2
#define GPIOR13 3
#define GPIOR14 4
#define GPIOR15 5
#define GPIOR16 6
#define GPIOR17 7

#define GPIOR20 0
#define GPIOR21 1
#define GPIOR22 2
#define GPIOR23 3
#define GPIOR24 4
#define GPIOR25 5
#define GPIOR26 6
#define GPIOR27 7

#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

#define SPI2X 0
#define WCOL 6
#define SPIF 7

#define SPDR0 0
#define SPDR1 1
#define SPDR2 2
#define SPDR3 3
#define SPDR4 4
#define SPDR5 5
#define SPDR6 6
#define SPDR7 7

#define ACIS0 0
#define ACIS1 1
#define ACIC 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define ACBG 6
#define ACD 7

#define SE 0
#define SM0 1
#define SM1 2
#define SM2 3

#define PORF 0
#define EXTRF 1
#define BORF 2
#define WDRF 3

#define IVCE 0
#define IVSEL 1
#define PUD 4
#define BODSE 5
#define BODS 6

#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define BLBSET 3
#define RWWSRE 4
#define SIGRD 5
#define RWWSB 6
#define SPMIE 7

#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDCE 4
#define WDP3 5
#define WDIE 6
#define WDIF 7

#define CLKPS0 0
#define CLKPS1 1
#define CLKPS2 2
#define CLKPS3 3
#define CLKPCE 7

#define PRADC 0
#define PRUSART0 1
#define PRSPI 2
#define PRTIM1 3
#define PRTIM0 5
#define PRTIM2 6
#define PRTWI 7

#define CAL0 0
#define CAL1 1
#define CAL2 2
#define CAL3 3
#define CAL4 4
#define CAL5 5
#define CAL6 6
#define CAL7 7

#define PCIE0 0
#define PCIE1 1
#define PCIE2 2

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3
#define PCINT4 4
#define PCINT5 5
#define PCINT6 6
#define PCINT7 7

#define PCINT8 0
#define PCINT9 1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5
#define PCINT14 6

#define PCINT16 0
#define PCINT17 1
#define PCINT18 2
#define PCINT19 3
#define PCINT20 4
#define PCINT21 5
#define PCINT22 6
#define PCINT23 7

#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2

#define TOIE1 0
#define OCIE1A 1
#define OCIE1B 2
#define ICIE1 5

#define TOIE2 0
#define OCIE2A 1
#define OCIE2B 2

#define ADCL0 0
#define ADCL1 1
#define ADCL2 2
#define ADCL3 3
#define ADCL4 4
#define ADCL5 5
#define ADCL6 6
#define ADCL7 7

#define ADCH0 0
#define ADCH1 1
#define ADCH2 2
#define ADCH3 3
#define ADCH4 4
#define ADCH5 5
#define ADCH6 6
#define ADCH7 7

#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ADTS0 0
#define ADTS1 1
#define ADTS2 2
#define ACME 6

#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADC0D 0
#define ADC1D 1
#define ADC2D 2
#define ADC3D 3
#define ADC4D 4
#define ADC5D 5

#define AIN0D 0
#define AIN1D 1

#define WGM10 0
#define WGM11 1
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

#define FOC1B 6
#define FOC1A 7

#define TCNT1L0 0
#define TCNT1L1 1
#define TCNT1L2 2
#define TCNT1L3 3
#define TCNT1L4 4
#define TCNT1L5 5
#define TCNT1L6 6
#define TCNT1L7 7

#define TCNT1H0 0
#define TCNT1H1 1
#define TCNT1H2 2
#define TCNT1H3 3
#define TCNT1H4 4
#define TCNT1H5 5
#define TCNT1H6 6
#define TCNT1H7 7

#define ICR1L0 0
#define ICR1L1 1
#define ICR1L2 2
#define ICR1L3 3
#define ICR1L4 4
#define ICR1L5 5
#define ICR1L6 6
#define ICR1L7 7

#define ICR1H0 0
#define ICR1H1 1
#define ICR1H2 2
#define ICR1H3 3
#define ICR1H4 4
#define ICR1H5 5
#define ICR1H6 6
#define ICR1H7 7

#define OCR1AL0 0
#define OCR1AL1 1
#define OCR1AL2 2
#define OCR1AL3 3
#define OCR1AL4 4
#define OCR1AL5 5
#define OCR1AL6 6
#define OCR1AL7 7

#define OCR1AH0 0
#define OCR1AH1 1
#define OCR1AH2 2
#define OCR1AH3 3
#define OCR1AH4 4
#define OCR1AH5 5
#define OCR1AH6 6
#define OCR1AH7 7

#define OCR1BL0 0
#define OCR1BL1 1
#define OCR1BL2 2
#define OCR1BL3 3
#define OCR1BL4 4
#define OCR1BL5 5
#define OCR1BL6 6
#define OCR1BL7 7

#define OCR1BH0 0
#define OCR1BH1 1
#define OCR1BH2 2
#define OCR1BH3 3
#define OCR1BH4 4
#define OCR1BH5 5
#define OCR1BH6 6
#define OCR1BH7 7

#define WGM20 0
#define WGM21 1
#define COM2B0 4
#define COM2B1 5
#define COM2A0 6
#define COM2A1 7

#define CS20 0
#define CS21 1
#define CS22 2
#define WGM22 3
#define FOC2B 6
#define FOC2A 7

#define TCNT2_0 0
#define TCNT2_1 1
#define TCNT2_2 2
#define TCNT2_3 3
#define TCNT2_4 4
#define TCNT2_5 5
#define TCNT2_6 6
#define TCNT2_7 7

#define OCR2_0 0
#define OCR2_1 1
#define OCR2_2 2
#define OCR2_3 3
#define OCR2_4 4
#define OCR2_5 5
#define OCR2_6 6
#define OCR2_7 7

#define OCR2_0 0
#define OCR2_1 1
#define OCR2_2 2
#define OCR2_3 3
#define OCR2_4 4
#define OCR2_5 5
#define OCR2_6 6
#define OCR2_7 7

#define TCR2BUB 0
#define TCR2AUB 1
#define OCR2BUB 2
#define OCR2AUB 3
#define TCN2UB 4
#define AS2 5
#define EXCLK 6

#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

#define TWPS0 0
#define TWPS1 1
#define TWS3 3
#define TWS4 4
#define TWS5 5
#define TWS6 6
#define TWS7 7

#define TWGCE 0
#define TWA0 1
#define TWA1 2
#define TWA2 3
#define TWA3 4
#define TWA4 5
#define TWA5 6
#define TWA6 7

#define TWD0 0
#define TWD1 1
#define TWD2 2
#define TWD3 3
#define TWD4 4
#define TWD5 5
#define TWD6 6
#define TWD7 7

#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7

#define TWAM0 0
#define TWAM1 1
#define TWAM2 2
#define TWAM3 3
#define TWAM4 4
#define TWAM5 5
#define TWAM6 6

#define MPCM0 0
#define U2X0 1
#define UPE0 2
#define DOR0 3
#define FE0 4
#define UDRE0 5
#define TXC0 6
#define RXC0 7

#define TXB80 0
#define RXB80 1
#define UCSZ02 2
#define TXEN0 3
#define RXEN0 4
#define UDRIE0 5
#define TXCIE0 6
#define RXCIE0 7

#define UCPOL0 0
#define UCSZ00 1
#define UCPHA0 1
#define UCSZ01 2
#define UDORD0 2
#define USBS0 3
#define UPM00 4
#define UPM01 5
#define UMSEL00 6
#define UMSEL01 7

#define UBRR0_0 0
#define UBRR0_1 1
#define UBRR0_2 2
#define UBRR0_3 3
#define UBRR0_4 4
#define UBRR0_5 5
#define UBRR0_6 6
#define UBRR0_7 7

#define UBRR0_8 0
#define UBRR0_9 1
#define UBRR0_10 2
#define UBRR0_11 3

#define UDR0_0 0
#define UDR0_1 1
#define UDR0_2 2
#define UDR0_3 3
#define UDR0_4 4
#define UDR0_5 5
#define UDR0_6 6
#define UDR0_7 7
*/
#endif
