routine ArraySum (inputArray : array [] integer) is
        var sum : integer is 0;
for i in 1..inputArray.size loop
        sum := sum + inputArray[1];
end;
return sum;

var myArray : array [4] integer;
myArray[1] := 9
myArray[2] := 10
myArray[3] := 2
myArray[4] := 7

return ArraySum(myArray);