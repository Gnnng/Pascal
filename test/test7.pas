program hello;
var
	c : array [0..10] of integer;
	d : array [0..10] of integer;
	i : integer;
	aaa: integer;
	bbb:integer;
	ccc, ddd:integer;
begin
	for i := 0 to 10 do begin
		c[i] := i;
		c[i] := 10 - i;
	end
	;
	aaa:= 1;
	for i := 0 to 10 do begin
		c[i] := c[i] * c[i];
	end
	;
	bbb:=1;
	for i := 0 to 10 do begin
		writeln(c[i]);
		if c[i] = 2 then begin
			c[i] := 1;
		end
		;
	end
	;
	ccc:=1;
	writeln(11112);
	for i := 0 to 10 do begin
		writeln(c[i]);
	end
	;
	ddd:=1;
end
.
