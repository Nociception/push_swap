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

*/