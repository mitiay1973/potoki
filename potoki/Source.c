#include <stdio.h>
#include <Windows.h>
#include < time.h >
int timers(long int t)
{
	int sec = t;
	int min = 0;
	int hours = 0;
	while (1)
	{
		while (sec > 60)
		{
			sec = sec - 60;
			min++;
		}
		while (min > 60)
		{
			min = min - 60;
			hours++;
		}
		while (hours > 24)
		{
			hours = hours - 24;
			if (hours < 24)
			{
				hours = hours + 3;
			}
		}
			Sleep(1000);
			sec--;
			if (hours == 0 && min == 0 && sec == 0)
			{
				printf_s("Время вышло");
				break;
			}
			if (sec == 0)
			{
				min--;
				sec = 59;
				if (min == 0)
				{
					hours--;
					min = 59;
				
				}
			}
			system("cls");
				printf_s("%d:%d:%d\n", hours, min, sec);
	}
}
int times(long int t)
{
	int sec = t;
	int min = 0;
	int hours = 0;
	while (1)
	{
		while (sec > 60)
		{
				sec=sec - 60;
				min++;
		}
		while (min > 60)
		{
			min = min - 60;
			hours++;
		}
		while (hours > 24)
		{			
				hours = hours - 24;
				if (hours < 24)
				{
					hours = hours + 3;
				}
		}
		Sleep(1000);
		sec++;
		if (sec == 60)
		{
			min++;
			sec = 0;
			if (min == 60)
			{
				hours++;
				min = 0;
				if (hours == 24)
				{
					hours = 0;
				}
			}
		}
		system("cls");
		printf_s("%d:%d:%d\n",hours,min,sec);
	}
}
int main()
{
	system("chcp 1251>nul");
	HANDLE hTread[4];
	DWORD p=-1;
	DWORD timer=0;
	DWORD timer1 = 0;
	DWORD timer2 = 0;
	DWORD timess = 0;
	DWORD timess1 = 0;
	DWORD timess2 = 0;
	long int ttime;
	printf_s("Выберите режим работы\n 2: секундомер\n 3: часы\n 4: таймер\n 5: настройка времени\n 1: Остановить выполнение программы\n");
	while (1)
	{
		scanf_s("%d", &p);
		switch (p)
		{
		case 1:
			for (size_t i = 0; i < 4; i++)
			{
				SuspendThread(hTread[i]);
				system("cls");
				printf_s("Выполнена остановка\n");
			}
			break;
		case 2:
			printf_s("Выбран режим секундомера\n");
			hTread[0] = CreateThread(NULL, 0, times, 0, NULL, NULL);
			break;
		case 3:		
			printf_s("Выбран режим часов\n");
			SuspendThread(hTread[0]);
			ttime= time(NULL);
		  hTread[1] = CreateThread(NULL, 0, times, ttime, NULL, NULL);
			break;
		case 4:
			printf_s("Выбран режим таймера\n");
			printf_s("ч: ");
			scanf_s("%d", &timer);
			printf_s("мин: ");
			scanf_s("%d", &timer1);
			printf_s("сек: ");
			scanf_s("%d", &timer2);
			if (timer > 24 || timer < 0 || timer1>60 || timer1 < 0 || timer2>60 || timer2 < 0)
			{
				printf_s("Неверные данные\n");
			}
			else
			{
				while (timer != 0 || timer1 != 0)
				{
					if (timer != 0)
					{
						timer = timer - 1;
						timer1 = timer1 + 60;
					}
					if (timer1 != 0)
					{
						timer1 = timer1 - 1;
						timer2 = timer2 + 60;
					}
				}
				hTread[2] = CreateThread(NULL, 0, timers, timer2, NULL, NULL);	
			}
			break;
		case 5:
			printf_s("Выбран режим настройки времени\n");
			printf_s("ч: ");
			scanf_s("%d", &timess);
			printf_s("мин: ");
			scanf_s("%d", &timess1);
			printf_s("сек: ");
			scanf_s("%d", &timess2);
			if (timess > 24 || timess < 0 || timess1>60 || timess1 < 0 || timess2>60 || timess2 < 0)
			{
				printf_s("Неверные данные\n");
			}
			else
			{
				while (timess != 0 || timess1 != 0)
				{
					if (timess != 0)
					{
						timess = timess - 1;
						timess1 = timess1 + 60;
					}
					if (timess1 != 0)
					{
						timess1 = timess1 - 1;
						timess2 = timess2 + 60;
					}
				}
			}
				hTread[3] = CreateThread(NULL, 0, times, timess2, NULL, NULL);
				break;
		default:
			printf_s("Несуществующая операция\n");
			break;
		}
	}
	WaitForSingleObject(hTread, INFINITE);
}