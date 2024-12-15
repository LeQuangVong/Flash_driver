

#ifndef MY_FLASH_H_
#define MY_FLASH_H_

#include <stdint.h>

typedef struct {
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;
	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t AR;
	volatile uint32_t OBR;
	volatile uint32_t WRPR;
}FLASH_RegDef_t;

#define FLASH_BASEADDR	0x40022000UL
#define FLASH			((FLASH_RegDef_t *)FLASH_BASEADDR)

void Flash_Unlock(void);
void Flash_Lock(void);
void Flash_EraseSector(uint32_t Sector);
void Flash_Write(uint32_t Address, uint16_t Data);



#endif /* MY_FLASH_H_ */
