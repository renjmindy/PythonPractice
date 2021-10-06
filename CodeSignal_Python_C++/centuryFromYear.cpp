int centuryFromYear(int year) {
    if (year % 100 > 0) {
        return int(year / 100) + 1;
    } else {
        return int(year / 100);
    }
}

def centuryFromYear(year):
    
    cen, remainder = divmod(year, 100)
    
    if remainder == 0:
        return cen
    else:
        return cen + 1
