#ifndef INSTRUCTTION_H_
#define INSTRUCTTION_H_


#define OPCODES \
    X(STOP, 0, 0x00, 0) \
    X(ADD, 2, 0x01, 3) \
    X(MUL, 2, 0x02, 5) \
    X(SUB, 2, 0x03, 3) \
    X(DIV, 2, 0x04, 5) \
    X(SDIV, 2, 0x05, 5) \
    X(MOD, 2, 0x06, 5) \
    X(SMOD, 2, 0x07, 5) \
    X(ADDMOD, 3, 0x08, 8) \
    X(MULMOD, 3, 0x09, 8) \
    X(EXP, 2, 0x0A, 10) \
    X(SIGNEXTEND, 2, 0x0B, 5) \
    X(LT, 2, 0x10, 3) \
    X(GT, 2, 0x11, 3) \
    X(SLT, 2, 0x12, 3) \
    X(SGT, 2, 0x13, 3) \
    X(EQ, 2, 0x14, 3) \
    X(ISZERO, 1, 0x15, 3) \
    X(AND, 2, 0x16, 3) \
    X(OR, 2, 0x17, 3) \
    X(XOR, 2, 0x18, 3) \
    X(NOT, 1, 0x19, 3) \
    X(BYTE, 2, 0x1A, 3) \
    X(SHA3, 2, 0x20, 30) \
    X(ADDRESS, 2, 0x30, 2) \
    X(BALANCE, 2, 0x31, 400) \
    X(ORIGIN, 2, 0x32, 2) \
    X(CALLER, 2, 0x33, 2) \
    X(CALLVALUE, 2, 0x34, 2) \
    X(CALLDATALOAD, 2, 0x35, 3) \
    X(CALLDATASIZE, 2, 0x36, 2) \
    X(CALLDATACOPY, 3, 0x37, 3) \
    X(CODESIZE, 2, 0x38, 2) \
    X(CODECOPY, 3, 0x39, 3) \
    X(GASPRICE, 2, 0x3A, 2) \
    X(EXTCODESIZE, 2, 0x3B, 700) \
    X(EXTCODECOPY, 4, 0x3C, 700) \
    X(RETURNDATASIZE, 2, 0x3D, 2) \
    X(RETURNDATACOPY, 3, 0x3E, 3) \
    X(BLOCKHASH, 2, 0x40, 20) \
    X(COINBASE, 2, 0x41, 2) \
    X(TIMESTAMP, 2, 0x42, 2) \
    X(NUMBER, 2, 0x43, 2) \
    X(DIFFICULTY, 2, 0x44, 2) \
    X(GASLIMIT, 2, 0x45, 2) \
    X(POP, 1, 0x50, 2) \
    X(MLOAD, 2, 0x51, 3) \
    X(MSTORE, 2, 0x52, 3) \
    X(MSTORE8, 2, 0x53, 3) \
    X(SLOAD, 2, 0x54, 50) \
    X(SSTORE, 2, 0x55, 0) \
    X(JUMP, 1, 0x56, 8) \
    X(JUMPI, 2, 0x57, 10) \
    X(PC, 2, 0x58, 2) \
    X(MSIZE, 2, 0x59, 2) \
    X(GAS, 2, 0x5A, 2) \
    X(JUMPDEST, 0, 0x5B, 1) \
    X(PUSH1, 1, 0x60, 3) \
    X(PUSH2, 2, 0x61, 3) \
    X(PUSH3, 3, 0x62, 3) \
    X(PUSH4, 4, 0x63, 3) \
    X(PUSH5, 5, 0x64, 3) \
    X(PUSH6, 6, 0x65, 3) \
    X(PUSH7, 7, 0x66, 3) \
    X(PUSH8, 8, 0x67, 3) \
    X(PUSH9, 9, 0x68, 3) \
    X(PUSH10, 10, 0x69, 3) \
    X(PUSH11, 11, 0x6A, 3) \
    X(PUSH12, 12, 0x6B, 3) \
    X(PUSH13, 13, 0x6C, 3) \
    X(PUSH14, 14, 0x6D, 3) \
    X(PUSH15, 15, 0x6E, 3) \
    X(PUSH16, 16, 0x6F, 3) \
    X(PUSH17, 17, 0x70, 3) \
    X(PUSH18, 18, 0x71, 3) \
    X(PUSH19, 19, 0x72, 3) \
    X(PUSH20, 20, 0x73, 3) \
    X(PUSH21, 21, 0x74, 3) \
    X(PUSH22, 22, 0x75, 3) \
    X(PUSH23, 23, 0x76, 3) \
    X(PUSH24, 24, 0x77, 3) \
    X(PUSH25, 25, 0x78, 3) \
    X(PUSH26, 26, 0x79, 3) \
    X(PUSH27, 27, 0x7A, 3) \
    X(PUSH28, 28, 0x7B, 3) \
    X(PUSH29, 29, 0x7C, 3) \
    X(PUSH30, 30, 0x7D, 3) \
    X(PUSH31, 31, 0x7E, 3) \
    X(PUSH32, 32, 0x7F, 3) \
    X(DUP1, 1, 0x80, 3) \
    X(DUP2, 2, 0x81, 3) \
    X(DUP3, 3, 0x82, 3) \
    X(DUP4, 4, 0x83, 3) \
    X(DUP5, 5, 0x84, 3) \
    X(DUP6, 6, 0x85, 3) \
    X(DUP7, 7, 0x86, 3) \
    X(DUP8, 8, 0x87, 3) \
    X(DUP9, 9, 0x88, 3) \
    X(DUP10, 10, 0x89, 3) \
    X(DUP11, 11, 0x8A, 3) \
    X(DUP12, 12, 0x8B, 3) \
    X(DUP13, 13, 0x8C, 3) \
    X(DUP14, 14, 0x8D, 3) \
    X(DUP15, 15, 0x8E, 3) \
    X(DUP16, 16, 0x8F, 3) \
    X(SWAP1, 1, 0x90, 3) \
    X(SWAP2, 2, 0x91, 3) \
    X(SWAP3, 3, 0x92, 3) \
    X(SWAP4, 4, 0x93, 3) \
    X(SWAP5, 5, 0x94, 3) \
    X(SWAP6, 6, 0x95, 3) \
    X(SWAP7, 7, 0x96, 3) \
    X(SWAP8, 8, 0x97, 3) \
    X(SWAP9, 9, 0x98, 3) \
    X(SWAP10, 10, 0x99, 3) \
    X(SWAP11, 11, 0x9A, 3) \
    X(SWAP12, 12, 0x9B, 3) \
    X(SWAP13, 13, 0x9C, 3) \
    X(SWAP14, 14, 0x9D, 3) \
    X(SWAP15, 15, 0x9E, 3) \
    X(SWAP16, 16, 0x9F, 3) \
    X(LOG0, 2, 0xA0, 375) \
    X(LOG1, 2, 0xA1, 750) \
    X(LOG2, 2, 0xA2, 1125) \
    X(LOG3, 2, 0xA3, 1500) \
    X(LOG4, 2, 0xA4, 1875) \
    X(CREATE, 3, 0xF0, 32000) \
    X(CALL, 7, 0xF1, 700) \
    X(CALLCODE, 7, 0xF2, 700) \
    X(RETURN, 2, 0xF3, 0) \
    X(DELEGATECALL, 6, 0xF4, 700) \
    X(CREATE2, 4, 0xF5, 32000) \
    X(STATICCALL, 6, 0xFA, 700) \
    X(REVERT, 2, 0xFD, 0) \
    X(INVALID, 0, 0xFE, 0) \
    X(SELFDESTRUCT, 1, 0xFF, 5000)

#endif // INSTRUCTTION_H_