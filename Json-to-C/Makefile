json.tab.c json.tab.h: json.y
	bison -d json.y

lex.yy.c: json.l json.tab.h
	flex json.l

json: lex.yy.c json.tab.c json.tab.h
	$(CC) json.tab.c lex.yy.c -lfl -o json

clean:
	$(RM) lex.yy.c json.tab.c json.tab.h json
