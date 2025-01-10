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
