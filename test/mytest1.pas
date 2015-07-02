program hello;
const
	cn = 2;
	dn = 123.23;

type
	ar=record
		a : integer;
		b :integer;
	end;
var 
	i : integer;
	j : ar;
	str : string;

begin
	j.a := 0;
	for i := 0 to 10 do begin
		j.a := j.a + i;
	end
	;
	writeln(j.a);
	while i > 5 do begin
		j.a := j.a + j.a;
		i := i - 1;
	end
	;
	writeln(j.a);
	repeat 
		j.a := j.a / 2;
	until j.a < 100
	;
	writeln(j.a);
	if j.a >= 0 then begin
		j.a := j.a + 1;
	end
	;
	writeln(j.a);
	writeln(str);
end
.
