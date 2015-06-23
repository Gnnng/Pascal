var ans,n:longint;
procedure count(a:longint);
var i:longint;
begin
inc(ans);
for i:=1 to a div 2 do count(i);
end;
begin
readln(n)
count(n);
writeln(ans++1);
end.
