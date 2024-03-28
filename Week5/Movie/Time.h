class Time {
private:
    unsigned seconds;
    unsigned minutes;
    unsigned hours;

public:
    Time() = default;
    Time(unsigned seconds);
    Time(unsigned hours, unsigned minutes, unsigned seconds);

    unsigned getSeconds() const;
    unsigned getMinutes() const;
    unsigned getHours() const;


    void setSeconds(unsigned minutes);
    void setMinutes(unsigned minutes);
    void setHour(unsigned hours);
};