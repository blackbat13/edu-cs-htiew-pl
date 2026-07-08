from faker import Faker
from random import choice

fake = Faker()
doctorsCount = 30
patientsCount = 100
visitsCount = 200

with open("lekarze.txt", "w", encoding="utf-8") as file:
    print("ID_lekarza;Imie;Nazwisko;Specjalizacja", file=file)
    for i in range(1,doctorsCount+1):
        name = fake.first_name()
        surname = fake.last_name()
        specialization = choice(["kardiolog", "neurolog", "ortopeda", "pediatra", "dermatolog", "ginekolog", "psychiatra", "radiolog", "chirurg", "endokrynolog"])
        print(f"{i};{name};{surname};{specialization}", file=file)

with open("pacjenci.txt", "w", encoding="utf-8") as file:
    print("ID_pacjenta;Imie;Nazwisko;PESEL", file=file)
    for i in range(1,patientsCount+1):
        name = fake.first_name()
        surname = fake.last_name()
        pesel = fake.unique.random_number(digits=11)
        print(f"{i};{name};{surname};{pesel}", file=file)


with open("wizyty.txt", "w", encoding="utf-8") as file:
    print("ID;ID_lekarza;ID_pacjenta;Data;Typ_wizyty", file=file)
    for i in range(1,visitsCount+1):
        doctor_id = choice(range(1, doctorsCount+1))
        patient_id = choice(range(1, patientsCount+1))
        date = fake.date_between(start_date='-2y', end_date='today')
        visit_type = choice(["konsultacja", "badanie", "zabieg", "kontrola", "rehabilitacja"])
        print(f"{i};{doctor_id};{patient_id};{date};{visit_type}", file=file)