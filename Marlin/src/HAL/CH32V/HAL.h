#pragma once

#include <stdint.h>
#include "../../core/macros.h"

// Hardware specific definitions for CH32V307 (RISC-V)

// Define I/O port macros
#define CH32V_FAST_GPIO 1

// VTF (Vector Table Free) interrupt attribute for negligible jitter
#define VTF_ISR_ATTR __attribute__((interrupt("WCH-Interrupt-fast")))

// Map Marlin's ISR_ATTR to VTF or SRAM section
#ifndef ISR_ATTR
  #define ISR_ATTR __attribute__((section(".data")))
#endif

// General HAL functions expected by Marlin
void HAL_init();
void HAL_idletask();
void HAL_clear_reset_source();
uint8_t HAL_get_reset_source();

void HAL_timer_start(const uint8_t timer_num, const uint32_t frequency);
void HAL_timer_enable_interrupt(const uint8_t timer_num);
void HAL_timer_disable_interrupt(const uint8_t timer_num);
bool HAL_timer_interrupt_enabled(const uint8_t timer_num);

// End of HAL.h
