program llvm;
var a, b, c: integer;
begin
b:=20;
a:=1;
if 1=2 then  
a := 22
else
a := 100+5;
if 1=1 then  
a := 22
else
a := 100;
while a<30 do
	a:=a+1;
repeat
a:=a+1;
until a=60;
for a:=1 to 100 do
begin
  b:=b+1;
  b:=b+1;
end;
writeln(a);
writeln(b);
end.
