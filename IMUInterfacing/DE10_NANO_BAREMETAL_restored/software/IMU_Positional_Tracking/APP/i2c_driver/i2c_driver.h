#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H
#include "socal/hps.h"
#include "socal/socal.h"
#include "lib_def.h"
#include "os_cpu.h"
#define I2C0_INTERRUPT_VECTOR 190
#define I2C1_INTERRUPT_VECTOR 191

#define HTONS(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
#define NTOHS(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
void init_I2C1_interrupt(void);

void init_I2C1(ALT_I2C_DEV_t * device);
void test_I2C1_as_master(ALT_I2C_DEV_t * device);
void test_master_send(int test, int length);
void test_master_receive(int length);
void test_target_device(void);

void I2C1_ISR_Handler(CPU_INT32U cpu_id);

//Destructive read of RX buffer
void read(void * data, size_t size);

//Bulk write of size bytes from data
ALT_STATUS_CODE write(void * data, size_t size);
#endif // I2C_DRIVER_H