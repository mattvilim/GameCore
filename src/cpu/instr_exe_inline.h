#ifndef INSTR_EXE_INLINE_H
#define INSTR_EXE_INLINE_H

#include "instr_exe.h"

GC_INLINE ubyte_t
_operand_read_gen_b(const cpu_t *cpu, const instr_t *instr) {
    return cpu_gen_read_b(cpu, instr->rm);
}

GC_INLINE void
_operand_write_gen_b(const cpu_t *cpu, const instr_t *instr, ubyte_t val) {
    return cpu_gen_write_b(cpu, instr->rm, val);
}

#endif
