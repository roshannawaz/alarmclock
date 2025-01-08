#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>

void displayCurrentTime() {
    while (true) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* localTime = std::localtime(&now_c);

        std::cout << "\rCurrent Time: " << std::put_time(localTime, "%H:%M:%S") << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void setAlarm(int alarmHour, int alarmMinute) {
    while (true) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* localTime = std::localtime(&now_c);

        if (localTime->tm_hour == alarmHour && localTime->tm_min == alarmMinute) {
            std::cout << "\n\n*** ALARM! Time to wake up! ***\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    int hour, minute;

    std::cout << "Set the alarm time." << std::endl;
    std::cout << "Hour (0-23): ";
    std::cin >> hour;
    std::cout << "Minute (0-59): ";
    std::cin >> minute;

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        std::cerr << "Invalid time entered. Please run the program again with valid inputs." << std::endl;
        return 1;
    }

    std::cout << "Alarm is set for " << std::setw(2) << std::setfill('0') << hour << ":"
              << std::setw(2) << std::setfill('0') << minute << ".\n";

    std::thread displayThread(displayCurrentTime);

    setAlarm(hour, minute);

    displayThread.detach();

    return 0;
}
