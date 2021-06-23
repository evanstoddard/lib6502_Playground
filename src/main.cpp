#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "Core6502.hpp"
#include <stdint.h>

void printCPUState(Core6502::CPU & cpu);

// Program sums all numbers from 0 to N
int main(int argc, char ** argv) {

	// Create memory
	uint8_t mem[0x10000];
	
	// Create CPU
	Core6502::CPU cpu(mem);

	// Set reset vector and reset CPU
	mem[0xFFFC] = 0x00;
	mem[0xFFFD] = 0x80;
	cpu.reset();

	// Load program into memory

	// Load 0 into accumulator
	mem[0x8000] = 0xA9;
	mem[0x8001] = 0x0;

	// Load N into register X
	uint8_t n = 10;
	mem[0x8002] = 0xA2;
	mem[0x8003] = n;

	// Store register X into zero page address 0x40
	mem[0x8004] = 0x86;
	mem[0x8005] = 0x40;

	// Add memory value to accumulator
	mem[0x8006] = 0x65;
	mem[0x8007] = 0x40;

	// Decrement register X
	mem[0x8008] = 0xCA;

	// Check if X is equal to 0
	mem[0x8009] = 0xD0;
	mem[0x800a] = 0x4;

	// Create NOP loop
	mem[0x800b] = 0xEA;
	mem[0x800c] = 0x4C;
	mem[0x800d] = 0x0b;
	mem[0x800e] = 0x80;

	// Jump back to 0x8004 if not 0
	mem[0x800f] = 0x4C;
	mem[0x8010] = 0x04;
	mem[0x8011] = 0x80;

	while (1) {

		printCPUState(cpu);

		std::cout << "Press enter to clock cpu..." << std::endl;

		// Wait for enter
		std::cin.ignore();

		// Clock CPU
		cpu.clock();

	}


	return 0;

}

void printCPUState(Core6502::CPU & cpu) {

	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif

	std::cout << "------ CPU State ------\n" << std::endl;

	std::cout << "Registers:" << std::endl;
	std::cout << "\tPC: 0x" << std::hex << (uint32_t)cpu.registers.PC << std::endl;
	std::cout << "\tA: 0x" << std::hex << (uint32_t)cpu.registers.A << std::endl;
	std::cout << "\tX: 0x" << std::hex << (uint32_t)cpu.registers.X << std::endl;
	std::cout << "\tY: 0x" << std::hex << (uint32_t)cpu.registers.Y << std::endl;
	std::cout << "\tSP: 0x" << std::hex << (uint32_t)cpu.registers.SP << std::endl;
	std::cout << std::endl;

	std::cout << "Flags:" << std::endl;
	std::cout << "\tCarry Flag: " << std::hex << (uint32_t)cpu.status.bitfield.CarryFlag << std::endl;
	std::cout << "\tZero Flag: " << std::hex << (uint32_t)cpu.status.bitfield.ZeroFlag << std::endl;
	std::cout << "\tInterrupt Disable: " << std::hex << (uint32_t)cpu.status.bitfield.InterruptDisable << std::endl;
	std::cout << "\tDecimal Flag: " << std::hex << (uint32_t)cpu.status.bitfield.DecimalMode << std::endl;
	std::cout << "\tBreak Flag: " << std::hex << (uint32_t)cpu.status.bitfield.BreakCommand << std::endl;
	std::cout << "\tOverflow Flag: " << std::hex << (uint32_t)cpu.status.bitfield.OverflowFlag << std::endl;
	std::cout << "\tNegative Flag: " << std::hex << (uint32_t)cpu.status.bitfield.NegativeFlag << std::endl;
	std::cout << "\tUser Flag: " << std::hex << (uint32_t)cpu.status.bitfield.UserFlag << std::endl;
	std::cout << std::endl;

	std::cout << "Remaining Cycles: " << std::dec << (uint32_t)cpu.cyclesRemaining << std::endl;
	std::cout << std::endl;

}