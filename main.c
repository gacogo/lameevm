#include "common.h"
#include "instruction.h"
#include <string.h>



// Define the X-Macro
// Generate the enum definition
#define X(name, args, value, gas) name = value,
enum Instruction {
    OPCODES
};
#undef X

// Generate the mapping function
const char *get_opcode_name(uint8_t value) {
    switch (value) {
#define X(name, args, value, gas) case value: return #name;
        OPCODES
#undef X
        default: return "unknown";
    }
}

// Get the gas cost of an opcode
int get_opcode_gas(int value) {
    switch (value) {
#define X(name, args, value, gas) case value: return gas;
        OPCODES
#undef X
        default: return -1; // Return a sentinel value for unknown opcodes
    }
}

// Get the number of arguments an opcode takes
int get_opcode_args(int value) {
    switch (value) {
#define X(name, args, value, gas) case value: return args;
        OPCODES
#undef X
        default: return -1; // Return a sentinel value for unknown opcodes
    }
}

unsigned char hexCharToInt(char);
size_t hexStringToBytes(const char *hex, unsigned char **bytes);
uint64_t processInstruction(char *bytecode, uint64_t offset);
static uint64_t simpleInstruction(const char *instruction, uint64_t offset);
//typedef char byte;
int main(int argc, const char *argv[]){

   // unsigned char *input ="6080604052"; //"006004600361";
    if (argc < 2){
        printf("usage  %s <bytecode>\n", argv[0]);
        return 0;
    }

    const unsigned char *input =  argv[1];
    uint64_t pc = 0;

    unsigned char *converted = NULL;

    size_t no_bytes = hexStringToBytes(input, &converted);
    uint8_t section = 0;
    printf("===== SECTION %d \t\t\n", section);
    while(pc < no_bytes){
        uint8_t opcode = converted[pc];


        printf("%04ld: 0x%02X\t\t", pc, converted[pc]);

          if (opcode ==  INVALID){

            section ++;

            printf("\n===== SECTION  %d \t\t\n", section);
        }

        pc  = processInstruction(converted, pc);

    }

    return 0;
}
uint64_t processInstruction(char *bytecode, uint64_t offset){
   uint8_t instruction =  *(bytecode + offset);
   char *instruction_name = strdup(get_opcode_name(instruction));
if (strcmp(instruction_name,  "unknown") == 0){
       printf("%04ld: 0x%02x\n", offset, instruction);
       return offset + 1;
   }

   printf("%04ld: %s\t\t", offset, instruction_name);
   //printf("%4ld \t %s\n", offset, instruction_name);

   if (instruction >= PUSH1 && instruction <= PUSH32){
       uint64_t arguments = ((uint8_t)instruction - 95);
       printf("0x");
       for (int i = 0; i < arguments; i++){
           printf("%02x", bytecode[offset + i + 1] & 0xFF);
       }
       printf("\n");
       return offset + 1 + arguments;
   }
   else{

       printf("\n");
       //printf("0x%02x\n", bytecode[offset] );
       return offset + 1;
   }
}
static uint64_t simpleInstruction(const char *label, uint64_t offset){
    printf("%s\n", label);
    return offset + 1;
}

unsigned char hexCharToInt(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    return 0; // Invalid character
}

size_t hexStringToBytes(const char *hexString, unsigned char **bytes) {
    size_t length  = strlen(hexString);
    size_t position = 0;
    *bytes = (unsigned char *)malloc(length * 2 + 1);
    size_t bytecount = 0;
    for(size_t i = 0; i < length; i +=2){
        *(*bytes + bytecount) = (hexCharToInt(hexString[i]) << 4 ) | hexCharToInt(hexString[i + 1]);
        bytecount++;
    }

    return bytecount;
}
