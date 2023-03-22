
MEMORY {
   FLASH (rx ) : ORIGIN = 0x000000, LENGTH = 28K
   RAM   (rwx) : ORIGIN = 0x800100, LENGTH =  2K
}

SECTIONS
{
   .text : {

        KEEP(*(.isr_vector))

        . = ALIGN(2);
        *(.text*) 

        . = ALIGN(2);
        *(.progmem*)

   } > FLASH 

    . = ALIGN(2);
   .data : {

        __data_ram_start = .;

        *(.rodata*)

        *(.data*)

   } > RAM AT > FLASH

   __data_flash_start = LOADADDR(.data);
   __data_size        = SIZEOF(.data);


  .bss  ADDR(.data) + SIZEOF (.data) : AT (ADDR (.bss)){
       __bss_start = .;
       *(.bss*)
   }  > RAM
   __bss_size = SIZEOF(.bss);

}
