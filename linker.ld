ENTRY(_start)

SECTIONS{
    . = 2M;
    kernel_start = .;
    
    text BLOCK(4K) : ALIGN(4K) {
		*(.multiboot)
		*(.text)
	}

	.rodata BLOCK(4K) : ALIGN(4K) {
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K) {
		*(.data)
	}

	.bss BLOCK(4K) : ALIGN(4K){
		*(COMMON)
		*(.bss)
	}

    . = ALIGN(4K);
    kernel_end = .;
}
