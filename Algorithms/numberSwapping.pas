Program exo15;

Var N, Nr, bit, p, compteur, i, valeur: longint;

BEGIN

    writeln('ins‚rez un num‚ro : ');
    readln(N);

    // on doit d‚composer l'entier N puis on compose le nouveau entier Nr

    // 1 - trouver le nombre des chiffres composant N
    valeur := N;

    Repeat

    	valeur := valeur DIV 10;
    	compteur := compteur + 1;

    until valeur = 0;

    // 2 - Initialisation de la variable p

    p := 1;

    for i := 1 to compteur-1 do

    begin
    	p := p*10;
    end;
    // fin de l'initialisation

    bit := 0;

    Repeat

    	bit := (N mod 10);
    	N := N DIV 10;
    	Nr := Nr + bit*p;
    	p := p DIV 10;

    until N = 0;

    writeln('le nouveau nombre :', Nr);


readln ;

end.
