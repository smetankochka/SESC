class Date {
private:
    static const int DEFAULT_DATE_DAY = 1;
    static const int DEFAULT_DATE_MONTH = 1;
    static const int DEFAULT_DATE_YEAR = 1970;
    static const int DAYS_IN_YEAR_WITHOUT_FEB = 337;

    int d = DEFAULT_DATE_DAY, m = DEFAULT_DATE_MONTH, y = DEFAULT_DATE_YEAR;

    int GetDaysInFeb(int year) const {
        if ((!(year % 4) && (year % 100)) || !(year % 400)) {
            return 29;
        }
        return 28;
    }

    int GetDaysInMonth(int month, int year) const {
        switch (month) {
            case 2:
                return GetDaysInFeb(year);
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            default:
                return 30;
        }
    }

    int GetDaysInYear(int year) const {
        return DAYS_IN_YEAR_WITHOUT_FEB + GetDaysInFeb(year);
    }

    bool IsCorrectDate() const {
        return m <= 12 && m >= 1 && d <= GetDaysInMonth(m, y) && d > 0;
    }

    int DaysPassedToMonth(int month, int year) const {
        int days = 0;
        for (int i = 1; i < month; ++i) {
            days += GetDaysInMonth(i, year);
        }
        return days;
    }

    int GetDays() const {
        int days = 0;
        for (int i = DEFAULT_DATE_YEAR; i < y; ++i) {
            days += GetDaysInYear(i);
        }
        return days + DaysPassedToMonth(m, y) + d;
    }

    void SetFromDays(int inp_days) {
        m = DEFAULT_DATE_MONTH;
        y = DEFAULT_DATE_YEAR;

        while (inp_days > GetDaysInYear(y)) {
            inp_days -= GetDaysInYear(y);
            ++y;
        }

        while (inp_days > DaysPassedToMonth(m + 1, y)) {
            ++m;
        }

        d = inp_days - DaysPassedToMonth(m, y);
    }

public:
    Date(int day, int month, int year) : d(day), m(month), y(year) {
        if (!IsCorrectDate()) {
            d = DEFAULT_DATE_DAY;
            m = DEFAULT_DATE_MONTH;
            y = DEFAULT_DATE_YEAR;
        }
    }

    int GetDay() const {
        return d;
    }

    int GetMonth() const {
        return m;
    }

    int GetYear() const {
        return y;
    }

    Date operator+(int k) const {
        Date result(*this);
        result.SetFromDays(result.GetDays() + k);
        return result;
    }

    Date operator-(int k) const {
        Date result(*this);
        result.SetFromDays(result.GetDays() - k);
        return result;
    }

    int operator-(const Date& other) const {
        return GetDays() - other.GetDays();
    }
};
