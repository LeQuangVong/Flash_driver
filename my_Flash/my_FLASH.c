#include "my_Flash.h"

void Flash_Unlock(void)
{
	if((FLASH->CR & (1 << 7)) != 0)
	{
		FLASH->KEYR =  0x45670123;
		FLASH->KEYR = 0xCDEF89AB;
	}

}
void Flash_Lock(void)
{
	FLASH->CR |= (1 << 7);
}
void Flash_EraseSector(uint32_t Sector)
{
	while((FLASH->SR & (1 << 0)) == 1);
	FLASH->CR |= (1 << 1);
	FLASH->AR = Sector;
	FLASH->CR |= (1 << 6);
	while((FLASH->SR & (1 << 0)) == 1);
	FLASH->CR &= ~(1 << 1);
}
void Flash_Write(uint32_t Address, uint16_t Data)
{
	while((FLASH->SR & (1 << 0)) == 1);
	FLASH->CR |= (1 << 0);
	*(uint16_t *)Address = Data;

	while((FLASH->SR & (1 << 0)) == 1);

	if((FLASH->SR & (1 << 5)))
	{
		FLASH->SR |= (1 << 5);
	}

	FLASH->CR &= ~(1 << 0);
}



