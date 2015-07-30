/*
 * Core 8086 Copyright (C) 2014 Matthew Vilim
 *
 * src/shared/macros.h
 */

#include <stdlib.h>

#ifndef CPU_H
#define CPU_H

gc_error_t cpu_init(cpu_t *cpu, mem_t *mem);
gc_error_t cpu_term(cpu_t *cpu);

#endif