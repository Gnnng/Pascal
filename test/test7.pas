program hello;
var
	c : array [0..10] of integer;
	d : array [0..10] of integer;
	i : integer;
begin
	for i := 0 to 10 do begin
		c[i] := i;
		d[i] := 10 - i;
	end
	;
	for i := 0 to 10 do begin
		c[i] := c[i] * d[i];
	end
	;
	for i := 0 to 10 do begin
		writeln(c[i]);
		if c[i] = 2 then begin
			c[i] := 1;
		end
		;
	end
	;
	for i := 0 to 10 do begin
		writeln(c[i]);
	end
	;
end
.
