program hello;
const 
	ta = 3;
var 
	c : array [0..10] of real;
	i : integer;
	j : integer;
	k : integer;
begin
	c[0] := 0.1;
	c[1] := 0.2;
	c[2] := 0.3;
	c[3] := 0.4;
	c[4] := 0.5;
	c[5] := 0.6;
	c[6] := 0.7;
	c[7] := 0.8;
	c[8] := 0.9;
	c[9] := 1.0;
	c[10] := 1.1;
	writeln(1.1);
	for i := 0 to 10 do
	begin
		c[i] := c[i] * c[i];
		writeln(i, c[i]);
	end
	;
end
.
