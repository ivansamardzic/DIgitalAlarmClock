#include <stdio.h>
#include <time.h>
#include <conio.h>

void displayTime(int hours, int minutes, int seconds) {
    printf("%02d:%02d:%02d\r", hours, minutes, seconds);
    fflush(stdout);
}

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Alarm Timer\n");
    printf("2. General Timer\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int hours, minutes, seconds;
        printf("Enter hours: ");
        scanf("%d", &hours);
        printf("Enter minutes: ");
        scanf("%d", &minutes);
        printf("Enter seconds: ");
        scanf("%d", &seconds);

        time_t alarmTime = time(NULL) + (hours * 3600) + (minutes * 60) + seconds;

        while (time(NULL) < alarmTime) {
            time_t remaining = alarmTime - time(NULL);
            int remainingHours = remaining / 3600;
            int remainingMinutes = (remaining % 3600) / 60;
            int remainingSeconds = remaining % 60;
            displayTime(remainingHours, remainingMinutes, remainingSeconds);
        }
        printf("Time's up!\n");
    } else if (choice == 2) {
        time_t startTime = time(NULL);
        while (!kbhit()) { // Wait for a key press to exit
            time_t currentTime = time(NULL);
            int elapsedSeconds = currentTime - startTime;
            int hours = elapsedSeconds / 3600;
            int minutes = (elapsedSeconds % 3600) / 60;
            int seconds = elapsedSeconds % 60;
            displayTime(hours, minutes, seconds);
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}


