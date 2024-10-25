def convert_days_to_years_weeks_days(days):
    years = days // 365
    days = days % 365
    weeks = days // 7
    days = days % 7
    return years, weeks, days

# Example usage:
days = 1000
years, weeks, days = convert_days_to_years_weeks_days(days)
print(f"{days} days is equivalent to {years} years, {weeks} weeks and {days} days.")
