#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 将时间转换为分钟表示
int convertToMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

// 将分钟表示转换为时间
string convertToTime(int minutes) {
    int hours = minutes / 60;
    int mins = minutes % 60;
    string hh = to_string(hours);
    string mm = to_string(mins);
    if (hh.length() == 1) {
        hh = "0" + hh;
    }
    if (mm.length() == 1) {
        mm = "0" + mm;
    }
    return hh + ":" + mm;
}

int main() {
    string currentTime;
    cin >> currentTime;

    int n;
    cin >> n;

    vector<string> alarmTimes(n);
    for (int i = 0; i < n; i++) {
        cin >> alarmTimes[i];
    }

    int currentMinutes = convertToMinutes(currentTime);
    vector<int> alarmMinutes(n);

    for (int i = 0; i < n; i++) {
        alarmMinutes[i] = convertToMinutes(alarmTimes[i]);
    }

    sort(alarmMinutes.begin(), alarmMinutes.end());

    int nextAlarmMinutes = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (alarmMinutes[i] > currentMinutes) {
            nextAlarmMinutes = alarmMinutes[i];
            break;
        }
    }

    if (nextAlarmMinutes == INT_MAX) {
        nextAlarmMinutes = alarmMinutes[0];
    }

    string nextAlarmTime = convertToTime(nextAlarmMinutes);
    cout << nextAlarmTime << endl;

    return 0;
}
