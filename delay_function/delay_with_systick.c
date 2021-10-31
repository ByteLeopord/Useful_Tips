#define SYSTICK_FREQUENCY (0.0001f)

uint32_t get_systick(void)
{
	uint32_t tick = systick_api();
	return tick;
}

void delay(uint16_t delay_ms)
{
	float begin = get_systick();
	do
	{
		float end = get_systick();
		uint16_t now_ms = (uint16_t)((end - begin) * SYSTICK_FREQUENCY);
	}while(now_ms < delay_ms);
}
