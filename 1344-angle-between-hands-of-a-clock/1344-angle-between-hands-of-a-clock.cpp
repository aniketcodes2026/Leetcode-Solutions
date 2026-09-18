class Solution {
public:
    double angleClock(int hour, int minutes) {
        double HourAngle = (hour % 12) * 30 + minutes * 0.5;
        double MinuteAngle = minutes * 6;

        double diff = abs(HourAngle - MinuteAngle);

        return min(diff, 360 - diff);
    }
};
