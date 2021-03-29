eeprom_stm32_DEFS := -DNO_DEBUG -DFLASH_STM32_MOCKED

eeprom_stm32_INC := \
	$(TMK_PATH)/common/chibios/

eeprom_stm32_SRC := \
	$(TMK_PATH)/common/test/eeprom_stm32_tests.cpp \
	$(TMK_PATH)/common/test/flash_stm32_mock.c \
	$(TMK_PATH)/common/chibios/eeprom_stm32.c
