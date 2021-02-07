// ARM Assembly code from university course.
// Used with LPCXpresso1549 and MCUExpresso.

// Exercise 4.2
__attribute__(( naked )) int prt(const char *a){
	// Print string in reversed order to serial port.
	asm volatile(
		"push { r4, r7, lr } \n"
		"mov r4, r0 \n"
		"mov r7, #0 \n"

		"print_check:"
		"ldrb r0, [r4, r7] \n"
		"cmp r0, #0 \n"
		"beq print_loop \n"
		"add r7, r7, #1 \n"
		"b print_check \n"

		"print_loop:"
		"cmp r7, #0 \n"
		"blt print_stop \n"
		"ldrb r0, [r4, r7] \n"
		"bl Board_UARTPutChar \n"
		"add r7, r7, #-1 \n"
		"b print_loop \n"

		"print_stop:"
		"pop { r4, r7, lr } \n"
		"bx lr \n"
	);
}


// Execerise 4.1
__attribute__(( naked )) int ex4_1(const char *a){
	// Print string in uppercase to serial port.
	asm volatile(
		"push { r4, r7, lr } \n"
		"mov r4, r0 \n"
		"mov r7, #0 \n"

		"print_loop:"
		"ldrb r0, [r4, r7] \n"

		"cmp r0, #0 \n"
		"beq print_stop \n"

		"cmp r0, #97 \n"
		"blt skibs \n"
		"cmp r0, #122 \n"
		"bgt skibs \n"
		"add r0, r0, #-32 \n"
		"skibs:"

		"bl Board_UARTPutChar \n"
		"add r7, r7, #1 \n"
		"b print_loop \n"

		"print_stop:"
		"pop { r4, r7, lr } \n"
		"bx lr \n"
	);
}


// Exercise 3
__attribute__(( naked )) int ex3(int a, int b){
	// Calculate absolute values of two signed numbers.
	asm volatile(
		"push {r4, r5, r6, r7} \n"

		"mov r7, #-1 \n"

		"cmp r0, #0 \n"
		"bge skip \n"
		"mul r0, r0, r7 \n"
		"skip: \n"

		"cmp r1, #0 \n"
		"bge skips \n"
		"mul r1, r1, r7 \n"
		"skips: \n"

		"adds r0, r0, r1 \n"

		"pop {r4, r5, r6, r7} \n"
		"bx lr \n"
	 );
}


// Exercise 2
__attribute__(( naked )) void ex2(int *a, int *b, int *c, int *d){
	// M0 = (M0 + M1) * (M2 + (M1 * M3))
	// Values from memory addresses.
	asm volatile(
		"push {r4, r5, r6, r7} \n"

		"ldr r4, [r0] \n"
		"ldr r5, [r1] \n"
		"ldr r6, [r2] \n"
		"ldr r7, [r3] \n"
		"mul r7, r7, r5 \n"
		"adds r7, r7, r6 \n"
		"adds r4, r4, r5 \n"
		"mul r7, r7, r4 \n"
		"str r7, [r0] \n"

		"pop {r4, r5, r6, r7} \n"
		"bx lr \n"
	);
}


// Exercise 1
__attribute__(( naked )) int ex1(int v0, int v1, int v2, int v3){
	// M0 = (M0 + M1) * (M2 + (M1 * M3)
	asm volatile(
		"push {r4, r5, r6, r7} \n"

		"adds r4, r0, r1 \n"
		"mul r5, r1, r3 \n"
		"adds r6, r2, r5 \n"
		"mul r0, r4, r6 \n"

		"pop {r4, r5, r6, r7} \n"
		"bx lr \n"
	);
}