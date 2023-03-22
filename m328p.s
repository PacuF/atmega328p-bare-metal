
.section .isr_vector, "ax"

rjmp _RESET ; Reset Handler
nop
rjmp _EXT_INT0 ; External interrupt 0 
nop
rjmp _EXT_INT1 ; External interrupt 1
nop
rjmp _PCINT0 ; PCINT0 Handler
nop
rjmp _PCINT1 ; PCINT1 Handler
nop
rjmp _PCINT2 ; PCINT2 Handler
nop
rjmp _WDT ; Watchdog Timer Handler
nop
rjmp _TIM2_COMPA ; Timer2 Compare A Handler
nop
rjmp _TIM2_COMPB ; Timer2 Compare B Handler
nop
rjmp _TIM2_OVF ; Timer2 Overflow Handler
nop
rjmp _TIM1_CAPT ; Timer1 Capture Handler
nop
rjmp _TIM1_COMPA ; Timer1 Compare A Handler
nop
rjmp _TIM1_COMPB ; Timer1 Compare B Handler
nop
rjmp _TIM1_OVF ; Timer1 Overflow Handler
nop
rjmp _TIM0_COMPA ; Timer0 Compare A Handler
nop
rjmp _TIM0_COMPB ; Timer0 Compare B Handler
nop
rjmp _TIM0_OVF ; Timer0 Overflow Handler
nop
rjmp _SPI_STC ; SPI Transfer Complete Handler
nop
rjmp _USART_RXC ; USART, RX Complete Handler
nop
rjmp _USART_UDRE ; USART, UDR Empty Handler
nop
rjmp _USART_TXC ; USART, TX Complete Handler
nop
rjmp _ADC ; ADC Conversion Complete Handler
nop
rjmp _EE_RDY ; EEPROM Ready Handler
nop
rjmp _ANA_COMP ; Analog Comparator Handler
nop
rjmp _TWI ; 2-wire Serial Interface Handler
nop
rjmp _SPM_RDY ; Store Program Memory Ready Handler
nop

_RESET:

    ldi r16, 0
    mov r1, r16
    
    ; Set Stack Pointer to top of ram:
    ldi r16, 0x08
    out 0x3E,r16
    ldi r16, 0xFF
    out 0x3D,r16

    ; copy data from flash to ram:

    ldi r26, lo8(__data_size)
    ldi r27, hi8(__data_size)
    ; -> X is the number of data bytes to be copied

    add r26, r27 ; when X is zero, the sum of r26 and r27 is also zero
    breq end_of_copy ; So if X is zero, there are no bytes to be copied

    ldi r28, lo8(__data_ram_start)
    ldi r29, hi8(__data_ram_start)
    ; -> Y points to start of data in ram

    ldi r30, lo8(__data_flash_start)
    ldi r31, hi8(__data_flash_start)
    ; -> Z points to start of data in flash

    copy_loop:
    lpm r18, Z+
    st Y+, r18
    sbiw X, 1
    brne copy_loop
    end_of_copy:

    ; initialize bss:
    ldi r26, lo8(__bss_size)
    ldi r27, hi8(__bss_size)
    ; -> X is the number of bss bytes 

    add r26, r27 
    breq end_of_bss_init 

    ldi r28, lo8(__bss_start)
    ldi r29, hi8(__bss_start)
    ; -> Y points to start of bss 

    ldi r18, 0
    bss_init_loop:
    st Y+, r18
    sbiw X, 1
    brne bss_init_loop
    end_of_bss_init:

    sei
    jmp main

_DEFAULT:
    jmp _DEFAULT

.weak ISR_EXT_INT0
.set ISR_EXT_INT0, _DEFAULT
_EXT_INT0:
    call ISR_EXT_INT0
    reti

.weak ISR_EXT_INT1
.set ISR_EXT_INT1, _DEFAULT
_EXT_INT1:
    call ISR_EXT_INT1
    reti

.weak ISR_TIM0_COMPA
.set ISR_TIM0_COMPA, _DEFAULT
_TIM0_COMPA:
    call ISR_TIM0_COMPA
    reti

.weak ISR_TIM1_COMPA
.set ISR_TIM1_COMPA, _DEFAULT
_TIM1_COMPA:
    call ISR_TIM1_COMPA
    reti

.weak ISR_TIM2_COMPA
.set ISR_TIM2_COMPA, _DEFAULT
_TIM2_COMPA:
    call ISR_TIM2_COMPA
    reti

.weak ISR_ANA_COMP
.set ISR_ANA_COMP, _DEFAULT
_ANA_COMP:
    call ISR_ANA_COMP
    reti

.weak ISR_PCINT0
.set ISR_PCINT0, _DEFAULT
_PCINT0:
    call ISR_PCINT0
    reti

.weak ISR_PCINT1
.set ISR_PCINT1, _DEFAULT
_PCINT1:
    call ISR_PCINT1
    reti

.weak ISR_PCINT2
.set ISR_PCINT2, _DEFAULT
_PCINT2:
    call ISR_PCINT2
    reti

.weak ISR_WDT
.set ISR_WDT, _DEFAULT
_WDT:
    call ISR_WDT
    reti

.weak IST_TIM2_COMPB
.set ISR_TIM2_COMPB, _DEFAULT
_TIM2_COMPB:
    call ISR_TIM2_COMPB
    reti

.weak ISR_TIM2_OVF
.set ISR_TIM2_OVF, _DEFAULT
_TIM2_OVF:
    call ISR_TIM2_OVF
    reti

.weak ISR_TIM1_CAPT
.set ISR_TIM1_CAPT, _DEFAULT
_TIM1_CAPT:
    call ISR_TIM1_CAPT
    reti

.weak ISR_TIM1_COMPB
.set ISR_TIM1_COMPB, _DEFAULT
_TIM1_COMPB:
    call ISR_TIM1_COMPB 
    reti

.weak ISR_TIM1_OVF
.set ISR_TIM1_OVF, _DEFAULT
_TIM1_OVF:
    call ISR_TIM1_OVF
    reti

.weak ISR_TIM0_COMPB
.set ISR_TIM0_COMPB, _DEFAULT
_TIM0_COMPB:
    call ISR_TIM0_COMPB
    reti

.weak ISR_TIM0_OVF
.set ISR_TIM0_OVF, _DEFAULT
_TIM0_OVF:
    call ISR_TIM0_OVF
    reti

.weak ISR_SPI_STC
.set ISR_SPI_STC, _DEFAULT
_SPI_STC:
    call ISR_SPI_STC
    reti

.weak ISR_USART_RXC
.set ISR_USART_RXC, _DEFAULT
_USART_RXC:
    call ISR_USART_RXC
    reti

.weak ISR_USART_UDRE
.set ISR_USART_UDRE, _DEFAULT
_USART_UDRE:
    call ISR_USART_UDRE
    reti

.weak ISR_USART_TXC
.set ISR_USART_TXC, _DEFAULT
_USART_TXC:
    call ISR_USART_TXC
    reti

.weak ISR_ADC
.set ISR_ADC, _DEFAULT
_ADC:
    call ISR_ADC
    reti

.weak ISR_EE_RDY
.set ISR_EE_RDY, _DEFAULT
_EE_RDY:
    call ISR_EE_RDY
    reti

.weak ISR_TWI
.set ISR_TWI, _DEFAULT
_TWI:
    call ISR_TWI
    reti

.weak ISR_SPM_RDY
.set ISR_SPM_RDY, _DEFAULT
_SPM_RDY:
    call ISR_SPM_RDY
    reti
