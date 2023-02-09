/*
établir les listes suivantes :
les 6 avant derniers
le dernier
les (len(A) - 7)/6 précédents

laisser les 6 derniers dans A
envoyer au bottom de B : le dernier, et les (len(A) - 7)/6 précédents
trier les 6 (jeu sur l'indice max)


Etablir la liste prioritaire : les 3 précédents (le 1er, le 2ème, le 3ème)
(Cette liste comprend trois éléments uniquement pour cette partie ;
    la liste analogue de la partie suivante n'en comprendra que 2)
Mettre à jour la liste secondaire : retirer les deux précédents passés dans la liste prioritaire
extraire les cibles prioritaires du bottom de B (à coup de rra du coup):
    les cibles prioritaires sont push directement sur A :

        si le 1er est push en premier : 
            maj de la liste prioritaire : 
                2ème->1er ; 3ème->2ème ; 3ème rempli à partir de la liste secondaire (*1)
            Quand la liste secondaire est vide, le 3ème slot n'est plus rempli
        et si le 1er est push sur le 2ème :
            swap
            si le 3ème est présent au bottom :
                il est envoyé au top (rra)
                maj de la liste prioritaire : 
                    remplissage de tous les slots
            sinon
                maj de la liste prioritaire : 
                    3ème->1er ; les 2ème et 3ème slot sont rempli
            Quand la liste secondaire est vide, le 3ème slot n'est plus rempli
        et si le 1er est push sur le 3ème (donc 2ème absent) :
            swap
            maj de la liste prioritaire : 
                2ème->1er ; 3ème->2ème ; 3ème rempli à partir de la liste secondaire (*1)
            Quand la liste secondaire est vide, le 3ème slot n'est plus rempli
        le premier ne peut pas être push sur le 2ème avec le 3ème (le 3ème, s'il est push, est systématiquement envoyé au bottom de A)

        le 2ème ne peut pas être push sur le 1er 
        (si le 1er est déjà sur A, alors le 2ème est en fait le 1er)
        le 2ème ne peut pas être push sur le 3ème (s'il est présent, il est forcément envoyé au bottom de A)
        le seul cas possible concernant spécifiquement le 2ème est donc le suivant :
        si le 2ème est push sur A (ce qui implique donc qu'il est push directement sur le bout) :
            maj de la liste prioritaire :
                aucune

        si le troisième est push, peu importe que le 2ème soit là ou pas :
            il est envoyé au bottom de A (ra)
            maj de la liste prioritaire :
                aucune

    les cibles secondaires sont laissées alternativement au top et au bottom de B
    durant ce processus, le dernier index sera croisé : lorsque ce sera le cas : l'envoyer au bottom de A
Une fois cette première réserve consommée, la partie suivante commence


SCENARIO A DEUX CIBLES PRIORITAIRES :

liste prioritaire : 1er 2ème précédents
liste secondaire : les len(B)/6 précédents

    repérer la cible à extraire en priorité selon le score calculé de la manière suivante :
        profondeur*2 - nombre de cibles secondaires rencontrées
    si la cible choisie est dans la première moitiée de B, on extrait alors avec des ra :
        3 types d'élément peuvent surgir durant l'extraction :
            - des cibles secondaires ; à envoyer :
                au bottom de A : pa, ra
            - des poubelles ; à envoyer :
                laissées au bottom de B
            - la cible prioritaire choisie (qui arrive par mécaniquement en dernier) ; à envoyer :
                au top de A : pa
    et si la cible choisie est dans la deuxième moitiée de B, on extrait alors avec des rra :
        3 types d'élément peuvent surgir durant l'extraction :
            - des cibles secondaires ; à envoyer :
                au bottom de A : pa, ra
            - des poubelles ; à envoyer :
                laissées au top de B
            - la cible prioritaire choisie (qui arrive par mécaniquement en dernier) ; à envoyer :
                au top de A : pa
    et si la cible choisie est dans la deuxième moitiée de A, dans la réserve (ce qui arrivera très souvent) :
        on extrait alors avec des rra pb :
            il n'y a que des secondaires envoyés au top de A, puis sur B
    si la cible choisie est le 1er :
        les listes sont maj
    et si la cible choisie est le 2ème :
        aucune liste n'est maj ; le 1er est maintenant la seule cible prioritaire disponible






DEUXIEME ALGO A DEUX CIBLES PRIORITAIRES DURANT LA SECONDE PARTIE :
On trie les 7 premiers à la façon habituelle
les (len(A) - 7)/6 suivants au bottom de B sont triés de la même manière que le premier algo

Deuxième partie (après la première réserve épuisée)
si la cible prioritaire choisie (score) se trouve dans la première moitié de B :
    on extrait alors à coup de ra
    - les secondaires sont envoyées sur A
    - les poubelles laissées au bottom de B
    - la prioritaire push sur A, puis envoyée au bottom
et si la cible prioritaire choisie (score) se trouve dans la deuxième moitié de B :
    on extrait alors à coup de rra
    - les secondaires sont envoyées sur A
    - les poubelles laissées au top de B
    - la prioritaire push sur A, puis envoyée au bottom
et si la cible prioritaire choisie (score) se trouve dans la réserve de A :
    on extrait alors à coup de pb
    - les secondaires sont envoyées sur B
    - il n'y a pas de poubelle
    - la prioritaire est envoyée au bottom

si la cible choisie est le 1er :
    si le 2ème est déjà au bottom :
        si le 1er est au top de A :
            rra
            sa
            ra
            ra
        et si le 1er est au top de B :
            rra
            pa
            ra
            ra
        les listes sont maj :
            xxxx
    sinon :
        ra
        les listes sont maj :
            xxxx
    et si la cible choisie est le 2ème :
        aucune liste n'est maj ; le 1er est maintenant la seule cible prioritaire disponible


TROISIEME ALGO

Tant que la liste n'est pas triée



Partie 0
liste des 6 : de l'index 1 à 6
liste des 3 : index 0 et 7 8
liste de la moitié : les (len(A) - 9) / 2 suivants
liste des autres (l'autre "moitié")

Première étape de la purge vers B :
    la liste des 6 et la liste des 3 est conservée dans A 
    (éventuellement, lorsque deux voisins non ordonnés de ces listes sont rencontrés, les swap)
    la première moitié est laissé dans la partie supérieure de B
    L'autre moitié est envoyée au bottom de B

Partie 1
Quand A ne contient plus que la liste des 6 et la liste des 3 :
    les 3 sont purgés sur B
    les 6 voient leur index respectifs réduits de 1, et leur index max ajusté à 6 (ou 5, ou 7 je ne sais plus)
    les 6 sont triés tel que :
        quand l'un des  6 n'a aucune proximité avec ses mitoyens, mais que dans ces mitoyens il y a l'un des 3
        le membre des 3 est extrait au top de A, puis push sur B et envoyé au bottom de B
        algo6

Quand les 6 sont triés :
    les 6 voient leur index respectifs rétablis, de même que leur indice max
    les 3 sont extraits du bottom de B puis envoyés sur A à leur emplacement approprié respectifs

Partie 2
    nouvelles listes :
        Prioritaires : les 2 suivants, ne pouvant être que dans la première moitié de B
            maj jusqu'à épuisement de la secondaire
        Secondaires : les 1/4 suivants (la moitié de la moitié)
            maj jusqu'à la moitié
    pendant l'extraction d'une cible prioritaire :
        si elle est extraite de la première moitié de B (à coup de rb):
            les éléments de la liste secondaire sont envoyés sur A
            les autres sont envoyés et laissés au bottom de B par le mouvements des ra successifs
            la cible prioritaire est envoyé sur A, puis au bottom de A
        si elle est extraite de la première moitié de A (à coup de pb):
            à ce stade, la première moitié de A ne peut contenir QUE des secondaires
            les éléments de la liste secondaire sont envoyés sur B, et laissés au top
            la cible prioritaire est envoyé au bottom de A (ra)
        si elle est extraite de la deuxième moitié de B (à coup de rra) 
        (ce qui arrivera une fois le premier quart consommé) :
            les éléments de la liste secondaire sont envoyés sur A (pa)
            les autres sont laissés au top de B
            la cible prioritaire est envoyée sur A, puis au bottom de A

Partie 3
Quand la première moitiée est épuisée : avant dernière étape (juste avant le placement de A triée)
    nouvelles listes :
        Prioritaires : les deux suivants
            maj à partir de la secondaire
            si la deuxième est envoyée en premier :
                aucune maj ; la seule cible prioritaire devient la première
        Secondaires : les 1/6 du reste suivants
            maj jusqu'à épuisement de B
    pendant l'extraction d'une cible prioritaire :
        si elle est extraite da la première moitié de B (à coup de rb) :
            les secondaires sont envoyés sur A, et laissés au top
            les autres sont laissés au bottom de B (par le mouvement des rb)
            la cible prioritaire est envoyée sur A, puis au bottom de A
        si elle est extraite de la première moitié de A (à coup de pb) :
            les secondaires sont laissés sur B
            les autres sont envoyés au bottom de B
            la cible prioritaire est envoyée au bottom de A (ra)
        si elle est extraite de la deuxième moitié de B (à coup de rrb) :
            les secondaires sont envoyés sur A (pa)
            les autres laissés sur B
            la cible prioritaire est envoyée sur A, puis au bottom de A

Partie 4
Placement de A triée

Considérations pratiques :
les listes prioritaires et secondaires seront des tableaux d'int remplis par les index
la liste des prioritaires sera d'abord 
    durant les trois premières partie : un tableau de trois int (pas besoin de malloc celui-ci)
    durant les parties 4 et 5 : un tableau de trois int (toujours pas besoin de malloc celui-ci)
la liste des secondaires sera un tableau d'int malloc à la taille 1/4 de l'index max initial


Avec une liste de 3 suivants prioritaires :
    Si le premier arrive sans les autres
        il est directement branché
        la liste est mise à jour
    Et Si le premier arrive avec le deuxième déjà présent :
        si le premier arrive de B :
            le deuxième est envoyé au top, puis le premier est push dessus
            les deux sont envoyés au bottom
        Et si le premier provient du top de A :
            le deuxième est envoyé au top de A
            les deux sont swap
            les deux sont envoyés au bottom
        la liste est mise à jour
    Et si le premier arrive avec le troisième déjà présent :
        si le premier arrive de B :
            le troisième est envoyé au top, puis le premier est push dessus
            les deux sont envoyés au bottom
        Et si le premier provient du top de A :
            le troisième est envoyé au top de A
            les deux sont swap
            les deux sont envoyés au bottom
        la liste est mise à jour :
            le troisième devient le deuxième, le troisième est rempli à partir de la secondaire
    Et si le premier arrive avec le deuxième et troisième déjà présent et ordonnés :
        si le premier arrive de B :
            les deuxième et troisième sont envoyés au top de A
            le premier est push dessus
            les trois sont envoyés au bottom de A
        et si le premier provient du top de A :
            une fois le premier au top, il est push sur B
            les deuxièmes et troisièmes sont envoyés au top de A
            le premier est push sur A
            les trois sont envoyés au bottom de A
        la liste est mise à jour
    Et si le deuxième arrive sans les autres
        il est directement branché
        la liste est mise à jour (l'index (dans la liste) du deuxième passe en négatif)
    Et si le deuxième arrive avec le troisième déjà présent :
        si le deuxième arrive de B :
            le troisième est envoyé au top, puis le deuxième est push dessus
            les deux sont envoyés au bottom
        Et si le deuxième provient du top de A :
            le troisième est envoyé au top de A
            les deux sont swap
            les deux sont envoyés au bottom
        la liste est mise à jour
    Et si le troisième arrive sans les autres :
        il est directement branché
        la liste est mise à jour (l'index (dans la liste) du troisième passe en négatif)
    Et si le troisième arrive avec le deuxième déjà présent :
        il est directement envoyé au bottom de B
        la liste est mise à jour (l'index (dans la liste) du troisième passe en négatif)

Avec une liste des 4 suivants prioritaires :
Si le premier arrive sans les autres
        il est directement branché
        la liste est mise à jour
    Et Si le premier arrive avec le deuxième déjà présent :
        si le premier arrive de B :
            le deuxième est envoyé au top, puis le premier est push dessus
            les deux sont envoyés au bottom
        Et si le premier provient du top de A :
            le deuxième est envoyé au top de A
            les deux sont swap
            les deux sont envoyés au bottom
        la liste est mise à jour
    Et si le premier arrive avec le troisième déjà présent :
        si le premier arrive de B :
            le troisième est envoyé au top, puis le premier est push dessus
            les deux sont envoyés au bottom
        Et si le premier provient du top de A :
            le troisième est envoyé au top de A
            les deux sont swap
            les deux sont envoyés au bottom
        la liste est mise à jour :
            le troisième devient le deuxième, le troisième est rempli à partir de la secondaire
    Et si le premier arrive avec le quatrième déjà présent :
        si le premier arrive de B :
            le quatrième est envoyé au top, puis le premier est push dessus
            les deux sont envoyés au bottom
        Et si le premier provient du top de A :
            le quatrième est envoyé au top de A
            les deux sont swap
            les deux sont envoyés au bottom
        la liste est mise à jour :
            le quatrième devient le troisième, le quatrième est rempli à partir de la secondaire
    Et si le premier arrive avec le deuxième et troisième déjà présents et ordonnés :
        si le premier arrive de B :
            les deuxième et troisième sont envoyés au top de A
            le premier est push dessus
            les trois sont envoyés au bottom de A
        et si le premier provient du top de A :
            une fois le premier au top, il est push sur B
            les deuxièmes et troisièmes sont envoyés au top de A
            le premier est push sur A
            les trois sont envoyés au bottom de A
        la liste est mise à jour
    Et si le premier arrive avec le troisième et quatrième déjà présents et ordonnés :
        si le premier arrive de B :
            les troisième et quatrième sont envoyés au top de A
            le premier est push dessus
            les trois sont envoyés au bottom de A
        et si le premier provient du top de A :
            une fois le premier au top, il est push sur B
            les troisième et quatrième sont envoyés au top de A
            le premier est push sur A
            les trois sont envoyés au bottom de A
        la liste est mise à jour
    Et si le deuxième arrive sans les autres
        il est directement branché
        la liste est mise à jour (l'index (dans la liste) du deuxième passe en négatif)
    Et si le deuxième arrive avec le troisième déjà présent :
        si le deuxième arrive de B :
            le troisième est envoyé au top, puis le deuxième est push dessus
            les deux sont envoyés au bottom
        Et si le deuxième provient du top de A :
            le troisième est envoyé au top de A
            les deux sont swap
            les deux sont envoyés au bottom
        la liste est mise à jour
    Et si le deuxième arrive avec le quatrième déjà présent :
    Et si le troisième arrive sans les autres :
        il est directement branché
        la liste est mise à jour (l'index (dans la liste) du troisième passe en négatif)
    Et si le troisième arrive avec le deuxième déjà présent :
        il est directement envoyé au bottom de B
        la liste est mise à jour (l'index (dans la liste) du troisième passe en négatif)
...

Avec une liste des n suivants prioritaires :
    une fois la cible prioritaire choisie pour l'envoyer au bottom de A :
        on fait remonter les déjà présents (indexés en négatif dans la liste des prioritaires)
        jusqu'à l'index directement inférieur à la cible
        puis la cible est push sur A
        si la cible suivante 

*/