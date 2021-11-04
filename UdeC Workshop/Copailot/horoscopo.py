#given a birthday, return the horoscope
def get_horoscope(birthday):
    horoscopes = ["Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius"]
    month = birthday.split('/')[0]
    day = birthday.split('/')[1]
    month = int(month)
    day = int(day)
    if month == 1:
        if day < 20:
            return horoscopes[0]
        else:
            return horoscopes[1]
    elif month == 2:
        if day < 19:
            return horoscopes[1]
        else:
            return horoscopes[2]
    elif month == 3:
        if day < 21:
            return horoscopes[2]
        else:
            return horoscopes[3]
    elif month == 4:
        if day < 21:
            return horoscopes[3]
        else:
            return horoscopes[4]
    elif month == 5:
        if day < 21:
            return horoscopes[4]
        else:
            return horoscopes[5]
    elif month == 6:
        if day < 22:
            return horoscopes[5]
        else:
            return horoscopes[6]
    elif month == 7:
        if day < 23:
            return horoscopes[6]
        else:
            return horoscopes[7]
    elif month == 8:
        if day < 23:
            return horoscopes[7]
        else:
            return horoscopes[8]
    elif month == 9:
        if day < 23:
            return horoscopes[8]
        else:
            return horoscopes[9]
    elif month == 10:
        if day < 23:
            return horoscopes[9]
        else:
            return horoscopes[10]
    elif month == 11:
        if day < 22:
            return horoscopes[10]
        else:
            return horoscopes[11]
    elif month == 12:
        if day < 22:
            return horoscopes[11]
        else:
            return horoscopes[0]
    else:
        return "Invalid date"

print(get_horoscope('12/18'))