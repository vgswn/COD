%{

%}
%%
[a-zA-z]* return 1;
%%
int yywrap(void)
{
  return 1;
}
