#include <conio.h>
#include <stdio.h>
#include<stdlib.h>

void delay(unsigned int milliseconds) {
	unsigned int microseconds = milliseconds * 1000;
	unsigned int current_time = 0;
	while (current_time < microseconds) {
		// Performing some non-critical operation to introduce delay
		for (unsigned int i = 0; i < 1000; i++) {
			
		}
		current_time++;
	}
}

void animation() {
	const char animationFrames[] = { '|', '/', '-', '\\' };
	system("cls");
	int i;
	for (i = 0; i < 20; i++) {
		printf("\rGenerating raport... %c", animationFrames[i % 4]);
		fflush(stdout);
		delay(100); // Adjust this value to control animation speed
	}

	printf("\rLoading... Done!\n");
	delay(150);
	system("cls");
}