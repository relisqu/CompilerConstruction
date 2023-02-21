/*
	First part of this file will cover the
	work of routines on usertype.
*/

type Human is record
var age : integer,
var weight : real,
var gender : boolean is 1 // Default is male
end;

routine HumanConstructor (age : integer, weight : real, gender : boolean) is
        var Result : Human;
Result.age = age;
Result.weight = weight;
Result.gender = gender;
return Result;
end;

var Bob : Human is HumanConstructor(16, 89.2, true);
var Alice : Human is HumanConstructor(14, 72.3, false);
var Charlie : Human is HumanConstructor(15, 81.5, false);
var Dave : Human is HumanConstructor(17, 90.1, true);

var People : array [4] Human;
// Assigning people to array;
People[1] := Bob;
People[2] := Alice;
People[3] := Charlie;
People[4] := Dave;

var underAge : integer is 0;

routine countUnderage(peopleArray : array [] Human) : integer is
var total : integer is 0;
for i in 1..peopleArray.size loop
if peopleArray[i].age <= 16 then // Using american
total := total + 1;
end;
end;
return total;
end;

underAge := countUnderage(People);

routine simulateAging(person : Human, targetAge : integer) is
while person.age < targetAge loop
person.age := person.age + 1;
person.weight := person.weight * 1.05;
end;
end;

routine agePeople(peopleArray : array [] Human, targetAge : integer) is
for i in 1..peopleArray.size loop
simulateAging(peopleArray[i], targetAge);
end;
end;

agePeople(People);

/*
	After this point there will be demonstrations of
	arithmetics and simple operations.
*/

routine arithmeticsDemo(a : real, b : real, c : integer, d : integer) : real is
return (a - b + (c % d * 4) * 0.35) / a;

var mathDemo is arithmeticsDemo(5.2, 3.1, 29, 17);

routine gcd(a : integer, b : integer) : integer is
if b = 0 then
return a;
end;
return gcd(b, a % b);
end;

var gcdDemo is gcd(150, 100);

routine isBetween(a : integer, leftb : integer, rightb : integer) : boolean is
if a >= leftb and a <= rightb then
return true;
else
return false;
end;
end;

var booleanDemo is isBetween(4, 2, 8);