program test_array;
var
	arr : array [1..10] of integer;
	x : integer;
	y : integer;
begin
	x := 10;
	writeln(x);
	arr[1] := x;
	y := arr[0];
end.
